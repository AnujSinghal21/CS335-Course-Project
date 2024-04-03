#ifndef THREEAC_HPP
#define THREEAC_HPP 
#include "globals.hpp"

class three_ac{
    public:
        string op;
        string arg1;
        string arg2;
        string result;
        string optype;
        string comment;
        three_ac();
        three_ac(string optype, string op = "", string arg1 = "", string arg2 = "", string result = "", string comment = "");
        void print(ofstream & out);
        static vector<three_ac*> threeAC;
        static int temp_counter;
        static int label_counter;
        static stack<int> label_stack;
        static three_ac * gen(string optype, string op = "", string arg1 = "", string arg2 = "", string result = "", string comment = "");
        static three_ac * append(three_ac * t);
        static void export_txt(string filename);
        static string new_temp();
        static string new_label();
        static string push_new_label();
        static string pop_label();
        static void dereference(struct TreeNode * node);
};

#endif