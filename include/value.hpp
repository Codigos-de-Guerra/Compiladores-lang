#ifndef VALUE
#define VALUE

#include "new_rules.hpp"

typedef union {
  programa *programaRet;
  statements *statementsRet;
  statement *statementRet;
  decl_fun *decl_funRet;
  literal *literalRet;
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
  expr *exprRet;
  caze * cazeRet;
  cazezeromais* cazeZeroRet;
  switcha* switchRet;
  cmd* cmdRet;
  cmd_cond* cmd_condRet;
  cmd_loop* cmd_loopRet;
  cmd_switch* cmd_switchRet;
  elsea* elseRet;
  ifa* ifRet;
  loop* loopRet;
  para_for* para_forRet;
  fora* forRet;
  block* blockRet;

  string *name;
} YYSTYPE;

extern YYSTYPE yylval;

#endif
