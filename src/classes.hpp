#ifndef CLASSES
#define CLASSES

#include "symbol.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
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
  literal(string t, string val) {
    type = t;
    value = val;
  }
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
  string type = "";
  primitive(string x) { type = x; }
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
  string type = "";

  decl_var_prim(primitive *t, string var_name) {
    type = t->type;
    name = var_name;
  }
};

class const_decl_var : public Node {
public:
  string name = "";
  string type = "";
  bool is_const = true;

  const_decl_var(decl_var_prim *var) {
    name = var->name;
    type = "CONST." + var->type;
  }
};

class all_decl_var : public Node {
public:
  all_decl_var() {}

  all_decl_var(decl_var_prim *var, list<SymTable> &tables) {
    optional<Symbol> sym = lookup(tables, var->name);

    if (sym.has_value())
      cout << var->name << " já foi declarado como " << sym.value().type << endl;
    else
      add_sym(tables, var->name, Symbol(var->type));
  }

  all_decl_var(const_decl_var *a, list<SymTable> &tables) {
    optional<Symbol> sym = lookup(tables, a->name);

    if (sym.has_value())
      cout << a->name << " já foi declarado como " << sym.value().type << endl;
    else
      add_sym(tables, a->name, Symbol(a->type));
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

class block : public Node {
public:
  block() {}
};

class expr : public Node {
public:
  vector<string> symbol_names;
  string type = "";

  expr(expr *left, expr *right, list<SymTable> &tables) {
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

  expr(expr *exp, list<SymTable> &tables) {
    if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
  }

  expr(identifier *id, list<SymTable> &tables) {
    symbol_names.push_back(id->name);

    if (symbol_names.size() < (1 << 30))
      for (string sym_name : symbol_names) {
        optional<Symbol> sym = lookup(tables, sym_name);

        if (sym.has_value()) {
          type = sym.value().type;
          cout << sym.value() << endl;
        }
        else
          cout << sym_name << " não foi declarado" << endl;
      }

    print_current_symtable(tables);
    // type = lookup(tables, id->name).value().type;
  }

  expr(literal *lit, list<SymTable> &tables) { type = lit->type; }
};

#endif
