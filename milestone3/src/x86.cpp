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
    if (this->ins_t == "ins"){
        out << "\t" << this->op << " " << this->arg1 << ", " << this->arg2;
    }else if (this->ins_t == "label"){
        out << this->op << ":";
    }else if (this->ins_t == "comment"){
        out << "\t" << this->comment;
    }else if (this->ins_t == "data"){
        out << "\t" << this->op << " " << this->arg1 << " " << this->arg2;
    }
    out << endl;
    return;
}

void x86_generator::export_asm(string filename){
    ofstream out;
    out.open(filename);

    // out << "\t.text\n";
    // for (int i = 0; i < three_ac::threeAC.size(); i++){
    //     three_ac::threeAC[i]->print(out);
    // }
    out.close();
    return;

}

instruction * gen_instruction(three_ac * t){
    instruction * ins;

    return ins;
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
        int curr_off = 0;
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
            instruction * ins = gen_instruction(threeAC[k]);
            if (ins != NULL){
                x86_generator::text_segment.push_back(ins);
            }
        }

        i = j+1;
    }

    return;
}