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
  string ret;
  literal(string tipo, string valor,state& estado){
    type=tipo;
    value=valor;
    
    intermid = "t"+to_string(estado.nxtId);
    ret = intermid+" = "+valor+";\n";
    estado.nxtId++;
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
  string ret = "";
  bool erro = false;
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

  expr(state & estado, expr *left,string operacao, expr *right) {
    intermid = "t"+to_string(estado.nxtId);
    estado.nxtId++;
    ret += left->ret;
    ret += right->ret;
    ret += intermid+" = "+left->intermid+" "+operacao+" "+right->intermid+";\n";

    if (left->symbol_names.size() < (1 << 30))
      for (string sym_name : left->symbol_names)
        symbol_names.push_back(sym_name);

    if (right->symbol_names.size() < (1 << 30))
      for (string sym_name : right->symbol_names)
        symbol_names.push_back(sym_name);

    if (left->type != right->type){
      if(compatibilidade.find(make_pair(left->type,right->type))==compatibilidade.end()){
            cout << left->type << " e " << right->type << " são incompativeis" << endl;
            estado.deuErro = true;
      }
    }

    type = left->type;
  }

  expr(state &estado, expr *exp) {
    if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
  }

  expr(state& estado, identifier *id) {
    symbol_names.push_back(id->name);
    intermid = id->name;
    if (symbol_names.size() < (1 << 30))
      for (string sym_name : symbol_names) {
        optional<symbol> sym = lookup(estado.tables, sym_name);

        if (sym.has_value())
          type = sym.value().first;
        else{
          cout << sym_name << " não foi declarado" << endl;
          estado.deuErro = true;
        }

      }
  }

  expr(state& estado, literal *lit) { 
    intermid = lit->intermid;
    ret = lit->ret;
    type = lit->type; 
  }
};

class assign_expr : public Node {
public:
  string intermid;
  string ret;
  assign_expr(){

  }
  assign_expr(expr* a){
    intermid = a->intermid;
    ret = a->ret;
  }
};

class assign_expr_maybe : public Node {
public:
string intermid = "";
string ret = "";
  assign_expr_maybe() {}
  assign_expr_maybe(assign_expr * a) {
    intermid = a->intermid;
    ret = a->ret;
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
/*
class cmd_loop : public Node {

}
class cmd : public Node {
public:
  string intermid;

  cmd(cmd_loop *a) {

  }
}*/
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

  all_decl_var(state& estado,decl_var_prim *var) {
    intermid = var->name;
    symtable local_table = estado.tables.back();
    auto sym = local_table.find(var->name);

    if (sym != local_table.end()){
      cout << var->name << " já foi declarado como " << sym->second.first
           << endl;
      estado.deuErro = true;
    }
    else
      add_sym(estado.tables, var->name, {var->type, false});
  }

  all_decl_var(state & estado,const_decl_var *var) {
    intermid = var->name;
    symtable local_table = estado.tables.back();
    auto sym = local_table.find(var->name);

    if (sym != local_table.end()){
      cout << var->name << " já foi declarado como " << sym->second.first
           << endl;
      estado.deuErro = true;
    }
    else
      add_sym(estado.tables, var->name, {var->type, true});
  }
};

class cmd_decl_var : public Node {
public:
  string ret;
  cmd_decl_var() {}
  cmd_decl_var(state& estado,all_decl_var *a, assign_expr_maybe *b) {
    if(b==NULL)return;
    if(!b->intermid.empty()){
      ret = b->ret;
      ret += a->intermid + " = " + b->intermid + '\n';
      // estado.arquivoEscrita += ret;
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
  cazezeromais(state &estado, caze* a , cazezeromais*b){
    if(b->valorEsperado!="")
      valorEsperado = b->valorEsperado;
    else valorEsperado = a->tipo;

    javi = b->javi;
    
    if(a->tipo != valorEsperado){
      if(compatibilidade.find(make_pair(a->tipo, valorEsperado))==compatibilidade.end()){
        cout<<a->tipo<<" "<<valorEsperado<<endl;

      cout << "Tipo incompativel no switch" << endl;
      estado.deuErro = true;
      }
    } else if (javi.find(a->valor)!=javi.end()) { 
        cout<<"Case já inserido"<<endl;
        estado.deuErro = true;
    } else javi.insert(a->valor);
  }
};

class block : public Node {
public:
    block() {}
};

class cmd : public Node {
public:
    string ret = "";

    cmd(cmd_decl_var *decl_var) {
        if (decl_var != NULL) ret = decl_var->ret; 
    }

    cmd(block *bl) {
        ret = "PLACEHOLDER\n";
    }
};

class elsea : public Node {
public:
    elsea () {}
};

class ifa : public Node {
public:
    string intermid;

    ifa (state &estado, expr *exp, cmd *c, elsea *el) {
        estado.arquivoEscrita += exp->ret;
        string labelTrue = "l" + to_string(estado.labelId++); 
        string labelFalse = "l" + to_string(estado.labelId++); 
        intermid = "if (" + exp->intermid + ") goto " + labelTrue + ";\n";
        intermid += "goto " + labelFalse + ";\n";
        intermid += labelTrue + ":\n";
        if (c != NULL) intermid += c->ret;
        if (el != NULL) {
            intermid += labelFalse + ":\n";
            intermid += "    aqui vai o else\n";
            // intermid += el->intermid;
        } 
        estado.arquivoEscrita += intermid;
    }
};

class typedlpar {
public:
  vector<parameter> params;

  typedlpar(state & estado, parameter *param, typedlpar *lpar) {
    params.push_back(*param);
    add_sym(estado.tables, param->id, {param->type, false});

    if (lpar->params.size() < (1 << 30))
      for (parameter param : lpar->params) {
        params.push_back(param);
        add_sym(estado.tables, param.id, {param.type, false});
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
  switcha(state &estado, expr* a, cazezeromais* b){
    if(b->valorEsperado=="")return;
    if(a->type!=b->valorEsperado){
      if(compatibilidade.find(make_pair(a->type,b->valorEsperado))==compatibilidade.end()){
        cout << a->type<<" "<<b->valorEsperado<<endl;
        cout << "Tipo incompativel no switch" << endl;
        estado.deuErro = true;
      }
    }    
  }
};

#endif
