%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tipos.hpp"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char* yytext;

/*
struct lval {
    int line;
    int col;
    // the value of the token. if it is the number 0, this is going to be 0
    string lexeme;
    int token;
    lval() {}
};


// all we have as symbols for the symbol table are identifiers. other possible
// symbols are, for example, goto labels
struct old_symbol {
    int scope = 0;
    // this is the actual name of the symbol. an id 'foo' has the name foo
    string name = "";
    string type = "";
    bool is_const= false;
    lval val;
    symbol() {}
};

// since we have 128 ASCII characters, that's the max number of children our
// trie can have, even though we won't use all of them
#define N 128

struct node {
    struct node *children[N];
    symbol sym;
    bool is_leaf;
};

node* root;

node *initialize()
{
    node *novo = (node*) calloc(1, sizeof(node));
    for (int i = 0; i < N; i++) novo->children[i] = NULL;
    novo->is_leaf = 0;

    return novo;
}

void adiciona(symbol simbolo)
{
    node *tmp = root;
    string word = simbolo.name;
    for (int i = 0; i<word.size(); i++) {
        // get the relative position in the alphabet list

        int position = (int) word[i] - 'a';

        if (tmp->children[position] == NULL){

            tmp->children[position] = initialize();
        }

        tmp = tmp->children[position];
    }


      tmp->is_leaf = 1;
      tmp->sym.name =  simbolo.name;
}

node *acha(symbol simbolo)
{
    // searches for word in the trie
    node *tmp = root;
    string word = simbolo.name;
    for(int i = 0; i<word.size(); i++)
    {
        int position = word[i] - 'a';
        if (tmp->children[position] == NULL) return NULL;
        tmp = tmp->children[position];
    }

    if (tmp != NULL && tmp->is_leaf == 1) return tmp;

    return NULL;
}
*/

SymTable symtable;

void print_symtable(SymTable &symtable) {
  for (auto const &sym : symtable) {
    string key = sym.first;
    Symbol val = sym.second;

    cout << "{" << key << " = " << val << "}" << endl;
  }
}
%}

%type <literalRetorno> literal
%type <cmdRetorno> cmd
%type <identifierRetorno> identifier
%type <assign_exprRetorno> assign_expr
%type <all_decl_varRetorno> all_decl_var
%type <cmd_decl_varRetorno> cmd_decl_var
%type <assign_expr_maybeRetorno> assign_expr_maybe
%type <decl_var_primRetorno> decl_var_prim
%type <primitivosRetorno> primitivos
%type <cochetezeromaisRetorno> cochetezeromais
%type <hashtagzeromaisRetorno>hashtagzeromais
%type <const_decl_varRetorno> const_decl_var

%token '[' IF ENDIF ELSE SWITCH CASE FOR LOOP RETURN STRUCT CONST BREAK CONTINUE READ WRITE EXIT WHEN FUNCTION INT REAL CHAR STR BOOL VOID PLUS MINUS TIMES DIV MOD TRUE FALSE NUMBER CHARACTER STRING LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET ID SEMICOLON QUESTION_MARK COLON DOT POINTER_VAL ARROW COMMA REFERENCE TERNARY ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULT ASSIGN_DIV ASSIGN_MOD ASSIGN
%start prog
%left '@'
%left LEFT_PAREN
%left RIGHT_PAREN
%left INCREMENT DECREMENT
%left NOT
%left OR AND
%left MINUS PLUS
%left TIMES DIV MOD
%nonassoc EQUALS DIFF LT GT LEQ GEQ

%% /* Inicio da segunda seção, onde colocamos as regras BNF */

prog : stmts {
};

stmts : /* epsilon */ {}
      | stmt stmts {};

stmt : decl_fun {}
     | cmd {};

decl_fun : FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block {};

cmd : identifier assign_expr SEMICOLON {$$ = new cmd($1,$2);}
      | cmd_decl_var SEMICOLON {$$ = new cmd($1);}
      | inOut SEMICOLON {}
      | cmd_loop {}
      | cmd_cond {}
      | cmd_switch {}
      | expr SEMICOLON {}
      | RETURN expr SEMICOLON {}
      | BREAK SEMICOLON {}
      | CONTINUE SEMICOLON {}
      | EXIT WHEN expr SEMICOLON {}
      | block {};

cmd_decl_var : all_decl_var assign_expr_maybe {
      $$ = new cmd_decl_var($1,$2);
};

assign_expr_maybe : /*epsilon*/ {$$ = NULL;}
      | assign_expr {$$ = new assign_expr_maybe();};

all_decl_var : decl_var_prim {$$ = new all_decl_var($1,symtable);
                              print_symtable(symtable);}
             | const_decl_var {$$ = new all_decl_var($1,symtable);
                              print_symtable(symtable);};

decl_var_prim : primitivos hashtagzeromais cochetezeromais ID {
      $$ = new decl_var_prim($1,$2,$3,yytext);
};
const_decl_var : CONST decl_var_prim {
      $$ = new const_decl_var($2);
}; 

hashtagzeromais : /*epsilon*/ {$$ = NULL;}
      | POINTER_VAL hashtagzeromais {$$ = new hashtagzeromais($2);};


cochetezeromais : /*epsilon*/ {$$ = NULL;}
      | LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais {$$ = new cochetezeromais($4);};

assign_expr : ASSIGN expr {$$ = new assign_expr();}
            | assign_extra expr {$$ = new assign_expr();}
            | inc {$$ = new assign_expr();};

assign_extra : ASSIGN_PLUS {}
      | ASSIGN_MINUS {}
      | ASSIGN_MULT {}
      | ASSIGN_DIV {}
      | ASSIGN_MOD {};

inc : DECREMENT {}
      | INCREMENT {};

inOut : in {}
      | out {};
in : READ LEFT_PAREN ID RIGHT_PAREN {};
out : WRITE LEFT_PAREN ID RIGHT_PAREN {};

cmd_loop : for {}
      | loop {}

cmd_cond : if {};

cmd_switch : switch {};

for : FOR LEFT_PAREN expr SEMICOLON expr SEMICOLON expr RIGHT_PAREN cmd {};


loop : LOOP cmd {};

if : IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else {};

else :  /*epsilon*/ {}
      | ELSE cmd {};

switch : SWITCH LEFT_PAREN expr RIGHT_PAREN LEFT_BRACE casezeromais RIGHT_BRACE {};

casezeromais : /*epsilon*/ {}
      | case casezeromais {};

case : CASE literal COLON stmts {};

type : typename {};
typename : primitivos {}
         | ID {};

primitivos : INT {$$ = new primitivos("INT");}
           | REAL {$$ = new primitivos("REAL");}
           | CHAR {$$ = new primitivos("CHAR");}
           | BOOL {$$ = new primitivos("BOOL");}
           | STR {$$ = new primitivos("STRING");}
           | VOID {$$ = new primitivos("VOID");};

typedlpar : /*epsilon*/ {}
      | parameter typedlparAfter {}

typedlparAfter : /*epsilon*/ {}
      | COMMA parameter typedlparAfter {};

parameter : type parameterAfter {};

parameterAfter : ID {}
      | REFERENCE ID {};

block : LEFT_BRACE stmts RIGHT_BRACE {};

expr : INCREMENT expr {}
     | DECREMENT expr {}
     | LEFT_PAREN expr RIGHT_PAREN {}
     | MINUS identifier {}
     | NOT expr {}
     | expr AND expr {}
     | expr OR expr {}
     | expr PLUS expr {}
     | expr TIMES expr {}
     | expr DIV expr {}
     | expr MINUS expr {} 
     | expr MOD expr {}
     | expr EQUALS expr {}
     | expr DIFF expr {}
     | expr LT expr {}
     | expr GT expr {}
     | expr LEQ expr {}
     | expr GEQ expr {}
     | expr_tern {}
     | literal {}
     | identifier {};

expr_tern : TERNARY expr QUESTION_MARK expr COLON expr TERNARY {};



identifier : ID {
            $$ = new identifier(yytext);
      } %prec '@'
          | ID arrayAccess {$$ = new identifier(yytext);}
          | ID LEFT_PAREN lpar RIGHT_PAREN {$$ = new identifier(yytext);}
          | ID pointerAccess {$$ = new identifier(yytext);};


arrayAccess : LEFT_BRACKET expr RIGHT_BRACKET {}
               | LEFT_BRACKET expr RIGHT_BRACKET arrayAccess {};


lpar : /*epsilon*/ { }|
       expr lparAfter {};

lparAfter :  /*epsilon*/ {}
      | COMMA expr lparAfter {};

pointerAccess : ARROW ID {}
               | ARROW ID pointerAccess {};

literal : NUMBER {$$ = new literal("NUMBER",yytext);}
      | CHARACTER {$$ = new literal("CHAR",yytext);}
      | TRUE {$$ = new literal("BOOL",yytext);}
      | FALSE {$$ = new literal("BOOL",yytext);}
      | STRING {$$ = new literal("STRING",yytext);};

%% /* Fim da segunda seção */

int main (void) {
      /* root = initialize(); */

      return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
