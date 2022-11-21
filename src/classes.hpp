#ifndef CLASSES
#define CLASSES
#include<vector>
#include<functional>
#include<iostream>
#include<string>
#include<map>

using namespace std;

class cmd_decl_var;
class all_decl_var;
class assign_expr_maybe;
class decl_var_prim;
class primitivos;
class hashtagzeromais;
class cochetezeromais;
class const_decl_var;
class Node{
public:
  vector<Node*> children;
  function<void(void)> exec;

  Node(vector<Node*> _children = {})
  :children(_children), exec([&](){
    exec_children();
  }){}

  void exec_children(){
    for(auto node : children){
      if(node) node->exec();
    }
  }
};

class literal : public Node{
    public:
    string tipo;
    string value;
    literal(string t,string val){
        tipo = t;
        value = val;
    }
};



class identifier : public Node{
  public:
  identifier(char* a){
    string s = a;
  }
};

class assign_expr : public Node{
  public:

};

class cmd : public Node{
  public:
  cmd(identifier* a, assign_expr* b){

  }
  cmd(cmd_decl_var* a){

  }
};



class cmd_decl_var : public Node{
  public:
  cmd_decl_var(){

  }
  cmd_decl_var(all_decl_var*a, assign_expr_maybe*b){

  }
};

class assign_expr_maybe : public Node{
  public:
  assign_expr_maybe(){

  }
};

class primitivos : public Node{
  public:
  string tipo = "";
  primitivos(string x){
    tipo = x;
  }
};


class decl_var_prim : public Node{
  public:
  string nome = "";
  string tipo = "";
  decl_var_prim(primitivos*a, hashtagzeromais*b, cochetezeromais*c, char*d){
    nome = d;
    tipo = a->tipo;
  }
};

class cochetezeromais : public Node{
  public:
  cochetezeromais(cochetezeromais* a){

  }
};
class hashtagzeromais: public Node{
  public:
  hashtagzeromais(hashtagzeromais* a){

  }
};
class const_decl_var : public Node{
  public:
  string nome = "";
  string tipo = "";
  const_decl_var(decl_var_prim* a){
    nome = a->nome;
    tipo = "CONST."+a->tipo;
  }
};

class all_decl_var : public Node{
  public: 
  all_decl_var(){

  }
  all_decl_var(decl_var_prim* a,map<string,string>&symtable){
    if(symtable.find(a->nome)!=symtable.end()){
      cout<<a->nome<<" já foi declarado como "<<symtable[a->nome]<<endl;
    }
    else symtable[a->nome] = a->tipo;
  }
  all_decl_var(const_decl_var* a,map<string,string>&symtable){
    if(symtable.find(a->nome)!=symtable.end()){
      cout<<a->nome<<" já foi declarado como "<<symtable[a->nome]<<endl;
    }
    else symtable[a->nome] = a->tipo;
  }
}; 

#endif