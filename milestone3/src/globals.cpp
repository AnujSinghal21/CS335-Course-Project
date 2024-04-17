#include "includes.hpp"

/*Lexer*/
stack<int> indent_stack;
int global_indent = 0;
int generated_EOF = 0;
int ready_EOF = 0;
int signal_EOF = 0;
int entered_newline = 0;
string last_token = "";
string last_token_value = "";
stack<char> brackets;
int terminated = 0;

/* node */
int curr_id = 0;
TreeNode * root = NULL;

/* parser */
symtable_global* global_symtable;
map<string, string> id_to_label;
map<string, vector<string> > edges;
symtable_func* curr_symtable_func = NULL;
symtable_class* curr_symtable_class = NULL;
symtable_global* curr_symtable_global;
unordered_set<string> declared_types;
ofstream threeac_file;

struct type int_node;
struct type float_node;
struct type bool_node;
struct type str_node;
struct type void_node;

string asm_lib_file = "lib.s";