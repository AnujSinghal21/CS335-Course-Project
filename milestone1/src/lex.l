%{
#include "parser.tab.h"
#include "globals.hpp"
// #include<bits/stdc++.h>
stack<int> indent_stack;
int global_indent = 0;
int generated_EOF = 0;
int ready_EOF = 0;
int signal_EOF = 0;
int entered_newline = 0;
string last_token = "";
string last_token_value = "";
stack<char> brackets;
int terminated = 0;

%}

%option yylineno

NEWLINE "\n"
INDENTATION ^[ \t]*
COMMENT "#"[^\n]*
KEYWORDS False|None|True|and|as|break|class|continue|def|elif|else|except|finally|for|from|global|if|import|in|is|lambda|not|or|pass|raise|return|try|while|with|yield
SPACES [ \t\r]*

stringescapeseq  "\\".
shortstringchar [^\\\n]
longstringchar [^\\]
shortstringitem  {shortstringchar}|{stringescapeseq}
longstringitem  {longstringchar}|{stringescapeseq}
shortstring "'"(({shortstringitem}|"\"")*)"'"|"\""(({shortstringitem}|"\'")*)"\""
longstring "'''"({longstringitem}*)"'''"|"\"\"\""({longstringitem}*)"\"\"\""
stringprefix "r"|"u"|"R"|"U"|"f"|"F"|"fr"|"Fr"|"fR"|"FR"|"rf"|"rF"|"Rf"|"RF"|"b"|"B"|"br"|"Br"|"bR"|"BR"|"rb"|"rB"|"Rb"|"RB"
stringliteral {stringprefix}?({shortstring}|{longstring})

nonzerodigit [1-9]
digit    [0-9]
bindigit [01]
octdigit [0-7]
hexdigit [0-9a-fA-F]
bininteger   "0"("b"|"B")("_"?{bindigit})+
octinteger   "0"("o"|"O")("_"?{octdigit})+
hexinteger   "0"("x"|"X")("_"?{hexdigit})+
decinteger {nonzerodigit}("_"?{digit})*|"0"+("_"?"0")*
integer {decinteger}|{bininteger}|{octinteger}|{hexinteger}

digitpart {digit}("_"?{digit})*
exponent ("e"|"E")("+"|"-")?{digitpart}
fraction "."{digitpart}
pointfloat {digitpart}?{fraction}|{digitpart}"."
exponentfloat ({digitpart}|{pointfloat}){exponent}
floatnumber {pointfloat}|{exponentfloat}

imagnumber (floatnumber|digitpart)("j"|"J")

operators "+"|"-"|"*"|"**"|"/"|"//"|"%"|"<<"|">>"|"&"|"|"|"^"|"~"|"<"|">"|"<="|">="|"=="|"!="|and|or|not|"="|"+="|"-="|"*="|"/="|"//="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="

delimiters "("|")"|"["|"]"|"{"|"}"|","|":"|"."|";"|"->"

IDENTIFIER ([a-zA-Z]|"_")([a-zA-Z0-9]|"_")*
dunder "__main__"|"__name__"|"__init__" 

%%
 {
    if (global_indent > 0){
        global_indent--;
        last_token = "INDENT";
        return INDENT;
    }else if(global_indent < 0){
        global_indent++;
        last_token = "DEDENT";
        return DEDENT;
    }
 }
"&=" {last_token="&=";yylval.node = makeNode(yytext,OPERATOR_TYPE);return ASSIGN_AND;}
"/=" {last_token="/=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_DIVIDE;}
"//=" {last_token="//=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_DOUBLESLASH;}
"=" {last_token="=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_EQUAL;}
"<<=" {last_token="<<=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_LEFTSHIFT;}
"-=" {last_token="-=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_MINUS;}
"%=" {last_token="%=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_MOD;}
"*=" {last_token="*=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_MULTIPLY;}
"|=" {last_token="|=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_OR;}
"+=" {last_token="+=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_PLUS;}
"**=" {last_token="**=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_POWER;}
">>=" {last_token=">>=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_RIGHTSHIFT;}
"^=" {last_token="^=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return ASSIGN_XOR;}
"]" {last_token="]";if (brackets.size() > 0 && brackets.top() == '['){brackets.pop();};yylval.node = makeNode(yytext,OPERATOR_TYPE); return CLOSE_SQUARE_BRACKET;}
"break" {last_token="break";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_BREAK;}
"class" {last_token="class";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_CLASS;}
"continue" {last_token="continue";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_CONTINUE;}
"elif" {last_token="elif";yylval.node = makeNode(yytext,ELIF_STATEMENT_TYPE); return KEY_ELIF;}
"else" {last_token="else";yylval.node = makeNode(yytext,ELSE_STATEMENT_TYPE); return KEY_ELSE;}
"False" {last_token="False";yylval.node = makeNode(yytext,BOOLEAN_TYPE); return KEY_FALSE;}
"for" {last_token="for";yylval.node = makeNode(yytext,FOR_STATEMENT_TYPE); return KEY_FOR;}
"def" {last_token="def";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_FUNCTION_DEF;}
"global" {last_token="global";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_GLOBAL;}
"if" {last_token="if";yylval.node = makeNode(yytext,IF_STATEMENT_TYPE); return KEY_IF;}
"None" {last_token="None";yylval.node = makeNode(yytext,NAME_TYPE); return KEY_NONE;}
"return" {last_token="return";yylval.node = makeNode(yytext,KEYWORD_TYPE); return KEY_RETURN;}
"True" {last_token="True";yylval.node = makeNode(yytext,BOOLEAN_TYPE); return KEY_TRUE;}
"while" {last_token="while";yylval.node = makeNode(yytext,WHILE_STATEMENT_TYPE); return KEY_WHILE;}
"[" {last_token="[";brackets.push('[');yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPEN_SQUARE_BRACKET;}
"and" {last_token="and";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_AND;}
"&" {last_token="&";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_AND_BITWISE;}
")" {last_token=")";if (brackets.size() > 0 && brackets.top() == '('){brackets.pop();};yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_CLOSE_BRACKET;}
":" {last_token=":";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_COLON;}
"," {last_token=",";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_COMMA;}
"/" {last_token="/";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_DIVIDE;}
"." {last_token=".";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_DOT;}
"==" {last_token="==";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_EQUAL;}
">" {last_token=">";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_GREATER_THAN;}
">=" {last_token=">=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_GREATER_THAN_EQUAL;}
"in" {last_token="in";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_IN;}
"//" {last_token="//";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_INT_DIV;}
"<<" {last_token="<<";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_LEFT_SHIFT;}
"<>" {last_token="<>";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_LESS_GREATER;}
"<" {last_token="<";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_LESS_THAN;}
"<=" {last_token="<=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_LESS_THAN_EQUAL;}
"-" {last_token="-";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_MINUS;}
"%" {last_token="%";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_MOD;}
"*" {last_token="*";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_MULTIPLY;}
"~" {last_token="~";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_NEGATIVE;}
"not" {last_token="not";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_NOT;}
"!=" {last_token="!=";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_NOT_EQUAL;}
"(" {last_token="("; brackets.push('(');yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_OPEN_BRACKET;}
"or" {last_token="or";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_OR;}
"|" {last_token="|";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_OR_BITWISE;}
"+" {last_token="+";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_PLUS;}
"**" {last_token="**";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_POWER;}
"->" {last_token="->";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_REFERENCE;}
">>" {last_token=">>";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_RIGHT_SHIFT;}
"^" {last_token="^";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_XOR_BITWISE;}
";" {last_token=";";yylval.node = makeNode(yytext,OPERATOR_TYPE); return OPER_SEMICOLON;}
{integer}|{floatnumber}|{imagnumber} {last_token="NUMBER";last_token_value=yytext;yylval.node = makeNode(yytext,NUMBER_TYPE); return NUMBER;}
{dunder} {last_token="NAME";last_token_value=yytext;yylval.node = makeNode(yytext,NAME_TYPE); return NAME;}
{IDENTIFIER} {last_token="NAME";last_token_value=yytext;yylval.node = makeNode(yytext,NAME_TYPE); return NAME;}
{stringliteral} {last_token="STRING";last_token_value=yytext;yylval.node = makeNode(yytext,STRING_TYPE); return STRING;}
{COMMENT} {}
"\\" {last_token = "\\";}
[\n\r\f]([ \n\t\r\f]|{COMMENT})* {
    if (last_token != "\\" && brackets.size() == 0){
        string spaces = yytext;
        int len = 0;
        for (auto c: spaces){
            if (c == ' ' || c == '\t') len++;
            if (c == '\n') len = 0;
        }
        int top = indent_stack.top();
        if(len > top) {
            global_indent++;
            indent_stack.push(len);
        }
        else{
            while (len < top){
                indent_stack.pop();
                top = indent_stack.top();
                global_indent--;
            }
        }
        last_token = "NEWLINE";
        yylval.node = makeNode("\n",MISC_TYPE);return NEWLINE;
    }
}
[ \t\r\f] {}

<<EOF>> {
    if (!ready_EOF){
        if (!entered_newline && last_token != "DEDENT"){
            entered_newline = 1;
            return NEWLINE;
        }
        if (indent_stack.size() > 1){
            indent_stack.pop();
            last_token = "DEDENT";
            return DEDENT;
        }else if (indent_stack.size() == 1){
            ready_EOF = 1;
            last_token = "NEWLINE";
            return NEWLINE;
        }
    }
    if (ready_EOF){
        if (generated_EOF){
            return 0;
        }
        generated_EOF = 1;
        yylval.node = makeNode("ENDMARKER",MISC_TYPE); return ENDMARKER;
    }
}

. {
    terminated = 1;
    cerr << "Error: Unrecognized token " << yytext << " at line " << yylineno << endl;
    yyterminate();
    return 0;
}

%%

int yywrap() {
    return 1;
}

