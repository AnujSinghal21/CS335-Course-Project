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
extern symtable_global* global_symtable;
int yylex();
int yyerror(const char * msg);

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

int is_declared_type(string t){
    return declared_types.find(t) != declared_types.end();
}

void checker_traverse(struct TreeNode* node){
    if(node == NULL){
        return;
    }

    for(auto child : node->children){
        if(child->node_type == NAME_TYPE){
            if(curr_symtable_func!=NULL){
                curr_symtable_func->check_declaration_var(child->lexeme,yylineno);
            }
            else{
                curr_symtable_global->check_declaration_var(child->lexeme,yylineno);
            }
        }
        checker_traverse(child);
    }
    return;
}
void printTree(struct TreeNode * node){
    if (node == NULL){
        return;
    }
    // cout << node->id << " " << node->lexeme << " has type: " << node->node_type << endl;
    for (auto child: node->children){
        printTree(child);
    }   
    return;
} 

struct type get_max_type(struct type t1, struct type t2){

    int val_t1= 0, val_t2 = 0;
    if(type_equal(t1,float_node)) val_t1 = 5; 
    else if(type_equal(t1,float_node)) val_t1 = 4; 
    else if(type_equal(t1,float_node)) val_t1 = 3; 
    else if(type_equal(t1,float_node)) val_t1 = 2; 
    else if(type_equal(t1,float_node)) val_t1 = 1; 

    if(type_equal(t2,float_node)) val_t2 = 5; 
    else if(type_equal(t2,float_node)) val_t2 = 4; 
    else if(type_equal(t2,float_node)) val_t2 = 3; 
    else if(type_equal(t2,float_node)) val_t2 = 2; 
    else if(type_equal(t2,float_node)) val_t2 = 1; 

    if(val_t1 > val_t2){
        return t1; 
    }else{
        return t2;
    }


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
%type <node> trailerlist
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
        struct type t;
        t.t = "void";

        $$->type = t;
        if ($2 == NULL){
            appendChild($$, $1);
        }else{
            appendChild($$, $2);
            insert_to_front($2, $1);
        }

        symtable_entry* entry=NULL; 

        if($2 != NULL && ($2->lexeme == ":" || $2->lexeme == ":=")){
            //DEBUG("here");
            if(curr_symtable_func!=NULL){
                //DEBUG("Entered Add Function Entry" << curr_symtable_func);
                entry = curr_symtable_func->add_entry($2,yylineno);
                //DEBUG("Exited Add Function Entry");
                $1->type = entry->type;
            }else if(curr_symtable_class!=NULL){
                entry = curr_symtable_class->add_attribute($2,yylineno);        
                $1->type = entry->type;
            }else{
                cout << "add global" << endl;
                entry = curr_symtable_global->add_global_var($2,yylineno);        
                $1->type = entry->type;
            }

            if($2->children.size() == 3){
                checker_traverse($2->children[2]);
                if (!type_equal($1->type, $2->children[2]->type)){
                    Error::type_mismatch(yylineno, $1->type, $2->children[2]->type, "initialization");
                }else{
                    if ($1->type.elems != -1){
                        $1->type.elems = $2->children[2]->type.elems;
                    }
                }
                three_ac::dereference($2->children[2]);
                three_ac::gen("unary", "=", $2->children[2]->addr, "", $2->children[0]->addr);
            } 
        }
        else if ($2 != NULL){
            checker_traverse($2);
            if (type_equal($1->type, $2->children[0]->type)){
                $$->type = $1->type;
            }else{
                Error::type_mismatch(yylineno, $1->type, $2->children[0]->type, "assignment");
            }
            three_ac::dereference($2->children[2]);
            string op = $2->children[1]->lexeme;
            if (op == "="){
                if ($2->children[0]->to_dereference){
                    three_ac::gen("address_assign", "=", $2->children[2]->addr, "", $2->children[0]->addr);
                }else{
                    three_ac::gen("unary", "=", $2->children[2]->addr, "", $2->children[0]->addr);
                }
            }else{
                if ($2->children[0]->to_dereference){
                    string temp = three_ac::new_temp();
                    three_ac::gen("DEREF", "*", $2->children[0]->addr, "", temp);
                    string op = $2->children[1]->lexeme.substr(0, $2->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, temp, $2->children[2]->addr, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", $2->children[0]->addr);
                }else{
                    string op = $2->children[1]->lexeme.substr(0, $2->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, $2->children[0]->addr, $2->children[2]->addr, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", $2->children[0]->addr);
                }
            }
        }
        checker_traverse($1);
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
        $$->addr = $3->addr;
        if ($2->to_dereference){
            three_ac::gen("address_assign", "=", $3->addr, "", $2->addr);
        }else{
            three_ac::gen("unary", "=", $3->addr, "", $2->addr);
        }
    }
    | ASSIGN_EQUAL test
    {
        $$ = makeNode("=",EXPR_TYPE);
        appendChild($$, $2);
     
        three_ac::dereference($2);
        $$->addr = $2->addr;
    }
    ;

annasign : OPER_COLON test 
    {
        $$ = makeNode(":", EXPR_TYPE);
        appendChild($$, $2);
    }
    | OPER_COLON test ASSIGN_EQUAL test
    {
        $$ = makeNode(":=", EXPR_TYPE);
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
        checker_traverse($2);
        //DEBUG($2->type.t);
        curr_symtable_func->check_returntype($2, yylineno);
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
        $$->type.t = "void";
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

classdef: "class" NAME inheritlist {
        curr_symtable_class = new symtable_class($2,$3);
        curr_symtable_global->add_class(curr_symtable_class);
        declared_types.insert($2->lexeme);
    } ":" suite
    {
        $$ = makeNode("",CLASS_TYPE);
        $$->type.t = "void";
        appendChild($$, $2);
        if ($3 != NULL){
            appendChild($$, $3);
        }
        appendChild($$, $6);

        curr_symtable_class = NULL;

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
       /* struct TreeNode* temp1 = makeNode($2->lexeme,NAME_TYPE);
        struct TreeNode* temp2 = makeNode("int",NAME_TYPE);
        struct TreeNode* temp = makeNode("",EXPR_TYPE);
        appendChild(temp,temp1);
        appendChild(temp,temp2);
        curr_symtable_func->add_entry(temp,yylineno); */
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
        appendChild($$, $6);
        $$->type.t = "void";
        if (!type_equal($2->type, int_node)){
            Error::other_semantic_error("TYPE_ERROR: Expected type int for iterator variable in for loop, got " + type_to_string($2->type), yylineno);
        }
    }
    ;

while_stmt: KEY_WHILE test OPER_COLON suite
    {
        $$ = $1;
        appendChild($$, $2);
        appendChild($$, $4);
        $$->type.t = "void";
        if (!type_equal($2->type, bool_node) && !type_equal($2->type, int_node)){
            Error::type_mismatch(yylineno, $2->type, bool_node, "while loop condition");
        }
    }
    ;

funcdef : "def" NAME parameters funcdef_dash {
        curr_symtable_func  = new symtable_func($2,$3,$4,yylineno); 
        if(curr_symtable_class != NULL){
            curr_symtable_class->add_func(curr_symtable_func);
        }else{
            curr_symtable_global->add_func(curr_symtable_func);
        }
        three_ac::gen("beginfunc", "beginfunc", curr_symtable_func->name);
    } ":" suite {
        $$ = makeNode("def",FUNCTION_TYPE);
        appendChild($$,$2);
        appendChild($$,$3);
        if ($4 != NULL){
            appendChild($$,$4);
        }

        appendChild($$, $7);

        $$->type.t = "void";
        curr_symtable_func = NULL;
        three_ac::gen("endfunc");
    }
    ;

funcdef_dash : "->" test 
    {
        //DEBUG($2->lexeme);
        $$ = $2;
    }
    | /*Empty*/
    {
        $$ = makeNode("void",NAME_TYPE);
    }
    ;

parameters : "(" parameters_dash ")" 
    {
        //DEBUG($2);
        //DEBUG("parameters" << $2->children.size());
        $$ = $2;
    }
    ;

parameters_dash : typedargslist
    {
        if (($1 != NULL) && $1->node_type == PARAMETERS_TYPE){
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
        if ($1 != NULL && $1->node_type == PARAMETERS_TYPE){
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

tfpdef : NAME ":" test
    {
        //DEBUG("tfpdef" << $1->lexeme << " " << $3->lexeme);
        $$ = makeNode(":",EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    }
    |
    NAME
    {
        if (curr_symtable_class != NULL){
            if ($1->lexeme == "self"){
                $$ = NULL;
            }else{
                Error::other_semantic_error("TYPE_ERROR: Expected variable type for "+$1->lexeme, yylineno);
            }
        }
    }
    |
    NAME ":" test "=" test
    {
        $$ = makeNode(":=",EXPR_TYPE);
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
    
    
        if(!(((type_equal($1->type,bool_node)) && (type_equal($3->type,bool_node)) ))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = bool_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "or", $1->addr, $3->addr, $$->addr);
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
    
        if(!(((type_equal($1->type,bool_node)) && (type_equal($3->type,bool_node)) ))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = bool_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "and", $1->addr, $3->addr, $$->addr);
    }
    ;

not_test : "not" not_test
    {
        $$ = makeNode("not",EXPR_TYPE);
        appendChild($$, $2);

        if(!(((type_equal($2->type,bool_node))))){
            if ($2->type.t != "-1")
                Error::invalid_unary_operation(yylineno,$2->type,"not");
        }        

        $$->type = bool_node;
        three_ac::dereference($2);
        $$->addr = three_ac::new_temp();
        three_ac::gen("unary", "not", $2->addr, $$->addr);
    }
    | comparison
    {
        $$ = $1;
    }
    ;

comparison : expr comp_op expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE); 
        appendChild($$, $1);
        appendChild($$, $3);

        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = bool_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", $2->lexeme, $1->addr, $3->addr, $$->addr);
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

        if(!(((type_equal($1->type,int_node)) && (type_equal($3->type,int_node))))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = int_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "|", $1->addr, $3->addr, $$->addr);
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
    
        if(!(((type_equal($1->type,int_node)) && (type_equal($3->type,int_node))))){ 
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = int_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "^", $1->addr, $3->addr, $$->addr);
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

        if(!(((type_equal($1->type,int_node)) && (type_equal($3->type,int_node))))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = int_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "&", $1->addr, $3->addr, $$->addr);
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
        
        if(!(((type_equal($1->type,int_node)) && (type_equal($3->type,int_node))))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = int_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "<<", $1->addr, $3->addr, $$->addr);
    }
    | shift_expr ">>" arith_expr
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    
        if(!(((type_equal($1->type,int_node)) && (type_equal($3->type,int_node))))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = int_node;
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", ">>", $1->addr, $3->addr, $$->addr);
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
    
        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "+", $1->addr, $3->addr, $$->addr);
    }
    | arith_expr "-" term
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    
        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
             if($1->type.t!="-1" && $3->type.t!="-1" )
            Error::type_mismatch(yylineno,$1->type,$3->type,$2->lexeme);
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "-", $1->addr, $3->addr, $$->addr);    
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

        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if ($1->type.t != "-1" && $3->type.t != "-1")
                Error::type_mismatch(yylineno,$1->type,$3->type,"*");
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "*", $1->addr, $3->addr, $$->addr);
    }
    | term "/" factor
    {   
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
    
        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if ($1->type.t != "-1" && $3->type.t != "-1")
                Error::type_mismatch(yylineno,$1->type,$3->type,"/");
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "/", $1->addr, $3->addr, $$->addr);    
    }
    | term "%" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);
        
        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if ($1->type.t != "-1" && $3->type.t != "-1")
                Error::type_mismatch(yylineno,$1->type,$3->type,"%");
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "%", $1->addr, $3->addr, $$->addr);
    }
    | term "//" factor
    {
        $$ = makeNode($2->lexeme,EXPR_TYPE);
        appendChild($$, $1);
        appendChild($$, $3);

        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if ($1->type.t != "-1" && $3->type.t != "-1")
                Error::type_mismatch(yylineno,$1->type,$3->type,"//");
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "//", $1->addr, $3->addr, $$->addr);
    }
    ;

factor : "+" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);
        
        if(!(((type_equal($2->type,int_node)||type_equal($2->type,float_node))))){
            if ($2->type.t != "-1")
                Error::invalid_unary_operation(yylineno,$2->type,"+");
        }
        $$->type = $2->type;
        three_ac::dereference($2);
        $$->addr = three_ac::new_temp();
        three_ac::gen("unary", "+", $2->addr, "", $$->addr);        
    }
    | "-" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);

        if(!(((type_equal($2->type,int_node)||type_equal($2->type,float_node))))){
            if ($2->type.t != "-1")
                Error::invalid_unary_operation(yylineno,$2->type,"-");
        }
        $$->type = $2->type;
        three_ac::dereference($2);
        $$->addr = three_ac::new_temp();
        three_ac::gen("unary", "-", $2->addr, "", $$->addr);        
    }
    | "~" factor
    {
        $$ = makeNode($1->lexeme,EXPR_TYPE);
        appendChild($$, $2);

        if(!(((type_equal($2->type,int_node))))){
            if($2->type.t!="-1")
            Error::invalid_unary_operation(yylineno,$2->type,"~");
        }        

        $$->type = int_node;
        three_ac::dereference($2);
        $$->addr = three_ac::new_temp();
        three_ac::gen("unary", "~", $2->addr, "", $$->addr);        
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
        if(!(((type_equal($1->type,int_node)||type_equal($1->type,float_node)) && (type_equal($3->type,float_node)||type_equal($3->type,int_node)) ))){
            if ($1->type.t != "-1" && $3->type.t != "-1")
                Error::type_mismatch(yylineno,$1->type,$3->type,"**");
        }
        $$->type = get_max_type($1->type,$3->type);
        three_ac::dereference($1);
        three_ac::dereference($3);
        $$->addr = three_ac::new_temp();
        three_ac::gen("quad", "**", $1->addr, $3->addr, $$->addr);
    }   
    ;

atom_expr : atom trailerlist
    {
        if ($2 == NULL){
            $$ = $1;
            if($1->addr == "not assigned"){
                $1->addr = $1->lexeme;
            }
        }else{
            $$ = makeNode("atom_expr", EXPR_TYPE);
            appendChild($$, $1);
            appendChild($$, $2);
            struct type temp = $1->type;
            
            if(is_declared_type($1->lexeme))
            for (int i = 0; i < $2->children.size(); i++){
                if ($2->node_type == TRAILER_TYPE){
                    if ($2->children[i]->lexeme == "()" && i == 0){
                        // function call
                        if ($1->node_type != NAME_TYPE){
                            Error::other_semantic_error("TYPE_ERROR: Invalid operation ()", yylineno);
                        }else{
                            string func_id = $1->lexeme;
                            for (auto x: $2->children[i]->children){
                                func_id += "@" + type_to_string(x->type);
                                
                            }
                            struct type ret = string_to_type(func_id);
                            if (ret.t == "-1"){
                                if(func_id!="main") Error::other_semantic_error("TYPE_ERROR: No declaration of function " + $1->lexeme+ " with these parameter types, called ", yylineno);
                            }else{
                                temp = ret;
                            }

                            DEBUG("Entered 3AC Function Call");
                            int stack_shift = 0;
                            symtable_func* funct = global_symtable->search_func(func_id);
                            for (auto x: $2->children[i]->children){
                                three_ac::gen("param",x->addr);
                                stack_shift += x->type.size;
                                three_ac::dereference(x);
                            }
                            three_ac::gen("stackpointer+",to_string(stack_shift));
                            three_ac::gen("call",func_id,to_string($2->children[i]->children.size()));
                            stack_shift -= ret.size;
                            three_ac::gen("stackpointer-",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            three_ac::gen("popparam","","","",temp_reg);
                            $$->addr = temp_reg;
                            DEBUG("Exited 3AC Function Call");
                            
                    }
                    }else if ($2->children[i]->lexeme == "[]"){
                        // list indexing
                        if($2->children[i]->children[0]->type.t!="-1"){ // taking care of list parameters
                            if (temp.elems != -1){
                                if (type_equal($2->children[i]->children[0]->type, int_node)){
                                    temp.elems = -1;
                                    
                                    string temp_reg = three_ac::new_temp();
                                    three_ac::gen("quad","+",$2->children[i]->children[0]->addr,$1->addr,temp_reg);
                                    $$->to_dereference = 1;
                                    $$->addr = temp_reg;


                                }else{
                                    Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string($2->children[i]->children[0]->type), yylineno);
                                }
                            }else{
                                Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                            }
                        }
                        else{
                            
                        }
                    }else if ($2->children[i]->lexeme == "."){
                        if (i + 1 < $2->children.size() && $2->children[i+1]->lexeme == "()"){
                            // method call
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
                            class_id += "." + $2->children[i]->children[0]->lexeme;
                            for (auto x: $2->children[i+1]->children){
                                class_id += "@" + type_to_string(x->type);
                            }
                            struct type ret = string_to_type(class_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No such method with given parameter types in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }

                            int stack_shift = 0;
                            symtable_class* object_class = global_symtable->search_class(class_name);
                            symtable_func* funct = object_class->search_func(class_id); 
                            symtable_entry* object_entry;
                            
                            object_entry = symtable_look_up($1->lexeme);

                            if(object_entry == NULL){
                                Error::sem_no_declaration_var($1->lexeme,yylineno);
                            }
                            
                            // three_ac("quad","+",object_entry->addr,funct->offset,) 
                            three_ac::gen("param",object_entry->addr);
                            for (auto x: $2->children[i+1]->children){
                                three_ac::gen("param",x->addr);
                                stack_shift += x->type.size;
                                three_ac::dereference(x);
                            }
                            three_ac::gen("stackpointer+",to_string(stack_shift));
                            three_ac::gen("call",class_id,to_string($2->children[i+1]->children.size()+1));
                            stack_shift -= ret.size;
                            three_ac::gen("stackpointer-",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            three_ac::gen("popparam","","","",temp_reg);
                            $$->addr = temp_reg;
                            DEBUG("Exited 3AC Function Call");
                        }
                        // else if(i+1<$2->children.size() && $2->childre[i+1]->lexeme == "[]"){
                        //     // a.b[i]


                        // }
                        
                        
                        else{
                            // attribute access
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
                            class_id += "." + $2->children[i]->children[0]->lexeme;
                            struct type ret = string_to_type(class_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No declaration of attribute " + $2->children[i]->children[0]->lexeme + " in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }


                            int stack_shift = 0;
                            symtable_class* object_class = global_symtable->search_class(class_name);
                            symtable_entry* class_attr = object_class->search_entry(class_id); 

                            class_attr = symtable_look_up($1->lexeme);
                            
                            if(class_attr == NULL){
                                Error::sem_no_declaration_var($1->lexeme,yylineno);
                            }
                            
                            string temp1 = three_ac::new_temp();
                            three_ac("lookup","",type_to_string(temp),class_id,temp1);
                            string temp2 = three_ac::new_temp();
                            three_ac("quad","+",class_attr->addr,temp1,temp2);
                            string temp3 = three_ac::new_temp();
                            three_ac("DEREF","*",temp2,"",temp3);
                        }
                    }else{
                        Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + $2->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            
            $$->type = temp;
            
        }
    }
    ;

trailerlist : trailerlist trailer
    {
        if ($1 == NULL){
            $$ = makeNode("trailer",TRAILER_TYPE);
            appendChild($$, $2);
        }else{
            $$ = $1;
            appendChild($$, $2);
        }
    }
    | /*Empty*/
    {
        $$ = NULL;
    }

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
    ;

atom : NAME
    {
        $$ = makeNode($1->lexeme,NAME_TYPE);
        $$->type = string_to_type($1->lexeme);
        //DEBUG("atom: " << $1->lexeme << ": " << $$->type.t);
    }
    | NUMBER
    {
        $$ = makeNode($1->lexeme,NUMBER_TYPE);
        int isnot_int = 0;
        for (auto c: $1->lexeme){
            if (!isdigit(c)){
                isnot_int = 1;
                break;
            }
        }
        if (isnot_int){
            $$->type.t = "float";
        }else{
            $$->type.t = "int";
        }
    }
    | STRING
    {
        $$ = makeNode($1->lexeme,STRING_TYPE);
        $$->type.t = "str";
    }
    | "None"
    {
        $$ = makeNode("void",NAME_TYPE);
        $$->type.t = "void";
    }
    | "True"
    {
        $$ = makeNode($1->lexeme,BOOLEAN_TYPE);
        $$->type.t = "bool";
    }
    | "False"
    {
        $$ = makeNode($1->lexeme,BOOLEAN_TYPE);
        $$->type.t = "bool";
    }
    | "(" test ")"
    {
        $$ = $2;
    }
    | "[" arglist "]" 
    {
        $$ = makeNode("[]", LIST_TYPE);
        $$->type.t = $2 == NULL? "void": $2->type.t;
        $$->type.elems = $2 == NULL? 0: $2->children.size();
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
        if (!type_equal($1->type,$3->type)){
            Error::type_mismatch(yylineno, $1->type, $3->type, ",");
        }else{
            $$->type = $1->type;
        }
    }
    | test
    {
        $$ = makeNode("",MISC_TYPE);
        appendChild($$, $1);
        $$->type = $1->type;
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
    int tac_file_arg = -1;
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
        }else if (arg == "-tac"){
            if (i+1 < argc){
                tac_file_arg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }
        else if (arg == "-output"){
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

    int_node.t = "int";
    float_node.t = "float";
    bool_node.t = "bool";
    str_node.t = "str";
    void_node.t = "void";

    global_symtable = new symtable_global();
    curr_symtable_global = global_symtable;
    curr_symtable_global->add_range_func();
    
    declared_types.insert("int");
    declared_types.insert("float");
    declared_types.insert("bool");
    declared_types.insert("str");
    declared_types.insert("void");
    declared_types.insert("list");
    
    yyparse();
    DEBUG("Reached before csv creation");
    curr_symtable_global->create_csv("sample.csv");
    

    if (tac_file_arg != -1){
        three_ac::export_txt(argv[tac_file_arg]);
    }else{
        three_ac::export_txt("tac.txt");
    }

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
