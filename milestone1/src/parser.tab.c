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

int yylex();
int yyerror(const char * msg);
struct Token{
    string lexeme;
};
int curr_id = 0;
struct TreeNode{
    public: 
        struct Token token;
        string id;
        vector<struct TreeNode*> children;
};


map<string, string> id_to_label;
map<string, vector<string> > edges;

struct TreeNode * makeNode(string lexeme){
    struct TreeNode * node = new (struct TreeNode);
    node->id = "N" + to_string(curr_id++);
    node->token.lexeme = lexeme;
    return node;
}
void labelNode(struct TreeNode * node){
    id_to_label[node->id] = node->token.lexeme;
    return;
}
void appendChild(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.push_back(child);
    edges[parent->id].push_back(child->id);
    return;
}
void insert_to_front(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.insert(parent->children.begin(), child);
    edges[parent->id].insert(edges[parent->id].begin(), child->id);
    return;
}


#line 128 "parser.tab.c"

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
  YYSYMBOL_KEY_ASSERT = 20,                /* "assert"  */
  YYSYMBOL_KEY_BREAK = 21,                 /* "break"  */
  YYSYMBOL_KEY_CLASS = 22,                 /* "class"  */
  YYSYMBOL_KEY_CONTINUE = 23,              /* "continue"  */
  YYSYMBOL_KEY_DELETE = 24,                /* "delete"  */
  YYSYMBOL_KEY_ELIF = 25,                  /* "elif"  */
  YYSYMBOL_KEY_ELSE = 26,                  /* "else"  */
  YYSYMBOL_KEY_FALSE = 27,                 /* "False"  */
  YYSYMBOL_KEY_FOR = 28,                   /* "for"  */
  YYSYMBOL_KEY_FUNCTION_DEF = 29,          /* "def"  */
  YYSYMBOL_KEY_GLOBAL = 30,                /* "global"  */
  YYSYMBOL_KEY_IF = 31,                    /* "if"  */
  YYSYMBOL_KEY_NONE = 32,                  /* "None"  */
  YYSYMBOL_KEY_NONLOCAL = 33,              /* "nonlocal"  */
  YYSYMBOL_KEY_RETURN = 34,                /* "return"  */
  YYSYMBOL_KEY_TRUE = 35,                  /* "True"  */
  YYSYMBOL_KEY_WHILE = 36,                 /* "while"  */
  YYSYMBOL_NAME = 37,                      /* NAME  */
  YYSYMBOL_NEWLINE = 38,                   /* NEWLINE  */
  YYSYMBOL_NUMBER = 39,                    /* NUMBER  */
  YYSYMBOL_OPEN_SQUARE_BRACKET = 40,       /* "["  */
  YYSYMBOL_OPER_AND = 41,                  /* "and"  */
  YYSYMBOL_OPER_AND_BITWISE = 42,          /* "&"  */
  YYSYMBOL_OPER_CLOSE_BRACKET = 43,        /* ")"  */
  YYSYMBOL_OPER_COLON = 44,                /* ":"  */
  YYSYMBOL_OPER_COMMA = 45,                /* ","  */
  YYSYMBOL_OPER_DIVIDE = 46,               /* "/"  */
  YYSYMBOL_OPER_DOT = 47,                  /* "."  */
  YYSYMBOL_OPER_EQUAL = 48,                /* "=="  */
  YYSYMBOL_OPER_GREATER_THAN = 49,         /* ">"  */
  YYSYMBOL_OPER_GREATER_THAN_EQUAL = 50,   /* ">="  */
  YYSYMBOL_OPER_IN = 51,                   /* "in"  */
  YYSYMBOL_OPER_INT_DIV = 52,              /* "//"  */
  YYSYMBOL_OPER_IS = 53,                   /* "is"  */
  YYSYMBOL_OPER_LEFT_SHIFT = 54,           /* "<<"  */
  YYSYMBOL_OPER_LESS_GREATER = 55,         /* "<>"  */
  YYSYMBOL_OPER_LESS_THAN = 56,            /* "<"  */
  YYSYMBOL_OPER_LESS_THAN_EQUAL = 57,      /* "<="  */
  YYSYMBOL_OPER_MINUS = 58,                /* "-"  */
  YYSYMBOL_OPER_MOD = 59,                  /* "%"  */
  YYSYMBOL_OPER_MULTIPLY = 60,             /* "*"  */
  YYSYMBOL_OPER_NEGATIVE = 61,             /* "~"  */
  YYSYMBOL_OPER_NOT = 62,                  /* "not"  */
  YYSYMBOL_OPER_NOT_EQUAL = 63,            /* "!="  */
  YYSYMBOL_OPER_OPEN_BRACKET = 64,         /* "("  */
  YYSYMBOL_OPER_OR = 65,                   /* "or"  */
  YYSYMBOL_OPER_OR_BITWISE = 66,           /* "|"  */
  YYSYMBOL_OPER_PLUS = 67,                 /* "+"  */
  YYSYMBOL_OPER_POWER = 68,                /* "**"  */
  YYSYMBOL_OPER_REFERENCE = 69,            /* "->"  */
  YYSYMBOL_OPER_RIGHT_SHIFT = 70,          /* ">>"  */
  YYSYMBOL_OPER_SEMICOLON = 71,            /* ";"  */
  YYSYMBOL_OPER_XOR_BITWISE = 72,          /* "^"  */
  YYSYMBOL_STRING = 73,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_input_file = 75,                /* input_file  */
  YYSYMBOL_input_file_dash = 76,           /* input_file_dash  */
  YYSYMBOL_stmt = 77,                      /* stmt  */
  YYSYMBOL_simple_stmt = 78,               /* simple_stmt  */
  YYSYMBOL_small_stmt_dash = 79,           /* small_stmt_dash  */
  YYSYMBOL_small_stmt = 80,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 81,                 /* expr_stmt  */
  YYSYMBOL_expr_stmt_dash = 82,            /* expr_stmt_dash  */
  YYSYMBOL_assign_dash = 83,               /* assign_dash  */
  YYSYMBOL_testlist = 84,                  /* testlist  */
  YYSYMBOL_annasign = 85,                  /* annasign  */
  YYSYMBOL_augassign = 86,                 /* augassign  */
  YYSYMBOL_del_stmt = 87,                  /* del_stmt  */
  YYSYMBOL_flow_stmt = 88,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 89,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 90,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 91,               /* return_stmt  */
  YYSYMBOL_global_stmt = 92,               /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 93,             /* nonlocal_stmt  */
  YYSYMBOL_assert_stmt = 94,               /* assert_stmt  */
  YYSYMBOL_NAME_dash = 95,                 /* NAME_dash  */
  YYSYMBOL_compound_stmt = 96,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 97,                   /* if_stmt  */
  YYSYMBOL_if_stmt_dash = 98,              /* if_stmt_dash  */
  YYSYMBOL_else_stmt_dash = 99,            /* else_stmt_dash  */
  YYSYMBOL_elif_stmt = 100,                /* elif_stmt  */
  YYSYMBOL_else_stmt = 101,                /* else_stmt  */
  YYSYMBOL_classdef = 102,                 /* classdef  */
  YYSYMBOL_inheritlist = 103,              /* inheritlist  */
  YYSYMBOL_for_stmt = 104,                 /* for_stmt  */
  YYSYMBOL_while_stmt = 105,               /* while_stmt  */
  YYSYMBOL_exprlist = 106,                 /* exprlist  */
  YYSYMBOL_funcdef = 107,                  /* funcdef  */
  YYSYMBOL_funcdef_dash = 108,             /* funcdef_dash  */
  YYSYMBOL_parameters = 109,               /* parameters  */
  YYSYMBOL_parameters_dash = 110,          /* parameters_dash  */
  YYSYMBOL_typedargslist = 111,            /* typedargslist  */
  YYSYMBOL_tfpdef = 112,                   /* tfpdef  */
  YYSYMBOL_suite = 113,                    /* suite  */
  YYSYMBOL_stmt_dash = 114,                /* stmt_dash  */
  YYSYMBOL_test = 115,                     /* test  */
  YYSYMBOL_or_test = 116,                  /* or_test  */
  YYSYMBOL_and_test = 117,                 /* and_test  */
  YYSYMBOL_not_test = 118,                 /* not_test  */
  YYSYMBOL_comparison = 119,               /* comparison  */
  YYSYMBOL_comp_op = 120,                  /* comp_op  */
  YYSYMBOL_expr = 121,                     /* expr  */
  YYSYMBOL_xor_expr = 122,                 /* xor_expr  */
  YYSYMBOL_and_expr = 123,                 /* and_expr  */
  YYSYMBOL_shift_expr = 124,               /* shift_expr  */
  YYSYMBOL_arith_expr = 125,               /* arith_expr  */
  YYSYMBOL_term = 126,                     /* term  */
  YYSYMBOL_factor = 127,                   /* factor  */
  YYSYMBOL_power = 128,                    /* power  */
  YYSYMBOL_atom_expr = 129,                /* atom_expr  */
  YYSYMBOL_trailer = 130,                  /* trailer  */
  YYSYMBOL_atom = 131,                     /* atom  */
  YYSYMBOL_trailer_dash = 132,             /* trailer_dash  */
  YYSYMBOL_arglist = 133,                  /* arglist  */
  YYSYMBOL_argument = 134                  /* argument  */
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
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   199,   199,   208,   212,   224,   229,   233,   239,   245,
     252,   258,   262,   266,   270,   274,   278,   284,   295,   299,
     305,   310,   315,   322,   330,   337,   343,   349,   359,   364,
     369,   374,   379,   384,   389,   394,   399,   404,   409,   414,
     421,   429,   433,   437,   443,   449,   455,   463,   471,   479,
     487,   494,   500,   504,   508,   512,   516,   522,   531,   540,
     544,   549,   553,   558,   566,   575,   583,   596,   603,   608,
     617,   627,   634,   640,   654,   661,   666,   676,   681,   686,
     693,   700,   709,   718,   730,   737,   741,   747,   759,   763,
     769,   773,   782,   786,   795,   801,   808,   814,   820,   824,
     828,   832,   836,   840,   844,   848,   852,   857,   861,   868,
     872,   881,   885,   894,   898,   907,   911,   918,   928,   932,
     939,   948,   952,   959,   966,   973,   982,   988,   994,  1000,
    1006,  1010,  1019,  1032,  1042,  1047,  1052,  1057,  1062,  1067,
    1072,  1077,  1083,  1089,  1095,  1101,  1107,  1113,  1121,  1128,
    1132,  1135,  1139
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
  "INDENT", "\"assert\"", "\"break\"", "\"class\"", "\"continue\"",
  "\"delete\"", "\"elif\"", "\"else\"", "\"False\"", "\"for\"", "\"def\"",
  "\"global\"", "\"if\"", "\"None\"", "\"nonlocal\"", "\"return\"",
  "\"True\"", "\"while\"", "NAME", "NEWLINE", "NUMBER", "\"[\"", "\"and\"",
  "\"&\"", "\")\"", "\":\"", "\",\"", "\"/\"", "\".\"", "\"==\"", "\">\"",
  "\">=\"", "\"in\"", "\"//\"", "\"is\"", "\"<<\"", "\"<>\"", "\"<\"",
  "\"<=\"", "\"-\"", "\"%\"", "\"*\"", "\"~\"", "\"not\"", "\"!=\"",
  "\"(\"", "\"or\"", "\"|\"", "\"+\"", "\"**\"", "\"->\"", "\">>\"",
  "\";\"", "\"^\"", "STRING", "$accept", "input_file", "input_file_dash",
  "stmt", "simple_stmt", "small_stmt_dash", "small_stmt", "expr_stmt",
  "expr_stmt_dash", "assign_dash", "testlist", "annasign", "augassign",
  "del_stmt", "flow_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "global_stmt", "nonlocal_stmt", "assert_stmt", "NAME_dash",
  "compound_stmt", "if_stmt", "if_stmt_dash", "else_stmt_dash",
  "elif_stmt", "else_stmt", "classdef", "inheritlist", "for_stmt",
  "while_stmt", "exprlist", "funcdef", "funcdef_dash", "parameters",
  "parameters_dash", "typedargslist", "tfpdef", "suite", "stmt_dash",
  "test", "or_test", "and_test", "not_test", "comparison", "comp_op",
  "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr", "term",
  "factor", "power", "atom_expr", "trailer", "atom", "trailer_dash",
  "arglist", "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    48,   247,  -136,  -136,   306,  -136,   -33,  -136,   345,
    -136,   345,    33,    36,   306,  -136,    36,   306,  -136,   306,
    -136,  -136,  -136,    -8,   345,   345,   306,   306,   345,  -136,
    -136,  -136,    39,     8,  -136,    30,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     0,  -136,  -136,  -136,
    -136,  -136,    18,    49,  -136,   192,    29,    27,    50,   -48,
     -37,    34,  -136,  -136,    32,  -136,  -136,    38,    60,    29,
      13,    43,  -136,    65,    67,    65,    68,    70,  -136,     7,
    -136,  -136,  -136,     4,  -136,  -136,   292,  -136,  -136,  -136,
     306,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
     306,   306,  -136,  -136,  -136,   306,   306,    71,  -136,    86,
    -136,   306,   306,  -136,  -136,  -136,  -136,    54,  -136,  -136,
    -136,    66,  -136,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,    20,   306,    74,   345,
     306,    83,    59,    92,   131,   131,  -136,    69,  -136,  -136,
       6,   126,  -136,    68,    93,   131,  -136,    49,  -136,  -136,
    -136,    29,    27,    50,   -48,   -37,   -37,    34,    34,  -136,
    -136,  -136,  -136,  -136,   306,   101,   306,  -136,   133,    23,
    -136,   131,    29,    17,    11,    97,    96,  -136,   306,    99,
    -136,   127,  -136,  -136,  -136,  -136,  -136,   306,   131,  -136,
      12,  -136,    26,   306,  -136,   306,  -136,   131,   306,   306,
    -136,    83,  -136,   131,  -136,  -136,   120,  -136,  -136,  -136,
    -136,  -136,  -136,   141,  -136,  -136,   199,  -136,   306,  -136,
    -136,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     2,     0,    44,     0,    45,     0,
     140,     0,     0,     0,     0,   138,     0,     0,   139,     0,
     135,     3,   136,     0,     0,     0,     0,     0,     0,   137,
       4,     6,     0,    10,    11,    21,    12,    13,    41,    42,
      43,    14,    15,    16,     7,    53,    62,    56,    55,    54,
      52,    25,    89,    90,    92,    95,    97,   109,   111,   113,
     115,   118,   121,   129,   130,   134,    49,    68,    40,    72,
       0,     0,    51,    47,     0,    48,    46,     0,   144,     0,
     127,   128,    94,     0,   126,     8,     0,    33,    31,    39,
       0,    36,    29,    32,    30,    34,    28,    38,    37,    35,
       0,     0,    17,    20,    18,     0,     0,     0,    57,    61,
      59,     0,     0,   100,    99,   101,   105,   107,   103,    98,
     102,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   150,     0,     0,
       0,    78,    75,     0,     0,     0,   142,     0,   141,     9,
      23,    26,    24,    19,     0,     0,    60,    91,    93,   108,
     106,    96,   110,   112,   114,   116,   117,   120,   119,   123,
     125,   124,   122,   131,     0,     0,   150,   133,   151,     0,
     149,     0,    71,     0,    84,     0,    77,    80,     0,     0,
      50,     0,    85,    58,    70,   143,    22,     0,     0,    65,
       0,   147,     0,     0,    67,     0,    66,     0,     0,     0,
      76,     0,    74,     0,    88,    27,    64,   146,   145,   152,
     148,    69,    82,    81,    79,    73,     0,    63,     0,    86,
      87,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   -78,    -2,    63,  -136,  -136,  -136,     3,
     -14,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   134,  -136,  -136,  -136,  -136,   -60,    53,  -136,  -136,
    -136,  -136,   146,  -136,  -136,  -136,  -136,  -136,   -52,  -135,
    -136,    -3,  -136,    56,   -25,  -136,  -136,    -4,    51,    47,
      52,   -46,   -41,   -10,  -136,  -136,  -136,  -136,  -136,     1,
     -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,   192,    32,    33,    34,   102,   103,
      35,   104,   105,    36,    37,    38,    39,    40,    41,    42,
      43,    73,    44,    45,    46,   108,   109,   110,    47,   138,
      48,    49,    68,    50,   189,   142,   185,   186,   187,   193,
     226,    51,    52,    53,    54,    55,   123,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   136,    65,   177,   179,
     180
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    82,    66,    76,    67,    69,   127,    69,    78,    79,
     194,    74,    90,    83,    80,    81,    77,   208,    84,    10,
     199,   129,   128,   146,    15,   106,   107,    18,   217,    20,
     130,    22,    23,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   206,   148,     3,   101,
      24,   101,   147,    25,    26,   209,    27,   101,   139,    28,
     174,   207,   101,   216,   140,    29,   204,   175,   205,   218,
      71,   205,   221,    72,   100,   101,   150,    85,   225,    86,
     131,   165,   166,   111,   176,   195,   132,   158,   167,   168,
     112,   153,   126,   133,   134,   124,    10,   151,   152,   125,
     135,    15,   137,   154,    18,   139,    20,   141,    22,    23,
     143,   144,   107,   101,   145,   155,   159,   160,   181,   161,
     184,   169,   170,   171,   172,   173,   183,    24,   188,   190,
      25,    26,   197,    27,   178,   182,    28,   198,   201,   203,
     210,   211,    29,   213,   152,   106,   214,   228,   230,   149,
      75,     5,     6,   196,     8,     9,   227,    70,    10,   224,
     200,    13,   156,    15,    16,    17,    18,   157,    20,   191,
      22,    23,   163,   178,   220,   162,     0,   202,   164,     0,
       0,     0,     0,     0,     0,   212,     0,     0,     0,    24,
       0,     0,    25,    26,   215,    27,     0,     0,    28,     0,
     219,     0,   178,     0,    29,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   229,     0,     0,     5,
       6,     7,     8,     9,    31,   231,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    22,    23,
     113,   114,   115,   116,     0,   117,     0,   118,   119,   120,
       0,     0,     0,     0,   121,   122,     0,    24,     0,     0,
      25,    26,     0,    27,     0,     4,    28,     5,     6,     7,
       8,     9,    29,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    25,    26,
       0,    27,     5,     6,    28,     8,     9,     0,     0,    10,
      29,     0,    13,     0,    15,    16,    17,    18,     0,    20,
       0,    22,    23,    10,     0,     0,     0,     0,    15,     0,
       0,    18,     0,    20,     0,    22,    23,     0,     0,     0,
      24,     0,     0,    25,    26,     0,    27,     0,     0,    28,
       0,     0,     0,     0,    24,    29,     0,    25,    26,     0,
      27,     0,    10,    28,     0,     0,     0,    15,     0,    29,
      18,     0,    20,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,    25,     0,     0,    27,
       0,     0,    28,     0,     0,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       2,    26,     5,    17,    37,     9,    54,    11,    16,    23,
     145,    14,     6,    27,    24,    25,    19,     6,    28,    27,
     155,    58,    70,    16,    32,    25,    26,    35,    16,    37,
      67,    39,    40,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   181,    43,     0,    45,
      58,    45,    45,    61,    62,    44,    64,    45,    45,    67,
      40,    44,    45,   198,    51,    73,    43,    47,    45,    43,
      37,    45,   207,    37,    44,    45,    90,    38,   213,    71,
      46,   127,   128,    65,    64,    16,    52,   112,   129,   130,
      41,   105,    42,    59,    60,    66,    27,   100,   101,    72,
      68,    32,    64,   106,    35,    45,    37,    64,    39,    40,
      45,    44,    26,    45,    44,    44,    62,    51,    44,   123,
      37,   131,   132,   133,   134,   135,   140,    58,    69,    37,
      61,    62,     6,    64,   137,   139,    67,    44,    37,     6,
      43,    45,    73,    44,   147,    25,    19,     6,   226,    86,
      16,    20,    21,   150,    23,    24,   216,    11,    27,   211,
     174,    30,   109,    32,    33,    34,    35,   111,    37,    38,
      39,    40,   125,   176,   205,   124,    -1,   176,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,   197,    64,    -1,    -1,    67,    -1,
     203,    -1,   205,    -1,    73,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    24,   226,   228,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      48,    49,    50,    51,    -1,    53,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    -1,    58,    -1,    -1,
      61,    62,    -1,    64,    -1,    18,    67,    20,    21,    22,
      23,    24,    73,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      -1,    64,    20,    21,    67,    23,    24,    -1,    -1,    27,
      73,    -1,    30,    -1,    32,    33,    34,    35,    -1,    37,
      -1,    39,    40,    27,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    58,    73,    -1,    61,    62,    -1,
      64,    -1,    27,    67,    -1,    -1,    -1,    32,    -1,    73,
      35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,    18,    20,    21,    22,    23,    24,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    58,    61,    62,    64,    67,    73,
      77,    78,    79,    80,    81,    84,    87,    88,    89,    90,
      91,    92,    93,    94,    96,    97,    98,   102,   104,   105,
     107,   115,   116,   117,   118,   119,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   131,   115,    37,   106,   121,
     106,    37,    37,    95,   115,    95,    84,   115,    16,    84,
     127,   127,   118,    84,   127,    38,    71,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      44,    45,    82,    83,    85,    86,    25,    26,    99,   100,
     101,    65,    41,    48,    49,    50,    51,    53,    55,    56,
      57,    62,    63,   120,    66,    72,    42,    54,    70,    58,
      67,    46,    52,    59,    60,    68,   130,    64,   103,    45,
      51,    64,   109,    45,    44,    44,    16,    45,    43,    79,
      84,   115,   115,    84,   115,    44,   101,   117,   118,    62,
      51,   121,   122,   123,   124,   125,   125,   126,   126,   127,
     127,   127,   127,   127,    40,    47,    64,   132,   115,   133,
     134,    44,   121,    84,    37,   110,   111,   112,    69,   108,
      37,    38,    78,   113,   113,    16,    83,     6,    44,   113,
      84,    37,   133,     6,    43,    45,   113,    44,     6,    44,
      43,    45,   115,    44,    19,   115,   113,    16,    43,   115,
     134,   113,   115,   115,   112,   113,   114,   100,     6,    17,
      77,   115
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    88,    88,    88,    89,    90,    91,    92,    93,    94,
      95,    95,    96,    96,    96,    96,    96,    97,    98,    99,
      99,    99,    99,   100,   100,   101,   102,   103,   103,   104,
     105,   106,   106,   107,   108,   108,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   124,   125,   125,
     125,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     128,   128,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   133,   133,
     133,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     0,     3,     2,     3,     1,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       2,     1,     0,     5,     4,     3,     5,     3,     0,     6,
       4,     3,     1,     6,     2,     0,     3,     1,     0,     3,
       1,     3,     3,     5,     1,     1,     4,     2,     0,     1,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     2,     2,     2,     1,
       1,     3,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     2,     3,     3,     2,     3,     1,
       0,     1,     3
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
#line 199 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        labelNode((yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
}
#line 1478 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 209 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1486 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 213 "parser.y"
    {
        if ((yyvsp[-1].node) != NULL){
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("input");
            labelNode((yyval.node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1501 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 224 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1509 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 230 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1517 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 234 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1525 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 240 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1533 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt ";" small_stmt_dash  */
#line 246 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1544 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 253 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1552 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 259 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1560 "parser.tab.c"
    break;

  case 12: /* small_stmt: del_stmt  */
#line 263 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1568 "parser.tab.c"
    break;

  case 13: /* small_stmt: flow_stmt  */
#line 267 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1576 "parser.tab.c"
    break;

  case 14: /* small_stmt: global_stmt  */
#line 271 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1584 "parser.tab.c"
    break;

  case 15: /* small_stmt: nonlocal_stmt  */
#line 275 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1592 "parser.tab.c"
    break;

  case 16: /* small_stmt: assert_stmt  */
#line 279 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1600 "parser.tab.c"
    break;

  case 17: /* expr_stmt: testlist expr_stmt_dash  */
#line 285 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
        }else{
            (yyval.node) = (yyvsp[0].node);
            insert_to_front((yyval.node), (yyvsp[-1].node));
        }
    }
#line 1613 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: annasign  */
#line 296 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1621 "parser.tab.c"
    break;

  case 19: /* expr_stmt_dash: augassign testlist  */
#line 300 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1631 "parser.tab.c"
    break;

  case 20: /* expr_stmt_dash: assign_dash  */
#line 306 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1639 "parser.tab.c"
    break;

  case 21: /* expr_stmt_dash: %empty  */
#line 310 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1647 "parser.tab.c"
    break;

  case 22: /* assign_dash: "=" testlist assign_dash  */
#line 316 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        labelNode((yyval.node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1658 "parser.tab.c"
    break;

  case 23: /* assign_dash: "=" testlist  */
#line 323 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1668 "parser.tab.c"
    break;

  case 24: /* testlist: testlist "," test  */
#line 331 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1679 "parser.tab.c"
    break;

  case 25: /* testlist: test  */
#line 338 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1687 "parser.tab.c"
    break;

  case 26: /* annasign: ":" test  */
#line 344 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1697 "parser.tab.c"
    break;

  case 27: /* annasign: ":" test "=" test  */
#line 350 "parser.y"
    {
        
        (yyval.node) = makeNode(": =");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1709 "parser.tab.c"
    break;

  case 28: /* augassign: "+="  */
#line 360 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1718 "parser.tab.c"
    break;

  case 29: /* augassign: "-="  */
#line 365 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1727 "parser.tab.c"
    break;

  case 30: /* augassign: "*="  */
#line 370 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1736 "parser.tab.c"
    break;

  case 31: /* augassign: "/="  */
#line 375 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1745 "parser.tab.c"
    break;

  case 32: /* augassign: "%="  */
#line 380 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1754 "parser.tab.c"
    break;

  case 33: /* augassign: "&="  */
#line 385 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1763 "parser.tab.c"
    break;

  case 34: /* augassign: "|="  */
#line 390 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1772 "parser.tab.c"
    break;

  case 35: /* augassign: "^="  */
#line 395 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1781 "parser.tab.c"
    break;

  case 36: /* augassign: "<<="  */
#line 400 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1790 "parser.tab.c"
    break;

  case 37: /* augassign: ">>="  */
#line 405 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1799 "parser.tab.c"
    break;

  case 38: /* augassign: "**="  */
#line 410 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1808 "parser.tab.c"
    break;

  case 39: /* augassign: "//="  */
#line 415 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 1817 "parser.tab.c"
    break;

  case 40: /* del_stmt: "delete" exprlist  */
#line 422 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1827 "parser.tab.c"
    break;

  case 41: /* flow_stmt: break_stmt  */
#line 430 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1835 "parser.tab.c"
    break;

  case 42: /* flow_stmt: continue_stmt  */
#line 434 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1843 "parser.tab.c"
    break;

  case 43: /* flow_stmt: return_stmt  */
#line 438 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1851 "parser.tab.c"
    break;

  case 44: /* break_stmt: "break"  */
#line 444 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1859 "parser.tab.c"
    break;

  case 45: /* continue_stmt: "continue"  */
#line 450 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1867 "parser.tab.c"
    break;

  case 46: /* return_stmt: "return" testlist  */
#line 456 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1877 "parser.tab.c"
    break;

  case 47: /* global_stmt: "global" NAME_dash  */
#line 464 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1887 "parser.tab.c"
    break;

  case 48: /* nonlocal_stmt: "nonlocal" NAME_dash  */
#line 472 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1897 "parser.tab.c"
    break;

  case 49: /* assert_stmt: "assert" test  */
#line 480 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1907 "parser.tab.c"
    break;

  case 50: /* NAME_dash: NAME_dash "," NAME  */
#line 488 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1918 "parser.tab.c"
    break;

  case 51: /* NAME_dash: NAME  */
#line 495 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1926 "parser.tab.c"
    break;

  case 52: /* compound_stmt: funcdef  */
#line 501 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1934 "parser.tab.c"
    break;

  case 53: /* compound_stmt: if_stmt  */
#line 505 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1942 "parser.tab.c"
    break;

  case 54: /* compound_stmt: while_stmt  */
#line 509 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1950 "parser.tab.c"
    break;

  case 55: /* compound_stmt: for_stmt  */
#line 513 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1958 "parser.tab.c"
    break;

  case 56: /* compound_stmt: classdef  */
#line 517 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1966 "parser.tab.c"
    break;

  case 57: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 523 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1977 "parser.tab.c"
    break;

  case 58: /* if_stmt_dash: "if" test ":" suite  */
#line 532 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1988 "parser.tab.c"
    break;

  case 59: /* else_stmt_dash: else_stmt  */
#line 541 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1996 "parser.tab.c"
    break;

  case 60: /* else_stmt_dash: elif_stmt else_stmt  */
#line 545 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2005 "parser.tab.c"
    break;

  case 61: /* else_stmt_dash: elif_stmt  */
#line 550 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2013 "parser.tab.c"
    break;

  case 62: /* else_stmt_dash: %empty  */
#line 553 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 2021 "parser.tab.c"
    break;

  case 63: /* elif_stmt: "elif" test ":" suite elif_stmt  */
#line 559 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 2033 "parser.tab.c"
    break;

  case 64: /* elif_stmt: "elif" test ":" suite  */
#line 567 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2044 "parser.tab.c"
    break;

  case 65: /* else_stmt: "else" ":" suite  */
#line 576 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2054 "parser.tab.c"
    break;

  case 66: /* classdef: "class" NAME inheritlist ":" suite  */
#line 584 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        labelNode((yyval.node));
        labelNode((yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-3].node));
        if ((yyvsp[-2].node) != NULL){
            appendChild((yyval.node), (yyvsp[-2].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2069 "parser.tab.c"
    break;

  case 67: /* inheritlist: "(" arglist ")"  */
#line 597 "parser.y"
    {
        (yyval.node) = makeNode("inheritlist");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2079 "parser.tab.c"
    break;

  case 68: /* inheritlist: %empty  */
#line 603 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2087 "parser.tab.c"
    break;

  case 69: /* for_stmt: "for" exprlist "in" testlist ":" suite  */
#line 609 "parser.y"
    {
        (yyval.node) = (yyvsp[-5].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2099 "parser.tab.c"
    break;

  case 70: /* while_stmt: "while" test ":" suite  */
#line 618 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2110 "parser.tab.c"
    break;

  case 71: /* exprlist: exprlist "," expr  */
#line 628 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2121 "parser.tab.c"
    break;

  case 72: /* exprlist: expr  */
#line 635 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2129 "parser.tab.c"
    break;

  case 73: /* funcdef: "def" NAME parameters funcdef_dash ":" suite  */
#line 641 "parser.y"
    {
        (yyval.node) = (yyvsp[-5].node);
        labelNode((yyval.node));
        labelNode((yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-3].node));
        if ((yyvsp[-2].node) != NULL){
            appendChild((yyval.node), (yyvsp[-2].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2145 "parser.tab.c"
    break;

  case 74: /* funcdef_dash: "->" test  */
#line 655 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2155 "parser.tab.c"
    break;

  case 75: /* funcdef_dash: %empty  */
#line 661 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2163 "parser.tab.c"
    break;

  case 76: /* parameters: "(" parameters_dash ")"  */
#line 667 "parser.y"
    {
        (yyval.node) = makeNode("()");
        labelNode((yyval.node));
        if ((yyvsp[-1].node) != NULL){
            appendChild((yyval.node), (yyvsp[-1].node));
        }
    }
#line 2175 "parser.tab.c"
    break;

  case 77: /* parameters_dash: typedargslist  */
#line 677 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2183 "parser.tab.c"
    break;

  case 78: /* parameters_dash: %empty  */
#line 681 "parser.y"
    {   
        (yyval.node) = NULL;
    }
#line 2191 "parser.tab.c"
    break;

  case 79: /* typedargslist: typedargslist "," tfpdef  */
#line 687 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2202 "parser.tab.c"
    break;

  case 80: /* typedargslist: tfpdef  */
#line 694 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2210 "parser.tab.c"
    break;

  case 81: /* tfpdef: NAME ":" test  */
#line 701 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        labelNode((yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2222 "parser.tab.c"
    break;

  case 82: /* tfpdef: NAME "=" test  */
#line 710 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        labelNode((yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2234 "parser.tab.c"
    break;

  case 83: /* tfpdef: NAME ":" test "=" test  */
#line 719 "parser.y"
    {
        cout << "I was here" << endl;
        (yyval.node) = makeNode(": =");
        symtable_entry * temp = new symtable_entry((yyvsp[-4].node)->token.lexeme, 0, "int");
        current_func->add_entry(temp);
        labelNode((yyval.node));
        labelNode((yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2250 "parser.tab.c"
    break;

  case 84: /* tfpdef: NAME  */
#line 731 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2259 "parser.tab.c"
    break;

  case 85: /* suite: simple_stmt  */
#line 738 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2267 "parser.tab.c"
    break;

  case 86: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 742 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2275 "parser.tab.c"
    break;

  case 87: /* stmt_dash: stmt_dash stmt  */
#line 748 "parser.y"
    {
        if ((yyvsp[-1].node) != NULL){
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("statements");
            labelNode((yyval.node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2290 "parser.tab.c"
    break;

  case 88: /* stmt_dash: %empty  */
#line 759 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2298 "parser.tab.c"
    break;

  case 89: /* test: or_test  */
#line 764 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2306 "parser.tab.c"
    break;

  case 90: /* or_test: and_test  */
#line 770 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2314 "parser.tab.c"
    break;

  case 91: /* or_test: or_test "or" and_test  */
#line 774 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2325 "parser.tab.c"
    break;

  case 92: /* and_test: not_test  */
#line 783 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2333 "parser.tab.c"
    break;

  case 93: /* and_test: and_test "and" not_test  */
#line 787 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2344 "parser.tab.c"
    break;

  case 94: /* not_test: "not" not_test  */
#line 796 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2354 "parser.tab.c"
    break;

  case 95: /* not_test: comparison  */
#line 802 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2362 "parser.tab.c"
    break;

  case 96: /* comparison: comparison comp_op expr  */
#line 809 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2372 "parser.tab.c"
    break;

  case 97: /* comparison: expr  */
#line 815 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2380 "parser.tab.c"
    break;

  case 98: /* comp_op: "<"  */
#line 821 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2388 "parser.tab.c"
    break;

  case 99: /* comp_op: ">"  */
#line 825 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2396 "parser.tab.c"
    break;

  case 100: /* comp_op: "=="  */
#line 829 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2404 "parser.tab.c"
    break;

  case 101: /* comp_op: ">="  */
#line 833 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2412 "parser.tab.c"
    break;

  case 102: /* comp_op: "<="  */
#line 837 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2420 "parser.tab.c"
    break;

  case 103: /* comp_op: "<>"  */
#line 841 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2428 "parser.tab.c"
    break;

  case 104: /* comp_op: "!="  */
#line 845 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2436 "parser.tab.c"
    break;

  case 105: /* comp_op: "in"  */
#line 849 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2444 "parser.tab.c"
    break;

  case 106: /* comp_op: "not" "in"  */
#line 853 "parser.y"
    {
        (yyval.node) = makeNode("not in");
        labelNode((yyval.node));
    }
#line 2453 "parser.tab.c"
    break;

  case 107: /* comp_op: "is"  */
#line 858 "parser.y"
    {
        labelNode((yyval.node));
    }
#line 2461 "parser.tab.c"
    break;

  case 108: /* comp_op: "is" "not"  */
#line 862 "parser.y"
    {
        (yyval.node) = makeNode("is not");
        labelNode((yyval.node));
    }
#line 2470 "parser.tab.c"
    break;

  case 109: /* expr: xor_expr  */
#line 869 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2478 "parser.tab.c"
    break;

  case 110: /* expr: expr "|" xor_expr  */
#line 873 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2489 "parser.tab.c"
    break;

  case 111: /* xor_expr: and_expr  */
#line 882 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2497 "parser.tab.c"
    break;

  case 112: /* xor_expr: xor_expr "^" and_expr  */
#line 886 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 2508 "parser.tab.c"
    break;

  case 113: /* and_expr: shift_expr  */
#line 895 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2516 "parser.tab.c"
    break;

  case 114: /* and_expr: and_expr "&" shift_expr  */
#line 899 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2527 "parser.tab.c"
    break;

  case 115: /* shift_expr: arith_expr  */
#line 908 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2535 "parser.tab.c"
    break;

  case 116: /* shift_expr: shift_expr "<<" arith_expr  */
#line 912 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2546 "parser.tab.c"
    break;

  case 117: /* shift_expr: shift_expr ">>" arith_expr  */
#line 919 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2557 "parser.tab.c"
    break;

  case 118: /* arith_expr: term  */
#line 929 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2565 "parser.tab.c"
    break;

  case 119: /* arith_expr: arith_expr "+" term  */
#line 933 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2576 "parser.tab.c"
    break;

  case 120: /* arith_expr: arith_expr "-" term  */
#line 940 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2587 "parser.tab.c"
    break;

  case 121: /* term: factor  */
#line 949 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2595 "parser.tab.c"
    break;

  case 122: /* term: term "*" factor  */
#line 953 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2606 "parser.tab.c"
    break;

  case 123: /* term: term "/" factor  */
#line 960 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2617 "parser.tab.c"
    break;

  case 124: /* term: term "%" factor  */
#line 967 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2628 "parser.tab.c"
    break;

  case 125: /* term: term "//" factor  */
#line 974 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2639 "parser.tab.c"
    break;

  case 126: /* factor: "+" factor  */
#line 983 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2649 "parser.tab.c"
    break;

  case 127: /* factor: "-" factor  */
#line 989 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2659 "parser.tab.c"
    break;

  case 128: /* factor: "~" factor  */
#line 995 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2669 "parser.tab.c"
    break;

  case 129: /* factor: power  */
#line 1001 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2677 "parser.tab.c"
    break;

  case 130: /* power: atom_expr  */
#line 1007 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2685 "parser.tab.c"
    break;

  case 131: /* power: atom_expr "**" factor  */
#line 1011 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2696 "parser.tab.c"
    break;

  case 132: /* atom_expr: atom trailer  */
#line 1020 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
        }else{
            (yyval.node) = makeNode("atom_expr");
            labelNode((yyval.node));
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2711 "parser.tab.c"
    break;

  case 133: /* trailer: trailer trailer_dash  */
#line 1033 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2724 "parser.tab.c"
    break;

  case 134: /* trailer: %empty  */
#line 1042 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2732 "parser.tab.c"
    break;

  case 135: /* atom: NAME  */
#line 1048 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2741 "parser.tab.c"
    break;

  case 136: /* atom: NUMBER  */
#line 1053 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2750 "parser.tab.c"
    break;

  case 137: /* atom: STRING  */
#line 1058 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2759 "parser.tab.c"
    break;

  case 138: /* atom: "None"  */
#line 1063 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2768 "parser.tab.c"
    break;

  case 139: /* atom: "True"  */
#line 1068 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2777 "parser.tab.c"
    break;

  case 140: /* atom: "False"  */
#line 1073 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        labelNode((yyval.node));
    }
#line 2786 "parser.tab.c"
    break;

  case 141: /* atom: "(" testlist ")"  */
#line 1078 "parser.y"
    {
        (yyval.node) = makeNode("()");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2796 "parser.tab.c"
    break;

  case 142: /* atom: "[" testlist "]"  */
#line 1084 "parser.y"
    {
        (yyval.node) = makeNode("[]");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2806 "parser.tab.c"
    break;

  case 143: /* atom: "[" testlist "," "]"  */
#line 1090 "parser.y"
    {
        (yyval.node) = makeNode("[]");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-2].node));
    }
#line 2816 "parser.tab.c"
    break;

  case 144: /* atom: "[" "]"  */
#line 1096 "parser.y"
    {
        (yyval.node) = makeNode("[]");
        labelNode((yyval.node));
    }
#line 2825 "parser.tab.c"
    break;

  case 145: /* trailer_dash: "(" arglist ")"  */
#line 1102 "parser.y"
    {
        (yyval.node) = makeNode("()");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2835 "parser.tab.c"
    break;

  case 146: /* trailer_dash: "[" testlist "]"  */
#line 1108 "parser.y"
    {
        (yyval.node) = makeNode("[]");
        labelNode((yyval.node));
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2845 "parser.tab.c"
    break;

  case 147: /* trailer_dash: "." NAME  */
#line 1114 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        labelNode((yyvsp[0].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2856 "parser.tab.c"
    break;

  case 148: /* arglist: arglist "," argument  */
#line 1122 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        labelNode((yyval.node));
        appendChild((yyval.node),(yyvsp[-2].node));
        appendChild((yyval.node),(yyvsp[0].node));
    }
#line 2867 "parser.tab.c"
    break;

  case 149: /* arglist: argument  */
#line 1129 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2875 "parser.tab.c"
    break;

  case 150: /* arglist: %empty  */
#line 1132 "parser.y"
                {(yyval.node) = NULL;}
#line 2881 "parser.tab.c"
    break;

  case 151: /* argument: test  */
#line 1136 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2889 "parser.tab.c"
    break;

  case 152: /* argument: test "=" test  */
#line 1140 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2899 "parser.tab.c"
    break;


#line 2903 "parser.tab.c"

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

#line 1148 "parser.y"

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

    string temp_name = "Hello";
    vector<symtable_entry *> temp_params;
    current_func = new symtable_func(temp_name, temp_params);

    yyparse();

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
