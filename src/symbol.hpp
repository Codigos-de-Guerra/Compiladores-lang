#ifndef SYMBOL
#define SYMBOL

#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <string>

using namespace std;

// class symbol {
// public:
//   string type = "";
//   bool is_const = false;

//   symbol() : type(""), is_const(false) {}

//   symbol(string type) : type(type), is_const(false) {}

//   symbol(string type, bool is_const) : type(type), is_const(is_const) {}

//   friend ostream &operator<<(ostream &os, symbol const &sym) {
//     string sym_str = sym.type;
//     if (sym.is_const)
//       sym_str = "CONST " + sym_str;
//     return os << sym_str;
//   }
// };

typedef pair<string, bool> symbol;

typedef map<string, pair<string, bool>> symtable;

void print_symtable(symtable &table);

void print_current_symtable(list<symtable> &tables);

symtable current_table(list<symtable> &tables);

optional<symbol> lookup(list<symtable> &tables, string sym_name);

void add_sym(list<symtable> &tables, string sym_name, symbol sym);

void push_scope(list<symtable> &tables, symtable new_table);

void pop_scope(list<symtable> &tables);

#endif
