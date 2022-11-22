#ifndef CLASSES
#define CLASSES
#include<vector>
#include<functional>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

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
    literal(string t){
        tipo = t;
        value = "";
    }
};



class identifier : public Node{
  public:
  string nome;
  identifier(string a){
    nome = a;
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
  decl_var_prim(primitivos*a, hashtagzeromais*b, cochetezeromais*c, string d){
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


class expr : public Node{
  public:
  vector<string> simbolosUsados;
  string tipo ="UNDECLARED";
  void checa(map<string,string> symtable){
    if(simbolosUsados.size()<(1<<30))
    for(auto k:simbolosUsados){
      if(symtable.find(k)==symtable.end()){
        cout<<k<<" nao foi declarado"<<endl;
      }
      else tipo = symtable[k];
    }
    
  }
  expr(expr*a,expr*b,map<string,string>& symtable){
    if(a->simbolosUsados.size()<(1<<30))
    for(auto k:a->simbolosUsados){
      simbolosUsados.push_back(k);
    }
    if(b->simbolosUsados.size()<(1<<30))
    for(auto k:b->simbolosUsados){
      
      simbolosUsados.push_back(k);
    }

    if(a->tipo != b->tipo){
      cout<<a->tipo<<" e "<<b->tipo<<" sao incompativeis"<<endl;
    }
    tipo = a->tipo;
  }
  expr(expr*a,map<string,string>& symtable){
    if(a->simbolosUsados.size()<(1<<30))
    for(auto k:a->simbolosUsados)simbolosUsados.push_back(k);
    tipo = a->tipo;
  }
  expr(identifier* a,map<string,string>& symtable){
    simbolosUsados.push_back(a->nome);
    checa(symtable);

  }
  expr(literal*a,map<string,string>& symtable){
    
    tipo = a->tipo;

  }
};

#endif