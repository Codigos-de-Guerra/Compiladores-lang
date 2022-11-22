#include "symbol.hpp"
#include <list>
#include <optional>

using namespace std;

SymTable current_table(list<SymTable> &tables) {
  SymTable final;
  for (SymTable &table : tables)
    final.merge(table);

  return final;
}

void print_symtable(SymTable symtable) {
  for (auto const &sym : symtable) {
    string key = sym.first;
    Symbol val = sym.second;

    cout << "{" << key << " = " << val << "}" << endl;
  }
}

optional<Symbol> lookup(list<SymTable> &tables, string sym_name) {
  SymTable current = current_table(tables);

  if (current.find(sym_name) == current.end())
    return {};

  return current[sym_name];
}

void add_sym(list<SymTable> &tables, string sym_name, Symbol sym) {
  tables.front().insert({sym_name, sym});
}

void push_scope(list<SymTable> &tables, SymTable new_table) {
  tables.push_front(new_table);
}

void pop_scope(list<SymTable> &tables) { tables.pop_front(); }
