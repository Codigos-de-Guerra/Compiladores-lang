#ifndef TIPOS
#define TIPOS

#include "classes.hpp"
typedef union{
    literal* literalRetorno;
    cmd* cmdRetorno;
    identifier* identifierRetorno;
    assign_expr* assign_exprRetorno;
    all_decl_var* all_decl_varRetorno;
    cmd_decl_var* cmd_decl_varRetorno;
    assign_expr_maybe* assign_expr_maybeRetorno;
    decl_var_prim* decl_var_primRetorno;
    primitivos* primitivosRetorno;
    cochetezeromais* cochetezeromaisRetorno;
    hashtagzeromais* hashtagzeromaisRetorno;
    const_decl_var* const_decl_varRetorno;
	string* name;
} YYSTYPE;

extern YYSTYPE yylval;


#endif