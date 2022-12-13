#ifndef RULES_H
#define RULES_H

#include "symbol.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <set>

using namespace std;

class cmd;
class programa;
class type_name;
class typedlpar;
class block;
class cmd_cond;
class cmd_loop;
class loop;
class fora;

class Node {
public:
  vector<Node *> children;
  
};

class decl_fun : public Node {
public:
  string intermid;

  decl_fun(type_name *t, typedlpar *tlpar, block *b);
};

class statement : public Node {
public:
  string intermid = "";

  statement(decl_fun *decl_f);
  statement(cmd *c);
};

class statements : public Node {
public:
  string intermid = "";

  statements(statement *st, statements *stmts);
};

class programa : public Node {
public:
  string intermid = "";

  programa(state &estado, statements *stmts);
};

class literal : public Node {
public:
  string type;
  string value;
  string intermid;
  string ret;

  literal(string tipo, string valor,state& estado);
};

class identifier : public Node {
public:
  string name;
  
  identifier(string nome);
};

class expr : public Node {
public:
  vector<string> symbol_names;
  string type = "UNDEFINED";
  string intermid = "_";
  string ret = "";
  bool erro = false;
  string valor = "";
  int qualId = 0;
  bool isId = false;
  string rootId = "";

  set<pair<string,string>> compatibilidade = {
    make_pair("INT","NUMBER"),
    make_pair("NUMBER","INT"),
    make_pair("INT","REAL"),
    make_pair("REAL","INT"),
    make_pair("INT","BOOL"),
    make_pair("BOOL","INT"),
    make_pair("NUMBER","BOOL"),
    make_pair("BOOL","NUMBER"),
    make_pair("REAL","NUMBER"),
    make_pair("NUMBER","REAL")
  };

  bool eInteiro();

  int getVal();

  expr(state & estado, expr *left,string operacao, expr *right);

  expr(state &estado, expr *exp);

  expr(state &estado, string operacao, expr *exp);

  expr(state& estado, identifier *id);

  expr(state& estado, literal *lit);
};

class assign_expr : public Node {
public:
  string intermid;
  string ret;

  assign_expr();
  assign_expr(expr* a);
};

class assign_expr_maybe : public Node {
public:
string intermid = "";
string ret = "";
  assign_expr_maybe();
  assign_expr_maybe(assign_expr * a);
};

class primitive : public Node {
public:
  string type = "UNDEFINED";

  primitive(string type);
};

class cochetezeromais : public Node {
public:
  cochetezeromais(cochetezeromais *a);
};

class hashtagzeromais : public Node {
public:
  hashtagzeromais(hashtagzeromais *a);
};

class decl_var_prim : public Node {
public:
  string name = "";
  string type = "UNDEFINED";

  decl_var_prim(primitive *t, string var_name);
};


class const_decl_var : public Node {
public:
  string name = "";
  string type = "UNDEFINED";
  bool is_const = true;

  const_decl_var(decl_var_prim *var);
};

class all_decl_var : public Node {
public:
  string intermid;
  all_decl_var();

  all_decl_var(state& estado,decl_var_prim *var);

  all_decl_var(state & estado,const_decl_var *var);
};

class cmd_decl_var : public Node {
public:
  string ret;
  cmd_decl_var();
  cmd_decl_var(state& estado,all_decl_var *a, assign_expr_maybe *b);
};

class type_name : public Node {
public:
  string name;

  type_name(primitive *prim_type);

  type_name(string id_type);
};

class parameter : public Node {
public:
  string type;
  string id;

  parameter(type_name *t, string id);
};

class caze : public Node {
public:
  string tipo = "";
  string valor = "";

  caze(literal * t);
};

class cazezeromais : public Node {
public:
  string valorEsperado = "";
  set<string> javi;
  set<pair<string,string>> compatibilidade = {
    make_pair("INT","NUMBER"),
    make_pair("NUMBER","INT"),
    make_pair("INT","REAL"),
    make_pair("REAL","INT"),
    make_pair("INT","BOOL"),
    make_pair("BOOL","INT"),
    make_pair("NUMBER","BOOL"),
    make_pair("BOOL","NUMBER"),
    make_pair("REAL","NUMBER"),
    make_pair("NUMBER","REAL")
  };

  cazezeromais();
  cazezeromais(state &estado, caze* a , cazezeromais*b);
};

class block : public Node {
public:
  string intermid;

  block(statements *stmts);
};

class cmd : public Node {
public:
    string ret = "";

    cmd (state& estado, string s);

    cmd(identifier* id,assign_expr* as);

    cmd(cmd_decl_var *decl_var);

    cmd(block *bl);

    cmd(cmd_cond *c_c);

    cmd(state &estado, expr *exp);

    cmd(state &estado, cmd_loop *c_l);

    cmd(state &estado, string s, expr* exp);
};

class elsea : public Node {
public:
  string intermid;
  
  elsea(state &estado, cmd *cmd);
};

class ifa : public Node {
public:
    string intermid;

    ifa (state &estado, expr *exp, cmd *c, elsea *el);
};

class cmd_cond : public Node {
public:
  string intermid;

  cmd_cond(ifa *iff);
};

class cmd_loop : public Node {
public:
  string intermid;

  cmd_loop(loop *lo);

  cmd_loop(fora *f);
};

class para_for : public Node {
public:
  string intermid = "";
  string ret = "";

  para_for(cmd_decl_var *decl_var);

  para_for(expr *exp);

  para_for(string op, expr *exp);
};

class fora : public Node {
public:
  string intermid = "";

  fora(state &estado, para_for *pa, para_for *pb, para_for *pc, cmd *c);
};

class loop : public Node {
public:
    string intermid;

    loop(state &estado, cmd *c);
};

class typedlpar {
public:
  vector<parameter> params;

  typedlpar(state & estado, parameter *param, typedlpar *lpar);
};

class switcha : public Node {
public:
set<pair<string,string>> compatibilidade = {
    make_pair("INT","NUMBER"),
    make_pair("NUMBER","INT"),
    make_pair("INT","REAL"),
    make_pair("REAL","INT"),
    make_pair("INT","BOOL"),
    make_pair("BOOL","INT"),
    make_pair("NUMBER","BOOL"),
    make_pair("BOOL","NUMBER"),
    make_pair("REAL","NUMBER"),
    make_pair("NUMBER","REAL")
  };
  
  switcha(state &estado, expr* a, cazezeromais* b);
};

#endif
