#include "threeAC.hpp"

int three_ac::temp_counter = 0;
int three_ac::label_counter = 0;
vector<three_ac*> three_ac::threeAC;
vector<int> three_ac::label_stack;

three_ac::three_ac(){
    op = "";
    arg1 = "";
    arg2 = "";
    result = "";
    optype = "";
    comment = "";
}

three_ac::three_ac(string optype, string op, string arg1, string arg2, string result, string comment){
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->result = result;
    this->optype = optype;
    this->comment = comment;
}

void three_ac::print(ofstream & out){
    if (this->optype == "symtable_get"){
        out << "\t" << this->result << " = " << this->optype << "(" << this->arg1 << ")";
    }else if (this->optype == "assign"){
        out << "\t" << this->result << " = " << this->arg1;
    }else if (this->optype == "address_assign"){
        out << "\t" << "*(" << this->result << ")" << " = " << this->arg1;
    }else if (this->optype == "DEREF"){
        out << "\t" << this->result << " = " << this->op << "(" << this->arg1 << ")";
    }else if (this->optype == "quad"){
        out << "\t" << this->result << " = " << this->arg1 << " " << this->op << " " << this->arg2 ;
    }else if (this->optype == "return"){
        out << "\t" << "return " << this->arg1;
    }else if (this->optype == "beginfunc"){
        out << "\t" << "beginfunc " << this->arg1;
    }else if (this->optype == "endfunc"){
        out << "\t" << "endfunc " << this->result;
    }else if (this->optype == "unary"){
        out << "\t" << this->result << " = " << this->op << this->arg1;
    }else if (this->optype == "param"){
        out << "\t" << "param " << this->op;
    }else if (this->optype == "call"){
        out << "\t" << "call " << this->op << " " << this->arg1;
    }else if (this->optype == "if_goto"){
        out << "\t" << this->op << " " << this->arg1 << " goto " << this->arg2;
    }else if (this->optype == "goto"){
        out << "\t" << this->op << " " << this->arg1;
    }else if (this->optype == "label"){
        out << this->op << ":" << this->arg1;
    }
    else{
        out << "\t" << this->optype << " " << this->op << " " << this->arg1 << " " << this->arg2 << " " << this->result;
    }

    // shiftpointer remaining, call remaining
    if (this->comment != ""){
        out << " \t # " << this->comment;
    }
    out << endl;
}

three_ac * three_ac::gen(string optype, string op, string arg1, string arg2, string result, string comment){
    three_ac * t = new three_ac(optype, op, arg1, arg2, result, comment);
    DEBUG("Generated 3AC: " << optype << " " << op << " " << arg1 << " " << arg2 << " " << result << " " << comment);
    threeAC.push_back(t);
    return t;
}

three_ac * three_ac::append(three_ac * t){
    threeAC.push_back(t);
    return t;
}

void three_ac::export_txt(string filename){
    ofstream out;
    out.open(filename);
    for (auto tac: threeAC){
        tac->print(out);
    }
    DEBUG("Exported 3AC to " << filename);
    out.close();
}

string three_ac::new_temp(){
    return "#t_" + to_string(temp_counter++);
}

string three_ac::new_label(){
    label_counter+= 1;
    return "@Label_" + to_string(label_counter);
}

string three_ac::push_new_label(string s){
    // string s = new_label();
    int nl = 10*(label_counter++);
    if (s == "if"){
        nl += 1;
    }else if (s == "while"){
        nl += 2;
    }else if (s == "for"){
        nl += 3;
    }
    label_stack.push_back(nl);
    return get_label("");
}

int three_ac::top_label(){
    if (label_stack.size() == 0){
        return -1;
    }
    return label_stack[label_stack.size()-1];
}

string three_ac::get_label(string command, int label){
    if (label == -1){
        label = three_ac::top_label();
    }
    if (command == "else_start"){
        return "@Label_" + to_string(label) + "_else_start";
    }else if (command == "if_end"){
        return "@Label_" + to_string(label) + "_if_end";
    }else{
        return "@Label_" + to_string(label);
    }

    return "@Label_" + to_string(label);
}

string three_ac::pop_label(){
    if (label_stack.size() == 0){
        return "";
    }
    label_counter = label_stack[label_stack.size()-1];
    label_stack.pop_back();
    return "@Label_" + to_string(label_counter);
}

string three_ac::dereference(struct TreeNode * node){
    if (node->to_dereference == 1){
        string temp = three_ac::new_temp();
        three_ac::gen("DEREF", "*", node->addr, "", temp);
        return temp;
    }
    return node->addr;
}