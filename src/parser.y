%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tipos.hpp"
#include "symbol.cpp"

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

list<symtable> tables {{}};
%}

%type <literalRet> literal
%type <cmdRet> cmd
%type <identifierRet> identifier
%type <assign_exprRet> assign_expr
%type <all_decl_varRet> all_decl_var
%type <cmd_decl_varRet> cmd_decl_var
%type <assign_expr_maybeRet> assign_expr_maybe
%type <decl_var_primRet> decl_var_prim
%type <primitiveRet> primitive
%type <cochetezeromaisRet> cochetezeromais
%type <hashtagzeromaisRet>hashtagzeromais
%type <const_decl_varRet> const_decl_var
%type <exprRet> expr

%token '['
%token IF
%token ENDIF
%token ELSE
%token SWITCH
%token CASE
%token FOR
%token LOOP
%token RETURN
%token STRUCT
%token CONST
%token BREAK
%token CONTINUE
%token READ
%token WRITE
%token EXIT
%token WHEN
%token FUNCTION
%token INT
%token REAL
%token CHAR
%token STR
%token BOOL
%token VOID
%token PLUS
%token MINUS
%token TIMES
%token DIV
%token MOD
%token TRUE
%token FALSE
%token NUMBER
%token CHARACTER
%token STRING
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token SEMICOLON
%token QUESTION_MARK
%token COLON
%token DOT
%token POINTER_VAL
%token ARROW
%token COMMA
%token REFERENCE
%token TERNARY
%token ASSIGN_PLUS
%token ASSIGN_MINUS
%token ASSIGN_MULT
%token ASSIGN_DIV
%token ASSIGN_MOD
%token ASSIGN
%token <name> ID

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

cmd_decl_var : all_decl_var assign_expr_maybe {$$ = new cmd_decl_var($1,$2);};

assign_expr_maybe : /*epsilon*/ {$$ = NULL;}
                  | assign_expr {$$ = new assign_expr_maybe();};

all_decl_var : decl_var_prim {$$ = new all_decl_var($1,tables);}
             | const_decl_var {$$ = new all_decl_var($1,tables);};

decl_var_prim : primitive hashtagzeromais cochetezeromais ID {
    $$ = new decl_var_prim($1,*$4);
};

const_decl_var : CONST decl_var_prim {$$ = new const_decl_var($2);};

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

typename : primitive {}
         | ID {};

primitive : INT {$$ = new primitive("INT");}
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

expr : INCREMENT expr {$$ = new expr($2,tables);}
     | DECREMENT expr {$$ = new expr($2,tables);}
     | LEFT_PAREN expr RIGHT_PAREN {$$ = new expr($2,tables);}
     | MINUS identifier {$$ = new expr($2,tables);}
     | NOT expr {$$ = new expr($2,tables);}
     | expr AND expr {$$ = new expr($1,$3,tables);}
     | expr OR expr {$$ = new expr($1,$3,tables);}
     | expr PLUS expr {$$ = new expr($1,$3,tables);}
     | expr TIMES expr {$$ = new expr($1,$3,tables);}
     | expr DIV expr {$$ = new expr($1,$3,tables);}
     | expr MINUS expr {$$ = new expr($1,$3,tables);}
     | expr MOD expr {$$ = new expr($1,$3,tables);}
     | expr EQUALS expr {$$ = new expr($1,$3,tables);}
     | expr DIFF expr {$$ = new expr($1,$3,tables);}
     | expr LT expr {$$ = new expr($1,$3,tables);}
     | expr GT expr {$$ = new expr($1,$3,tables);}
     | expr LEQ expr {$$ = new expr($1,$3,tables);}
     | expr GEQ expr {$$ = new expr($1,$3,tables);}
     | expr_tern {}
     | literal {$$ = new expr($1,tables);}
     | identifier {$$ = new expr($1,tables);};

expr_tern : TERNARY expr QUESTION_MARK expr COLON expr TERNARY {};

identifier : ID {$$ = new identifier(*$1);} %prec '@'
           | ID arrayAccess {$$ = new identifier(*$1);}
           | ID LEFT_PAREN lpar RIGHT_PAREN {$$ = new identifier(*$1);}
           | ID pointerAccess {$$ = new identifier(*$1);};

arrayAccess : LEFT_BRACKET expr RIGHT_BRACKET {}
              | LEFT_BRACKET expr RIGHT_BRACKET arrayAccess {};

lpar : /*epsilon*/ {}
     | expr lparAfter {};

lparAfter : /*epsilon*/ {}
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
