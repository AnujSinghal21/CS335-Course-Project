#include "includes.hpp"

map<string, int> offsets; 
vector<instruction*> x86_generator::text_segment;
vector<instruction *> x86_generator::data_segment;

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
    out << ".text" << endl;
    for (auto ins : x86_generator::text_segment){
        ins->print(out);
    }
    out.close();
    return;

}

instruction * gen_instruction(three_ac * t){
    if (t->optype == "assign"){
        if (t->arg1 != "popparam"){
            if (t->arg1[0] >= '0' && t->arg1[0] <= '9'){
                instruction * ins = new instruction();
                ins->op = "movq";
                ins->arg1 = "$" + t->arg1;
                ins->arg2 = "%rbx";
                ins->ins_t = "oaa";
                x86_generator::text_segment.push_back(ins);
                instruction * ins2 = new instruction();
                ins2->op = "movq";
                ins2->arg1 = "%rbx";
                ins2->arg2 = to_string(offsets[t->result]) + "(%rbp)";
                ins2->ins_t = "oaa";
                x86_generator::text_segment.push_back(ins2);
            }
        }
    }
    return NULL;
}

void x86_generator::generate_code(vector<three_ac*> & threeAC){
    int i = 0, j = 0;
    while (i < threeAC.size() && j < threeAC.size()){
        while (i < threeAC.size() && threeAC[i]->optype != "beginfunc"){
            i++;
        }
        j = i;
        while (j < threeAC.size() && threeAC[j]->optype != "endfunc"){
            j++;
        }
        // make instructions for code between i and j
        DEBUG("Generating code for function"); 
        DEBUG(i);
        DEBUG(j);
        offsets.clear();
        int curr_off = -8;
        int param_off = 16;
        for (int k = i+1; k < j; k++){
            if (threeAC[k]->optype == "assign"){
                if (offsets.find(threeAC[k]->result) == offsets.end()){
                    if (threeAC[k]->arg1 == "popparam"){
                        offsets[threeAC[k]->result] = param_off;
                        param_off += 8;
                    }else{
                        offsets[threeAC[k]->result] = curr_off;
                        curr_off -= 8;
                    }
                }
            }
        }
        for (auto it = offsets.begin(); it != offsets.end(); it++){
            DEBUG(it->first);
            DEBUG(it->second);
        }
        for (int k = i+1; k < j; k++){
            gen_instruction(threeAC[k]);
        }

        i = j+1;
    }

    return;
}