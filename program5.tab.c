/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "program5.y" /* yacc.c:339  */


#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "attributes.h"

using std::cerr;
using std::cout;
using std::endl;

// externs defined in program3.cpp 
extern vector<Node*> forest;
extern yyFlexLexer myScanner;

// Make C++ scanner play nice with C parser
#define yylex() myScanner.yylex()

// Parser function prototype
void yyerror(const char *);


#line 89 "program5.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "program5.tab.h".  */
#ifndef YY_YY_PROGRAM5_TAB_H_INCLUDED
# define YY_YY_PROGRAM5_TAB_H_INCLUDED
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
    DOT = 258,
    THIS = 259,
    LBRACK = 260,
    RBRACK = 261,
    DOUBBRACK = 262,
    LBRACE = 263,
    RBRACE = 264,
    INT = 265,
    IDEN = 266,
    NUM = 267,
    NLL = 268,
    READ = 269,
    NEW = 270,
    LPAREN = 271,
    RPAREN = 272,
    IF = 273,
    ELSE = 274,
    DEQ = 275,
    NEQ = 276,
    LEQ = 277,
    GEQ = 278,
    GT = 279,
    LT = 280,
    PLUS = 281,
    MINUS = 282,
    OR = 283,
    MULT = 284,
    DIVD = 285,
    MOD = 286,
    AND = 287,
    BANG = 288,
    SEMI = 289,
    EQ = 290,
    COMMA = 291,
    RETURN = 292,
    WHILE = 293,
    PRINT = 294,
    VOID = 295,
    CLASS = 296,
    RO = 297,
    SO = 298,
    PO = 299,
    UO = 300,
    DE = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "program5.y" /* yacc.c:355  */

  Node *ttype;
  struct attributes* atts;

#line 181 "program5.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM5_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "program5.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    81,    88,    99,   104,   113,   122,   131,
     141,   151,   161,   177,   184,   192,   199,   207,   214,   223,
     235,   247,   259,   273,   284,   295,   308,   314,   325,   327,
     333,   337,   343,   350,   354,   364,   374,   382,   393,   404,
     412,   423,   434,   441,   452,   462,   468,   476,   485,   496,
     508,   521,   537,   542,   551,   560,   572,   579,   587,   594,
     602,   608,   619,   621,   630,   637,   641,   645,   655,   665,
     671,   679,   687,   694,   700,   706,   712,   717,   723,   733,
     741,   752,   764,   766,   773,   775,   781,   795,   797,   803,
     807,   813,   817,   821,   827,   834,   846,   850,   857,   860,
     865,   868,   871,   874,   877,   880,   885,   888,   891,   896,
     899,   902,   905,   910,   913,   916
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "THIS", "LBRACK", "RBRACK",
  "DOUBBRACK", "LBRACE", "RBRACE", "INT", "IDEN", "NUM", "NLL", "READ",
  "NEW", "LPAREN", "RPAREN", "IF", "ELSE", "DEQ", "NEQ", "LEQ", "GEQ",
  "GT", "LT", "PLUS", "MINUS", "OR", "MULT", "DIVD", "MOD", "AND", "BANG",
  "SEMI", "EQ", "COMMA", "RETURN", "WHILE", "PRINT", "VOID", "CLASS", "RO",
  "SO", "PO", "UO", "DE", "$accept", "program", "classdec", "classbody",
  "methdecplus", "constdecplus", "vardecplus", "methoddec", "constdec",
  "vardec", "paramlist", "paramplus", "param", "statement",
  "condstatement", "block", "stateplus", "locvardecplus", "locvardec",
  "optexp", "exp", "newexp", "brackstar", "expstar", "arglist", "explist",
  "name", "type", "simpleType", "relop", "sumop", "proop", "unyop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -100

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,    -4,     5,  -107,     4,  -107,  -107,    18,  -107,  -107,
    -107,   166,    42,   128,   235,   267,  -107,  -107,  -107,     2,
    -107,   223,   223,    -2,  -107,  -107,  -107,   116,  -107,   270,
    -107,  -107,   273,   276,  -107,  -107,    10,    55,    23,  -107,
     137,    63,   223,    66,  -107,  -107,  -107,   279,  -107,   223,
    -107,    77,   223,  -107,    77,    77,    96,  -107,   104,    91,
    -107,  -107,  -107,  -107,    77,    77,    77,    77,  -107,  -107,
     165,    80,  -107,   288,    94,   106,  -107,  -107,  -107,    39,
     108,  -107,    76,   167,  -107,  -107,  -107,  -107,   288,  -107,
    -107,  -107,    38,   286,   288,  -107,  -107,  -107,     7,   319,
    -107,   322,   288,   288,   288,  -107,  -107,  -107,    52,  -107,
     109,   288,   288,   288,    34,   163,   118,   198,   125,  -107,
     180,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   288,   288,   288,   288,
    -107,   197,   319,   215,   113,  -107,  -107,   229,   230,   131,
    -107,  -107,   132,   132,  -107,  -107,  -107,   288,   170,  -107,
    -107,   210,   299,  -107,   292,   132,   132,   145,    35,   288,
    -107,  -107,   162,    37,  -107,  -107,   194,   272,   294,   288,
     287,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   319,  -107,
    -107,  -107,   132,   132,  -107,  -107,   242,  -107,  -107,  -107,
    -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     3,     0,     4,     5,
      98,     0,     0,     0,     0,     0,    13,    15,    17,     0,
      96,    28,    28,     0,     8,    99,    14,     0,     7,     0,
      16,     6,     0,     0,    18,    97,     0,     0,    29,    30,
       0,     0,    28,     0,    11,    10,     9,     0,    27,    28,
      26,     0,     0,    32,     0,     0,     0,    12,     0,     0,
      24,    31,    25,    23,     0,     0,     0,     0,    91,    52,
      92,     0,    33,    62,     0,     0,    56,    42,    47,     0,
       0,    58,     0,     0,    22,    20,    21,    19,     0,    92,
      65,    66,     0,     0,     0,   113,   114,   115,     0,    63,
      72,    64,     0,     0,    87,    54,    57,    53,     0,    59,
       0,     0,    87,     0,     0,     0,     0,     0,    99,    84,
       0,    46,    45,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,    87,
      76,     0,    89,     0,    88,    55,    93,     0,     0,     0,
      61,    60,     0,     0,    71,    70,    69,    87,    82,    78,
      77,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      95,    94,     0,     0,    35,    34,    49,    48,     0,     0,
      81,    68,    67,    44,    43,    41,    40,    39,    90,    38,
      37,    36,     0,     0,    80,    79,     0,    83,    51,    50,
      86,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   296,  -107,     1,   290,  -107,   -10,    70,   291,
      82,  -107,   256,   -78,  -107,   269,   232,  -107,   237,  -107,
     -71,  -107,  -107,  -107,  -106,  -107,   -59,     3,   225,  -107,
    -107,  -107,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    13,    14,    15,    16,    17,    18,
      37,    38,    39,    76,    77,    78,    79,    80,    81,    98,
     142,   100,   180,   158,   143,   144,   101,    27,    20,   136,
     137,   138,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,   106,    99,    26,     1,     5,   148,     4,   121,    35,
      19,    48,     7,    36,    42,    29,    32,   115,    19,    26,
      82,    82,    26,   120,    40,    40,    49,     9,    10,    11,
     106,   140,   141,   164,    47,   150,   186,    26,   190,   116,
     147,   122,   149,    68,    50,    40,     1,    59,   105,    82,
      89,   178,    40,    23,   117,    40,    68,    71,    12,    52,
      59,   145,    83,    89,    54,   161,   162,   163,   151,   187,
      71,   191,    51,    72,   176,   177,    73,    74,    75,   110,
      55,   111,    49,    83,    30,    59,    72,   183,   184,    73,
      74,    75,   112,    82,    82,    68,    88,    64,   188,    59,
      69,    10,    70,    30,    41,    66,    82,    82,   196,    71,
     103,   113,    68,    65,   198,   199,    59,   107,    10,    70,
     146,    67,   104,    35,    56,    72,    71,    43,    73,    74,
      75,    58,   174,    82,    82,   154,    68,    24,    10,    25,
      59,   157,    72,    89,    35,    73,    74,    75,    53,   169,
      71,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   152,   175,    72,    21,    12,    73,
      74,    75,   -99,   -99,    35,   179,   -99,   -99,   114,   185,
     153,   159,    22,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   189,   160,   165,   155,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   192,   166,   156,   167,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     170,   172,   168,    10,    25,   171,   129,   130,   131,   132,
     133,   134,   135,   200,    28,    10,    11,   173,   201,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    12,    31,    10,    11,    44,
      10,    25,    45,    10,    25,    46,    10,    11,    57,    10,
      25,   193,    68,   181,   197,   194,    10,   118,     6,    89,
      90,    91,    92,    93,    94,    33,    34,    12,    61,   182,
      12,   195,   108,    12,    95,    96,    12,   109,   119,    12,
      60,    97,     0,    62,    63,   110,     0,   111,   132,   133,
     134,   135,     0,    84,    85,    86,    87,     0,   139,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135
};

static const yytype_int16 yycheck[] =
{
      59,    79,    73,    13,    41,     0,   112,    11,     1,     7,
       7,     1,     8,    11,    16,    14,    15,    88,    15,    29,
      79,    80,    32,    94,    21,    22,    16,     9,    10,    11,
     108,   102,   103,   139,    33,     1,     1,    47,     1,     1,
     111,    34,   113,     4,    34,    42,    41,     8,     9,   108,
      11,   157,    49,    11,    16,    52,     4,    18,    40,    36,
       8,     9,    59,    11,     1,   136,   137,   138,    34,    34,
      18,    34,    17,    34,   152,   153,    37,    38,    39,     3,
      17,     5,    16,    80,    14,     8,    34,   165,   166,    37,
      38,    39,    16,   152,   153,     4,    16,     1,   169,     8,
       9,    10,    11,    33,    22,     1,   165,   166,   179,    18,
      16,    35,     4,    17,   192,   193,     8,     9,    10,    11,
      11,    17,    16,     7,    42,    34,    18,    11,    37,    38,
      39,    49,     1,   192,   193,    17,     4,     9,    10,    11,
       8,    16,    34,    11,     7,    37,    38,    39,    11,    36,
      18,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     1,    34,    34,     1,    40,    37,
      38,    39,     7,     7,     7,     5,    11,    11,    11,    34,
      17,     1,    16,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    34,    17,     1,     1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    19,    17,    17,     1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       1,     1,    17,    10,    11,     6,    26,    27,    28,    29,
      30,    31,    32,     1,     9,    10,    11,    17,     6,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    40,     9,    10,    11,     9,
      10,    11,     9,    10,    11,     9,    10,    11,     9,    10,
      11,    19,     4,     1,     7,     1,    10,    11,     2,    11,
      12,    13,    14,    15,    16,    15,    15,    40,    52,    17,
      40,    17,    80,    40,    26,    27,    40,    80,    93,    40,
      51,    33,    -1,    54,    55,     3,    -1,     5,    29,    30,
      31,    32,    -1,    64,    65,    66,    67,    -1,    16,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    48,    49,    11,     0,    49,     8,    50,     9,
      10,    11,    40,    51,    52,    53,    54,    55,    56,    74,
      75,     1,    16,    11,     9,    11,    54,    74,     9,    51,
      55,     9,    51,    52,    56,     7,    11,    57,    58,    59,
      74,    57,    16,    11,     9,     9,     9,    51,     1,    16,
      34,    17,    36,    11,     1,    17,    57,     9,    57,     8,
      62,    59,    62,    62,     1,    17,     1,    17,     4,     9,
      11,    18,    34,    37,    38,    39,    60,    61,    62,    63,
      64,    65,    73,    74,    62,    62,    62,    62,    16,    11,
      12,    13,    14,    15,    16,    26,    27,    33,    66,    67,
      68,    73,    79,    16,    16,     9,    60,     9,    63,    65,
       3,     5,    16,    35,    11,    67,     1,    16,    11,    75,
      67,     1,    34,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    76,    77,    78,    16,
      67,    67,    67,    71,    72,     9,    11,    67,    71,    67,
       1,    34,     1,    17,    17,     1,    17,    16,    70,     1,
      17,    67,    67,    67,    71,     1,    17,     1,    17,    36,
       1,     6,     1,    17,     1,    34,    60,    60,    71,     5,
      69,     1,    17,    60,    60,    34,     1,    34,    67,    34,
       1,    34,    19,    19,     1,    17,    67,     7,    60,    60,
       1,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     2,     3,     3,     3,     4,
       4,     4,     5,     1,     2,     1,     2,     1,     2,     6,
       6,     6,     6,     5,     5,     5,     3,     3,     0,     1,
       1,     3,     2,     1,     4,     4,     5,     5,     5,     5,
       5,     5,     1,     5,     5,     3,     3,     1,     5,     5,
       7,     7,     2,     3,     3,     4,     1,     2,     1,     2,
       3,     3,     0,     1,     1,     1,     1,     4,     4,     3,
       3,     3,     1,     3,     3,     3,     2,     3,     3,     5,
       5,     4,     0,     2,     0,     4,     4,     0,     1,     1,
       3,     1,     1,     3,     4,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 77 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
               (yyval.ttype)->setValid(false);
             }
             forest.push_back((yyvsp[0].ttype));}
#line 1453 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
               (yyval.ttype)->setValid(false);
             }
             forest.push_back((yyvsp[0].ttype));}
#line 1462 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classdecNode((yyvsp[-1].atts)->value);
              (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
              if(!(yyvsp[0].ttype)->getValid()) {
                (yyval.ttype)->setValid(false);
              }
              (yyval.ttype)->addChild((yyvsp[0].ttype));
              delete (yyvsp[-2].atts);
              delete (yyvsp[-1].atts);}
#line 1475 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("empty");
              (yyval.ttype)->setlnum((yyvsp[-1].atts)->lNum);
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1484 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("vdecs");
              (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
               if(!(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1497 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("cdecs");
              (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
               if(!(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1510 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("mdecs");
              (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
               if(!(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1523 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 132 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("vcdecs");
              (yyval.ttype)->setlnum((yyvsp[-3].atts)->lNum);
               if(!(yyvsp[-2].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[0].atts);}
#line 1537 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("vmdecs");
              (yyval.ttype)->setlnum((yyvsp[-3].atts)->lNum);
               if(!(yyvsp[-2].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[0].atts);}
#line 1551 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("cmdecs");
              (yyval.ttype)->setlnum((yyvsp[-3].atts)->lNum);
               if(!(yyvsp[-2].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[0].atts);}
#line 1565 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new classbodyNode("vcmdecs");
              (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               if(!(yyvsp[-3].ttype)->getValid() || !(yyvsp[-2].ttype)->getValid() || (yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               if(!(yyvsp[-3].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-3].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[0].atts);}
#line 1583 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 178 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                   (yyval.ttype)->setValid(false);
                 }
                 (yyval.ttype) = new plusstarNode();
                 (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
                 (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1594 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 185 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                   (yyval.ttype)->setValid(false);
                 }
                 (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
                 (yyval.ttype) = (yyvsp[-1].ttype);}
#line 1604 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 193 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                    (yyval.ttype)->setValid(false);
                  }
                  (yyval.ttype) = new plusstarNode();
                  (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
                  (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1615 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 200 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                    (yyval.ttype)->setValid(false);
                  }
                  (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
                  (yyval.ttype) = (yyvsp[-1].ttype);}
#line 1625 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 208 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                  (yyval.ttype)->setValid(false);
                }
                (yyval.ttype) = new plusstarNode();
                (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
                (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1636 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                   (yyval.ttype)->setValid(false);
                }
                (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
                (yyval.ttype) = (yyvsp[-1].ttype);}
#line 1646 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new methoddecNode("type", (yyvsp[-4].atts)->value);
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-5].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);}
#line 1662 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 236 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new methoddecNode("void", (yyvsp[-4].atts)->value);
               (yyval.ttype)->setlnum((yyvsp[-5].atts)->lNum);
               if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               delete (yyvsp[-5].atts);
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);}
#line 1678 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Expected ')' after parameter list: line " 
                    << (yyvsp[-4].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<MethDec>");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               (yyval.ttype)->addChild((yyvsp[-5].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               (yyval.ttype)->setValid(false);
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               yyerrok;}
#line 1694 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Expected ')' after parameter list: line " 
                    << (yyvsp[-4].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<MethDec>");
               (yyval.ttype)->setlnum((yyvsp[-5].atts)->lNum);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               (yyval.ttype)->setValid(false);
               delete (yyvsp[-5].atts);
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               yyerrok;}
#line 1710 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 274 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new constdecNode((yyvsp[-4].atts)->value);
              (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
              if(!(yyvsp[0].ttype)->getValid()) {
                (yyval.ttype)->setValid(false);
              }
              (yyval.ttype)->addChild((yyvsp[-2].ttype));
              (yyval.ttype)->addChild((yyvsp[0].ttype));
              delete (yyvsp[-4].atts);
              delete (yyvsp[-3].atts);
              delete (yyvsp[-1].atts);}
#line 1725 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 285 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Expected '(' after identifier: line " 
                   << (yyvsp[-4].atts)->lNum << endl << endl;
              (yyval.ttype) = new errorNode("<ConstDec>");
              (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
              (yyval.ttype)->addChild((yyvsp[-2].ttype));
              (yyval.ttype)->addChild((yyvsp[0].ttype));
              (yyval.ttype)->setValid(false);
              delete (yyvsp[-4].atts);
              delete (yyvsp[-1].atts);
              yyerrok;}
#line 1740 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 296 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Expected ')' after parameter list: line " 
                   << (yyvsp[-4].atts)->lNum << endl << endl;
              (yyval.ttype) = new errorNode("<ConstDec>");
              (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
              (yyval.ttype)->addChild((yyvsp[-2].ttype));
              (yyval.ttype)->addChild((yyvsp[0].ttype));
              (yyval.ttype)->setValid(false);
              delete (yyvsp[-4].atts);
              delete (yyvsp[-3].atts);
              yyerrok;}
#line 1755 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 309 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new varDecNode((yyvsp[-1].atts)->value);
            (yyval.ttype)->setlnum((yyvsp[-1].atts)->lNum);
            (yyval.ttype)->addChild((yyvsp[-2].ttype));
            delete (yyvsp[-1].atts);
            delete (yyvsp[0].atts);}
#line 1765 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 315 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after identifier: line " 
                 << (yyvsp[-1].atts)->lNum << endl << endl;
            (yyval.ttype) = new errorNode("<VarDec>");
            (yyval.ttype)->setlnum((yyvsp[-1].atts)->lNum);
            (yyval.ttype)->addChild((yyvsp[-2].ttype));
            (yyval.ttype)->setValid(false);
            delete (yyvsp[-1].atts);
            yyerrok;}
#line 1778 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 326 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new paramlistNode("empty");}
#line 1784 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 328 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new paramlistNode("rec");
               (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1792 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 334 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();
               (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1800 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 338 "program5.y" /* yacc.c:1646  */
    {(yyvsp[-2].ttype)->addChild((yyvsp[0].ttype));
               (yyval.ttype) = (yyvsp[-2].ttype);
               delete (yyvsp[-1].atts);}
#line 1808 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new paramNode((yyvsp[0].atts)->value);
           (yyval.ttype)->setlnum((yyvsp[-1].ttype)->getlnum());
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[0].atts);}
#line 1817 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 351 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("semi");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 1825 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 355 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("nameeq");
               (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
               if(!(yyvsp[-3].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-3].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1839 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 365 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after statement: line " 
                    << (yyvsp[-2].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-3].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               yyerrok;}
#line 1853 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 375 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("namearglist");
               (yyval.ttype)->setlnum((yyvsp[-4].ttype)->getlnum());
               (yyval.ttype)->addChild((yyvsp[-4].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1865 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 383 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after statement: line " 
                    << (yyvsp[-3].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-4].ttype)->getlnum());
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-4].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               yyerrok;}
#line 1880 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 394 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after arglist in statement: line " 
                    << (yyvsp[-3].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-4].ttype)->getlnum());
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-4].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[0].atts);
               yyerrok;}
#line 1895 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 405 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("printarglist");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1907 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 413 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after statement: line " 
                    << (yyvsp[-3].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               yyerrok;}
#line 1922 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after arglist in statement: line " 
                    << (yyvsp[-3].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[0].atts);
               yyerrok;}
#line 1937 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 435 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("cond");
               (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
               if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1948 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 442 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("while");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               if(!(yyvsp[-2].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);}
#line 1963 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 453 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after while expression in statement: line " 
                    << (yyvsp[-3].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);}
#line 1977 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 463 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("optexp");
               (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1987 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 469 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after return statement: line " 
                    << (yyvsp[-2].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);}
#line 1999 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 477 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("block");
               (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
               if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2010 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 486 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new condstatementNode("if");
                   (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
                   if(!(yyvsp[-2].ttype)->getValid()) {
                     (yyval.ttype)->setValid(false);
                   }
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-4].atts);
                   delete (yyvsp[-3].atts);
                   delete (yyvsp[-1].atts);}
#line 2025 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 497 "program5.y" /* yacc.c:1646  */
    {cerr << endl 
                        << "Missing ')' after expression in conditional statement: line " 
                        << (yyvsp[-3].atts)->lNum << endl << endl;
                   (yyval.ttype) = new errorNode("<ConditionalStatement>");
                   (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
                   (yyval.ttype)->setValid(false);
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-4].atts);
                   delete (yyvsp[-3].atts);
                   yyerrok;}
#line 2041 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 509 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new condstatementNode("if-else");
                   (yyval.ttype)->setlnum((yyvsp[-6].atts)->lNum);
                   if(!(yyvsp[-4].ttype)->getValid()) {
                     (yyval.ttype)->setValid(false);
                   }
                   (yyval.ttype)->addChild((yyvsp[-4].ttype));
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-6].atts);
                   delete (yyvsp[-5].atts);
                   delete (yyvsp[-3].atts);
                   delete (yyvsp[-1].atts);}
#line 2058 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 522 "program5.y" /* yacc.c:1646  */
    {cerr << endl 
                        << "Missing ')' after expression in conditional statement: line " 
                        << (yyvsp[-5].atts)->lNum << endl << endl;
                   (yyval.ttype) = new errorNode("<ConditionalStatement>");
                   (yyval.ttype)->setlnum((yyvsp[-6].atts)->lNum);
                   (yyval.ttype)->setValid(false);
                   (yyval.ttype)->addChild((yyvsp[-4].ttype));
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-6].atts);
                   delete (yyvsp[-5].atts);
                   delete (yyvsp[-1].atts);
                   yyerrok;}
#line 2076 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 538 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("empty");
           (yyval.ttype)->setlnum((yyvsp[-1].atts)->lNum);
           delete (yyvsp[-1].atts);
           delete (yyvsp[0].atts);}
#line 2085 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 543 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("locvardecs");
           (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
           if(!(yyvsp[-1].ttype)->getValid()) {
             (yyval.ttype)->setValid(false);
           }
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-2].atts);
           delete (yyvsp[0].atts);}
#line 2098 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 552 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("statements");
           (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
           if(!(yyvsp[-1].ttype)->getValid()) {
             (yyval.ttype)->setValid(false);
           }
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-2].atts);
           delete (yyvsp[0].atts);}
#line 2111 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 561 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("both");
           (yyval.ttype)->setlnum((yyvsp[-3].atts)->lNum);
           if(!(yyvsp[-2].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
             (yyval.ttype)->setValid(false);
           }
           (yyval.ttype)->addChild((yyvsp[-2].ttype));
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-3].atts);
           delete (yyvsp[0].atts);}
#line 2125 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 573 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();
               (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
               if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2136 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 580 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
               (yyval.ttype) = (yyvsp[-1].ttype);}
#line 2146 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 588 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();
                   (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
                   if(!(yyvsp[0].ttype)->getValid()) {
                     (yyval.ttype)->setValid(false);
                   }
                   (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2157 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 595 "program5.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].ttype)->getValid()) {
                     (yyval.ttype)->setValid(false);
                   }
                   (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
                   (yyval.ttype) = (yyvsp[-1].ttype);}
#line 2167 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 603 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new locvardecNode((yyvsp[-1].atts)->value);
               (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 2177 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 609 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ';' after local variable identifier: line " 
                    << (yyvsp[-1].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<LocalVarDec>");
               (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->setValid(false);
               delete (yyvsp[-1].atts);
               yyerrok;}
#line 2190 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 620 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new optexpNode("empty");}
#line 2196 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 622 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new optexpNode("exp");
            (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
            if(!(yyvsp[0].ttype)->getValid()) {
              (yyval.ttype)->setValid(false);
            }
            (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2207 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 631 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("name");
         (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
         if(!(yyvsp[0].ttype)->getValid()) {
           (yyval.ttype)->setValid(false);
         }
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2218 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 638 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("num", (yyvsp[0].atts)->value);
         (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
         delete (yyvsp[0].atts);}
#line 2226 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 642 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("null");
         (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
         delete (yyvsp[0].atts);}
#line 2234 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 646 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("name paren");
         (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
         if(!(yyvsp[-3].ttype)->getValid()) {
           (yyval.ttype)->setValid(false);
         }
         (yyval.ttype)->addChild((yyvsp[-3].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         delete (yyvsp[-2].atts);
         delete (yyvsp[0].atts);}
#line 2248 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 656 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after name declaration: line " 
              << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
         (yyval.ttype)->setValid(false);
         (yyval.ttype)->addChild((yyvsp[-3].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         delete (yyvsp[-2].atts);
         yyerrok;}
#line 2262 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 666 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("read");
         (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
         delete (yyvsp[-2].atts);
         delete (yyvsp[-1].atts);
         delete (yyvsp[0].atts);}
#line 2272 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 672 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after read: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         delete (yyvsp[-1].atts);
         yyerrok;}
#line 2284 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 680 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing '(' after read: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         delete (yyvsp[0].atts);
         yyerrok;}
#line 2296 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 688 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("newexp");
         (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
         if(!(yyvsp[0].ttype)->getValid()) {
           (yyval.ttype)->setValid(false);
         }
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2307 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 695 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("relop");
         (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2317 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 701 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("sumop");
         (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2327 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 707 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("proop");
         (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2337 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 713 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("unyop");
         (yyval.ttype)->setlnum((yyvsp[-1].ttype)->getlnum());
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2346 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 718 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("paren");
         (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         delete (yyvsp[-2].atts);
         delete (yyvsp[0].atts);}
#line 2356 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 724 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after expression: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         yyerrok;}
#line 2368 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 734 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new newexpNode("parens", (yyvsp[-3].atts)->value);
            (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            delete (yyvsp[-4].atts);
            delete (yyvsp[-3].atts);
            delete (yyvsp[-2].atts);
            delete (yyvsp[0].atts);}
#line 2380 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 742 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ')' after arglist for new expression: line " 
                 << (yyvsp[-4].atts)->lNum << endl << endl;
            (yyval.ttype) = new errorNode("<NewExpression>");
            (yyval.ttype)->setlnum((yyvsp[-4].atts)->lNum);
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            (yyval.ttype)->setValid(false);
            delete (yyvsp[-4].atts);
            delete (yyvsp[-3].atts);
            delete (yyvsp[-2].atts);
            yyerrok;}
#line 2395 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 753 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new newexpNode("bracks");
            (yyval.ttype)->setlnum((yyvsp[-3].atts)->lNum);
            if(!(yyvsp[-1].ttype)->getValid()) {
              (yyval.ttype)->setValid(false);
            }
            (yyval.ttype)->addChild((yyvsp[-2].ttype)); 
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            (yyval.ttype)->addChild((yyvsp[0].ttype));
            delete (yyvsp[-3].atts);}
#line 2409 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 765 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();}
#line 2415 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 767 "program5.y" /* yacc.c:1646  */
    {(yyvsp[-1].ttype)->addChild(new plusstarNode());
               (yyval.ttype)->setlnum((yyvsp[-1].ttype)->getlnum());
               (yyval.ttype) = (yyvsp[-1].ttype);
               delete (yyvsp[0].atts);}
#line 2424 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 774 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();}
#line 2430 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 776 "program5.y" /* yacc.c:1646  */
    {(yyvsp[-3].ttype)->addChild((yyvsp[-1].ttype));
             (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
             (yyval.ttype) = (yyvsp[-3].ttype);
             delete (yyvsp[-2].atts);
             delete (yyvsp[0].atts);}
#line 2440 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 782 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ']' after new expression: line " 
                  << (yyvsp[-2].atts)->lNum << endl << endl;
             (yyval.ttype) = new errorNode("<expstar>");
             (yyval.ttype)->setlnum((yyvsp[-2].atts)->lNum);
             (yyvsp[-3].ttype)->addChild((yyvsp[-1].ttype));
             (yyval.ttype)->setValid(false);
             (yyvsp[-3].ttype)->setValid(false);
             (yyvsp[-1].ttype)->setValid(false);
             (yyval.ttype) = (yyvsp[-3].ttype);
             delete (yyvsp[-2].atts);
             yyerrok;}
#line 2456 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 796 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new arglistNode("empty");}
#line 2462 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 798 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new arglistNode("rec");
             (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
             (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2470 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 804 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new plusstarNode();
             (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
             (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2478 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 808 "program5.y" /* yacc.c:1646  */
    {(yyvsp[-2].ttype)->addChild((yyvsp[0].ttype));
             (yyval.ttype) = (yyvsp[-2].ttype);
             delete (yyvsp[-1].atts);}
#line 2486 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 814 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("this", "");
          (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
          delete (yyvsp[0].atts);}
#line 2494 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 818 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("id", (yyvsp[0].atts)->value);
          (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
          delete (yyvsp[0].atts);}
#line 2502 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 822 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("dotid", (yyvsp[0].atts)->value);
          (yyval.ttype)->setlnum((yyvsp[-2].ttype)->getlnum());
          (yyval.ttype)->addChild((yyvsp[-2].ttype));;
          delete (yyvsp[-1].atts);
          delete (yyvsp[0].atts);}
#line 2512 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 828 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("exp", "");
          (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
          (yyval.ttype)->addChild((yyvsp[-3].ttype));
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[-2].atts);
          delete (yyvsp[0].atts);}
#line 2523 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 835 "program5.y" /* yacc.c:1646  */
    {cerr << endl << "Missing ']' after name: line " 
               << (yyvsp[-2].atts)->lNum << endl << endl;
          (yyval.ttype) = new errorNode("<Name>");
          (yyval.ttype)->setlnum((yyvsp[-3].ttype)->getlnum());
          (yyval.ttype)->setValid(false);
          (yyval.ttype)->addChild((yyvsp[-3].ttype));
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[-2].atts);
          yyerrok;}
#line 2537 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 847 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new typeNode("simpleType");
          (yyval.ttype)->setlnum((yyvsp[0].ttype)->getlnum());
          (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 2545 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 851 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new typeNode("type");
          (yyval.ttype)->setlnum((yyvsp[-1].ttype)->getlnum());
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[0].atts);}
#line 2554 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 857 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new simpleTypeNode((yyvsp[0].atts)->token, "");
                   (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
                   delete (yyvsp[0].atts);}
#line 2562 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 860 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new simpleTypeNode("id", (yyvsp[0].atts)->value);
                   (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
                   delete (yyvsp[0].atts);}
#line 2570 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 865 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("==");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2578 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 868 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("!=");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2586 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 871 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("<=");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2594 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 874 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode(">=");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2602 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 877 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode(">");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2610 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 880 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("<");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2618 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 885 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("+");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2626 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 888 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("-");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2634 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 891 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("||");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2642 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 896 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("*");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2650 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 899 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("/");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2658 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 902 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("%");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2666 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 905 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("&&");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2674 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 910 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("+");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2682 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 913 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("-");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2690 "program5.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 916 "program5.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("!");
               (yyval.ttype)->setlnum((yyvsp[0].atts)->lNum);
               delete (yyvsp[0].atts);}
#line 2698 "program5.tab.c" /* yacc.c:1646  */
    break;


#line 2702 "program5.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 921 "program5.y" /* yacc.c:1906  */

