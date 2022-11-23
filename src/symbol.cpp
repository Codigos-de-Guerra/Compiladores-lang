#include "symbol.hpp"
#include <list>
#include <optional>

using namespace std;

symtable current_table(list<symtable> &tables) {
  symtable final = symtable(tables.back());

  for (reverse_iterator it = tables.rbegin(); it != tables.rend(); it++)
    final.merge(*it);

  return final;
}

void print_symtable(symtable &table) {
  if (table.size() > 0) {
    cout << "{" << endl;
    for (pair<string, symbol> const &sym : table) {
      string name = sym.first;
      string type = sym.second.first;
      if (sym.second.second)
        type = "CONST " + type;

      cout << "  " << name << ": " << type << "," << endl;
    }
    cout << "}" << endl;
  } else {
    cout << "{}" << endl;
  }
}

void print_current_symtable(list<symtable> &tables) {
  symtable table = current_table(tables);

  print_symtable(table);
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
