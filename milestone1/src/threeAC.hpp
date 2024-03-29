#include <bits/stdc++.h>
using namespace std;

class quad
{
public:
    int op;
    string arg1;
    string arg2;
    string result;
    quad();
    quad(int opcode, string arg1, string arg2, string result);
    void append();
    static vector<quad> three_ac; 
    static void print(string filename);
    enum opcode
    {
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        MOV,
        LT,
        GT,
        LE,
        GE,
        EQ,
        NE,
        AND,
        OR,
        GOTO,
        IFZ,
        PARAM,
        CALL,
        RET,
        FUNC,
        END
    };
private: 
    static string opcode_string(int opcode);
};
