#include "threeAC.hpp"

quad::quad()
{
    op = -1;
    arg1 = "";
    arg2 = "";
    result = "";
}
quad::quad(int opcode, string arg1, string arg2, string result)
{
    this->op = opcode;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->result = result;
}
void quad::append()
{
    quad::three_ac.push_back(*this);
}
void quad::print(string filename)
{

    ofstream out;
    out.open(filename);
    for (int i = 0; i < quad::three_ac.size(); i++)
    {
        out << i << ": " << quad::opcode_string(quad::three_ac[i].op) << ", " << quad::three_ac[i].arg1 << ", " << quad::three_ac[i].arg2 << ", " << quad::three_ac[i].result << endl;
    }
}
string quad::opcode_string(int opcode)
{
    switch (opcode)
    {
    case ADD:
        return "ADD";
    case SUB:
        return "SUB";
    case MUL:
        return "MUL";
    case DIV:
        return "DIV";
    case MOD:
        return "MOD";
    case MOV:
        return "MOV";
    case LT:
        return "LT";
    case GT:
        return "GT";
    case LE:
        return "LE";
    case GE:
        return "GE";
    case EQ:
        return "EQ";
    case NE:
        return "NE";
    case AND:
        return "AND";
    case OR:
        return "OR";
    case GOTO:
        return "GOTO";
    case IFZ:
        return "IFZ";
    case PARAM:
        return "PARAM";
    case CALL:
        return "CALL";
    case RET:
        return "RET";
    case FUNC:
        return "FUNC";
    case END:
        return "END";
    default:
        return "INVALID";
    }
}