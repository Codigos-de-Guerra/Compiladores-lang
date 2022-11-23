#ifndef VALUE
#define VALUE

#include "rules.hpp"

typedef union {
  literal *literalRet;
  cmd *cmdRet;
  identifier *identifierRet;
  assign_expr *assign_exprRet;
  all_decl_var *all_decl_varRet;
  cmd_decl_var *cmd_decl_varRet;
  assign_expr_maybe *assign_expr_maybeRet;
  decl_var_prim *decl_var_primRet;
  primitive *primitiveRet;
  cochetezeromais *cochetezeromaisRet;
  hashtagzeromais *hashtagzeromaisRet;
  const_decl_var *const_decl_varRet;
  type_name *type_nameRet;
  parameter *parameterRet;
  typedlpar *typedlparRet;
  decl_fun *decl_funRet;
  block *blockRet;
  expr *exprRet;
  string *name;
} YYSTYPE;

extern YYSTYPE yylval;

#endif