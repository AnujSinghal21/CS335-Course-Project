/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
unordered_set<string> declared_types;
ofstream threeac_file;

struct type int_node;
struct type float_node;
struct type bool_node;
struct type str_node;
struct type void_node;

int is_declared_type(string t){
    return declared_types.find(t) != declared_types.end();
}

void checker_traverse(struct TreeNode* node){
    if(node == NULL){
        return;
    }

    for(auto child : node->children){
        if(child->node_type == NAME_TYPE){
            if(curr_symtable_func!=NULL){
                curr_symtable_func->check_declaration_var(child->lexeme,yylineno);
            }
            else{
                curr_symtable_global->check_declaration_var(child->lexeme,yylineno);
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


#line 160 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN_AND = 258,
    ASSIGN_DIVIDE = 259,
    ASSIGN_DOUBLESLASH = 260,
    ASSIGN_EQUAL = 261,
    ASSIGN_LEFTSHIFT = 262,
    ASSIGN_MINUS = 263,
    ASSIGN_MOD = 264,
    ASSIGN_MULTIPLY = 265,
    ASSIGN_OR = 266,
    ASSIGN_PLUS = 267,
    ASSIGN_POWER = 268,
    ASSIGN_RIGHTSHIFT = 269,
    ASSIGN_XOR = 270,
    CLOSE_SQUARE_BRACKET = 271,
    DEDENT = 272,
    ENDMARKER = 273,
    INDENT = 274,
    KEY_BREAK = 275,
    KEY_CLASS = 276,
    KEY_CONTINUE = 277,
    KEY_ELIF = 278,
    KEY_ELSE = 279,
    KEY_FALSE = 280,
    KEY_FOR = 281,
    KEY_FUNCTION_DEF = 282,
    KEY_GLOBAL = 283,
    KEY_IF = 284,
    KEY_NONE = 285,
    KEY_RETURN = 286,
    KEY_TRUE = 287,
    KEY_WHILE = 288,
    NAME = 289,
    NEWLINE = 290,
    NUMBER = 291,
    OPEN_SQUARE_BRACKET = 292,
    OPER_AND = 293,
    OPER_AND_BITWISE = 294,
    OPER_CLOSE_BRACKET = 295,
    OPER_COLON = 296,
    OPER_COMMA = 297,
    OPER_DIVIDE = 298,
    OPER_DOT = 299,
    OPER_EQUAL = 300,
    OPER_GREATER_THAN = 301,
    OPER_GREATER_THAN_EQUAL = 302,
    OPER_IN = 303,
    OPER_INT_DIV = 304,
    OPER_LEFT_SHIFT = 305,
    OPER_LESS_GREATER = 306,
    OPER_LESS_THAN = 307,
    OPER_LESS_THAN_EQUAL = 308,
    OPER_MINUS = 309,
    OPER_MOD = 310,
    OPER_MULTIPLY = 311,
    OPER_NEGATIVE = 312,
    OPER_NOT = 313,
    OPER_NOT_EQUAL = 314,
    OPER_OPEN_BRACKET = 315,
    OPER_OR = 316,
    OPER_OR_BITWISE = 317,
    OPER_PLUS = 318,
    OPER_POWER = 319,
    OPER_REFERENCE = 320,
    OPER_RIGHT_SHIFT = 321,
    OPER_SEMICOLON = 322,
    OPER_XOR_BITWISE = 323,
    STRING = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 91 "parser.y"

    struct TreeNode * node;

#line 286 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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

#define YYUNDEFTOK  2
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,   225,   225,   235,   239,   256,   261,   265,   271,   278,
     289,   296,   301,   305,   311,   391,   395,   400,   405,   410,
     422,   432,   437,   445,   449,   453,   457,   461,   465,   469,
     473,   477,   481,   485,   489,   495,   499,   503,   509,   515,
     521,   531,   544,   555,   561,   565,   569,   573,   577,   583,
     593,   601,   605,   610,   614,   619,   626,   634,   641,   641,
     660,   665,   670,   676,   695,   707,   707,   731,   737,   742,
     750,   760,   765,   776,   782,   790,   801,   810,   815,   824,
     829,   836,   842,   846,   865,   869,   887,   902,   908,   924,
     931,   935,   939,   943,   947,   951,   955,   961,   965,   983,
     987,  1005,  1009,  1027,  1031,  1047,  1065,  1069,  1085,  1103,
    1107,  1123,  1139,  1155,  1173,  1187,  1201,  1216,  1223,  1227,
    1244,  1410,  1421,  1425,  1434,  1439,  1446,  1452,  1468,  1473,
    1478,  1483,  1488,  1492,  1505,  1510,  1515,  1525
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"&=\"", "\"/=\"", "\"//=\"", "\"=\"",
  "\"<<=\"", "\"-=\"", "\"%=\"", "\"*=\"", "\"|=\"", "\"+=\"", "\"**=\"",
  "\">>=\"", "\"^=\"", "\"]\"", "DEDENT", "ENDMARKER", "INDENT",
  "\"break\"", "\"class\"", "\"continue\"", "\"elif\"", "\"else\"",
  "\"False\"", "\"for\"", "\"def\"", "\"global\"", "\"if\"", "\"None\"",
  "\"return\"", "\"True\"", "\"while\"", "NAME", "NEWLINE", "NUMBER",
  "\"[\"", "\"and\"", "\"&\"", "\")\"", "\":\"", "\",\"", "\"/\"", "\".\"",
  "\"==\"", "\">\"", "\">=\"", "\"in\"", "\"//\"", "\"<<\"", "\"<>\"",
  "\"<\"", "\"<=\"", "\"-\"", "\"%\"", "\"*\"", "\"~\"", "\"not\"",
  "\"!=\"", "\"(\"", "\"or\"", "\"|\"", "\"+\"", "\"**\"", "\"->\"",
  "\">>\"", "\";\"", "\"^\"", "STRING", "$accept", "input_file",
  "input_file_dash", "stmt", "simple_stmt", "small_stmt_dash",
  "small_stmt", "expr_stmt", "expr_stmt_dash", "assign_dash", "annasign",
  "augassign", "flow_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "global_stmt", "NAME_dash", "compound_stmt", "if_stmt", "if_stmt_dash",
  "else_stmt_dash", "elif_stmt", "else_stmt", "classdef", "$@1",
  "inheritlist", "for_stmt", "while_stmt", "funcdef", "$@2",
  "funcdef_dash", "parameters", "parameters_dash", "typedargslist",
  "tfpdef", "suite", "stmt_dash", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "arith_expr", "term", "factor", "power", "atom_expr",
  "trailerlist", "trailer", "atom", "arglist", "arglist_dash", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

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
      16,    83,    85,    98,    88,   100,   102,   104,   105,   108,
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
    -175,  -175,  -175,  -174,    -2,  -175,    65,  -175,  -175,     1,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   -52,    66,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   -46,  -125,  -175,    -8,  -175,
      43,   -21,  -175,  -175,    34,    36,    41,    42,   -61,   -59,
     -12,  -175,  -175,  -175,  -175,  -175,   -11,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,   172,    29,    30,    31,    96,    97,
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

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 225 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1669 "parser.tab.c"
    break;

  case 3:
#line 236 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1677 "parser.tab.c"
    break;

  case 4:
#line 240 "parser.y"
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
#line 1697 "parser.tab.c"
    break;

  case 5:
#line 256 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1705 "parser.tab.c"
    break;

  case 6:
#line 262 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1713 "parser.tab.c"
    break;

  case 7:
#line 266 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1721 "parser.tab.c"
    break;

  case 8:
#line 272 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1730 "parser.tab.c"
    break;

  case 9:
#line 279 "parser.y"
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
#line 1745 "parser.tab.c"
    break;

  case 10:
#line 290 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1753 "parser.tab.c"
    break;

  case 11:
#line 297 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1762 "parser.tab.c"
    break;

  case 12:
#line 302 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1770 "parser.tab.c"
    break;

  case 13:
#line 306 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1778 "parser.tab.c"
    break;

  case 14:
#line 312 "parser.y"
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

        if((yyvsp[0].node) != NULL && ((yyvsp[0].node)->lexeme == ":" || (yyvsp[0].node)->lexeme == ":=")){
            //DEBUG("here");
            if(curr_symtable_func!=NULL){
                //DEBUG("Entered Add Function Entry" << curr_symtable_func);
                entry = curr_symtable_func->add_entry((yyvsp[0].node),yylineno);
                //DEBUG("Exited Add Function Entry");
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
                three_ac::dereference((yyvsp[0].node)->children[2]);
                three_ac::gen("unary", "=", (yyvsp[0].node)->children[2]->addr, "", (yyvsp[0].node)->children[0]->addr);
            } 
        }
        else if ((yyvsp[0].node) != NULL){
            checker_traverse((yyvsp[0].node));
            if (type_equal((yyvsp[-1].node)->type, (yyvsp[0].node)->children[0]->type)){
                (yyval.node)->type = (yyvsp[-1].node)->type;
            }else{
                Error::type_mismatch(yylineno, (yyvsp[-1].node)->type, (yyvsp[0].node)->children[0]->type, "assignment");
            }
            three_ac::dereference((yyvsp[0].node)->children[2]);
            string op = (yyvsp[0].node)->children[1]->lexeme;
            if (op == "="){
                if ((yyvsp[0].node)->children[0]->to_dereference){
                    three_ac::gen("address_assign", "=", (yyvsp[0].node)->children[2]->addr, "", (yyvsp[0].node)->children[0]->addr);
                }else{
                    three_ac::gen("unary", "=", (yyvsp[0].node)->children[2]->addr, "", (yyvsp[0].node)->children[0]->addr);
                }
            }else{
                if ((yyvsp[0].node)->children[0]->to_dereference){
                    string temp = three_ac::new_temp();
                    three_ac::gen("DEREF", "*", (yyvsp[0].node)->children[0]->addr, "", temp);
                    string op = (yyvsp[0].node)->children[1]->lexeme.substr(0, (yyvsp[0].node)->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, temp, (yyvsp[0].node)->children[2]->addr, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", (yyvsp[0].node)->children[0]->addr);
                }else{
                    string op = (yyvsp[0].node)->children[1]->lexeme.substr(0, (yyvsp[0].node)->children[1]->lexeme.size()-1);
                    string temp2 = three_ac::new_temp();
                    three_ac::gen("quad", op, (yyvsp[0].node)->children[0]->addr, (yyvsp[0].node)->children[2]->addr, temp2);
                    three_ac::gen("address_assign", "=", temp2, "", (yyvsp[0].node)->children[0]->addr);
                }
            }
        }
        checker_traverse((yyvsp[-1].node));
    }
#line 1860 "parser.tab.c"
    break;

  case 15:
#line 392 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1868 "parser.tab.c"
    break;

  case 16:
#line 396 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1877 "parser.tab.c"
    break;

  case 17:
#line 401 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1885 "parser.tab.c"
    break;

  case 18:
#line 405 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1893 "parser.tab.c"
    break;

  case 19:
#line 411 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        insert_to_front((yyvsp[0].node), (yyvsp[-1].node));
        (yyval.node)->addr = (yyvsp[0].node)->addr;
        if ((yyvsp[-1].node)->to_dereference){
            three_ac::gen("address_assign", "=", (yyvsp[0].node)->addr, "", (yyvsp[-1].node)->addr);
        }else{
            three_ac::gen("unary", "=", (yyvsp[0].node)->addr, "", (yyvsp[-1].node)->addr);
        }
    }
#line 1909 "parser.tab.c"
    break;

  case 20:
#line 423 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
     
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = (yyvsp[0].node)->addr;
    }
#line 1921 "parser.tab.c"
    break;

  case 21:
#line 433 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1930 "parser.tab.c"
    break;

  case 22:
#line 438 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1940 "parser.tab.c"
    break;

  case 23:
#line 446 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1948 "parser.tab.c"
    break;

  case 24:
#line 450 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1956 "parser.tab.c"
    break;

  case 25:
#line 454 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1964 "parser.tab.c"
    break;

  case 26:
#line 458 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1972 "parser.tab.c"
    break;

  case 27:
#line 462 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1980 "parser.tab.c"
    break;

  case 28:
#line 466 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1988 "parser.tab.c"
    break;

  case 29:
#line 470 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1996 "parser.tab.c"
    break;

  case 30:
#line 474 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2004 "parser.tab.c"
    break;

  case 31:
#line 478 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2012 "parser.tab.c"
    break;

  case 32:
#line 482 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2020 "parser.tab.c"
    break;

  case 33:
#line 486 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2028 "parser.tab.c"
    break;

  case 34:
#line 490 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2036 "parser.tab.c"
    break;

  case 35:
#line 496 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2044 "parser.tab.c"
    break;

  case 36:
#line 500 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2052 "parser.tab.c"
    break;

  case 37:
#line 504 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2060 "parser.tab.c"
    break;

  case 38:
#line 510 "parser.y"
    {
        (yyval.node) = makeNode("break",STATEMENT_TYPE);
    }
#line 2068 "parser.tab.c"
    break;

  case 39:
#line 516 "parser.y"
    {
        (yyval.node) = makeNode("continue",STATEMENT_TYPE);
    }
#line 2076 "parser.tab.c"
    break;

  case 40:
#line 522 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        checker_traverse((yyvsp[0].node));
        //DEBUG($2->type.t);
        curr_symtable_func->check_returntype((yyvsp[0].node), yylineno);
    }
#line 2088 "parser.tab.c"
    break;

  case 41:
#line 532 "parser.y"
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
#line 2103 "parser.tab.c"
    break;

  case 42:
#line 545 "parser.y"
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
#line 2118 "parser.tab.c"
    break;

  case 43:
#line 556 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2126 "parser.tab.c"
    break;

  case 44:
#line 562 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2134 "parser.tab.c"
    break;

  case 45:
#line 566 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2142 "parser.tab.c"
    break;

  case 46:
#line 570 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2150 "parser.tab.c"
    break;

  case 47:
#line 574 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2158 "parser.tab.c"
    break;

  case 48:
#line 578 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2166 "parser.tab.c"
    break;

  case 49:
#line 584 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
        (yyval.node)->type.t = "void";
    }
#line 2178 "parser.tab.c"
    break;

  case 50:
#line 594 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 2188 "parser.tab.c"
    break;

  case 51:
#line 602 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2196 "parser.tab.c"
    break;

  case 52:
#line 606 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2205 "parser.tab.c"
    break;

  case 53:
#line 611 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2213 "parser.tab.c"
    break;

  case 54:
#line 614 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 2221 "parser.tab.c"
    break;

  case 55:
#line 620 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[-1].node));
        appendChild((yyval.node), (yyvsp[0].node));        
    }
#line 2232 "parser.tab.c"
    break;

  case 56:
#line 627 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2242 "parser.tab.c"
    break;

  case 57:
#line 635 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2251 "parser.tab.c"
    break;

  case 58:
#line 641 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
        declared_types.insert((yyvsp[-1].node)->lexeme);
    }
#line 2261 "parser.tab.c"
    break;

  case 59:
#line 646 "parser.y"
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
#line 2278 "parser.tab.c"
    break;

  case 60:
#line 661 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2286 "parser.tab.c"
    break;

  case 61:
#line 666 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2294 "parser.tab.c"
    break;

  case 62:
#line 670 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2302 "parser.tab.c"
    break;

  case 63:
#line 677 "parser.y"
    {   
       /* struct TreeNode* temp1 = makeNode($2->lexeme,NAME_TYPE);
        struct TreeNode* temp2 = makeNode("int",NAME_TYPE);
        struct TreeNode* temp = makeNode("",EXPR_TYPE);
        appendChild(temp,temp1);
        appendChild(temp,temp2);
        curr_symtable_func->add_entry(temp,yylineno); */
        (yyval.node) = (yyvsp[-5].node);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        if (!type_equal((yyvsp[-4].node)->type, int_node)){
            Error::other_semantic_error("TYPE_ERROR: Expected type int for iterator variable in for loop, got " + type_to_string((yyvsp[-4].node)->type), yylineno);
        }
    }
#line 2323 "parser.tab.c"
    break;

  case 64:
#line 696 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type.t = "void";
        if (!type_equal((yyvsp[-2].node)->type, bool_node) && !type_equal((yyvsp[-2].node)->type, int_node)){
            Error::type_mismatch(yylineno, (yyvsp[-2].node)->type, bool_node, "while loop condition");
        }
    }
#line 2337 "parser.tab.c"
    break;

  case 65:
#line 707 "parser.y"
                                             {
        curr_symtable_func  = new symtable_func((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node),yylineno); 
        if(curr_symtable_class != NULL){
            curr_symtable_class->add_func(curr_symtable_func);
        }else{
            curr_symtable_global->add_func(curr_symtable_func);
        }
        three_ac::gen("beginfunc", "beginfunc", curr_symtable_func->name);
    }
#line 2351 "parser.tab.c"
    break;

  case 66:
#line 715 "parser.y"
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
        three_ac::gen("endfunc");
    }
#line 2370 "parser.tab.c"
    break;

  case 67:
#line 732 "parser.y"
    {
        //DEBUG($2->lexeme);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2379 "parser.tab.c"
    break;

  case 68:
#line 737 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
    }
#line 2387 "parser.tab.c"
    break;

  case 69:
#line 743 "parser.y"
    {
        //DEBUG($2);
        //DEBUG("parameters" << $2->children.size());
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2397 "parser.tab.c"
    break;

  case 70:
#line 751 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2410 "parser.tab.c"
    break;

  case 71:
#line 760 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2418 "parser.tab.c"
    break;

  case 72:
#line 766 "parser.y"
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
#line 2433 "parser.tab.c"
    break;

  case 73:
#line 777 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2441 "parser.tab.c"
    break;

  case 74:
#line 783 "parser.y"
    {
        //DEBUG("tfpdef" << $1->lexeme << " " << $3->lexeme);
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2452 "parser.tab.c"
    break;

  case 75:
#line 791 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }else{
                Error::other_semantic_error("TYPE_ERROR: Expected variable type for "+(yyvsp[0].node)->lexeme, yylineno);
            }
        }
    }
#line 2466 "parser.tab.c"
    break;

  case 76:
#line 802 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2477 "parser.tab.c"
    break;

  case 77:
#line 811 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2486 "parser.tab.c"
    break;

  case 78:
#line 816 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2497 "parser.tab.c"
    break;

  case 79:
#line 825 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2506 "parser.tab.c"
    break;

  case 80:
#line 830 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2515 "parser.tab.c"
    break;

  case 81:
#line 837 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2523 "parser.tab.c"
    break;

  case 82:
#line 843 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2531 "parser.tab.c"
    break;

  case 83:
#line 847 "parser.y"
    {
        (yyval.node) = makeNode("or",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "or", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2552 "parser.tab.c"
    break;

  case 84:
#line 866 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2560 "parser.tab.c"
    break;

  case 85:
#line 870 "parser.y"
    {
        (yyval.node) = makeNode("and",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,bool_node)) && (type_equal((yyvsp[0].node)->type,bool_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "and", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2580 "parser.tab.c"
    break;

  case 86:
#line 888 "parser.y"
    {
        (yyval.node) = makeNode("not",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,bool_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"not");
        }        

        (yyval.node)->type = bool_node;
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "not", (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2599 "parser.tab.c"
    break;

  case 87:
#line 903 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2607 "parser.tab.c"
    break;

  case 88:
#line 909 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE); 
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = bool_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", (yyvsp[-1].node)->lexeme, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2627 "parser.tab.c"
    break;

  case 89:
#line 925 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2635 "parser.tab.c"
    break;

  case 90:
#line 932 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2643 "parser.tab.c"
    break;

  case 91:
#line 936 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2651 "parser.tab.c"
    break;

  case 92:
#line 940 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2659 "parser.tab.c"
    break;

  case 93:
#line 944 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2667 "parser.tab.c"
    break;

  case 94:
#line 948 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2675 "parser.tab.c"
    break;

  case 95:
#line 952 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2683 "parser.tab.c"
    break;

  case 96:
#line 956 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2691 "parser.tab.c"
    break;

  case 97:
#line 962 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2699 "parser.tab.c"
    break;

  case 98:
#line 966 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "|", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2719 "parser.tab.c"
    break;

  case 99:
#line 984 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2727 "parser.tab.c"
    break;

  case 100:
#line 988 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){ 
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "^", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2747 "parser.tab.c"
    break;

  case 101:
#line 1006 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2755 "parser.tab.c"
    break;

  case 102:
#line 1010 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "&", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2775 "parser.tab.c"
    break;

  case 103:
#line 1028 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2783 "parser.tab.c"
    break;

  case 104:
#line 1032 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "<<", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2803 "parser.tab.c"
    break;

  case 105:
#line 1048 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)) && (type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", ">>", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2823 "parser.tab.c"
    break;

  case 106:
#line 1066 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2831 "parser.tab.c"
    break;

  case 107:
#line 1070 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "+", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2851 "parser.tab.c"
    break;

  case 108:
#line 1086 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
             if((yyvsp[-2].node)->type.t!="-1" && (yyvsp[0].node)->type.t!="-1" )
            Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "-", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);    
    }
#line 2871 "parser.tab.c"
    break;

  case 109:
#line 1104 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2879 "parser.tab.c"
    break;

  case 110:
#line 1108 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"*");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "*", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2899 "parser.tab.c"
    break;

  case 111:
#line 1124 "parser.y"
    {   
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"/");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "/", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);    
    }
#line 2919 "parser.tab.c"
    break;

  case 112:
#line 1140 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"%");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "%", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2939 "parser.tab.c"
    break;

  case 113:
#line 1156 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"//");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "//", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 2959 "parser.tab.c"
    break;

  case 114:
#line 1174 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        
        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"+");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "+", (yyvsp[0].node)->addr, "", (yyval.node)->addr);        
    }
#line 2977 "parser.tab.c"
    break;

  case 115:
#line 1188 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node)||type_equal((yyvsp[0].node)->type,float_node))))){
            if ((yyvsp[0].node)->type.t != "-1")
                Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"-");
        }
        (yyval.node)->type = (yyvsp[0].node)->type;
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "-", (yyvsp[0].node)->addr, "", (yyval.node)->addr);        
    }
#line 2995 "parser.tab.c"
    break;

  case 116:
#line 1202 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));

        if(!(((type_equal((yyvsp[0].node)->type,int_node))))){
            if((yyvsp[0].node)->type.t!="-1")
            Error::invalid_unary_operation(yylineno,(yyvsp[0].node)->type,"~");
        }        

        (yyval.node)->type = int_node;
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("unary", "~", (yyvsp[0].node)->addr, "", (yyval.node)->addr);        
    }
#line 3014 "parser.tab.c"
    break;

  case 117:
#line 1217 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        
    }
#line 3023 "parser.tab.c"
    break;

  case 118:
#line 1224 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3031 "parser.tab.c"
    break;

  case 119:
#line 1228 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
        if(!(((type_equal((yyvsp[-2].node)->type,int_node)||type_equal((yyvsp[-2].node)->type,float_node)) && (type_equal((yyvsp[0].node)->type,float_node)||type_equal((yyvsp[0].node)->type,int_node)) ))){
            if ((yyvsp[-2].node)->type.t != "-1" && (yyvsp[0].node)->type.t != "-1")
                Error::type_mismatch(yylineno,(yyvsp[-2].node)->type,(yyvsp[0].node)->type,"**");
        }
        (yyval.node)->type = get_max_type((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        three_ac::dereference((yyvsp[-2].node));
        three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = three_ac::new_temp();
        three_ac::gen("quad", "**", (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr, (yyval.node)->addr);
    }
#line 3050 "parser.tab.c"
    break;

  case 120:
#line 1245 "parser.y"
    {
        if ((yyvsp[0].node) == NULL){
            (yyval.node) = (yyvsp[-1].node);
            if((yyvsp[-1].node)->addr == "not assigned"){
                (yyvsp[-1].node)->addr = (yyvsp[-1].node)->lexeme;
            }
        }else{
            (yyval.node) = makeNode("atom_expr", EXPR_TYPE);
            appendChild((yyval.node), (yyvsp[-1].node));
            appendChild((yyval.node), (yyvsp[0].node));
            struct type temp = (yyvsp[-1].node)->type;
            
            if(is_declared_type((yyvsp[-1].node)->lexeme))
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
                                if(func_id!="main") Error::other_semantic_error("TYPE_ERROR: No declaration of function " + (yyvsp[-1].node)->lexeme+ " with these parameter types, called ", yylineno);
                            }else{
                                temp = ret;
                            }

                            DEBUG("Entered 3AC Function Call");
                            int stack_shift = 0;
                            symtable_func* funct = global_symtable->search_func(func_id);
                            for (auto x: (yyvsp[0].node)->children[i]->children){
                                three_ac::gen("param",x->addr);
                                stack_shift += x->type.size;
                                three_ac::dereference(x);
                            }
                            three_ac::gen("stackpointer+",to_string(stack_shift));
                            three_ac::gen("call",func_id,to_string((yyvsp[0].node)->children[i]->children.size()));
                            stack_shift -= ret.size;
                            three_ac::gen("stackpointer-",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            three_ac::gen("popparam","","","",temp_reg);
                            (yyval.node)->addr = temp_reg;
                            DEBUG("Exited 3AC Function Call");
                            
                    }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "[]"){
                        // list indexing
                        if((yyvsp[0].node)->children[i]->children[0]->type.t!="-1"){ // taking care of list parameters
                            if (temp.elems != -1){
                                if (type_equal((yyvsp[0].node)->children[i]->children[0]->type, int_node)){
                                    temp.elems = -1;
                                    
                                    string temp_reg = three_ac::new_temp();
                                    three_ac::gen("quad","+",(yyvsp[0].node)->children[i]->children[0]->addr,(yyvsp[-1].node)->addr,temp_reg);
                                    (yyval.node)->to_dereference = 1;
                                    (yyval.node)->addr = temp_reg;


                                }else{
                                    Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string((yyvsp[0].node)->children[i]->children[0]->type), yylineno);
                                }
                            }else{
                                Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                            }
                        }
                        else{
                            
                        }
                    }else if ((yyvsp[0].node)->children[i]->lexeme == "."){
                        if (i + 1 < (yyvsp[0].node)->children.size() && (yyvsp[0].node)->children[i+1]->lexeme == "()"){
                            // method call
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
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

                            int stack_shift = 0;
                            symtable_class* object_class = global_symtable->search_class(class_name);
                            symtable_func* funct = object_class->search_func(class_id); 
                            symtable_entry* object_entry;
                            
                            object_entry = symtable_look_up((yyvsp[-1].node)->lexeme);

                            if(object_entry == NULL){
                                Error::sem_no_declaration_var((yyvsp[-1].node)->lexeme,yylineno);
                            }
                            
                            // three_ac("quad","+",object_entry->addr,funct->offset,) 
                            three_ac::gen("param",object_entry->addr);
                            for (auto x: (yyvsp[0].node)->children[i+1]->children){
                                three_ac::gen("param",x->addr);
                                stack_shift += x->type.size;
                                three_ac::dereference(x);
                            }
                            three_ac::gen("stackpointer+",to_string(stack_shift));
                            three_ac::gen("call",class_id,to_string((yyvsp[0].node)->children[i+1]->children.size()+1));
                            stack_shift -= ret.size;
                            three_ac::gen("stackpointer-",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            three_ac::gen("popparam","","","",temp_reg);
                            (yyval.node)->addr = temp_reg;
                            DEBUG("Exited 3AC Function Call");
                        }
                        // else if(i+1<$2->children.size() && $2->childre[i+1]->lexeme == "[]"){
                        //     // a.b[i]


                        // }
                        
                        
                        else{
                            // attribute access
                            string class_id = type_to_string(temp);
                            string class_name = class_id;
                            class_id += "." + (yyvsp[0].node)->children[i]->children[0]->lexeme;
                            struct type ret = string_to_type(class_id);
                            if (ret.t == "-1"){
                                Error::other_semantic_error("TYPE_ERROR: No declaration of attribute " + (yyvsp[0].node)->children[i]->children[0]->lexeme + " in class " + type_to_string(temp), yylineno);
                            }else{
                                temp = ret;
                            }


                            int stack_shift = 0;
                            symtable_class* object_class = global_symtable->search_class(class_name);
                            symtable_entry* class_attr = object_class->search_entry(class_id); 

                            class_attr = symtable_look_up((yyvsp[-1].node)->lexeme);
                            
                            if(class_attr == NULL){
                                Error::sem_no_declaration_var((yyvsp[-1].node)->lexeme,yylineno);
                            }
                            
                            string temp1 = three_ac::new_temp();
                            three_ac("lookup","",type_to_string(temp),class_id,temp1);
                            string temp2 = three_ac::new_temp();
                            three_ac("quad","+",class_attr->addr,temp1,temp2);
                            string temp3 = three_ac::new_temp();
                            three_ac("DEREF","*",temp2,"",temp3);
                        }
                    }else{
                        Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + (yyvsp[0].node)->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            
            (yyval.node)->type = temp;
            
        }
    }
#line 3218 "parser.tab.c"
    break;

  case 121:
#line 1411 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 3232 "parser.tab.c"
    break;

  case 122:
#line 1421 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3240 "parser.tab.c"
    break;

  case 123:
#line 1426 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 3253 "parser.tab.c"
    break;

  case 124:
#line 1435 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 3262 "parser.tab.c"
    break;

  case 125:
#line 1440 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 3271 "parser.tab.c"
    break;

  case 126:
#line 1447 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
        (yyval.node)->type = string_to_type((yyvsp[0].node)->lexeme);
        //DEBUG("atom: " << $1->lexeme << ": " << $$->type.t);
    }
#line 3281 "parser.tab.c"
    break;

  case 127:
#line 1453 "parser.y"
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
#line 3301 "parser.tab.c"
    break;

  case 128:
#line 1469 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
        (yyval.node)->type.t = "str";
    }
#line 3310 "parser.tab.c"
    break;

  case 129:
#line 1474 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
        (yyval.node)->type.t = "void";
    }
#line 3319 "parser.tab.c"
    break;

  case 130:
#line 1479 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 3328 "parser.tab.c"
    break;

  case 131:
#line 1484 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
    }
#line 3337 "parser.tab.c"
    break;

  case 132:
#line 1489 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3345 "parser.tab.c"
    break;

  case 133:
#line 1493 "parser.y"
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
#line 3360 "parser.tab.c"
    break;

  case 134:
#line 1506 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3368 "parser.tab.c"
    break;

  case 135:
#line 1510 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3376 "parser.tab.c"
    break;

  case 136:
#line 1516 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
        if (!type_equal((yyvsp[-2].node)->type,(yyvsp[0].node)->type)){
            Error::type_mismatch(yylineno, (yyvsp[-2].node)->type, (yyvsp[0].node)->type, ",");
        }else{
            (yyval.node)->type = (yyvsp[-2].node)->type;
        }
    }
#line 3390 "parser.tab.c"
    break;

  case 137:
#line 1526 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3400 "parser.tab.c"
    break;


#line 3404 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1534 "parser.y"

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
    int tac_file_arg = -1;
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
        else if (arg == "-output"){
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
    curr_symtable_global->add_range_func();
    
    declared_types.insert("int");
    declared_types.insert("float");
    declared_types.insert("bool");
    declared_types.insert("str");
    declared_types.insert("void");
    declared_types.insert("list");
    
    yyparse();
    DEBUG("Reached before csv creation");
    curr_symtable_global->create_csv("sample.csv");
    

    if (tac_file_arg != -1){
        three_ac::export_txt(argv[tac_file_arg]);
    }else{
        three_ac::export_txt("tac.txt");
    }

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
