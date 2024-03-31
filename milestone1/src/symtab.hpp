#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

class symtable_func;
class symtable_class;

class symtable_entry {
    public:
        string name;
        string type;
        ll line_no;
        ll size;
        bool is_init;
        ll init_val;
        ll offset = 0; // no idea
        ll dims = 0; // for multidim array 
        
        symtable_entry();
        symtable_entry(string name, ll line_no, string type);
        symtable_entry(string name, const symtable_entry& other); // may be for a=b type
        void update_type(string type);
};
class symtable_global{
    public:
        map<string,symtable_func*> functions;
        map<string,symtable_class*> classes;
        map<string,symtable_entry*> global_vars;
        symtable_global();
        void add_func(symtable_func* function);
        void add_class(symtable_class* class_);
        void add_global_var(symtable_entry* global_var);
        symtable_func* search_func(string &name, vector<string> &params);
        symtable_class* search_class(string &name);
        symtable_entry* search_global_var(string &name);
        void delete_func(string name);
        void delete_class(string name);
        void delete_global_var(string name);
        void print();
        void print_func(string name);
        void print_class(string name);
        void print_global_var(string name);
        void print_all();
};

class symtable_func {
    public :
        map <string,symtable_entry*> entries;
        map <string,symtable_entry*> paramlist;
        string name;
        //string returntype;
        symtable_global* parent_symtab = NULL;
        symtable_func(string func_name, const vector<symtable_entry*>& params);
        void add_entry(symtable_entry* new_entry);
        void delete_entry(string name);
        int get_localspace_size();
        symtable_entry* find_entry(string name);
        // void update_modifiers(const vector<symtable_entry*>& modifiers); ( any one any idea about this function)  
};


class symtable_class {
    public: 
        string name;
        map<string,symtable_func*> methods;
        map<string,symtable_entry*> attributes;
        //int size;
        symtable_global* parent_symtab = NULL;
        symtable_class(string class_name);
        void add_func(symtable_func* function);
        // void add_attribute
        symtable_func* search_func(string &name, vector<string> &params);

};


#endif