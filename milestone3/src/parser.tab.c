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


#line 99 "parser.tab.c"

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
#line 30 "parser.y"

    struct TreeNode * node;

#line 225 "parser.tab.c"

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
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

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
       0,   163,   163,   173,   177,   194,   199,   203,   209,   216,
     227,   233,   238,   242,   248,   369,   373,   378,   383,   388,
     400,   410,   415,   423,   427,   431,   435,   439,   443,   447,
     451,   455,   459,   463,   467,   473,   477,   481,   487,   502,
     518,   527,   534,   553,   564,   570,   574,   578,   582,   586,
     592,   603,   602,   616,   630,   633,   637,   629,   656,   661,
     668,   667,   678,   678,   697,   702,   707,   714,   723,   713,
     784,   788,   783,   806,   806,   835,   840,   845,   851,   861,
     866,   877,   883,   890,   901,   910,   915,   924,   929,   936,
     942,   946,   965,   969,   987,  1002,  1008,  1026,  1033,  1037,
    1041,  1045,  1049,  1053,  1057,  1063,  1067,  1085,  1089,  1107,
    1111,  1129,  1133,  1149,  1167,  1171,  1187,  1205,  1209,  1225,
    1241,  1257,  1275,  1289,  1303,  1318,  1325,  1329,  1346,  1595,
    1606,  1610,  1619,  1624,  1631,  1644,  1661,  1668,  1674,  1680,
    1686,  1690,  1703,  1708,  1713,  1718
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
  "$@1", "else_stmt_dash", "elif_stmt", "$@2", "$@3", "$@4", "else_stmt",
  "$@5", "classdef", "$@6", "inheritlist", "for_stmt", "$@7", "$@8",
  "while_stmt", "$@9", "$@10", "funcdef", "$@11", "funcdef_dash",
  "parameters", "parameters_dash", "typedargslist", "tfpdef", "suite",
  "stmt_dash", "test", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "factor", "power", "atom_expr", "trailerlist", "trailer", "atom",
  "arglist", "arglist_dash", YY_NULLPTR
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
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,   189,    29,    30,    31,    96,    97,
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

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
#line 163 "parser.y"
                                      {
    if ((yyvsp[-1].node) != NULL){
        (yyval.node) = (yyvsp[-1].node);
    }else{
        (yyval.node) = NULL;
    }
    root = (yyval.node);
}
#line 1609 "parser.tab.c"
    break;

  case 3:
#line 174 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1617 "parser.tab.c"
    break;

  case 4:
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
#line 1637 "parser.tab.c"
    break;

  case 5:
#line 194 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1645 "parser.tab.c"
    break;

  case 6:
#line 200 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1653 "parser.tab.c"
    break;

  case 7:
#line 204 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1661 "parser.tab.c"
    break;

  case 8:
#line 210 "parser.y"
    {

        (yyval.node) = (yyvsp[-1].node);
    }
#line 1670 "parser.tab.c"
    break;

  case 9:
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
#line 1685 "parser.tab.c"
    break;

  case 10:
#line 228 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1693 "parser.tab.c"
    break;

  case 11:
#line 234 "parser.y"
    {   

        (yyval.node) = (yyvsp[0].node);
    }
#line 1702 "parser.tab.c"
    break;

  case 12:
#line 239 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1710 "parser.tab.c"
    break;

  case 13:
#line 243 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1718 "parser.tab.c"
    break;

  case 14:
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
                DEBUG("CLASS ATTRIBUTE DECLARATION");
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
                DEBUG("CLASS ATTRIBUTE ADDED");
            } else{
                Error::other_semantic_error("SYNTAX_ERROR: Expected Identifier in declaration", yylineno);
            }
            
            if((yyvsp[0].node)->children.size() == 3){
                if (!type_equal((yyvsp[-1].node)->type, (yyvsp[0].node)->children[2]->type)){
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
                    if ((yyvsp[-1].node)->type.elems != -1 || (yyvsp[-1].node)->type.t == "string"){
                        // list or string declaration
                        if (entry != NULL){
                            (yyvsp[-1].node)->type.elems = (yyvsp[0].node)->children[2]->type.elems;
                            string t = three_ac::new_temp();
                            three_ac::gen("symtable_get", "symtable.get", (yyvsp[0].node)->children[0]->lexeme, "", t);
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
                            DEBUG(drt)
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
#line 1841 "parser.tab.c"
    break;

  case 15:
#line 370 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1849 "parser.tab.c"
    break;

  case 16:
#line 374 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[-1].node)->lexeme,EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));    
    }
#line 1858 "parser.tab.c"
    break;

  case 17:
#line 379 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1866 "parser.tab.c"
    break;

  case 18:
#line 383 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 1874 "parser.tab.c"
    break;

  case 19:
#line 389 "parser.y"
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
#line 1890 "parser.tab.c"
    break;

  case 20:
#line 401 "parser.y"
    {
        (yyval.node) = makeNode("=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
     
        string drt = three_ac::dereference((yyvsp[0].node));
        (yyval.node)->addr = drt;
    }
#line 1902 "parser.tab.c"
    break;

  case 21:
#line 411 "parser.y"
    {
        (yyval.node) = makeNode(":", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1911 "parser.tab.c"
    break;

  case 22:
#line 416 "parser.y"
    {
        (yyval.node) = makeNode(":=", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 1921 "parser.tab.c"
    break;

  case 23:
#line 424 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1929 "parser.tab.c"
    break;

  case 24:
#line 428 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1937 "parser.tab.c"
    break;

  case 25:
#line 432 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1945 "parser.tab.c"
    break;

  case 26:
#line 436 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1953 "parser.tab.c"
    break;

  case 27:
#line 440 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1961 "parser.tab.c"
    break;

  case 28:
#line 444 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1969 "parser.tab.c"
    break;

  case 29:
#line 448 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1977 "parser.tab.c"
    break;

  case 30:
#line 452 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1985 "parser.tab.c"
    break;

  case 31:
#line 456 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1993 "parser.tab.c"
    break;

  case 32:
#line 460 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2001 "parser.tab.c"
    break;

  case 33:
#line 464 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2009 "parser.tab.c"
    break;

  case 34:
#line 468 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2017 "parser.tab.c"
    break;

  case 35:
#line 474 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2025 "parser.tab.c"
    break;

  case 36:
#line 478 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2033 "parser.tab.c"
    break;

  case 37:
#line 482 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2041 "parser.tab.c"
    break;

  case 38:
#line 488 "parser.y"
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
#line 2058 "parser.tab.c"
    break;

  case 39:
#line 503 "parser.y"
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
#line 2076 "parser.tab.c"
    break;

  case 40:
#line 519 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        checker_traverse((yyvsp[0].node));
        curr_symtable_func->check_returntype((yyvsp[0].node), yylineno);
        string drt = three_ac::dereference((yyvsp[0].node));
        three_ac::gen("return", "return", drt);
    }
#line 2089 "parser.tab.c"
    break;

  case 41:
#line 528 "parser.y"
    {
        (yyval.node) = makeNode("return",STATEMENT_TYPE);
        three_ac::gen("return", "return");   
    }
#line 2098 "parser.tab.c"
    break;

  case 42:
#line 535 "parser.y"
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
#line 2119 "parser.tab.c"
    break;

  case 43:
#line 554 "parser.y"
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
#line 2134 "parser.tab.c"
    break;

  case 44:
#line 565 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2142 "parser.tab.c"
    break;

  case 45:
#line 571 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2150 "parser.tab.c"
    break;

  case 46:
#line 575 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2158 "parser.tab.c"
    break;

  case 47:
#line 579 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2166 "parser.tab.c"
    break;

  case 48:
#line 583 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2174 "parser.tab.c"
    break;

  case 49:
#line 587 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2182 "parser.tab.c"
    break;

  case 50:
#line 593 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        if ((yyvsp[0].node) != NULL){
            appendChild((yyval.node), (yyvsp[0].node));
        }
        (yyval.node)->type.t = "void";
    }
#line 2194 "parser.tab.c"
    break;

  case 51:
#line 603 "parser.y"
    {
        three_ac::push_new_label("if");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, three_ac::get_label("else_start"));
    }
#line 2203 "parser.tab.c"
    break;

  case 52:
#line 607 "parser.y"
    {
        (yyval.node) = (yyvsp[-4].node);
        appendChild((yyval.node), (yyvsp[-3].node));
        appendChild((yyval.node), (yyvsp[0].node));
        string l = three_ac::get_label("if_end");
        three_ac::gen("goto", "goto", l);
    }
#line 2215 "parser.tab.c"
    break;

  case 53:
#line 617 "parser.y"
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
#line 2230 "parser.tab.c"
    break;

  case 54:
#line 630 "parser.y"
    {
        three_ac::gen("label", "label", three_ac::get_label("else_start"));        
    }
#line 2238 "parser.tab.c"
    break;

  case 55:
#line 633 "parser.y"
    {
        three_ac::push_new_label("if");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, three_ac::get_label("else_start"));
    }
#line 2247 "parser.tab.c"
    break;

  case 56:
#line 637 "parser.y"
    {
        string l = three_ac::get_label("if_end");
        three_ac::gen("goto", "goto", l);
    }
#line 2256 "parser.tab.c"
    break;

  case 57:
#line 642 "parser.y"
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
#line 2275 "parser.tab.c"
    break;

  case 58:
#line 657 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2283 "parser.tab.c"
    break;

  case 59:
#line 661 "parser.y"
    {
        (yyval.node) = NULL;  

    }
#line 2292 "parser.tab.c"
    break;

  case 60:
#line 668 "parser.y"
    {
        three_ac::gen("label", "label", three_ac::get_label("else_start"));
    }
#line 2300 "parser.tab.c"
    break;

  case 61:
#line 672 "parser.y"
    {
        (yyval.node) = (yyvsp[-3].node);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2309 "parser.tab.c"
    break;

  case 62:
#line 678 "parser.y"
                                   {
        curr_symtable_class = new symtable_class((yyvsp[-1].node),(yyvsp[0].node));
        curr_symtable_global->add_class(curr_symtable_class);
        declared_types.insert((yyvsp[-1].node)->lexeme);
        curr_symtable_global->add_len_func((yyvsp[-1].node)->lexeme);
    }
#line 2320 "parser.tab.c"
    break;

  case 63:
#line 684 "parser.y"
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
#line 2336 "parser.tab.c"
    break;

  case 64:
#line 698 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2344 "parser.tab.c"
    break;

  case 65:
#line 703 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2352 "parser.tab.c"
    break;

  case 66:
#line 707 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2360 "parser.tab.c"
    break;

  case 67:
#line 714 "parser.y"
    {
        three_ac::push_new_label("for");
        three_ac::gen("label", "label", three_ac::get_label("for_init"));
        if ((yyvsp[-1].node)->node_type != NAME_TYPE
        || !(type_equal((yyvsp[-1].node)->type, int_node))
        ){
            Error::other_semantic_error("TYPE_ERROR: Expected type int for iterator variable in for loop, got " + type_to_string((yyvsp[-1].node)->type), yylineno);
        }
    }
#line 2374 "parser.tab.c"
    break;

  case 68:
#line 723 "parser.y"
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
            Error::other_semantic_error("SYNTAX_ERROR: Expected range object in for loop", yylineno);
        }
    }
#line 2423 "parser.tab.c"
    break;

  case 69:
#line 767 "parser.y"
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
#line 2442 "parser.tab.c"
    break;

  case 70:
#line 784 "parser.y"
    {
        three_ac::push_new_label("while");
        three_ac::gen("label", "label", three_ac::get_label("while_start"));
    }
#line 2451 "parser.tab.c"
    break;

  case 71:
#line 788 "parser.y"
    {
        string l = three_ac::get_label("while_end");
        three_ac::gen("if_goto", "if_false", (yyvsp[-1].node)->addr, l);
    }
#line 2460 "parser.tab.c"
    break;

  case 72:
#line 792 "parser.y"
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
#line 2477 "parser.tab.c"
    break;

  case 73:
#line 806 "parser.y"
                                             {
        curr_symtable_func  = new symtable_func((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node),yylineno); 
        if(curr_symtable_class != NULL){
            curr_symtable_class->add_func(curr_symtable_func);
        }else{
            curr_symtable_global->add_func(curr_symtable_func);
        }

        three_ac::gen("beginfunc", "beginfunc", curr_symtable_func->name);
        for (auto x: curr_symtable_func->paramlist){
            DEBUG(x.second->name)
            x.second->addr = three_ac::new_temp();
            three_ac::gen("assign", "=", "popparam", "", x.second->addr);
        }
    }
#line 2497 "parser.tab.c"
    break;

  case 74:
#line 820 "parser.y"
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
#line 2515 "parser.tab.c"
    break;

  case 75:
#line 836 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2523 "parser.tab.c"
    break;

  case 76:
#line 840 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
    }
#line 2531 "parser.tab.c"
    break;

  case 77:
#line 846 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2539 "parser.tab.c"
    break;

  case 78:
#line 852 "parser.y"
    {
        if (((yyvsp[0].node) != NULL) && (yyvsp[0].node)->node_type == PARAMETERS_TYPE){
            (yyval.node) = (yyvsp[0].node);
        }else{
            (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 2552 "parser.tab.c"
    break;

  case 79:
#line 861 "parser.y"
    {   
        (yyval.node) = makeNode("parameters",PARAMETERS_TYPE);
    }
#line 2560 "parser.tab.c"
    break;

  case 80:
#line 867 "parser.y"
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
#line 2575 "parser.tab.c"
    break;

  case 81:
#line 878 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2583 "parser.tab.c"
    break;

  case 82:
#line 884 "parser.y"
    {
        (yyval.node) = makeNode(":",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2593 "parser.tab.c"
    break;

  case 83:
#line 891 "parser.y"
    {
        if (curr_symtable_class != NULL){
            if ((yyvsp[0].node)->lexeme == "self"){
                (yyval.node) = NULL;
            }else{
                Error::other_semantic_error("TYPE_ERROR: Expected variable type for "+(yyvsp[0].node)->lexeme, yylineno);
            }
        }
    }
#line 2607 "parser.tab.c"
    break;

  case 84:
#line 902 "parser.y"
    {
        (yyval.node) = makeNode(":=",EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-4].node));
        appendChild((yyval.node), (yyvsp[-2].node));
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2618 "parser.tab.c"
    break;

  case 85:
#line 911 "parser.y"
    {   
        (yyval.node) = makeNode("", SUITE_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2627 "parser.tab.c"
    break;

  case 86:
#line 916 "parser.y"
    {
        (yyval.node) = makeNode("", SUITE_TYPE);
        for (auto x: (yyvsp[-1].node)->children){
            appendChild((yyval.node), x);
        }
    }
#line 2638 "parser.tab.c"
    break;

  case 87:
#line 925 "parser.y"
    {
        appendChild((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2647 "parser.tab.c"
    break;

  case 88:
#line 930 "parser.y"
    {
        (yyval.node) = makeNode("statements", STATEMENT_GROUP_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 2656 "parser.tab.c"
    break;

  case 89:
#line 937 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2664 "parser.tab.c"
    break;

  case 90:
#line 943 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2672 "parser.tab.c"
    break;

  case 91:
#line 947 "parser.y"
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
#line 2693 "parser.tab.c"
    break;

  case 92:
#line 966 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2701 "parser.tab.c"
    break;

  case 93:
#line 970 "parser.y"
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
#line 2721 "parser.tab.c"
    break;

  case 94:
#line 988 "parser.y"
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
#line 2740 "parser.tab.c"
    break;

  case 95:
#line 1003 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2748 "parser.tab.c"
    break;

  case 96:
#line 1009 "parser.y"
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
#line 2770 "parser.tab.c"
    break;

  case 97:
#line 1027 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2778 "parser.tab.c"
    break;

  case 98:
#line 1034 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2786 "parser.tab.c"
    break;

  case 99:
#line 1038 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2794 "parser.tab.c"
    break;

  case 100:
#line 1042 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2802 "parser.tab.c"
    break;

  case 101:
#line 1046 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2810 "parser.tab.c"
    break;

  case 102:
#line 1050 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2818 "parser.tab.c"
    break;

  case 103:
#line 1054 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2826 "parser.tab.c"
    break;

  case 104:
#line 1058 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2834 "parser.tab.c"
    break;

  case 105:
#line 1064 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2842 "parser.tab.c"
    break;

  case 106:
#line 1068 "parser.y"
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
#line 2862 "parser.tab.c"
    break;

  case 107:
#line 1086 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2870 "parser.tab.c"
    break;

  case 108:
#line 1090 "parser.y"
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
#line 2890 "parser.tab.c"
    break;

  case 109:
#line 1108 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2898 "parser.tab.c"
    break;

  case 110:
#line 1112 "parser.y"
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
#line 2918 "parser.tab.c"
    break;

  case 111:
#line 1130 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2926 "parser.tab.c"
    break;

  case 112:
#line 1134 "parser.y"
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
#line 2946 "parser.tab.c"
    break;

  case 113:
#line 1150 "parser.y"
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
#line 2966 "parser.tab.c"
    break;

  case 114:
#line 1168 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2974 "parser.tab.c"
    break;

  case 115:
#line 1172 "parser.y"
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
#line 2994 "parser.tab.c"
    break;

  case 116:
#line 1188 "parser.y"
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
#line 3014 "parser.tab.c"
    break;

  case 117:
#line 1206 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3022 "parser.tab.c"
    break;

  case 118:
#line 1210 "parser.y"
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
#line 3042 "parser.tab.c"
    break;

  case 119:
#line 1226 "parser.y"
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
#line 3062 "parser.tab.c"
    break;

  case 120:
#line 1242 "parser.y"
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
#line 3082 "parser.tab.c"
    break;

  case 121:
#line 1258 "parser.y"
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
#line 3102 "parser.tab.c"
    break;

  case 122:
#line 1276 "parser.y"
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
#line 3120 "parser.tab.c"
    break;

  case 123:
#line 1290 "parser.y"
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
#line 3138 "parser.tab.c"
    break;

  case 124:
#line 1304 "parser.y"
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
#line 3157 "parser.tab.c"
    break;

  case 125:
#line 1319 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        
    }
#line 3166 "parser.tab.c"
    break;

  case 126:
#line 1326 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3174 "parser.tab.c"
    break;

  case 127:
#line 1330 "parser.y"
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
#line 3193 "parser.tab.c"
    break;

  case 128:
#line 1347 "parser.y"
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
            if((global_symtable->search_class(temp_name)!=NULL&&(yyvsp[0].node)->children.size()>0&&(yyvsp[0].node)->children[0]->lexeme == "()")||!is_declared_type((yyvsp[-1].node)->lexeme)){
            DEBUG(temp_addr<<temp_name)
                for (int i = 0; i < (yyvsp[0].node)->children.size(); i++){
                    if ((yyvsp[0].node)->children[i]->lexeme == "()" && i == 0){
                        // function call
                        if ((yyvsp[-1].node)->node_type != NAME_TYPE){
                            Error::other_semantic_error("TYPE_ERROR: Invalid operation ()", yylineno);
                        }else{
                            string func_id = (yyvsp[-1].node)->lexeme;
                            if(global_symtable->search_class(func_id)){
                                DEBUG("Entered Func_id search")
                                func_id = func_id + "." + "__init__" + "@" + func_id;
                            }

                            
                            for (auto x: (yyvsp[0].node)->children[i]->children){
                                DEBUG("params: "<< x->lexeme)
                                func_id += "@" + type_to_string(x->type);
                            }

                            struct type ret = string_to_type(func_id);
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
                                if(ret.t!="void") three_ac::gen("assign","=","popparam","",temp_reg);
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
                                    Error::other_semantic_error("TYPE_ERROR: Expression inside [] for indexing must have type int, got " + type_to_string((yyvsp[0].node)->children[i]->children[0]->type), yylineno);
                                }
                            }else{
                                if (temp.t == "-1" && i == 0){
                                    Error::use_before_declaration((yyvsp[-1].node)->lexeme, yylineno);
                                }else{
                                    Error::other_semantic_error("TYPE_ERROR: Invalid operation [] performed on type " + type_to_string(temp), yylineno);
                                }
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
                            class_id+="@"+class_name;
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
                            symtable_entry* object_entry = symtable_look_up((yyvsp[-1].node)->lexeme);            
                            
                            if(object_entry == NULL){
                                Error::sem_no_declaration_var((yyvsp[-1].node)->lexeme,yylineno);
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
                            
                            three_ac::gen("stackpointer+",to_string(stack_shift));
                            three_ac::gen("call",(yyvsp[-1].node)->lexeme+"."+class_id,to_string((yyvsp[0].node)->children[i+1]->children.size()+1));
                            stack_shift -= ret.size;
                            three_ac::gen("stackpointer-",to_string(stack_shift));
                            string temp_reg = three_ac::new_temp();
                            three_ac::gen("popparam","","","",temp_reg);
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
                    }else{
                        Error::other_semantic_error("TYPE_ERROR: Invalid operation near " + (yyvsp[0].node)->children[i]->lexeme[0], yylineno);   
                    }
                }
            }
            (yyval.node)->type = temp;
        } 
    }
#line 3444 "parser.tab.c"
    break;

  case 129:
#line 1596 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL){
            (yyval.node) = makeNode("trailer",TRAILER_TYPE);
            appendChild((yyval.node), (yyvsp[0].node));
        }else{
            (yyval.node) = (yyvsp[-1].node);
            appendChild((yyval.node), (yyvsp[0].node));
        }
    }
#line 3458 "parser.tab.c"
    break;

  case 130:
#line 1606 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3466 "parser.tab.c"
    break;

  case 131:
#line 1611 "parser.y"
    {
        (yyval.node) = makeNode("()", EXPR_TYPE);
        if ((yyvsp[-1].node) != NULL){
            for (auto x: (yyvsp[-1].node)->children){
                appendChild((yyval.node), x);
            }
        }
    }
#line 3479 "parser.tab.c"
    break;

  case 132:
#line 1620 "parser.y"
    {
        (yyval.node) = makeNode("[]", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[-1].node));
    }
#line 3488 "parser.tab.c"
    break;

  case 133:
#line 1625 "parser.y"
    {
        (yyval.node) = makeNode(".", EXPR_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
    }
#line 3497 "parser.tab.c"
    break;

  case 134:
#line 1632 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,NAME_TYPE);
        
        symtable_entry * entry = symtable_look_up((yyvsp[0].node)->lexeme);
        if (entry != NULL){
            DEBUG("Self name : " << entry->name)
            DEBUG("Self type : " << entry->type.t)
            
            (yyval.node)->type = string_to_type((yyvsp[0].node)->lexeme);
            (yyval.node)->addr = entry->addr;
        }
    }
#line 3514 "parser.tab.c"
    break;

  case 135:
#line 1645 "parser.y"
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
#line 3535 "parser.tab.c"
    break;

  case 136:
#line 1662 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,STRING_TYPE);
        DEBUG((yyval.node)->lexeme);
        (yyval.node)->type.t = "str";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3546 "parser.tab.c"
    break;

  case 137:
#line 1669 "parser.y"
    {
        (yyval.node) = makeNode("void",NAME_TYPE);
        (yyval.node)->type.t = "void";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3556 "parser.tab.c"
    break;

  case 138:
#line 1675 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3566 "parser.tab.c"
    break;

  case 139:
#line 1681 "parser.y"
    {
        (yyval.node) = makeNode((yyvsp[0].node)->lexeme,BOOLEAN_TYPE);
        (yyval.node)->type.t = "bool";
        (yyval.node)->addr = (yyval.node)->lexeme;
    }
#line 3576 "parser.tab.c"
    break;

  case 140:
#line 1687 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3584 "parser.tab.c"
    break;

  case 141:
#line 1691 "parser.y"
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
#line 3599 "parser.tab.c"
    break;

  case 142:
#line 1704 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3607 "parser.tab.c"
    break;

  case 143:
#line 1708 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 3615 "parser.tab.c"
    break;

  case 144:
#line 1714 "parser.y"
    {
        appendChild((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 3624 "parser.tab.c"
    break;

  case 145:
#line 1719 "parser.y"
    {
        (yyval.node) = makeNode("",MISC_TYPE);
        appendChild((yyval.node), (yyvsp[0].node));
        (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3634 "parser.tab.c"
    break;


#line 3638 "parser.tab.c"

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
#line 1724 "parser.y"

