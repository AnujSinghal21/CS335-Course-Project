#ifndef GLOBALS
#define GLOBALS

#include <bits/stdc++.h>
using namespace std;

struct type{
    string t = "-1";
    int size = 8;
    int elems = -1;
    //bool is_list = false;
};

#include"symtab.hpp"
#include"threeAC.hpp"
#define DEBUG(msg) \
    std::cerr << "Debug [" << __FILE__ << ":" << __LINE__ << "]: " << msg << std::endl;


// #include <node.hpp>
// #include "symtab.hpp"
// #include <threeAC.hpp>

// symtable_global symtab;
// symtable_func* current_func = NULL;

class Error {
    public: 
        static void clean_up();
        static void sem_var_redeclare(string varname,long long line_no, long long prev_line_no);
        static void sem_func_redeclare(string funcname,long long line_no, long long prev_line_no);
        static void sem_no_declaration_var(string name,long long line_no);
        static void sem_returntype_error(string name,string type1,string type2, long long line_no);
        static void type_mismatch(int yylineno, struct type t1, struct type t2, string op);
        static void invalid_operation(int yylineno, string op, struct type t1);
        static void other_semantic_error(string msg, long long line_no);
        static void invalid_unary_operation(int yylineno, struct type t1, string operation);

};

enum NODE_TYPES {
    EXPR_TYPE,
    NAME_TYPE,
    OPERATOR_TYPE, 
    NUMBER_TYPE,
    STRING_TYPE,
    LIST_TYPE,
    KEYWORD_TYPE,
    FUNCTION_TYPE,
    CLASS_TYPE,
    IF_STATEMENT_TYPE,
    ELIF_STATEMENT_TYPE,
    ELSE_STATEMENT_TYPE,
    WHILE_STATEMENT_TYPE,
    FOR_STATEMENT_TYPE,
    RETURN_TYPE, // the return type of function
    SUITE_TYPE, 
    STATEMENT_TYPE, 
    STATEMENT_GROUP_TYPE,
    TRAILER_TYPE,
    PARAMETERS_TYPE,
    BOOLEAN_TYPE,
    MISC_TYPE
};


int get_size(string type);
string type_to_string(struct type t);

struct TreeNode{
    string lexeme = "";
    string id;
    struct type type;
    string addr = "NOT_ASSIGNED";
    int to_dereference = 0;
    int node_type = -1;
    vector<struct TreeNode*> children;
};

struct TreeNode * makeNode(string lexeme, int node_type);
void appendChild(struct TreeNode* parent, struct TreeNode* child);
void insert_to_front(struct TreeNode* parent, struct TreeNode* child);

struct type infer_type(struct type t1, struct type t2);
int type_equal(struct type t1, struct type t2);
#endif