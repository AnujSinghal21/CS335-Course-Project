#include "symtab.hpp"

map <string,int> size_of_type = {

};

symtable_global* global_symtable = new symtable_global();

//////////SYMTABENTRY STARTS////////////
////////////////////////////////////////


symtable_entry :: symtable_entry(){;}

symtable_entry :: symtable_entry(TreeNode* entry, ll line_no)
{
    this->line_no = line_no;
    TreeNode* var_name = entry->children[0];
    TreeNode* type_name = entry->children[1];
    this->name = var_name->lexeme;
    // if(entry->children.size()==3){
    //     this->init_val = 
    // }
    
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

//////////SYMTABENTRY ENDS//////////////
////////////////////////////////////////



////////// GLOBAL STARTS ///////////
////////////////////////////////////
symtable_global :: symtable_global() {;}

void symtable_global :: add_func(symtable_func* function){ 
    string funcname = function->name;
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+param.second->type;
    }
    if(functions.find(funcname)!=functions.end()) cout << "Not a valid function, already present";
    else functions[funcname] = function;
    function->parent_symtab = this;
}

void symtable_global :: add_class(symtable_class* class_){
    string classname = class_->name;
    if(classes.find(classname)!=classes.end()) cout << "Not a valid function, already present";
    else classes[classname] = class_;
    class_->parent_symtab = this;
}

void symtable_global :: add_global_var(TreeNode* global_var, ll line_no){
    symtable_entry* temp = new symtable_entry(global_var, line_no);
    string varname = temp->name;
    if(global_vars.find(varname)!=global_vars.end()) cout << "Not a valid variable, already present";
    else global_vars[varname] = temp;
}

symtable_func* symtable_global :: search_func(string &name, vector<string> &types){
    string funcname = name;
    for(auto type : types){
        funcname.push_back('@');
        funcname = funcname + type;
    }
    for(auto func : this->functions){
        if(func.second->name == funcname){
                return func.second;
        }
    }
    return NULL;
}

symtable_class* symtable_global :: search_class(string &name){
    for(auto class: this->classes){
        if(class.first == name){
            return class.second;
        }
    }
    cout<< "Class "<<name<<" not present"<<endl;
    return NULL;
}

symtable_entry* symtable_global :: search_global_var(string &name){
    for(auto var : this->global_vars){
        if(var.second->name == name){
            return var.second;
        }
    }

    return NULL;
}


////////// GLOBAL ENDS /////////////
////////////////////////////////////



////////// FUNCTION STARTS /////////
////////////////////////////////////

symtable_func::symtable_func (TreeNode* function, TreeNode* params, TreeNode* returntype, ll line_no){
    this->name = function->lexeme;
    this->returntype = returntype->lexeme;
    for(int i =0;i<params->children.size();i++){
        symtable_entry* temp = new symtable_entry(params->children[i], line_no);
        this->paramlist[temp->name] = temp;
    }
}

void symtable_func::add_entry(TreeNode* new_entry,ll line_no){
    symtable_entry* temp = new symtable_entry(new_entry, line_no);
    string entryname = temp->name;
    if(entries.find(entryname)!=entries.end() || paramlist.find(entryname)!=paramlist.end()){
        cout << "ALREADY DECLARED \n";
    }
    else{
        cout << "Adding entry" << endl;
        cout << "Entry name: " << temp->name << endl;
        entries[entryname]=temp;
    }
}

void symtable_func::delete_entry(string name){
    if(entries.find(name)==entries.end()){
        cout << "entry is not present in symbol table\n";
    }
    else entries.erase(name);
}

int symtable_func::get_localspace_size(){
    int space = 0;
    for(auto entry : this->entries) {
        space += entry.second -> size;
    }
    return space;
    //return 0;
}

symtable_entry* symtable_func::find_entry(string name){
    for(auto param : this->paramlist) {
        if(param.second -> name == name) {
            return param.second;
        }
    }

    for(auto entry : this->entries) {
        if(entry.second -> name == name) {
            return entry.second;
        }
    }
    
    if(this->parent_symtab != NULL) {
        return this->parent_symtab->search_global_var(name);
    }
    return NULL;
}


////////// FUNCTION ENDS ///////////
////////////////////////////////////

////////// CLASS STARTS ////////////
////////////////////////////////////
symtable_class::symtable_class(TreeNode* class_, TreeNode* parentclass){    
    this->name = class_->lexeme;
    symtable_class parent_class = NULL;
    if(parentclass!=NULL){
        string parentclassname = parentclass->lexeme;
        parent_class = global_symtable->search_class(parentclassname);
    }
    this->parentclass_symtab = parent_class;
}

void symtable_class :: add_func(symtable_func* function){
    string funcname = function->name;
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+param.second->type;
    }
    if(methods.find(funcname)!=methods.end()) cout << "Not a valid function, already present";
    else methods[funcname] = function;
    function->parent_class = this;
}

//// abhi i am assuming ki i am getting symtab of that function, may be i am wrong

void symtable_class::add_attribute(TreeNode* entry, ll line_no){
    symtable_entry* temp = new symtable_entry(entry, line_no);
    string varname = temp->name;
    if(attributes.find(varname)!=attributes.end()) cout << "Not a valid variable, already present";
    else attributes[varname] = temp;
}

symtable_func* symtable_class:: search_func(string &name, vector<string> &types){
    // string funcname = this->name;
    // funcname.push_back('.');
    string funcname = name;
    for(auto type : types){
        funcname.push_back('@');
        funcname = funcname + type;
    }
    for(auto func : this->methods){
        if(func.second->name == funcname){
                return func.second;
        }
    }
    
    if(this->parentclass_symtab!=NULL){
        return this->parentclass_symtab->search_func(name,types);
    }

    return NULL;
}

symtable_entry* symtable_class::search_entry(string &name){
    for(auto var : this->attributes){
        if(var.second->name == name){
            return var.second;
        }
    }

    if(this->parentclass_symtab != NULL){
        return this->parentclass_symtab->search-entry(name);
    }

    return NULL;
}

////////// CLASS ENDS //////////////
////////////////////////////////////