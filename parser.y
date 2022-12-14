%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "value.hpp"
#include "symbol.cpp"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char* yytext;

state estado;
%}

%type <programaRet> prog
%type <statementsRet> stmts
%type <statementRet> stmt
%type <decl_funRet> decl_fun
%type <literalRet> literal
%type <identifierRet> identifier
%type <assign_exprRet> assign_expr
%type <all_decl_varRet> all_decl_var
%type <cmd_decl_varRet> cmd_decl_var
%type <assign_expr_maybeRet> assign_expr_maybe
%type <decl_var_primRet> decl_var_prim
%type <primitiveRet> primitive
%type <cochetezeromaisRet> cochetezeromais
%type <hashtagzeromaisRet> hashtagzeromais
%type <const_decl_varRet> const_decl_var
%type <type_nameRet> typename
%type <type_nameRet> type
%type <typedlparRet> typedlpar
%type <typedlparRet> typedlparAfter
%type <parameterRet> parameter
%type <name> parameterAfter
%type <exprRet> expr
%type <cazeRet> case
%type <cazeZeroRet> casezeromais
%type <switchRet> switch
%type <cmdRet> cmd
%type <cmd_condRet> cmd_cond
%type <cmd_loopRet> cmd_loop
%type <cmd_switchRet> cmd_switch
%type <elseRet> else
%type <ifRet> if
%type <loopRet> loop
%type <para_forRet> para_for
%type <forRet> for
%type <blockRet> block

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

%% /* Inicio da segunda se????o, onde colocamos as regras BNF */

prog : stmts {$$ = new programa(estado, $1);};

stmts : /* epsilon */ {$$ = NULL;}
      | stmt stmts {$$ = new statements($1,$2);};

stmt : decl_fun {$$ = new statement($1);}
     | cmd {$$ = new statement($1);};

decl_fun : FUNCTION type ID {
    add_sym(estado.tables, *$3, {$2->name, false});
    push_scope(estado.tables);
} LEFT_PAREN typedlpar RIGHT_PAREN block {$$ = new decl_fun($2,$6,$8);};

cmd : identifier assign_expr SEMICOLON {$$ = new cmd($1,$2);}
    | cmd_decl_var SEMICOLON {$$ = new cmd($1);}
    | inOut SEMICOLON {}
    | cmd_loop {$$ = new cmd(estado,$1);}
    | cmd_cond {$$ = new cmd($1);}
    | cmd_switch {$$ = new cmd($1);}
    | expr SEMICOLON {$$ = new cmd(estado, $1);}//cuidado com o construtor do exit when 
    | RETURN expr SEMICOLON {$$ = new cmd(estado, "RETURN", $2);}
    | RETURN SEMICOLON {$$ = new cmd(estado, "RETURN");}
    | CONTINUE SEMICOLON {$$ = new cmd(estado,"CONTINUE");}
    | EXIT WHEN expr SEMICOLON {$$ = new cmd(estado, "EXIT WHEN", $3);}
    | {push_scope(estado.tables);} block {$$ = new cmd($2);};

cmd_decl_var : all_decl_var assign_expr_maybe {$$ = new cmd_decl_var(estado,$1,$2);};

all_decl_var : decl_var_prim {$$ = new all_decl_var(estado,$1);}
             | const_decl_var {$$ = new all_decl_var(estado,$1);};

assign_expr_maybe : /*epsilon*/ {$$ = NULL;}
                  | assign_expr {$$ = new assign_expr_maybe($1);};

decl_var_prim : primitive hashtagzeromais cochetezeromais ID {
    $$ = new decl_var_prim($1,*$4);
};

const_decl_var : CONST decl_var_prim {$$ = new const_decl_var($2);};

hashtagzeromais : /*epsilon*/ {$$ = NULL;}
                | POINTER_VAL hashtagzeromais {$$ = new hashtagzeromais($2);};

cochetezeromais : /*epsilon*/ {$$ = NULL;}
                | LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais {$$ = new cochetezeromais($4);};

assign_expr : ASSIGN expr {$$ = new assign_expr($2);}
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

cmd_loop : for {$$ = new cmd_loop($1);}
      | loop {$$ = new cmd_loop($1);}

cmd_cond : if {$$ = new cmd_cond($1);};

cmd_switch : switch {$$ = new cmd_switch($1);};

for : FOR LEFT_PAREN para_for SEMICOLON para_for SEMICOLON para_for RIGHT_PAREN cmd {
    $$ = new fora(estado, $3, $5, $7, $9);
    };

para_for: cmd_decl_var {$$ = new para_for($1);}
        | expr {$$ = new para_for($1);}
        | expr INCREMENT {$$ = new para_for("++", $1);}
        | expr DECREMENT {$$ = new para_for("--", $1);};

loop : LOOP cmd {$$ = new loop(estado, $2);};

// ifrule
if : IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else {
    $$ = new ifa(estado, $3, $5, $7);
};

else :  /*epsilon*/ {$$ = NULL;}
      | ELSE cmd {$$ = new elsea(estado, $2);};

switch : SWITCH LEFT_PAREN expr RIGHT_PAREN {push_scope(estado.tables);} LEFT_BRACE casezeromais RIGHT_BRACE {
         pop_scope(estado.tables);
         $$ = new switcha(estado,$3,$7);
    };

casezeromais : /*epsilon*/ {$$ = new cazezeromais();}
      | case casezeromais {$$ = new cazezeromais(estado,$1,$2);};

case : CASE literal COLON stmts BREAK SEMICOLON {$$ = new caze($2, $4, true);}
     | CASE literal COLON stmts {$$ = new caze($2, $4, false);};

typename : primitive {$$ = new type_name($1);}
         | ID {$$ = new type_name(*$1);};

primitive : INT {$$ = new primitive("INT");}
          | REAL {$$ = new primitive("REAL");}
          | CHAR {$$ = new primitive("CHAR");}
          | BOOL {$$ = new primitive("BOOL");}
          | STR {$$ = new primitive("STRING");}
          | VOID {$$ = new primitive("VOID");};

type : typename hashtagzeromais cochetezeromais {$$ = $1;};

typedlpar : /*epsilon*/ {$$ = NULL;}
          | parameter typedlparAfter {$$ = new typedlpar(estado, $1, $2);}

typedlparAfter : /*epsilon*/ {$$ = NULL;}
               | COMMA parameter typedlparAfter {
    $$ = new typedlpar(estado, $2, $3);
};

parameter : type parameterAfter {$$ = new parameter($1, *$2);};

parameterAfter : ID {$$ = $1;}
               | REFERENCE ID {$$ = $2;};

block : LEFT_BRACE stmts RIGHT_BRACE {
    pop_scope(estado.tables);
    $$ = new block($2);
};

expr : INCREMENT expr {$$ = new expr(estado, "++", $2);}
     | DECREMENT expr {$$ = new expr(estado, "--", $2);}
     | LEFT_PAREN expr RIGHT_PAREN {$$ = new expr(estado, $2);}
     | MINUS expr {$$ = new expr(estado, "-", $2);}
     | NOT expr {$$ = new expr(estado, "!", $2);}
     | expr AND expr {$$ = new expr(estado, $1,"&", $3);}
     | expr OR expr {$$ = new expr(estado, $1,"|", $3);}
     | expr PLUS expr {$$ = new expr(estado, $1,"+", $3);}
     | expr TIMES expr {$$ = new expr(estado, $1,"*", $3);}
     | expr DIV expr {$$ = new expr(estado, $1,"/", $3);}
     | expr MINUS expr {$$ = new expr(estado, $1,"-", $3);}
     | expr MOD expr {$$ = new expr(estado, $1,"%", $3);}
     | expr EQUALS expr {$$ = new expr(estado, $1,"==", $3);}
     | expr DIFF expr {$$ = new expr(estado, $1,"!=", $3);}
     | expr LT expr {$$ = new expr(estado, $1,"<", $3);}
     | expr GT expr {$$ = new expr(estado, $1,">", $3);}
     | expr LEQ expr {$$ = new expr(estado, $1,"<=", $3);}
     | expr GEQ expr {$$ = new expr(estado, $1,">=", $3);}
     | expr_tern {}
     | literal {$$ = new expr(estado, $1);}
     | identifier {$$ = new expr(estado, $1);};

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

literal : NUMBER {$$ = new literal("NUMBER",yytext,estado);}
        | CHARACTER {$$ = new literal("CHAR",yytext,estado);}
        | TRUE {$$ = new literal("BOOL",yytext,estado);}
        | FALSE {$$ = new literal("BOOL",yytext,estado);}
        | STRING {$$ = new literal("STRING",yytext,estado);};

%% /* Fim da segunda se????o */

int main (void) {
      /* root = initialize(); */

    yyparse();
    if (estado.deuErro) {
        cout << "ERRO DE COMPILACAO\n";
    }
    else cout << estado.arquivoEscrita;
    return 0;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    
	return 0;
}
