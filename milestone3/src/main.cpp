#include "includes.hpp"
extern stack<int> indent_stack;
extern struct type int_node;
extern struct type float_node;
extern struct type bool_node;
extern struct type str_node;
extern struct type void_node;
extern TreeNode * root;
extern FILE* yyin;
extern symtable_func* curr_symtable_func;
extern symtable_class* curr_symtable_class;
extern symtable_global* curr_symtable_global;
extern symtable_global* global_symtable;
extern int yyparse();
extern int terminated;
extern unordered_set<string> declared_types;

void help_printer(){
    cout << "USAGE: " << endl;
    cout << "[-input <path-to-inputfile>]: specify the file path to parse, if not given, takes input from stdin" << endl;
    cout << "[-output <path-to-outputfile>]: specify the file path to write the ast, if not given, defaults to ast.dot" << endl;
    cout << "[-verbose]: prints verbose messages to stdout, error messages are anyways printed" << endl;
    cout << "[-help]: print usage instructions" << endl;
    cout << "For more help regarding how to use and output, refer to doc" << endl;
    return;
}

int main(int argc, char ** argv){
    FILE *file;
    int verbose = 0;
    int print_help = 0;
    int inputfilearg = -1;
    int astfilearg = -1; 
    int tac_file_arg = -1;
    int csv_file_arg = -1;
    int asm_file_arg = -1;
    char default_output_name[] = "ast.dot";
    indent_stack.push(0);
    
    for (int i = 1; i < argc; i++){
        string arg = argv[i];
        if (arg == "-input"){
            if (i+1 < argc){
                inputfilearg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-tac"){
            if (i+1 < argc){
                tac_file_arg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }
        else if (arg == "-ast"){
            if (i+1 < argc){
                astfilearg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-csv"){
            if (i+1 < argc){
                csv_file_arg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-asm"){
            if (i+1 < argc){
                asm_file_arg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }
        else if (arg == "-verbose"){
            verbose = 1;
        }
        else {
            print_help = 1;
        }
    }
    if (print_help){
        help_printer();
        return 0;
    }
    
    if (inputfilearg == -1){
        yyin = stdin;
    }else{
        file = fopen(argv[inputfilearg], "r");
        if (file == NULL) {
            cerr << "Error opening file" << endl;
            return 0;
        }else{
            yyin = file;
        }
    }

    if (verbose){
        cout << "Started parsing" <<endl;
    }

    int_node.t = "int";
    float_node.t = "float";
    bool_node.t = "bool";
    str_node.t = "str";
    void_node.t = "void";

    global_symtable = new symtable_global();
    curr_symtable_global = global_symtable;
    curr_symtable_global->add_range_func();
    declared_types.insert("int");
    declared_types.insert("float");
    declared_types.insert("bool");
    declared_types.insert("str");
    declared_types.insert("void");
    declared_types.insert("list");
    for(auto s:declared_types){
        if(s!="void" && s!="list") curr_symtable_global->add_len_func(s);
    }
    struct type t;
    curr_symtable_global->add_print_func(int_node);
    curr_symtable_global->add_print_func(float_node);
    curr_symtable_global->add_print_func(bool_node);
    curr_symtable_global->add_print_func(str_node);
    yyparse();
    if(csv_file_arg!=-1){
        curr_symtable_global->create_csv(argv[csv_file_arg]);
    }else{
        curr_symtable_global->create_csv("symtab.csv");
    }    
    if (tac_file_arg != -1){
        // DEBUG("Here")
        three_ac::export_txt(argv[tac_file_arg]);
        cout << "3AC written in file: " << argv[tac_file_arg] << endl;
    }else{
        // DEBUG("Here")
        three_ac::export_txt("3AC.txt");
        cout << "3AC written in file: 3AC.txt" << endl;
    }
    if (asm_file_arg != -1){
        x86_generator::generate_code(three_ac::threeAC);
        x86_generator::export_asm(argv[asm_file_arg]);
        cout << "x86 written in file: " << argv[asm_file_arg] << endl;
    }else{
        x86_generator::generate_code(three_ac::threeAC);
        x86_generator::export_asm("x86.s");
        cout << "x86 written in file: x86.s" << endl;
    }

    if (verbose){
        if (terminated){
            cout << "Error in parsing, AST generated might be incomplete/erroneous" << endl;
        }else{
            cout << "Parsing complete without errors, printing abstract syntax tree" << endl;
        }
    }
    if (astfilearg == -1){
        printAST(default_output_name);
        if (verbose){
            cout << "AST written in file: " << default_output_name << endl;
        }
    }else{
        printAST(argv[astfilearg]);
        if (verbose){
            cout << "AST written in file: " << argv[astfilearg] << endl;
        }
    }

    fclose(yyin);

    return 0;
}
