/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN_AND = 258,              /* "&="  */
    ASSIGN_DIVIDE = 259,           /* "/="  */
    ASSIGN_DOUBLESLASH = 260,      /* "//="  */
    ASSIGN_EQUAL = 261,            /* "="  */
    ASSIGN_LEFTSHIFT = 262,        /* "<<="  */
    ASSIGN_MINUS = 263,            /* "-="  */
    ASSIGN_MOD = 264,              /* "%="  */
    ASSIGN_MULTIPLY = 265,         /* "*="  */
    ASSIGN_OR = 266,               /* "|="  */
    ASSIGN_PLUS = 267,             /* "+="  */
    ASSIGN_POWER = 268,            /* "**="  */
    ASSIGN_RIGHTSHIFT = 269,       /* ">>="  */
    ASSIGN_XOR = 270,              /* "^="  */
    CLOSE_SQUARE_BRACKET = 271,    /* "]"  */
    DEDENT = 272,                  /* DEDENT  */
    ENDMARKER = 273,               /* ENDMARKER  */
    INDENT = 274,                  /* INDENT  */
    KEY_BREAK = 275,               /* "break"  */
    KEY_CLASS = 276,               /* "class"  */
    KEY_CONTINUE = 277,            /* "continue"  */
    KEY_ELIF = 278,                /* "elif"  */
    KEY_ELSE = 279,                /* "else"  */
    KEY_FALSE = 280,               /* "False"  */
    KEY_FOR = 281,                 /* "for"  */
    KEY_FUNCTION_DEF = 282,        /* "def"  */
    KEY_GLOBAL = 283,              /* "global"  */
    KEY_IF = 284,                  /* "if"  */
    KEY_NONE = 285,                /* "None"  */
    KEY_RETURN = 286,              /* "return"  */
    KEY_TRUE = 287,                /* "True"  */
    KEY_WHILE = 288,               /* "while"  */
    NAME = 289,                    /* NAME  */
    NEWLINE = 290,                 /* NEWLINE  */
    NUMBER = 291,                  /* NUMBER  */
    OPEN_SQUARE_BRACKET = 292,     /* "["  */
    OPER_AND = 293,                /* "and"  */
    OPER_AND_BITWISE = 294,        /* "&"  */
    OPER_CLOSE_BRACKET = 295,      /* ")"  */
    OPER_COLON = 296,              /* ":"  */
    OPER_COMMA = 297,              /* ","  */
    OPER_DIVIDE = 298,             /* "/"  */
    OPER_DOT = 299,                /* "."  */
    OPER_EQUAL = 300,              /* "=="  */
    OPER_GREATER_THAN = 301,       /* ">"  */
    OPER_GREATER_THAN_EQUAL = 302, /* ">="  */
    OPER_IN = 303,                 /* "in"  */
    OPER_INT_DIV = 304,            /* "//"  */
    OPER_LEFT_SHIFT = 305,         /* "<<"  */
    OPER_LESS_GREATER = 306,       /* "<>"  */
    OPER_LESS_THAN = 307,          /* "<"  */
    OPER_LESS_THAN_EQUAL = 308,    /* "<="  */
    OPER_MINUS = 309,              /* "-"  */
    OPER_MOD = 310,                /* "%"  */
    OPER_MULTIPLY = 311,           /* "*"  */
    OPER_NEGATIVE = 312,           /* "~"  */
    OPER_NOT = 313,                /* "not"  */
    OPER_NOT_EQUAL = 314,          /* "!="  */
    OPER_OPEN_BRACKET = 315,       /* "("  */
    OPER_OR = 316,                 /* "or"  */
    OPER_OR_BITWISE = 317,         /* "|"  */
    OPER_PLUS = 318,               /* "+"  */
    OPER_POWER = 319,              /* "**"  */
    OPER_REFERENCE = 320,          /* "->"  */
    OPER_RIGHT_SHIFT = 321,        /* ">>"  */
    OPER_SEMICOLON = 322,          /* ";"  */
    OPER_XOR_BITWISE = 323,        /* "^"  */
    STRING = 324                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "parser.y"

    struct TreeNode * node;

#line 137 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
