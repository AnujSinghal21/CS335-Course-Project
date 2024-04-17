#include "includes.hpp"

map<string, int> offsets; 
vector<instruction*> x86_generator::text_segment;
vector<instruction *> x86_generator::data_segment;
extern string asm_lib_file;

map<string, string> func_names; 
int comp_labels = 0;
int string_constants = 0;
instruction::instruction(){

}

instruction::instruction(string arg1, string arg2, string arg3, string op, string ins_t, string comment){
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->arg3 = arg3;
    this->op = op;
    this->ins_t = ins_t;
    this->comment = comment;
}

void instruction::print(ofstream & out){
    if (this->comment == "Unused"){
        return;
    }
    if (this->ins_t == "oaa"){
        out << "\t" << this->op << " " << this->arg1 << ", " << this->arg2;
    }else if (this->ins_t == "oa"){
        out << "\t" << this->op << " " << this->arg1;
    }else if (this->ins_t == "o"){
        out << "\t" << this->op;
    }else if (this->ins_t == "l"){
        out << this->arg1 << ": ";
    }else if (this->ins_t == "ds"){
        out << this->arg1 << ": " << this->arg2 << " " << this->arg3;
    }
    out << endl;
    return;
}

void x86_generator::export_asm(string filename){
    ofstream out;
    out.open(filename);
    out << ".data" << endl;
    for (auto ins : x86_generator::data_segment){
        ins->print(out);
    }
    out << ".globl main" << endl;
    out << ".text" << endl;
    for (auto ins : x86_generator::text_segment){
        ins->print(out);
    }
    ifstream lib(asm_lib_file);
    string line;
    while (getline(lib, line)){
        out << line << endl;
    }
    out << endl;
    lib.close();
    out.close();
    return;

}
string make_simple_string(string s){
    if (s[0] == '\''){
        s[0] = '"';
        s[s.size()-1] = '"';
    }
    string s2 = "";
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '\n'){
            s2 += "\\n";
        }else{
            s2.push_back(s[i]);
        }
    }
    return s2;
}
string get_value(string arg){
    if (arg == ""){
        return "$0";
    }else if (arg == "#returnval"){
        return "%rax";
    }else if (offsets.find(arg) != offsets.end()){
        return to_string(offsets[arg]) + "(%rbp)";
    }else if (arg == "True"){
        return "$1";
    }else if (arg == "False"){
        return "$0";
    }else if (arg[0] == '['){
        return "$0";
    }else if (arg[0] == '"' || arg[0] == '\''){
        string nm = "str_const_"+to_string(++string_constants);
        instruction * ins = new instruction(nm, ".asciz", make_simple_string(arg), "", "ds", "");
        x86_generator::data_segment.push_back(ins);
        instruction * ins2 = new instruction(nm + "(%rip)", "%r8", "", "lea", "oaa", "");
        x86_generator::text_segment.push_back(ins2);
        return "%r8";
    }else{
        return "$" + arg;
    }
}

instruction * gen_instruction(three_ac * t){    
    if (t->optype == "assign"){
        if (t->arg1 != "#popparam"){
            instruction * ins = new instruction();
            ins->op = "movq";
            ins->arg1 = get_value(t->arg1);
            ins->arg2 = "%rbx";
            ins->ins_t = "oaa";
            x86_generator::text_segment.push_back(ins);
            instruction * ins2 = new instruction();
            ins2->op = "movq";
            ins2->arg1 = "%rbx";
            ins2->arg2 = get_value(t->result);
            ins2->ins_t = "oaa";
            x86_generator::text_segment.push_back(ins2);
        }
    }else if (t->optype == "quad"){
        /* Arithmetic operations */
        if (t->op == "+"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "addq", "oaa", "");    
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);            
        }
        else if (t->op == "-"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "subq", "oaa", "");
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);    
        }else if (t->op == "*"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "imulq", "oaa", "");
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }else if (t->op == "/" || t->op == "//"){
            instruction * ins = new instruction(get_value(t->arg1), "%rax", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rbx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("", "", "", "cqo", "o", "");
            instruction * ins4 = new instruction("%rbx", "", "", "idivq", "oa", "");
            instruction * ins5 = new instruction("%rax", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
        }else if (t->op == "%"){
            instruction * ins = new instruction(get_value(t->arg1), "%rax", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rbx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("", "", "", "cqo", "o", "");
            instruction * ins4 = new instruction("%rbx", "", "", "idivq", "oa", "");
            instruction * ins5 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
        }else if (t->op == "**"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "", "", "pushq", "oa", "");
            instruction * ins4 = new instruction("%rbx", "", "", "pushq", "oa", "");
            instruction * ins5 = new instruction("power", "", "", "call", "oa", "");
            instruction * ins6 = new instruction("$16", "%rsp", "", "addq", "oaa", "");
            instruction * ins7 = new instruction("%rax", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
            x86_generator::text_segment.push_back(ins7);
        }
        /* Bitwise and boolean operations */
        else if (t->op == "&" || t->op == "and"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "andq", "oaa", "");
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }else if (t->op == "|" || t->op == "or"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "orq", "oaa", "");
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }else if (t->op == "^"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "xorq", "oaa", "");
            instruction * ins4 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }else if (t->op == "<<"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%cl", "", "", "movb", "oa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "shlq", "oaa", "");
            instruction * ins5 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
        }else if (t->op == ">>"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%cl", "", "", "movb", "oa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "sarq", "oaa", "");
            instruction * ins5 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
        }
        /* Comparison operations */
        else if (t->op == "<"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "setl", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == ">"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "setg", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == "<="){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "setle", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == ">="){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "setge", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == "=="){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "sete", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == "!=" || t->op == "<>"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction(get_value(t->arg2), "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("$0", "%rdx", "", "movq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins5 = new instruction("%dl", "", "", "setne", "oa", "");
            instruction * ins6 = new instruction("%rdx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);    
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
            x86_generator::text_segment.push_back(ins6);
        }else if (t->op == "" && t->arg1 == "#space"){
            //DEBUG("Space");
            instruction * ins = new instruction("%rbp", "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction("$" + t->arg2, "%rbx", "", "addq", "oaa", "");
            instruction * ins3 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            int sz = offsets[t->result] - atoi((t->arg2).c_str());
            instruction * ins4 = new instruction("$" + to_string(sz), "-8(%rbx)", "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }
    }else if (t->optype == "unary"){
        if (t->op == "-"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction("$0", "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rbx", "%rcx", "", "subq", "oaa", "");
            instruction * ins4 = new instruction("%rcx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
        }else if (t->op == "+"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
        }else if (t->op == "not"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction("$0", "%rcx", "", "movq", "oaa", "");
            instruction * ins3 = new instruction("%rcx", "%rbx", "", "cmpq", "oaa", "");
            instruction * ins4 = new instruction("%cl", "", "", "sete", "oa", "");
            instruction * ins5 = new instruction("%rcx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
            x86_generator::text_segment.push_back(ins4);
            x86_generator::text_segment.push_back(ins5);
        }else if (t->op == "~"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins2 = new instruction("%rbx", "", "", "notq", "oa", "");
            instruction * ins3 = new instruction("%rbx", get_value(t->result), "", "movq", "oaa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins2);
            x86_generator::text_segment.push_back(ins3);
        }
    }else if (t->optype == "DEREF"){
        instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
        instruction * ins2 = new instruction("(%rbx)", "%rcx", "", "movq", "oaa", "");
        instruction * ins3 = new instruction("%rcx", get_value(t->result), "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins);
        x86_generator::text_segment.push_back(ins2);
        x86_generator::text_segment.push_back(ins3);
    }else if (t->optype == "address_assign"){
        instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
        instruction * ins2 = new instruction(get_value(t->result), "%rcx", "", "movq", "oaa", "");
        instruction * ins3 = new instruction("%rbx", "(%rcx)", "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins);
        x86_generator::text_segment.push_back(ins2);
        x86_generator::text_segment.push_back(ins3);
    }else if (t->optype == "if_goto"){
        if (t->op == "if_false"){
            instruction * ins = new instruction(get_value(t->arg1), "%rbx", "", "movq", "oaa", "");
            instruction * ins1 = new instruction("%rbx", "%rbx", "", "testq", "oaa", "");
            instruction * ins2 = new instruction((t->arg2).substr(1), "", "", "jz", "oa", "");
            x86_generator::text_segment.push_back(ins);
            x86_generator::text_segment.push_back(ins1);
            x86_generator::text_segment.push_back(ins2);
        }
    }else if (t->optype == "goto"){
        instruction * ins = new instruction((t->arg1).substr(1), "", "", "jmp", "oa", "");
        x86_generator::text_segment.push_back(ins);
    }else if (t->optype == "label" && t->comment != "Unused"){
        instruction * ins = new instruction((t->arg1).substr(1), "", "", "", "l", "");
        x86_generator::text_segment.push_back(ins);
    }
    else if (t->optype == "call"){
        int param_size = atoi(t->arg1.c_str()) * 8;
        instruction * ins = new instruction(func_names[t->op], "" , "", "call", "oa", "");
        x86_generator::text_segment.push_back(ins);
        instruction * ins1 = new instruction(get_value(to_string(param_size)), "%rsp", "", "addq", "oaa", "");
        x86_generator::text_segment.push_back(ins1);
    }else if (t->optype == "param"){
        instruction * ins = new instruction(get_value(t->op), "", "", "pushq", "oa", "");
        x86_generator::text_segment.push_back(ins);
    }else if (t->optype == "return"){
        instruction * ins = new instruction(get_value(t->arg1), "%rax", "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins);
        instruction * ins1 = new instruction("%rbp", "%rsp", "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins1);
        instruction * ins2 = new instruction("%rbp", "", "", "popq", "oa", "");
        x86_generator::text_segment.push_back(ins2);
        instruction * ins3 = new instruction("", "", "", "ret", "o", "");
        x86_generator::text_segment.push_back(ins3);
    }
    return NULL;
}

void x86_generator::generate_code(vector<three_ac*> & threeAC){
    int i = 0, j = 0, func_renamer = 0;
    func_names["print@int"] = "print_int";
    func_names["print@str"] = "print_string";
    func_names["print@bool"] = "print_bool";
    func_names["len"] = "len";
    for (i = 0; i < threeAC.size(); i++){
        if (threeAC[i]->optype == "beginfunc"){
            if (threeAC[i]->arg1 == "global.main"){
                func_names[threeAC[i]->arg1] = "main";
            }else{
                func_names[threeAC[i]->arg1] = "func" + to_string(++func_renamer);
            }
        }
    }
    i = 0;
    while (i < threeAC.size() && j < threeAC.size()){
        while (i < threeAC.size() && threeAC[i]->optype != "beginfunc"){
            i++;
        }
        j = i;
        while (j < threeAC.size() && threeAC[j]->optype != "endfunc"){
            j++;
        }
        // make instructions for code between i and j
        //DEBUG("Generating code for function"); 
        //DEBUG(i);
        //DEBUG(j);
        offsets.clear();
        int curr_off = -8;
        int param_off = 16;

        for (int k = i+1; k < j; k++){
            if (threeAC[k]->optype == "assign" || threeAC[k]->optype == "quad" || threeAC[k]->optype == "DEREF" || threeAC[k]->optype == "unary" ){
                if (offsets.find(threeAC[k]->result) == offsets.end()){
                    if (threeAC[k]->arg1 == "#popparam"){
                        offsets[threeAC[k]->result] = param_off;
                        param_off += 8;
                    }
                    else{
                        offsets[threeAC[k]->result] = curr_off;
                        curr_off -= 8;
                    }
                }
                if (threeAC[k]->arg1 == "#space"){
                    curr_off -= atoi(threeAC[k]->arg2.c_str());
                    threeAC[k]->arg2 = to_string(curr_off+8);
                    curr_off -= 8;
                }
            }
        }
        for (auto it = offsets.begin(); it != offsets.end(); it++){
            //DEBUG(it->first);
            //DEBUG(it->second);
        }
        // start of func call
        instruction * ins = new instruction(func_names[threeAC[i]->arg1], "", "", "", "l", "");
        x86_generator::text_segment.push_back(ins);
        instruction * ins1 = new instruction("%rbp", "", "", "pushq", "oa", "");
        x86_generator::text_segment.push_back(ins1);
        instruction * ins2 = new instruction("%rsp", "%rbp", "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins2);
        instruction * ins3 = new instruction("$" + to_string(-(curr_off+8)), "%rsp", "", "subq", "oaa", "");
        x86_generator::text_segment.push_back(ins3);
        for (int k = i+1; k < j; k++){
            gen_instruction(threeAC[k]);
        }
        // end of func call
        instruction * ins4 = new instruction("%rbp", "%rsp", "", "movq", "oaa", "");
        x86_generator::text_segment.push_back(ins4);
        instruction * ins5 = new instruction("%rbp", "", "", "popq", "oa", "");
        x86_generator::text_segment.push_back(ins5);
        if (threeAC[i]->arg1 == "global.main"){
            instruction * ins6 = new instruction("exit0", "", "", "jmp", "oa", "");
            x86_generator::text_segment.push_back(ins6);
        }else{
            instruction * ins6 = new instruction("", "", "", "ret", "o", "");
            x86_generator::text_segment.push_back(ins6);
        }

        i = j+1;
    }

    return;
}