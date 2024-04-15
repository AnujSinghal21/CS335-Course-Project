#include "x86.hpp"
void x86_generator::generate_code(string filename, vector<three_ac*> & threeAC){
    ofstream out;
    out.open(filename);
    out << "\t.text\n";
    for (int i = 0; i < threeAC.size(); i++){
        threeAC[i]->print(out);
    }
    out.close();
    return;
}