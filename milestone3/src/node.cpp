#include "includes.hpp"
extern int curr_id;
extern int yylineno;
extern symtable_func* curr_symtable_func;
extern symtable_global* curr_symtable_global;
extern symtable_class* curr_symtable_class;
extern map<string, string> id_to_label;
extern map<string, vector<string> > edges;

struct TreeNode * makeNode(string lexeme, int node_type = -1){
    struct TreeNode * node = new (struct TreeNode);
    node->id = "N" + to_string(curr_id++);
    node->lexeme = lexeme;
    node->node_type = node_type;
    return node;
}

void appendChild(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.push_back(child);
    return;
}

void insert_to_front(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.insert(parent->children.begin(), child);
    return;
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
            // else if(curr_symtable_class!=NULL){
            //     string ss = curr_symtable_class->name;
            //     ss.push_back('.');
            //     ss+=child->lexeme;
            //     DEBUG(ss);
            //     if(curr_symtable_class->search_entry(ss)==NULL){
            //         cout << "variable " << child->lexeme << " is not declared before use" << endl;
            //         Error::clean_up();
            //     }
                
            // }
            else{
                curr_symtable_global->check_declaration_var(child->lexeme,yylineno);
            } 
        }
        checker_traverse(child);
    }
    return;
}

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
