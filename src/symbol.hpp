#ifndef SYMBOL
#define SYMBOL

#include <optional>
#include <string>
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Symbol {
public:
  string type = "";
  bool is_const = false;

  Symbol() : type(""), is_const(false) {}

  Symbol(string type) : type(type), is_const(false) {}

  Symbol(string type, bool is_const) : type(type), is_const(is_const) {}

  friend ostream &operator<<(ostream &os, Symbol const &sym) {
    string sym_str = sym.type;
    if (sym.is_const)
      sym_str = "CONST " + sym_str;
    return os << sym_str;
  }
};

typedef map<string, Symbol> SymTable;

void print_symtable(SymTable &table);

void print_current_symtable(list<SymTable> &tables);

void push_scope(list<SymTable> &tables, SymTable new_table);

void pop_scope(list<SymTable> &tables);

SymTable current_table(list<SymTable> &tables);

optional<Symbol> lookup(list<SymTable> &tables, string sym_name);

void add_sym(list<SymTable> &tables, string sym_name, Symbol sym);

#endif
