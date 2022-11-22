#include "symbol.hpp"
#include <list>
#include <optional>

using namespace std;

symtable current_table(list<symtable> &tables) {
  symtable final;
  for (symtable &table : tables)
    final.merge(table);

  return final;
}

void print_symtable(symtable &table) {
  for (pair<string, symbol> const &sym : table) {
    string key = sym.first;
    symbol val = sym.second;

    cout << "{" << key << " = " << val << "}" << endl;
  }
}

void print_current_symtable(list<symtable> &tables) {
  symtable table = current_table(tables);

  for (pair<string, symbol> const &sym : table) {
    string key = sym.first;
    symbol val = sym.second;

    cout << "{" << key << " = " << val << "}" << endl;
  }
}

optional<symbol> lookup(list<symtable> &tables, string sym_name) {
  symtable current = current_table(tables);

  if (current.find(sym_name) == current.end())
    return {};

  return current[sym_name];
}

void add_sym(list<symtable> &tables, string sym_name, symbol sym) {
  tables.back().insert({sym_name, sym});
}

void push_scope(list<symtable> &tables, symtable new_table) {
  tables.push_back(new_table);
}

void pop_scope(list<symtable> &tables) { tables.pop_back(); }
