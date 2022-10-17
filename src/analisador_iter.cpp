#include <iostream>
#include "lex.yy.c"

int tok;
void advance() {
  printf("entrei no advance\n");
  tok = yylex();
  printf("li o token %d\n",tok);
  if (tok == ENDOFFILE) exit(0);
}

void error() {
  printf("erro\n");
  exit(0);
}

void error2(){
    printf("erro2\n");
    exit(0);
}

void EAT(tokens t) {
  printf("preciso do token %d\n", t);
  if (tok == t) {
    printf("comendo o %d\n", t);
    advance();
  }
  else error();
}

void T_S(void);
void T_PROGRAM(void);
void T_STMTS(void);
void T_STMT(void);
void T_ALL_DECL_VAR(void);
void T_DECL_VAR_PRIM(void);
void T_ASSIGN_EXPR(void);
void T_INC_EXPR(void);
void T_CONST_DECL_VAR(void);
void T_DECL_FUNC(void);
void T_DECL_STRUCT(void);
void T_BLOCK(void);
void T_TYPEDLPAR(void);
void T_TYPEDLPARAFTER(void);
void T_PARAMETER(void);
void T_PARAMETERAFTER(void);
void T_CMD(void);
void T_IDAFTERRULE(void);
void T_IDAFTERAFTERRULE(void);
void T_CMD_DECL_VAR(void);
void T_ASSIGN_EXPR_MAYBE(void);
void T_CMD_LOOP(void);
void T_CMD_COND(void);
void T_CMD_SWITCH(void);
void T_FOR(void);
void T_FOR_STMT(void);
void T_LOOP(void);
void T_IF(void);
void T_ELSE(void);
void T_SWITCH(void);
void T_CASEZEROMAIS(void);
void T_CASE(void);
void T_FUNCALL(void);
void T_LPAR(void);
void T_LPARAFTER(void);
void T_EXPR_TERN(void);
void T_OP_UN(void);
void T_OP_BIN(void);
void T_OP_MATH(void);
void T_ASSIGN_EXTRA(void);
void T_OP_LOGIC(void);
void T_INC(void);
void T_INOUT(void);
void T_IN(void);
void T_OUT(void);
void T_TYPE(void);
void T_TYPENAME(void);
void T_PRIMITIVOS(void);
void T_HASHTAGZEROMAIS(void);
void T_LITERAL(void);
void T_ARRAY_ACCESS(void);
void T_COCHETEZEROMAIS(void);
void T_INSIDE_COCHETE(void);
void T_TERMAFTER(void);
void T_PONTEIROZEROMAIS(void);
void T_EXPR(void);
void T_EXPR_WITHOUT_TERM(void);
void T_EXPR_BINMAYBE(void);

void T_S(void) {
  printf("fun(S)\n");
  switch(tok){
    case ID:
      T_PROGRAM();
      break;
    case CONST:
      T_PROGRAM();
      break;
    case FUNCTION:
      T_PROGRAM();
      break;
    case LEFT_PAREN:
      T_PROGRAM();
      break;
    case STRUCT:
      T_PROGRAM();
      break;
    case SEMICOLON:
      T_PROGRAM();
      break;
    case LEFT_BRACE:
      T_PROGRAM();
      break;
    case RETURN:
      T_PROGRAM();
      break;
    case BREAK:
      T_PROGRAM();
      break;
    case CONTINUE:
      T_PROGRAM();
      break;
    case EXIT:
      T_PROGRAM();
      break;
    case FOR:
      T_PROGRAM();
      break;
    case LOOP:
      T_PROGRAM();
      break;
    case IF:
      T_PROGRAM();
      break;
    case SWITCH:
      T_PROGRAM();
      break;
    case TERNARY:
      T_PROGRAM();
      break;
    case NOT:
      T_PROGRAM();
      break;
    case DECREMENT:
      T_PROGRAM();
      break;
    case INCREMENT:
      T_PROGRAM();
      break;
    case READ:
      T_PROGRAM();
      break;
    case WRITE:
      T_PROGRAM();
      break;
    case INT:
      T_PROGRAM();
      break;
    case REAL:
      T_PROGRAM();
      break;
    case CHAR:
      T_PROGRAM();
      break;
    case BOOL:
      T_PROGRAM();
      break;
    case STR:
      T_PROGRAM();
      break;
    case VOID:
      T_PROGRAM();
      break;
    case NUMBER:
      T_PROGRAM();
      break;
    case CHARACTER:
      T_PROGRAM();
      break;
    case TRUE:
      T_PROGRAM();
      break;
    case FALSE:
      T_PROGRAM();
      break;
    case STRING:
      T_PROGRAM();
      break;
    default: error();
  }
}

void T_PROGRAM(void) {
  printf("fun(program)\n");
  switch(tok){
    case ID:
      T_STMTS();
      break;
    case CONST:
      T_STMTS();
      break;
    case FUNCTION:
      T_STMTS();
      break;
    case LEFT_PAREN:
      T_STMTS();
      break;
    case STRUCT:
      T_STMTS();
      break;
    case SEMICOLON:
      T_STMTS();
      break;
    case LEFT_BRACE:
      T_STMTS();
      break;
    case RETURN:
      T_STMTS();
      break;
    case BREAK:
      T_STMTS();
      break;
    case CONTINUE:
      T_STMTS();
      break;
    case EXIT:
      T_STMTS();
      break;
    case FOR:
      T_STMTS();
      break;
    case LOOP:
      T_STMTS();
      break;
    case IF:
      T_STMTS();
      break;
    case SWITCH:
      T_STMTS();
      break;
    case TERNARY:
      T_STMTS();
      break;
    case NOT:
      T_STMTS();
      break;
    case DECREMENT:
      T_STMTS();
      break;
    case INCREMENT:
      T_STMTS();
      break;
    case READ:
      T_STMTS();
      break;
    case WRITE:
      T_STMTS();
      break;
    case INT:
      T_STMTS();
      break;
    case REAL:
      T_STMTS();
      break;
    case CHAR:
      T_STMTS();
      break;
    case BOOL:
      T_STMTS();
      break;
    case STR:
      T_STMTS();
      break;
    case VOID:
      T_STMTS();
      break;
    case NUMBER:
      T_STMTS();
      break;
    case CHARACTER:
      T_STMTS();
      break;
    case TRUE:
      T_STMTS();
      break;
    case FALSE:
      T_STMTS();
      break;
    case STRING:
      T_STMTS();
      break;
    default: error();
  }
}

void T_STMTS(void) {
  printf("fun(stmts)\n");
  switch(tok){
    case ID:
      T_STMT();
      T_STMTS();
      break;
    case CONST:
      T_STMT();
      T_STMTS();
      break;
    case FUNCTION:
      T_STMT();
      T_STMTS();
      break;
    case LEFT_PAREN:
      T_STMT();
      T_STMTS();
      break;
    case STRUCT:
      T_STMT();
      T_STMTS();
      break;
    case SEMICOLON:
      T_STMT();
      T_STMTS();
      break;
    case LEFT_BRACE:
      T_STMT();
      T_STMTS();
      break;
    case RIGHT_BRACE:
      break;
    case RETURN:
      T_STMT();
      T_STMTS();
      break;
    case BREAK:
      T_STMT();
      T_STMTS();
      break;
    case CONTINUE:
      T_STMT();
      T_STMTS();
      break;
    case EXIT:
      T_STMT();
      T_STMTS();
      break;
    case FOR:
      T_STMT();
      T_STMTS();
      break;
    case LOOP:
      T_STMT();
      T_STMTS();
      break;
    case IF:
      T_STMT();
      T_STMTS();
      break;
    case SWITCH:
      T_STMT();
      T_STMTS();
      break;
    case CASE:
      break;
    case TERNARY:
      T_STMT();
      T_STMTS();
      break;
    case NOT:
      T_STMT();
      T_STMTS();
      break;
    case DECREMENT:
      T_STMT();
      T_STMTS();
      break;
    case INCREMENT:
      T_STMT();
      T_STMTS();
      break;
    case READ:
      T_STMT();
      T_STMTS();
      break;
    case WRITE:
      T_STMT();
      T_STMTS();
      break;
    case INT:
      T_STMT();
      T_STMTS();
      break;
    case REAL:
      T_STMT();
      T_STMTS();
      break;
    case CHAR:
      T_STMT();
      T_STMTS();
      break;
    case BOOL:
      T_STMT();
      T_STMTS();
      break;
    case STR:
      T_STMT();
      T_STMTS();
      break;
    case VOID:
      T_STMT();
      T_STMTS();
      break;
    case NUMBER:
      T_STMT();
      T_STMTS();
      break;
    case CHARACTER:
      T_STMT();
      T_STMTS();
      break;
    case TRUE:
      T_STMT();
      T_STMTS();
      break;
    case FALSE:
      T_STMT();
      T_STMTS();
      break;
    case STRING:
      T_STMT();
      T_STMTS();
      break;
    default: error();
  }
}

void T_STMT(void) {
  printf("fun(stmt)\n");
  switch(tok){
    case ID:
      T_CMD();
      break;
    case CONST:
      T_CMD();
      break;
    case FUNCTION:
      T_DECL_FUNC();
      break;
    case LEFT_PAREN:
      T_CMD();
      break;
    case STRUCT:
      T_DECL_STRUCT();
      break;
    case SEMICOLON:
      T_CMD();
      break;
    case LEFT_BRACE:
      T_CMD();
      break;
    case RETURN:
      T_CMD();
      break;
    case BREAK:
      T_CMD();
      break;
    case CONTINUE:
      T_CMD();
      break;
    case EXIT:
      T_CMD();
      break;
    case FOR:
      T_CMD();
      break;
    case LOOP:
      T_CMD();
      break;
    case IF:
      T_CMD();
      break;
    case SWITCH:
      T_CMD();
      break;
    case TERNARY:
      T_CMD();
      break;
    case NOT:
      T_CMD();
      break;
    case DECREMENT:
      T_CMD();
      break;
    case INCREMENT:
      T_CMD();
      break;
    case READ:
      T_CMD();
      break;
    case WRITE:
      T_CMD();
      break;
    case INT:
      T_CMD();
      break;
    case REAL:
      T_CMD();
      break;
    case CHAR:
      T_CMD();
      break;
    case BOOL:
      T_CMD();
      break;
    case STR:
      T_CMD();
      break;
    case VOID:
      T_CMD();
      break;
    case NUMBER:
      T_CMD();
      break;
    case CHARACTER:
      T_CMD();
      break;
    case TRUE:
      T_CMD();
      break;
    case FALSE:
      T_CMD();
      break;
    case STRING:
      T_CMD();
      break;
    default: error();
  }
}

void T_ALL_DECL_VAR(void) {
  printf("fun(all_decl_var)\n");
  switch(tok){
    case CONST:
      T_CONST_DECL_VAR();
      break;
    case INT:
      T_DECL_VAR_PRIM();
      break;
    case REAL:
      T_DECL_VAR_PRIM();
      break;
    case CHAR:
      T_DECL_VAR_PRIM();
      break;
    case BOOL:
      T_DECL_VAR_PRIM();
      break;
    case STR:
      T_DECL_VAR_PRIM();
      break;
    case VOID:
      T_DECL_VAR_PRIM();
      break;
    default: error();
  }
}

void T_DECL_VAR_PRIM(void) {
  printf("fun(decl_var_prim)\n");
  switch(tok){
    case INT:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    case REAL:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    case CHAR:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    case BOOL:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    case STR:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    case VOID:
      T_PRIMITIVOS();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      EAT(ID);
      break;
    default: error();
  }
}

void T_ASSIGN_EXPR(void) {
  printf("fun(assign_expr)\n");
  switch(tok){
    case ASSIGN:
      EAT(ASSIGN);
      T_EXPR();
      break;
    case ASSIGN_PLUS:
      T_ASSIGN_EXTRA();
      T_EXPR();
      break;
    case ASSIGN_MINUS:
      T_ASSIGN_EXTRA();
      T_EXPR();
      break;
    case ASSIGN_MULT:
      T_ASSIGN_EXTRA();
      T_EXPR();
      break;
    case ASSIGN_DIV:
      T_ASSIGN_EXTRA();
      T_EXPR();
      break;
    case ASSIGN_MOD:
      T_ASSIGN_EXTRA();
      T_EXPR();
      break;
    case DECREMENT:
      T_INC();
      break;
    case INCREMENT:
      T_INC();
      break;
    default: error();
  }
}

void T_INC_EXPR(void) {
  printf("fun(inc_expr)\n");
  switch(tok){
    case DECREMENT:
      T_INC();
      EAT(ID);
      break;
    case INCREMENT:
      T_INC();
      EAT(ID);
      break;
    default: error();
  }
}

void T_CONST_DECL_VAR(void) {
  printf("fun(const_decl_var)\n");
  switch(tok){
    case CONST:
      EAT(CONST);
      T_DECL_VAR_PRIM();
      break;
    default: error();
  }
}

void T_DECL_FUNC(void) {
  printf("fun(decl_func)\n");
  switch(tok){
    case FUNCTION:
      EAT(FUNCTION);
      T_TYPE();
      EAT(ID);
      EAT(LEFT_PAREN);
      T_TYPEDLPAR();
      EAT(RIGHT_PAREN);
      T_BLOCK();
      break;
    default: error();
  }
}

void T_DECL_STRUCT(void) {
  printf("fun(decl_struct)\n");
  switch(tok){
    case STRUCT:
      EAT(STRUCT);
      EAT(ID);
      T_BLOCK();
      EAT(SEMICOLON);
      break;
    default: error();
  }
}

void T_BLOCK(void) {
  printf("fun(block)\n");
  switch(tok){
    case LEFT_BRACE:
      EAT(LEFT_BRACE);
      T_STMTS();
      EAT(RIGHT_BRACE);
      break;
    default: error();
  }
}

void T_TYPEDLPAR(void) {
  printf("fun(typedlpar)\n");
  switch(tok){
    case ID:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case RIGHT_PAREN:
      break;
    case INT:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case REAL:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case CHAR:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case BOOL:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case STR:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    case VOID:
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    default: error();
  }
}

void T_TYPEDLPARAFTER(void) {
  printf("fun(typedlparAfter)\n");
  switch(tok){
    case RIGHT_PAREN:
      break;
    case COMMA:
      EAT(COMMA);
      T_PARAMETER();
      T_TYPEDLPARAFTER();
      break;
    default: error();
  }
}

void T_PARAMETER(void) {
  printf("fun(parameter)\n");
  switch(tok){
    case ID:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case INT:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case REAL:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case CHAR:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case BOOL:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case STR:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    case VOID:
      T_TYPE();
      T_PARAMETERAFTER();
      break;
    default: error();
  }
}

void T_PARAMETERAFTER(void) {
  printf("fun(parameterAfter)\n");
  switch(tok){
    case ID:
      EAT(ID);
      break;
    case REFERENCE:
      EAT(REFERENCE);
      EAT(ID);
      break;
    default: error();
  }
}

void T_CMD(void) {
  printf("fun(cmd)\n");
  switch(tok){
    case ID:
      T_IDAFTERRULE();
      EAT(SEMICOLON);
      break;
    case CONST:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case LEFT_PAREN:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case SEMICOLON:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case LEFT_BRACE:
      T_BLOCK();
      break;
    case RETURN:
      EAT(RETURN);
      T_EXPR();
      EAT(SEMICOLON);
      break;
    case BREAK:
      EAT(BREAK);
      EAT(SEMICOLON);
      break;
    case CONTINUE:
      EAT(CONTINUE);
      EAT(SEMICOLON);
      break;
    case EXIT:
      EAT(EXIT);
      EAT(WHEN);
      T_EXPR();
      EAT(SEMICOLON);
      break;
    case FOR:
      T_CMD_LOOP();
      break;
    case LOOP:
      T_CMD_LOOP();
      break;
    case IF:
      T_CMD_COND();
      break;
    case SWITCH:
      T_CMD_SWITCH();
      break;
    case TERNARY:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case NOT:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case DECREMENT:
      T_IDAFTERRULE();
      EAT(SEMICOLON);
      break;
    case INCREMENT:
      T_IDAFTERRULE();
      EAT(SEMICOLON);
      break;
    case READ:
      T_INOUT();
      EAT(SEMICOLON);
      break;
    case WRITE:
      T_INOUT();
      EAT(SEMICOLON);
      break;
    case INT:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case REAL:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case CHAR:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case BOOL:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case STR:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case VOID:
      T_CMD_DECL_VAR();
      EAT(SEMICOLON);
      break;
    case NUMBER:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case CHARACTER:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case TRUE:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case FALSE:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    case STRING:
      T_EXPR_WITHOUT_TERM();
      EAT(SEMICOLON);
      break;
    default: error();
  }
}

void T_IDAFTERRULE(void) {
  printf("fun(idAfterRule)\n");
  switch(tok){
    case ID:
      EAT(ID);
      T_TERMAFTER();
      T_IDAFTERAFTERRULE();
      break;
    case DECREMENT:
      T_INC();
      EAT(ID);
      T_COCHETEZEROMAIS();
      break;
    case INCREMENT:
      T_INC();
      EAT(ID);
      T_COCHETEZEROMAIS();
      break;
    default: error();
  }
}

void T_IDAFTERAFTERRULE(void) {
  printf("fun(idAfterAfterRule)\n");
  switch(tok){
    case ID:
      EAT(ID);
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case ASSIGN:
      T_ASSIGN_EXPR();
      break;
    case RIGHT_PAREN:
      T_EXPR_BINMAYBE();
      break;
    case SEMICOLON:
      T_EXPR_BINMAYBE();
      break;
    case MINUS:
      T_EXPR_BINMAYBE();
      break;
    case PLUS:
      T_EXPR_BINMAYBE();
      break;
    case DIV:
      T_EXPR_BINMAYBE();
      break;
    case TIMES:
      T_EXPR_BINMAYBE();
      break;
    case MOD:
      T_EXPR_BINMAYBE();
      break;
    case ASSIGN_PLUS:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MINUS:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MULT:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_DIV:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MOD:
      T_ASSIGN_EXPR();
      break;
    case EQUALS:
      T_EXPR_BINMAYBE();
      break;
    case DIFF:
      T_EXPR_BINMAYBE();
      break;
    case LEQ:
      T_EXPR_BINMAYBE();
      break;
    case GEQ:
      T_EXPR_BINMAYBE();
      break;
    case GT:
      T_EXPR_BINMAYBE();
      break;
    case LT:
      T_EXPR_BINMAYBE();
      break;
    case AND:
      T_EXPR_BINMAYBE();
      break;
    case OR:
      T_EXPR_BINMAYBE();
      break;
    case DECREMENT:
      T_ASSIGN_EXPR();
      break;
    case INCREMENT:
      T_ASSIGN_EXPR();
      break;
    case RIGHT_BRACKET:
      T_EXPR_BINMAYBE();
      break;
    default: error();
  }
}

void T_CMD_DECL_VAR(void) {
  printf("fun(cmd_decl_var)\n");
  switch(tok){
    case CONST:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case INT:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case REAL:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case CHAR:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case BOOL:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case STR:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    case VOID:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR_MAYBE();
      break;
    default: error();
  }
}

void T_ASSIGN_EXPR_MAYBE(void) {
  printf("fun(assign_expr_maybe)\n");
  switch(tok){
    case ASSIGN:
      T_ASSIGN_EXPR();
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case ASSIGN_PLUS:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MINUS:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MULT:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_DIV:
      T_ASSIGN_EXPR();
      break;
    case ASSIGN_MOD:
      T_ASSIGN_EXPR();
      break;
    case DECREMENT:
      T_ASSIGN_EXPR();
      break;
    case INCREMENT:
      T_ASSIGN_EXPR();
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

void T_CMD_LOOP(void) {
  printf("fun(cmd_loop)\n");
  switch(tok){
    case FOR:
      T_FOR();
      break;
    case LOOP:
      T_LOOP();
      break;
    default: error();
  }
}

void T_CMD_COND(void) {
  printf("fun(cmd_cond)\n");
  switch(tok){
    case IF:
      T_IF();
      break;
    default: error();
  }
}

void T_CMD_SWITCH(void) {
  printf("fun(cmd_switch)\n");
  switch(tok){
    case SWITCH:
      T_SWITCH();
      break;
    default: error();
  }
}

void T_FOR(void) {
  printf("fun(for)\n");
  switch(tok){
    case FOR:
      EAT(FOR);
      EAT(LEFT_PAREN);
      T_FOR_STMT();
      EAT(SEMICOLON);
      T_FOR_STMT();
      EAT(SEMICOLON);
      T_FOR_STMT();
      EAT(RIGHT_PAREN);
      T_CMD();
      break;
    default: error();
  }
}

void T_FOR_STMT(void) {
  printf("fun(for_stmt)\n");
  switch(tok){
    case ID:
      T_IDAFTERRULE();
      break;
    case CONST:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case DECREMENT:
      T_IDAFTERRULE();
      break;
    case INCREMENT:
      T_IDAFTERRULE();
      break;
    case INT:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case REAL:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case CHAR:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case BOOL:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case STR:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    case VOID:
      T_ALL_DECL_VAR();
      T_ASSIGN_EXPR();
      break;
    default: error();
  }
}

void T_LOOP(void) {
  printf("fun(loop)\n");
  switch(tok){
    case LOOP:
      EAT(LOOP);
      T_CMD();
      break;
    default: error();
  }
}

void T_IF(void) {
  printf("fun(if)\n");
  switch(tok){
    case IF:
      EAT(IF);
      EAT(LEFT_PAREN);
      T_EXPR();
      EAT(RIGHT_PAREN);
      T_CMD();
      EAT(ENDIF);
      T_ELSE();
      break;
    default: error();
  }
}

void T_ELSE(void) {
  printf("fun(else)\n");
  switch(tok){
    case ID:
      break;
    case CONST:
      break;
    case FUNCTION:
      break;
    case LEFT_PAREN:
      break;
    case STRUCT:
      break;
    case SEMICOLON:
      break;
    case LEFT_BRACE:
      break;
    case RIGHT_BRACE:
      break;
    case RETURN:
      break;
    case BREAK:
      break;
    case CONTINUE:
      break;
    case EXIT:
      break;
    case FOR:
      break;
    case LOOP:
      break;
    case IF:
      break;
    case ENDIF:
      break;
    case ELSE:
      EAT(ELSE);
      T_CMD();
      break;
    case SWITCH:
      break;
    case CASE:
      break;
    case TERNARY:
      break;
    case NOT:
      break;
    case DECREMENT:
      break;
    case INCREMENT:
      break;
    case READ:
      break;
    case WRITE:
      break;
    case INT:
      break;
    case REAL:
      break;
    case CHAR:
      break;
    case BOOL:
      break;
    case STR:
      break;
    case VOID:
      break;
    case NUMBER:
      break;
    case CHARACTER:
      break;
    case TRUE:
      break;
    case FALSE:
      break;
    case STRING:
      break;
    default: error();
  }
}

void T_SWITCH(void) {
  printf("fun(switch)\n");
  switch(tok){
    case SWITCH:
      EAT(SWITCH);
      EAT(LEFT_PAREN);
      T_EXPR();
      EAT(RIGHT_PAREN);
      EAT(LEFT_BRACE);
      T_CASEZEROMAIS();
      EAT(RIGHT_BRACE);
      break;
    default: error();
  }
}

void T_CASEZEROMAIS(void) {
  printf("fun(casezeromais)\n");
  switch(tok){
    case RIGHT_BRACE:
      break;
    case CASE:
      T_CASE();
      T_CASEZEROMAIS();
      break;
    default: error();
  }
}

void T_CASE(void) {
  printf("fun(case)\n");
  switch(tok){
    case CASE:
      EAT(CASE);
      T_LITERAL();
      EAT(COLON);
      T_STMTS();
      break;
    default: error();
  }
}

void T_FUNCALL(void) {
  printf("fun(funCall)\n");
  switch(tok){
    case LEFT_PAREN:
      EAT(LEFT_PAREN);
      T_LPAR();
      EAT(RIGHT_PAREN);
      break;
    default: error();
  }
}

void T_LPAR(void) {
  printf("fun(lpar)\n");
  switch(tok){
    case ID:
      T_EXPR();
      T_LPARAFTER();
      break;
    case LEFT_PAREN:
      T_EXPR();
      T_LPARAFTER();
      break;
    case RIGHT_PAREN:
      T_EXPR();
      T_LPARAFTER();
      break;
    case COMMA:
      T_EXPR();
      T_LPARAFTER();
      break;
    case TERNARY:
      T_EXPR();
      T_LPARAFTER();
      break;
    case NOT:
      T_EXPR();
      T_LPARAFTER();
      break;
    case NUMBER:
      T_EXPR();
      T_LPARAFTER();
      break;
    case CHARACTER:
      T_EXPR();
      T_LPARAFTER();
      break;
    case TRUE:
      T_EXPR();
      T_LPARAFTER();
      break;
    case FALSE:
      T_EXPR();
      T_LPARAFTER();
      break;
    case STRING:
      T_EXPR();
      T_LPARAFTER();
      break;
    default: error();
  }
}

void T_LPARAFTER(void) {
  printf("fun(lparAfter)\n");
  switch(tok){
    case RIGHT_PAREN:
      break;
    case COMMA:
      EAT(COMMA);
      T_EXPR();
      T_LPARAFTER();
      break;
    default: error();
  }
}

void T_EXPR_TERN(void) {
  printf("fun(expr_tern)\n");
  switch(tok){
    case TERNARY:
      EAT(TERNARY);
      T_EXPR();
      EAT(QUESTION_MARK);
      T_EXPR();
      EAT(COLON);
      T_EXPR();
      break;
    default: error();
  }
}

void T_OP_UN(void) {
  printf("fun(op_un)\n");
  switch(tok){
    case NOT:
      EAT(NOT);
      break;
    default: error();
  }
}

void T_OP_BIN(void) {
  printf("fun(op_bin)\n");
  switch(tok){
    case MINUS:
      T_OP_MATH();
      break;
    case PLUS:
      T_OP_MATH();
      break;
    case DIV:
      T_OP_MATH();
      break;
    case TIMES:
      T_OP_MATH();
      break;
    case MOD:
      T_OP_MATH();
      break;
    case EQUALS:
      T_OP_LOGIC();
      break;
    case DIFF:
      T_OP_LOGIC();
      break;
    case LEQ:
      T_OP_LOGIC();
      break;
    case GEQ:
      T_OP_LOGIC();
      break;
    case GT:
      T_OP_LOGIC();
      break;
    case LT:
      T_OP_LOGIC();
      break;
    case AND:
      T_OP_LOGIC();
      break;
    case OR:
      T_OP_LOGIC();
      break;
    default: error();
  }
}

void T_OP_MATH(void) {
  printf("fun(op_math)\n");
  switch(tok){
    case MINUS:
      EAT(MINUS);
      break;
    case PLUS:
      EAT(PLUS);
      break;
    case DIV:
      EAT(DIV);
      break;
    case TIMES:
      EAT(TIMES);
      break;
    case MOD:
      EAT(MOD);
      break;
    default: error();
  }
}

void T_ASSIGN_EXTRA(void) {
  printf("fun(assign_extra)\n");
  switch(tok){
    case ASSIGN_PLUS:
      EAT(ASSIGN_PLUS);
      break;
    case ASSIGN_MINUS:
      EAT(ASSIGN_MINUS);
      break;
    case ASSIGN_MULT:
      EAT(ASSIGN_MULT);
      break;
    case ASSIGN_DIV:
      EAT(ASSIGN_DIV);
      break;
    case ASSIGN_MOD:
      EAT(ASSIGN_MOD);
      break;
    default: error();
  }
}

void T_OP_LOGIC(void) {
  printf("fun(op_logic)\n");
  switch(tok){
    case EQUALS:
      EAT(EQUALS);
      break;
    case DIFF:
      EAT(DIFF);
      break;
    case LEQ:
      EAT(LEQ);
      break;
    case GEQ:
      EAT(GEQ);
      break;
    case GT:
      EAT(GT);
      break;
    case LT:
      EAT(LT);
      break;
    case AND:
      EAT(AND);
      break;
    case OR:
      EAT(OR);
      break;
    default: error();
  }
}

void T_INC(void) {
  printf("fun(inc)\n");
  switch(tok){
    case DECREMENT:
      EAT(DECREMENT);
      break;
    case INCREMENT:
      EAT(INCREMENT);
      break;
    default: error();
  }
}

void T_INOUT(void) {
  printf("fun(inOut)\n");
  switch(tok){
    case READ:
      T_IN();
      break;
    case WRITE:
      T_OUT();
      break;
    default: error();
  }
}

void T_IN(void) {
  printf("fun(in)\n");
  switch(tok){
    case READ:
      EAT(READ);
      EAT(LEFT_PAREN);
      EAT(ID);
      EAT(RIGHT_PAREN);
      break;
    default: error();
  }
}

void T_OUT(void) {
  printf("fun(out)\n");
  switch(tok){
    case WRITE:
      EAT(WRITE);
      EAT(LEFT_PAREN);
      EAT(ID);
      EAT(RIGHT_PAREN);
      break;
    default: error();
  }
}

void T_TYPE(void) {
  printf("fun(type)\n");
  switch(tok){
    case ID:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case INT:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case REAL:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case CHAR:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case BOOL:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case STR:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    case VOID:
      T_TYPENAME();
      T_HASHTAGZEROMAIS();
      T_COCHETEZEROMAIS();
      break;
    default: error();
  }
}

void T_TYPENAME(void) {
  printf("fun(typename)\n");
  switch(tok){
    case ID:
      EAT(ID);
      break;
    case INT:
      T_PRIMITIVOS();
      break;
    case REAL:
      T_PRIMITIVOS();
      break;
    case CHAR:
      T_PRIMITIVOS();
      break;
    case BOOL:
      T_PRIMITIVOS();
      break;
    case STR:
      T_PRIMITIVOS();
      break;
    case VOID:
      T_PRIMITIVOS();
      break;
    default: error();
  }
}

void T_PRIMITIVOS(void) {
  printf("fun(primitivos)\n");
  switch(tok){
    case INT:
      EAT(INT);
      break;
    case REAL:
      EAT(REAL);
      break;
    case CHAR:
      EAT(CHAR);
      break;
    case BOOL:
      EAT(BOOL);
      break;
    case STR:
      EAT(STR);
      break;
    case VOID:
      EAT(VOID);
      break;
    default: error();
  }
}

void T_HASHTAGZEROMAIS(void) {
  printf("fun(hashtagzeromais)\n");
  switch(tok){
    case ID:
      break;
    case ASSIGN:
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case REFERENCE:
      break;
    case ASSIGN_PLUS:
      break;
    case ASSIGN_MINUS:
      break;
    case ASSIGN_MULT:
      break;
    case ASSIGN_DIV:
      break;
    case ASSIGN_MOD:
      break;
    case DECREMENT:
      break;
    case INCREMENT:
      break;
    case POINTER_VAL:
      EAT(POINTER_VAL);
      T_HASHTAGZEROMAIS();
      break;
    case LEFT_BRACKET:
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

void T_LITERAL(void) {
  printf("fun(literal)\n");
  switch(tok){
    case NUMBER:
      EAT(NUMBER);
      break;
    case CHARACTER:
      EAT(CHARACTER);
      break;
    case TRUE:
      EAT(TRUE);
      break;
    case FALSE:
      EAT(FALSE);
      break;
    case STRING:
      EAT(STRING);
      break;
    default: error();
  }
}

void T_ARRAY_ACCESS(void) {
  printf("fun(array_access)\n");
  switch(tok){
    case LEFT_BRACKET:
      EAT(LEFT_BRACKET);
      T_INSIDE_COCHETE();
      EAT(RIGHT_BRACKET);
      T_COCHETEZEROMAIS();
      break;
    default: error();
  }
}

void T_COCHETEZEROMAIS(void) {
  printf("fun(cochetezeromais)\n");
  switch(tok){
    case ID:
      break;
    case ASSIGN:
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case COMMA:
      break;
    case REFERENCE:
      break;
    case COLON:
      break;
    case QUESTION_MARK:
      break;
    case MINUS:
      break;
    case PLUS:
      break;
    case DIV:
      break;
    case TIMES:
      break;
    case MOD:
      break;
    case ASSIGN_PLUS:
      break;
    case ASSIGN_MINUS:
      break;
    case ASSIGN_MULT:
      break;
    case ASSIGN_DIV:
      break;
    case ASSIGN_MOD:
      break;
    case EQUALS:
      break;
    case DIFF:
      break;
    case LEQ:
      break;
    case GEQ:
      break;
    case GT:
      break;
    case LT:
      break;
    case AND:
      break;
    case OR:
      break;
    case DECREMENT:
      break;
    case INCREMENT:
      break;
    case LEFT_BRACKET:
      EAT(LEFT_BRACKET);
      T_INSIDE_COCHETE();
      EAT(RIGHT_BRACKET);
      T_COCHETEZEROMAIS();
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

void T_INSIDE_COCHETE(void) {
  printf("fun(inside_cochete)\n");
  switch(tok){
    case ID:
      T_IDAFTERRULE();
      break;
    case LEFT_PAREN:
      T_EXPR_WITHOUT_TERM();
      break;
    case TERNARY:
      T_EXPR_WITHOUT_TERM();
      break;
    case NOT:
      T_EXPR_WITHOUT_TERM();
      break;
    case DECREMENT:
      T_IDAFTERRULE();
      break;
    case INCREMENT:
      T_IDAFTERRULE();
      break;
    case NUMBER:
      T_EXPR_WITHOUT_TERM();
      break;
    case CHARACTER:
      T_EXPR_WITHOUT_TERM();
      break;
    case TRUE:
      T_EXPR_WITHOUT_TERM();
      break;
    case FALSE:
      T_EXPR_WITHOUT_TERM();
      break;
    case STRING:
      T_EXPR_WITHOUT_TERM();
      break;
    case RIGHT_BRACKET:
      T_EXPR_WITHOUT_TERM();
      break;
    default: error();
  }
}

void T_TERMAFTER(void) {
  printf("fun(termAfter)\n");
  switch(tok){
    case ID:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN:
      T_PONTEIROZEROMAIS();
      break;
    case LEFT_PAREN:
      T_FUNCALL();
      break;
    case RIGHT_PAREN:
      T_PONTEIROZEROMAIS();
      break;
    case SEMICOLON:
      T_PONTEIROZEROMAIS();
      break;
    case COMMA:
      T_PONTEIROZEROMAIS();
      break;
    case COLON:
      T_PONTEIROZEROMAIS();
      break;
    case QUESTION_MARK:
      T_PONTEIROZEROMAIS();
      break;
    case MINUS:
      T_PONTEIROZEROMAIS();
      break;
    case PLUS:
      T_PONTEIROZEROMAIS();
      break;
    case DIV:
      T_PONTEIROZEROMAIS();
      break;
    case TIMES:
      T_PONTEIROZEROMAIS();
      break;
    case MOD:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN_PLUS:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN_MINUS:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN_MULT:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN_DIV:
      T_PONTEIROZEROMAIS();
      break;
    case ASSIGN_MOD:
      T_PONTEIROZEROMAIS();
      break;
    case EQUALS:
      T_PONTEIROZEROMAIS();
      break;
    case DIFF:
      T_PONTEIROZEROMAIS();
      break;
    case LEQ:
      T_PONTEIROZEROMAIS();
      break;
    case GEQ:
      T_PONTEIROZEROMAIS();
      break;
    case GT:
      T_PONTEIROZEROMAIS();
      break;
    case LT:
      T_PONTEIROZEROMAIS();
      break;
    case AND:
      T_PONTEIROZEROMAIS();
      break;
    case OR:
      T_PONTEIROZEROMAIS();
      break;
    case DECREMENT:
      T_PONTEIROZEROMAIS();
      break;
    case INCREMENT:
      T_PONTEIROZEROMAIS();
      break;
    case LEFT_BRACKET:
      T_ARRAY_ACCESS();
      break;
    case RIGHT_BRACKET:
      T_PONTEIROZEROMAIS();
      break;
    case ARROW:
      T_PONTEIROZEROMAIS();
      break;
    default: error();
  }
}

void T_PONTEIROZEROMAIS(void) {
  printf("fun(ponteirozeromais)\n");
  switch(tok){
    case ID:
      break;
    case ASSIGN:
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case COMMA:
      break;
    case COLON:
      break;
    case QUESTION_MARK:
      break;
    case MINUS:
      break;
    case PLUS:
      break;
    case DIV:
      break;
    case TIMES:
      break;
    case MOD:
      break;
    case ASSIGN_PLUS:
      break;
    case ASSIGN_MINUS:
      break;
    case ASSIGN_MULT:
      break;
    case ASSIGN_DIV:
      break;
    case ASSIGN_MOD:
      break;
    case EQUALS:
      break;
    case DIFF:
      break;
    case LEQ:
      break;
    case GEQ:
      break;
    case GT:
      break;
    case LT:
      break;
    case AND:
      break;
    case OR:
      break;
    case DECREMENT:
      break;
    case INCREMENT:
      break;
    case RIGHT_BRACKET:
      break;
    case ARROW:
      EAT(ARROW);
      EAT(ID);
      T_PONTEIROZEROMAIS();
      break;
    default: error();
  }
}

void T_EXPR(void) {
  printf("fun(expr)\n");
  switch(tok){
    case ID:
      EAT(ID);
      T_TERMAFTER();
      T_EXPR_BINMAYBE();
      break;
    case LEFT_PAREN:
      EAT(LEFT_PAREN);
      T_EXPR();
      EAT(RIGHT_PAREN);
      break;
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case COMMA:
      break;
    case COLON:
      break;
    case TERNARY:
      T_EXPR_TERN();
      break;
    case QUESTION_MARK:
      break;
    case NOT:
      T_OP_UN();
      T_EXPR();
      break;
    case NUMBER:
      T_LITERAL();
      T_EXPR_BINMAYBE();
      break;
    case CHARACTER:
      T_LITERAL();
      T_EXPR_BINMAYBE();
      break;
    case TRUE:
      T_LITERAL();
      T_EXPR_BINMAYBE();
      break;
    case FALSE:
      T_LITERAL();
      T_EXPR_BINMAYBE();
      break;
    case STRING:
      T_LITERAL();
      T_EXPR_BINMAYBE();
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

void T_EXPR_WITHOUT_TERM(void) {
  printf("fun(expr_without_term)\n");
  switch(tok){
    case LEFT_PAREN:
      EAT(LEFT_PAREN);
      T_EXPR();
      EAT(RIGHT_PAREN);
      break;
    case SEMICOLON:
      break;
    case TERNARY:
      T_EXPR_TERN();
      break;
    case NOT:
      T_OP_UN();
      T_EXPR();
      break;
    case NUMBER:
      T_LITERAL();
      break;
    case CHARACTER:
      T_LITERAL();
      break;
    case TRUE:
      T_LITERAL();
      break;
    case FALSE:
      T_LITERAL();
      break;
    case STRING:
      T_LITERAL();
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

void T_EXPR_BINMAYBE(void) {
  printf("fun(expr_binMaybe)\n");
  switch(tok){
    case RIGHT_PAREN:
      break;
    case SEMICOLON:
      break;
    case COMMA:
      break;
    case COLON:
      break;
    case QUESTION_MARK:
      break;
    case MINUS:
      T_OP_BIN();
      T_EXPR();
      break;
    case PLUS:
      T_OP_BIN();
      T_EXPR();
      break;
    case DIV:
      T_OP_BIN();
      T_EXPR();
      break;
    case TIMES:
      T_OP_BIN();
      T_EXPR();
      break;
    case MOD:
      T_OP_BIN();
      T_EXPR();
      break;
    case EQUALS:
      T_OP_BIN();
      T_EXPR();
      break;
    case DIFF:
      T_OP_BIN();
      T_EXPR();
      break;
    case LEQ:
      T_OP_BIN();
      T_EXPR();
      break;
    case GEQ:
      T_OP_BIN();
      T_EXPR();
      break;
    case GT:
      T_OP_BIN();
      T_EXPR();
      break;
    case LT:
      T_OP_BIN();
      T_EXPR();
      break;
    case AND:
      T_OP_BIN();
      T_EXPR();
      break;
    case OR:
      T_OP_BIN();
      T_EXPR();
      break;
    case RIGHT_BRACKET:
      break;
    default: error();
  }
}

int main(){
    advance();
    T_S();
}
