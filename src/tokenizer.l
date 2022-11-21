%option noyywrap

%{
#include "tipos.hpp"


#include "y.tab.h"



int column = 0;
int char_count = 0;

typedef struct lval_s {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    char *lexeme;
    int token;
} lval;


/* all we have as symbols for the symbol table are identifiers. other possible
   symbols are, for example, goto labels */
typedef struct symbol_s {
    int scope;
    /* this is the actual name of the symbol. an id 'foo' has the name foo */
    char *name;
    char *type;
    bool is_const;
    lval val;
} symbol;

// since we have 128 ASCII characters, that's the max number of children our
// trie can have, even though we won't use all of them
#define N 128

typedef struct node_s {
    struct node_s *children[N];
    symbol sym;
    bool is_leaf;
} node;

node *init()
{
    node *root = (node*) calloc(1, sizeof(node));
    for (int i = 0; i < N; i++) root->children[i] = NULL;
    root->is_leaf = 0;

    return root;
}

node *add(node *root, char *word)
{
    node *tmp = root;

    for (int i = 0; word[i] != '\0'; i++) {
        /* get the relative position in the alphabet list */
        int position = (int) word[i] - 'a';

        if (tmp->children[position] == NULL)
            tmp->children[position] = init();

        tmp = tmp->children[position];
    }

    tmp->is_leaf = 1;

    return root;
}

node *find(node *root, char *word)
{
    /* searches for word in the trie */
    node *tmp = root;

    for(int i = 0; word[i] != '\0'; i++)
    {
        int position = word[i] - 'a';
        if (tmp->children[position] == NULL) return NULL;
        tmp = tmp->children[position];
    }

    if (tmp != NULL && tmp->is_leaf == 1) return tmp;

    return NULL;
}

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
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
endif    { lval val = {yylineno, column, yytext, ENDIF};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
else     { lval val = {yylineno, column, yytext, ELSE};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
switch   { lval val = {yylineno, column, yytext, SWITCH};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
case     { lval val = {yylineno, column, yytext, CASE};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
for      { lval val = {yylineno, column, yytext, FOR};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
loop     { lval val = {yylineno, column, yytext, LOOP};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
return   { lval val = {yylineno, column, yytext, RETURN};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
struct   { lval val = {yylineno, column, yytext, STRUCT};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
const    { lval val = {yylineno, column, yytext, CONST};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
break    { lval val = {yylineno, column, yytext, BREAK};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
continue { lval val = {yylineno, column, yytext, CONTINUE};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
read     { lval val = {yylineno, column, yytext, READ};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
write    { lval val = {yylineno, column, yytext, WRITE};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
exit     { lval val = {yylineno, column, yytext, EXIT};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }
when     { lval val = {yylineno, column, yytext, WHEN};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }

function   { lval val = {yylineno, column, yytext, FUNCTION};
           char_count += yyleng;
           column += yyleng;
           // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
           return val.token; }

int  { lval val = {yylineno, column, yytext, INT};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
real { lval val = {yylineno, column, yytext, REAL};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
char { lval val = {yylineno, column, yytext, CHAR};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
str  { lval val = {yylineno, column, yytext, STR};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
bool { lval val = {yylineno, column, yytext, BOOL};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
void { lval val = {yylineno, column, yytext, VOID};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }

\+  { lval val = {yylineno, column, yytext, PLUS};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
-   { lval val = {yylineno, column, yytext, MINUS};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\*  { lval val = {yylineno, column, yytext, TIMES};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\/  { lval val = {yylineno, column, yytext, DIV};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
%   { lval val = {yylineno, column, yytext, MOD};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
=   { lval val = {yylineno, column, yytext, ASSIGN};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\+= { lval val = {yylineno, column, yytext, ASSIGN_PLUS};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
-=  { lval val = {yylineno, column, yytext, ASSIGN_MINUS};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\*= { lval val = {yylineno, column, yytext, ASSIGN_MULT};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\/= { lval val = {yylineno, column, yytext, ASSIGN_DIV};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
%=  { lval val = {yylineno, column, yytext, ASSIGN_MOD};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
==  { lval val = {yylineno, column, yytext, EQUALS};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
!=  { lval val = {yylineno, column, yytext, DIFF};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\<  { lval val = {yylineno, column, yytext, LT};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\>  { lval val = {yylineno, column, yytext, GT};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\<= { lval val = {yylineno, column, yytext, LEQ};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
\>= { lval val = {yylineno, column, yytext, GEQ};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
(\|\||or) { lval val = {yylineno, column, yytext, OR};
            char_count += yyleng;
            column += yyleng;
            // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
            return val.token; }
(&&|and)  { lval val = {yylineno, column, yytext, AND};
            char_count += yyleng;
            column += yyleng;
            // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
            return val.token; }
(!|not)   { lval val = {yylineno, column, yytext, NOT};
            char_count += yyleng;
            column += yyleng;
            // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
            return val.token; }

(true)  { lval val = {yylineno, column, yytext, TRUE};
          char_count += yyleng;
          column += yyleng;
          // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
          return val.token; }
(false) { lval val = {yylineno, column, yytext, FALSE};
          char_count += yyleng;
          column += yyleng;
          // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
          return val.token; }
'.' { lval val = {yylineno, column, yytext, CHARACTER};
      char_count += yyleng;
      column += yyleng;
      // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
      return val.token; }
[+-]?[0-9]+(\.[0-9]+)?  { lval val = {yylineno, column, yytext, NUMBER};
                     char_count += yyleng;
                     column += yyleng;
                     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
                     return val.token; }
\"([^\"\\]|\\[abefnrtv\\\"])*\" { lval val = {yylineno, column, yytext, STRING};
                                  char_count += yyleng;
                                  column += yyleng;
                                  // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
                                  return val.token; }

\( { lval val = {yylineno, column, yytext, LEFT_PAREN};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }
\) { lval val = {yylineno, column, yytext, RIGHT_PAREN};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }
\{ { lval val = {yylineno, column, yytext, LEFT_BRACE};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }
\} { lval val = {yylineno, column, yytext, RIGHT_BRACE};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }
\[ { lval val = {yylineno, column, yytext, LEFT_BRACKET};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }
\] { lval val = {yylineno, column, yytext, RIGHT_BRACKET};
     char_count += yyleng;
     column += yyleng;
     // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
     return val.token; }

[a-z|A-Z|\_][a-z|A-Z|0-9|\_]* { lval val = {yylineno, column, yytext, ID};
                         symbol sym = {-1, yytext, NULL, false, val};
                         //add(sym_table, yytext);
                         char_count += yyleng;
                         column += yyleng;
                         // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
                         return val.token; }

\;   { lval val = {yylineno, column, yytext, SEMICOLON};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\?   { lval val = {yylineno, column, yytext, QUESTION_MARK};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\:   { lval val = {yylineno, column, yytext, COLON};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\.   { lval val = {yylineno, column, yytext, DOT};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
#    { lval val = {yylineno, column, yytext, POINTER_VAL};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
-\>  { lval val = {yylineno, column, yytext, ARROW};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\,   { lval val = {yylineno, column, yytext, COMMA};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\+\+ { lval val = {yylineno, column, yytext, INCREMENT};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
\-\- { lval val = {yylineno, column, yytext, DECREMENT};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
&    { lval val = {yylineno, column, yytext, REFERENCE};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }
@   { lval val = {yylineno, column, yytext, TERNARY};
       char_count += yyleng;
       column += yyleng;
       // printf("%d:%d %s %s\n", val.line, val.col, enumStr(val.token), val.lexeme);
       return val.token; }

\/\/.* { char_count += yyleng; }
%%

void print(node *root)
{
    if (!root) return;
    for (int i = 0; i < N; i++){
        if(root->children[i]!=NULL){
            printf("%c->",(char)('a'+i));
            print(root->children[i]);
        }
    }
    if (root->is_leaf) printf("\n");
}
