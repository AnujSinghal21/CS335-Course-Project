#include "includes.hpp"
extern struct type int_node;
extern struct type float_node;
extern struct type bool_node;
extern struct type str_node;
extern struct type void_node;
extern unordered_set<string> declared_types;

struct type infer_type(struct type op1, struct type op2){
    struct type res;
    return res;
}

int get_size(string type){
    if (type == "int"){
        return 4;
    }
    else if(type=="str"){
        return 8;
    } 
    else if (type == "float"){
        return 4;
    }
    else if (type == "char"){
        return 1;
    }
    else if (type == "bool"){
        return 1;
    }
    else if (type == "void"){
        return 0;
    }
    return 0;
}

string type_to_string(struct type t){
    if (t.elems == -1){
        return t.t;
    }
    else{
        return "list[" + t.t + "]";
    }
    return "";
}

int type_equal(struct type t1, struct type t2){
    if (t1.t == t2.t && !((t1.elems==-1)^(t2.elems== -1))){
        return 1;
    }
    return 0;
}

int is_declared_type(string t){
    return declared_types.find(t) != declared_types.end();
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