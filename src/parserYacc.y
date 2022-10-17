%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%token '[' IF ENDIF ELSE SWITCH CASE FOR LOOP RETURN STRUCT CONST BREAK CONTINUE READ WRITE EXIT WHEN FUNCTION INT REAL CHAR STR BOOL VOID PLUS MINUS TIMES DIV MOD TRUE FALSE NUMBER CHARACTER STRING LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET ID SEMICOLON QUESTION_MARK COLON DOT POINTER_VAL ARROW COMMA REFERENCE TERNARY ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULT ASSIGN_DIV ASSIGN_MOD ASSIGN
%start prog
%left LEFT_PAREN
%left RIGHT_PAREN
%left INCREMENT DECREMENT
%left NOT
%left OR AND
%left '+' '-'
%left '*' '/' '%'
%nonassoc EQUALS DIFF LT GT LEQ GEQ
%% /* Inicio da segunda seção, onde colocamos as regras BNF */

prog : stmts {};

stmts : /* epsilon */ {}
      | stmt stmts {};

stmt : decl_fun {}
      | expr {};

decl_fun : FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block {};

type : typename {};
typename : primitivos {}
      | ID {};

primitivos : INT {}
      | REAL {}
      | CHAR {}
      | BOOL {}
      | STR {}
      | VOID {};

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
     | '-' expr {}
     | NOT expr {}
     | expr AND expr {}
     | expr OR expr {}
     | expr '+' expr {}
     | expr '*' expr {}
     | expr '/' expr {}
     | expr '-' expr {}
     | expr '%' expr {}
     | expr EQUALS expr {}
     | expr DIFF expr {}
     | expr LT expr {}
     | expr GT expr {}
     | expr LEQ expr {}
     | expr GEQ expr {}
     | NUMBER {}
     | identifier {}
     | TRUE {}
     | FALSE {}
     | CHARACTER {}
     | STRING {};

identifier : ID {}
          | ID arrayAccess {}
          | ID funcall {}
          | ID pointerAccess {};

arrayAccess : '[' expr ']' {}
               | '[' expr ']' arrayAccess {};

funcall : LEFT_PAREN lpar RIGHT_PAREN {};

lpar : /*epsilon*/ |
       expr lparAfter {};

lparAfter :  /*epsilon*/ {}
      | COMMA expr lparAfter {};

pointerAccess : ARROW ID {}
               | ARROW ID pointerAccess {};

%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}