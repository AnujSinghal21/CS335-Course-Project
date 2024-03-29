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
    KEY_ASSERT = 275,              /* "assert"  */
    KEY_BREAK = 276,               /* "break"  */
    KEY_CLASS = 277,               /* "class"  */
    KEY_CONTINUE = 278,            /* "continue"  */
    KEY_DELETE = 279,              /* "delete"  */
    KEY_ELIF = 280,                /* "elif"  */
    KEY_ELSE = 281,                /* "else"  */
    KEY_FALSE = 282,               /* "False"  */
    KEY_FOR = 283,                 /* "for"  */
    KEY_FUNCTION_DEF = 284,        /* "def"  */
    KEY_GLOBAL = 285,              /* "global"  */
    KEY_IF = 286,                  /* "if"  */
    KEY_NONE = 287,                /* "None"  */
    KEY_NONLOCAL = 288,            /* "nonlocal"  */
    KEY_RETURN = 289,              /* "return"  */
    KEY_TRUE = 290,                /* "True"  */
    KEY_WHILE = 291,               /* "while"  */
    NAME = 292,                    /* NAME  */
    NEWLINE = 293,                 /* NEWLINE  */
    NUMBER = 294,                  /* NUMBER  */
    OPEN_SQUARE_BRACKET = 295,     /* "["  */
    OPER_AND = 296,                /* "and"  */
    OPER_AND_BITWISE = 297,        /* "&"  */
    OPER_CLOSE_BRACKET = 298,      /* ")"  */
    OPER_COLON = 299,              /* ":"  */
    OPER_COMMA = 300,              /* ","  */
    OPER_DIVIDE = 301,             /* "/"  */
    OPER_DOT = 302,                /* "."  */
    OPER_EQUAL = 303,              /* "=="  */
    OPER_GREATER_THAN = 304,       /* ">"  */
    OPER_GREATER_THAN_EQUAL = 305, /* ">="  */
    OPER_IN = 306,                 /* "in"  */
    OPER_INT_DIV = 307,            /* "//"  */
    OPER_IS = 308,                 /* "is"  */
    OPER_LEFT_SHIFT = 309,         /* "<<"  */
    OPER_LESS_GREATER = 310,       /* "<>"  */
    OPER_LESS_THAN = 311,          /* "<"  */
    OPER_LESS_THAN_EQUAL = 312,    /* "<="  */
    OPER_MINUS = 313,              /* "-"  */
    OPER_MOD = 314,                /* "%"  */
    OPER_MULTIPLY = 315,           /* "*"  */
    OPER_NEGATIVE = 316,           /* "~"  */
    OPER_NOT = 317,                /* "not"  */
    OPER_NOT_EQUAL = 318,          /* "!="  */
    OPER_OPEN_BRACKET = 319,       /* "("  */
    OPER_OR = 320,                 /* "or"  */
    OPER_OR_BITWISE = 321,         /* "|"  */
    OPER_PLUS = 322,               /* "+"  */
    OPER_POWER = 323,              /* "**"  */
    OPER_REFERENCE = 324,          /* "->"  */
    OPER_RIGHT_SHIFT = 325,        /* ">>"  */
    OPER_SEMICOLON = 326,          /* ";"  */
    OPER_XOR_BITWISE = 327,        /* "^"  */
    STRING = 328                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "parser.y"

    struct TreeNode * node;

#line 141 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
