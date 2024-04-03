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

TreeNode * root = NULL;


#line 131 "parser.tab.c"

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
#define YYNRULES  137
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
       0,   195,   195,   205,   209,   226,   231,   235,   241,   248,
     260,   267,   272,   276,   282,   326,   330,   335,   340,   345,
     351,   358,   363,   371,   375,   379,   383,   387,   391,   395,
     399,   403,   407,   411,   415,   421,   425,   429,   435,   441,
     447,   454,   467,   478,   484,   488,   492,   496,   500,   506,
     515,   523,   527,   532,   536,   541,   548,   556,   563,   563,
     580,   585,   590,   596,   605,   613,   613,   637,   643,   648,
     656,   666,   671,   682,   688,   695,   704,   713,   718,   727,
     732,   739,   745,   749,   757,   761,   769,   774,   780,   786,
     792,   796,   800,   804,   808,   812,   816,   822,   826,   834,
     838,   846,   850,   858,   862,   868,   876,   880,   886,   894,
     898,   904,   910,   916,   924,   930,   935,   941,   948,   952,
     963,  1009,  1020,  1024,  1033,  1038,  1045,  1050,  1066,  1071,
    1076,  1081,  1086,  1090,  1103,  1108,  1113,  1123
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
    -175,  -175,  -175,  -175,   324,   -39,    11,  -175,    37,     3,
       0,    27,   -47,   -40,    -1,  -175,  -175,     6,  -175,    12,
      23,    14,  -175,    34,    38,  -175,    40,  -175,    62,    43,
    -175,  -175,  -175,    46,  -175,  -175,   215,   249,    51,  -175,
      69,  -175,  -175,  -175,  -175,   249,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   249,  -175,  -175,  -175,   249,
     249,   249,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   -17,    10,  -175,   249,    60,    30,    63,   196,
     196,  -175,   249,  -175,  -175,    57,   196,  -175,    93,    94,
    -175,    11,  -175,     3,     0,    27,   -47,   -40,   -40,    -1,
      -1,  -175,  -175,  -175,  -175,  -175,   249,    67,   249,  -175,
      64,  -175,    61,    70,    71,    73,    68,  -175,   249,  -175,
    -175,    84,  -175,  -175,  -175,  -175,   196,  -175,  -175,   249,
      98,  -175,    75,  -175,   196,   196,   249,  -175,    60,  -175,
      77,   154,    97,  -175,  -175,  -175,  -175,  -175,   110,  -175,
     196,  -175,     4,  -175,   249,  -175,  -175,  -175,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     2,    38,     0,    39,   131,     0,
       0,     0,     0,   129,     0,   130,     0,   126,     3,   127,
     135,     0,     0,     0,     0,     0,   128,     4,     6,     0,
      10,    11,    12,    35,    36,    37,    13,     7,    45,    54,
      48,    47,    46,    44,    18,    81,    82,    84,    87,    89,
      97,    99,   101,   103,   106,   109,   117,   118,   122,    62,
       0,     0,    43,    41,     0,    40,     0,   137,     0,   134,
     115,   116,    86,     0,   114,     8,     0,     0,     0,    49,
      53,    51,    28,    26,    34,     0,    31,    24,    27,    25,
      29,    23,    33,    32,    30,     0,    14,    17,    15,     0,
       0,     0,    92,    91,    93,    95,    90,    94,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,     0,    58,     0,    71,    68,     0,     0,
       0,   133,     0,   132,     9,     0,     0,    52,    20,    21,
      16,    83,    85,    88,    98,   100,   102,   104,   105,   108,
     107,   111,   113,   112,   110,   119,     0,     0,   135,   121,
       0,    61,     0,     0,    75,     0,    70,    73,     0,    65,
      42,     0,    77,    50,    64,   136,     0,    57,    19,     0,
       0,   125,     0,    60,     0,     0,     0,    69,     0,    67,
       0,     0,    56,    22,   124,   123,    59,    63,    74,    72,
       0,    80,     0,    55,     0,    66,    78,    79,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,  -174,    -2,  -175,    49,  -175,  -175,     1,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   -52,    65,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   -46,  -125,  -175,    -8,  -175,
      41,   -21,  -175,  -175,    35,    33,    36,    39,   -61,   -59,
     -12,  -175,  -175,  -175,  -175,  -175,    -9,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,   172,    29,    30,    31,    96,    97,
      98,    99,    32,    33,    34,    35,    36,    63,    37,    38,
      39,    79,    80,    81,    40,   162,   124,    41,    42,    43,
     190,   169,   127,   165,   166,   167,   173,   202,    44,    45,
      46,    47,    48,   109,    49,    50,    51,    52,    53,    54,
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
     197,    22,    23,    62,    24,   110,   112,    25,   111,   135,
     121,   125,   123,    26,   126,   205,   128,   138,   131,   129,
     142,   130,   102,   103,   104,   132,   133,   139,   105,   106,
     107,   140,   136,    78,   164,   168,   108,   170,   176,    85,
     179,   181,   184,   191,   183,   151,   152,   153,   154,   155,
     188,   185,   186,   187,   194,   195,   204,   163,   200,     4,
      77,     5,     6,     7,   175,   134,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   178,
     203,   141,   199,   144,   143,   137,     0,   145,   180,   182,
      67,   146,     0,     0,     0,    21,     0,     0,    22,    23,
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
     185,    57,    58,    34,    60,    62,    39,    63,    68,    77,
      64,    48,    60,    69,    60,   200,    42,    85,    16,    41,
     101,    41,    45,    46,    47,    42,    40,    95,    51,    52,
      53,    99,    41,    24,    34,    65,    59,    34,    41,     6,
       6,    34,    41,    19,    40,   117,   118,   119,   120,   121,
      42,    41,    41,    40,    16,    40,     6,   125,    41,    18,
      23,    20,    21,    22,   132,    76,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   138,
     192,   100,   188,   110,   109,    80,    -1,   111,   156,   158,
     158,   112,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
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
      61,    38,    45,    46,    47,    51,    52,    53,    59,   113,
      62,    68,    39,    50,    66,    54,    63,    43,    49,    55,
      56,    64,   123,    60,    96,    48,    60,   102,    42,    41,
      41,    16,    42,    40,    76,   108,    41,    93,   108,   108,
     108,   110,   111,   114,   115,   116,   117,   118,   118,   119,
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
     107,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   118,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   121,   121,
     122,   123,   123,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   127,   127
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     3,
       2,     2,     0,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     0,     3,     1
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
#line 195 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1447 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 206 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1455 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 210 "parser.y"
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
#line 1475 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 226 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1483 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 232 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1491 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 236 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1499 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 242 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1508 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt_dash ";" small_stmt  */
#line 249 "parser.y"
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
#line 1524 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 261 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1532 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 268 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1541 "parser.tab.c"
    break;

  case 12: /* small_stmt: flow_stmt  */
#line 273 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1549 "parser.tab.c"
    break;

  case 13: /* small_stmt: global_stmt  */
#line 277 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1557 "parser.tab.c"
    break;

  case 14: /* expr_stmt: test expr_stmt_dash  */
#line 283 "parser.y"
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
            }else if(curr_symtable_class!=NULL){
                entry = curr_symtable_class->add_attribute((yyvsp[0].node),yylineno);        
            }else{
                cout << "add global" << endl;
                entry = curr_symtable_global->add_global_var((yyvsp[0].node),yylineno);        
            }

            if((yyvsp[0].node)->children.size()>2){
                for(int i = 2;i<(yyvsp[0].node)->children.size();i++){
                checker_traverse((yyvsp[0].node)->children[i]);
                }
            } 
        }
        else{
            checker_traverse((yyvsp[-1].node));
            checker_traverse((yyvsp[0].node));
        }
    }
#line 1603 "parser.tab.c"
    break;

  case 15: /* expr_stmt_dash: annasign  */
#line 327 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1611 "parser.tab.c"
    break;

  case 16: /* expr_stmt_dash: augassign test  */
#line 331 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1620 "parser.tab.c"
    break;

  case 17: /* expr_stmt_dash: assign_dash  */
#line 336 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1628 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: %empty  */
#line 340 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1636 "parser.tab.c"
    break;

  case 19: /* assign_dash: "=" test assign_dash  */
#line 346 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
    }
#line 1646 "parser.tab.c"
    break;

  case 20: /* assign_dash: "=" test  */
#line 352 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1655 "parser.tab.c"
    break;

  case 21: /* annasign: ":" test  */
#line 359 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1664 "parser.tab.c"
    break;

  case 22: /* annasign: ":" test "=" test  */
#line 364 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1674 "parser.tab.c"
    break;

  case 23: /* augassign: "+="  */
#line 372 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1682 "parser.tab.c"
    break;

  case 24: /* augassign: "-="  */
#line 376 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1690 "parser.tab.c"
    break;

  case 25: /* augassign: "*="  */
#line 380 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1698 "parser.tab.c"
    break;

  case 26: /* augassign: "/="  */
#line 384 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1706 "parser.tab.c"
    break;

  case 27: /* augassign: "%="  */
#line 388 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1714 "parser.tab.c"
    break;

  case 28: /* augassign: "&="  */
#line 392 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1722 "parser.tab.c"
    break;

  case 29: /* augassign: "|="  */
#line 396 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1730 "parser.tab.c"
    break;

  case 30: /* augassign: "^="  */
#line 400 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1738 "parser.tab.c"
    break;

  case 31: /* augassign: "<<="  */
#line 404 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1746 "parser.tab.c"
    break;

  case 32: /* augassign: ">>="  */
#line 408 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1754 "parser.tab.c"
    break;

  case 33: /* augassign: "**="  */
#line 412 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1762 "parser.tab.c"
    break;

  case 34: /* augassign: "//="  */
#line 416 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1770 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 422 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1778 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 426 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1786 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 430 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1794 "parser.tab.c"
    break;

  case 38: /* break_stmt: "break"  */
#line 436 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
    }
#line 1802 "parser.tab.c"
    break;

  case 39: /* continue_stmt: "continue"  */
#line 442 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
    }
#line 1810 "parser.tab.c"
    break;

  case 40: /* return_stmt: "return" test  */
#line 448 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1819 "parser.tab.c"
    break;

  case 41: /* global_stmt: "global" NAME_dash  */
#line 455 "parser.y"
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
#line 1834 "parser.tab.c"
    break;

  case 42: /* NAME_dash: NAME_dash "," NAME  */
#line 468 "parser.y"
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
#line 1849 "parser.tab.c"
    break;

  case 43: /* NAME_dash: NAME  */
#line 479 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1857 "parser.tab.c"
    break;

  case 44: /* compound_stmt: funcdef  */
#line 485 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1865 "parser.tab.c"
    break;

  case 45: /* compound_stmt: if_stmt  */
#line 489 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1873 "parser.tab.c"
    break;

  case 46: /* compound_stmt: while_stmt  */
#line 493 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1881 "parser.tab.c"
    break;

  case 47: /* compound_stmt: for_stmt  */
#line 497 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1889 "parser.tab.c"
    break;

  case 48: /* compound_stmt: classdef  */
#line 501 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1897 "parser.tab.c"
    break;

  case 49: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 507 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1908 "parser.tab.c"
    break;

  case 50: /* if_stmt_dash: "if" test ":" suite  */
#line 516 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1918 "parser.tab.c"
    break;

  case 51: /* else_stmt_dash: else_stmt  */
#line 524 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1926 "parser.tab.c"
    break;

  case 52: /* else_stmt_dash: elif_stmt else_stmt  */
#line 528 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1935 "parser.tab.c"
    break;

  case 53: /* else_stmt_dash: elif_stmt  */
#line 533 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1943 "parser.tab.c"
    break;

  case 54: /* else_stmt_dash: %empty  */
#line 536 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1951 "parser.tab.c"
    break;

  case 55: /* elif_stmt: "elif" test ":" suite elif_stmt  */
#line 542 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 1962 "parser.tab.c"
    break;

  case 56: /* elif_stmt: "elif" test ":" suite  */
#line 549 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1972 "parser.tab.c"
    break;

  case 57: /* else_stmt: "else" ":" suite  */
#line 557 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1981 "parser.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 563 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
    }
#line 1990 "parser.tab.c"
    break;

  case 59: /* classdef: "class" NAME inheritlist $@1 ":" suite  */
#line 567 "parser.y"
    {
        (yyval.node) = makeNode("",CLASS_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node), (yyvsp[-3].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));

        curr_symtable_class = NULL;

    }
#line 2006 "parser.tab.c"
    break;

  case 60: /* inheritlist: "(" NAME ")"  */
#line 581 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2014 "parser.tab.c"
    break;

  case 61: /* inheritlist: "(" ")"  */
#line 586 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2022 "parser.tab.c"
    break;

  case 62: /* inheritlist: %empty  */
#line 590 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2030 "parser.tab.c"
    break;

  case 63: /* for_stmt: "for" test "in" test ":" suite  */
#line 597 "parser.y"
    {   
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2041 "parser.tab.c"
    break;

  case 64: /* while_stmt: "while" test ":" suite  */
#line 606 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2051 "parser.tab.c"
    break;

  case 65: /* $@2: %empty  */
#line 613 "parser.y"
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
#line 2066 "parser.tab.c"
    break;

  case 66: /* funcdef: "def" NAME parameters funcdef_dash $@2 ":" suite  */
#line 622 "parser.y"
            {
        (yyval.node) = makeNode("def",FUNCTION_TYPE);
        appendChild((yyval.node),(yyvsp[-5].node));
        appendChild((yyval.node),(yyvsp[-4].node));
        appendChild((yyval.node),(yyvsp[-3].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node),(yyvsp[-3].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));
        

        curr_symtable_func = NULL;
    }
#line 2084 "parser.tab.c"
    break;

  case 67: /* funcdef_dash: "->" test  */
#line 638 "parser.y"
    {
        DEBUG((yyvsp[0].node)->lexeme);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2093 "parser.tab.c"
    break;

  case 68: /* funcdef_dash: %empty  */
#line 643 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2101 "parser.tab.c"
    break;

  case 69: /* parameters: "(" parameters_dash ")"  */
#line 649 "parser.y"
    {
        DEBUG((yyvsp[-1].node));
        DEBUG("parameters" << (yyvsp[-1].node)->children.size());
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2111 "parser.tab.c"
    break;

  case 70: /* parameters_dash: typedargslist  */
#line 657 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2124 "parser.tab.c"
    break;

  case 71: /* parameters_dash: %empty  */
#line 666 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2132 "parser.tab.c"
    break;

  case 72: /* typedargslist: typedargslist "," tfpdef  */
#line 672 "parser.y"
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
#line 2147 "parser.tab.c"
    break;

  case 73: /* typedargslist: tfpdef  */
#line 683 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2155 "parser.tab.c"
    break;

  case 74: /* tfpdef: NAME ":" test  */
#line 689 "parser.y"
    {
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2165 "parser.tab.c"
    break;

  case 75: /* tfpdef: NAME  */
#line 696 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }
        }
    }
#line 2177 "parser.tab.c"
    break;

  case 76: /* tfpdef: NAME ":" test "=" test  */
#line 705 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2188 "parser.tab.c"
    break;

  case 77: /* suite: simple_stmt  */
#line 714 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2197 "parser.tab.c"
    break;

  case 78: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 719 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2208 "parser.tab.c"
    break;

  case 79: /* stmt_dash: stmt_dash stmt  */
#line 728 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2217 "parser.tab.c"
    break;

  case 80: /* stmt_dash: stmt  */
#line 733 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2226 "parser.tab.c"
    break;

  case 81: /* test: or_test  */
#line 740 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2234 "parser.tab.c"
    break;

  case 82: /* or_test: and_test  */
#line 746 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2242 "parser.tab.c"
    break;

  case 83: /* or_test: or_test "or" and_test  */
#line 750 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2252 "parser.tab.c"
    break;

  case 84: /* and_test: not_test  */
#line 758 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2260 "parser.tab.c"
    break;

  case 85: /* and_test: and_test "and" not_test  */
#line 762 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2270 "parser.tab.c"
    break;

  case 86: /* not_test: "not" not_test  */
#line 770 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2279 "parser.tab.c"
    break;

  case 87: /* not_test: comparison  */
#line 775 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2287 "parser.tab.c"
    break;

  case 88: /* comparison: comparison comp_op expr  */
#line 781 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2297 "parser.tab.c"
    break;

  case 89: /* comparison: expr  */
#line 787 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2305 "parser.tab.c"
    break;

  case 90: /* comp_op: "<"  */
#line 793 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2313 "parser.tab.c"
    break;

  case 91: /* comp_op: ">"  */
#line 797 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2321 "parser.tab.c"
    break;

  case 92: /* comp_op: "=="  */
#line 801 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2329 "parser.tab.c"
    break;

  case 93: /* comp_op: ">="  */
#line 805 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2337 "parser.tab.c"
    break;

  case 94: /* comp_op: "<="  */
#line 809 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2345 "parser.tab.c"
    break;

  case 95: /* comp_op: "<>"  */
#line 813 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2353 "parser.tab.c"
    break;

  case 96: /* comp_op: "!="  */
#line 817 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2361 "parser.tab.c"
    break;

  case 97: /* expr: xor_expr  */
#line 823 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2369 "parser.tab.c"
    break;

  case 98: /* expr: expr "|" xor_expr  */
#line 827 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2379 "parser.tab.c"
    break;

  case 99: /* xor_expr: and_expr  */
#line 835 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2387 "parser.tab.c"
    break;

  case 100: /* xor_expr: xor_expr "^" and_expr  */
#line 839 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2397 "parser.tab.c"
    break;

  case 101: /* and_expr: shift_expr  */
#line 847 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2405 "parser.tab.c"
    break;

  case 102: /* and_expr: and_expr "&" shift_expr  */
#line 851 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2415 "parser.tab.c"
    break;

  case 103: /* shift_expr: arith_expr  */
#line 859 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2423 "parser.tab.c"
    break;

  case 104: /* shift_expr: shift_expr "<<" arith_expr  */
#line 863 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2433 "parser.tab.c"
    break;

  case 105: /* shift_expr: shift_expr ">>" arith_expr  */
#line 869 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2443 "parser.tab.c"
    break;

  case 106: /* arith_expr: term  */
#line 877 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2451 "parser.tab.c"
    break;

  case 107: /* arith_expr: arith_expr "+" term  */
#line 881 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2461 "parser.tab.c"
    break;

  case 108: /* arith_expr: arith_expr "-" term  */
#line 887 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2471 "parser.tab.c"
    break;

  case 109: /* term: factor  */
#line 895 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2479 "parser.tab.c"
    break;

  case 110: /* term: term "*" factor  */
#line 899 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2489 "parser.tab.c"
    break;

  case 111: /* term: term "/" factor  */
#line 905 "parser.y"
    {   
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2499 "parser.tab.c"
    break;

  case 112: /* term: term "%" factor  */
#line 911 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2509 "parser.tab.c"
    break;

  case 113: /* term: term "//" factor  */
#line 917 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2519 "parser.tab.c"
    break;

  case 114: /* factor: "+" factor  */
#line 925 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
           
    }
#line 2529 "parser.tab.c"
    break;

  case 115: /* factor: "-" factor  */
#line 931 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2538 "parser.tab.c"
    break;

  case 116: /* factor: "~" factor  */
#line 936 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        
    }
#line 2548 "parser.tab.c"
    break;

  case 117: /* factor: power  */
#line 942 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        
    }
#line 2557 "parser.tab.c"
    break;

  case 118: /* power: atom_expr  */
#line 949 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2565 "parser.tab.c"
    break;

  case 119: /* power: atom_expr "**" factor  */
#line 953 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"**");
        }
    }
#line 2578 "parser.tab.c"
    break;

  case 120: /* atom_expr: atom trailerlist  */
#line 964 "parser.y"
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
                        
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "."){
                        if (i + 1 < (yyvsp[0].node)->children.size() && (yyvsp[0].node)->children[i+1]->lexeme == "()"){
                            // method call
                        }else{
                            // attribute access
                        }
                    }else{
                        Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + (yyvsp[0].node)->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            (yyval.node)->type = temp;
        }
    }
#line 2626 "parser.tab.c"
    break;

  case 121: /* trailerlist: trailerlist trailer  */
#line 1010 "parser.y"
    {
        if ((yyval.node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2640 "parser.tab.c"
    break;

  case 122: /* trailerlist: %empty  */
#line 1020 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2648 "parser.tab.c"
    break;

  case 123: /* trailer: "(" arglist ")"  */
#line 1025 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2661 "parser.tab.c"
    break;

  case 124: /* trailer: "[" test "]"  */
#line 1034 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2670 "parser.tab.c"
    break;

  case 125: /* trailer: "." NAME  */
#line 1039 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2679 "parser.tab.c"
    break;

  case 126: /* atom: NAME  */
#line 1046 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
        (yyval.node)->type = string_to_type((yyvsp[0].node)->lexeme);
    }
#line 2688 "parser.tab.c"
    break;

  case 127: /* atom: NUMBER  */
#line 1051 "parser.y"
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
#line 2708 "parser.tab.c"
    break;

  case 128: /* atom: STRING  */
#line 1067 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
        (yyval.node)->type.t = "str";
    }
#line 2717 "parser.tab.c"
    break;

  case 129: /* atom: "None"  */
#line 1072 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type.t = "void";
    }
#line 2726 "parser.tab.c"
    break;

  case 130: /* atom: "True"  */
#line 1077 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 2735 "parser.tab.c"
    break;

  case 131: /* atom: "False"  */
#line 1082 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 2744 "parser.tab.c"
    break;

  case 132: /* atom: "(" test ")"  */
#line 1087 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2752 "parser.tab.c"
    break;

  case 133: /* atom: "[" arglist "]"  */
#line 1091 "parser.y"
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
#line 2767 "parser.tab.c"
    break;

  case 134: /* arglist: arglist_dash  */
#line 1104 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2775 "parser.tab.c"
    break;

  case 135: /* arglist: %empty  */
#line 1108 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2783 "parser.tab.c"
    break;

  case 136: /* arglist_dash: arglist_dash "," test  */
#line 1114 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
        if (!type_equal((yyvsp[-2].node)->type,(yyvsp[0].node)->type)){
            Error::type_mismatch(yylineno, (yyvsp[-2].node)->type, (yyvsp[0].node)->type, ",");
        }else{
            (yyval.node)->type = (yyvsp[-2].node)->type;
        }
    }
#line 2797 "parser.tab.c"
    break;

  case 137: /* arglist_dash: test  */
#line 1124 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 2807 "parser.tab.c"
    break;


#line 2811 "parser.tab.c"

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

#line 1132 "parser.y"

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
