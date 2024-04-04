#include "symtab.hpp"

extern symtable_global* global_symtable;
extern symtable_func* curr_symtable_func;
extern symtable_class* curr_symtable_class;
extern struct type int_node;
extern struct type float_node;
extern struct type bool_node;
extern struct type str_node;
extern struct type void_node;
extern unordered_set<string> declared_types;
extern struct type string_to_type(string temp){
   int is_func = 0;
   int is_class_attr = 0;
   int ind;
   string s;
   struct type t;
   for(int i=0;i<temp.size();i++){
    if(temp[i]=='@'){
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

            if(curr_class->attributes.find(ss)!=curr_class->attributes.end()){
                symtable_entry* curr_ent =  curr_class->attributes[ss];
                t = curr_ent->type;
            }
            else if(curr_class->methods.find(temp)!=curr_class->methods.end()){
                symtable_func* curr_ent =  curr_class->methods[temp];
                t = curr_ent->returntype;
                
            }
            
        }
    }
    else{
        if(curr_symtable_func!=NULL){
            if (curr_symtable_func->entries.find(temp)!=curr_symtable_func->entries.end()) 
            {
                symtable_entry* curr_ent = curr_symtable_func->entries[temp];
                return curr_ent->type;
            }
            else if(global_symtable->functions.find(temp)!=global_symtable->functions.end()){
                 return global_symtable->functions.find(temp)->second->returntype;
            }else if (global_symtable->global_vars.find(temp)!=global_symtable->global_vars.end()) 
            {                
                symtable_entry* curr_ent = global_symtable->global_vars[temp];
                return curr_ent->type;
            }
        }
        else{
            if (global_symtable->global_vars.find(temp)!=global_symtable->global_vars.end()) 
            {                
                symtable_entry* curr_ent = global_symtable->global_vars[temp];
                return curr_ent->type;
            }
            else if(global_symtable->functions.find(temp)!=global_symtable->functions.end()){
                 return global_symtable->functions.find(temp)->second->returntype;
            }
        }
    }
    return t;
}

 
symtable_entry* symtable_look_up(string temp){
   int is_func = 0;
   int is_class_attr = 0;
   int ind;
   string s;
   struct type t;
   symtable_entry* curr_ent = NULL;
   for(int i=0;i<temp.size();i++){
    if(temp[i]=='@'){
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
    // if(is_func){
    //     // if(global_symtable->functions.find(temp)!=global_symtable->functions.end()){
    //     //     return global_symtable->functions.find(temp)->second->returntype;
    //     // }
    //     return NULL;
    // }
    if(is_class_attr){
        if (global_symtable->classes.find(s)!=global_symtable->classes.end())
        {
            symtable_class* curr_class = global_symtable->classes[s];
            if(curr_class==NULL) return NULL;
            string ss;
            for(int i = ind+1;i<temp.size();i++){
                ss.push_back(temp[i]);
            }
            curr_ent =  curr_class->attributes[ss];
        }
    }
    else{
        if(curr_symtable_func!=NULL){
            if (curr_symtable_func->entries.find(temp)!=curr_symtable_func->entries.end()) 
            {
                symtable_entry* curr_ent = curr_symtable_func->entries[temp];

                return curr_ent;
            }
            else if (global_symtable->global_vars.find(temp)!=global_symtable->global_vars.end()) 
            {                
                symtable_entry* curr_ent = global_symtable->global_vars[temp];
                return curr_ent;
            }
        }
        else{
            if (global_symtable->global_vars.find(temp)!=global_symtable->global_vars.end()) 
            {                
                symtable_entry* curr_ent = global_symtable->global_vars[temp];
                return curr_ent;
            }
        }
    }
    return curr_ent;
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
                return t;
            }
        default:
            DEBUG("Type is NULL");
            return t;
    }
}

int type_to_size(struct type t){
    int fund_type_size = t.size;
    if(t.elems ==-1){
        return fund_type_size;
    }else{
        return 8;
    } 
    return 0;
}

symtable_entry :: symtable_entry(TreeNode* entry, ll line_no)
{
    TreeNode* var_name = entry->children[0];
    TreeNode* type_name = entry->children[1];
    
    string temp_str = "";
    this->name = var_name->lexeme;
    this->type = create_string_type(type_name);
    this->size = type_to_size(type); 
    this->line_no = line_no;
    
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

void symtable_global :: add_range_func(){
    symtable_func* func_range = new symtable_func();
    func_range->name = "range";
    symtable_entry* range_attr1 = new symtable_entry();
    range_attr1->name = "a";
    range_attr1->type = int_node;
    symtable_entry* range_attr2 = new symtable_entry();
    range_attr2->name = "b";
    range_attr2->type = int_node;
    func_range->paramlist[range_attr1->name] = range_attr1;
    func_range->paramlist[range_attr2->name] = range_attr2;
    func_range->returntype = int_node;
    string temp = func_range->name+"@int@int";
    global_symtable->functions[temp]=func_range;
    temp.clear();
    symtable_func* func_range2 = new symtable_func();
    func_range2->name = "range";
    symtable_entry* range_attr = new symtable_entry();
    range_attr->name = "n";
    range_attr->type = int_node;
    // symtable_entry* range_attr2 = new symtable_entry();
    // range_attr2->name = "b";
    // range_attr2->type = int_node;
    func_range2->paramlist[range_attr->name] = range_attr;
    func_range2->returntype = int_node;
    temp = func_range2->name+"@int";
    //func_range->paramlist[range_attr2->name] = range_attr2;
    global_symtable->functions[temp]=func_range2;

    //len_attr->type = 
}

void symtable_global:: add_len_func(string temp){
    symtable_func* func = new symtable_func();
    func->name = "len";
    symtable_entry* attr = new symtable_entry();
    struct type typ;
    typ.t = temp;
    attr->name = "a";
    attr->type = typ;
    func->paramlist[attr->name]=attr;
    string tem=func->name;
    tem+="@list";
    tem.push_back('[');
    tem+=temp;
    tem.push_back(']');
    func->returntype = int_node;
    global_symtable->functions[tem]=func;
}

void symtable_global:: add_print_func(struct type type){
    symtable_func* func = new symtable_func();
    func->name = "print";
    symtable_entry* param = new symtable_entry();
    param->type = type;
    param->name = "a";
    // struct type typ;
    // typ.t="void";
    func->returntype = void_node;
    func->paramlist[param->name]=param;
    string temp = "print";
    temp.push_back('@');
    temp+=type.t;
    global_symtable->functions[temp]=func;
}

void symtable_global :: add_func(symtable_func* function){ 
    string funcname = function->name;
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+ type_to_string(param.second->type);
    }
    if(functions.find(funcname)!=functions.end()) {
        Error::sem_func_redeclare(function->name,function->line_no,functions[funcname]->line_no);
    }
    else functions[funcname] = function;
    function->name = "global." + funcname;
    function->parent_symtab = this;
}

void symtable_global :: add_class(symtable_class* class_){
    string classname = class_->name;
    if(classes.find(classname)!=classes.end()) cout << "Not a valid function, already present";
    else classes[classname] = class_;
    class_->parent_symtab = this;
}

symtable_entry* symtable_global::add_global_var(TreeNode* global_var,ll line_no){
    symtable_entry* temp = new symtable_entry(global_var,line_no);
    string varname = temp->name;
    if(this->global_vars.find(varname)!=this->global_vars.end()){
        Error::sem_var_redeclare(varname,line_no,this->global_vars[varname]->line_no);
        return NULL;
    }
    else{
        //cout << "here at global add" << endl;
        global_vars[varname] = temp; 
        return temp;
    }
    return NULL; 
}

symtable_func* symtable_global :: search_func(string &name){
    string funcname = name;
    for(auto func : this->functions){
        if(func.first == funcname){
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

symtable_func::symtable_func(){;}

symtable_func::symtable_func (TreeNode* function, TreeNode* params, TreeNode* returntype, ll line_no){
    this->name = function->lexeme;
    this->returntype = create_string_type(returntype);
    
    for(int i =0;i<params->children.size();i++){
        symtable_entry* temp = new symtable_entry(params->children[i], line_no);
        this->paramlist[temp->name] = temp;
        this->entries[temp->name] = temp;
    }

    this->line_no = line_no - 1;
    // cout << "NEW FUNC SYMTAB CREATED" << endl;
    // cout << "Name : " << this->name << endl;
    // cout << "Return type : " << type_to_string(this->returntype) << endl;
}

symtable_entry* symtable_func::add_entry(TreeNode* new_entry,ll line_no){
    symtable_entry* temp = new symtable_entry(new_entry, line_no);
    string entryname = temp->name;
    if(entries.find(entryname)!=entries.end() || paramlist.find(entryname)!=paramlist.end()){
        Error::sem_var_redeclare(entryname,line_no,this->entries[entryname]->line_no);
        return NULL;
    }
    else{
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
    
    // if(this->parent_symtab != NULL) {
    //     return this->parent_symtab->search_global_var(name);
    // }    // can also use this, maine function me ek parent rakha tha

    if(global_symtable!=NULL){
        return global_symtable->search_global_var(name);
    }
    
    return NULL;
}

void symtable_func :: check_declaration_var(string name, ll line_no){
    if(entries.find(name)==entries.end() && paramlist.find(name)==paramlist.end()){
        Error::sem_no_declaration_var(name,line_no);
    }
}

void symtable_func::check_returntype(struct TreeNode* node, ll line_no){
    if(!((type_equal(this->returntype,float_node) || type_equal(this->returntype,bool_node)) && type_equal(node->type,int_node))){
        if(type_equal(this->returntype,node->type)==0){
            if(node->type.t == "-1"){
                Error::sem_no_declaration_var(node->lexeme,line_no);
            }
        }
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
}

void symtable_class :: add_func(symtable_func* function){
    symtable_entry* temp = new symtable_entry();
    temp->name = "self";
    type t;
    t.t = this->name;
    temp->type = t;

    string funcname = this->name;
    funcname.push_back('.');
    funcname += function->name;
    funcname.push_back('@');
    funcname+=type_to_string(temp->type);
    for(auto param : function->paramlist){
        funcname.push_back('@');
        funcname = funcname+type_to_string(param.second->type);
    }
    function->paramlist["self"] = temp;
    // funcname.push_back('-');
    // funcname.push_back('>');
    // funcname = funcname + function->returntype;
    if(methods.find(funcname)!=methods.end()){
         Error::sem_func_redeclare(function->name,function->line_no,methods[funcname]->line_no);
    }
    else {
        methods[funcname] = function;
        function->parent_class = this;
        function->name = funcname;
    }
}

symtable_entry* symtable_class::add_attribute(TreeNode* entry, ll line_no){
    symtable_entry* temp = new symtable_entry(entry, line_no);
    string varname = this->name;
    varname.push_back('.');
    varname += temp->name;
    if(attributes.find(varname)!=attributes.end()) {
        Error::sem_var_redeclare(varname,line_no,this->attributes[varname]->line_no);
        return NULL;
    }
    else {
        attributes[varname] = temp;
        return temp;
    }
    return NULL;
}

symtable_func* symtable_class:: search_func(string &name){
    // string funcname = this->name;
    // funcname.push_back('.');

    for(auto func : this->methods){
        if(func.second->name == name){
                return func.second;
        }
    }
    
    if(this->parentclass_symtab!=NULL){
        return this->parentclass_symtab->search_func(name);
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

////////// CLASS ENDS //////////////
////////////////////////////////////

//////////////////////////////////////////
/////////////// CSV STARTS ///////////////


void symtable_func::create_csv(string filename){
    ofstream out(filename, ios::app);
    if(this->name!="len"&&this->name!="range"&&this->name!="print"){
        out<<"Function: "<<this->name<<endl;
        
        out<<"Lexeme, Type, Token, LineNo, Size"<<endl;
        
        for(auto entry: this->entries){
            
            out<<entry.second->name<<", "<<type_to_string(entry.second->type)<<", "<<"NAME"<<", "<<entry.second->line_no<<", "<<entry.second->size<<endl;
        }
        out<<"\n\n\n\n\n\n";
    }
}


void symtable_global::create_csv(string filename){
    ofstream out(filename, ios::out);
    out<<"Functions Definition"<<endl;
    for(auto func: this->functions){
            ofstream out(filename, ios::app);
            if(func.second->name!="len"&&func.second->name!="range"&&func.second->name!="print"){
            out<<"Function: "<<func.second->name<<endl;
            
            out<<"Lexeme, Type, Token, LineNo, Size"<<endl;
            
            for(auto entry: func.second->entries){
                
                out<<entry.second->name<<", "<<type_to_string(entry.second->type)<<", "<<"NAME"<<", "<<entry.second->line_no<<", "<<entry.second->size<<endl;
            }
            out<<"\n\n\n";
            }
        //func.second->create_csv(filename);
    }

    for(auto cl : this->classes){
        out << "Class: " <<cl.first<<endl;
        for(auto method: cl.second->methods){
           ofstream out(filename, ios::app);
            if(method.second->name!="len"&& method.second->name!="range"&& method.second->name!="print"){
            out<<"Function: "<<method.second->name<<endl;
            
            out<<"Lexeme, Type, Token, LineNo, Size"<<endl;
            
            for(auto entry: method.second->entries){
                
                out<<entry.second->name<<", "<<type_to_string(entry.second->type)<<", "<<"NAME"<<", "<<entry.second->line_no<<", "<<entry.second->size<<endl;
            }
            out<<"\n\n\n";
            }
        }
    }
}


/* void symtable_global::create_csv(string filename){
        ofstream out(filename, ios::app);
        out << "PRINTING GLOBAL VARIABLES" << endl;
        out<<"Lexeme, Type, Token, LineNo, Size"<<endl;
        for(auto var : this->global_vars){
            out << var.second->name << ", " << type_to_string(var.second->type) << ", " << "NAME" << ", " << var.second->line_no << 
        }

}*/ 
///////////////  CSV ENDS  ///////////////
//////////////////////////////////////////
