#ifndef RULES
#define RULES

#include "symbol.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
  vector<Node *> children;
  function<void(void)> exec;

  Node(vector<Node *> _children = {})
      : children(_children), exec([&]() { exec_children(); }) {}

  void exec_children() {
    for (auto node : children) {
      if (node)
        node->exec();
    }
  }
};

class literal : public Node {
public:
  string type;
  string value;

  literal(string type, string value) : type(type), value(value) {}
};

class identifier : public Node {
public:
  string name;

  identifier(string name) : name(name) {}
};

class assign_expr : public Node {
public:
};

class assign_expr_maybe : public Node {
public:
  assign_expr_maybe() {}
};

class primitive : public Node {
public:
  string type = "UNDEFINED";

  primitive(string type) : type(type) {}
};

class cochetezeromais : public Node {
public:
  cochetezeromais(cochetezeromais *a) {}
};

class hashtagzeromais : public Node {
public:
  hashtagzeromais(hashtagzeromais *a) {}
};

class decl_var_prim : public Node {
public:
  string name = "";
  string type = "UNDEFINED";

  decl_var_prim(primitive *t, string var_name) {
    type = t->type;
    name = var_name;
  }
};

class const_decl_var : public Node {
public:
  string name = "";
  string type = "UNDEFINED";
  bool is_const = true;

  const_decl_var(decl_var_prim *var) {
    name = var->name;
    type = "CONST." + var->type;
  }
};

class all_decl_var : public Node {
public:
  all_decl_var() {}

  all_decl_var(decl_var_prim *var, list<symtable> &tables) {
    optional<symbol> sym = lookup(tables, var->name);

    if (sym.has_value())
      cout << var->name << " já foi declarado como " << sym.value().first
           << endl;
    else
      add_sym(tables, var->name, {var->type, false});
  }

  all_decl_var(const_decl_var *var, list<symtable> &tables) {
    optional<symbol> sym = lookup(tables, var->name);

    if (sym.has_value())
      cout << var->name << " já foi declarado como " << sym.value().first
           << endl;
    else
      add_sym(tables, var->name, {var->type, true});
  }
};

class cmd_decl_var : public Node {
public:
  cmd_decl_var() {}
  cmd_decl_var(all_decl_var *a, assign_expr_maybe *b) {}
};

class cmd : public Node {
public:
  cmd(identifier *a, assign_expr *b) {}

  cmd(cmd_decl_var *a) {}
};

class type_name : public Node {
public:
  string name;

  type_name(primitive *prim_type) : name(prim_type->type){};

  type_name(string id_type) : name(id_type){};
};

class parameter : public Node {
public:
  string type;
  string id;

  parameter(type_name *t, string id) : type(t->name), id(id) {}
};

class typedlpar {
public:
  vector<parameter> params;

  typedlpar(list<symtable> &tables, parameter *param, typedlpar *lpar) {
    params.push_back(*param);
    add_sym(tables, param->id, {param->type, false});

    if (lpar->params.size() < (1 << 30))
      for (parameter param : lpar->params) {
        params.push_back(param);
        add_sym(tables, param.id, {param.type, false});
      }
  }
};

class decl_fun : public Node {
public:
  string type;
  string name;

  decl_fun(list<symtable> &tables, type_name *type_name, string id) {
    type = type_name->name;
    add_sym(tables, id, {type, false});
  };
};

class block : public Node {
public:
  block() {}
};

class expr : public Node {
public:
  vector<string> symbol_names;
  string type = "UNDEFINED";

  expr(list<symtable> &tables, expr *left, expr *right) {
    if (left->symbol_names.size() < (1 << 30))
      for (string sym_name : left->symbol_names)
        symbol_names.push_back(sym_name);

    if (right->symbol_names.size() < (1 << 30))
      for (string sym_name : right->symbol_names)
        symbol_names.push_back(sym_name);

    if (left->type != right->type)
      cout << left->type << " e " << right->type << " são incompativeis"
           << endl;

    type = left->type;
  }

  expr(list<symtable> &tables, expr *exp) {
    if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
  }

  expr(list<symtable> &tables, identifier *id) {
    symbol_names.push_back(id->name);

    if (symbol_names.size() < (1 << 30))
      for (string sym_name : symbol_names) {
        optional<symbol> sym = lookup(tables, sym_name);

        if (sym.has_value())
          type = sym.value().first;
        else
          cout << sym_name << " não foi declarado" << endl;
      }
  }

  expr(list<symtable> &tables, literal *lit) { type = lit->type; }
};

#endif
