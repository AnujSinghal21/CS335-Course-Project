#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <bits/stdc++.h>
#include "globals.hpp"
using namespace std;

class symtable_func;
class symtable_class;

typedef long long ll;

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
        
        ll offset = 0; // no idea
        //ll dims = 0; // for multidim array 
        
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
        // void update_modifiers(const vector<symtable_entry*>& modifiers); ( any one any idea about this function)  
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

#endif