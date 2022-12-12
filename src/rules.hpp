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
#include<set>

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
  string intermid;
  literal(string tipo, string valor,int& id){
    type=tipo;
    value=valor;
    
    intermid = "t"+to_string(id);
    cout<<intermid<<" = "<<valor<<";\n";
    id++;
  }
};

class identifier : public Node {
public:
  string name;
  
  identifier(string nome) {
    name = nome;
   
  }
};

class expr : public Node {
public:
  vector<string> symbol_names;
  string type = "UNDEFINED";
  string intermid = "_";
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
  expr(list<symtable> &tables, expr *left,string operacao, expr *right,int& id) {
    intermid = "t"+to_string(id);
    id++;
    cout<<intermid<<" = "<<left->intermid<<" "<<operacao<<" "<<right->intermid<<";"<<endl;
    if (left->symbol_names.size() < (1 << 30))
      for (string sym_name : left->symbol_names)
        symbol_names.push_back(sym_name);

    if (right->symbol_names.size() < (1 << 30))
      for (string sym_name : right->symbol_names)
        symbol_names.push_back(sym_name);

    if (left->type != right->type){
      if(compatibilidade.find(make_pair(left->type,right->type))==compatibilidade.end())
            cout << left->type << " e " << right->type << " são incompativeis" << endl;
    }

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
    intermid = id->name;
    if (symbol_names.size() < (1 << 30))
      for (string sym_name : symbol_names) {
        optional<symbol> sym = lookup(tables, sym_name);

        if (sym.has_value())
          type = sym.value().first;
        else
          cout << sym_name << " não foi declarado" << endl;
      }
  }

  expr(list<symtable> &tables, literal *lit) { 
    intermid = lit->intermid;
    type = lit->type; 
  }
};

class assign_expr : public Node {
public:
  string intermid;
  assign_expr(){

  }
  assign_expr(expr* a){
    intermid = a->intermid;
  }
};

class assign_expr_maybe : public Node {
public:
string intermid = "";
  assign_expr_maybe() {}
  assign_expr_maybe(assign_expr * a) {
    intermid = a->intermid;
  }
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
  string intermid;
  all_decl_var() {}

  all_decl_var(decl_var_prim *var, list<symtable> &tables) {
    intermid = var->name;
    symtable local_table = tables.back();
    auto sym = local_table.find(var->name);

    if (sym != local_table.end())
      cout << var->name << " já foi declarado como " << sym->second.first
           << endl;
    else
      add_sym(tables, var->name, {var->type, false});
  }

  all_decl_var(const_decl_var *var, list<symtable> &tables) {
    intermid = var->name;
    symtable local_table = tables.back();
    auto sym = local_table.find(var->name);

    if (sym != local_table.end())
      cout << var->name << " já foi declarado como " << sym->second.first
           << endl;
    else
      add_sym(tables, var->name, {var->type, true});
  }
};

class cmd_decl_var : public Node {
public:
  cmd_decl_var() {}
  cmd_decl_var(all_decl_var *a, assign_expr_maybe *b) {
    if(b==NULL)return;
    if(!b->intermid.empty()){
      cout<<a->intermid<<" = "<<b->intermid<<'\n';
    }
  }
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

class caze : public Node {
public:
  string tipo = "";
  string valor = "";
  caze(literal * t){
    tipo = t->type;
    valor = t->value;
  }
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
  cazezeromais(){

  }
  cazezeromais(caze* a , cazezeromais*b){
    if(b->valorEsperado!="")
      valorEsperado = b->valorEsperado;
    else valorEsperado = a->tipo;

    javi = b->javi;
    
    if(a->tipo != valorEsperado){
      if(compatibilidade.find(make_pair(a->tipo, valorEsperado))==compatibilidade.end()){
        cout<<a->tipo<<" "<<valorEsperado<<endl;
      cout<<"Tipo incompativel no switch"<<endl;
      }
    }
    else if(javi.find(a->valor)!=javi.end())cout<<"Case já inserido"<<endl;
    else javi.insert(a->valor);

    
  }
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
  switcha(expr* a,cazezeromais* b){
    if(b->valorEsperado=="")return;
    if(a->type!=b->valorEsperado){
      if(compatibilidade.find(make_pair(a->type,b->valorEsperado))==compatibilidade.end()){
        cout<<a->type<<" "<<b->valorEsperado<<endl;
        cout<<"Tipo incompativel no switch"<<endl;
      }
    }    
  }
};

class cmd{

};

#endif
