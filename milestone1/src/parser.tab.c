/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include<bits/stdc++.h>
#include "globals.hpp"
using namespace std;
extern stack<int> indent_stack;
extern int yylineno;
extern FILE* yyin;
extern string last_token;
extern string last_token_value;
extern int terminated;
extern symtable_global* global_symtable;
int yylex();
int yyerror(const char * msg);

symtable_global* global_symtable;
map<string, string> id_to_label;
map<string, vector<string> > edges;
symtable_func* curr_symtable_func = NULL;
symtable_class* curr_symtable_class = NULL;
symtable_global* curr_symtable_global;

struct type int_node;
struct type float_node;
struct type bool_node;
struct type str_node;
struct type void_node;


void checker_traverse(struct TreeNode* node){
    if(node == NULL){
        return;
    }

    for(auto child : node->children){
        if(child->node_type == NAME_TYPE){
            if(curr_symtable_func!=NULL){
                curr_symtable_func->check_declaration_var(child->lexeme,yylineno-1);
            }
            else{
                curr_symtable_global->check_declaration_var(child->lexeme,yylineno-1);
            }
        }

        checker_traverse(child);
    }
    return;
}
void printTree(struct TreeNode * node){
    if (node == NULL){
        return;
    }
    // cout << node->id << " " << node->lexeme << " has type: " << node->node_type << endl;
    for (auto child: node->children){
        printTree(child);
    }   
    return;
} 

struct type get_max_type(struct type t1, struct type t2){

    int val_t1= 0, val_t2 = 0;
    if(type_equal(t1,float_node)) val_t1 = 5; 
    else if(type_equal(t1,float_node)) val_t1 = 4; 
    else if(type_equal(t1,float_node)) val_t1 = 3; 
    else if(type_equal(t1,float_node)) val_t1 = 2; 
    else if(type_equal(t1,float_node)) val_t1 = 1; 

    if(type_equal(t2,float_node)) val_t2 = 5; 
    else if(type_equal(t2,float_node)) val_t2 = 4; 
    else if(type_equal(t2,float_node)) val_t2 = 3; 
    else if(type_equal(t2,float_node)) val_t2 = 2; 
    else if(type_equal(t2,float_node)) val_t2 = 1; 

    if(val_t1 > val_t2){
        return t1; 
    }else{
        return t2;
    }


}

TreeNode * root = NULL;


#line 157 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN_AND = 3,                 /* "&="  */
  YYSYMBOL_ASSIGN_DIVIDE = 4,              /* "/="  */
  YYSYMBOL_ASSIGN_DOUBLESLASH = 5,         /* "//="  */
  YYSYMBOL_ASSIGN_EQUAL = 6,               /* "="  */
  YYSYMBOL_ASSIGN_LEFTSHIFT = 7,           /* "<<="  */
  YYSYMBOL_ASSIGN_MINUS = 8,               /* "-="  */
  YYSYMBOL_ASSIGN_MOD = 9,                 /* "%="  */
  YYSYMBOL_ASSIGN_MULTIPLY = 10,           /* "*="  */
  YYSYMBOL_ASSIGN_OR = 11,                 /* "|="  */
  YYSYMBOL_ASSIGN_PLUS = 12,               /* "+="  */
  YYSYMBOL_ASSIGN_POWER = 13,              /* "**="  */
  YYSYMBOL_ASSIGN_RIGHTSHIFT = 14,         /* ">>="  */
  YYSYMBOL_ASSIGN_XOR = 15,                /* "^="  */
  YYSYMBOL_CLOSE_SQUARE_BRACKET = 16,      /* "]"  */
  YYSYMBOL_DEDENT = 17,                    /* DEDENT  */
  YYSYMBOL_ENDMARKER = 18,                 /* ENDMARKER  */
  YYSYMBOL_INDENT = 19,                    /* INDENT  */
  YYSYMBOL_KEY_BREAK = 20,                 /* "break"  */
  YYSYMBOL_KEY_CLASS = 21,                 /* "class"  */
  YYSYMBOL_KEY_CONTINUE = 22,              /* "continue"  */
  YYSYMBOL_KEY_ELIF = 23,                  /* "elif"  */
  YYSYMBOL_KEY_ELSE = 24,                  /* "else"  */
  YYSYMBOL_KEY_FALSE = 25,                 /* "False"  */
  YYSYMBOL_KEY_FOR = 26,                   /* "for"  */
  YYSYMBOL_KEY_FUNCTION_DEF = 27,          /* "def"  */
  YYSYMBOL_KEY_GLOBAL = 28,                /* "global"  */
  YYSYMBOL_KEY_IF = 29,                    /* "if"  */
  YYSYMBOL_KEY_NONE = 30,                  /* "None"  */
  YYSYMBOL_KEY_RETURN = 31,                /* "return"  */
  YYSYMBOL_KEY_TRUE = 32,                  /* "True"  */
  YYSYMBOL_KEY_WHILE = 33,                 /* "while"  */
  YYSYMBOL_NAME = 34,                      /* NAME  */
  YYSYMBOL_NEWLINE = 35,                   /* NEWLINE  */
  YYSYMBOL_NUMBER = 36,                    /* NUMBER  */
  YYSYMBOL_OPEN_SQUARE_BRACKET = 37,       /* "["  */
  YYSYMBOL_OPER_AND = 38,                  /* "and"  */
  YYSYMBOL_OPER_AND_BITWISE = 39,          /* "&"  */
  YYSYMBOL_OPER_CLOSE_BRACKET = 40,        /* ")"  */
  YYSYMBOL_OPER_COLON = 41,                /* ":"  */
  YYSYMBOL_OPER_COMMA = 42,                /* ","  */
  YYSYMBOL_OPER_DIVIDE = 43,               /* "/"  */
  YYSYMBOL_OPER_DOT = 44,                  /* "."  */
  YYSYMBOL_OPER_EQUAL = 45,                /* "=="  */
  YYSYMBOL_OPER_GREATER_THAN = 46,         /* ">"  */
  YYSYMBOL_OPER_GREATER_THAN_EQUAL = 47,   /* ">="  */
  YYSYMBOL_OPER_IN = 48,                   /* "in"  */
  YYSYMBOL_OPER_INT_DIV = 49,              /* "//"  */
  YYSYMBOL_OPER_LEFT_SHIFT = 50,           /* "<<"  */
  YYSYMBOL_OPER_LESS_GREATER = 51,         /* "<>"  */
  YYSYMBOL_OPER_LESS_THAN = 52,            /* "<"  */
  YYSYMBOL_OPER_LESS_THAN_EQUAL = 53,      /* "<="  */
  YYSYMBOL_OPER_MINUS = 54,                /* "-"  */
  YYSYMBOL_OPER_MOD = 55,                  /* "%"  */
  YYSYMBOL_OPER_MULTIPLY = 56,             /* "*"  */
  YYSYMBOL_OPER_NEGATIVE = 57,             /* "~"  */
  YYSYMBOL_OPER_NOT = 58,                  /* "not"  */
  YYSYMBOL_OPER_NOT_EQUAL = 59,            /* "!="  */
  YYSYMBOL_OPER_OPEN_BRACKET = 60,         /* "("  */
  YYSYMBOL_OPER_OR = 61,                   /* "or"  */
  YYSYMBOL_OPER_OR_BITWISE = 62,           /* "|"  */
  YYSYMBOL_OPER_PLUS = 63,                 /* "+"  */
  YYSYMBOL_OPER_POWER = 64,                /* "**"  */
  YYSYMBOL_OPER_REFERENCE = 65,            /* "->"  */
  YYSYMBOL_OPER_RIGHT_SHIFT = 66,          /* ">>"  */
  YYSYMBOL_OPER_SEMICOLON = 67,            /* ";"  */
  YYSYMBOL_OPER_XOR_BITWISE = 68,          /* "^"  */
  YYSYMBOL_STRING = 69,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_input_file = 71,                /* input_file  */
  YYSYMBOL_input_file_dash = 72,           /* input_file_dash  */
  YYSYMBOL_stmt = 73,                      /* stmt  */
  YYSYMBOL_simple_stmt = 74,               /* simple_stmt  */
  YYSYMBOL_small_stmt_dash = 75,           /* small_stmt_dash  */
  YYSYMBOL_small_stmt = 76,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 77,                 /* expr_stmt  */
  YYSYMBOL_expr_stmt_dash = 78,            /* expr_stmt_dash  */
  YYSYMBOL_assign_dash = 79,               /* assign_dash  */
  YYSYMBOL_annasign = 80,                  /* annasign  */
  YYSYMBOL_augassign = 81,                 /* augassign  */
  YYSYMBOL_flow_stmt = 82,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 83,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 84,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 85,               /* return_stmt  */
  YYSYMBOL_global_stmt = 86,               /* global_stmt  */
  YYSYMBOL_NAME_dash = 87,                 /* NAME_dash  */
  YYSYMBOL_compound_stmt = 88,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 89,                   /* if_stmt  */
  YYSYMBOL_if_stmt_dash = 90,              /* if_stmt_dash  */
  YYSYMBOL_else_stmt_dash = 91,            /* else_stmt_dash  */
  YYSYMBOL_elif_stmt = 92,                 /* elif_stmt  */
  YYSYMBOL_else_stmt = 93,                 /* else_stmt  */
  YYSYMBOL_classdef = 94,                  /* classdef  */
  YYSYMBOL_95_1 = 95,                      /* $@1  */
  YYSYMBOL_inheritlist = 96,               /* inheritlist  */
  YYSYMBOL_for_stmt = 97,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 98,                /* while_stmt  */
  YYSYMBOL_funcdef = 99,                   /* funcdef  */
  YYSYMBOL_100_2 = 100,                    /* $@2  */
  YYSYMBOL_funcdef_dash = 101,             /* funcdef_dash  */
  YYSYMBOL_parameters = 102,               /* parameters  */
  YYSYMBOL_parameters_dash = 103,          /* parameters_dash  */
  YYSYMBOL_typedargslist = 104,            /* typedargslist  */
  YYSYMBOL_tfpdef = 105,                   /* tfpdef  */
  YYSYMBOL_suite = 106,                    /* suite  */
  YYSYMBOL_stmt_dash = 107,                /* stmt_dash  */
  YYSYMBOL_test = 108,                     /* test  */
  YYSYMBOL_or_test = 109,                  /* or_test  */
  YYSYMBOL_and_test = 110,                 /* and_test  */
  YYSYMBOL_not_test = 111,                 /* not_test  */
  YYSYMBOL_comparison = 112,               /* comparison  */
  YYSYMBOL_comp_op = 113,                  /* comp_op  */
  YYSYMBOL_expr = 114,                     /* expr  */
  YYSYMBOL_xor_expr = 115,                 /* xor_expr  */
  YYSYMBOL_and_expr = 116,                 /* and_expr  */
  YYSYMBOL_shift_expr = 117,               /* shift_expr  */
  YYSYMBOL_arith_expr = 118,               /* arith_expr  */
  YYSYMBOL_term = 119,                     /* term  */
  YYSYMBOL_factor = 120,                   /* factor  */
  YYSYMBOL_power = 121,                    /* power  */
  YYSYMBOL_atom_expr = 122,                /* atom_expr  */
  YYSYMBOL_trailerlist = 123,              /* trailerlist  */
  YYSYMBOL_trailer = 124,                  /* trailer  */
  YYSYMBOL_atom = 125,                     /* atom  */
  YYSYMBOL_arglist = 126,                  /* arglist  */
  YYSYMBOL_arglist_dash = 127              /* arglist_dash  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   221,   221,   231,   235,   252,   257,   261,   267,   274,
     286,   293,   298,   302,   308,   365,   369,   374,   379,   384,
     390,   397,   402,   410,   414,   418,   422,   426,   430,   434,
     438,   442,   446,   450,   454,   460,   464,   468,   474,   480,
     486,   493,   506,   517,   523,   527,   531,   535,   539,   545,
     555,   563,   567,   572,   576,   581,   588,   596,   603,   603,
     620,   625,   630,   636,   649,   661,   661,   685,   691,   696,
     704,   714,   719,   730,   736,   743,   752,   761,   766,   775,
     780,   787,   793,   797,   813,   817,   832,   844,   851,   864,
     868,   872,   876,   880,   884,   888,   894,   898,   912,   916,
     931,   935,   950,   954,   966,   982,   986,   998,  1013,  1017,
    1030,  1043,  1054,  1069,  1080,  1090,  1103,  1110,  1114,  1127,
    1200,  1211,  1215,  1224,  1229,  1236,  1241,  1257,  1262,  1267,
    1272,  1277,  1281,  1294,  1299,  1304,  1314
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"&=\"", "\"/=\"",
  "\"//=\"", "\"=\"", "\"<<=\"", "\"-=\"", "\"%=\"", "\"*=\"", "\"|=\"",
  "\"+=\"", "\"**=\"", "\">>=\"", "\"^=\"", "\"]\"", "DEDENT", "ENDMARKER",
  "INDENT", "\"break\"", "\"class\"", "\"continue\"", "\"elif\"",
  "\"else\"", "\"False\"", "\"for\"", "\"def\"", "\"global\"", "\"if\"",
  "\"None\"", "\"return\"", "\"True\"", "\"while\"", "NAME", "NEWLINE",
  "NUMBER", "\"[\"", "\"and\"", "\"&\"", "\")\"", "\":\"", "\",\"",
  "\"/\"", "\".\"", "\"==\"", "\">\"", "\">=\"", "\"in\"", "\"//\"",
  "\"<<\"", "\"<>\"", "\"<\"", "\"<=\"", "\"-\"", "\"%\"", "\"*\"",
  "\"~\"", "\"not\"", "\"!=\"", "\"(\"", "\"or\"", "\"|\"", "\"+\"",
  "\"**\"", "\"->\"", "\">>\"", "\";\"", "\"^\"", "STRING", "$accept",
  "input_file", "input_file_dash", "stmt", "simple_stmt",
  "small_stmt_dash", "small_stmt", "expr_stmt", "expr_stmt_dash",
  "assign_dash", "annasign", "augassign", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "global_stmt", "NAME_dash",
  "compound_stmt", "if_stmt", "if_stmt_dash", "else_stmt_dash",
  "elif_stmt", "else_stmt", "classdef", "$@1", "inheritlist", "for_stmt",
  "while_stmt", "funcdef", "$@2", "funcdef_dash", "parameters",
  "parameters_dash", "typedargslist", "tfpdef", "suite", "stmt_dash",
  "test", "or_test", "and_test", "not_test", "comparison", "comp_op",
  "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr", "term",
  "factor", "power", "atom_expr", "trailerlist", "trailer", "atom",
  "arglist", "arglist_dash", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -175,    15,   101,  -175,  -175,  -175,   -16,  -175,  -175,   249,
      13,    29,   249,  -175,   249,  -175,   249,  -175,  -175,  -175,
     249,   257,   257,   249,   249,   257,  -175,  -175,  -175,   -28,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    22,
    -175,  -175,  -175,  -175,   324,   -39,    11,  -175,  -175,    37,
      -3,    27,   -47,   -40,    -1,  -175,  -175,     6,  -175,     8,
      23,    12,  -175,    32,    35,  -175,    38,  -175,    62,    39,
    -175,  -175,  -175,    45,  -175,  -175,   215,   249,    51,  -175,
      69,  -175,  -175,  -175,  -175,   249,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   249,  -175,  -175,  -175,   249,
     249,   249,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   -17,    10,  -175,   249,    52,    30,    60,   196,
     196,  -175,   249,  -175,  -175,    56,   196,  -175,    92,    94,
    -175,    11,  -175,    -3,    40,    27,   -47,   -40,   -40,    -1,
      -1,  -175,  -175,  -175,  -175,  -175,   249,    67,   249,  -175,
      63,  -175,    70,    71,    72,    64,    68,  -175,   249,  -175,
    -175,    95,  -175,  -175,  -175,  -175,   196,  -175,  -175,   249,
      99,  -175,    76,  -175,   196,   196,   249,  -175,    52,  -175,
      77,   154,    97,  -175,  -175,  -175,  -175,  -175,   119,  -175,
     196,  -175,     4,  -175,   249,  -175,  -175,  -175,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     2,    38,     0,    39,   130,     0,
       0,     0,     0,   128,     0,   129,     0,   125,     3,   126,
     134,     0,     0,     0,     0,     0,   127,     4,     6,     0,
      10,    11,    12,    35,    36,    37,    13,     7,    45,    54,
      48,    47,    46,    44,    18,    81,    82,    84,    87,     0,
      96,    98,   100,   102,   105,   108,   116,   117,   121,    62,
       0,     0,    43,    41,     0,    40,     0,   136,     0,   133,
     114,   115,    86,     0,   113,     8,     0,     0,     0,    49,
      53,    51,    28,    26,    34,     0,    31,    24,    27,    25,
      29,    23,    33,    32,    30,     0,    14,    17,    15,     0,
       0,     0,    91,    90,    92,    94,    89,    93,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,     0,    58,     0,    71,    68,     0,     0,
       0,   132,     0,   131,     9,     0,     0,    52,    20,    21,
      16,    83,    85,    97,    88,    99,   101,   103,   104,   107,
     106,   110,   112,   111,   109,   118,     0,     0,   134,   120,
       0,    61,     0,     0,    75,     0,    70,    73,     0,    65,
      42,     0,    77,    50,    64,   135,     0,    57,    19,     0,
       0,   124,     0,    60,     0,     0,     0,    69,     0,    67,
       0,     0,    56,    22,   123,   122,    59,    63,    74,    72,
       0,    80,     0,    55,     0,    66,    78,    79,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,  -174,    -2,  -175,    65,  -175,  -175,     1,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   -52,    66,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   -46,  -125,  -175,    -8,  -175,
      43,   -21,  -175,  -175,    34,    36,    41,    42,   -61,   -59,
     -12,  -175,  -175,  -175,  -175,  -175,   -11,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,   172,    29,    30,    31,    96,    97,
      98,    99,    32,    33,    34,    35,    36,    63,    37,    38,
      39,    79,    80,    81,    40,   162,   124,    41,    42,    43,
     190,   169,   127,   165,   166,   167,   173,   202,    44,    45,
      46,    47,    48,   110,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   122,   159,    58,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    60,    72,   113,    64,   174,    65,    75,    66,    70,
      71,   177,    67,    74,   115,     3,    73,   201,    59,   114,
     156,   206,   100,   116,     5,     6,     7,   157,   207,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    76,
      19,    20,   117,   158,   160,    77,    78,    61,   118,   101,
     161,   192,   147,   148,   119,   120,   149,   150,    21,   196,
     197,    22,    23,    62,    24,   111,   112,    25,   123,   135,
     121,   125,   126,    26,   128,   205,   129,   138,   131,   130,
     142,   132,   102,   103,   104,   133,   164,   139,   105,   106,
     107,   140,   136,    78,   170,   168,   108,   176,    85,   109,
     179,   181,   109,   183,   187,   151,   152,   153,   154,   155,
     188,   184,   185,   186,   191,   194,   195,   163,   200,     4,
      77,     5,     6,     7,   175,   204,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   178,
     203,   134,   199,   141,   144,   143,   137,   182,   180,     0,
      67,     0,   145,     0,   146,    21,     0,     0,    22,    23,
     189,    24,     0,     0,    25,     0,     0,     0,     0,     0,
      26,   193,     0,     0,     5,     6,     7,     0,   198,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    28,
      19,    20,     0,     0,     0,     0,   208,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,    22,    23,     0,    24,     0,     5,    25,     7,     0,
       0,     8,     0,    26,    11,     0,    13,    14,    15,     0,
      17,   171,    19,    20,     0,     5,     0,     7,     0,     0,
       8,     0,     0,    11,     0,    13,    14,    15,     0,    17,
      21,    19,    20,    22,    23,     0,    24,     0,     0,    25,
       0,     0,     0,     0,     0,    26,     0,     0,     0,    21,
       0,     0,    22,    23,     8,    24,     0,     0,    25,    13,
       0,    15,     8,    17,    26,    19,    20,    13,     0,    15,
       0,    17,     0,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    22,    23,     0,    24,
       0,    21,    25,     0,    22,     0,     0,    24,    26,     0,
      25,     0,     0,     0,     0,     0,    26,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
       2,     9,    23,    50,    12,   130,    14,    35,    16,    21,
      22,   136,    20,    25,    54,     0,    24,   191,    34,    66,
      37,    17,    61,    63,    20,    21,    22,    44,   202,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    67,
      36,    37,    43,    60,    34,    23,    24,    34,    49,    38,
      40,   176,   113,   114,    55,    56,   115,   116,    54,   184,
     185,    57,    58,    34,    60,    68,    39,    63,    60,    77,
      64,    48,    60,    69,    42,   200,    41,    85,    16,    41,
     101,    42,    45,    46,    47,    40,    34,    95,    51,    52,
      53,    99,    41,    24,    34,    65,    59,    41,     6,    62,
       6,    34,    62,    40,    40,   117,   118,   119,   120,   121,
      42,    41,    41,    41,    19,    16,    40,   125,    41,    18,
      23,    20,    21,    22,   132,     6,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   138,
     192,    76,   188,   100,   110,   109,    80,   158,   156,    -1,
     158,    -1,   111,    -1,   112,    54,    -1,    -1,    57,    58,
     168,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,   179,    -1,    -1,    20,    21,    22,    -1,   186,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   191,
      36,    37,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    60,    -1,    20,    63,    22,    -1,
      -1,    25,    -1,    69,    28,    -1,    30,    31,    32,    -1,
      34,    35,    36,    37,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    -1,    34,
      54,    36,    37,    57,    58,    -1,    60,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    25,    60,    -1,    -1,    63,    30,
      -1,    32,    25,    34,    69,    36,    37,    30,    -1,    32,
      -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,    60,
      -1,    54,    63,    -1,    57,    -1,    -1,    60,    69,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,    72,     0,    18,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    54,    57,    58,    60,    63,    69,    73,    74,    75,
      76,    77,    82,    83,    84,    85,    86,    88,    89,    90,
      94,    97,    98,    99,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   125,    34,
     108,    34,    34,    87,   108,   108,   108,   108,   126,   127,
     120,   120,   111,   108,   120,    35,    67,    23,    24,    91,
      92,    93,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    41,    78,    79,    80,    81,
      61,    38,    45,    46,    47,    51,    52,    53,    59,    62,
     113,    68,    39,    50,    66,    54,    63,    43,    49,    55,
      56,    64,   123,    60,    96,    48,    60,   102,    42,    41,
      41,    16,    42,    40,    76,   108,    41,    93,   108,   108,
     108,   110,   111,   115,   114,   116,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,    37,    44,    60,   124,
      34,    40,    95,   108,    34,   103,   104,   105,    65,   101,
      34,    35,    74,   106,   106,   108,    41,   106,    79,     6,
     108,    34,   126,    40,    41,    41,    41,    40,    42,   108,
     100,    19,   106,   108,    16,    40,   106,   106,   108,   105,
      41,    73,   107,    92,     6,   106,    17,    73,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    78,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    88,    88,    88,    89,
      90,    91,    91,    91,    91,    92,    92,    93,    95,    94,
      96,    96,    96,    97,    98,   100,    99,   101,   101,   102,
     103,   103,   104,   104,   105,   105,   105,   106,   106,   107,
     107,   108,   109,   109,   110,   110,   111,   111,   112,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   117,   118,   118,   118,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     2,     1,     2,     1,     0,     3,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     2,     1,     0,     5,     4,     3,     0,     6,
       3,     2,     0,     6,     4,     0,     7,     2,     0,     3,
       1,     0,     3,     1,     3,     1,     5,     1,     4,     2,
       1,     1,     1,     3,     1,     3,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     2,     2,     2,     1,     1,     3,     2,
       2,     0,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input_file: input_file_dash ENDMARKER  */
#line 221 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1473 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 232 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1481 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 236 "parser.y"
    {
        if ((yyvsp[-1].node) != NULL){
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("", SUITE_TYPE);
            if ((yyvsp[0].node)->node_type == STATEMENT_GROUP_TYPE){
                for (auto x: (yyvsp[0].node)->children){
                    appendChild((yyval.node), x);
                }
            }else{
                appendChild((yyval.node), (yyvsp[0].node));
            }
        }
    }
#line 1501 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 252 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1509 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 258 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1517 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 262 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1525 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 268 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1534 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt_dash ";" small_stmt  */
#line 275 "parser.y"
    {
        
        if ((yyvsp[-2].node)->node_type == STATEMENT_GROUP_TYPE){
            (yyval.node) = (yyvsp[-2].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("", STATEMENT_GROUP_TYPE);
            appendChild((yyval.node), (yyvsp[-2].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1550 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 287 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1558 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 294 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1567 "parser.tab.c"
    break;

  case 12: /* small_stmt: flow_stmt  */
#line 299 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1575 "parser.tab.c"
    break;

  case 13: /* small_stmt: global_stmt  */
#line 303 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1583 "parser.tab.c"
    break;

  case 14: /* expr_stmt: test expr_stmt_dash  */
#line 309 "parser.y"
    { 
        (yyval.node) = makeNode("EXPR_STATEMENT",STATEMENT_TYPE);
        struct type t;
        t.t = "void";
        (yyval.node)->type = t;
        if ((yyvsp[0].node) == NULL){
            appendChild((yyval.node), (yyvsp[-1].node));
        }else{
            appendChild((yyval.node), (yyvsp[0].node));
            insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
        }
        if ((yyvsp[0].node) == NULL){
            return 0;
        }

        symtable_entry* entry=NULL; 

        if((yyvsp[0].node)->lexeme == ":" || (yyvsp[0].node)->lexeme == ":="){
            DEBUG("here");
            if(curr_symtable_func!=NULL){
                DEBUG("Entered Add Function Entry" << curr_symtable_func);
                entry = curr_symtable_func->add_entry((yyvsp[0].node),yylineno);
                DEBUG("Exited Add Function Entry");
                (yyvsp[-1].node)->type = entry->type;
            }else if(curr_symtable_class!=NULL){
                entry = curr_symtable_class->add_attribute((yyvsp[0].node),yylineno);        
                (yyvsp[-1].node)->type = entry->type;
            }else{
                cout << "add global" << endl;
                entry = curr_symtable_global->add_global_var((yyvsp[0].node),yylineno);        
                (yyvsp[-1].node)->type = entry->type;
            }

            if((yyvsp[0].node)->children.size() == 3){
                checker_traverse((yyvsp[0].node)->children[2]);
                if (!type_equal((yyvsp[-1].node)->type, (yyvsp[0].node)->children[2]->type)){
                    Error::type_mismatch(yylineno, (yyvsp[-1].node)->type, (yyvsp[0].node)->children[2]->type, "initialization");
                }else{
                    if ((yyvsp[-1].node)->type.elems != -1){
                        (yyvsp[-1].node)->type.elems = (yyvsp[0].node)->children[2]->type.elems;
                    }
                }
            } 
        }
        else if ((yyvsp[0].node) != NULL){
            checker_traverse((yyvsp[0].node));
            if (type_equal((yyvsp[-1].node)->type, (yyvsp[0].node)->children[0]->type)){
                (yyval.node)->type = (yyvsp[-1].node)->type;
            }else{
                Error::type_mismatch(yylineno, (yyvsp[-1].node)->type, (yyvsp[0].node)->children[0]->type, "assignment");
            }
        }
        checker_traverse((yyvsp[-1].node));
    }
#line 1642 "parser.tab.c"
    break;

  case 15: /* expr_stmt_dash: annasign  */
#line 366 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1650 "parser.tab.c"
    break;

  case 16: /* expr_stmt_dash: augassign test  */
#line 370 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1659 "parser.tab.c"
    break;

  case 17: /* expr_stmt_dash: assign_dash  */
#line 375 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1667 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: %empty  */
#line 379 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1675 "parser.tab.c"
    break;

  case 19: /* assign_dash: "=" test assign_dash  */
#line 385 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
    }
#line 1685 "parser.tab.c"
    break;

  case 20: /* assign_dash: "=" test  */
#line 391 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1694 "parser.tab.c"
    break;

  case 21: /* annasign: ":" test  */
#line 398 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1703 "parser.tab.c"
    break;

  case 22: /* annasign: ":" test "=" test  */
#line 403 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1713 "parser.tab.c"
    break;

  case 23: /* augassign: "+="  */
#line 411 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1721 "parser.tab.c"
    break;

  case 24: /* augassign: "-="  */
#line 415 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1729 "parser.tab.c"
    break;

  case 25: /* augassign: "*="  */
#line 419 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1737 "parser.tab.c"
    break;

  case 26: /* augassign: "/="  */
#line 423 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1745 "parser.tab.c"
    break;

  case 27: /* augassign: "%="  */
#line 427 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1753 "parser.tab.c"
    break;

  case 28: /* augassign: "&="  */
#line 431 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1761 "parser.tab.c"
    break;

  case 29: /* augassign: "|="  */
#line 435 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1769 "parser.tab.c"
    break;

  case 30: /* augassign: "^="  */
#line 439 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1777 "parser.tab.c"
    break;

  case 31: /* augassign: "<<="  */
#line 443 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1785 "parser.tab.c"
    break;

  case 32: /* augassign: ">>="  */
#line 447 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1793 "parser.tab.c"
    break;

  case 33: /* augassign: "**="  */
#line 451 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1801 "parser.tab.c"
    break;

  case 34: /* augassign: "//="  */
#line 455 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1809 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 461 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1817 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 465 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1825 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 469 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1833 "parser.tab.c"
    break;

  case 38: /* break_stmt: "break"  */
#line 475 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
    }
#line 1841 "parser.tab.c"
    break;

  case 39: /* continue_stmt: "continue"  */
#line 481 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
    }
#line 1849 "parser.tab.c"
    break;

  case 40: /* return_stmt: "return" test  */
#line 487 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1858 "parser.tab.c"
    break;

  case 41: /* global_stmt: "global" NAME_dash  */
#line 494 "parser.y"
    {
        (yyval.node) = makeNode("global",STATEMENT_TYPE);
        if ((yyvsp[0].node)->node_type == MISC_TYPE){
            for (auto x: (yyvsp[0].node)->children){
                appendChild((yyval.node), x);
            }
        }else{
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1873 "parser.tab.c"
    break;

  case 42: /* NAME_dash: NAME_dash "," NAME  */
#line 507 "parser.y"
    {
        if ((yyvsp[-2].node)->node_type == MISC_TYPE){
            (yyval.node) = (yyvsp[-2].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("",MISC_TYPE);
            appendChild((yyval.node), (yyvsp[-2].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1888 "parser.tab.c"
    break;

  case 43: /* NAME_dash: NAME  */
#line 518 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1896 "parser.tab.c"
    break;

  case 44: /* compound_stmt: funcdef  */
#line 524 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1904 "parser.tab.c"
    break;

  case 45: /* compound_stmt: if_stmt  */
#line 528 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1912 "parser.tab.c"
    break;

  case 46: /* compound_stmt: while_stmt  */
#line 532 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1920 "parser.tab.c"
    break;

  case 47: /* compound_stmt: for_stmt  */
#line 536 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1928 "parser.tab.c"
    break;

  case 48: /* compound_stmt: classdef  */
#line 540 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1936 "parser.tab.c"
    break;

  case 49: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 546 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
        (yyval.node)->type.t = "void";
    }
#line 1948 "parser.tab.c"
    break;

  case 50: /* if_stmt_dash: "if" test ":" suite  */
#line 556 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1958 "parser.tab.c"
    break;

  case 51: /* else_stmt_dash: else_stmt  */
#line 564 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1966 "parser.tab.c"
    break;

  case 52: /* else_stmt_dash: elif_stmt else_stmt  */
#line 568 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1975 "parser.tab.c"
    break;

  case 53: /* else_stmt_dash: elif_stmt  */
#line 573 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1983 "parser.tab.c"
    break;

  case 54: /* else_stmt_dash: %empty  */
#line 576 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1991 "parser.tab.c"
    break;

  case 55: /* elif_stmt: "elif" test ":" suite elif_stmt  */
#line 582 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 2002 "parser.tab.c"
    break;

  case 56: /* elif_stmt: "elif" test ":" suite  */
#line 589 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2012 "parser.tab.c"
    break;

  case 57: /* else_stmt: "else" ":" suite  */
#line 597 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2021 "parser.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 603 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
    }
#line 2030 "parser.tab.c"
    break;

  case 59: /* classdef: "class" NAME inheritlist $@1 ":" suite  */
#line 607 "parser.y"
    {
        (yyval.node) = makeNode("",CLASS_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node), (yyvsp[-3].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));

        curr_symtable_class = NULL;

    }
#line 2046 "parser.tab.c"
    break;

  case 60: /* inheritlist: "(" NAME ")"  */
#line 621 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2054 "parser.tab.c"
    break;

  case 61: /* inheritlist: "(" ")"  */
#line 626 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2062 "parser.tab.c"
    break;

  case 62: /* inheritlist: %empty  */
#line 630 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2070 "parser.tab.c"
    break;

  case 63: /* for_stmt: "for" test "in" test ":" suite  */
#line 637 "parser.y"
    {   
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        if (!type_equal((yyvsp[-4].node)->type, int_node)){
            Error::other_semantic_error("TYPE_ERROR: Expected type int for iterator variable in for loop, got " + type_to_string((yyvsp[-4].node)->type), yylineno);
        }
    }
#line 2085 "parser.tab.c"
    break;

  case 64: /* while_stmt: "while" test ":" suite  */
#line 650 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        if (!type_equal((yyvsp[-2].node)->type, bool_node) && !type_equal((yyvsp[-2].node)->type, int_node)){
            Error::type_mismatch(yylineno, (yyvsp[-2].node)->type, bool_node, "while loop condition");
        }
    }
#line 2099 "parser.tab.c"
    break;

  case 65: /* $@2: %empty  */
#line 661 "parser.y"
                                             {
    curr_symtable_func  = new symtable_func((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node),yylineno); 
    if(curr_symtable_class != NULL){
        curr_symtable_class->add_func(curr_symtable_func);
    }else{
        DEBUG("Adding function to global sym tab");
        curr_symtable_global->add_func(curr_symtable_func);
        DEBUG("Added function to global sym tab");
    }
}
#line 2114 "parser.tab.c"
    break;

  case 66: /* funcdef: "def" NAME parameters funcdef_dash $@2 ":" suite  */
#line 670 "parser.y"
            {
        (yyval.node) = makeNode("def",FUNCTION_TYPE);
        appendChild((yyval.node),(yyvsp[-5].node));
        appendChild((yyval.node),(yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node),(yyvsp[-3].node));
        }

        appendChild((yyval.node), (yyvsp[0].node));

        (yyval.node)->type.t = "void";        
        curr_symtable_func = NULL;
    }
#line 2132 "parser.tab.c"
    break;

  case 67: /* funcdef_dash: "->" test  */
#line 686 "parser.y"
    {
        DEBUG((yyvsp[0].node)->lexeme);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2141 "parser.tab.c"
    break;

  case 68: /* funcdef_dash: %empty  */
#line 691 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
    }
#line 2149 "parser.tab.c"
    break;

  case 69: /* parameters: "(" parameters_dash ")"  */
#line 697 "parser.y"
    {
        DEBUG((yyvsp[-1].node));
        DEBUG("parameters" << (yyvsp[-1].node)->children.size());
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2159 "parser.tab.c"
    break;

  case 70: /* parameters_dash: typedargslist  */
#line 705 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2172 "parser.tab.c"
    break;

  case 71: /* parameters_dash: %empty  */
#line 714 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2180 "parser.tab.c"
    break;

  case 72: /* typedargslist: typedargslist "," tfpdef  */
#line 720 "parser.y"
    {
        if ((yyvsp[-2].node) != NULL && (yyvsp[-2].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[-2].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("parameters", PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[-2].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2195 "parser.tab.c"
    break;

  case 73: /* typedargslist: tfpdef  */
#line 731 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2203 "parser.tab.c"
    break;

  case 74: /* tfpdef: NAME ":" test  */
#line 737 "parser.y"
    {
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2213 "parser.tab.c"
    break;

  case 75: /* tfpdef: NAME  */
#line 744 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }
        }
    }
#line 2225 "parser.tab.c"
    break;

  case 76: /* tfpdef: NAME ":" test "=" test  */
#line 753 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2236 "parser.tab.c"
    break;

  case 77: /* suite: simple_stmt  */
#line 762 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2245 "parser.tab.c"
    break;

  case 78: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 767 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2256 "parser.tab.c"
    break;

  case 79: /* stmt_dash: stmt_dash stmt  */
#line 776 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2265 "parser.tab.c"
    break;

  case 80: /* stmt_dash: stmt  */
#line 781 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2274 "parser.tab.c"
    break;

  case 81: /* test: or_test  */
#line 788 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2282 "parser.tab.c"
    break;

  case 82: /* or_test: and_test  */
#line 794 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2290 "parser.tab.c"
    break;

  case 83: /* or_test: or_test "or" and_test  */
#line 798 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;

    
    }
#line 2308 "parser.tab.c"
    break;

  case 84: /* and_test: not_test  */
#line 814 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2316 "parser.tab.c"
    break;

  case 85: /* and_test: and_test "and" not_test  */
#line 818 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;

    
    }
#line 2333 "parser.tab.c"
    break;

  case 86: /* not_test: "not" not_test  */
#line 833 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,bool_node))))){
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"not");
        }        

        (yyval.node)->type = bool_node;

    }
#line 2349 "parser.tab.c"
    break;

  case 87: /* not_test: comparison  */
#line 845 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);

    }
#line 2358 "parser.tab.c"
    break;

  case 88: /* comparison: expr comp_op expr  */
#line 852 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;

    }
#line 2374 "parser.tab.c"
    break;

  case 89: /* comp_op: "<"  */
#line 865 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2382 "parser.tab.c"
    break;

  case 90: /* comp_op: ">"  */
#line 869 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2390 "parser.tab.c"
    break;

  case 91: /* comp_op: "=="  */
#line 873 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2398 "parser.tab.c"
    break;

  case 92: /* comp_op: ">="  */
#line 877 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2406 "parser.tab.c"
    break;

  case 93: /* comp_op: "<="  */
#line 881 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2414 "parser.tab.c"
    break;

  case 94: /* comp_op: "<>"  */
#line 885 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2422 "parser.tab.c"
    break;

  case 95: /* comp_op: "!="  */
#line 889 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2430 "parser.tab.c"
    break;

  case 96: /* expr: xor_expr  */
#line 895 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2438 "parser.tab.c"
    break;

  case 97: /* expr: expr "|" xor_expr  */
#line 899 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"|");
        }
        (yyval.node)->type = int_node;

    }
#line 2454 "parser.tab.c"
    break;

  case 98: /* xor_expr: and_expr  */
#line 913 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2462 "parser.tab.c"
    break;

  case 99: /* xor_expr: xor_expr "^" and_expr  */
#line 917 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"^");
        }
        (yyval.node)->type = int_node;

    
    }
#line 2479 "parser.tab.c"
    break;

  case 100: /* and_expr: shift_expr  */
#line 932 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2487 "parser.tab.c"
    break;

  case 101: /* and_expr: and_expr "&" shift_expr  */
#line 936 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"&");
        }
        (yyval.node)->type = int_node;


    }
#line 2504 "parser.tab.c"
    break;

  case 102: /* shift_expr: arith_expr  */
#line 951 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2512 "parser.tab.c"
    break;

  case 103: /* shift_expr: shift_expr "<<" arith_expr  */
#line 955 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"<<");
        }
        (yyval.node)->type = int_node;

    }
#line 2528 "parser.tab.c"
    break;

  case 104: /* shift_expr: shift_expr ">>" arith_expr  */
#line 967 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,">>");
        }
        (yyval.node)->type = int_node;


    
    }
#line 2546 "parser.tab.c"
    break;

  case 105: /* arith_expr: term  */
#line 983 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2554 "parser.tab.c"
    break;

  case 106: /* arith_expr: arith_expr "+" term  */
#line 987 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"+");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);

    }
#line 2570 "parser.tab.c"
    break;

  case 107: /* arith_expr: arith_expr "-" term  */
#line 999 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"-");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);

    
    }
#line 2587 "parser.tab.c"
    break;

  case 108: /* term: factor  */
#line 1014 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2595 "parser.tab.c"
    break;

  case 109: /* term: term "*" factor  */
#line 1018 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"*");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);


    }
#line 2612 "parser.tab.c"
    break;

  case 110: /* term: term "/" factor  */
#line 1031 "parser.y"
    {   
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"/");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);

    
    }
#line 2629 "parser.tab.c"
    break;

  case 111: /* term: term "%" factor  */
#line 1044 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"%");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    }
#line 2644 "parser.tab.c"
    break;

  case 112: /* term: term "//" factor  */
#line 1055 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"//");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);


    }
#line 2661 "parser.tab.c"
    break;

  case 113: /* factor: "+" factor  */
#line 1070 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"+");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;

    }
#line 2676 "parser.tab.c"
    break;

  case 114: /* factor: "-" factor  */
#line 1081 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"-");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 2690 "parser.tab.c"
    break;

  case 115: /* factor: "~" factor  */
#line 1091 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node))))){
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"~");
        }        

        (yyval.node)->type = int_node;

        
    }
#line 2707 "parser.tab.c"
    break;

  case 116: /* factor: power  */
#line 1104 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        
    }
#line 2716 "parser.tab.c"
    break;

  case 117: /* power: atom_expr  */
#line 1111 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2724 "parser.tab.c"
    break;

  case 118: /* power: atom_expr "**" factor  */
#line 1115 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"**");
        }
        
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    }
#line 2739 "parser.tab.c"
    break;

  case 119: /* atom_expr: atom trailerlist  */
#line 1128 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
        }else{
            (yyval.node) = makeNode("atom_expr", EXPR_TYPE);
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
            struct type temp = (yyvsp[-1].node)->type;
            for (int i = 0; i < (yyvsp[0].node)->children.size(); i++){
                if ((yyvsp[0].node)->node_type == TRAILER_TYPE){
                    if ((yyvsp[0].node)->children[i]->lexeme == "()" && i == 0){
                        // function call
                        if ((yyvsp[-1].node)->node_type != NAME_TYPE){
                            Error::other_semantic_error("TYPE_ERROR: Invalid operation ()", yylineno);
                        }else{
                            string func_id = (yyvsp[-1].node)->lexeme;
                            for (auto x: (yyvsp[0].node)->children[i]->children){
                                func_id += "@" + type_to_string(x->type);
                            }
                            struct type ret = string_to_type(func_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No declaration of function " + (yyvsp[-1].node)->lexeme+ " with these parameter types, called ", yylineno);
                            }else{
                                temp = ret;
                            }   
                    }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "[]"){
                        // list indexing
                        if (temp.elems != -1){
                            if (!type_equal((yyvsp[0].node)->children[i]->children[0]->type, int_node)){
                                temp.elems = -1;
                            }else{
                                Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string((yyvsp[0].node)->children[i]->children[0]->type), yylineno);
                            }
                        }else{
                            Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                        }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "."){
                        if (i + 1 < (yyvsp[0].node)->children.size() && (yyvsp[0].node)->children[i+1]->lexeme == "()"){
                            // method call
                            string class_id = type_to_string(temp);
                            class_id += "." + (yyvsp[0].node)->children[i]->children[0]->lexeme;
                            for (auto x: (yyvsp[0].node)->children[i+1]->children){
                                class_id += "@" + type_to_string(x->type);
                            }
                            struct type ret = string_to_type(class_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No such method with given parameter types in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }
                        }else{
                            // attribute access
                            string class_id = type_to_string(temp);
                            class_id += "." + (yyvsp[0].node)->children[i]->children[0]->lexeme;
                            struct type ret = string_to_type(class_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No declaration of attribute " + (yyvsp[0].node)->children[i]->children[0]->lexeme + " in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }
                        }
                    }else{
                        Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + (yyvsp[0].node)->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            (yyval.node)->type = temp;
        }
    }
#line 2814 "parser.tab.c"
    break;

  case 120: /* trailerlist: trailerlist trailer  */
#line 1201 "parser.y"
    {
        if ((yyval.node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2828 "parser.tab.c"
    break;

  case 121: /* trailerlist: %empty  */
#line 1211 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2836 "parser.tab.c"
    break;

  case 122: /* trailer: "(" arglist ")"  */
#line 1216 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2849 "parser.tab.c"
    break;

  case 123: /* trailer: "[" test "]"  */
#line 1225 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2858 "parser.tab.c"
    break;

  case 124: /* trailer: "." NAME  */
#line 1230 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2867 "parser.tab.c"
    break;

  case 125: /* atom: NAME  */
#line 1237 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
        (yyval.node)->type = string_to_type((yyvsp[0].node)->lexeme);
    }
#line 2876 "parser.tab.c"
    break;

  case 126: /* atom: NUMBER  */
#line 1242 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NUMBER_TYPE);
        int isnot_int = 0;
        for (auto c: (yyvsp[0].node)->lexeme){
            if (!isdigit(c)){
                isnot_int = 1;
                break;
            }
        }
        if (isnot_int){
            (yyval.node)->type.t = "float";
        }else{
            (yyval.node)->type.t = "int";
        }
    }
#line 2896 "parser.tab.c"
    break;

  case 127: /* atom: STRING  */
#line 1258 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
        (yyval.node)->type.t = "str";
    }
#line 2905 "parser.tab.c"
    break;

  case 128: /* atom: "None"  */
#line 1263 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
        (yyval.node)->type.t = "void";
    }
#line 2914 "parser.tab.c"
    break;

  case 129: /* atom: "True"  */
#line 1268 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 2923 "parser.tab.c"
    break;

  case 130: /* atom: "False"  */
#line 1273 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 2932 "parser.tab.c"
    break;

  case 131: /* atom: "(" test ")"  */
#line 1278 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2940 "parser.tab.c"
    break;

  case 132: /* atom: "[" arglist "]"  */
#line 1282 "parser.y"
    {
        (yyval.node) = makeNode("[]", LIST_TYPE);
        (yyval.node)->type.t = (yyvsp[-1].node) == NULL? "void": (yyvsp[-1].node)->type.t;
        (yyval.node)->type.elems = (yyvsp[-1].node) == NULL? 0: (yyvsp[-1].node)->children.size();
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2955 "parser.tab.c"
    break;

  case 133: /* arglist: arglist_dash  */
#line 1295 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2963 "parser.tab.c"
    break;

  case 134: /* arglist: %empty  */
#line 1299 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2971 "parser.tab.c"
    break;

  case 135: /* arglist_dash: arglist_dash "," test  */
#line 1305 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
        if (!type_equal((yyvsp[-2].node)->type,(yyvsp[0].node)->type)){
            Error::type_mismatch(yylineno, (yyvsp[-2].node)->type, (yyvsp[0].node)->type, ",");
        }else{
            (yyval.node)->type = (yyvsp[-2].node)->type;
        }
    }
#line 2985 "parser.tab.c"
    break;

  case 136: /* arglist_dash: test  */
#line 1315 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 2995 "parser.tab.c"
    break;


#line 2999 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1323 "parser.y"

void printAST(char * filename){
    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        cerr << "Error opening file" << endl;
        return;
    }
    fprintf(file, "digraph G {\n");
    for (auto it = id_to_label.begin(); it != id_to_label.end(); it++){
        string quoted = "";
        for (auto c: it->second){
            if (c == '\"'){
                quoted += "\\\"";
            }else if (c == '\\'){
                quoted += "\\\\";
            }else{
                quoted += c;
            }
        }
        fprintf(file, "%s [label=\"%s\"]\n", it->first.c_str(), quoted.c_str());
    }
    for (auto it = edges.begin(); it != edges.end(); it++){
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++){
            fprintf(file, "%s -> %s\n", it->first.c_str(), jt->c_str());
        }
    }
    fprintf(file, "}\n");
    return;
}
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
    int outputfilearg = -1; 
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
        }else if (arg == "-output"){
            if (i+1 < argc){
                outputfilearg = i+1;
                i++;
            }else{
                print_help = 1;
            }
        }else if (arg == "-verbose"){
            verbose = 1;
        }else {
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

    // string temp_name = "Hello";
    // vector<symtable_entry *> temp_params;
    // current_func = new symtable_func(temp_name, temp_params);

    int_node.t = "int";
    float_node.t = "float";
    bool_node.t = "bool";
    str_node.t = "str";
    void_node.t = "void";



    global_symtable = new symtable_global();
    curr_symtable_global = global_symtable;
    yyparse();
    DEBUG("Reached before csv creation");
    curr_symtable_global->create_csv("sample.csv");
    printTree(root);
    if (verbose){
        if (terminated){
            cout << "Error in parsing, AST generated might be incomplete/erroneous" << endl;
        }else{
            cout << "Parsing complete without errors, printing abstract syntax tree" << endl;
        }
    }
    if (outputfilearg == -1){
        printAST(default_output_name);
        if (verbose){
            cout << "AST written in file: " << default_output_name << endl;
        }
    }else{
        printAST(argv[outputfilearg]);
        if (verbose){
            cout << "AST written in file: " << argv[outputfilearg] << endl;
        }
    }

    fclose(yyin);

    return 0;
}

int yyerror(const char* msg) {
    if (terminated){
        return 0;
    }
    terminated = 1;
    if (last_token == "INDENT"){
        cout << "SYNTAX ERROR: Unexpected indent at line " << yylineno << endl;
    }else if (last_token == "DEDENT"){
        cout << "SYNTAX ERROR: Unexpected dedent at line " << yylineno << endl;
    }else if (last_token == "NEWLINE"){
        cout << "SYNTAX ERROR: Unexpected line break at line " << yylineno << endl;
    }else if (last_token == "NUMBER"){
        cout << "SYNTAX ERROR: Unexpected number: " << last_token_value << " at line " << yylineno << endl;
    }else if (last_token == "STRING"){
        cout << "SYNTAX ERROR: Unexpected string literal: " << last_token_value << " at line " << yylineno << endl;
    }else if (last_token == "NAME"){
        cout << "SYNTAX ERROR: Unexpected identifier: " << last_token_value << " at line " << yylineno << endl;
    }else{
        cout << "SYNTAX ERROR: Unexpected token: " << last_token << " at line " << yylineno << endl;
    }
    return 0;
}
