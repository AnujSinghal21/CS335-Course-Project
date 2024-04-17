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

#include "includes.hpp"
extern stack<int> indent_stack;
extern int yylineno;
extern FILE* yyin;
extern string last_token;
extern string last_token_value;
extern int terminated;
extern symtable_global* global_symtable;
extern symtable_entry* symtable_look_up(string temp);
extern symtable_global* global_symtable;
extern map<string, string> id_to_label;
extern map<string, vector<string> > edges;
extern symtable_func* curr_symtable_func;
extern symtable_class* curr_symtable_class;
extern symtable_global* curr_symtable_global;
extern unordered_set<string> declared_types;
extern ofstream threeac_file;
extern struct type int_node;
extern struct type float_node;
extern struct type bool_node;
extern struct type str_node;
extern struct type void_node;
extern TreeNode * root;

int yylex();


#line 100 "parser.tab.c"

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
  YYSYMBOL_91_1 = 91,                      /* $@1  */
  YYSYMBOL_else_stmt_dash = 92,            /* else_stmt_dash  */
  YYSYMBOL_elif_stmt = 93,                 /* elif_stmt  */
  YYSYMBOL_94_2 = 94,                      /* $@2  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_96_4 = 96,                      /* $@4  */
  YYSYMBOL_else_stmt = 97,                 /* else_stmt  */
  YYSYMBOL_98_5 = 98,                      /* $@5  */
  YYSYMBOL_classdef = 99,                  /* classdef  */
  YYSYMBOL_100_6 = 100,                    /* $@6  */
  YYSYMBOL_inheritlist = 101,              /* inheritlist  */
  YYSYMBOL_for_stmt = 102,                 /* for_stmt  */
  YYSYMBOL_103_7 = 103,                    /* $@7  */
  YYSYMBOL_104_8 = 104,                    /* $@8  */
  YYSYMBOL_while_stmt = 105,               /* while_stmt  */
  YYSYMBOL_106_9 = 106,                    /* $@9  */
  YYSYMBOL_107_10 = 107,                   /* $@10  */
  YYSYMBOL_funcdef = 108,                  /* funcdef  */
  YYSYMBOL_109_11 = 109,                   /* $@11  */
  YYSYMBOL_funcdef_dash = 110,             /* funcdef_dash  */
  YYSYMBOL_parameters = 111,               /* parameters  */
  YYSYMBOL_parameters_dash = 112,          /* parameters_dash  */
  YYSYMBOL_typedargslist = 113,            /* typedargslist  */
  YYSYMBOL_tfpdef = 114,                   /* tfpdef  */
  YYSYMBOL_suite = 115,                    /* suite  */
  YYSYMBOL_stmt_dash = 116,                /* stmt_dash  */
  YYSYMBOL_test = 117,                     /* test  */
  YYSYMBOL_or_test = 118,                  /* or_test  */
  YYSYMBOL_and_test = 119,                 /* and_test  */
  YYSYMBOL_not_test = 120,                 /* not_test  */
  YYSYMBOL_comparison = 121,               /* comparison  */
  YYSYMBOL_comp_op = 122,                  /* comp_op  */
  YYSYMBOL_expr = 123,                     /* expr  */
  YYSYMBOL_xor_expr = 124,                 /* xor_expr  */
  YYSYMBOL_and_expr = 125,                 /* and_expr  */
  YYSYMBOL_shift_expr = 126,               /* shift_expr  */
  YYSYMBOL_arith_expr = 127,               /* arith_expr  */
  YYSYMBOL_term = 128,                     /* term  */
  YYSYMBOL_factor = 129,                   /* factor  */
  YYSYMBOL_power = 130,                    /* power  */
  YYSYMBOL_atom_expr = 131,                /* atom_expr  */
  YYSYMBOL_trailerlist = 132,              /* trailerlist  */
  YYSYMBOL_trailer = 133,                  /* trailer  */
  YYSYMBOL_atom = 134,                     /* atom  */
  YYSYMBOL_arglist = 135,                  /* arglist  */
  YYSYMBOL_arglist_dash = 136              /* arglist_dash  */
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
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

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
       0,   163,   163,   173,   177,   194,   199,   203,   209,   216,
     227,   233,   238,   242,   248,   394,   398,   403,   408,   413,
     425,   435,   440,   448,   452,   456,   460,   464,   468,   472,
     476,   480,   484,   488,   492,   498,   502,   506,   512,   527,
     543,   552,   559,   578,   589,   595,   599,   603,   607,   611,
     617,   628,   627,   641,   655,   658,   662,   654,   681,   686,
     693,   692,   703,   703,   722,   727,   732,   739,   749,   738,
     811,   815,   810,   833,   833,   862,   867,   872,   878,   888,
     893,   904,   910,   917,   929,   938,   943,   952,   957,   964,
     970,   974,   993,   997,  1015,  1030,  1036,  1054,  1061,  1065,
    1069,  1073,  1077,  1081,  1085,  1091,  1095,  1113,  1117,  1135,
    1139,  1157,  1161,  1177,  1195,  1199,  1215,  1233,  1237,  1253,
    1269,  1285,  1303,  1317,  1331,  1346,  1353,  1357,  1374,  1670,
    1682,  1686,  1695,  1700,  1707,  1720,  1737,  1744,  1750,  1756,
    1762,  1766,  1779,  1784,  1789,  1794
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
  "compound_stmt", "if_stmt", "if_stmt_dash", "$@1", "else_stmt_dash",
  "elif_stmt", "$@2", "$@3", "$@4", "else_stmt", "$@5", "classdef", "$@6",
  "inheritlist", "for_stmt", "$@7", "$@8", "while_stmt", "$@9", "$@10",
  "funcdef", "$@11", "funcdef_dash", "parameters", "parameters_dash",
  "typedargslist", "tfpdef", "suite", "stmt_dash", "test", "or_test",
  "and_test", "not_test", "comparison", "comp_op", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "factor", "power",
  "atom_expr", "trailerlist", "trailer", "atom", "arglist", "arglist_dash", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-178)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -178,    29,    36,  -178,  -178,  -178,     0,  -178,  -178,    81,
       9,    15,   198,  -178,   198,  -178,  -178,  -178,  -178,  -178,
     198,   206,   206,   198,   198,   206,  -178,  -178,  -178,   -29,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    13,
    -178,  -178,  -178,  -178,   273,    17,    14,  -178,  -178,    30,
      -8,    40,   -36,   -23,    42,  -178,  -178,    22,  -178,    27,
      47,    48,  -178,    65,    68,  -178,   198,  -178,    94,    70,
    -178,  -178,  -178,    74,  -178,  -178,   190,  -178,    75,  -178,
    -178,  -178,  -178,  -178,  -178,   198,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,   198,  -178,  -178,  -178,   198,
     198,   198,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,    -9,    -1,  -178,  -178,    85,    55,    88,  -178,
      82,  -178,   198,  -178,  -178,   198,  -178,   119,   123,  -178,
      14,  -178,    -8,    83,    40,   -36,   -23,   -23,    42,    42,
    -178,  -178,  -178,  -178,  -178,   198,    96,   198,  -178,   107,
    -178,   108,   198,   111,   113,   112,  -178,   198,  -178,  -178,
     148,  -178,  -178,   114,   148,  -178,   198,   132,  -178,   117,
    -178,   148,   118,   198,  -178,    85,  -178,   120,   139,  -178,
    -178,   148,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   156,
    -178,   148,   106,  -178,   148,   148,   198,  -178,  -178,   -10,
    -178,  -178,  -178,  -178,  -178,    13,  -178
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     2,    38,     0,    39,   139,     0,
       0,     0,     0,   137,    41,   138,    70,   134,     3,   135,
     143,     0,     0,     0,     0,     0,   136,     4,     6,     0,
      10,    11,    12,    35,    36,    37,    13,     7,    46,    59,
      49,    48,    47,    45,    18,    89,    90,    92,    95,    97,
     105,   107,   109,   111,   114,   117,   125,   126,   130,    66,
       0,     0,    44,    42,     0,    40,     0,   145,     0,   142,
     123,   124,    94,     0,   122,     8,     0,    54,     0,    50,
      53,    58,    28,    26,    34,     0,    31,    24,    27,    25,
      29,    23,    33,    32,    30,     0,    14,    17,    15,     0,
       0,     0,   100,    99,   101,   103,    98,   102,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,    62,    67,    79,    76,     0,    51,
       0,   141,     0,   140,     9,     0,    60,    20,    21,    16,
      91,    93,   106,    96,   108,   110,   112,   113,   116,   115,
     119,   121,   120,   118,   127,     0,     0,   143,   129,     0,
      65,     0,     0,    83,     0,    78,    81,     0,    73,    43,
       0,    71,   144,     0,     0,    19,     0,     0,   133,     0,
      64,     0,     0,     0,    77,     0,    75,     0,     0,    85,
      52,     0,    55,    61,    22,   132,   131,    63,    68,    82,
      80,     0,     0,    72,     0,     0,     0,    74,    88,     0,
      56,    69,    84,    86,    87,    59,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -177,    -2,  -178,    91,  -178,  -178,    34,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   -41,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,    -4,   115,  -178,   -11,  -178,    77,
     -21,  -178,  -178,    76,    78,    79,    80,   -72,   -70,   -17,
    -178,  -178,  -178,  -178,   179,    32,  -178
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,   189,    29,    30,    31,    96,    97,
      98,    99,    32,    33,    34,    35,    36,    63,    37,    38,
      39,   170,    79,    80,   135,   204,   215,    81,   174,    40,
     161,   124,    41,   162,   205,    42,    66,   191,    43,   187,
     168,   127,   164,   165,   166,   190,   209,    44,    45,    46,
      47,    48,   110,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   122,   158,    58,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    64,    72,    65,    70,    71,    75,   213,    74,    67,
       5,     6,     7,    73,   113,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,   208,    19,    20,   155,     3,
     114,   115,   214,   159,    59,   156,    77,    78,    76,   160,
     116,   146,   147,    61,    21,   148,   149,    22,    23,    62,
      24,   157,   101,    25,     4,   130,     5,     6,     7,    26,
     111,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   137,   102,   103,   104,   100,   112,
     141,   105,   106,   107,   138,   117,   121,   123,   139,   108,
      21,   118,   109,    22,    23,   125,    24,   119,   120,    25,
     150,   151,   152,   153,   154,    26,     8,   128,   126,   129,
     131,    13,   132,    15,   133,    17,   136,    19,    20,   163,
     167,   172,   169,   171,   173,    85,     5,     6,     7,   176,
     178,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    24,    19,    20,   177,   109,    67,   180,   195,   181,
      26,   182,   183,   184,   185,   192,   186,   196,   202,   198,
      21,   201,   206,    22,    23,   194,    24,   134,     5,    25,
       7,   175,   199,     8,   216,    26,    11,   140,    13,    14,
      15,   200,    17,   188,    19,    20,   143,   142,    60,   179,
     144,     0,   145,     0,     0,   212,     0,     0,     0,     0,
      28,     0,    21,     0,     0,    22,    23,    28,    24,     0,
       5,    25,     7,     0,     0,     8,     0,    26,    11,     0,
      13,    14,    15,     8,    17,     0,    19,    20,    13,     0,
      15,     8,    17,     0,    19,    20,    13,     0,    15,     0,
      17,     0,    19,    20,    21,     0,     0,    22,    23,     0,
      24,     0,    21,    25,     0,    22,    23,     0,    24,    26,
      21,    25,     0,    22,     0,     0,    24,    26,     0,    25,
       0,     0,     0,     0,     0,    26,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   193,
       0,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,     0,    95,     0,   207,     0,     0,   210,
     211
};

static const yytype_int16 yycheck[] =
{
       2,    12,    23,    14,    21,    22,    35,    17,    25,    20,
      20,    21,    22,    24,    50,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   202,    36,    37,    37,     0,
      66,    54,   209,    34,    34,    44,    23,    24,    67,    40,
      63,   113,   114,    34,    54,   115,   116,    57,    58,    34,
      60,    60,    38,    63,    18,    66,    20,    21,    22,    69,
      68,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    85,    45,    46,    47,    61,    39,
     101,    51,    52,    53,    95,    43,    64,    60,    99,    59,
      54,    49,    62,    57,    58,    48,    60,    55,    56,    63,
     117,   118,   119,   120,   121,    69,    25,    42,    60,    41,
      16,    30,    42,    32,    40,    34,    41,    36,    37,    34,
      65,   132,    34,    41,   135,     6,    20,    21,    22,     6,
      34,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    60,    36,    37,   155,    62,   157,    40,    16,    41,
      69,   162,    41,    40,    42,    41,   167,    40,    19,    41,
      54,    41,     6,    57,    58,   176,    60,    76,    20,    63,
      22,   137,   183,    25,   215,    69,    28,   100,    30,    31,
      32,   185,    34,    35,    36,    37,   110,   109,     9,   157,
     111,    -1,   112,    -1,    -1,   206,    -1,    -1,    -1,    -1,
     202,    -1,    54,    -1,    -1,    57,    58,   209,    60,    -1,
      20,    63,    22,    -1,    -1,    25,    -1,    69,    28,    -1,
      30,    31,    32,    25,    34,    -1,    36,    37,    30,    -1,
      32,    25,    34,    -1,    36,    37,    30,    -1,    32,    -1,
      34,    -1,    36,    37,    54,    -1,    -1,    57,    58,    -1,
      60,    -1,    54,    63,    -1,    57,    58,    -1,    60,    69,
      54,    63,    -1,    57,    -1,    -1,    60,    69,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,   201,    -1,    -1,   204,
     205
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    72,     0,    18,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    54,    57,    58,    60,    63,    69,    73,    74,    75,
      76,    77,    82,    83,    84,    85,    86,    88,    89,    90,
      99,   102,   105,   108,   117,   118,   119,   120,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   134,    34,
     134,    34,    34,    87,   117,   117,   106,   117,   135,   136,
     129,   129,   120,   117,   129,    35,    67,    23,    24,    92,
      93,    97,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    41,    78,    79,    80,    81,
      61,    38,    45,    46,    47,    51,    52,    53,    59,    62,
     122,    68,    39,    50,    66,    54,    63,    43,    49,    55,
      56,    64,   132,    60,   101,    48,    60,   111,    42,    41,
     117,    16,    42,    40,    76,    94,    41,   117,   117,   117,
     119,   120,   124,   123,   125,   126,   127,   127,   128,   128,
     129,   129,   129,   129,   129,    37,    44,    60,   133,    34,
      40,   100,   103,    34,   112,   113,   114,    65,   110,    34,
      91,    41,   117,   117,    98,    79,     6,   117,    34,   135,
      40,    41,   117,    41,    40,    42,   117,   109,    35,    74,
     115,   107,    41,   115,   117,    16,    40,   115,    41,   117,
     114,    41,    19,   115,    95,   104,     6,   115,    73,   116,
     115,   115,   117,    17,    73,    96,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    78,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    88,    88,
      89,    91,    90,    92,    94,    95,    96,    93,    93,    93,
      98,    97,   100,    99,   101,   101,   101,   103,   104,   102,
     106,   107,   105,   109,   108,   110,   110,   111,   112,   112,
     113,   113,   114,   114,   114,   115,   115,   116,   116,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   127,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   132,
     132,   133,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   135,   136,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     2,     1,     2,     1,     0,     3,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       2,     0,     5,     1,     0,     0,     0,     8,     1,     0,
       0,     4,     0,     6,     3,     2,     0,     0,     0,     8,
       0,     0,     6,     0,     7,     2,     0,     3,     1,     0,
       3,     1,     3,     1,     5,     1,     4,     2,     1,     1,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     2,     2,     2,     1,     1,     3,     2,     2,
       0,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     0,     3,     1
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
#line 163 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1425 "parser.tab.c"
    break;

  case 3: /* input_file_dash: input_file_dash NEWLINE  */
#line 174 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1433 "parser.tab.c"
    break;

  case 4: /* input_file_dash: input_file_dash stmt  */
#line 178 "parser.y"
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
#line 1453 "parser.tab.c"
    break;

  case 5: /* input_file_dash: %empty  */
#line 194 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1461 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 200 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1469 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 204 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1477 "parser.tab.c"
    break;

  case 8: /* simple_stmt: small_stmt_dash NEWLINE  */
#line 210 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1486 "parser.tab.c"
    break;

  case 9: /* small_stmt_dash: small_stmt_dash ";" small_stmt  */
#line 217 "parser.y"
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
#line 1501 "parser.tab.c"
    break;

  case 10: /* small_stmt_dash: small_stmt  */
#line 228 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1509 "parser.tab.c"
    break;

  case 11: /* small_stmt: expr_stmt  */
#line 234 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1518 "parser.tab.c"
    break;

  case 12: /* small_stmt: flow_stmt  */
#line 239 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1526 "parser.tab.c"
    break;

  case 13: /* small_stmt: global_stmt  */
#line 243 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1534 "parser.tab.c"
    break;

  case 14: /* expr_stmt: test expr_stmt_dash  */
#line 249 "parser.y"
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

        symtable_entry* entry=NULL; 
        symtable_entry* class_entry = NULL;
        if((yyvsp[0].node) != NULL && ((yyvsp[0].node)->lexeme == ":" || (yyvsp[0].node)->lexeme == ":=")){
            
            if ((yyvsp[0].node)->children[0]->node_type == NAME_TYPE){
                if(curr_symtable_func!=NULL){
                    entry = curr_symtable_func->add_entry((yyvsp[0].node),yylineno);
                    (yyvsp[-1].node)->type = entry->type;
                }else{
                    entry = curr_symtable_global->add_global_var((yyvsp[0].node),yylineno);        
                    (yyvsp[-1].node)->type = entry->type;
                }
                (yyvsp[0].node)->children[0]->addr = (yyvsp[0].node)->children[0]->lexeme;
                entry->addr = (yyvsp[0].node)->children[0]->lexeme;
            }else if ((yyvsp[0].node)->children[0]->lexeme == "atom_expr"
                && (yyvsp[0].node)->children[0]->children.size() == 2
                && (yyvsp[0].node)->children[0]->children[0]->node_type == NAME_TYPE
                && (yyvsp[0].node)->children[0]->children[1]->node_type == TRAILER_TYPE
                && (yyvsp[0].node)->children[0]->children[0]->lexeme == "self"
                && (yyvsp[0].node)->children[0]->children[1]->children.size() == 1
                && (yyvsp[0].node)->children[0]->children[1]->children[0]->lexeme == "."
                && (yyvsp[0].node)->children[0]->children[1]->children[0]->children.size() == 1
                && (yyvsp[0].node)->children[0]->children[1]->children[0]->children[0]->node_type == NAME_TYPE
                && curr_symtable_class != NULL
            ){
                //DEBUG("CLASS ATTRIBUTE DECLARATION");
                class_entry = new symtable_entry();
                string classname = curr_symtable_class->name;
                classname += ".";
                classname += (yyvsp[0].node)->children[0]->children[1]->children[0]->children[0]->lexeme;
                class_entry->name = classname;
                class_entry->type = create_string_type((yyvsp[0].node)->children[1]);
                (yyvsp[-1].node)->type = class_entry->type;
                curr_symtable_class->attributes[classname] = class_entry;
                class_entry->offset = curr_symtable_class->size;
                curr_symtable_class->size += class_entry->type.size;
                //DEBUG("CLASS ATTRIBUTE ADDED");
            } else{
                DEBUG("error");
                Error::other_semantic_error("SYNTAX_ERROR: Expected Identifier in declaration", yylineno);
            }
            
            if((yyvsp[0].node)->children.size() == 3){
                if (!type_equal((yyvsp[-1].node)->type, (yyvsp[0].node)->children[2]->type)){
                    DEBUG("HERE");
                    DEBUG((yyvsp[-1].node)->type.t);
                    DEBUG((yyvsp[0].node)->children[2]->type.t)
                    Error::type_mismatch(yylineno, (yyvsp[-1].node)->type, (yyvsp[0].node)->children[2]->type, "initialization");
                    
                }else{
                    if (class_entry != NULL){
                        string t_off = three_ac::new_temp();
                        // three_ac::gen("class_get", "symtable", curr_symtable_class->name, $2->children[0]->children[1]->children[0]->children[0]->lexeme , t_off);
                        three_ac::gen("assign","=",to_string(class_entry->offset),"",t_off);
                        string t = three_ac::new_temp();
                        three_ac::gen("quad", "+", (yyvsp[0].node)->children[0]->children[0]->addr,t_off,t);
                        class_entry->addr = t;

                    }
                    if ((yyvsp[-1].node)->type.elems != -1 || (yyvsp[-1].node)->type.t == "str"){
                        // list or string declaration
                        if (entry != NULL){
                            (yyvsp[-1].node)->type.elems = (yyvsp[0].node)->children[2]->type.elems;
                            string list_form;

                            if((yyvsp[-1].node)->type.t != "str"){
                                list_form = "[";
                                DEBUG("List is " << (yyvsp[0].node)->children[2]->children.size())
                                for(int i = 0; i <(yyvsp[0].node)->children[2]->children.size();i++){
                                
                                    list_form += (yyvsp[0].node)->children[2]->children[i]->lexeme;
                                    if(i+1!=(yyvsp[0].node)->children[2]->children.size()){
                                        list_form += ",";
                                    }else{
                                        list_form += "]";
                                    }
                                }
                                DEBUG(list_form)
                            }else{
                                list_form = (yyvsp[0].node)->children[2]->lexeme;
                            }
                            string t = three_ac::new_temp();
                            // three_ac::gen("symtable_get", "symtable.get", $2->children[0]->lexeme, "", t);
                            three_ac::gen("assign","=",list_form,"",t);
                            entry->addr = t;
                        }

                    }else{
                        // normal var (name declaration)
                        string drt = three_ac::dereference((yyvsp[0].node)->children[2]);
                        if (entry != NULL){
                            entry->addr = entry->name;
                            three_ac::gen("assign", "=", drt, "", entry->name);
                        }else{
                            string t = three_ac::new_temp();
                            //DEBUG(drt)
                            three_ac::gen("address_assign", "=", drt, "", class_entry->addr);
                        }
                    }
                }
            } 
        }


        else if ((yyvsp[0].node) != NULL){
            string drt = three_ac::dereference((yyvsp[0].node)->children[1]);
            string op = (yyvsp[0].node)->lexeme;
            if (op == "="){
                if ((yyvsp[0].node)->children[0]->to_dereference){
                    three_ac::gen("address_assign", "=", drt, "", (yyvsp[0].node)->children[0]->addr);
                }else{
                    three_ac::gen("assign", "=", drt, "", (yyvsp[0].node)->children[0]->addr);
                }
            }else{
                if ((yyvsp[0].node)->children[0]->to_dereference){
                    string temp = three_ac::new_temp();
                    three_ac::gen("DEREF", "*", (yyvsp[0].node)->children[0]->addr, "", temp);
                    string op = (yyvsp[0].node)->children[1]->lexeme.substr(0, (yyvsp[0].node)->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, temp, drt, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", (yyvsp[0].node)->children[0]->addr);
                }else{
                    string op = (yyvsp[0].node)->children[1]->lexeme.substr(0, (yyvsp[0].node)->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, (yyvsp[0].node)->children[0]->addr, drt, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", (yyvsp[0].node)->children[0]->addr);
                }
            }
        }
    }
#line 1682 "parser.tab.c"
    break;

  case 15: /* expr_stmt_dash: annasign  */
#line 395 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1690 "parser.tab.c"
    break;

  case 16: /* expr_stmt_dash: augassign test  */
#line 399 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1699 "parser.tab.c"
    break;

  case 17: /* expr_stmt_dash: assign_dash  */
#line 404 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1707 "parser.tab.c"
    break;

  case 18: /* expr_stmt_dash: %empty  */
#line 408 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1715 "parser.tab.c"
    break;

  case 19: /* assign_dash: "=" test assign_dash  */
#line 414 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
        (yyval.node)->addr = (yyvsp[0].node)->addr;
        if ((yyvsp[-1].node)->to_dereference){
            three_ac::gen("address_assign", "=", (yyvsp[0].node)->addr, "", (yyvsp[-1].node)->addr);
        }else{
            three_ac::gen("assign", "=", (yyvsp[0].node)->addr, "", (yyvsp[-1].node)->addr);
        }
    }
#line 1731 "parser.tab.c"
    break;

  case 20: /* assign_dash: "=" test  */
#line 426 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
     
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = drt;
    }
#line 1743 "parser.tab.c"
    break;

  case 21: /* annasign: ":" test  */
#line 436 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1752 "parser.tab.c"
    break;

  case 22: /* annasign: ":" test "=" test  */
#line 441 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1762 "parser.tab.c"
    break;

  case 23: /* augassign: "+="  */
#line 449 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1770 "parser.tab.c"
    break;

  case 24: /* augassign: "-="  */
#line 453 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1778 "parser.tab.c"
    break;

  case 25: /* augassign: "*="  */
#line 457 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1786 "parser.tab.c"
    break;

  case 26: /* augassign: "/="  */
#line 461 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1794 "parser.tab.c"
    break;

  case 27: /* augassign: "%="  */
#line 465 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1802 "parser.tab.c"
    break;

  case 28: /* augassign: "&="  */
#line 469 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1810 "parser.tab.c"
    break;

  case 29: /* augassign: "|="  */
#line 473 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1818 "parser.tab.c"
    break;

  case 30: /* augassign: "^="  */
#line 477 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1826 "parser.tab.c"
    break;

  case 31: /* augassign: "<<="  */
#line 481 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1834 "parser.tab.c"
    break;

  case 32: /* augassign: ">>="  */
#line 485 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1842 "parser.tab.c"
    break;

  case 33: /* augassign: "**="  */
#line 489 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1850 "parser.tab.c"
    break;

  case 34: /* augassign: "//="  */
#line 493 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1858 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 499 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1866 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 503 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1874 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 507 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1882 "parser.tab.c"
    break;

  case 38: /* break_stmt: "break"  */
#line 513 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
        for (int i = three_ac::label_stack.size()-1; i >= 0; i--){
            if (three_ac::label_stack[i] % 10 == 2 ){
                three_ac::gen("goto", "goto", three_ac::get_label("while_end", three_ac::label_stack[i]));
                break;
            }else if (three_ac::label_stack[i] % 10 == 3){
                three_ac::gen("goto", "goto", three_ac::get_label("for_end", three_ac::label_stack[i]));
                break;
            }
        }
    }
#line 1899 "parser.tab.c"
    break;

  case 39: /* continue_stmt: "continue"  */
#line 528 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
        for (int i = three_ac::label_stack.size()-1; i >= 0; i--){
            if (three_ac::label_stack[i] % 10 == 2 ){
                three_ac::gen("goto", "goto", three_ac::get_label("while_start", three_ac::label_stack[i]));
                break;
            }else if (three_ac::label_stack[i] % 10 == 3){
                three_ac::gen("goto", "goto", three_ac::get_label("for_start", three_ac::label_stack[i]));
                break;
            }
        }

    }
#line 1917 "parser.tab.c"
    break;

  case 40: /* return_stmt: "return" test  */
#line 544 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        //checker_traverse($2);
        curr_symtable_func->check_returntype((yyvsp[0].node), yylineno);
        string drt = three_ac::dereference((yyvsp[0].node));
        three_ac::gen("return", "return", drt);
    }
#line 1930 "parser.tab.c"
    break;

  case 41: /* return_stmt: "return"  */
#line 553 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        three_ac::gen("return", "return");   
    }
#line 1939 "parser.tab.c"
    break;

  case 42: /* global_stmt: "global" NAME_dash  */
#line 560 "parser.y"
    {
        (yyval.node) = makeNode("global",STATEMENT_TYPE);
        if ((yyvsp[0].node)->node_type == MISC_TYPE){
            for (auto x: (yyvsp[0].node)->children){
                appendChild((yyval.node), x);
                symtable_entry* temp = new symtable_entry();
                temp->name = x->lexeme;
                curr_symtable_func->entries[temp->name]=temp;
            }
        }else{
            appendChild((yyval.node), (yyvsp[0].node));
            symtable_entry* temp = new symtable_entry();
                temp->name = (yyvsp[0].node)->lexeme;
                curr_symtable_func->entries[temp->name]=temp;
        }
    }
#line 1960 "parser.tab.c"
    break;

  case 43: /* NAME_dash: NAME_dash "," NAME  */
#line 579 "parser.y"
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
#line 1975 "parser.tab.c"
    break;

  case 44: /* NAME_dash: NAME  */
#line 590 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1983 "parser.tab.c"
    break;

  case 45: /* compound_stmt: funcdef  */
#line 596 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1991 "parser.tab.c"
    break;

  case 46: /* compound_stmt: if_stmt  */
#line 600 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1999 "parser.tab.c"
    break;

  case 47: /* compound_stmt: while_stmt  */
#line 604 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2007 "parser.tab.c"
    break;

  case 48: /* compound_stmt: for_stmt  */
#line 608 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2015 "parser.tab.c"
    break;

  case 49: /* compound_stmt: classdef  */
#line 612 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2023 "parser.tab.c"
    break;

  case 50: /* if_stmt: if_stmt_dash else_stmt_dash  */
#line 618 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
        (yyval.node)->type.t = "void";
    }
#line 2035 "parser.tab.c"
    break;

  case 51: /* $@1: %empty  */
#line 628 "parser.y"
    {
        three_ac::push_new_label("if");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, three_ac::get_label("else_start"));
    }
#line 2044 "parser.tab.c"
    break;

  case 52: /* if_stmt_dash: "if" test ":" $@1 suite  */
#line 632 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[0].node));
        string l = three_ac::get_label("if_end");
        three_ac::gen("goto", "goto", l);
    }
#line 2056 "parser.tab.c"
    break;

  case 53: /* else_stmt_dash: elif_stmt  */
#line 642 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        if ((yyvsp[0].node) == NULL){
            string l = three_ac::get_label("else_start");
            three_ac::gen("label", "label", l);
        }
        string l2 = three_ac::get_label("if_end");
        three_ac::gen("label", "label", l2);
        three_ac::pop_label();
    }
#line 2071 "parser.tab.c"
    break;

  case 54: /* $@2: %empty  */
#line 655 "parser.y"
    {
        three_ac::gen("label", "label", three_ac::get_label("else_start"));        
    }
#line 2079 "parser.tab.c"
    break;

  case 55: /* $@3: %empty  */
#line 658 "parser.y"
    {
        three_ac::push_new_label("if");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, three_ac::get_label("else_start"));
    }
#line 2088 "parser.tab.c"
    break;

  case 56: /* $@4: %empty  */
#line 662 "parser.y"
    {
        string l = three_ac::get_label("if_end");
        three_ac::gen("goto", "goto", l);
    }
#line 2097 "parser.tab.c"
    break;

  case 57: /* elif_stmt: "elif" $@2 test ":" $@3 suite $@4 elif_stmt  */
#line 667 "parser.y"
    {
        (yyval.node) = (yyvsp[-7].node);
        appendChild((yyval.node), (yyvsp[-5].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));   
        // // ifs khatam     
        if ((yyvsp[0].node) == NULL){
            string l = three_ac::get_label("else_start");
            three_ac::gen("label", "label", l);
        }
        string l2 = three_ac::get_label("if_end");
        three_ac::gen("label", "label", l2);
        three_ac::pop_label();
    }
#line 2116 "parser.tab.c"
    break;

  case 58: /* elif_stmt: else_stmt  */
#line 682 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2124 "parser.tab.c"
    break;

  case 59: /* elif_stmt: %empty  */
#line 686 "parser.y"
    {
        (yyval.node) = NULL;  

    }
#line 2133 "parser.tab.c"
    break;

  case 60: /* $@5: %empty  */
#line 693 "parser.y"
    {
        three_ac::gen("label", "label", three_ac::get_label("else_start"));
    }
#line 2141 "parser.tab.c"
    break;

  case 61: /* else_stmt: "else" ":" $@5 suite  */
#line 697 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2150 "parser.tab.c"
    break;

  case 62: /* $@6: %empty  */
#line 703 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
        declared_types.insert((yyvsp[-1].node)->lexeme);
        curr_symtable_global->add_len_func((yyvsp[-1].node)->lexeme);
    }
#line 2161 "parser.tab.c"
    break;

  case 63: /* classdef: "class" NAME inheritlist $@6 ":" suite  */
#line 709 "parser.y"
    {
        (yyval.node) = makeNode("",CLASS_TYPE);
        (yyval.node)->type.t = "void";
        appendChild((yyval.node), (yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node), (yyvsp[-3].node));
        }
        appendChild((yyval.node), (yyvsp[0].node));

        curr_symtable_class = NULL;
    }
#line 2177 "parser.tab.c"
    break;

  case 64: /* inheritlist: "(" NAME ")"  */
#line 723 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2185 "parser.tab.c"
    break;

  case 65: /* inheritlist: "(" ")"  */
#line 728 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2193 "parser.tab.c"
    break;

  case 66: /* inheritlist: %empty  */
#line 732 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2201 "parser.tab.c"
    break;

  case 67: /* $@7: %empty  */
#line 739 "parser.y"
    {
        three_ac::push_new_label("for");
        three_ac::gen("label", "label", three_ac::get_label("for_init"));
        if ((yyvsp[-1].node)->node_type != NAME_TYPE
        || !(type_equal((yyvsp[-1].node)->type, int_node))
        ){
            DEBUG("error");
            Error::other_semantic_error("TYPE_ERROR: Expected type int for iterator variable in for loop, got " + type_to_string((yyvsp[-1].node)->type), yylineno);
        }
    }
#line 2216 "parser.tab.c"
    break;

  case 68: /* $@8: %empty  */
#line 749 "parser.y"
    {
        if ((yyvsp[-1].node)->children.size() == 2 
            && (yyvsp[-1].node)->children[0]->lexeme == "range" 
            && (yyvsp[-1].node)->children[1]->node_type == TRAILER_TYPE
            && (yyvsp[-1].node)->children[1]->children.size() == 1 
            && (yyvsp[-1].node)->children[1]->children[0]->lexeme == "()"
            && (yyvsp[-1].node)->children[1]->children[0]->children.size() >= 1
        ){
            string loop_start, loop_end;
            struct TreeNode * params = (yyvsp[-1].node)->children[1]->children[0]; 
            if (params->children.size() == 2){
                loop_start = params->children[0]->addr;
                loop_end = params->children[1]->addr;
            }else{
                loop_start = "0";
                loop_end = params->children[0]->addr;
            }
            int ins = -1, ins2 = -1;
            for (int i = three_ac::threeAC.size()-1; i >= 0; i--){
                if (three_ac::threeAC[i]->op == "label" && three_ac::threeAC[i]->arg1 == three_ac::get_label("for_init")){
                    ins = i;
                    break;
                }
                if (three_ac::threeAC[i]->result == loop_start){
                    ins2 = i;
                    break;
                }
            }
            if (ins2  == -1){
                ins2 = ins;
            }
            three_ac * tac = new three_ac("assign", "=", loop_start, "", (yyvsp[-4].node)->lexeme, "");
            three_ac::threeAC.insert(three_ac::threeAC.begin()+ins2+1, tac);
            ins2++;
            three_ac * tac2 = new three_ac("label", "label", three_ac::get_label("for_start"), "", "", "");
            three_ac::threeAC.insert(three_ac::threeAC.begin()+ins2+1, tac2);

            string t = three_ac::new_temp();
            three_ac::gen("quad", "<", (yyvsp[-4].node)->lexeme, loop_end, t);
            three_ac::gen("if_goto", "if_false", t, three_ac::get_label("for_end"));
        }else{
            DEBUG("error");
            Error::other_semantic_error("SYNTAX_ERROR: Expected range object in for loop", yylineno);
        }
    }
#line 2266 "parser.tab.c"
    break;

  case 69: /* for_stmt: "for" atom "in" $@7 test ":" $@8 suite  */
#line 794 "parser.y"
    {
        (yyval.node) = (yyvsp[-7].node);
        appendChild((yyval.node), (yyvsp[-6].node));
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        string t = three_ac::new_temp();
        three_ac::gen("quad", "+", (yyvsp[-6].node)->lexeme, "1", t);
        three_ac::gen("assign", "=", t, "", (yyvsp[-6].node)->lexeme);
        three_ac::gen("goto", "goto", three_ac::get_label("for_start"));
        string l = three_ac::get_label("for_end");
        three_ac::gen("label", "label", l);
        three_ac::pop_label();
    }
#line 2285 "parser.tab.c"
    break;

  case 70: /* $@9: %empty  */
#line 811 "parser.y"
    {
        three_ac::push_new_label("while");
        three_ac::gen("label", "label", three_ac::get_label("while_start"));
    }
#line 2294 "parser.tab.c"
    break;

  case 71: /* $@10: %empty  */
#line 815 "parser.y"
    {
        string l = three_ac::get_label("while_end");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, l);
    }
#line 2303 "parser.tab.c"
    break;

  case 72: /* while_stmt: "while" $@9 test ":" $@10 suite  */
#line 819 "parser.y"
    {
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        if (!type_equal((yyvsp[-3].node)->type, bool_node) && !type_equal((yyvsp[-3].node)->type, int_node)){
            Error::type_mismatch(yylineno, (yyvsp[-3].node)->type, bool_node, "while loop condition");
        }
        three_ac::gen("goto", "goto", three_ac::get_label("while_start"));
        string l2 = three_ac::get_label("while_end");
        three_ac::gen("label", "label", l2);
    }
#line 2320 "parser.tab.c"
    break;

  case 73: /* $@11: %empty  */
#line 833 "parser.y"
                                             {
        curr_symtable_func  = new symtable_func((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node),yylineno); 
        if(curr_symtable_class != NULL){
            curr_symtable_class->add_func(curr_symtable_func);
        }else{
            curr_symtable_global->add_func(curr_symtable_func);
        }

        three_ac::gen("beginfunc", "beginfunc", curr_symtable_func->name);
        for (auto x: curr_symtable_func->paramlist){
            //DEBUG(x.second->name)
            x.second->addr = three_ac::new_temp();
            three_ac::gen("assign", "=", "#popparam", "", x.second->addr);
        }
    }
#line 2340 "parser.tab.c"
    break;

  case 74: /* funcdef: "def" NAME parameters funcdef_dash $@11 ":" suite  */
#line 847 "parser.y"
                {
        (yyval.node) = makeNode("def",FUNCTION_TYPE);
        appendChild((yyval.node),(yyvsp[-5].node));
        appendChild((yyval.node),(yyvsp[-4].node));
        if ((yyvsp[-3].node) != NULL){
            appendChild((yyval.node),(yyvsp[-3].node));
        }

        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        three_ac::gen("endfunc");
        curr_symtable_func = NULL;
    }
#line 2358 "parser.tab.c"
    break;

  case 75: /* funcdef_dash: "->" test  */
#line 863 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2366 "parser.tab.c"
    break;

  case 76: /* funcdef_dash: %empty  */
#line 867 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
    }
#line 2374 "parser.tab.c"
    break;

  case 77: /* parameters: "(" parameters_dash ")"  */
#line 873 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2382 "parser.tab.c"
    break;

  case 78: /* parameters_dash: typedargslist  */
#line 879 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2395 "parser.tab.c"
    break;

  case 79: /* parameters_dash: %empty  */
#line 888 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2403 "parser.tab.c"
    break;

  case 80: /* typedargslist: typedargslist "," tfpdef  */
#line 894 "parser.y"
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
#line 2418 "parser.tab.c"
    break;

  case 81: /* typedargslist: tfpdef  */
#line 905 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2426 "parser.tab.c"
    break;

  case 82: /* tfpdef: NAME ":" test  */
#line 911 "parser.y"
    {
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2436 "parser.tab.c"
    break;

  case 83: /* tfpdef: NAME  */
#line 918 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }else{
                DEBUG("error");
                Error::other_semantic_error("TYPE_ERROR: Expected variable type for "+(yyvsp[0].node)->lexeme, yylineno);
            }
        }
    }
#line 2451 "parser.tab.c"
    break;

  case 84: /* tfpdef: NAME ":" test "=" test  */
#line 930 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2462 "parser.tab.c"
    break;

  case 85: /* suite: simple_stmt  */
#line 939 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2471 "parser.tab.c"
    break;

  case 86: /* suite: NEWLINE INDENT stmt_dash DEDENT  */
#line 944 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2482 "parser.tab.c"
    break;

  case 87: /* stmt_dash: stmt_dash stmt  */
#line 953 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2491 "parser.tab.c"
    break;

  case 88: /* stmt_dash: stmt  */
#line 958 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2500 "parser.tab.c"
    break;

  case 89: /* test: or_test  */
#line 965 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2508 "parser.tab.c"
    break;

  case 90: /* or_test: and_test  */
#line 971 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2516 "parser.tab.c"
    break;

  case 91: /* or_test: or_test "or" and_test  */
#line 975 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "or", drt1, drt2, (yyval.node)->addr);
    }
#line 2537 "parser.tab.c"
    break;

  case 92: /* and_test: not_test  */
#line 994 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2545 "parser.tab.c"
    break;

  case 93: /* and_test: and_test "and" not_test  */
#line 998 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "and", drt1, drt2, (yyval.node)->addr);
    }
#line 2565 "parser.tab.c"
    break;

  case 94: /* not_test: "not" not_test  */
#line 1016 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,bool_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"not");
        }        

        (yyval.node)->type = bool_node;
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "not", drt, "", (yyval.node)->addr);
    }
#line 2584 "parser.tab.c"
    break;

  case 95: /* not_test: comparison  */
#line 1031 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2592 "parser.tab.c"
    break;

  case 96: /* comparison: expr comp_op expr  */
#line 1037 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if(!(type_equal((yyvsp[-2].node)->type,(yyvsp[0].node)->type) && (type_equal((yyvsp[-2].node)->type,bool_node) || type_equal((yyvsp[-2].node)->type,str_node)))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
            }
        }
        (yyval.node)->type = bool_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", (yyvsp[-1].node)->lexeme, drt1, drt2, (yyval.node)->addr);
    }
#line 2614 "parser.tab.c"
    break;

  case 97: /* comparison: expr  */
#line 1055 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2622 "parser.tab.c"
    break;

  case 98: /* comp_op: "<"  */
#line 1062 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2630 "parser.tab.c"
    break;

  case 99: /* comp_op: ">"  */
#line 1066 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2638 "parser.tab.c"
    break;

  case 100: /* comp_op: "=="  */
#line 1070 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2646 "parser.tab.c"
    break;

  case 101: /* comp_op: ">="  */
#line 1074 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2654 "parser.tab.c"
    break;

  case 102: /* comp_op: "<="  */
#line 1078 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2662 "parser.tab.c"
    break;

  case 103: /* comp_op: "<>"  */
#line 1082 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2670 "parser.tab.c"
    break;

  case 104: /* comp_op: "!="  */
#line 1086 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2678 "parser.tab.c"
    break;

  case 105: /* expr: xor_expr  */
#line 1092 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2686 "parser.tab.c"
    break;

  case 106: /* expr: expr "|" xor_expr  */
#line 1096 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "|", drt1, drt2, (yyval.node)->addr);
    }
#line 2706 "parser.tab.c"
    break;

  case 107: /* xor_expr: and_expr  */
#line 1114 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2714 "parser.tab.c"
    break;

  case 108: /* xor_expr: xor_expr "^" and_expr  */
#line 1118 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){ 
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "^", drt1, drt2, (yyval.node)->addr);
    }
#line 2734 "parser.tab.c"
    break;

  case 109: /* and_expr: shift_expr  */
#line 1136 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2742 "parser.tab.c"
    break;

  case 110: /* and_expr: and_expr "&" shift_expr  */
#line 1140 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "&", drt1, drt2, (yyval.node)->addr);
    }
#line 2762 "parser.tab.c"
    break;

  case 111: /* shift_expr: arith_expr  */
#line 1158 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2770 "parser.tab.c"
    break;

  case 112: /* shift_expr: shift_expr "<<" arith_expr  */
#line 1162 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "<<", drt1, drt2, (yyval.node)->addr);
    }
#line 2790 "parser.tab.c"
    break;

  case 113: /* shift_expr: shift_expr ">>" arith_expr  */
#line 1178 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", ">>", drt1, drt2, (yyval.node)->addr);
    }
#line 2810 "parser.tab.c"
    break;

  case 114: /* arith_expr: term  */
#line 1196 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2818 "parser.tab.c"
    break;

  case 115: /* arith_expr: arith_expr "+" term  */
#line 1200 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "+", drt1, drt2, (yyval.node)->addr);
    }
#line 2838 "parser.tab.c"
    break;

  case 116: /* arith_expr: arith_expr "-" term  */
#line 1216 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
             if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "-", drt1, drt2, (yyval.node)->addr);    
    }
#line 2858 "parser.tab.c"
    break;

  case 117: /* term: factor  */
#line 1234 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2866 "parser.tab.c"
    break;

  case 118: /* term: term "*" factor  */
#line 1238 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"*");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "*", drt1, drt2, (yyval.node)->addr);
    }
#line 2886 "parser.tab.c"
    break;

  case 119: /* term: term "/" factor  */
#line 1254 "parser.y"
    {   
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"/");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "/", drt1, drt2, (yyval.node)->addr);    
    }
#line 2906 "parser.tab.c"
    break;

  case 120: /* term: term "%" factor  */
#line 1270 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"%");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "%", drt1, drt2, (yyval.node)->addr);
    }
#line 2926 "parser.tab.c"
    break;

  case 121: /* term: term "//" factor  */
#line 1286 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"//");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "//", drt1, drt2, (yyval.node)->addr);
    }
#line 2946 "parser.tab.c"
    break;

  case 122: /* factor: "+" factor  */
#line 1304 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"+");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "+", drt, "", (yyval.node)->addr);        
    }
#line 2964 "parser.tab.c"
    break;

  case 123: /* factor: "-" factor  */
#line 1318 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"-");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "-", drt, "", (yyval.node)->addr);        
    }
#line 2982 "parser.tab.c"
    break;

  case 124: /* factor: "~" factor  */
#line 1332 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[0].node)->type.t!="-1")
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"~");
        }        

        (yyval.node)->type = int_node;
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "~", drt, "", (yyval.node)->addr);        
    }
#line 3001 "parser.tab.c"
    break;

  case 125: /* factor: power  */
#line 1347 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        
    }
#line 3010 "parser.tab.c"
    break;

  case 126: /* power: atom_expr  */
#line 1354 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3018 "parser.tab.c"
    break;

  case 127: /* power: atom_expr "**" factor  */
#line 1358 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"**");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        string drt1 = three_ac::dereference((yyvsp[-2].node));
        string drt2 = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "**", drt1, drt2, (yyval.node)->addr);
    }
#line 3037 "parser.tab.c"
    break;

  case 128: /* atom_expr: atom trailerlist  */
#line 1375 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
            // checker_traverse($1);
        }else{
            (yyval.node) = makeNode("atom_expr", EXPR_TYPE);
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
            struct type temp = (yyvsp[-1].node)->type;
            string temp_addr = (yyvsp[-1].node)->addr;
            string temp_name = (yyvsp[-1].node)->lexeme;
            
            // if($1->lexeme == "CLRParser"){
            //     DEBUG("In CLRParser: " << $1->lexeme)

            // }

            if((global_symtable->search_class(temp_name)!=NULL&&(yyvsp[0].node)->children.size()>0&&(yyvsp[0].node)->children[0]->lexeme == "()")||!is_declared_type((yyvsp[-1].node)->lexeme)){
            //DEBUG(temp_addr<<temp_name)
                for (int i = 0; i < (yyvsp[0].node)->children.size(); i++){
                    if ((yyvsp[0].node)->children[i]->lexeme == "()" && i == 0){
                        // function call
                        if ((yyvsp[-1].node)->node_type != NAME_TYPE){
                            DEBUG("error");
                            Error::other_semantic_error("TYPE_ERROR: Invalid operation ()", yylineno);
                        }else{
                            string func_id = (yyvsp[-1].node)->lexeme;
                            if(global_symtable->search_class(func_id)){
                                //DEBUG("Entered Func_id search")
                                func_id = func_id + "." + "__init__" + "@" + func_id;
                            }

                           
                            for (auto x: (yyvsp[0].node)->children[i]->children){
                                //DEBUG("params: "<< x->lexeme);
                               
                                
                                if(x->lexeme == "atom_expr"){
                                    //TreeNode* p = x->children[1];
                                    //TreeNode* q = p->children[0];
                                    //TreeNode* r = q->children[0];
                                    //for(auto r : q->children)
                                    //DEBUG(r->lexeme);

                                    
                                    //func_id += "@" + type_to_string(r->type);
                                }
                                else{
                                //DEBUG(x->type.t);
                                func_id += "@" + type_to_string(x->type);
                                }
                            }
                            //DEBUG(func_id);
                            struct type ret = string_to_type(func_id);
                            //DEBUG(ret.t);
                            if (ret.t == "-1"){
                                int error = 1;
                                if ((yyvsp[-1].node)->lexeme == "len"){
                                    if (temp.elems != -1){
                                        ret = int_node;
                                        error = 0;
                                    }
                                }
                                // if ($1->lexeme == "print"){
                                //     error=0;
                                // }
                                if (error){
                                    DEBUG("error");
                                    Error::other_semantic_error("TYPE_ERROR: No declaration of function " + (yyvsp[-1].node)->lexeme+ " with these parameter types", yylineno);
                                }
                            }else{
                                temp = ret;
                            }
                            if ((yyvsp[-1].node)->lexeme != "range"){
                                int stack_shift = 0;
                                
                                
                                
                                symtable_func* funct = NULL;
                                
                                symtable_class* constructor_class = global_symtable->search_class((yyvsp[-1].node)->lexeme);
                                if(constructor_class!=NULL){
                                    funct = constructor_class->search_func(func_id);
                                    if(funct == NULL){
                                        DEBUG("error");
                                        Error::other_semantic_error("ERROR: Class does not have a constructor of type "+ func_id + " at line number", yylineno);
                                    }
                                }
                                if(funct==NULL){
                                    funct = global_symtable->search_func(func_id);
                                }
                                
                                
                                for (int j=(yyvsp[0].node)->children[i]->children.size()-1; j>=0;j--){
                                    struct TreeNode * x = (yyvsp[0].node)->children[i]->children[j];
                                    string drt = three_ac::dereference(x);
                                    three_ac::gen("param",drt);
                                    if (x->type.elems != -1){
                                        stack_shift += 8;
                                    }else{
                                        stack_shift += x->type.size;
                                    }
                                }
                                
                                three_ac::gen("shiftpointer",to_string(stack_shift));
                                three_ac::gen("call",funct->name,to_string((yyvsp[0].node)->children[i]->children.size()));
                                stack_shift -= ret.size;
                                stack_shift = -stack_shift;
                                three_ac::gen("shiftpointer",to_string(stack_shift));
                                string temp_reg = three_ac::new_temp();
                                if(ret.t!="void") three_ac::gen("assign","=","#returnval","",temp_reg);
                                (yyval.node)->addr = temp_reg;
                                if (ret.elems != -1){
                                    (yyval.node)->to_dereference = 1;
                                }
                            }
                        }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "[]"){
                        // list indexing
                        if (
                            (yyvsp[0].node)->children[i]->children.size() == 1 && 
                            (yyvsp[0].node)->children[i]->children[0]->type.t != "-1"
                        )
                        {
                            struct TreeNode * index_node = (yyvsp[0].node)->children[i]->children[0];
                            if (temp.elems != -1){
                                if (type_equal((yyvsp[0].node)->children[i]->children[0]->type, int_node)){
                                    temp.elems = -1;
                                    symtable_entry* list_name = symtable_look_up(temp_name);
                                    string address;
                                    if (index_node->node_type == NAME_TYPE){
                                        symtable_entry * index = symtable_look_up(index_node->lexeme);
                                        if (index == NULL){
                                            Error::use_before_declaration(index_node->lexeme, yylineno);
                                        }else{
                                            address = index_node->addr;
                                        }
                                    }else{
                                        address = three_ac::dereference(index_node);
                                    }
                                    if(list_name == NULL){
                                        if (i == 0){
                                            Error::use_before_declaration(temp_name,yylineno);
                                        }else{
                                            Error::member_not_found(temp.t, temp_name, yylineno);
                                        }
                                    }
                                    
                                    string temp1 = three_ac::new_temp();
                                    three_ac::gen("quad","*",address,to_string(temp.size),temp1);
                                    string temp2 = three_ac::new_temp();
                                    three_ac::gen("quad","+",temp1,list_name->addr,temp2);
                                    (yyval.node)->to_dereference = 1;
                                    (yyval.node)->addr = temp2;   
                                }else{
                                    DEBUG("error");
                                    Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string((yyvsp[0].node)->children[i]->children[0]->type), yylineno);
                                }
                            }else{
                                if (temp.t == "-1" && i == 0){
                                    Error::use_before_declaration((yyvsp[-1].node)->lexeme, yylineno);
                                }else{
                                    DEBUG("error");
                                    Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                                }
                            }
                        }
                        else{
                            
                        }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "."){
                        DEBUG("Inside . : "<<(yyvsp[0].node)->children[i]->lexeme);
                        if (i + 1 < (yyvsp[0].node)->children.size() && (yyvsp[0].node)->children[i+1]->lexeme == "()"){
                            // method call  
                            
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
                            class_id += "." + (yyvsp[0].node)->children[i]->children[0]->lexeme;
                            class_id+="@"+class_name;
                            for (auto x: (yyvsp[0].node)->children[i+1]->children){
                                class_id += "@" + type_to_string(x->type);
                            }
                            struct type ret = string_to_type(class_id);
                            
                            if (ret.t == "-1"){
                                DEBUG("error");
                                Error::other_semantic_error("TYPE_ERROR: No such method with given parameter types in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }
                            int stack_shift = 0;
                            symtable_class* object_class = global_symtable->search_class(class_name);
                            symtable_func* funct = object_class->search_func(class_id); 
                            symtable_entry* object_entry = symtable_look_up((yyvsp[-1].node)->lexeme);   

                            DEBUG(funct->returntype.t << ' ' << funct->name);         
                            
                            if(object_entry == NULL){
                                Error::sem_no_declaration_var((yyvsp[-1].node)->lexeme,yylineno);
                                //DEBUG("here");
                            }
                            
                            // three_ac("quad","+",object_entry->addr,funct->offset,)
                            stack_shift += object_class->size; 
                            for (int j=(yyvsp[0].node)->children[i+1]->children.size()-1; j>=0;j-- ){
                                auto x = (yyvsp[0].node)->children[i+1]->children[i];
                                string drt = three_ac::dereference(x);
                                three_ac::gen("param",drt);
                                stack_shift += x->type.size;
                            }
                            three_ac::gen("param",object_entry->addr);
                            three_ac::gen("shiftpointer",to_string(stack_shift));
                            three_ac::gen("call",class_id,to_string((yyvsp[0].node)->children[i+1]->children.size()+1));
                            stack_shift -= ret.size;
                            stack_shift *= -1;
                            three_ac::gen("shiftpointer",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            if(funct->returntype.t != "void") three_ac::gen("assign","=","#returnval","",temp_reg);
                            (yyval.node)->addr = temp_reg;
                        }
                        else{
                            // attribute access
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
                            class_id += "." + (yyvsp[0].node)->children[i]->children[0]->lexeme;
                            struct type ret = string_to_type(class_id);
                            if (ret.t != "-1"){

                                int stack_shift = 0;
                                symtable_class* object_class = global_symtable->search_class(class_name);
                                symtable_entry* class_attr = object_class->search_entry(class_id); 
                                
                                // class_attr = symtable_look_up($1->lexeme);
                                if(class_attr == NULL){
                                    Error::sem_no_declaration_var((yyvsp[-1].node)->lexeme,yylineno);
                                    //DEBUG("here");
                                }
                                string t_off = three_ac::new_temp();
                                // three_ac::gen("class_get", "symtable", object_class->name, $2->children[i]->children[0]->lexeme , t_off);
                                three_ac::gen("assign", "=",to_string(class_attr->offset),"",t_off);

                                string temp1 = three_ac::new_temp();
                                three_ac::gen("quad","+",temp_addr,t_off,temp1);
                                if(i + 1 < (yyvsp[0].node)->children.size() && (yyvsp[0].node)->children[i+1]->lexeme == "[]"){
                                    // if($2->children[i+1]->children[0]->type.t!="-1"){ 
                                    //     if (temp.elems != -1){
                                    //         if (type_equal($2->children[i+1]->children[0]->type, int_node)){
                                    //             temp.elems = -1;
                                                
                                    //             symtable_entry* index  = symtable_look_up($2->children[i+1]->children[0]->lexeme);
                                    //             if(index ==NULL ){
                                    //                 Error::sem_no_declaration_var($2->children[i+1]->children[0]->lexeme,yylineno);
                                    //             }
                                    //             string temp3 = three_ac::new_temp();
                                    //             three_ac::gen("quad","*",index->addr,to_string(index->type.size),temp3);
                                    //             string temp4 = three_ac::new_temp();
                                    //             three_ac::gen("quad","+",temp3,temp2,temp4);
                                    //             $$->to_dereference = 1;
                                    //             $$->addr = temp4;
                                    //         }else{
                                    //             Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string($2->children[i]->children[0]->type), yylineno);
                                    //         }
                                    //     }else{
                                    //         Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                                    //     }
                                    // }                                
                                }else{
                                    (yyval.node)->addr = temp1;
                                    (yyval.node)->to_dereference = 1;
                                }
                            }
                        }
                    }
                    else{
                       if(i==0) Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + (yyvsp[0].node)->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            if((yyvsp[-1].node)->lexeme == "self" && curr_symtable_class!=NULL){
                string ss="";
                ss += curr_symtable_class->name;
                ss.push_back('.');
                ss+=((yyvsp[0].node)->children[0]->children[0]->lexeme);
                //DEBUG(ss);
                type temp_type;
                if(curr_symtable_class->search_entry(ss)!=NULL){
                    temp_type = curr_symtable_class->search_entry(ss)->type;
                    temp = temp_type;
                }
            }
            (yyval.node)->type = temp;
        } 
    }
#line 3335 "parser.tab.c"
    break;

  case 129: /* trailerlist: trailerlist trailer  */
#line 1671 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
            //DEBUG($$->type.t << );
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 3350 "parser.tab.c"
    break;

  case 130: /* trailerlist: %empty  */
#line 1682 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3358 "parser.tab.c"
    break;

  case 131: /* trailer: "(" arglist ")"  */
#line 1687 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 3371 "parser.tab.c"
    break;

  case 132: /* trailer: "[" test "]"  */
#line 1696 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 3380 "parser.tab.c"
    break;

  case 133: /* trailer: "." NAME  */
#line 1701 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 3389 "parser.tab.c"
    break;

  case 134: /* atom: NAME  */
#line 1708 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
        
        symtable_entry * entry = symtable_look_up((yyvsp[0].node)->lexeme);
        if (entry != NULL){
            //DEBUG("Self name : " << entry->name)
            //DEBUG("Self type : " << entry->type.t)
            
            (yyval.node)->type = string_to_type((yyvsp[0].node)->lexeme);
            (yyval.node)->addr = entry->addr;
        }
    }
#line 3406 "parser.tab.c"
    break;

  case 135: /* atom: NUMBER  */
#line 1721 "parser.y"
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
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3427 "parser.tab.c"
    break;

  case 136: /* atom: STRING  */
#line 1738 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
        //DEBUG($$->lexeme);
        (yyval.node)->type.t = "str";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3438 "parser.tab.c"
    break;

  case 137: /* atom: "None"  */
#line 1745 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
        (yyval.node)->type.t = "void";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3448 "parser.tab.c"
    break;

  case 138: /* atom: "True"  */
#line 1751 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3458 "parser.tab.c"
    break;

  case 139: /* atom: "False"  */
#line 1757 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3468 "parser.tab.c"
    break;

  case 140: /* atom: "(" test ")"  */
#line 1763 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3476 "parser.tab.c"
    break;

  case 141: /* atom: "[" arglist "]"  */
#line 1767 "parser.y"
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
#line 3491 "parser.tab.c"
    break;

  case 142: /* arglist: arglist_dash  */
#line 1780 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3499 "parser.tab.c"
    break;

  case 143: /* arglist: %empty  */
#line 1784 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3507 "parser.tab.c"
    break;

  case 144: /* arglist_dash: arglist_dash "," test  */
#line 1790 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 3516 "parser.tab.c"
    break;

  case 145: /* arglist_dash: test  */
#line 1795 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3526 "parser.tab.c"
    break;


#line 3530 "parser.tab.c"

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

#line 1800 "parser.y"

