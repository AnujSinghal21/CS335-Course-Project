#ifndef GLOBALS
#define GLOBALS

#include <bits/stdc++.h>
using namespace std;

// #include <node.hpp>
// #include "symtab.hpp"
// #include <threeAC.hpp>

// symtable_global symtab;
// symtable_func* current_func = NULL;

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
    PARAMETERS_TYPE,
    BOOLEAN_TYPE,
    MISC_TYPE
};

struct TreeNode{
    string lexeme = "";
    string id;
    int node_type = -1;
    vector<struct TreeNode*> children;
};

#endif