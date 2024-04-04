#include "globals.hpp"
using namespace std;
int curr_id = 0;

struct TreeNode * makeNode(string lexeme, int node_type = -1){
    struct TreeNode * node = new (struct TreeNode);
    node->id = "N" + to_string(curr_id++);
    node->lexeme = lexeme;
    node->node_type = node_type;
    return node;
}

void appendChild(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.push_back(child);
    // edges[parent->id].push_back(child->id);
    return;
}

void insert_to_front(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.insert(parent->children.begin(), child);
    // edges[parent->id].insert(edges[parent->id].begin(), child->id);
    return;
}

struct type infer_type(struct type op1, struct type op2){
    struct type res;
    return res;
}

int get_size(string type){
    if (type == "int"){
        return 4;
    }
    else if (type == "float"){
        return 4;
    }
    else if (type == "char"){
        return 1;
    }
    else if (type == "bool"){
        return 1;
    }
    else if (type == "void"){
        return 0;
    }
    return 0;
}

string type_to_string(struct type t){
    if (t.elems == -1){
        return t.t;
    }
    else{
        return "list[" + t.t + "]";
    }
    return "";
}

int type_equal(struct type t1, struct type t2){
    if (t1.t == t2.t && !((t1.elems==-1)^(t2.elems== -1))){
        return 1;
    }
    return 0;
}

void Error::sem_var_redeclare(string varname,long long line_no, long long prev_line_no){
    cout << "Error at line_no : " << line_no << " can't declare variable in this scope again" << endl;
    cout << "variable " << varname << " already declared at line no " << prev_line_no << endl;
}

void Error::type_mismatch(int yylineno, struct type t1, struct type t2, string op){
    cout << "TYPE_ERROR: Incompatible types "<< type_to_string(t1) << " and " << type_to_string(t2) << " at \"" << op << "\" at line no" << yylineno << endl;
}

void Error::sem_func_redeclare(string funcname,long long line_no, long long prev_line_no){
    cout << "Error at line_no : " << line_no << " can't declare function in this scope again" << endl;
    cout << "function " << funcname << " already declared at line no " << prev_line_no << " with same parameter types" << endl;
}

void Error::sem_no_declaration_var(string name, long long line_no){
    cout << "Error at line no : " << line_no << endl;
    cout << "variable " << name << " is not declared before use" << endl;
}

void Error::sem_returntype_error(string name,string type1,string type2, long long line_no){
    cout << "Error at line no : " << line_no << endl;
    cout << "Return type of function " << name << " is " << type1 << " but return type is " << type2 << endl;
}

void Error::invalid_unary_operation(int yylineno, struct type t1, string operation){
    cout<<"Error at line no : " << yylineno<<endl;
    cout<<"Invalid Unary Operation " <<operation<< " with type " <<type_to_string(t1);

}

void Error::other_semantic_error(string msg, long long line_no){
    cout << msg << " at line no : " << line_no << endl;
}

void Error::use_before_declaration(string name, long long line_no){
    cerr << "SEMANTIC ERROR: Use of undeclared variable " << name << " at line no " << line_no << endl;
}
void Error::member_not_found(string name, string member, long long line_no){
    cerr << "SEMANTIC ERROR: Member " << member << " not found in class " << name << " at line no " << line_no << endl;
}

void Error::clean_up(){
    exit(0);
}