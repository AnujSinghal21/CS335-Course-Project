%{
#include<bits/stdc++.h>
#include "globals.hpp"
using namespace std;
extern stack<int> indent_stack;
extern int yylineno;
extern FILE* yyin;
extern string last_token;
extern string last_token_value;
extern int terminated;

int yylex();
int yyerror(const char * msg);

int curr_id = 0;

struct TreeNode{
    string lexeme = "";
    string id;
    int node_type = -1;
    vector<struct TreeNode*> children;
};


map<string, string> id_to_label;
map<string, vector<string> > edges;



struct TreeNode * makeNode(string lexeme, int node_type = -1){
    struct TreeNode * node = new (struct TreeNode);
    node->id = "N" + to_string(curr_id++);
    node->lexeme = lexeme;
    node->node_type = node_type;
    return node;
}
void labelNode(struct TreeNode * node){
    id_to_label[node->id] = node->lexeme;
    return;
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

void printTree(struct TreeNode * node){
    if (node == NULL){
        return;
    }
    cout << node->id << " " << node->lexeme << " has type: " << node->node_type << endl;
    for (auto child: node->children){
        printTree(child);
    }   
    return;
}

TreeNode * root = NULL;

%}

%union {
    struct TreeNode * node;
}

%token <node> ASSIGN_AND "&="
%token <node> ASSIGN_DIVIDE "/="
%token <node> ASSIGN_DOUBLESLASH "//="
%token <node> ASSIGN_EQUAL "="
%token <node> ASSIGN_LEFTSHIFT "<<="
%token <node> ASSIGN_MINUS "-="
%token <node> ASSIGN_MOD "%="
%token <node> ASSIGN_MULTIPLY "*="
%token <node> ASSIGN_OR "|="
%token <node> ASSIGN_PLUS "+="
%token <node> ASSIGN_POWER "**="
%token <node> ASSIGN_RIGHTSHIFT ">>="
%token <node> ASSIGN_XOR "^="
%token <node> CLOSE_SQUARE_BRACKET "]"
%token <node> DEDENT
%token <node> ENDMARKER
%token <node> INDENT
%token <node> KEY_BREAK "break"
%token <node> KEY_CLASS "class"
%token <node> KEY_CONTINUE "continue"
%token <node> KEY_ELIF "elif"
%token <node> KEY_ELSE "else"
%token <node> KEY_FALSE "False"
%token <node> KEY_FOR "for"
%token <node> KEY_FUNCTION_DEF "def"
%token <node> KEY_GLOBAL "global"
%token <node> KEY_IF "if"
%token <node> KEY_NONE "None"
%token <node> KEY_RETURN "return"
%token <node> KEY_TRUE "True"
%token <node> KEY_WHILE "while"
%token <node> NAME 
%token <node> NEWLINE
%token <node> NUMBER
%token <node> OPEN_SQUARE_BRACKET "["
%token <node> OPER_AND "and"
%token <node> OPER_AND_BITWISE "&"
%token <node> OPER_CLOSE_BRACKET ")"
%token <node> OPER_COLON ":"
%token <node> OPER_COMMA ","
%token <node> OPER_DIVIDE "/"
%token <node> OPER_DOT "."
%token <node> OPER_EQUAL "=="
%token <node> OPER_GREATER_THAN ">"
%token <node> OPER_GREATER_THAN_EQUAL ">="
%token <node> OPER_IN "in"
%token <node> OPER_INT_DIV "//"
%token <node> OPER_IS "is"
%token <node> OPER_LEFT_SHIFT "<<"
%token <node> OPER_LESS_GREATER "<>"
%token <node> OPER_LESS_THAN "<"
%token <node> OPER_LESS_THAN_EQUAL "<="
%token <node> OPER_MINUS "-"
%token <node> OPER_MOD "%"
%token <node> OPER_MULTIPLY "*"
%token <node> OPER_NEGATIVE "~"
%token <node> OPER_NOT "not"
%token <node> OPER_NOT_EQUAL "!="
%token <node> OPER_OPEN_BRACKET "("  
%token <node> OPER_OR "or"
%token <node> OPER_OR_BITWISE "|"
%token <node> OPER_PLUS "+"
%token <node> OPER_POWER "**"
%token <node> OPER_REFERENCE "->"
%token <node> OPER_RIGHT_SHIFT ">>"
%token <node> OPER_SEMICOLON ";"
%token <node> OPER_XOR_BITWISE "^"
%token <node> STRING

%type <node> and_expr
%type <node> and_test
%type <node> annasign
%type <node> arglist
%type <node> arglist_dash
%type <node> arith_expr
%type <node> assign_dash
%type <node> atom
%type <node> atom_expr
%type <node> augassign
%type <node> break_stmt
%type <node> classdef 
%type <node> comp_op
%type <node> comparison
%type <node> compound_stmt
%type <node> continue_stmt
%type <node> elif_stmt
%type <node> else_stmt
%type <node> else_stmt_dash
%type <node> expr
%type <node> expr_stmt
%type <node> expr_stmt_dash
%type <node> factor
%type <node> flow_stmt
%type <node> for_stmt
%type <node> funcdef
%type <node> funcdef_dash 
%type <node> global_stmt
%type <node> if_stmt
%type <node> if_stmt_dash
%type <node> inheritlist
%type <node> input_file
%type <node> input_file_dash
%type <node> NAME_dash
%type <node> not_test
%type <node> or_test
%type <node> parameters
%type <node> parameters_dash
%type <node> power
%type <node> return_stmt
%type <node> shift_expr
%type <node> simple_stmt
%type <node> small_stmt
%type <node> small_stmt_dash
%type <node> stmt
%type <node> stmt_dash
%type <node> suite
%type <node> term
%type <node> test
%type <node> tfpdef
%type <node> trailer
%type <node> typedargslist
%type <node> while_stmt
%type <node> xor_expr

%start input_file

%%

////// Anuj's reviewed starts here

input_file : input_file_dash ENDMARKER{
    if ($1 != NULL){
        $$ = $1;
    }else{
        $$ = NULL;
    }
    root = $$;
}
;

input_file_dash : input_file_dash NEWLINE
    {
        $$ = $1;
    }
    | input_file_dash stmt
    {
        if ($1 != NULL){
            $$ = $1;
            appendChild($$, $2);
        }else{
            $$ = makeNode("", SUITE_TYPE);
            if ($2->node_type == STATEMENT_GROUP_TYPE){
                for (auto x: $2->children){
                    appendChild($$, x);
                }
            }else{
                appendChild($$, $2);
            }
        }
    }
    | /*empty*/ 
    {
        $$ = NULL;
    }
    ;

stmt : simple_stmt
    {
        $$ = $1;
    }
    | compound_stmt
    {
        $$ = $1;
    }
    ;

simple_stmt : small_stmt_dash NEWLINE
    {
        $$ = $1;
    }
    ;

small_stmt_dash : small_stmt_dash ";" small_stmt 
    {
        if ($1->node_type == STATEMENT_GROUP_TYPE){
            $$ = $1;
            appendChild($$, $3);
        }else{
            $$ = makeNode("", STATEMENT_GROUP_TYPE);
            appendChild($$, $1);
            appendChild($$, $3);
        }
    }
    | small_stmt
    {
        $$ = $1;
    }

    ;

small_stmt : expr_stmt 
    {
        $$ = $1;
    }
    | flow_stmt 
    {
        $$ = $1;
    }
    | global_stmt
    {
        $$ = $1;
    }
    ;

expr_stmt : test expr_stmt_dash
    {
        $$ = makeNode("EXPR_STATEMENT",STATEMENT_TYPE);
        if ($2 == NULL){
            appendChild($$, $1);
        }else{
            appendChild($$, $2);
            insert_to_front($2, $1);
        }
    }
    ;

expr_stmt_dash : annasign 
    {
        $$ = $1;
    }
    | augassign test
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);
    }
    | assign_dash
    {
        $$ = $1;
    }
    | /*empty*/ 
    {
        $$ = NULL;
    }
    ;

assign_dash: ASSIGN_EQUAL test assign_dash
    {
        $$ = makeNode("=",EXPR_TYPE);
        appendChild($$, $3);
        insert_to_front($3, $2);
    }
    | ASSIGN_EQUAL test
    {
        $$ = makeNode("=",EXPR_TYPE);
        appendChild($$, $2);
    }
    ;

annasign : OPER_COLON test 
    {
        $$ = makeNode(":", EXPR_TYPE);
        appendChild($$, $2);
    }
    | OPER_COLON test ASSIGN_EQUAL test
    {
        $$ = makeNode(": =", EXPR_TYPE);
        appendChild($$, $2);
        appendChild($$, $4);
    }
    ;

augassign : ASSIGN_PLUS
    {
        $$ = $1;
    }
    | ASSIGN_MINUS
    {
        $$ = $1;
    }
    | ASSIGN_MULTIPLY
    {
        $$ = $1;
    }
    | ASSIGN_DIVIDE
    {
        $$ = $1;
    }
    | ASSIGN_MOD
    {
        $$ = $1;
    }
    | ASSIGN_AND
    {
        $$ = $1;
    }
    | ASSIGN_OR
    {
        $$ = $1;
    }
    | ASSIGN_XOR
    {
        $$ = $1;
    }
    | ASSIGN_LEFTSHIFT
    {
        $$ = $1;
    }
    | ASSIGN_RIGHTSHIFT
    {
        $$ = $1;
    }
    | ASSIGN_POWER
    {
        $$ = $1;
    }
    | ASSIGN_DOUBLESLASH
    {
        $$ = $1;
    }
    ;

flow_stmt : break_stmt 
    {
        $$ = $1;
    }
    | continue_stmt
    {
        $$ = $1;
    }
    | return_stmt
    {
        $$ = $1;
    }
    ;

break_stmt : KEY_BREAK
    {
        $$ = makeNode("break",STATEMENT_TYPE);
    }
    ;

continue_stmt : KEY_CONTINUE
    {
        $$ = makeNode("continue",STATEMENT_TYPE);
    }
    ;

return_stmt : KEY_RETURN test 
    {
        $$ = makeNode("return",STATEMENT_TYPE);
        appendChild($$, $2);
    }
    ;

global_stmt : KEY_GLOBAL NAME_dash
    {
        $$ = makeNode("global",STATEMENT_TYPE);
        if ($2->node_type == MISC_TYPE){
            for (auto x: $2->children){
                appendChild($$, x);
            }
        }else{
            appendChild($$, $2);
        }
    }
    ;

NAME_dash : NAME_dash OPER_COMMA NAME 
    {
        if ($1->node_type == MISC_TYPE){
            $$ = $1;
            appendChild($$, $3);
        }else{
            $$ = makeNode("",MISC_TYPE);
            appendChild($$, $1);
            appendChild($$, $3);
        }
    }
    | NAME
    {
        $$ = $1;
    }
    ;

compound_stmt : funcdef
    {
        $$ = $1;
    }
    | if_stmt
    {
        $$ = $1;
    }
    | while_stmt
    {
        $$ = $1;
    }
    | for_stmt
    {
        $$ = $1;
    }
    | classdef
    {
        $$ = $1;
    } 
    ;

if_stmt : if_stmt_dash else_stmt_dash 
    {
        $$ = $1;
        if ($2 != NULL){
            appendChild($$, $2);
        }
    }
    ;

if_stmt_dash : KEY_IF test OPER_COLON suite 
    {
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);    
    }
    ;

else_stmt_dash : else_stmt 
    {
        $$ = $1;
    }
    | elif_stmt else_stmt
    {
        $$ = $1;
        appendChild($$, $2);
    }
    | elif_stmt
    {
        $$ = $1;
    }
    | /*empty*/ {
        $$ = NULL;
    }
    ;

elif_stmt : KEY_ELIF test OPER_COLON suite elif_stmt
    {
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
        appendChild($$, $5);        
    }
    | KEY_ELIF test OPER_COLON suite
    {
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
    }
    ;

else_stmt : KEY_ELSE OPER_COLON suite
    {
        $$ = $1;
        appendChild($$, $3);
    }
    ;

classdef: "class" NAME inheritlist ":" suite
    {
        $$ = makeNode("",CLASS_TYPE);
        appendChild($$, $2);
        if ($3 != NULL){
            appendChild($$, $3);
        }
        appendChild($$, $5);
    }
    ;

inheritlist: "(" NAME ")"
    {
        $$ = $2;
    }
    |
    "(" ")"
    {
        $$ = NULL;
    }
    | /*Empty*/ 
    {
        $$ = NULL;
    }
    ;

for_stmt: "for" test "in" test ":" suite
    {   
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
        appendChild($$, $6);
    }
    ;

while_stmt: KEY_WHILE test OPER_COLON suite
    {
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
    }
    ;

funcdef : "def" NAME parameters funcdef_dash ":" suite {
        $$ = makeNode("def",FUNCTION_TYPE);
        appendChild($$,$2);
        appendChild($$,$3);
        appendChild($$,$4);
        
        if ($4 != NULL){
            appendChild($$,$4);
        }
        appendChild($$, $6);
    }
    ;

funcdef_dash : "->" test 
    {
        $$ = $2;
    }
    | /*Empty*/
    {
        $$ = NULL;
    }
    ;

parameters : "(" parameters_dash ")" 
    {
        $$ = $2;
    }
    ;

parameters_dash : typedargslist
    {
        if ($1->node_type == PARAMETERS_TYPE){
            $$ = $1;
        }else{
            $$ = makeNode("parameters",PARAMETERS_TYPE);
            appendChild($$, $1);
        }
    }
    | /*Empty*/
    {   
        $$ = makeNode("parameters",PARAMETERS_TYPE);
    }
    ;

typedargslist : typedargslist "," tfpdef
    {
        if ($1->node_type == PARAMETERS_TYPE){
            $$ = $1;
            appendChild($$, $3);
        }else{
            $$ = makeNode("parameters", PARAMETERS_TYPE);
            appendChild($$, $1);
            appendChild($$, $3);
        }
    }
    | tfpdef
    {
        $$ = $1;
    }
    ;

tfpdef : NAME ":" atom_expr
    {
        $$ = makeNode("",EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    |
    NAME
    {
        $$ = $1;
    }
    |
    NAME ":" atom_expr "=" test
    {
        $$ = makeNode("",EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
        appendChild($$, $5);
    }
    ;

suite: simple_stmt 
    {
        $$ = makeNode("", SUITE_TYPE);
        appendChild($$, $1);
    }
    | NEWLINE INDENT stmt_dash DEDENT
    {
        $$ = makeNode("", SUITE_TYPE);
        for (auto x: $3->children){
            appendChild($$, x);
        }
    }
    ;

stmt_dash : stmt_dash stmt 
    {
        appendChild($1, $2);
        $$ = $1;
    }
    | stmt
    {
        $$ = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild($$, $1);
    }
    ;

test: or_test
    {
        $$ = $1;
    }
    ;

or_test : and_test
    {
        $$ = $1;
    }
    | or_test "or" and_test
    {
        $$ = makeNode("or",EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

and_test : not_test
    {
        $$ = $1;
    }
    | and_test "and" not_test
    {
        $$ = makeNode("and",EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

not_test : "not" not_test
    {
        $$ = makeNode("not",EXPR_TYPE);
        appendChild($$, $2);
    }
    | comparison
    {
        $$ = $1;
    }
    ;

comparison : comparison comp_op expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE); 
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | expr
    {
        $$ = $1;
    }
    ; 

comp_op: "<"
    {
        $$ = $1;
    }
    |">"
    {
        $$ = $1;
    }
    |"=="
    {
        $$ = $1;
    }
    |">="
    {
        $$ = $1;
    }
    |"<="
    {
        $$ = $1;
    }
    |"<>"
    {
        $$ = $1;
    }
    |"!="
    {
        $$ = $1;
    }
    |"is"
    {
        $$ = $1;
    }
    |"is" "not"
    {
        $$ = makeNode("is not", OPERATOR_TYPE);
    }
    ;

expr : xor_expr
    {
        $$ = $1; 
    }
    | expr "|" xor_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

xor_expr : and_expr
    {
        $$ = $1;
    }
    | xor_expr "^" and_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

and_expr: shift_expr
    {
        $$ = $1;
    }
    | and_expr "&" shift_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

shift_expr : arith_expr
    {
        $$ = $1;
    }
    | shift_expr "<<" arith_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | shift_expr ">>" arith_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

arith_expr : term
    {
        $$ = $1;
    }
    | arith_expr "+" term
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | arith_expr "-" term
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

term: factor
    {
        $$ = $1;
    }
    | term "*" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | term "/" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | term "%" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    | term "//" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

factor : "+" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);
    }
    | "-" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);
    }
    | "~" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);
    }
    | power
    {
        $$ = $1;
    }
    ;

power : atom_expr
    {
        $$ = $1;
    }
    | atom_expr "**" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    ;

atom_expr : atom trailer
    {
        if ($2 == NULL){
            $$ = $1;
        }else{
            $$ = makeNode("atom_expr", EXPR_TYPE);
            appendChild($$, $1);
            appendChild($$, $2);
        }
    }
    ;

trailer : "(" arglist ")" 
    {
        $$ = makeNode("()", EXPR_TYPE);
        if ($2 != NULL){
            for (auto x: $2->children){
                appendChild($$, x);
            }
        }
    }
    | "[" test "]" 
    {
        $$ = makeNode("[]", EXPR_TYPE);
        appendChild($$, $2);
    }
    | "." NAME
    {
        $$ = makeNode(".", EXPR_TYPE);
        appendChild($$, $2);
    }
    | /*Empty*/ 
    {
        $$ = NULL;
    }
    ;

atom : NAME
    {
        $$ = makeNode($1->lexeme,NAME_TYPE);
    }
    | NUMBER
    {
        $$ = makeNode($1->lexeme,NUMBER_TYPE);
    }
    | STRING
    {
        $$ = makeNode($1->lexeme,STRING_TYPE);
    }
    | "None"
    {
        $$ = $1;
    }
    | "True"
    {
        $$ = makeNode($1->lexeme,BOOLEAN_TYPE);
    }
    | "False"
    {
        $$ = makeNode($1->lexeme,BOOLEAN_TYPE);
    }
    | "(" test ")"
    {
        $$ = $2;
    }
    | "[" arglist "]" 
    {
        $$ = makeNode("[]", LIST_TYPE);
        if ($2 != NULL){
            for (auto x: $2->children){
                appendChild($$, x);
            }
        }
    }
    ;

arglist : arglist_dash
    {
        $$ = $1;
    }
    | /*empty*/ 
    {
        $$ = NULL;
    }
    ; 

arglist_dash : arglist_dash "," test
    {
        appendChild($1, $3);
        $$ = $1;
    }
    | test
    {
        $$ = makeNode("",MISC_TYPE);
        appendChild($$, $1);
    }

////// Anuj's reviewed ends here

%%
void printAST(char * filename){
    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        cerr << "Error opening file" << endl;
        return;
    }
    fprintf(file, "digraph G {\n");
    for (auto it = id_to_label.begin(); it != id_to_label.end(); it++){
        string quoted = "";
        for (auto c: it->second){
            if (c == '\"'){
                quoted += "\\\"";
            }else if (c == '\\'){
                quoted += "\\\\";
            }else{
                quoted += c;
            }
        }
        fprintf(file, "%s [label=\"%s\"]\n", it->first.c_str(), quoted.c_str());
    }
    for (auto it = edges.begin(); it != edges.end(); it++){
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++){
            fprintf(file, "%s -> %s\n", it->first.c_str(), jt->c_str());
        }
    }
    fprintf(file, "}\n");
    return;
}
void help_printer(){
    cout << "USAGE: " << endl;
    cout << "[-input <path-to-inputfile>]: specify the file path to parse, if not given, takes input from stdin" << endl;
    cout << "[-output <path-to-outputfile>]: specify the file path to write the ast, if not given, defaults to ast.dot" << endl;
    cout << "[-verbose]: prints verbose messages to stdout, error messages are anyways printed" << endl;
    cout << "[-help]: print usage instructions" << endl;
    cout << "For more help regarding how to use and output, refer to doc" << endl;
    return;
}

int main(int argc, char ** argv){
    FILE *file;
    int verbose = 0;
    int print_help = 0;
    int inputfilearg = -1;
    int outputfilearg = -1; 
    char default_output_name[] = "ast.dot";
    indent_stack.push(0);

    for (int i = 1; i < argc; i++){
        string arg = argv[i];
        if (arg == "-input"){
            if (i+1 < argc){
                inputfilearg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-output"){
            if (i+1 < argc){
                outputfilearg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-verbose"){
            verbose = 1;
        }else {
            print_help = 1;
        }
    }
    if (print_help){
        help_printer();
        return 0;
    }
    if (inputfilearg == -1){
        yyin = stdin;
    }else{
        file = fopen(argv[inputfilearg], "r");
        if (file == NULL) {
            cerr << "Error opening file" << endl;
            return 0;
        }else{
            yyin = file;
        }
    }
    if (verbose){
        cout << "Started parsing" <<endl;
    }

    // string temp_name = "Hello";
    // vector<symtable_entry *> temp_params;
    // current_func = new symtable_func(temp_name, temp_params);

    yyparse();
    printTree(root);
    if (verbose){
        if (terminated){
            cout << "Error in parsing, AST generated might be incomplete/erroneous" << endl;
        }else{
            cout << "Parsing complete without errors, printing abstract syntax tree" << endl;
        }
    }
    if (outputfilearg == -1){
        printAST(default_output_name);
        if (verbose){
            cout << "AST written in file: " << default_output_name << endl;
        }
    }else{
        printAST(argv[outputfilearg]);
        if (verbose){
            cout << "AST written in file: " << argv[outputfilearg] << endl;
        }
    }

    fclose(yyin);

    return 0;
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