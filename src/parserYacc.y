%{
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "customString.c"
int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;



typedef struct lval_s {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    char *lexeme;
    int token;
} lval;

typedef enum { false, true } bool;

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
      char* word = simbolo.name;
    for (int i = 0; word[i] != '\0'; i++) {
        /* get the relative position in the alphabet list */
        int position = (int) word[i] - 'a';

        if (tmp->children[position] == NULL)
            tmp->children[position] = initialize();

        tmp = tmp->children[position];
    }

    tmp->is_leaf = 1;

      tmp->sym = simbolo;
}

node *acha(symbol simbolo)
{
    /* searches for word in the trie */
    node *tmp = root;
char* word = simbolo.name;
    for(int i = 0; word[i] != '\0'; i++)
    {
        int position = word[i] - 'a';
        if (tmp->children[position] == NULL) return NULL;
        tmp = tmp->children[position];
    }

    if (tmp != NULL && tmp->is_leaf == 1) return tmp;

    return NULL;
}

//<string implementation from https://gist.github.com/water-air-flash/fb74ab18c53c485769c2a6cd1b81f082>

string *str_create(char *init) {
    string *s = (string *)malloc(sizeof(string));

    if(!s) return NULL;

    s->size = MAX(strlen(init) + 1, STRSIZE);
    s->str = (char *)malloc(s->size);

    strcpy(s->str, init);

    return s;
}

void str_free(string *s) {
    free(s->str);
    free(s);
}

void str_growto(string *s, unsigned int newsize) {
    if(newsize <= s->size) return;

    unsigned int oldsize = s->size;

    while(s->size < newsize)
        s->size *= 2;
    
    s->str = (char *)realloc((void *)s->str, s->size);

    memset((void *)(s->str + oldsize), '\0', s->size - oldsize);
}

void str_grow(string *s) {
    str_growto(s, s->size * 2);
}

void str_shrink(string *s) {
    s->size /= 2;
    s->size = MAX(s->size, STRSIZE);
    s->str = (char *)realloc((void *)s->str, s->size);
    s->str[s->size-1] = '\0';
}

unsigned int str_sizeof(string *s) {
    return s->size;
}

unsigned int str_length(string *s) {
    return strlen(s->str);
}

char str_getc(string *s, unsigned int index) {
    if(index >= s->size) return '\0';

    return s->str[index];
}

char *str_get(string *s) {
    return s->str;
}

void str_append(string *s, char *app) {
    int len = strlen(s->str);

    str_growto(s, s->size + len);

    int i;
    for(i = 0; i < strlen(app); i++) {
        s->str[len+i] = app[i];
    }
}

void str_cappend(string *s, char c) {
    unsigned int len = strlen(s->str);

    if(len >= s->size-1)
        str_grow(s);

    s->str[len] = c;
}

void str_set(string *s, char *newstr) {
    str_growto(s, s->size + strlen(newstr));
    strcpy(s->str, newstr);
}

//</string implementation>


%}




%union {
       string* tipo;
      }

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

prog : stmts {
      char* c1 = "adicionar";
      symbol s;
      s.name = c1;
      adiciona(s);
      printf("%d",acha(s)==NULL);
};

stmts : /* epsilon */ {}
      | stmt stmts {};

stmt : decl_fun {}
      | cmd {};

decl_fun : FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block {};

cmd :  identifier assign_expr SEMICOLON {}
      |cmd_decl_var SEMICOLON {}
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

cmd_decl_var : all_decl_var assign_expr_maybe {};

assign_expr_maybe : /*epsilon*/ {}
      | assign_expr {};


all_decl_var : decl_var_prim {}
            | const_decl_var {};

decl_var_prim : primitivos hashtagzeromais cochetezeromais ID {};
const_decl_var : CONST decl_var_prim {}; 

hashtagzeromais : /*epsilon*/ {}
      | POINTER_VAL hashtagzeromais {};


cochetezeromais : /*epsilon*/ {}
      | LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais {};

assign_expr : ASSIGN expr {}
            | assign_extra expr {}
            | inc {};

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
     | '-' identifier {}
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
     | expr_tern {}
     | literal {}
     | identifier {};

expr_tern : TERNARY expr QUESTION_MARK expr COLON expr TERNARY {};



identifier : ID {} %prec '@'
          | ID arrayAccess {}
          | ID LEFT_PAREN lpar RIGHT_PAREN {}
          | ID pointerAccess {};


arrayAccess : LEFT_BRACKET expr RIGHT_BRACKET {}
               | LEFT_BRACKET expr RIGHT_BRACKET arrayAccess {};


lpar : /*epsilon*/ { }|
       expr lparAfter {};

lparAfter :  /*epsilon*/ {}
      | COMMA expr lparAfter {};

pointerAccess : ARROW ID {}
               | ARROW ID pointerAccess {};

literal : NUMBER {$<tipo>$ = str_create("NUMBER");}
      | CHARACTER {$<tipo>$ = str_create("CHAR");}
      | TRUE {$<tipo>$ = str_create("BOOL");}
      | FALSE {$<tipo>$ = str_create("BOOL");}
      | STRING {$<tipo>$ = str_create("STRING");};

%% /* Fim da segunda seção */





int main (void) {
      root = initialize();

      //return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}