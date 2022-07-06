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
#line 1 "miniJS.y" /* yacc.c:339  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>

using namespace std;

int count_label = 0;
int linha = 1;

int recuperarValor(int tk);
void mostrar(string valor);
void erro(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);
void setVar(string var, int linha);
void checkVar(string var);

map<string,int> var_declaradas;

  
struct Atributos {
  string valor;
};

#define YYSTYPE Atributos

#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"


#line 105 "y.tab.c" /* yacc.c:339  */

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
    _ID = 258,
    _FOR = 259,
    _IF = 260,
    _ELSE = 261,
    _INT = 262,
    _FLOAT = 263,
    _MAIG = 264,
    _MEIG = 265,
    _IG = 266,
    _DIF = 267,
    _STRING = 268,
    _STRING2 = 269,
    _COMENTARIO = 270,
    _PRINT = 271,
    _LET = 272,
    _CONST = 273,
    _VAR = 274,
    _CONC = 275,
    _MAISMAIS = 276,
    _NEWOBJECT = 277
  };
#endif
/* Tokens.  */
#define _ID 258
#define _FOR 259
#define _IF 260
#define _ELSE 261
#define _INT 262
#define _FLOAT 263
#define _MAIG 264
#define _MEIG 265
#define _IG 266
#define _DIF 267
#define _STRING 268
#define _STRING2 269
#define _COMENTARIO 270
#define _PRINT 271
#define _LET 272
#define _CONST 273
#define _VAR 274
#define _CONC 275
#define _MAISMAIS 276
#define _NEWOBJECT 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 197 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,     2,     2,     2,
      33,    34,    31,    26,    23,    25,    38,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      28,    24,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    47,    48,    54,    55,    58,    61,    64,
      65,    68,    69,    72,    73,    74,    75,    76,    77,    80,
      81,    82,    85,    86,    87,    88,    91,    92,    95,    96,
      97,   100,   101,   104,   105,   108,   109,   110,   111,   114,
     115,   116,   117,   118,   121,   122,   123,   126,   127,   128,
     131,   132,   133,   138,   139,   140,   141,   142,   143,   144,
     145,   148,   151,   154,   155,   156,   159,   160,   163,   164,
     165,   168,   169,   172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ID", "_FOR", "_IF", "_ELSE", "_INT",
  "_FLOAT", "_MAIG", "_MEIG", "_IG", "_DIF", "_STRING", "_STRING2",
  "_COMENTARIO", "_PRINT", "_LET", "_CONST", "_VAR", "_CONC", "_MAISMAIS",
  "_NEWOBJECT", "','", "'='", "'-'", "'+'", "'>'", "'<'", "'^'", "'!'",
  "'*'", "'/'", "'('", "')'", "'}'", "'['", "']'", "'.'", "'{'", "';'",
  "$accept", "Argumentos", "Atribuicao_Objeto", "Atribuicao_MIGUAL",
  "AtribuicaoObj_MIGUAL", "Atribuicao_ID2", "Atribuicao_ID",
  "Conta_Simples", "Conta_Complexa2", "Conta_Complexa", "Funcao",
  "Declaracao_Complexa", "Declaracao_Simples", "Expressao_Declaracao",
  "Declaracao", "Membro_Simples", "Objeto", "Casos_ID", "Casos_Objeto",
  "Membro", "Termo", "Conta", "Jump", "Comando", "Expressao",
  "Continuacao", "Entrada", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    44,    61,    45,    43,    62,    60,    94,
      33,    42,    47,    40,    41,   125,    91,    93,    46,   123,
      59
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     188,    55,  -103,   -10,  -103,  -103,  -103,   291,    28,    28,
      28,    17,   291,   291,   291,    16,  -103,  -103,  -103,   -14,
    -103,  -103,   -18,    -8,   270,  -103,    24,    68,    45,    44,
     307,    29,   291,    69,  -103,   246,  -103,    51,    -2,  -103,
    -103,  -103,  -103,  -103,  -103,    46,  -103,    54,    57,   291,
    -103,   291,   291,   291,   291,  -103,  -103,   291,   291,   291,
     291,   291,  -103,  -103,   120,  -103,   291,  -103,    -8,   130,
    -103,  -103,    47,    59,    48,    58,   291,    99,   291,  -103,
    -103,  -103,   291,  -103,  -103,  -103,  -103,  -103,     9,  -103,
      -8,    -8,    -8,    -8,    -8,    65,  -103,  -103,  -103,   307,
    -103,  -103,   291,   222,  -103,    43,    83,  -103,   -18,  -103,
    -103,  -103,  -103,  -103,    82,  -103,    72,   154,  -103,   270,
     107,   291,  -103,  -103,  -103,  -103,  -103,    76,  -103,    89,
      83,   270,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      60,    12,    67,     0,    40,    41,    39,     4,     0,     0,
       0,     0,    60,    60,    60,     0,    54,    68,    53,     6,
      56,    55,    21,    18,    38,    69,     0,     0,     0,     0,
      60,    60,    60,     0,    47,    60,    27,     2,    30,    35,
      36,    37,    42,    58,    57,     0,    43,     0,     0,    60,
      50,    60,    60,    60,    60,    24,    61,    60,    60,    60,
      60,    60,    62,    70,    60,     1,    60,    48,    18,    12,
      11,    10,     0,     0,    44,     0,    60,     0,    60,    34,
      28,    59,    60,    51,    52,     5,    19,    20,    21,    23,
      18,    18,    18,    18,    18,     0,    73,     7,    49,    60,
      26,    46,    60,    38,     3,    32,    30,     8,    21,    17,
      13,    14,    15,    16,    60,     9,     0,    60,    66,    38,
       0,    60,    31,    33,    22,    71,    45,     0,    63,    32,
      30,    38,    29,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,    90,  -103,  -103,  -103,    14,  -103,   -34,    26,    18,
    -103,  -102,  -100,     6,  -103,  -103,  -103,  -103,  -103,    77,
     -11,    -5,  -103,  -103,     0,   -84,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    36,    50,    67,    83,    70,    34,    62,    55,    56,
      16,    79,    80,    39,    17,    18,    19,    20,    21,    22,
      23,    24,   118,    25,    95,    96,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    43,    37,    57,   123,   122,    47,    48,    44,    45,
      49,    51,    52,    53,    54,    40,    41,    58,    59,    60,
      61,    77,    78,    35,    63,    71,    37,    73,   132,   122,
     125,    38,     1,   127,    98,    75,     4,     5,    51,    52,
      86,    87,     6,    89,    85,     7,    90,    91,    92,    93,
      94,    11,    42,    46,    12,    13,   109,   110,   111,   112,
     113,    97,    14,    -4,    64,    15,   120,   121,    65,    66,
      68,   104,    74,   106,    76,    28,    29,   107,    82,    30,
      81,   100,   -72,    84,   102,     1,     2,     3,    31,     4,
       5,    32,   103,    33,    71,     6,   101,   116,     7,     8,
       9,    10,   105,   119,    11,   114,    77,    12,    13,   126,
     129,   131,   120,   115,   108,    14,   130,   -72,    15,   128,
     -72,    72,   -38,     1,     2,     3,   124,     4,     5,     0,
      88,   133,     0,     6,     0,     0,     7,     8,     9,    10,
       0,     0,    11,     0,     0,    12,    13,     0,     0,     0,
      28,    29,     0,    14,    99,     0,    15,     1,     2,     3,
     -38,     4,     5,    31,     0,     0,    32,     6,    33,     0,
       7,     8,     9,    10,     0,     0,    11,     0,     0,    12,
      13,     0,     0,     0,     0,     0,     0,    14,     0,   -72,
      15,     1,     2,     3,   -38,     4,     5,     0,     0,     0,
       0,     6,     0,     0,     7,     8,     9,    10,     0,     0,
      11,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     1,     2,     3,   -38,     4,
       5,     0,     0,     0,     0,     6,     0,     0,     7,     8,
       9,    10,     0,     0,    11,     0,     0,    12,    13,     1,
       2,     3,     0,     4,     5,    14,     0,     0,    15,     6,
       0,   117,     7,     8,     9,    10,     0,     0,    11,     0,
       0,    12,    13,     1,     2,     3,     0,     4,     5,    14,
     -38,     0,    15,     6,     0,     0,     7,     8,     9,    10,
       0,     0,    11,     0,     1,    12,    13,     0,     4,     5,
       0,     0,     0,    14,     6,     0,    15,     7,     0,     0,
      69,     0,     0,    11,     4,     5,    12,    13,     0,     0,
       6,     0,     0,     7,    14,     0,     0,    15,     0,    11,
       0,     0,    12,    13,     0,     0,     0,     0,     0,     0,
      14,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
       0,    12,     7,    11,   106,   105,    20,    21,    13,    14,
      24,    29,    30,    31,    32,     9,    10,    25,    26,    27,
      28,    23,    24,    33,    24,    30,    31,    32,   130,   129,
     114,     3,     3,   117,    68,    35,     7,     8,    29,    30,
      51,    52,    13,    54,    49,    16,    57,    58,    59,    60,
      61,    22,    35,    37,    25,    26,    90,    91,    92,    93,
      94,    66,    33,    34,    40,    36,    23,    24,     0,    24,
      26,    76,     3,    78,    23,    20,    21,    82,    24,    24,
      34,    34,     0,    26,    36,     3,     4,     5,    33,     7,
       8,    36,    34,    38,    99,    13,    37,   102,    16,    17,
      18,    19,     3,   103,    22,    40,    23,    25,    26,    37,
       3,    35,    23,    99,    88,    33,   121,    35,    36,   119,
       0,    31,    40,     3,     4,     5,   108,     7,     8,    -1,
      53,   131,    -1,    13,    -1,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      20,    21,    -1,    33,    24,    -1,    36,     3,     4,     5,
      40,     7,     8,    33,    -1,    -1,    36,    13,    38,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      36,     3,     4,     5,    40,     7,     8,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,     3,     4,     5,    40,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    25,    26,     3,
       4,     5,    -1,     7,     8,    33,    -1,    -1,    36,    13,
      -1,    39,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    25,    26,     3,     4,     5,    -1,     7,     8,    33,
      34,    -1,    36,    13,    -1,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,     3,    25,    26,    -1,     7,     8,
      -1,    -1,    -1,    33,    13,    -1,    36,    16,    -1,    -1,
       3,    -1,    -1,    22,     7,     8,    25,    26,    -1,    -1,
      13,    -1,    -1,    16,    33,    -1,    -1,    36,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    13,    16,    17,    18,
      19,    22,    25,    26,    33,    36,    51,    55,    56,    57,
      58,    59,    60,    61,    62,    64,    65,    67,    20,    21,
      24,    33,    36,    38,    47,    33,    42,    62,     3,    54,
      54,    54,    35,    61,    62,    62,    37,    20,    21,    24,
      43,    29,    30,    31,    32,    49,    50,    11,    25,    26,
      27,    28,    48,    65,    40,     0,    24,    44,    26,     3,
      46,    62,    42,    62,     3,    65,    23,    23,    24,    52,
      53,    34,    24,    45,    26,    62,    61,    61,    60,    61,
      61,    61,    61,    61,    61,    65,    66,    62,    48,    24,
      34,    37,    36,    34,    62,     3,    62,    62,    49,    48,
      48,    48,    48,    48,    40,    46,    62,    39,    63,    65,
      23,    24,    53,    52,    50,    66,    37,    66,    65,     3,
      62,    35,    52,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    44,    45,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     0,     2,     2,     3,
       1,     2,     0,     3,     3,     3,     3,     3,     0,     2,
       2,     0,     4,     2,     1,     0,     4,     2,     1,     5,
       0,     3,     0,     4,     2,     2,     2,     2,     0,     1,
       1,     1,     2,     2,     3,     6,     4,     2,     3,     4,
       2,     3,     3,     1,     1,     1,     1,     2,     2,     3,
       0,     2,     2,     2,     4,     0,     5,     1,     1,     1,
       2,     3,     0,     3
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
#line 46 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[0]).valor;}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 48 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " [=] ^";}
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "[@]";}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 58 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " + = ^";}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " + [=] ^";}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " +(yyvsp[-2]).valor + (yyvsp[0]).valor + " " + (yyvsp[-2]).valor + "@" + " = ^ ";}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " = ^";}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "@";}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + " -" + (yyvsp[0]).valor;}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + " +" + (yyvsp[0]).valor;}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " > ";}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " < ";}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " == ";}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " ^";}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " fat #" + (yyvsp[0]).valor;}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-2]).valor + (yyvsp[-1]).valor + " *" + (yyvsp[0]).valor;}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " /";}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + " " + (yyvsp[-3]).valor + " #";}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " print #";}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 95 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-3]).valor, linha);(yyval).valor = " " + (yyvsp[-3]).valor + "& " + (yyvsp[-3]).valor + " " + (yyvsp[-1]).valor + " = ^"+ (yyvsp[0]).valor;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 100 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-1]).valor, linha);(yyval).valor = " " + (yyvsp[-1]).valor + "&" + (yyvsp[0]).valor;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-3]).valor, linha); (yyval).valor = (yyvsp[-3]).valor + "& " + (yyvsp[-3]).valor + " " + (yyvsp[-1]).valor + " = ^" + (yyvsp[0]).valor;}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 105 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-1]).valor, linha); (yyval).valor = (yyvsp[-1]).valor + "&" + (yyvsp[0]).valor;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 108 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 109 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 111 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 114 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 115 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 116 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "{}";}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 118 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "[]";}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 121 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + "@ " + (yyvsp[0]).valor;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 122 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-5]).valor + "@ " + (yyvsp[-3]).valor + "[@] " + (yyvsp[-1]).valor;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 123 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-3]).valor + "@ " + (yyvsp[-1]).valor;}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 126 "miniJS.y" /* yacc.c:1646  */
    {checkVar((yyvsp[-1]).valor);(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 127 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "@ " + (yyvsp[0]).valor;}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 128 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-3]).valor + "@" + (yyvsp[0]).valor + " " + (yyvsp[-3]).valor + " " + (yyvsp[-3]).valor + "@ 1 + = ^";}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 131 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 132 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "[@] " + (yyvsp[0]).valor;}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 133 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "@ 1 + [=] ^ " + (yyvsp[-2]).valor + "@";}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 138 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 139 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 141 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 142 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 143 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "0 " + (yyvsp[0]).valor + " -";}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 144 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor;}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 145 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 148 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 151 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 154 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = (yyvsp[0]).valor + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + (yyvsp[-1]).valor + " " +LABEL_RENDIF + to_string(count_label) + " " + (yyvsp[0]).valor;}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 155 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = (yyvsp[-2]).valor +  LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + (yyvsp[-2]).valor + " " +LABEL_RENDIF + to_string(count_label) + " " + (yyvsp[0]).valor;}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 156 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 159 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + LABEL_IF + to_string(count_label) + " ? " + (yyvsp[0]).valor;}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 163 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 164 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 165 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 168 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-2]).valor + (yyvsp[0]).valor;}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 169 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 172 "miniJS.y" /* yacc.c:1646  */
    {mostrar((yyvsp[-2]).valor + (yyvsp[0]).valor + " .");}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1834 "y.tab.c" /* yacc.c:1646  */
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
#line 174 "miniJS.y" /* yacc.c:1906  */


#include "lex.yy.c"

void setVar(string var, int linha){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
        }
        var_declaradas[var] = linha;
}

void checkVar(string var){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) return;
        }
        erro("a variável '" + var + "' não foi declarada.");
}

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

string printToken(int numToken, string tk){
        //cout << numToken << " " << tk << endl;
        return "";
}

void mostrar(string valor){
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; valor[pc] != '.' ; pc++) {
     
        if(valor[pc] == ';'){
                label = true;
                tk += valor[pc];
                continue;
        }

        if(label){
                if(valor[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        
                        //tk = printToken(pc_nolabel, tk);
                        label_in_process = "";
                }else{
                        label_in_process += valor[pc];
                        tk += valor[pc];
                }

                continue;       
        }

        if(valor[pc] == '"'){
                if(!palavra){
                        palavra = true;
                }else{
                        palavra = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                }
                continue;
        }

        if(palavra){
                tk += valor[pc];
                continue;
        }

        if(valor[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                }

                continue;
        }
        
        
        if(palavra2){
                if(valor[pc] == ' '){
                        palavra2 = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                } else{
                        tk += valor[pc];
                }
                continue;
        }
        
        if(valor[pc] == ' ') {
                tk = "";
                continue;
        }

        tk = valor[pc];
        tk = printToken(pc_nolabel, tk);
        pc_nolabel++;
   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      //cout << it->first << "=>" << it->second << endl;
      ReplaceStringInPlace(valor, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(valor, ";" + it->first + " ", ""); 
   }
        
   cout << valor;

}

void erro( string msg ) {
  cout << "Erro: " << msg << endl;
  exit(0); 
}


int recuperarValor( int tk ) {  
  yylval.valor = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}
