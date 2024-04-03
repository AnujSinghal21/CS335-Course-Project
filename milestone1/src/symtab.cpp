#include "symtab.hpp"

extern symtable_global* global_symtable;
extern symtable_func* curr_symtable_func;
extern symtable_class* curr_symtable_class;

struct type string_to_type(string temp){
   int is_func = 0;
   int is_class_attr = 0;
   int ind;
   string s;
   struct type t;
   for(int i=0;i<temp.size();i++){
    if(temp[i]='@'){
        is_func = 1;
        break;
    }
    else if(temp[i]=='.'){
        is_class_attr = 1;
        ind = i;
        break;
    }
    else{
        s.push_back(temp[i]);
    }
    }
    if(is_func){
        if(global_symtable->functions.find(temp)!=global_symtable->functions.end()){
            return global_symtable->functions.find(temp)->second->returntype;
        }
    }
    else if(is_class_attr){
        if (global_symtable->classes.find(s)!=global_symtable->classes.end())
        {
            symtable_class* curr_class = global_symtable->classes[s];
            if(curr_class==NULL) return t;
            string ss;
            for(int i = ind+1;i<temp.size();i++){
                ss.push_back(temp[i]);
            }
            symtable_entry* curr_ent =  curr_class->attributes[ss];
        }
    }
    else{
        if(curr_symtable_func!=NULL){
            if (curr_symtable_func->entries.find(temp)!=curr_symtable_func->entries.end()) 
            {
                symtable_entry* curr_ent = curr_symtable_func->entries[temp];
                return curr_ent->type;
            }
        }
        else{
            if (global_symtable->global_vars.find(temp)!=global_symtable->global_vars.end()) 
            {                
                symtable_entry* curr_ent = global_symtable->global_vars[temp];
                return curr_ent->type;
            }
        }
    }
    return t;
}

map <string,int> size_of_type = {
    
};

//////////SYMTABENTRY STARTS////////////
////////////////////////////////////////

symtable_entry :: symtable_entry(){;}

struct type create_string_type(TreeNode* type){
    struct type t;
    if (type == NULL){
        DEBUG("Type is NULL");
    }
    switch (type->node_type){
        case NAME_TYPE:
            t.t = type->lexeme;
            t.size = get_size(t.t);
            return t;
        case EXPR_TYPE:
            if (type->children[0]->node_type == NAME_TYPE 
                && type->children[0]->lexeme == "list"
                && type->children[1]->node_type == TRAILER_TYPE 
                && type->children[1]->children[0]->node_type == EXPR_TYPE
                && type->children[1]->children[0]->lexeme == "[]"
                && type->children[1]->children[0]->children[0]->node_type == NAME_TYPE
                ){
                t.t = type->children[1]->children[0]->children[0]->lexeme;
                t.size = get_size(t.t);
                t.elems = 0;
                return t;
            }
            else{
                DEBUG("INVALID TYPE");
                return t;
            }
        default:
            DEBUG("Type is NULL");
            return t;
    }
}

symtable_entry :: symtable_entry(TreeNode* entry, ll line_no)
{
    //DEBUG("Entered Sym Table Entry method");
    TreeNode* var_name = entry->children[0];
    TreeNode* type_name = entry->children[1];
    //DEBUG("Exited Sym Table Entry method");
    
    string temp_str = "";
    this->name = var_name->lexeme;
    //cout << var_name->lexeme << endl;
    //cout << "entry" << endl;
    this->type = create_string_type(type_name);
    this->line_no = line_no-1;
    // cout << "NEW SYMTAB ENTRY CREATED" << endl;
    // cout << "Name : " << this->name << endl;
    // cout << "Type : " << type_to_string(this->type) << endl;
    
}


symtable_entry :: symtable_entry(string name, const symtable_entry &other){
    this->name = name;
    this->type = other.type;
    this->line_no = other.line_no;
    this->size = other.size;
}

void symtable_entry::update_type(TreeNode* type){

    // this->type = create_string_type(type);
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
        funcname = funcname+ type_to_string(param.second->type);
    }
    // funcname.push_back('-');
    // funcname.push_back('>');
    // funcname = funcname + function->returntype;
    if(functions.find(funcname)!=functions.end()) {
        Error::sem_func_redeclare(function->name,function->line_no,functions[funcname]->line_no);
    }
    else functions[funcname] = function;
    function->parent_symtab = this;
    //DEBUG("function added in global symbol table" << funcname);
}

void symtable_global :: add_class(symtable_class* class_){
    string classname = class_->name;
    if(classes.find(classname)!=classes.end()) cout << "Not a valid function, already present";
    else classes[classname] = class_;
    class_->parent_symtab = this;
     //DEBUG("class added in global symbol table" << classname);
}

symtable_entry* symtable_global::add_global_var(TreeNode* global_var,ll line_no){
    symtable_entry* temp = new symtable_entry(global_var,line_no);
    string varname = temp->name;
    //DEBUG("global var added in global symbol table" << varname);
    if(this->global_vars.find(varname)!=this->global_vars.end()){
        // cout << "Not a valid variable, already present";
        Error::sem_var_redeclare(varname,line_no-1,this->global_vars[varname]->line_no);
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
    //cout<< "Class "<<name<<" not present"<<endl;
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

void symtable_global :: check_declaration_var(string name, ll line_no){
    if(global_vars.find(name)==global_vars.end()){
        Error::sem_no_declaration_var(name,line_no);
    }
}

////////// GLOBAL ENDS /////////////
////////////////////////////////////

////////// FUNCTION STARTS /////////
////////////////////////////////////

symtable_func::symtable_func (TreeNode* function, TreeNode* params, TreeNode* returntype, ll line_no){
    this->name = function->lexeme;
    this->returntype = create_string_type(returntype);
    
    for(int i =0;i<params->children.size();i++){
        //DEBUG(i);
        symtable_entry* temp = new symtable_entry(params->children[i], line_no);
        this->paramlist[temp->name] = temp;
        //DEBUG(temp->name);
        this->entries[temp->name] = temp;
    }

    this->line_no = line_no - 1;
    // cout << "NEW FUNC SYMTAB CREATED" << endl;
    // cout << "Name : " << this->name << endl;
    // cout << "Return type : " << type_to_string(this->returntype) << endl;
}

symtable_entry* symtable_func::add_entry(TreeNode* new_entry,ll line_no){
    symtable_entry* temp = new symtable_entry(new_entry, line_no);
    //DEBUG(temp);
    string entryname = temp->name;
    //DEBUG("Adding Symbol Table Entry to Function" << entryname);
    if(entries.find(entryname)!=entries.end() || paramlist.find(entryname)!=paramlist.end()){
        Error::sem_var_redeclare(entryname,line_no-1,this->entries[entryname]->line_no);
        return NULL;
    }
    else{
        // cout << "Adding entry" << endl;
        // cout << "Entry name: " << temp->name << endl;
        entries[entryname]=temp;
        return temp;
    }
   return NULL;
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

void symtable_func :: check_declaration_var(string name, ll line_no){
    if(entries.find(name)==entries.end() && paramlist.find(name)==paramlist.end()){
        Error::sem_no_declaration_var(name,line_no);
    }
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

    //DEBUG("NEW CLASS SYMTAB CREATED" << this->name);
    //cout << "Name : " << this->name << endl;
    //cout << "Return type : " << this->returntype << endl;
}

void symtable_class :: add_func(symtable_func* function){
    symtable_entry* temp = new symtable_entry();
    temp->name = "self";
    type t;
    t.t = this->name;
    temp->type = t;

    function->paramlist["self"] = temp;
    
    string funcname = this->name;
    funcname.push_back('.');
    funcname += function->name;
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+type_to_string(param.second->type);
    }
    // funcname.push_back('-');
    // funcname.push_back('>');
    // funcname = funcname + function->returntype;
    if(methods.find(funcname)!=methods.end()){
         Error::sem_func_redeclare(function->name,function->line_no,methods[funcname]->line_no);
    }
    else {
        methods[funcname] = function;
        function->parent_class = this;
        //DEBUG("function added in class symbol table" << funcname);
    }
}

symtable_entry* symtable_class::add_attribute(TreeNode* entry, ll line_no){
    symtable_entry* temp = new symtable_entry(entry, line_no);
    string varname = this->name;
    varname.push_back('.');
    varname += temp->name;
    //DEBUG("attribute added in global symbol table" << varname);
    if(attributes.find(varname)!=attributes.end()) {
        Error::sem_var_redeclare(varname,line_no-1,this->attributes[varname]->line_no);
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

//////////////////////////////////////////
/////////////// CSV STARTS ///////////////


void symtable_func::create_csv(string filename){
    ofstream out(filename, ios::app);
    out<<"Function: "<<this->name<<endl;
    
    out<<"Lexeme, Type, Token, LineNo, Size"<<endl;
    for(auto entry: this->entries){
        
        out<<entry.second->name<<", "<<type_to_string(entry.second->type)<<", "<<"NAME"<<", "<<entry.second->line_no<<", "<<entry.second->size<<endl;
    }
    out<<"\n\n\n\n\n\n";
}


void symtable_global::create_csv(string filename){
    ofstream out(filename, ios::out);
    out<<"Functions Definition"<<endl;
    for(auto func: this->functions){
        func.second->create_csv(filename);
    }
    for(auto cl : this->classes){
        out << "Class: " <<cl.first<<endl;
        for(auto method: cl.second->methods){
            method.second->create_csv(filename);
        }
    }
}

///////////////  CSV ENDS  ///////////////
//////////////////////////////////////////