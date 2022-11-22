#ifndef CLASSES
#define CLASSES

#include "symbol.hpp"
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
  string tipo;
  string value;
  literal(string t, string val) {
    tipo = t;
    value = val;
  }
};

class identifier : public Node {
public:
  identifier(char *a) { string s = a; }
};

class assign_expr : public Node {
public:
};

class assign_expr_maybe : public Node {
public:
  assign_expr_maybe() {}
};

class primitivos : public Node {
public:
  string type = "";
  primitivos(string x) { type = x; }
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
  decl_var_prim(primitivos *a, hashtagzeromais *b, cochetezeromais *c,
                char *d) {
    name = d;
    type = a->type;
  }
};

class const_decl_var : public Node {
public:
  string name = "";
  string type = "";
  bool is_const = true;

  const_decl_var(decl_var_prim *a) {
    name = a->name;
    type = "CONST." + a->type;
  }
};

class all_decl_var : public Node {
public:
  all_decl_var() {}

  all_decl_var(decl_var_prim *a, list<SymTable> &tables) {
    optional<Symbol> sym = lookup(tables, a->name);

    if (sym.has_value())
      cout << a->name << " já foi declarado como " << sym.value().type << endl;
    else
      add_sym(tables, a->name, Symbol(a->type));

    print_symtable(current_table(tables));
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

#endif
