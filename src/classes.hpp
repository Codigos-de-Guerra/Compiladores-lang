#ifndef CLASSES
#define CLASSES

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Symbol {
public:
  int scope = 1;
  string type = "";
  bool is_const = false;

  Symbol() : scope(1), type(""), is_const(false) {}

  Symbol(string type) : scope(1), type(type), is_const(false) {}

  Symbol(string type, bool is_const)
      : scope(1), type(type), is_const(is_const) {}

  friend ostream &operator<<(ostream &os, Symbol const &sym) {
    string sym_str = sym.type + "(" + to_string(sym.scope) + ")";
    if (sym.is_const)
      sym_str = "CONST " + sym_str;
    return os << sym_str;
  }
};

typedef map<string, Symbol> SymTable;

class cmd_decl_var;
class all_decl_var;
class assign_expr_maybe;
class decl_var_prim;
class primitivos;
class hashtagzeromais;
class cochetezeromais;
class const_decl_var;
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

class cmd : public Node {
public:
  cmd(identifier *a, assign_expr *b) {}
  cmd(cmd_decl_var *a) {}
};

class cmd_decl_var : public Node {
public:
  cmd_decl_var() {}
  cmd_decl_var(all_decl_var *a, assign_expr_maybe *b) {}
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

class cochetezeromais : public Node {
public:
  cochetezeromais(cochetezeromais *a) {}
};

class hashtagzeromais : public Node {
public:
  hashtagzeromais(hashtagzeromais *a) {}
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

  all_decl_var(decl_var_prim *a, SymTable &symtable) {
    if (symtable.find(a->name) != symtable.end()) {
      cout << a->name << " já foi declarado como " << symtable[a->name].type
           << endl;
    } else {
      symtable.insert({a->name, Symbol(a->type)});
    }
  }

  all_decl_var(const_decl_var *a, SymTable &symtable) {
    if (symtable.find(a->name) != symtable.end()) {
      cout << a->name << " já foi declarado como " << symtable[a->name].type
           << endl;
    } else {
      symtable.insert({a->name, Symbol(a->type, a->is_const)});
    }
  }
};

class block : public Node {
public:
  block() {}
};

#endif
