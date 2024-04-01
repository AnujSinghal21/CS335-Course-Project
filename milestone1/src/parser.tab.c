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

int curr_id = 0;

struct TreeNode{
    string lexeme = "";
    string id;
    int node_type = -1;
    vector<struct TreeNode*> children;
};


map<string, string> id_to_label;
map<string, vector<string> > edges;



struct TreeNode * makeNode(string lexeme, int node_type = -1){
    struct TreeNode * node = new (struct TreeNode);
    node->id = "N" + to_string(curr_id++);
    node->lexeme = lexeme;
    node->node_type = node_type;
    return node;
}
void labelNode(struct TreeNode * node){
    id_to_label[node->id] = node->lexeme;
    return;
}
void appendChild(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.push_back(child);
    // edges[parent->id].push_back(child->id);
    return;
}
void insert_to_front(struct TreeNode* parent, struct TreeNode* child){
    if(child == NULL || parent == NULL){
        return;
    }
    parent->children.insert(parent->children.begin(), child);
    // edges[parent->id].insert(edges[parent->id].begin(), child->id);
    return;
}

void printTree(struct TreeNode * node){
    if (node == NULL){
        return;
    }
    cout << node->id << " " << node->lexeme << " has type: " << node->node_type << endl;
    for (auto child: node->children){
        printTree(child);
    }   
    return;
}

TreeNode * root = NULL;


#line 143 "parser.tab.c"

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
  YYSYMBOL_inheritlist = 96,               /* inheritlist  */
  YYSYMBOL_for_stmt = 97,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 98,                /* while_stmt  */
  YYSYMBOL_funcdef = 99,                   /* funcdef  */
  YYSYMBOL_funcdef_dash = 100,             /* funcdef_dash  */
  YYSYMBOL_parameters = 101,               /* parameters  */
  YYSYMBOL_parameters_dash = 102,          /* parameters_dash  */
  YYSYMBOL_typedargslist = 103,            /* typedargslist  */
  YYSYMBOL_tfpdef = 104,                   /* tfpdef  */
  YYSYMBOL_suite = 105,                    /* suite  */
  YYSYMBOL_stmt_dash = 106,                /* stmt_dash  */
  YYSYMBOL_test = 107,                     /* test  */
  YYSYMBOL_or_test = 108,                  /* or_test  */
  YYSYMBOL_and_test = 109,                 /* and_test  */
  YYSYMBOL_not_test = 110,                 /* not_test  */
  YYSYMBOL_comparison = 111,               /* comparison  */
  YYSYMBOL_comp_op = 112,                  /* comp_op  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_xor_expr = 114,                 /* xor_expr  */
  YYSYMBOL_and_expr = 115,                 /* and_expr  */
  YYSYMBOL_shift_expr = 116,               /* shift_expr  */
  YYSYMBOL_arith_expr = 117,               /* arith_expr  */
  YYSYMBOL_term = 118,                     /* term  */
  YYSYMBOL_factor = 119,                   /* factor  */
  YYSYMBOL_power = 120,                    /* power  */
  YYSYMBOL_atom_expr = 121,                /* atom_expr  */
  YYSYMBOL_trailer = 122,                  /* trailer  */
  YYSYMBOL_atom = 123,                     /* atom  */
  YYSYMBOL_arglist = 124,                  /* arglist  */
  YYSYMBOL_arglist_dash = 125              /* arglist_dash  */
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
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
       0,   207,   207,   217,   221,   238,   243,   247,   253,   259,
     270,   277,   281,   285,   291,   303,   307,   312,   317,   322,
     328,   335,   340,   348,   352,   356,   360,   364,   368,   372,
     376,   380,   384,   388,   392,   398,   402,   406,   412,   418,
     424,   431,   444,   455,   461,   465,   469,   473,   477,   483,
     492,   500,   504,   509,   513,   518,   525,   533,   540,   551,
     556,   561,   566,   575,   583,   596,   601,   606,   612,   622,
     627,   638,   644,   651,   656,   665,   670,   679,   684,   691,
     697,   701,   709,   713,   721,   726,   732,   738,   744,   748,
     752,   756,   760,   764,   768,   772,   776,   782,   786,   794,
     798,   806,   810,   818,   822,   828,   836,   840,   846,   854,
     858,   864,   870,   876,   884,   889,   894,   899,   905,   909,
     917,   929,   938,   943,   949,   954,   958,   962,   966,   970,
     974,   978,   982,   993,   998,  1003,  1008
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
  "elif_stmt", "else_stmt", "classdef", "inheritlist", "for_stmt",
  "while_stmt", "funcdef", "funcdef_dash", "parameters", "parameters_dash",
  "typedargslist", "tfpdef", "suite", "stmt_dash", "test", "or_test",
  "and_test", "not_test", "comparison", "comp_op", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "factor", "power",
  "atom_expr", "trailer", "atom", "arglist", "arglist_dash", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -153,     3,    68,  -153,  -153,  -153,   -14,  -153,  -153,   210,
      15,    19,   210,  -153,   210,  -153,   210,  -153,  -153,  -153,
     210,   230,   230,   210,   210,   230,  -153,  -153,  -153,   -28,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,    47,
    -153,  -153,  -153,  -153,   298,   -30,    24,  -153,   108,    -6,
      -4,    29,   -13,   -20,    17,  -153,  -153,    18,     2,    21,
      36,    31,  -153,    43,    70,  -153,    71,  -153,    97,    72,
    -153,  -153,  -153,    76,  -153,  -153,   193,   210,    77,  -153,
      95,  -153,  -153,  -153,  -153,   210,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   210,  -153,  -153,  -153,   210,
     210,   210,  -153,  -153,  -153,    61,  -153,  -153,  -153,  -153,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   210,    88,   210,  -153,   -19,    83,   210,
      91,    64,    99,   173,   173,  -153,   210,  -153,  -153,    90,
     173,  -153,   128,   133,  -153,    24,  -153,  -153,    -6,    -4,
      29,   -13,   -20,   -20,    17,    17,  -153,  -153,  -153,  -153,
    -153,   134,  -153,   116,   117,  -153,   173,   118,   122,   125,
     124,  -153,   210,   126,  -153,   150,  -153,  -153,  -153,  -153,
     173,  -153,  -153,   210,  -153,  -153,  -153,  -153,   173,    11,
    -153,    91,  -153,   173,   115,   148,  -153,  -153,   166,  -153,
    -153,  -153,    -3,  -153,   210,  -153,  -153,  -153
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
      48,    47,    46,    44,    18,    79,    80,    82,    85,    87,
      97,    99,   101,   103,   106,   109,   117,   118,   124,    61,
       0,     0,    43,    41,     0,    40,     0,   136,     0,   133,
     115,   116,    84,     0,   114,     8,     0,     0,     0,    49,
      53,    51,    28,    26,    34,     0,    31,    24,    27,    25,
      29,    23,    33,    32,    30,     0,    14,    17,    15,     0,
       0,     0,    90,    89,    91,    95,    93,    88,    92,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   120,     0,     0,     0,
      69,    66,     0,     0,     0,   132,     0,   131,     9,     0,
       0,    52,    20,    21,    16,    81,    83,    96,    86,    98,
     100,   102,   104,   105,   108,   107,   111,   113,   112,   110,
     119,     0,   123,     0,     0,    60,     0,     0,    73,     0,
      68,    71,     0,     0,    42,     0,    75,    50,    63,   135,
       0,    57,    19,     0,   122,   121,    59,    58,     0,     0,
      67,     0,    65,     0,     0,    56,    22,    62,    72,    70,
      64,    78,     0,    55,     0,    76,    77,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -152,    -2,  -153,   101,  -153,  -153,    38,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,   -17,   102,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,   -10,  -129,  -153,    -8,  -153,    84,   -21,
    -153,  -153,    73,    75,    78,    74,   -39,   -38,   -12,  -153,
      -1,  -153,  -153,    66,  -153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,   176,    29,    30,    31,    96,    97,
      98,    99,    32,    33,    34,    35,    36,    63,    37,    38,
      39,    79,    80,    81,    40,   128,    41,    42,    43,   173,
     131,   169,   170,   171,   177,   202,    44,    45,    46,    47,
      48,   110,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   126,    58,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    60,    72,     3,    64,   178,    65,    75,    66,    70,
      71,   181,    67,    74,   205,   164,    73,     5,     6,     7,
      59,   165,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   100,    19,    20,   116,     8,   187,   114,   123,
      76,    13,   201,    15,   117,    17,   124,    19,    20,    61,
     206,   195,    21,    62,   115,    22,    23,   111,    24,   197,
     118,    25,   101,   125,   200,   112,   119,    26,   113,   139,
      77,    78,    24,   120,   121,   152,   153,   142,   154,   155,
     146,    26,   127,   122,   129,   132,     4,   143,     5,     6,
       7,   144,   130,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   156,   157,   158,   159,
     160,   133,   134,   135,   136,   161,   137,    67,   140,    78,
     147,   167,   162,    21,   166,   168,    22,    23,   179,    24,
     172,   180,    25,   174,    85,     5,     6,     7,    26,   183,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     184,    19,    20,   102,   103,   104,   185,   186,   105,   188,
     106,   107,   108,   189,   192,   190,   191,   193,   109,   194,
      21,    77,   204,    22,    23,   196,    24,   138,   203,    25,
     182,   199,   141,   148,   145,    26,   149,   151,   198,     0,
     150,   163,    28,     5,     0,     7,   207,     0,     8,     0,
      28,    11,     0,    13,    14,    15,     0,    17,   175,    19,
      20,     0,     0,     5,     0,     7,     0,     0,     8,     0,
       0,    11,     0,    13,    14,    15,     0,    17,    21,    19,
      20,    22,    23,     0,    24,     8,     0,    25,     0,     0,
      13,     0,    15,    26,    17,     0,    19,    20,    21,     0,
       0,    22,    23,     0,    24,     8,     0,    25,     0,     0,
      13,     0,    15,    26,    17,    21,    19,    20,    22,    23,
       0,    24,     0,     0,    25,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,    24,     0,     0,    25,     0,     0,     0,     0,     0,
      26,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
       2,     9,    23,     0,    12,   134,    14,    35,    16,    21,
      22,   140,    20,    25,    17,    34,    24,    20,    21,    22,
      34,    40,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    62,    36,    37,    55,    25,   166,    51,    37,
      68,    30,   194,    32,    64,    34,    44,    36,    37,    34,
     202,   180,    55,    34,    67,    58,    59,    63,    61,   188,
      43,    64,    38,    61,   193,    69,    49,    70,    39,    77,
      23,    24,    61,    56,    57,   114,   115,    85,   116,   117,
     101,    70,    61,    65,    48,    42,    18,    95,    20,    21,
      22,    99,    61,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   118,   119,   120,   121,
     122,    41,    41,    16,    42,   123,    40,   125,    41,    24,
      59,   129,    34,    55,    41,    34,    58,    59,   136,    61,
      66,    41,    64,    34,     6,    20,    21,    22,    70,     6,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      16,    36,    37,    45,    46,    47,    40,    40,    50,    41,
      52,    53,    54,    41,   172,    40,    42,    41,    60,    19,
      55,    23,     6,    58,    59,   183,    61,    76,   195,    64,
     142,   191,    80,   110,   100,    70,   111,   113,   189,    -1,
     112,   125,   194,    20,    -1,    22,   204,    -1,    25,    -1,
     202,    28,    -1,    30,    31,    32,    -1,    34,    35,    36,
      37,    -1,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    32,    -1,    34,    55,    36,
      37,    58,    59,    -1,    61,    25,    -1,    64,    -1,    -1,
      30,    -1,    32,    70,    34,    -1,    36,    37,    55,    -1,
      -1,    58,    59,    -1,    61,    25,    -1,    64,    -1,    -1,
      30,    -1,    32,    70,    34,    55,    36,    37,    58,    59,
      -1,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    73,     0,    18,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    55,    58,    59,    61,    64,    70,    74,    75,    76,
      77,    78,    83,    84,    85,    86,    87,    89,    90,    91,
      95,    97,    98,    99,   107,   108,   109,   110,   111,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   123,    34,
     107,    34,    34,    88,   107,   107,   107,   107,   124,   125,
     119,   119,   110,   107,   119,    35,    68,    23,    24,    92,
      93,    94,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    41,    79,    80,    81,    82,
      62,    38,    45,    46,    47,    50,    52,    53,    54,    60,
     112,    63,    69,    39,    51,    67,    55,    64,    43,    49,
      56,    57,    65,    37,    44,    61,   122,    61,    96,    48,
      61,   101,    42,    41,    41,    16,    42,    40,    77,   107,
      41,    94,   107,   107,   107,   109,   110,    59,   113,   114,
     115,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     119,   107,    34,   124,    34,    40,    41,   107,    34,   102,
     103,   104,    66,   100,    34,    35,    75,   105,   105,   107,
      41,   105,    80,     6,    16,    40,    40,   105,    41,    41,
      40,    42,   107,    41,    19,   105,   107,   105,   121,   104,
     105,    74,   106,    93,     6,    17,    74,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    85,
      86,    87,    88,    88,    89,    89,    89,    89,    89,    90,
      91,    92,    92,    92,    92,    93,    93,    94,    95,    96,
      96,    96,    97,    98,    99,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   104,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     2,     1,     2,     1,     0,     3,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     2,     1,     0,     5,     4,     3,     5,     3,
       2,     0,     6,     4,     6,     2,     0,     3,     1,     0,
       3,     1,     3,     1,     5,     1,     4,     2,     1,     1,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     3,
       2,     3,     3,     2,     0,     1,     1,     1,     1,     1,
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
#line 207 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1450 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 218 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1458 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 222 "parser.y"
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
#line 1478 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 238 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1486 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 244 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1494 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 248 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1502 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 254 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1510 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt_dash ";" small_stmt  */
#line 260 "parser.y"
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
#line 1525 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 271 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1533 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 278 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1541 "parser.tab.c"
    break;

  case 12: /* small_stmt: flow_stmt  */
#line 282 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1549 "parser.tab.c"
    break;

  case 13: /* small_stmt: global_stmt  */
#line 286 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1557 "parser.tab.c"
    break;

  case 14: /* expr_stmt: test expr_stmt_dash  */
#line 292 "parser.y"
    {
        (yyval.node) = makeNode("EXPR_STATEMENT",STATEMENT_TYPE);
        if ((yyvsp[0].node) == NULL){
            appendChild((yyval.node), (yyvsp[-1].node));
        }else{
            appendChild((yyval.node), (yyvsp[0].node));
            insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
        }
    }
#line 1571 "parser.tab.c"
    break;

  case 15: /* expr_stmt_dash: annasign  */
#line 304 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1579 "parser.tab.c"
    break;

  case 16: /* expr_stmt_dash: augassign test  */
#line 308 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1588 "parser.tab.c"
    break;

  case 17: /* expr_stmt_dash: assign_dash  */
#line 313 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1596 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: %empty  */
#line 317 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1604 "parser.tab.c"
    break;

  case 19: /* assign_dash: "=" test assign_dash  */
#line 323 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
    }
#line 1614 "parser.tab.c"
    break;

  case 20: /* assign_dash: "=" test  */
#line 329 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1623 "parser.tab.c"
    break;

  case 21: /* annasign: ":" test  */
#line 336 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1632 "parser.tab.c"
    break;

  case 22: /* annasign: ":" test "=" test  */
#line 341 "parser.y"
    {
        (yyval.node) = makeNode(": =", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1642 "parser.tab.c"
    break;

  case 23: /* augassign: "+="  */
#line 349 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1650 "parser.tab.c"
    break;

  case 24: /* augassign: "-="  */
#line 353 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1658 "parser.tab.c"
    break;

  case 25: /* augassign: "*="  */
#line 357 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1666 "parser.tab.c"
    break;

  case 26: /* augassign: "/="  */
#line 361 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1674 "parser.tab.c"
    break;

  case 27: /* augassign: "%="  */
#line 365 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1682 "parser.tab.c"
    break;

  case 28: /* augassign: "&="  */
#line 369 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1690 "parser.tab.c"
    break;

  case 29: /* augassign: "|="  */
#line 373 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1698 "parser.tab.c"
    break;

  case 30: /* augassign: "^="  */
#line 377 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1706 "parser.tab.c"
    break;

  case 31: /* augassign: "<<="  */
#line 381 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1714 "parser.tab.c"
    break;

  case 32: /* augassign: ">>="  */
#line 385 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1722 "parser.tab.c"
    break;

  case 33: /* augassign: "**="  */
#line 389 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1730 "parser.tab.c"
    break;

  case 34: /* augassign: "//="  */
#line 393 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1738 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 399 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1746 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 403 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1754 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 407 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1762 "parser.tab.c"
    break;

  case 38: /* break_stmt: "break"  */
#line 413 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
    }
#line 1770 "parser.tab.c"
    break;

  case 39: /* continue_stmt: "continue"  */
#line 419 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
    }
#line 1778 "parser.tab.c"
    break;

  case 40: /* return_stmt: "return" test  */
#line 425 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1787 "parser.tab.c"
    break;

  case 41: /* global_stmt: "global" NAME_dash  */
#line 432 "parser.y"
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
#line 1802 "parser.tab.c"
    break;

  case 42: /* NAME_dash: NAME_dash "," NAME  */
#line 445 "parser.y"
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
#line 1817 "parser.tab.c"
    break;

  case 43: /* NAME_dash: NAME  */
#line 456 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1825 "parser.tab.c"
    break;

  case 44: /* compound_stmt: funcdef  */
#line 462 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1833 "parser.tab.c"
    break;

  case 45: /* compound_stmt: if_stmt  */
#line 466 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1841 "parser.tab.c"
    break;

  case 46: /* compound_stmt: while_stmt  */
#line 470 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1849 "parser.tab.c"
    break;

  case 47: /* compound_stmt: for_stmt  */
#line 474 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1857 "parser.tab.c"
    break;

  case 48: /* compound_stmt: classdef  */
#line 478 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1865 "parser.tab.c"
    break;

  case 49: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 484 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1876 "parser.tab.c"
    break;

  case 50: /* if_stmt_dash: "if" test ":" suite  */
#line 493 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1886 "parser.tab.c"
    break;

  case 51: /* else_stmt_dash: else_stmt  */
#line 501 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1894 "parser.tab.c"
    break;

  case 52: /* else_stmt_dash: elif_stmt else_stmt  */
#line 505 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1903 "parser.tab.c"
    break;

  case 53: /* else_stmt_dash: elif_stmt  */
#line 510 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1911 "parser.tab.c"
    break;

  case 54: /* else_stmt_dash: %empty  */
#line 513 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1919 "parser.tab.c"
    break;

  case 55: /* elif_stmt: "elif" test ":" suite elif_stmt  */
#line 519 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 1930 "parser.tab.c"
    break;

  case 56: /* elif_stmt: "elif" test ":" suite  */
#line 526 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1940 "parser.tab.c"
    break;

  case 57: /* else_stmt: "else" ":" suite  */
#line 534 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1949 "parser.tab.c"
    break;

  case 58: /* classdef: "class" NAME inheritlist ":" suite  */
#line 541 "parser.y"
    {
        (yyval.node) = makeNode("",CLASS_TYPE);
        appendChild((yyval.node), (yyvsp[-3].node));
        if ((yyvsp[-2].node) != NULL){
            appendChild((yyval.node), (yyvsp[-2].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1962 "parser.tab.c"
    break;

  case 59: /* inheritlist: "(" NAME ")"  */
#line 552 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1970 "parser.tab.c"
    break;

  case 60: /* inheritlist: "(" ")"  */
#line 557 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1978 "parser.tab.c"
    break;

  case 61: /* inheritlist: %empty  */
#line 561 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1986 "parser.tab.c"
    break;

  case 62: /* for_stmt: "for" test "in" test ":" suite  */
#line 567 "parser.y"
    {   
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1997 "parser.tab.c"
    break;

  case 63: /* while_stmt: "while" test ":" suite  */
#line 576 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2007 "parser.tab.c"
    break;

  case 64: /* funcdef: "def" NAME parameters funcdef_dash ":" suite  */
#line 583 "parser.y"
                                                       {
        (yyval.node) = makeNode("def",FUNCTION_TYPE);
        appendChild((yyval.node),(yyvsp[-4].node));
        appendChild((yyval.node),(yyvsp[-3].node));
        appendChild((yyval.node),(yyvsp[-2].node));
        
        if ((yyvsp[-2].node) != NULL){
            appendChild((yyval.node),(yyvsp[-2].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2023 "parser.tab.c"
    break;

  case 65: /* funcdef_dash: "->" test  */
#line 597 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2031 "parser.tab.c"
    break;

  case 66: /* funcdef_dash: %empty  */
#line 601 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2039 "parser.tab.c"
    break;

  case 67: /* parameters: "(" parameters_dash ")"  */
#line 607 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2047 "parser.tab.c"
    break;

  case 68: /* parameters_dash: typedargslist  */
#line 613 "parser.y"
    {
        if ((yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2060 "parser.tab.c"
    break;

  case 69: /* parameters_dash: %empty  */
#line 622 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2068 "parser.tab.c"
    break;

  case 70: /* typedargslist: typedargslist "," tfpdef  */
#line 628 "parser.y"
    {
        if ((yyvsp[-2].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[-2].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = makeNode("parameters", PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[-2].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2083 "parser.tab.c"
    break;

  case 71: /* typedargslist: tfpdef  */
#line 639 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2091 "parser.tab.c"
    break;

  case 72: /* tfpdef: NAME ":" atom_expr  */
#line 645 "parser.y"
    {
        (yyval.node) = makeNode("",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2101 "parser.tab.c"
    break;

  case 73: /* tfpdef: NAME  */
#line 652 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2109 "parser.tab.c"
    break;

  case 74: /* tfpdef: NAME ":" atom_expr "=" test  */
#line 657 "parser.y"
    {
        (yyval.node) = makeNode("",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2120 "parser.tab.c"
    break;

  case 75: /* suite: simple_stmt  */
#line 666 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2129 "parser.tab.c"
    break;

  case 76: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 671 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2140 "parser.tab.c"
    break;

  case 77: /* stmt_dash: stmt_dash stmt  */
#line 680 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2149 "parser.tab.c"
    break;

  case 78: /* stmt_dash: stmt  */
#line 685 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2158 "parser.tab.c"
    break;

  case 79: /* test: or_test  */
#line 692 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2166 "parser.tab.c"
    break;

  case 80: /* or_test: and_test  */
#line 698 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2174 "parser.tab.c"
    break;

  case 81: /* or_test: or_test "or" and_test  */
#line 702 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2184 "parser.tab.c"
    break;

  case 82: /* and_test: not_test  */
#line 710 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2192 "parser.tab.c"
    break;

  case 83: /* and_test: and_test "and" not_test  */
#line 714 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2202 "parser.tab.c"
    break;

  case 84: /* not_test: "not" not_test  */
#line 722 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2211 "parser.tab.c"
    break;

  case 85: /* not_test: comparison  */
#line 727 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2219 "parser.tab.c"
    break;

  case 86: /* comparison: comparison comp_op expr  */
#line 733 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2229 "parser.tab.c"
    break;

  case 87: /* comparison: expr  */
#line 739 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2237 "parser.tab.c"
    break;

  case 88: /* comp_op: "<"  */
#line 745 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2245 "parser.tab.c"
    break;

  case 89: /* comp_op: ">"  */
#line 749 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2253 "parser.tab.c"
    break;

  case 90: /* comp_op: "=="  */
#line 753 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2261 "parser.tab.c"
    break;

  case 91: /* comp_op: ">="  */
#line 757 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2269 "parser.tab.c"
    break;

  case 92: /* comp_op: "<="  */
#line 761 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2277 "parser.tab.c"
    break;

  case 93: /* comp_op: "<>"  */
#line 765 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2285 "parser.tab.c"
    break;

  case 94: /* comp_op: "!="  */
#line 769 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2293 "parser.tab.c"
    break;

  case 95: /* comp_op: "is"  */
#line 773 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2301 "parser.tab.c"
    break;

  case 96: /* comp_op: "is" "not"  */
#line 777 "parser.y"
    {
        (yyval.node) = makeNode("is not", OPERATOR_TYPE);
    }
#line 2309 "parser.tab.c"
    break;

  case 97: /* expr: xor_expr  */
#line 783 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2317 "parser.tab.c"
    break;

  case 98: /* expr: expr "|" xor_expr  */
#line 787 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2327 "parser.tab.c"
    break;

  case 99: /* xor_expr: and_expr  */
#line 795 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2335 "parser.tab.c"
    break;

  case 100: /* xor_expr: xor_expr "^" and_expr  */
#line 799 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2345 "parser.tab.c"
    break;

  case 101: /* and_expr: shift_expr  */
#line 807 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2353 "parser.tab.c"
    break;

  case 102: /* and_expr: and_expr "&" shift_expr  */
#line 811 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2363 "parser.tab.c"
    break;

  case 103: /* shift_expr: arith_expr  */
#line 819 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2371 "parser.tab.c"
    break;

  case 104: /* shift_expr: shift_expr "<<" arith_expr  */
#line 823 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2381 "parser.tab.c"
    break;

  case 105: /* shift_expr: shift_expr ">>" arith_expr  */
#line 829 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2391 "parser.tab.c"
    break;

  case 106: /* arith_expr: term  */
#line 837 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2399 "parser.tab.c"
    break;

  case 107: /* arith_expr: arith_expr "+" term  */
#line 841 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2409 "parser.tab.c"
    break;

  case 108: /* arith_expr: arith_expr "-" term  */
#line 847 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2419 "parser.tab.c"
    break;

  case 109: /* term: factor  */
#line 855 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2427 "parser.tab.c"
    break;

  case 110: /* term: term "*" factor  */
#line 859 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2437 "parser.tab.c"
    break;

  case 111: /* term: term "/" factor  */
#line 865 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2447 "parser.tab.c"
    break;

  case 112: /* term: term "%" factor  */
#line 871 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2457 "parser.tab.c"
    break;

  case 113: /* term: term "//" factor  */
#line 877 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2467 "parser.tab.c"
    break;

  case 114: /* factor: "+" factor  */
#line 885 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2476 "parser.tab.c"
    break;

  case 115: /* factor: "-" factor  */
#line 890 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2485 "parser.tab.c"
    break;

  case 116: /* factor: "~" factor  */
#line 895 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2494 "parser.tab.c"
    break;

  case 117: /* factor: power  */
#line 900 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2502 "parser.tab.c"
    break;

  case 118: /* power: atom_expr  */
#line 906 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2510 "parser.tab.c"
    break;

  case 119: /* power: atom_expr "**" factor  */
#line 910 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2520 "parser.tab.c"
    break;

  case 120: /* atom_expr: atom trailer  */
#line 918 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
        }else{
            (yyval.node) = makeNode("atom_expr", EXPR_TYPE);
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2534 "parser.tab.c"
    break;

  case 121: /* trailer: "(" arglist ")"  */
#line 930 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2547 "parser.tab.c"
    break;

  case 122: /* trailer: "[" test "]"  */
#line 939 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 2556 "parser.tab.c"
    break;

  case 123: /* trailer: "." NAME  */
#line 944 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2565 "parser.tab.c"
    break;

  case 124: /* trailer: %empty  */
#line 949 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2573 "parser.tab.c"
    break;

  case 125: /* atom: NAME  */
#line 955 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
    }
#line 2581 "parser.tab.c"
    break;

  case 126: /* atom: NUMBER  */
#line 959 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NUMBER_TYPE);
    }
#line 2589 "parser.tab.c"
    break;

  case 127: /* atom: STRING  */
#line 963 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
    }
#line 2597 "parser.tab.c"
    break;

  case 128: /* atom: "None"  */
#line 967 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2605 "parser.tab.c"
    break;

  case 129: /* atom: "True"  */
#line 971 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
    }
#line 2613 "parser.tab.c"
    break;

  case 130: /* atom: "False"  */
#line 975 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
    }
#line 2621 "parser.tab.c"
    break;

  case 131: /* atom: "(" test ")"  */
#line 979 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2629 "parser.tab.c"
    break;

  case 132: /* atom: "[" arglist "]"  */
#line 983 "parser.y"
    {
        (yyval.node) = makeNode("[]", LIST_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 2642 "parser.tab.c"
    break;

  case 133: /* arglist: arglist_dash  */
#line 994 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2650 "parser.tab.c"
    break;

  case 134: /* arglist: %empty  */
#line 998 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2658 "parser.tab.c"
    break;

  case 135: /* arglist_dash: arglist_dash "," test  */
#line 1004 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2667 "parser.tab.c"
    break;

  case 136: /* arglist_dash: test  */
#line 1009 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2676 "parser.tab.c"
    break;


#line 2680 "parser.tab.c"

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

#line 1016 "parser.y"

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
