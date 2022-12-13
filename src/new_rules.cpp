#include "new_rules.hpp"

decl_fun::decl_fun(type_name *t, typedlpar *tlpar, block *bl) {
  //intermid = t->name;

  if(bl != NULL) intermid += bl->intermid;
}

statement::statement(decl_fun *decl_f) {
  if(decl_f != NULL) intermid = decl_f->intermid;
}

statement::statement(cmd *c) {
  if(c != NULL) intermid = c->ret;
}

statements::statements(statement *st, statements *stmts) {
  if(st != NULL) intermid += st->intermid;
  if(stmts != NULL) intermid += stmts->intermid;
}


programa::programa(state &estado, statements *stmts) {
  if(stmts != NULL) intermid += stmts->intermid;
  estado.arquivoEscrita += intermid;
}


literal::literal(string tipo, string valor,state& estado){
    type=tipo;
    value=valor;
    
    intermid = "t"+to_string(estado.nxtId);
    ret = intermid+" = "+valor+";\n";
}

identifier::identifier(string nome) {
    name = nome;
}

bool expr::eInteiro(){
    for(auto x:valor){
      if(x<'0' || x>'9'){
        if(x!='-')
        return false;
      }
    }
    return true;
}

int expr::getVal(){
    if(valor.empty())return 0;
    return stoi(valor);
}

expr::expr(state & estado, expr *left,string operacao, expr *right) {
    // cout<<operacao<<endl;
    qualId = estado.nxtId;
    intermid = "t"+to_string(estado.nxtId);
    if(left->eInteiro()){
      if(operacao=="&" || operacao == "*"){
        if(left->getVal()==0){
          ret = left->ret;
          estado.nxtId = left->qualId;
          qualId = estado.nxtId;
          cout<<"left "<<estado.nxtId<<endl;
          intermid = "t"+to_string(estado.nxtId);
        
          type = left->type;
          return;
        }
      }
      if(operacao=="|"){
        if(left->getVal()!=0){
          ret = left->ret;
          estado.nxtId = left->qualId ;
          qualId = estado.nxtId;
          intermid = "t"+to_string(estado.nxtId);
          type = left->type;
          return;
        }
      }

      if(operacao == "&"){
        valor = to_string(left->getVal()&right->getVal());
      }
      else if(operacao == "|"){
        valor = to_string(left->getVal()|right->getVal());
      }
      else if(operacao == "+"){
        valor = to_string(left->getVal()+right->getVal());
      }
      else if(operacao == "*"){
        valor = to_string(left->getVal()*right->getVal());
      }
      else if(operacao == "/"){
        valor = to_string(left->getVal()/right->getVal());
      }
      else if(operacao == "-"){
        valor = to_string(left->getVal()-right->getVal());
      }
      else if(operacao == "%"){
        valor = to_string(left->getVal()%right->getVal());
      }
      else if(operacao == "=="){
        valor = to_string(left->getVal()==right->getVal());
      }
      else if(operacao == "!="){
        valor = to_string(left->getVal()!=right->getVal());
      }
      else if(operacao == "<"){
        valor = to_string(left->getVal()<right->getVal());
      }
      else if(operacao == ">"){
        valor = to_string(left->getVal()>right->getVal());
      }
      else if(operacao == "<="){
        valor = to_string(left->getVal()<=right->getVal());
      }
      else if(operacao == ">="){
        valor = to_string(left->getVal()>=right->getVal());
      }
    }
    

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

expr::expr(state &estado, expr *exp) {
    qualId = estado.nxtId - 1;
    valor = exp->valor;
    ret = exp->ret;
    intermid = "t"+to_string(qualId);
    if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
}

expr::expr(state &estado, string operacao, expr *exp) {
  qualId = estado.nxtId;
  valor = exp->valor;
  ret = exp->ret;

  intermid = "t"+to_string(qualId);

  estado.nxtId++;
  if(operacao == "++" or operacao == "--") {
    if(exp->isId) {
      this->isId = true;
      this->rootId = exp->rootId;
      //TODO
      // Tentativa de ter algo como ++(++a) recursivo que de fato incremente "a" multiplas vezes
    }
    ret += intermid + " = " + exp->intermid + " " + operacao[0] + " 1;\n";
    ret += exp->intermid + " = " + intermid + ";\n";  
  } else if(operacao == "!") {
    ret += intermid + " = " + "not " + exp->intermid + ";\n";
  } else if(operacao == "-") {
    ret += intermid + " = " + "0 - " + exp->intermid + ";\n";
  }
  if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
}

expr::expr(state& estado, identifier *id) {
    isId = true;
    rootId = id->name;
    qualId = estado.nxtId;
    symbol_names.push_back(id->name);
    valor = -1;
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

expr::expr(state& estado, literal *lit) { 
    qualId = estado.nxtId;
    estado.nxtId++;
    intermid = lit->intermid;
    ret = lit->ret;
    type = lit->type; 
    valor = lit->value;
}

assign_expr::assign_expr() {}

assign_expr::assign_expr(expr* a){
    intermid = a->intermid;
    ret = a->ret;
}

assign_expr_maybe::assign_expr_maybe() {}

assign_expr_maybe::assign_expr_maybe(assign_expr * a) {
    intermid = a->intermid;
    ret = a->ret;
}

primitive::primitive(string type) : type(type) {}

cochetezeromais::cochetezeromais(cochetezeromais *a) {}

hashtagzeromais::hashtagzeromais(hashtagzeromais *a) {}


decl_var_prim::decl_var_prim(primitive *t, string var_name) {
    type = t->type;
    name = var_name;
}


const_decl_var::const_decl_var(decl_var_prim *var) {
    name = var->name;
    type = "CONST." + var->type;
}

all_decl_var::all_decl_var() {}

all_decl_var::all_decl_var(state& estado,decl_var_prim *var) {
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

all_decl_var::all_decl_var(state & estado,const_decl_var *var) {
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

cmd_decl_var::cmd_decl_var() {}
cmd_decl_var::cmd_decl_var(state& estado,all_decl_var *a, assign_expr_maybe *b) {
    if(b==NULL)return;
    if(!b->intermid.empty()) {
      ret = b->ret;
      ret += a->intermid + " = " + b->intermid + '\n';
    }
}


type_name::type_name(primitive *prim_type) : name(prim_type->type){};

type_name::type_name(string id_type) : name(id_type){};

parameter::parameter(type_name *t, string id) : type(t->name), id(id) {}

caze::caze(literal * t){
    tipo = t->type;
    valor = t->value;
}

cazezeromais::cazezeromais() {}
cazezeromais::cazezeromais(state &estado, caze* a , cazezeromais*b) {
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

block::block(statements *stmts) {
  if(stmts != NULL) intermid = stmts->intermid;
}

cmd::cmd(cmd_decl_var *decl_var) {
  if (decl_var != NULL) ret = decl_var->ret; 
}

cmd::cmd(block *bl) {
  if(bl != NULL) ret = bl->intermid;
}

cmd::cmd(cmd_cond *c_c) {
  if (c_c != NULL) ret = c_c->intermid;
}

cmd::cmd(state &estado, expr *exp) {
  //cout << "ret = " << exp->ret << endl;
  //cout << "intermid = " << exp->intermid << endl;
  ret = exp->ret;
}

cmd::cmd(state & estado, string s, expr* exp) {
  if(s == "EXIT WHEN") {
    ret = exp->ret;
    ret += "if ("+exp->intermid+") goto l"+to_string(estado.labelId+1)+";\n";
  }
  else if(s == "RETURN") {
    ret = exp->ret;
    ret += "return " + exp->intermid + ";\n";
  }
}

cmd::cmd(state& estado, string s) {
  if(s=="BREAK") ret = "goto l"+to_string(estado.labelId+1)+";\n";
  else if(s=="CONTINUE") ret = "goto l"+to_string(estado.labelId)+";\n";
}

cmd::cmd(state& estado, cmd_loop *c_l) {
  if(c_l != NULL) ret = c_l->intermid;
}

cmd::cmd(identifier* id, assign_expr * as){
  //cout<<"::"<<id->name<<" -=- "<<as->intermid<<" -=- "<<as->ret<<" -=- \n";
  ret = as->ret;
  ret+= id->name + " = "+as->intermid+";\n";
  
}

elsea::elsea(state &estado, cmd *c) {
  if(c != NULL) intermid = c->ret;
}

ifa::ifa(state &estado, expr *exp, cmd *c, elsea *el) {
  intermid = exp->ret;
  string labelTrue = "l" + to_string(estado.labelId++); 
  string labelFalse = "l" + to_string(estado.labelId++);
  string labelHasElse = "";
  intermid += "if (" + exp->intermid + ") goto " + labelTrue + ";\n";
  intermid += "goto " + labelFalse + ";\n";
  intermid += labelTrue + ":\n";
  if (c != NULL) intermid += c->ret;
  if (el != NULL) {
    labelHasElse = "l" + to_string(estado.labelId++);
    intermid += "goto " + labelHasElse + ";\n";
  }
  intermid += labelFalse + ":\n";
  if (el != NULL) {
    intermid += el->intermid;
    intermid += labelHasElse + ":\n";
  }
}

cmd_cond::cmd_cond(ifa *iff) {
  if( iff != NULL) intermid = iff->intermid;
}

cmd_loop::cmd_loop(loop *lo) {
  if( lo != NULL) intermid = lo->intermid;
}

cmd_loop::cmd_loop(fora *f) {
  if( f != NULL) intermid = f->intermid;
}

para_for::para_for(cmd_decl_var *decl_var) {
  if( decl_var != NULL) {
    intermid = decl_var->ret;
    ret = intermid;
  }
}

para_for::para_for(expr *exp) {
  if( exp != NULL) {
    intermid = exp->intermid;
    ret = exp->ret;
  }
}

para_for::para_for(string op, expr *exp) {
  if( exp != NULL) {
    intermid = exp->intermid;
    ret = intermid + " = " + intermid + " " + op[0] + " 1;\n";
  }
}

fora::fora(state &estado, para_for *pa, para_for *pb, para_for *pc, cmd *c) {
  intermid = pa->intermid;
  string labelFor= "l" + to_string(estado.labelId++);
  intermid += labelFor + ":\n";

  string labelTrue = "l" + to_string(estado.labelId++);
  string labelFalse = "l" + to_string(estado.labelId++);
  intermid += pb->ret;
  intermid += "if (" + pb->intermid + ") goto " + labelTrue+ ";\n";
  intermid += "goto " + labelFalse + "\n";
  intermid += labelTrue + ":\n";
  intermid += c->ret;
  intermid += pc->ret;
  intermid += "goto " + labelFor + "\n";
  intermid += labelFalse + ":\n";
}

loop::loop(state &estado, cmd *c) {
  intermid = "l"+to_string(estado.labelId)+":\n";
  estado.labelId++;
  if (c != NULL) intermid += c->ret;
  intermid += "goto l" +to_string(estado.labelId-1)+";\n";
  intermid += "l"+to_string(estado.labelId)+":\n";
  estado.labelId++;
}

typedlpar::typedlpar(state & estado, parameter *param, typedlpar *lpar) {
    params.push_back(*param);
    add_sym(estado.tables, param->id, {param->type, false});

    if (lpar->params.size() < (1 << 30))
      for (parameter param : lpar->params) {
        params.push_back(param);
        add_sym(estado.tables, param.id, {param.type, false});
      }
}

switcha::switcha(state &estado, expr* a, cazezeromais* b){
    if(b->valorEsperado=="")return;
    if(a->type!=b->valorEsperado){
      if(compatibilidade.find(make_pair(a->type,b->valorEsperado))==compatibilidade.end()){
        cout << a->type<<" "<<b->valorEsperado<<endl;
        cout << "Tipo incompativel no switch" << endl;
        estado.deuErro = true;
      }
    }    
}
