/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "interval.y" /* yacc.c:339  */

  extern char *yytext;
  int yylex (void);
  #define YYSTYPE int
  #include "main.h"


#line 74 "interval.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "interval.tab.h".  */
#ifndef YY_YY_INTERVAL_TAB_H_INCLUDED
# define YY_YY_INTERVAL_TAB_H_INCLUDED
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
    OKRSKOB = 258,
    ZKRSKOB = 259,
    OKVSKOB = 260,
    ZKVSKOB = 261,
    LESS = 262,
    GREATER = 263,
    LESSEQUAL = 264,
    GREATEREQUAL = 265,
    PLUSINF = 266,
    MINUSINF = 267,
    UNIF = 268,
    EXP = 269,
    LN = 270,
    SIN = 271,
    COS = 272,
    TAN = 273,
    COTAN = 274,
    TOZA = 275,
    IKS = 276,
    ARCSIN = 277,
    ARCCOS = 278,
    ARCTAN = 279,
    NUM = 280,
    MINUS = 281,
    PLUS = 282,
    MULTIPLY = 283,
    DIVIDE = 284,
    NEG = 285,
    POWER = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERVAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 157 "interval.tab.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    25,    25,    26,    27,    28,    29,    30,    32,    33,
      34,    36,    73,   110,   148,   177,   178,   179,   180,   182,
     183,   185,   186,   188,   189,   191,   192,   193,   195,   201,
     210,   219,   228,   237,   246,   253,   254,   261,   268,   275,
     282,   289,   296,   303,   310
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OKRSKOB", "ZKRSKOB", "OKVSKOB",
  "ZKVSKOB", "LESS", "GREATER", "LESSEQUAL", "GREATEREQUAL", "PLUSINF",
  "MINUSINF", "UNIF", "EXP", "LN", "SIN", "COS", "TAN", "COTAN", "TOZA",
  "IKS", "ARCSIN", "ARCCOS", "ARCTAN", "NUM", "MINUS", "PLUS", "MULTIPLY",
  "DIVIDE", "NEG", "POWER", "$accept", "intervalloop", "unifiedinterval",
  "largeinterval", "mediuminterval", "smallinterval", "otnos", "kvskob",
  "geq", "leq", "bexp", "exp", YY_NULL
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
     285,   286
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,   150,   -45,   -45,   -45,   -45,     5,    12,    20,    50,
      62,    63,     3,    64,    67,    70,   -45,   184,    36,   -45,
     -10,   -45,   -45,   167,    11,   -22,   184,    76,    77,    18,
     184,   184,   184,   184,   184,   184,   -45,   -45,   -45,   -45,
     184,   184,   184,   184,    37,   -45,   133,    69,   -45,   -45,
     -45,   -45,    61,    78,   184,   184,   184,   184,   184,    18,
      84,    85,   -45,    33,    48,    59,    65,    74,    80,   -22,
      91,   100,   106,   -45,   167,     6,    41,    -4,    -4,    37,
      37,    37,   133,   133,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,    23,   167,   167,   -45,   -45,   -45,   -45,
     -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    19,    20,    27,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     7,
       4,     3,     2,     0,     0,    25,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     0,    34,     1,     0,     0,    23,    21,
      24,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     5,    35,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    10,     0,     0,     0,    30,    29,    31,
      32,    33,     0,     0,    36,    37,    38,    39,    40,    44,
      41,    42,    43,     0,     0,     0,     9,     8,    11,    13,
      12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -44,   -45,   -45,    82,   111,   -45,    21,    38,    39,
     -23,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    22,    40,    23,    52,    53,
      24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    29,    73,    46,    54,    55,    56,    57,    30,    58,
      36,    37,    38,    39,    49,    31,    51,    44,    48,    49,
      50,    51,    62,    32,    56,    57,    59,    58,     2,     3,
      63,    64,    65,    66,    67,    68,    45,    84,    96,    97,
      69,    70,    71,    72,    54,    55,    56,    57,    48,    58,
      50,    93,    85,    33,    77,    78,    79,    80,    81,    54,
      55,    56,    57,    86,    58,    34,    35,    41,    58,    87,
      42,    99,   100,    43,    54,    55,    56,    57,    88,    58,
      60,    61,    75,    27,    89,    54,    55,    56,    57,    74,
      58,    54,    55,    56,    57,    90,    58,    82,    83,    76,
      54,    55,    56,    57,    91,    58,    54,    55,    56,    57,
      92,    58,    28,    94,    98,    95,     0,    54,    55,    56,
      57,     0,    58,     0,     0,     0,    54,    55,    56,    57,
       0,    58,    54,    55,    56,    57,     1,    58,     2,     3,
       0,     0,     0,     0,     4,     5,     0,     6,     7,     8,
       9,    10,    11,    26,    12,    13,    14,    15,    16,    17,
       0,     4,     5,     0,     6,     7,     8,     9,    10,    11,
      26,    12,    13,    14,    15,    16,    17,     0,     4,     5,
       0,     6,     7,     8,     9,    10,    11,    26,     0,    13,
      14,    15,    16,    17,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     0,    13,    14,    15,    16,
      17
};

static const yytype_int8 yycheck[] =
{
      23,     1,    46,    13,    26,    27,    28,    29,     3,    31,
       7,     8,     9,    10,     8,     3,    10,    17,     7,     8,
       9,    10,     4,     3,    28,    29,    26,    31,     5,     6,
      30,    31,    32,    33,    34,    35,     0,     4,    82,    83,
      40,    41,    42,    43,    26,    27,    28,    29,     7,    31,
       9,    74,     4,     3,    54,    55,    56,    57,    58,    26,
      27,    28,    29,     4,    31,     3,     3,     3,    31,     4,
       3,    94,    95,     3,    26,    27,    28,    29,     4,    31,
       4,     4,    21,     1,     4,    26,    27,    28,    29,    20,
      31,    26,    27,    28,    29,     4,    31,    13,    13,    21,
      26,    27,    28,    29,     4,    31,    26,    27,    28,    29,
       4,    31,     1,    75,    93,    76,    -1,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    31,    26,    27,    28,    29,     3,    31,     5,     6,
      -1,    -1,    -1,    -1,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,     3,    21,    22,    23,    24,    25,    26,
      -1,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
       3,    21,    22,    23,    24,    25,    26,    -1,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,     3,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,    11,    12,    14,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    26,    33,    34,
      35,    36,    37,    39,    42,    43,     3,    36,    37,    43,
       3,     3,     3,     3,     3,     3,     7,     8,     9,    10,
      38,     3,     3,     3,    43,     0,    13,    42,     7,     8,
       9,    10,    40,    41,    26,    27,    28,    29,    31,    43,
       4,     4,     4,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    33,    20,    21,    21,    43,    43,    43,
      43,    43,    13,    13,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    42,    40,    41,    33,    33,    39,    42,
      42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    33,    33,    33,    33,    34,    34,
      34,    35,    36,    36,    37,    38,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    42,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     5,     5,
       3,     5,     5,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
        case 11:
#line 36 "interval.y" /* yacc.c:1646  */
    {
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);
				
				if ((yyvsp[-4]) == ZKVSKOB) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ((yyvsp[0]) == OKVSKOB) {temp1.openright = true;} else {temp1.openright = false;};
				
				if ((yyvsp[-1]) == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ((yyvsp[-1]) == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(10);};
				if (((yyvsp[-1]) != MINUSINF) && ((yyvsp[-1]) != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ((yyvsp[-3]) == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ((yyvsp[-3]) == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(20);};
				if (((yyvsp[-3]) != MINUSINF) && ((yyvsp[-4]) != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;
				
				if (((yyvsp[-3]) == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (((yyvsp[-1]) == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				}
#line 1335 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "interval.y" /* yacc.c:1646  */
    {
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ((yyvsp[-3]) == LESS) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ((yyvsp[-1]) == LESS) {temp1.openright = true;} else {temp1.openright = false;};

				if ((yyvsp[0]) == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ((yyvsp[0]) == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(10);};
				if (((yyvsp[0]) != MINUSINF) && ((yyvsp[0]) != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ((yyvsp[-4]) == MINUSINF) {mpz_set(&temp1.left, &ocon1e100);};
				if ((yyvsp[-4]) == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(20);};
				if (((yyvsp[-4]) != MINUSINF) && ((yyvsp[-4]) != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;
				
				if (((yyvsp[-4]) == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (((yyvsp[0]) == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				
				}
#line 1377 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "interval.y" /* yacc.c:1646  */
    {
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ((yyvsp[-3]) == GREATER) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ((yyvsp[-1]) == GREATER) {temp1.openright = true;} else {temp1.openright = false;};

				if ((yyvsp[0]) == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ((yyvsp[0]) == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(10);};
				if (((yyvsp[0]) != MINUSINF) && ((yyvsp[0]) != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.left, &temp, 0); };

				if ((yyvsp[-4]) == PLUSINF) {mpz_set(&temp1.right, &pcon1e100);};
				if ((yyvsp[-4]) == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(20);};
				if (((yyvsp[-4]) != MINUSINF) && ((yyvsp[-4]) != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.right, &temp, 0);
						     };


				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be smaller than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;
				
				if (((yyvsp[0]) == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (((yyvsp[-4]) == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				}
#line 1419 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "interval.y" /* yacc.c:1646  */
    {
			    mpz_init (&temp1.left);
			    mpz_init (&temp1.right);
			
			    if (((yyvsp[-1]) == GREATER) || ((yyvsp[-1]) == GREATEREQUAL)) {
			     temp = g_array_index (stack, __mpfr_struct, --stacksize);
			     stack = g_array_remove_index (stack, stacksize);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.left, &temp, 0);
			     temp1.openright = true;
			     mpz_set(&temp1.right, &pcon1e100);
			     if ((yyvsp[-1]) == GREATER) {temp1.openleft = true;} else {temp1.openleft = false;};
			    }
			    else
			    {
			     temp = g_array_index (stack, __mpfr_struct, --stacksize);
			     stack = g_array_remove_index (stack, stacksize);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.right, &temp, 0);
			     temp1.openleft = true;
			     mpz_set(&temp1.left, &ocon1e100);
			     if ((yyvsp[-1]) == LESS) {temp1.openright = true;} else {temp1.openright = false;};
			    }

			    g_array_append_val (intervals, temp1);
			    intervalsize++;
			    }
#line 1451 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "interval.y" /* yacc.c:1646  */
    {(yyval) = LESS;}
#line 1457 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 178 "interval.y" /* yacc.c:1646  */
    {(yyval) = GREATER;}
#line 1463 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "interval.y" /* yacc.c:1646  */
    {(yyval) = LESSEQUAL;}
#line 1469 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 180 "interval.y" /* yacc.c:1646  */
    {(yyval) = GREATEREQUAL;}
#line 1475 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 182 "interval.y" /* yacc.c:1646  */
    {(yyval) = OKVSKOB;}
#line 1481 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 183 "interval.y" /* yacc.c:1646  */
    {(yyval) = ZKVSKOB;}
#line 1487 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 185 "interval.y" /* yacc.c:1646  */
    {(yyval) = GREATER;}
#line 1493 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "interval.y" /* yacc.c:1646  */
    {(yyval) = GREATEREQUAL;}
#line 1499 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "interval.y" /* yacc.c:1646  */
    {(yyval) = LESS;}
#line 1505 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "interval.y" /* yacc.c:1646  */
    {(yyval) = LESSEQUAL;}
#line 1511 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 191 "interval.y" /* yacc.c:1646  */
    {(yyval) = NUM;}
#line 1517 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "interval.y" /* yacc.c:1646  */
    {(yyval) = MINUSINF;}
#line 1523 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 193 "interval.y" /* yacc.c:1646  */
    {(yyval) = PLUSINF;}
#line 1529 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 195 "interval.y" /* yacc.c:1646  */
    {
			    mpfr_init (&temp);
			    mpfr_set_str (&temp, yytext, 10, 0);
			    g_array_append_val (stack, temp);
			    stacksize++;
			    }
#line 1540 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 201 "interval.y" /* yacc.c:1646  */
    { 
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_add (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1554 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 210 "interval.y" /* yacc.c:1646  */
    {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_sub (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1568 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "interval.y" /* yacc.c:1646  */
    {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_mul (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1582 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "interval.y" /* yacc.c:1646  */
    {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_div (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1596 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 237 "interval.y" /* yacc.c:1646  */
    {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_pow (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1610 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 246 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_neg (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1622 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 254 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_exp (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1634 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 261 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_log (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1646 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 268 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_sin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1658 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 275 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_cos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1670 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 282 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_tan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1682 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 289 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_asin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1694 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_acos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1706 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 303 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_atan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1718 "interval.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 310 "interval.y" /* yacc.c:1646  */
    { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_cot (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
#line 1730 "interval.tab.c" /* yacc.c:1646  */
    break;


#line 1734 "interval.tab.c" /* yacc.c:1646  */
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
#line 319 "interval.y" /* yacc.c:1906  */


int yyerror (char const *s) {
   fprintf (stderr, "%s near symbol %s\n", s, yytext);
   exit (2);
 }
