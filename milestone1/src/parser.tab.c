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


#line 107 "parser.tab.c"

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
  YYSYMBOL_OPER_IS = 50,                   /* "is"  */
  YYSYMBOL_OPER_LEFT_SHIFT = 51,           /* "<<"  */
  YYSYMBOL_OPER_LESS_GREATER = 52,         /* "<>"  */
  YYSYMBOL_OPER_LESS_THAN = 53,            /* "<"  */
  YYSYMBOL_OPER_LESS_THAN_EQUAL = 54,      /* "<="  */
  YYSYMBOL_OPER_MINUS = 55,                /* "-"  */
  YYSYMBOL_OPER_MOD = 56,                  /* "%"  */
  YYSYMBOL_OPER_MULTIPLY = 57,             /* "*"  */
  YYSYMBOL_OPER_NEGATIVE = 58,             /* "~"  */
  YYSYMBOL_OPER_NOT = 59,                  /* "not"  */
  YYSYMBOL_OPER_NOT_EQUAL = 60,            /* "!="  */
  YYSYMBOL_OPER_OPEN_BRACKET = 61,         /* "("  */
  YYSYMBOL_OPER_OR = 62,                   /* "or"  */
  YYSYMBOL_OPER_OR_BITWISE = 63,           /* "|"  */
  YYSYMBOL_OPER_PLUS = 64,                 /* "+"  */
  YYSYMBOL_OPER_POWER = 65,                /* "**"  */
  YYSYMBOL_OPER_REFERENCE = 66,            /* "->"  */
  YYSYMBOL_OPER_RIGHT_SHIFT = 67,          /* ">>"  */
  YYSYMBOL_OPER_SEMICOLON = 68,            /* ";"  */
  YYSYMBOL_OPER_XOR_BITWISE = 69,          /* "^"  */
  YYSYMBOL_STRING = 70,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_input_file = 72,                /* input_file  */
  YYSYMBOL_input_file_dash = 73,           /* input_file_dash  */
  YYSYMBOL_stmt = 74,                      /* stmt  */
  YYSYMBOL_simple_stmt = 75,               /* simple_stmt  */
  YYSYMBOL_small_stmt_dash = 76,           /* small_stmt_dash  */
  YYSYMBOL_small_stmt = 77,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 78,                 /* expr_stmt  */
  YYSYMBOL_expr_stmt_dash = 79,            /* expr_stmt_dash  */
  YYSYMBOL_assign_dash = 80,               /* assign_dash  */
  YYSYMBOL_annasign = 81,                  /* annasign  */
  YYSYMBOL_augassign = 82,                 /* augassign  */
  YYSYMBOL_flow_stmt = 83,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 84,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 85,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 86,               /* return_stmt  */
  YYSYMBOL_global_stmt = 87,               /* global_stmt  */
  YYSYMBOL_NAME_dash = 88,                 /* NAME_dash  */
  YYSYMBOL_compound_stmt = 89,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 90,                   /* if_stmt  */
  YYSYMBOL_if_stmt_dash = 91,              /* if_stmt_dash  */
  YYSYMBOL_else_stmt_dash = 92,            /* else_stmt_dash  */
  YYSYMBOL_elif_stmt = 93,                 /* elif_stmt  */
  YYSYMBOL_else_stmt = 94,                 /* else_stmt  */
  YYSYMBOL_classdef = 95,                  /* classdef  */
  YYSYMBOL_96_1 = 96,                      /* $@1  */
  YYSYMBOL_inheritlist = 97,               /* inheritlist  */
  YYSYMBOL_for_stmt = 98,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 99,                /* while_stmt  */
  YYSYMBOL_funcdef = 100,                  /* funcdef  */
  YYSYMBOL_101_2 = 101,                    /* $@2  */
  YYSYMBOL_funcdef_dash = 102,             /* funcdef_dash  */
  YYSYMBOL_parameters = 103,               /* parameters  */
  YYSYMBOL_parameters_dash = 104,          /* parameters_dash  */
  YYSYMBOL_typedargslist = 105,            /* typedargslist  */
  YYSYMBOL_tfpdef = 106,                   /* tfpdef  */
  YYSYMBOL_suite = 107,                    /* suite  */
  YYSYMBOL_stmt_dash = 108,                /* stmt_dash  */
  YYSYMBOL_test = 109,                     /* test  */
  YYSYMBOL_or_test = 110,                  /* or_test  */
  YYSYMBOL_and_test = 111,                 /* and_test  */
  YYSYMBOL_not_test = 112,                 /* not_test  */
  YYSYMBOL_comparison = 113,               /* comparison  */
  YYSYMBOL_comp_op = 114,                  /* comp_op  */
  YYSYMBOL_expr = 115,                     /* expr  */
  YYSYMBOL_xor_expr = 116,                 /* xor_expr  */
  YYSYMBOL_and_expr = 117,                 /* and_expr  */
  YYSYMBOL_shift_expr = 118,               /* shift_expr  */
  YYSYMBOL_arith_expr = 119,               /* arith_expr  */
  YYSYMBOL_term = 120,                     /* term  */
  YYSYMBOL_factor = 121,                   /* factor  */
  YYSYMBOL_power = 122,                    /* power  */
  YYSYMBOL_atom_expr = 123,                /* atom_expr  */
  YYSYMBOL_trailerlist = 124,              /* trailerlist  */
  YYSYMBOL_trailer = 125,                  /* trailer  */
  YYSYMBOL_atom = 126,                     /* atom  */
  YYSYMBOL_arglist = 127,                  /* arglist  */
  YYSYMBOL_arglist_dash = 128              /* arglist_dash  */
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
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   172,   172,   182,   186,   203,   208,   212,   218,   225,
     237,   244,   249,   253,   259,   286,   290,   295,   300,   305,
     311,   318,   323,   331,   335,   339,   343,   347,   351,   355,
     359,   363,   367,   371,   375,   381,   385,   389,   395,   401,
     407,   414,   427,   438,   444,   448,   452,   456,   460,   466,
     475,   483,   487,   492,   496,   501,   508,   516,   523,   523,
     542,   547,   552,   558,   567,   575,   575,   599,   605,   610,
     618,   628,   633,   644,   650,   657,   666,   675,   680,   689,
     694,   701,   707,   711,   719,   723,   731,   736,   742,   748,
     754,   758,   762,   766,   770,   774,   778,   782,   786,   792,
     796,   804,   808,   816,   820,   828,   832,   838,   846,   850,
     856,   864,   868,   874,   880,   886,   894,   899,   904,   909,
     915,   919,   927,   939,   950,   954,   963,   968,   975,   979,
     983,   987,   991,   995,   999,  1003,  1014,  1019,  1024,  1029
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
  "\"is\"", "\"<<\"", "\"<>\"", "\"<\"", "\"<=\"", "\"-\"", "\"%\"",
  "\"*\"", "\"~\"", "\"not\"", "\"!=\"", "\"(\"", "\"or\"", "\"|\"",
  "\"+\"", "\"**\"", "\"->\"", "\">>\"", "\";\"", "\"^\"", "STRING",
  "$accept", "input_file", "input_file_dash", "stmt", "simple_stmt",
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

#define YYPACT_NINF (-187)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -187,    17,    68,  -187,  -187,  -187,    -6,  -187,  -187,   105,
       8,    21,   105,  -187,   105,  -187,   105,  -187,  -187,  -187,
     105,   236,   236,   105,   105,   236,  -187,  -187,  -187,   -20,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,    23,
    -187,  -187,  -187,  -187,   304,   -40,    20,  -187,   101,     1,
      -3,    28,   -48,   -41,     0,  -187,  -187,     6,  -187,     9,
      24,    12,  -187,    33,    37,  -187,    38,  -187,    65,    40,
    -187,  -187,  -187,    43,  -187,  -187,   219,   105,    44,  -187,
      60,  -187,  -187,  -187,  -187,   105,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   105,  -187,  -187,  -187,   105,
     105,   105,  -187,  -187,  -187,    52,  -187,  -187,  -187,  -187,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   -17,     5,  -187,   105,    58,    46,    79,
     199,   199,  -187,   105,  -187,  -187,    73,   199,  -187,   109,
     110,  -187,    20,  -187,  -187,     1,    -3,    28,   -48,   -41,
     -41,     0,     0,  -187,  -187,  -187,  -187,  -187,   105,    83,
     105,  -187,    80,  -187,    78,    81,    87,    84,    89,  -187,
     105,  -187,  -187,   102,  -187,  -187,  -187,  -187,   199,  -187,
    -187,   105,   117,  -187,    94,  -187,   199,   199,   105,  -187,
      58,  -187,    95,   156,   120,  -187,  -187,  -187,  -187,  -187,
     134,  -187,   199,  -187,     4,  -187,   105,  -187,  -187,  -187,
    -187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     2,    38,     0,    39,   133,     0,
       0,     0,     0,   131,     0,   132,     0,   128,     3,   129,
     137,     0,     0,     0,     0,     0,   130,     4,     6,     0,
      10,    11,    12,    35,    36,    37,    13,     7,    45,    54,
      48,    47,    46,    44,    18,    81,    82,    84,    87,    89,
      99,   101,   103,   105,   108,   111,   119,   120,   124,    62,
       0,     0,    43,    41,     0,    40,     0,   139,     0,   136,
     117,   118,    86,     0,   116,     8,     0,     0,     0,    49,
      53,    51,    28,    26,    34,     0,    31,    24,    27,    25,
      29,    23,    33,    32,    30,     0,    14,    17,    15,     0,
       0,     0,    92,    91,    93,    97,    95,    90,    94,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,    58,     0,    71,    68,     0,
       0,     0,   135,     0,   134,     9,     0,     0,    52,    20,
      21,    16,    83,    85,    98,    88,   100,   102,   104,   106,
     107,   110,   109,   113,   115,   114,   112,   121,     0,     0,
     137,   123,     0,    61,     0,     0,    75,     0,    70,    73,
       0,    65,    42,     0,    77,    50,    64,   138,     0,    57,
      19,     0,     0,   127,     0,    60,     0,     0,     0,    69,
       0,    67,     0,     0,    56,    22,   126,   125,    59,    63,
      74,    72,     0,    80,     0,    55,     0,    66,    78,    79,
      76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -186,    -2,  -187,    69,  -187,  -187,    10,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,   -50,    76,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   -33,  -126,  -187,    -8,  -187,
      59,   -21,  -187,  -187,    48,    54,    55,    57,   -64,   -63,
     -12,  -187,  -187,  -187,  -187,  -187,    11,  -187
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,   174,    29,    30,    31,    96,    97,
      98,    99,    32,    33,    34,    35,    36,    63,    37,    38,
      39,    79,    80,    81,    40,   164,   125,    41,    42,    43,
     192,   171,   128,   167,   168,   169,   175,   204,    44,    45,
      46,    47,    48,   110,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   123,   161,    58,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    60,    72,   114,    64,   176,    65,   203,    66,    70,
      71,   179,    67,    74,   116,    75,    73,     3,   209,   115,
     158,   208,   100,   117,     5,     6,     7,   159,    59,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   162,
      19,    20,    61,   118,   160,   163,    77,    78,    76,   119,
     149,   150,   194,   151,   152,    62,   120,   121,   101,    21,
     198,   199,    22,    23,   111,    24,   112,   113,    25,   136,
     124,   122,   126,   127,    26,   129,   207,   139,   130,   131,
     143,   132,   133,   134,    78,   137,     4,   140,     5,     6,
       7,   141,   166,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   153,   154,   155,   156,
     157,   144,   170,   172,   178,    85,   181,   183,   165,   186,
     185,   193,   187,    21,   189,   177,    22,    23,   188,    24,
       8,   190,    25,   196,   197,    13,   202,    15,    26,    17,
     206,    19,    20,    77,   205,   135,   102,   103,   104,   180,
     182,   105,    67,   106,   107,   108,   138,   201,   145,   142,
      21,   109,   191,    22,    23,   146,    24,   147,     0,    25,
     148,   184,     0,   195,     0,    26,     5,     6,     7,     0,
     200,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    28,    19,    20,     0,     0,     0,     0,   210,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    22,    23,     0,    24,     0,     5,
      25,     7,     0,     0,     8,     0,    26,    11,     0,    13,
      14,    15,     0,    17,   173,    19,    20,     0,     0,     5,
       0,     7,     0,     0,     8,     0,     0,    11,     0,    13,
      14,    15,     0,    17,    21,    19,    20,    22,    23,     0,
      24,     8,     0,    25,     0,     0,    13,     0,    15,    26,
      17,     0,    19,    20,    21,     0,     0,    22,    23,     0,
      24,     0,     0,    25,     0,     0,     0,     0,     0,    26,
       0,    21,     0,     0,    22,     0,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,    26,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
       2,     9,    23,    51,    12,   131,    14,   193,    16,    21,
      22,   137,    20,    25,    55,    35,    24,     0,   204,    67,
      37,    17,    62,    64,    20,    21,    22,    44,    34,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    34,
      36,    37,    34,    43,    61,    40,    23,    24,    68,    49,
     114,   115,   178,   116,   117,    34,    56,    57,    38,    55,
     186,   187,    58,    59,    63,    61,    69,    39,    64,    77,
      61,    65,    48,    61,    70,    42,   202,    85,    41,    41,
     101,    16,    42,    40,    24,    41,    18,    95,    20,    21,
      22,    99,    34,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   118,   119,   120,   121,
     122,    59,    66,    34,    41,     6,     6,    34,   126,    41,
      40,    19,    41,    55,    40,   133,    58,    59,    41,    61,
      25,    42,    64,    16,    40,    30,    41,    32,    70,    34,
       6,    36,    37,    23,   194,    76,    45,    46,    47,   139,
     158,    50,   160,    52,    53,    54,    80,   190,   110,   100,
      55,    60,   170,    58,    59,   111,    61,   112,    -1,    64,
     113,   160,    -1,   181,    -1,    70,    20,    21,    22,    -1,
     188,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   193,    36,    37,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    61,    -1,    20,
      64,    22,    -1,    -1,    25,    -1,    70,    28,    -1,    30,
      31,    32,    -1,    34,    35,    36,    37,    -1,    -1,    20,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    -1,    34,    55,    36,    37,    58,    59,    -1,
      61,    25,    -1,    64,    -1,    -1,    30,    -1,    32,    70,
      34,    -1,    36,    37,    55,    -1,    -1,    58,    59,    -1,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,    18,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    55,    58,    59,    61,    64,    70,    74,    75,    76,
      77,    78,    83,    84,    85,    86,    87,    89,    90,    91,
      95,    98,    99,   100,   109,   110,   111,   112,   113,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   126,    34,
     109,    34,    34,    88,   109,   109,   109,   109,   127,   128,
     121,   121,   112,   109,   121,    35,    68,    23,    24,    92,
      93,    94,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    41,    79,    80,    81,    82,
      62,    38,    45,    46,    47,    50,    52,    53,    54,    60,
     114,    63,    69,    39,    51,    67,    55,    64,    43,    49,
      56,    57,    65,   124,    61,    97,    48,    61,   103,    42,
      41,    41,    16,    42,    40,    77,   109,    41,    94,   109,
     109,   109,   111,   112,    59,   115,   116,   117,   118,   119,
     119,   120,   120,   121,   121,   121,   121,   121,    37,    44,
      61,   125,    34,    40,    96,   109,    34,   104,   105,   106,
      66,   102,    34,    35,    75,   107,   107,   109,    41,   107,
      80,     6,   109,    34,   127,    40,    41,    41,    41,    40,
      42,   109,   101,    19,   107,   109,    16,    40,   107,   107,
     109,   106,    41,    74,   108,    93,     6,   107,    17,    74,
     109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    85,
      86,    87,    88,    88,    89,    89,    89,    89,    89,    90,
      91,    92,    92,    92,    92,    93,    93,    94,    96,    95,
      97,    97,    97,    98,    99,   101,   100,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     122,   122,   123,   124,   124,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   128,   128
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     2,     2,     2,     1,
       1,     3,     2,     2,     0,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     0,     3,     1
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
#line 172 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1423 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 183 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1431 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 187 "parser.y"
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
#line 1451 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 203 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1459 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 209 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1467 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 213 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1475 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 219 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1484 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt_dash ";" small_stmt  */
#line 226 "parser.y"
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
#line 1500 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 238 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1508 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 245 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1517 "parser.tab.c"
    break;

  case 12: /* small_stmt: flow_stmt  */
#line 250 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1525 "parser.tab.c"
    break;

  case 13: /* small_stmt: global_stmt  */
#line 254 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1533 "parser.tab.c"
    break;

  case 14: /* expr_stmt: test expr_stmt_dash  */
#line 260 "parser.y"
    { 
        (yyval.node) = makeNode("EXPR_STATEMENT",STATEMENT_TYPE);
        if ((yyvsp[0].node) == NULL){
            appendChild((yyval.node), (yyvsp[-1].node));
        }else{
            appendChild((yyval.node), (yyvsp[0].node));
            insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
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
        }
    }
#line 1562 "parser.tab.c"
    break;

  case 15: /* expr_stmt_dash: annasign  */
#line 287 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1570 "parser.tab.c"
    break;

  case 16: /* expr_stmt_dash: augassign test  */
#line 291 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1579 "parser.tab.c"
    break;

  case 17: /* expr_stmt_dash: assign_dash  */
#line 296 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1587 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: %empty  */
#line 300 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1595 "parser.tab.c"
    break;

  case 19: /* assign_dash: "=" test assign_dash  */
#line 306 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
    }
#line 1605 "parser.tab.c"
    break;

  case 20: /* assign_dash: "=" test  */
#line 312 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1614 "parser.tab.c"
    break;

  case 21: /* annasign: ":" test  */
#line 319 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1623 "parser.tab.c"
    break;

  case 22: /* annasign: ":" test "=" test  */
#line 324 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1633 "parser.tab.c"
    break;

  case 23: /* augassign: "+="  */
#line 332 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1641 "parser.tab.c"
    break;

  case 24: /* augassign: "-="  */
#line 336 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1649 "parser.tab.c"
    break;

  case 25: /* augassign: "*="  */
#line 340 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1657 "parser.tab.c"
    break;

  case 26: /* augassign: "/="  */
#line 344 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1665 "parser.tab.c"
    break;

  case 27: /* augassign: "%="  */
#line 348 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1673 "parser.tab.c"
    break;

  case 28: /* augassign: "&="  */
#line 352 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1681 "parser.tab.c"
    break;

  case 29: /* augassign: "|="  */
#line 356 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1689 "parser.tab.c"
    break;

  case 30: /* augassign: "^="  */
#line 360 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1697 "parser.tab.c"
    break;

  case 31: /* augassign: "<<="  */
#line 364 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1705 "parser.tab.c"
    break;

  case 32: /* augassign: ">>="  */
#line 368 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1713 "parser.tab.c"
    break;

  case 33: /* augassign: "**="  */
#line 372 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1721 "parser.tab.c"
    break;

  case 34: /* augassign: "//="  */
#line 376 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1729 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 382 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1737 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 386 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1745 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 390 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1753 "parser.tab.c"
    break;

  case 38: /* break_stmt: "break"  */
#line 396 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
    }
#line 1761 "parser.tab.c"
    break;

  case 39: /* continue_stmt: "continue"  */
#line 402 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
    }
#line 1769 "parser.tab.c"
    break;

  case 40: /* return_stmt: "return" test  */
#line 408 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1778 "parser.tab.c"
    break;

  case 41: /* global_stmt: "global" NAME_dash  */
#line 415 "parser.y"
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
#line 1793 "parser.tab.c"
    break;

  case 42: /* NAME_dash: NAME_dash "," NAME  */
#line 428 "parser.y"
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
#line 1808 "parser.tab.c"
    break;

  case 43: /* NAME_dash: NAME  */
#line 439 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1816 "parser.tab.c"
    break;

  case 44: /* compound_stmt: funcdef  */
#line 445 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1824 "parser.tab.c"
    break;

  case 45: /* compound_stmt: if_stmt  */
#line 449 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1832 "parser.tab.c"
    break;

  case 46: /* compound_stmt: while_stmt  */
#line 453 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1840 "parser.tab.c"
    break;

  case 47: /* compound_stmt: for_stmt  */
#line 457 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1848 "parser.tab.c"
    break;

  case 48: /* compound_stmt: classdef  */
#line 461 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1856 "parser.tab.c"
    break;

  case 49: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 467 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1867 "parser.tab.c"
    break;

  case 50: /* if_stmt_dash: "if" test ":" suite  */
#line 476 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1877 "parser.tab.c"
    break;

  case 51: /* else_stmt_dash: else_stmt  */
#line 484 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1885 "parser.tab.c"
    break;

  case 52: /* else_stmt_dash: elif_stmt else_stmt  */
#line 488 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1894 "parser.tab.c"
    break;

  case 53: /* else_stmt_dash: elif_stmt  */
#line 493 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1902 "parser.tab.c"
    break;

  case 54: /* else_stmt_dash: %empty  */
#line 496 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1910 "parser.tab.c"
    break;

  case 55: /* elif_stmt: "elif" test ":" suite elif_stmt  */
#line 502 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 1921 "parser.tab.c"
    break;

  case 56: /* elif_stmt: "elif" test ":" suite  */
#line 509 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1931 "parser.tab.c"
    break;

  case 57: /* else_stmt: "else" ":" suite  */
#line 517 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1940 "parser.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 523 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
    }
#line 1949 "parser.tab.c"
    break;

  case 59: /* classdef: "class" NAME inheritlist $@1 ":" suite  */
#line 527 "parser.y"
    {
            
        
        (yyval.node) = makeNode("",CLASS_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node), (yyvsp[-3].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));

        curr_symtable_class = NULL;

    }
#line 1967 "parser.tab.c"
    break;

  case 60: /* inheritlist: "(" NAME ")"  */
#line 543 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1975 "parser.tab.c"
    break;

  case 61: /* inheritlist: "(" ")"  */
#line 548 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1983 "parser.tab.c"
    break;

  case 62: /* inheritlist: %empty  */
#line 552 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1991 "parser.tab.c"
    break;

  case 63: /* for_stmt: "for" test "in" test ":" suite  */
#line 559 "parser.y"
    {   
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2002 "parser.tab.c"
    break;

  case 64: /* while_stmt: "while" test ":" suite  */
#line 568 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2012 "parser.tab.c"
    break;

  case 65: /* $@2: %empty  */
#line 575 "parser.y"
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
#line 2027 "parser.tab.c"
    break;

  case 66: /* funcdef: "def" NAME parameters funcdef_dash $@2 ":" suite  */
#line 584 "parser.y"
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
#line 2045 "parser.tab.c"
    break;

  case 67: /* funcdef_dash: "->" test  */
#line 600 "parser.y"
    {
        DEBUG((yyvsp[0].node)->lexeme);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2054 "parser.tab.c"
    break;

  case 68: /* funcdef_dash: %empty  */
#line 605 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2062 "parser.tab.c"
    break;

  case 69: /* parameters: "(" parameters_dash ")"  */
#line 611 "parser.y"
    {
        DEBUG((yyvsp[-1].node));
        DEBUG("parameters" << (yyvsp[-1].node)->children.size());
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2072 "parser.tab.c"
    break;

  case 70: /* parameters_dash: typedargslist  */
#line 619 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2085 "parser.tab.c"
    break;

  case 71: /* parameters_dash: %empty  */
#line 628 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2093 "parser.tab.c"
    break;

  case 72: /* typedargslist: typedargslist "," tfpdef  */
#line 634 "parser.y"
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
#line 2108 "parser.tab.c"
    break;

  case 73: /* typedargslist: tfpdef  */
#line 645 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2116 "parser.tab.c"
    break;

  case 74: /* tfpdef: NAME ":" test  */
#line 651 "parser.y"
    {
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2126 "parser.tab.c"
    break;

  case 75: /* tfpdef: NAME  */
#line 658 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }
        }
    }
#line 2138 "parser.tab.c"
    break;

  case 76: /* tfpdef: NAME ":" test "=" test  */
#line 667 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2149 "parser.tab.c"
    break;

  case 77: /* suite: simple_stmt  */
#line 676 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2158 "parser.tab.c"
    break;

  case 78: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 681 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2169 "parser.tab.c"
    break;

  case 79: /* stmt_dash: stmt_dash stmt  */
#line 690 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2178 "parser.tab.c"
    break;

  case 80: /* stmt_dash: stmt  */
#line 695 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2187 "parser.tab.c"
    break;

  case 81: /* test: or_test  */
#line 702 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2195 "parser.tab.c"
    break;

  case 82: /* or_test: and_test  */
#line 708 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2203 "parser.tab.c"
    break;

  case 83: /* or_test: or_test "or" and_test  */
#line 712 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2213 "parser.tab.c"
    break;

  case 84: /* and_test: not_test  */
#line 720 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2221 "parser.tab.c"
    break;

  case 85: /* and_test: and_test "and" not_test  */
#line 724 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2231 "parser.tab.c"
    break;

  case 86: /* not_test: "not" not_test  */
#line 732 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2240 "parser.tab.c"
    break;

  case 87: /* not_test: comparison  */
#line 737 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2248 "parser.tab.c"
    break;

  case 88: /* comparison: comparison comp_op expr  */
#line 743 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2258 "parser.tab.c"
    break;

  case 89: /* comparison: expr  */
#line 749 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2266 "parser.tab.c"
    break;

  case 90: /* comp_op: "<"  */
#line 755 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2274 "parser.tab.c"
    break;

  case 91: /* comp_op: ">"  */
#line 759 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2282 "parser.tab.c"
    break;

  case 92: /* comp_op: "=="  */
#line 763 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2290 "parser.tab.c"
    break;

  case 93: /* comp_op: ">="  */
#line 767 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2298 "parser.tab.c"
    break;

  case 94: /* comp_op: "<="  */
#line 771 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2306 "parser.tab.c"
    break;

  case 95: /* comp_op: "<>"  */
#line 775 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2314 "parser.tab.c"
    break;

  case 96: /* comp_op: "!="  */
#line 779 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2322 "parser.tab.c"
    break;

  case 97: /* comp_op: "is"  */
#line 783 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2330 "parser.tab.c"
    break;

  case 98: /* comp_op: "is" "not"  */
#line 787 "parser.y"
    {
        (yyval.node) = makeNode("is not", OPERATOR_TYPE);
    }
#line 2338 "parser.tab.c"
    break;

  case 99: /* expr: xor_expr  */
#line 793 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2346 "parser.tab.c"
    break;

  case 100: /* expr: expr "|" xor_expr  */
#line 797 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2356 "parser.tab.c"
    break;

  case 101: /* xor_expr: and_expr  */
#line 805 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2364 "parser.tab.c"
    break;

  case 102: /* xor_expr: xor_expr "^" and_expr  */
#line 809 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2374 "parser.tab.c"
    break;

  case 103: /* and_expr: shift_expr  */
#line 817 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2382 "parser.tab.c"
    break;

  case 104: /* and_expr: and_expr "&" shift_expr  */
#line 821 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2392 "parser.tab.c"
    break;

  case 105: /* shift_expr: arith_expr  */
#line 829 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2400 "parser.tab.c"
    break;

  case 106: /* shift_expr: shift_expr "<<" arith_expr  */
#line 833 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2410 "parser.tab.c"
    break;

  case 107: /* shift_expr: shift_expr ">>" arith_expr  */
#line 839 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2420 "parser.tab.c"
    break;

  case 108: /* arith_expr: term  */
#line 847 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2428 "parser.tab.c"
    break;

  case 109: /* arith_expr: arith_expr "+" term  */
#line 851 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2438 "parser.tab.c"
    break;

  case 110: /* arith_expr: arith_expr "-" term  */
#line 857 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2448 "parser.tab.c"
    break;

  case 111: /* term: factor  */
#line 865 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2456 "parser.tab.c"
    break;

  case 112: /* term: term "*" factor  */
#line 869 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2466 "parser.tab.c"
    break;

  case 113: /* term: term "/" factor  */
#line 875 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2476 "parser.tab.c"
    break;

  case 114: /* term: term "%" factor  */
#line 881 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2486 "parser.tab.c"
    break;

  case 115: /* term: term "//" factor  */
#line 887 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2496 "parser.tab.c"
    break;

  case 116: /* factor: "+" factor  */
#line 895 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2505 "parser.tab.c"
    break;

  case 117: /* factor: "-" factor  */
#line 900 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2514 "parser.tab.c"
    break;

  case 118: /* factor: "~" factor  */
#line 905 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2523 "parser.tab.c"
    break;

  case 119: /* factor: power  */
#line 910 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2531 "parser.tab.c"
    break;

  case 120: /* power: atom_expr  */
#line 916 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2539 "parser.tab.c"
    break;

  case 121: /* power: atom_expr "**" factor  */
#line 920 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2549 "parser.tab.c"
    break;

  case 122: /* atom_expr: atom trailerlist  */
#line 928 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
        }else{
            (yyval.node) = makeNode("atom_expr", EXPR_TYPE);
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2563 "parser.tab.c"
    break;

  case 123: /* trailerlist: trailerlist trailer  */
#line 940 "parser.y"
    {
        if ((yyval.node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2577 "parser.tab.c"
    break;

  case 124: /* trailerlist: %empty  */
#line 950 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2585 "parser.tab.c"
    break;

  case 125: /* trailer: "(" arglist ")"  */
#line 955 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2598 "parser.tab.c"
    break;

  case 126: /* trailer: "[" test "]"  */
#line 964 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2607 "parser.tab.c"
    break;

  case 127: /* trailer: "." NAME  */
#line 969 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2616 "parser.tab.c"
    break;

  case 128: /* atom: NAME  */
#line 976 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
    }
#line 2624 "parser.tab.c"
    break;

  case 129: /* atom: NUMBER  */
#line 980 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NUMBER_TYPE);
    }
#line 2632 "parser.tab.c"
    break;

  case 130: /* atom: STRING  */
#line 984 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
    }
#line 2640 "parser.tab.c"
    break;

  case 131: /* atom: "None"  */
#line 988 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2648 "parser.tab.c"
    break;

  case 132: /* atom: "True"  */
#line 992 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
    }
#line 2656 "parser.tab.c"
    break;

  case 133: /* atom: "False"  */
#line 996 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
    }
#line 2664 "parser.tab.c"
    break;

  case 134: /* atom: "(" test ")"  */
#line 1000 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2672 "parser.tab.c"
    break;

  case 135: /* atom: "[" arglist "]"  */
#line 1004 "parser.y"
    {
        (yyval.node) = makeNode("[]", LIST_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2685 "parser.tab.c"
    break;

  case 136: /* arglist: arglist_dash  */
#line 1015 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2693 "parser.tab.c"
    break;

  case 137: /* arglist: %empty  */
#line 1019 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2701 "parser.tab.c"
    break;

  case 138: /* arglist_dash: arglist_dash "," test  */
#line 1025 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2710 "parser.tab.c"
    break;

  case 139: /* arglist_dash: test  */
#line 1030 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2719 "parser.tab.c"
    break;


#line 2723 "parser.tab.c"

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

#line 1037 "parser.y"

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

    global_symtable = new symtable_global();
    curr_symtable_global = global_symtable;
    yyparse();
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
