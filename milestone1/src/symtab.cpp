#include "symtab.hpp"

extern symtable_global* global_symtable;
map <string,int> size_of_type = {
    
};

//////////SYMTABENTRY STARTS////////////
////////////////////////////////////////

symtable_entry :: symtable_entry(){;}

string create_string_type(TreeNode* type){
    if (type == NULL){
        DEBUG("Type is NULL");
    }
    switch (type->node_type){
        case NAME_TYPE:
            return type->lexeme;
        case EXPR_TYPE:
            if (type->children[0]->node_type == NAME_TYPE 
                && type->children[0]->lexeme == "list"
                && type->children[1]->node_type == TRAILER_TYPE 
                && type->children[1]->children[0]->node_type == EXPR_TYPE
                && type->children[1]->children[0]->lexeme == "[]"
                && type->children[1]->children[0]->children[0]->node_type == NAME_TYPE
                ){
                return "list[" + type->children[1]->children[0]->children[0]->lexeme + "]";
            }
            else{
                DEBUG("INVALID TYPE");
                return "";
            }
        default:
            DEBUG("Type is NULL");
            return "";
    }
}

symtable_entry :: symtable_entry(TreeNode* entry, ll line_no)
{
    // this->line_no = line_no;
    // TreeNode* type_name = type;
    // TreeNode* var_name = entry->children[0];
    // string temp_str = "";
    // this->type = create_string_type(type,temp_str);
    // this->name = var_name->lexeme;
    // this->name = name;
    // this->line_no = line_no;
    // this->type = type;
    // this->size = size_of_type[type];
    DEBUG("Entered Sym Table Entry method");
    TreeNode* var_name = entry->children[0];
    TreeNode* type_name = entry->children[1];
    DEBUG("Exited Sym Table Entry method");
    
    string temp_str = "";
    this->name = var_name->lexeme;
    //cout << var_name->lexeme << endl;
    //cout << "entry" << endl;
    this->type = create_string_type(type_name);
    
    cout << "NEW SYMTAB ENTRY CREATED" << endl;
    cout << "Name : " << this->name << endl;
    cout << "Type : " << this->type << endl;
    
}


symtable_entry :: symtable_entry(string name, const symtable_entry &other){
    this->name = name;
    this->type = other.type;
    this->line_no = other.line_no;
    this->size = other.size;
}

void symtable_entry::update_type(TreeNode* type){

    this->type = create_string_type(type);
    // this->size = size_of_type[type];
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
    funcname.push_back('-');
    funcname.push_back('>');
    funcname = funcname + function->returntype;
    if(functions.find(funcname)!=functions.end()) cout << "Not a valid function, already present";
    else functions[funcname] = function;
    function->parent_symtab = this;
    DEBUG("function added in global symbol table" << funcname);
}

void symtable_global :: add_class(symtable_class* class_){
    string classname = class_->name;
    if(classes.find(classname)!=classes.end()) cout << "Not a valid function, already present";
    else classes[classname] = class_;
    class_->parent_symtab = this;
     DEBUG("class added in global symbol table" << classname);
}

symtable_entry* symtable_global::add_global_var(TreeNode* global_var,ll line_no){
    symtable_entry* temp = new symtable_entry(global_var,line_no);
    //cout<<"here"<<endl;
    string varname = temp->name;
    //cout << varname << endl;
    DEBUG("global var added in global symbol table" << varname);
    if(this->global_vars.find(varname)!=this->global_vars.end()){
        cout << "Not a valid variable, already present";
        return NULL;
    }
    else{
        //cout << "here at global add" << endl;
        global_vars[varname] = temp; 
        return temp;
    }
    return NULL; 
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
    for(auto c: this->classes){
        if(c.first == name){
            return c.second;
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
    this->returntype = create_string_type(returntype);
    
    for(int i =0;i<params->children.size();i++){
        DEBUG(i);
        symtable_entry* temp = new symtable_entry(params->children[i], line_no);
        this->paramlist[temp->name] = temp;
        DEBUG(temp->name);
    }

    cout << "NEW FUNC SYMTAB CREATED" << endl;
    cout << "Name : " << this->name << endl;
    cout << "Return type : " << this->returntype << endl;
}

symtable_entry* symtable_func::add_entry(TreeNode* new_entry,ll line_no){
    symtable_entry* temp = new symtable_entry(new_entry, line_no);
    DEBUG(temp);
    string entryname = temp->name;
    DEBUG("Adding Symbol Table Entry to Function" << entryname);
    if(entries.find(entryname)!=entries.end() || paramlist.find(entryname)!=paramlist.end()){
        cout << "ALREADY DECLARED \n";
    }
    else{
        cout << "Adding entry" << endl;
        cout << "Entry name: " << temp->name << endl;
        entries[entryname]=temp;
    }
    return temp;
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
    symtable_class* parent_class = NULL;
    if(parentclass!=NULL){
        string parentclassname = parentclass->lexeme;
        parent_class = global_symtable->search_class(parentclassname);
    }
    this->parentclass_symtab = parent_class;

    DEBUG("NEW CLASS SYMTAB CREATED" << this->name);
    //cout << "Name : " << this->name << endl;
    //cout << "Return type : " << this->returntype << endl;
}

void symtable_class :: add_func(symtable_func* function){
    symtable_entry* temp = new symtable_entry();
    temp->name = "self";
    temp->type = this->name;

    function->paramlist["self"] = temp;
    
    string funcname = function->name;
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+param.second->type;
    }
    funcname.push_back('-');
    funcname.push_back('>');
    funcname = funcname + function->returntype;
    if(methods.find(funcname)!=methods.end()) cout << "Not a valid function, already present";
    else methods[funcname] = function;
    function->parent_class = this;
    DEBUG("function added in class symbol table" << funcname);
}

//// abhi i am assuming ki i am getting symtab of that function, may be i am wrong

symtable_entry* symtable_class::add_attribute(TreeNode* entry, ll line_no){
    symtable_entry* temp = new symtable_entry(entry, line_no);
    string varname = temp->name;
    DEBUG("attribute added in global symbol table" << varname);
    if(attributes.find(varname)!=attributes.end()) {
        cout << "Not a valid variable, already present";
        return NULL;
    }
    else {
        attributes[varname] = temp;
        return temp;
    }
     return NULL;
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
        return this->parentclass_symtab->search_entry(name);
    }

    return NULL;
}

////////// CLASS ENDS //////////////
////////////////////////////////////