#ifndef INCLUDES
#define INCLUDES

/* STL */ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Helper */
#define DEBUG(msg) \
    std::cerr << "Debug [" << __FILE__ << ":" << __LINE__ << "]: " << msg << std::endl;

/* variable types */
struct type{
    string t = "-1";
    int size = 8;
    int elems = -1;
};

int get_size(string type);
string type_to_string(struct type t);
struct type infer_type(struct type t1, struct type t2);
int type_equal(struct type t1, struct type t2);
int is_declared_type(string t);
struct type get_max_type(struct type t1, struct type t2);

/* Tree Node */
struct TreeNode{
    string lexeme = "";
    string id;
    struct type type;
    string addr = "NOT_ASSIGNED";
    int to_dereference = 0;
    int node_type = -1;
    vector<struct TreeNode*> children;
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

struct TreeNode * makeNode(string lexeme, int node_type);
void appendChild(struct TreeNode* parent, struct TreeNode* child);
void insert_to_front(struct TreeNode* parent, struct TreeNode* child);
void checker_traverse(struct TreeNode* node);
void printAST(char * filename);

/* Errors */
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
        static void use_before_declaration(string name, long long line_no);
        static void member_not_found(string name, string member, long long line_no);
};
int yyerror(const char * msg);

/* Symbol Tables */
class symtable_func;
class symtable_class;

class symtable_entry {
    public:
        string name;
        struct type type;
        ll line_no;
        ll size;
        ll list_size = -1;
        bool is_init;
        string addr = "NOT ASSIGNED";
        ll init_val;
        ll offset = 0;         
        symtable_entry();
        symtable_entry(struct TreeNode* entry, ll line_no);
        symtable_entry(string name, const symtable_entry& other); // may be for a=b type
        void create_csv(string temp);
        void update_type(TreeNode* type);
};

class symtable_global{
    public:
        map<string,symtable_func*> functions;
        map<string,symtable_class*> classes;
        map<string,symtable_entry*> global_vars;
        symtable_global();
        void add_range_func();
        void add_len_func(string temp);
        void add_print_func(struct type type);
        void add_func(symtable_func* function);
        void add_class(symtable_class* class_);
        symtable_entry* add_global_var(struct TreeNode* global_var, ll line_no);
        symtable_func* search_func(string &name);
        symtable_class* search_class(string &name);
        symtable_entry* search_global_var(string &name);
        void check_declaration_var(string name, ll line_no);
        void delete_func(string name);
        void delete_class(string name);
        void delete_global_var(string name);
        void print();
        void print_func(string name);
        void print_class(string name);
        void print_global_var(string name);
        void print_all();
        void create_csv(string filename);
};

class symtable_func {
    public :
        map <string,symtable_entry*> entries;
        map <string,symtable_entry*> paramlist;
        string name;
        struct type returntype;
        ll line_no;
        symtable_global* parent_symtab = NULL;
        symtable_class* parent_class = NULL;
        symtable_func();
        symtable_func(struct TreeNode* function,struct TreeNode* params,struct TreeNode* returntype, ll line_no);
        symtable_entry * add_entry(struct TreeNode* new_entry, ll line_no);
        void check_declaration_var(string name, ll line_no);
        void check_returntype(struct TreeNode* node, ll line_no);
        void delete_entry(string name);
        int get_localspace_size();
        symtable_entry* find_entry(string name);
        void create_csv(string filename);
};

class symtable_class {
    public: 
        string name;
        map<string,symtable_func*> methods;
        map<string,symtable_entry*> attributes;
        int size;
        symtable_global* parent_symtab = NULL;
        symtable_class* parentclass_symtab = NULL;
        symtable_class(struct TreeNode* class_,struct TreeNode* parentclass);
        void add_func(symtable_func* function);
        symtable_entry*  add_attribute(struct TreeNode* entry, ll line_no);
        symtable_func* search_func(string &name);
        symtable_entry* search_entry(string &name);
        void create_csv(string filename);
};

struct type string_to_type(string temp); 
symtable_entry* symtable_look_up(string temp);
struct type create_string_type(TreeNode* type);

/* 3AC */
class three_ac{
    public:
        string op;
        string arg1;
        string arg2;
        string result;
        string optype;
        string comment;
        three_ac();
        three_ac(string optype, string op = "", string arg1 = "", string arg2 = "", string result = "", string comment = "");
        void print(ofstream & out);
        static vector<three_ac*> threeAC;
        static int temp_counter;
        static int label_counter;
        static vector<int> label_stack;
        static three_ac * gen(string optype, string op = "", string arg1 = "", string arg2 = "", string result = "", string comment = "");
        static three_ac * append(three_ac * t);
        static void export_txt(string filename);
        static string new_temp();
        static string new_label();
        static string push_new_label(string s);
        static int top_label();
        static string get_label(string command, int label = -1);
        static string pop_label();
        static string dereference(struct TreeNode * node);
        static void threeac_relabel();
};

/* x86 */
class instruction{
    public:
    instruction();
    instruction(string arg1, string arg2="", string arg3="", string op="", string ins_t="", string comment="");
    string arg1 = "";
    string arg2 = "";
    string arg3 = "";
    string op = "";
    string code = "";
    string ins_t = "";
    string comment = "";
    void print(ofstream & out);
};

class x86_generator{
    public: 
    static vector<instruction*> data_segment;
    static vector<instruction*> text_segment;
    static void generate_code(vector<three_ac*> & threeAC);
    static void export_asm(string filename);
};

#endif