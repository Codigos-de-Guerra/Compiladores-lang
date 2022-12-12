%{
#include <stdio.h>
#include<stdlib.h>
#include<string>
#include "tipos.hpp"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;


 struct lval {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    string lexeme;
    int token;
    lval(){

    }
};


/* all we have as symbols for the symbol table are identifiers. other possible
   symbols are, for example, goto labels */
struct symbol {
    int scope = 0;
    /* this is the actual name of the symbol. an id 'foo' has the name foo */
    string name = "";
    string type = "";
    bool is_const= false;
    lval val;
    symbol(){

    }
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
        /* get the relative position in the alphabet list */
        
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
    /* searches for word in the trie */
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


map<string,string> symtable;

%}




%type <literalRetorno> literal
%type <cmdRetorno> cmd
%type <identifierRetorno> identifier
%type <assign_exprRetorno> assign_expr
%type<all_decl_varRetorno> all_decl_var
%type<cmd_decl_varRetorno> cmd_decl_var
%type<assign_expr_maybeRetorno> assign_expr_maybe
%type<decl_var_primRetorno> decl_var_prim
%type<primitivosRetorno> primitivos
%type<cochetezeromaisRetorno> cochetezeromais
%type<hashtagzeromaisRetorno>hashtagzeromais
%type<const_decl_varRetorno> const_decl_var
%type<exprRetorno> expr

%token '[' IF ENDIF ELSE SWITCH CASE FOR LOOP RETURN STRUCT CONST BREAK CONTINUE READ WRITE EXIT WHEN FUNCTION INT REAL CHAR STR BOOL VOID PLUS MINUS TIMES DIV MOD TRUE FALSE NUMBER CHARACTER STRING LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET SEMICOLON QUESTION_MARK COLON DOT POINTER_VAL ARROW COMMA REFERENCE TERNARY ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULT ASSIGN_DIV ASSIGN_MOD ASSIGN
%token<name> ID
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

cmd :  identifier assign_expr SEMICOLON {
            $$ = new cmd($1,$2);
      }
      |cmd_decl_var SEMICOLON {
            $$ = new cmd($1);}
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
      | assign_expr {
            $$ = new assign_expr_maybe();};

all_decl_var : decl_var_prim {$$ = new all_decl_var($1,symtable);}
            | const_decl_var {$$ = new all_decl_var($1,symtable);};

decl_var_prim : primitivos hashtagzeromais cochetezeromais ID {
      $$ = new decl_var_prim($1,$2,$3,*$4);
};
const_decl_var : CONST decl_var_prim {
      $$ = new const_decl_var($2);
}; 

hashtagzeromais : /*epsilon*/ {$$ = NULL;}
      | POINTER_VAL hashtagzeromais {$$ = new hashtagzeromais($2);};


cochetezeromais : /*epsilon*/ {$$ = NULL;}
      | LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais {$$ = new cochetezeromais($4);};

assign_expr : ASSIGN expr {
                  $$ = new assign_expr();}
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

primitivos : INT {$$ = new primitive("INT");}
           | REAL {$$ = new primitive("REAL");}
           | CHAR {$$ = new primitive("CHAR");}
           | BOOL {$$ = new primitive("BOOL");}
           | STR {$$ = new primitive("STRING");}
           | VOID {$$ = new primitive("VOID");};

typedlpar : /*epsilon*/ {}
      | parameter typedlparAfter {}

typedlparAfter : /*epsilon*/ {}
      | COMMA parameter typedlparAfter {};

parameter : type parameterAfter {};

parameterAfter : ID {}
      | REFERENCE ID {};

block : LEFT_BRACE stmts RIGHT_BRACE {};

expr : INCREMENT expr {$$ = new expr($2,symtable);}
     | DECREMENT expr {$$ = new expr($2,symtable);}
     | LEFT_PAREN expr RIGHT_PAREN {$$ = new expr($2,symtable);}
     | MINUS identifier {$$ = new expr($2,symtable);}
     | NOT expr {$$ = new expr($2,symtable);}
     | expr AND expr {$$ = new expr($1,$3,symtable);}
     | expr OR expr {$$ = new expr($1,$3,symtable);}
     | expr PLUS expr {
                  $$ = new expr($1,$3,symtable);}
     | expr TIMES expr {$$ = new expr($1,$3,symtable);}
     | expr DIV expr {$$ = new expr($1,$3,symtable);}
     | expr MINUS expr {
                        
                        $$ = new expr($1,$3,symtable);}
     | expr MOD expr {$$ = new expr($1,$3,symtable);}
     | expr EQUALS expr {$$ = new expr($1,$3,symtable);}
     | expr DIFF expr {$$ = new expr($1,$3,symtable);}
     | expr LT expr {$$ = new expr($1,$3,symtable);}
     | expr GT expr {$$ = new expr($1,$3,symtable);}
     | expr LEQ expr {$$ = new expr($1,$3,symtable);}
     | expr GEQ expr {$$ = new expr($1,$3,symtable);}
     | expr_tern {}
     | literal {$$ = new expr($1,symtable);}
     | identifier {
            $$ = new expr($1,symtable);
      };

expr_tern : TERNARY expr QUESTION_MARK expr COLON expr TERNARY {};



identifier : ID {
            $$ = new identifier(*$1);
      } %prec '@'
          | ID arrayAccess {$$ = new identifier(*$1);}
          | ID LEFT_PAREN lpar RIGHT_PAREN {$$ = new identifier(*$1);}
          | ID pointerAccess {$$ = new identifier(*$1);};


arrayAccess : LEFT_BRACKET expr RIGHT_BRACKET {}
               | LEFT_BRACKET expr RIGHT_BRACKET arrayAccess {};


lpar : /*epsilon*/ { }|
       expr lparAfter {};

lparAfter :  /*epsilon*/ {}
      | COMMA expr lparAfter {};

pointerAccess : ARROW ID {}
               | ARROW ID pointerAccess {};

literal : NUMBER {$$ = new literal("NUMBER");}
      | CHARACTER {$$ = new literal("CHAR");}
      | TRUE {$$ = new literal("BOOL");}
      | FALSE {$$ = new literal("BOOL");}
      | STRING {$$ = new literal("STRING");};

%% /* Fim da segunda seção */





int main (void) {
    
      root = initialize();

      return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
