%option noyywrap

%{
#include "value.hpp"

#include "y.tab.hpp"

int column = 0;
int char_count = 0;

typedef struct lval_s {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    char *lexeme;
    int token;
} lval;
%}

dig         [0-9]
alpha       [A-Z|a-z]
id          ({alpha}|\_)({alpha}|{dig}|\_)*

%%
[ \t\r\f]+ { char_count += yyleng;
             column += yyleng; }
\n+        { yylineno += yyleng;
             char_count += yyleng;
             column = 0; }

if       { lval val = {yylineno, column, yytext, IF};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
endif    { lval val = {yylineno, column, yytext, ENDIF};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
else     { lval val = {yylineno, column, yytext, ELSE};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
switch   { lval val = {yylineno, column, yytext, SWITCH};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
case     { lval val = {yylineno, column, yytext, CASE};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
for      { lval val = {yylineno, column, yytext, FOR};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
loop     { lval val = {yylineno, column, yytext, LOOP};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
return   { lval val = {yylineno, column, yytext, RETURN};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
struct   { lval val = {yylineno, column, yytext, STRUCT};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
const    { lval val = {yylineno, column, yytext, CONST};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
break    { lval val = {yylineno, column, yytext, BREAK};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
continue { lval val = {yylineno, column, yytext, CONTINUE};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
read     { lval val = {yylineno, column, yytext, READ};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
write    { lval val = {yylineno, column, yytext, WRITE};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
exit     { lval val = {yylineno, column, yytext, EXIT};
           char_count += yyleng;
           column += yyleng;
           return val.token; }
when     { lval val = {yylineno, column, yytext, WHEN};
           char_count += yyleng;
           column += yyleng;
           return val.token; }

function   { lval val = {yylineno, column, yytext, FUNCTION};
           char_count += yyleng;
           column += yyleng;
           return val.token; }

int  { lval val = {yylineno, column, yytext, INT};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
real { lval val = {yylineno, column, yytext, REAL};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
char { lval val = {yylineno, column, yytext, CHAR};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
str  { lval val = {yylineno, column, yytext, STR};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
bool { lval val = {yylineno, column, yytext, BOOL};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
void { lval val = {yylineno, column, yytext, VOID};
       char_count += yyleng;
       column += yyleng;
       return val.token; }

\+  { lval val = {yylineno, column, yytext, PLUS};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
-   { lval val = {yylineno, column, yytext, MINUS};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\*  { lval val = {yylineno, column, yytext, TIMES};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\/  { lval val = {yylineno, column, yytext, DIV};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
%   { lval val = {yylineno, column, yytext, MOD};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
=   { lval val = {yylineno, column, yytext, ASSIGN};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\+= { lval val = {yylineno, column, yytext, ASSIGN_PLUS};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
-=  { lval val = {yylineno, column, yytext, ASSIGN_MINUS};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\*= { lval val = {yylineno, column, yytext, ASSIGN_MULT};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\/= { lval val = {yylineno, column, yytext, ASSIGN_DIV};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
%=  { lval val = {yylineno, column, yytext, ASSIGN_MOD};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
==  { lval val = {yylineno, column, yytext, EQUALS};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
!=  { lval val = {yylineno, column, yytext, DIFF};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\<  { lval val = {yylineno, column, yytext, LT};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\>  { lval val = {yylineno, column, yytext, GT};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\<= { lval val = {yylineno, column, yytext, LEQ};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
\>= { lval val = {yylineno, column, yytext, GEQ};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
(\|\||or) { lval val = {yylineno, column, yytext, OR};
            char_count += yyleng;
            column += yyleng;
            return val.token; }
(&&|and)  { lval val = {yylineno, column, yytext, AND};
            char_count += yyleng;
            column += yyleng;
            return val.token; }
(!|not)   { lval val = {yylineno, column, yytext, NOT};
            char_count += yyleng;
            column += yyleng;
            return val.token; }

(true)  { lval val = {yylineno, column, yytext, TRUE};
          char_count += yyleng;
          column += yyleng;
          return val.token; }
(false) { lval val = {yylineno, column, yytext, FALSE};
          char_count += yyleng;
          column += yyleng;
          return val.token; }
'.' { lval val = {yylineno, column, yytext, CHARACTER};
      char_count += yyleng;
      column += yyleng;
      return val.token; }
[+-]?[0-9]+(\.[0-9]+)? { lval val = {yylineno, column, yytext, NUMBER};
                         char_count += yyleng;
                         column += yyleng;
                         return val.token; }
\"([^\"\\]|\\[abefnrtv\\\"])*\" { lval val = {yylineno, column, yytext, STRING};
                                  char_count += yyleng;
                                  column += yyleng;
                                  return val.token; }

\( { lval val = {yylineno, column, yytext, LEFT_PAREN};
     char_count += yyleng;
     column += yyleng;
     return val.token; }
\) { lval val = {yylineno, column, yytext, RIGHT_PAREN};
     char_count += yyleng;
     column += yyleng;
     return val.token; }
\{ { lval val = {yylineno, column, yytext, LEFT_BRACE};
     char_count += yyleng;
     column += yyleng;
     return val.token; }
\} { lval val = {yylineno, column, yytext, RIGHT_BRACE};
     char_count += yyleng;
     column += yyleng;
     return val.token; }
\[ { lval val = {yylineno, column, yytext, LEFT_BRACKET};
     char_count += yyleng;
     column += yyleng;
     return val.token; }
\] { lval val = {yylineno, column, yytext, RIGHT_BRACKET};
     char_count += yyleng;
     column += yyleng;
     return val.token; }

[a-z|A-Z|\_][a-z|A-Z|0-9|\_]* { lval val = {yylineno, column, yytext, ID};
                                char_count += yyleng;
                                column += yyleng;
                                yylval.name = new std::string(yytext);
                                return val.token; }

\;   { lval val = {yylineno, column, yytext, SEMICOLON};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\?   { lval val = {yylineno, column, yytext, QUESTION_MARK};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\:   { lval val = {yylineno, column, yytext, COLON};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\.   { lval val = {yylineno, column, yytext, DOT};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\#   { lval val = {yylineno, column, yytext, POINTER_VAL};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
-\>  { lval val = {yylineno, column, yytext, ARROW};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\,   { lval val = {yylineno, column, yytext, COMMA};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\+\+ { lval val = {yylineno, column, yytext, INCREMENT};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
\-\- { lval val = {yylineno, column, yytext, DECREMENT};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
&    { lval val = {yylineno, column, yytext, REFERENCE};
       char_count += yyleng;
       column += yyleng;
       return val.token; }
@   { lval val = {yylineno, column, yytext, TERNARY};
       char_count += yyleng;
       column += yyleng;
       return val.token; }

\/\/.* { char_count += yyleng; }
%%
