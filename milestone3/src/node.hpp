#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        string name;
        string type;
        string lexeme;
        // int line_no;
        int unique_id;
        // int size;
        // bool is_init;
        // int init_val;

        vector<node *> children;
        void append_child(node *child);
        

        // int offset = 0; // no idea
        // ll dims = 0; // for multidim array 
        
        // node();
        // node(string name, ll line_no, string type);
        // node(string name, const node& other); // may be for a=b type
        // void update_type(string type);
};