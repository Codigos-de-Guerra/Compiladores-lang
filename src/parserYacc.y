%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%token '[' IF ENDIF ELSE SWITCH CASE FOR LOOP RETURN STRUCT CONST BREAK CONTINUE READ WRITE EXIT WHEN FUNCTION INT REAL CHAR STR BOOL VOID PLUS MINUS TIMES DIV MOD TRUE FALSE NUMBER CHARACTER STRING LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET ID SEMICOLON QUESTION_MARK COLON DOT POINTER_VAL ARROW COMMA REFERENCE TERNARY ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULT ASSIGN_DIV ASSIGN_MOD ASSIGN
%start prog
%left '@'
%left LEFT_PAREN
%left RIGHT_PAREN
%left INCREMENT DECREMENT
%left NOT
%left OR AND
%left '-' '+'
%left '*' '/' '%'
%nonassoc EQUALS DIFF LT GT LEQ GEQ
%% /* Inicio da segunda seção, onde colocamos as regras BNF */

prog : stmts {printf(" stmts ");};

stmts : /* epsilon */ {printf(" /* epsilon */ ");}
      | stmt stmts {printf(" stmt stmts ");};

stmt : decl_fun {printf(" decl_fun ");}
      | cmd {printf(" cmd ");};

decl_fun : FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block {printf(" FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block ");};

cmd : cmd_decl_var SEMICOLON {printf(" cmd_decl_var SEMICOLON ");}
      | inOut SEMICOLON {printf(" inOut SEMICOLON ");}
      | cmd_loop {printf(" cmd_loop ");}
      | cmd_cond {printf(" cmd_cond ");}
      | cmd_switch {printf(" cmd_switch ");}
      | expr SEMICOLON {printf(" expr SEMICOLON ");}
      | RETURN expr SEMICOLON {printf(" RETURN expr SEMICOLON ");}
      | BREAK SEMICOLON {printf(" BREAK SEMICOLON ");}
      | CONTINUE SEMICOLON {printf(" CONTINUE SEMICOLON ");}
      | EXIT WHEN expr SEMICOLON {printf(" EXIT WHEN expr SEMICOLON ");}
      | block {printf(" block ");};

cmd_decl_var : all_decl_var assign_expr_maybe {printf(" all_decl_var assign_expr_maybe ");};

assign_expr_maybe : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | assign_expr {printf(" assign_expr ");};

all_decl_var : decl_var_prim {printf(" decl_var_prim ");}
            | const_decl_var {printf(" const_decl_var ");};

decl_var_prim : primitivos hashtagzeromais cochetezeromais ID {printf(" primitivos hashtagzeromais cochetezeromais ID ");};

const_decl_var : CONST decl_var_prim {printf(" CONST decl_var_prim ");};

hashtagzeromais : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | POINTER_VAL hashtagzeromais {printf(" POINTER_VAL hashtagzeromais ");};


cochetezeromais : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | LEFT_BRACKET NUMBER RIGHT_BRACKET cochetezeromais {printf(" LEFT_BRACKET NUMBER RIGHT_BRACKET cochetezeromais ");};

assign_expr : ASSIGN expr {printf(" ASSIGN expr ");}
            | assign_extra expr {printf(" assign_extra expr ");}
            | inc {printf(" inc ");};

assign_extra : ASSIGN_PLUS {printf(" ASSIGN_PLUS ");}
      | ASSIGN_MINUS {printf(" ASSIGN_MINUS ");}
      | ASSIGN_MULT {printf(" ASSIGN_MULT ");}
      | ASSIGN_DIV {printf(" ASSIGN_DIV ");}
      | ASSIGN_MOD {printf(" ASSIGN_MOD ");};

inc : DECREMENT {printf(" DECREMENT ");}
      | INCREMENT {printf(" INCREMENT ");};

inOut : in {printf(" in ");}
      | out {printf(" out ");};
in : READ LEFT_PAREN ID RIGHT_PAREN {printf(" READ LEFT_PAREN ID RIGHT_PAREN ");};
out : WRITE LEFT_PAREN ID RIGHT_PAREN {printf(" WRITE LEFT_PAREN ID RIGHT_PAREN ");};

cmd_loop : for {printf(" for ");}
      | loop {printf(" loop ");}

cmd_cond : if {printf(" if ");};

cmd_switch : switch {printf(" switch ");};

for : FOR LEFT_PAREN expr SEMICOLON expr SEMICOLON expr RIGHT_PAREN cmd {printf(" FOR LEFT_PAREN expr SEMICOLON expr SEMICOLON expr RIGHT_PAREN cmd ");};


loop : LOOP cmd {printf(" LOOP cmd ");};

if : IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else {printf(" IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else ");};

else :  /*epsilon*/ {printf("  /*epsilon*/ ");}
      | ELSE cmd {printf(" ELSE cmd ");};

switch : SWITCH LEFT_PAREN expr RIGHT_PAREN LEFT_BRACE casezeromais RIGHT_BRACE {printf(" SWITCH LEFT_PAREN expr RIGHT_PAREN LEFT_BRACE casezeromais RIGHT_BRACE ");};

casezeromais : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | case casezeromais {printf(" case casezeromais ");};

case : CASE literal COLON stmts {printf(" CASE literal COLON stmts ");};

type : typename {printf(" typename ");};
typename : primitivos {printf(" primitivos ");}
      | ID {printf(" ID ");};

primitivos : INT {printf(" INT ");}
      | REAL {printf(" REAL ");}
      | CHAR {printf(" CHAR ");}
      | BOOL {printf(" BOOL ");}
      | STR {printf(" STR ");}
      | VOID {printf(" VOID ");};

typedlpar : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | parameter typedlparAfter {printf(" parameter typedlparAfter ");}

typedlparAfter : /*epsilon*/ {printf(" /*epsilon*/ ");}
      | COMMA parameter typedlparAfter {printf(" COMMA parameter typedlparAfter ");};

parameter : type parameterAfter {printf(" type parameterAfter ");};

parameterAfter : ID {printf(" ID ");}
      | REFERENCE ID {printf(" REFERENCE ID ");};

block : LEFT_BRACE stmts RIGHT_BRACE {printf(" LEFT_BRACE stmts RIGHT_BRACE ");};

expr : INCREMENT expr {printf(" INCREMENT expr ");}
     | DECREMENT expr {printf(" DECREMENT expr ");}
     | LEFT_PAREN expr RIGHT_PAREN {printf(" LEFT_PAREN expr RIGHT_PAREN ");}
     | '-' identifier {printf(" '-' identifier ");}
     | NOT expr {printf(" NOT expr ");}
     | expr AND expr {printf(" expr AND expr ");}
     | expr OR expr {printf(" expr OR expr ");}
     | expr '+' expr {printf(" expr '+' expr ");}
     | expr '*' expr {printf(" expr '*' expr ");}
     | expr '/' expr {printf(" expr '/' expr ");}
     | expr '-' expr {printf(" expr '-' expr ");} 
     | expr '%' expr {printf(" expr 'mod' expr ");}
     | expr EQUALS expr {printf(" expr EQUALS expr ");}
     | expr DIFF expr {printf(" expr DIFF expr ");}
     | expr LT expr {printf(" expr LT expr ");}
     | expr GT expr {printf(" expr GT expr ");}
     | expr LEQ expr {printf(" expr LEQ expr ");}
     | expr GEQ expr {printf(" expr GEQ expr ");}
     | expr_tern {printf(" expr_tern ");}
     | NUMBER {printf(" NUMBER ");}
     | identifier {printf(" identifier ");}
     | TRUE {printf(" TRUE ");}
     | FALSE {printf(" FALSE ");}
     | CHARACTER {printf(" CHARACTER ");}
     | STRING {printf(" STRING ");};

expr_tern : TERNARY expr QUESTION_MARK expr COLON expr TERNARY {printf(" TERNARY expr QUESTION_MARK expr COLON expr TERNARY ");};



identifier : ID {printf(" ID ");} %prec '@'
          | ID arrayAccess {printf(" ID arrayAccess ");}
          | ID LEFT_PAREN lpar RIGHT_PAREN {printf(" ID LEFT_PAREN lpar RIGHT_PAREN ");}
          | ID pointerAccess {printf(" ID pointerAccess ");};


arrayAccess : LEFT_BRACKET expr RIGHT_BRACKET {printf(" LEFT_BRACKET expr RIGHT_BRACKET ");}
               | LEFT_BRACKET expr RIGHT_BRACKET arrayAccess {printf(" LEFT_BRACKET expr RIGHT_BRACKET arrayAccess ");};


lpar : /*epsilon*/ |
       expr lparAfter {};

lparAfter :  /*epsilon*/ {printf("  /*epsilon*/ ");}
      | COMMA expr lparAfter {printf(" COMMA expr lparAfter ");};

pointerAccess : ARROW ID {printf(" ARROW ID ");}
               | ARROW ID pointerAccess {printf(" ARROW ID pointerAccess ");};

literal : NUMBER {printf(" NUMBER ");}
      | CHARACTER {printf(" CHARACTER ");}
      | TRUE {printf(" TRUE ");}
      | FALSE {printf(" FALSE ");}
      | STRING {printf(" STRING ");};

%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}