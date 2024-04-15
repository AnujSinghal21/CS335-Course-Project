#include "includes.hpp"
extern struct type int_node;
extern struct type float_node;
extern struct type bool_node;
extern struct type str_node;
extern struct type void_node;
extern string last_token;
extern string last_token_value;
extern int terminated;
extern int yylineno;

void Error::sem_var_redeclare(string varname,long long line_no, long long prev_line_no){
    cout << "Error at line_no : " << line_no << " can't declare variable in this scope again" << endl;
    cout << "variable " << varname << " already declared at line no " << prev_line_no << endl;
    Error::clean_up();
}

void Error::type_mismatch(int yylineno, struct type t1, struct type t2, string op){
    if(!(type_equal(t2,int_node) && (type_equal(t1,float_node) || type_equal(t1,bool_node)))){
    cout << "TYPE_ERROR: Incompatible types "<< type_to_string(t1) << " and " << type_to_string(t2) << " at \"" << op << "\" at line no" << yylineno << endl;
    Error::clean_up();
    }
}

void Error::sem_func_redeclare(string funcname,long long line_no, long long prev_line_no){
    cout << "Error at line_no : " << line_no << " can't declare function in this scope again" << endl;
    cout << "function " << funcname << " already declared at line no " << prev_line_no << " with same parameter types" << endl;
    Error::clean_up();
}

void Error::sem_no_declaration_var(string name, long long line_no){
    cout << "Error at line no : " << line_no << endl;
    cout << "variable " << name << " is not declared before use" << endl;
    Error::clean_up();
}

void Error::sem_returntype_error(string name,string type1,string type2, long long line_no){
    cout << "Error at line no : " << line_no << endl;
    cout << "Return type of function " << name << " is " << type1 << " but return type is " << type2 << endl;
    Error::clean_up();
}

void Error::invalid_unary_operation(int yylineno, struct type t1, string operation){
    cout<<"Error at line no : " << yylineno<<endl;
    cout<<"Invalid Unary Operation " <<operation<< " with type " <<type_to_string(t1);
    Error::clean_up();
}

void Error::other_semantic_error(string msg, long long line_no){
    cout << msg << " at line no : " << line_no << endl;
    Error::clean_up();
}

void Error::use_before_declaration(string name, long long line_no){
    cerr << "SEMANTIC ERROR: Use of undeclared variable " << name << " at line no " << line_no << endl;
    Error::clean_up();
}
void Error::member_not_found(string name, string member, long long line_no){
    cerr << "SEMANTIC ERROR: Member " << member << " not found in class " << name << " at line no " << line_no << endl;
    Error::clean_up();
}

void Error::clean_up(){
    // exit(0);
}

int yyerror(const char* msg) {
    if (terminated){
        return 0;
    }
    terminated = 1;
    if (last_token == "INDENT"){
        cout << "SYNTAX ERROR: Unexpected indent at line " << yylineno << endl;
    }else if (last_token == "DEDENT"){
        cout << "SYNTAX ERROR: Unexpected dedent at line " << yylineno << endl;
    }else if (last_token == "NEWLINE"){
        cout << "SYNTAX ERROR: Unexpected line break at line " << yylineno << endl;
    }else if (last_token == "NUMBER"){
        cout << "SYNTAX ERROR: Unexpected number: " << last_token_value << " at line " << yylineno << endl;
    }else if (last_token == "STRING"){
        cout << "SYNTAX ERROR: Unexpected string literal: " << last_token_value << " at line " << yylineno << endl;
    }else if (last_token == "NAME"){
        cout << "SYNTAX ERROR: Unexpected identifier: " << last_token_value << " at line " << yylineno << endl;
    }else{
        cout << "SYNTAX ERROR: Unexpected token: " << last_token << " at line " << yylineno << endl;
    }
    return 0;
}
