#ifndef CLASSES
#define CLASSES
#include<vector>
#include<functional>
#include<iostream>
using namespace std;

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

#endif