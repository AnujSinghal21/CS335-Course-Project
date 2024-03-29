#include "symtab.hpp"

map <string,int> size_of_type = {

};

symtable_entry :: symtable_entry(){;}

symtable_entry :: symtable_entry(string name, ll line_no, string type)
{
    this->name = name;
    this->line_no = line_no;
    this->type = type;
    this->size = size_of_type[type];
}

symtable_entry :: symtable_entry(string name, const symtable_entry &other){
    this->name = name;
    this->type = other.type;
    this->line_no = other.line_no;
    this->size = other.size;
}

void symtable_entry::update_type(string type){
    this->type = type;
    this->size = size_of_type[type];
    // if(this -> size == 0) {
    //     this -> size = address_size;       // otherwise it's a reference and hence address_size bytes
    // }
}

symtable_func::symtable_func(string func_name, const vector<symtable_entry*>& params){
       this->name = func_name;
       for(auto &param : params){
            entry_map[param->name]=param;
       }
}

void symtable_func::add_entry(symtable_entry* new_entry){
    string entryname = new_entry->name;
    if(entry_map.find(entryname)!=entry_map.end()){
        cout << "VARIABLE ALREADY DECLARED \n";
    }
    else{
        cout << "Adding entry" << endl;
        cout << "Entry name: " << new_entry->name << endl;
        entry_map[entryname]=new_entry;
    }
}

void symtable_func::delete_entry(string name){
    if(entry_map.find(name)==entry_map.end()){
        cout << "entry is not present in symbol table\n";
    }
    else entry_map.erase(name);
}

int symtable_func::get_localspace_size(){
    return 0;
}

symtable_entry* symtable_func::find_entry(string name){
    return NULL;
}