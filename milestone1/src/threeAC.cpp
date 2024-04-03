#include "threeAC.hpp"

int three_ac::temp_counter = 0;
int three_ac::label_counter = 0;
vector<three_ac*> three_ac::threeAC;
stack<int> three_ac::label_stack;

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
    out << op << " " << arg1 << " " << arg2 << " " << result << " // " << comment << " " << optype << endl;
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
    label_counter+= 10;
    return "@Label_" + to_string(label_counter);
}

string three_ac::push_new_label(){
    string s = new_label();
    label_stack.push(label_counter);
    return s;
}

string three_ac::pop_label(){
    if (label_stack.empty()){
        return "";
    }
    label_counter = label_stack.top();
    label_stack.pop();
    return "@Label_" + to_string(label_counter);
}

void three_ac::dereference(struct TreeNode * node){
    if (node->to_dereference == 1){
        string temp = three_ac::new_temp();
        three_ac::gen("DEREF", "*", node->addr, "", temp);
        node->addr = temp;
    }
    return;
}