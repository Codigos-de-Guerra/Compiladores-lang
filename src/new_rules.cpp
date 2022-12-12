#include "new_rules.hpp"

//decl_fun::decl_fun(type_name *t, typedlpar *tlpar, block *b) {}
decl_fun::decl_fun() {
    intermid = "";
}

statement::statement(decl_fun *decl_f) {}
statement::statement(cmd *c) {
  if(c != NULL) intermid = c->ret;
}

statements::statements(statement *st, statements *stmts) {
  if(st != NULL) intermid = st->intermid;
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
    estado.nxtId++;
}

identifier::identifier(string nome) {
    name = nome;
}

expr::expr(state & estado, expr *left,string operacao, expr *right) {
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

expr::expr(state &estado, expr *exp) {
    if (exp->symbol_names.size() < (1 << 30))
      for (string sym_name : exp->symbol_names)
        symbol_names.push_back(sym_name);

    type = exp->type;
}

expr::expr(state& estado, identifier *id) {
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

expr::expr(state& estado, literal *lit) { 
    intermid = lit->intermid;
    ret = lit->ret;
    type = lit->type; 
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
    if(!b->intermid.empty()){
      ret = b->ret;
      ret += a->intermid + " = " + b->intermid + '\n';
      // estado.arquivoEscrita += ret;
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

elsea::elsea () {}

ifa::ifa (state &estado, expr *exp, cmd *c, elsea *el) {
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
