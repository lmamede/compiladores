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
  string retorno = "";
  string getRetorno(){
        if(" " + valor == retorno){
                return "";
        } 
        else return retorno;
  }
};

#define YYSTYPE Atributos

#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"
#define LABEL_WHILE ":while_"
#define LABEL_CORPO_WHILE ":whilec_"
#define LABEL_ENDWHILE ":end_while"
#define LABEL_FOR ":for_"
#define LABEL_CORPO_FOR ":forc_"
#define LABEL_ENDFOR ":end_for"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"
#define LABEL_RWHILE ";while_"
#define LABEL_RCORPO_WHILE ";whilec_"
#define LABEL_RENDWHILE ";end_while"
#define LABEL_RFOR ";for_"
#define LABEL_RCORPO_FOR ";forc_"
#define LABEL_RENDFOR ";end_for"


#line 124 "y.tab.c" /* yacc.c:339  */

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
    _NEWOBJECT = 277,
    _WHILE = 278
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
#define _WHILE 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 218 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,     2,     2,
      34,    35,    32,    27,    24,    26,    39,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      29,    25,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    67,    73,    74,    77,    78,    81,
      84,    87,    88,    91,    92,    95,    96,    97,    98,    99,
     100,   103,   104,   105,   108,   109,   110,   111,   114,   115,
     118,   119,   120,   123,   124,   127,   128,   131,   132,   133,
     134,   137,   138,   139,   140,   141,   144,   145,   148,   149,
     150,   153,   154,   155,   158,   159,   160,   165,   166,   167,
     168,   169,   170,   171,   172,   175,   178,   181,   182,   189,
     190,   193,   194,   195,   200,   201,   204,   205,   206,   209,
     210,   213,   214,   215,   216,   219,   220
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
  "_NEWOBJECT", "_WHILE", "','", "'='", "'-'", "'+'", "'>'", "'<'", "'^'",
  "'!'", "'*'", "'/'", "'('", "')'", "'}'", "'['", "']'", "'.'", "';'",
  "'{'", "$accept", "Argumentos", "Atribuicao_Objeto2",
  "Atribuicao_Objeto", "Atribuicao_MIGUAL", "AtribuicaoObj_MIGUAL",
  "Atribuicao_ID2", "Atribuicao_ID", "Conta_Simples", "Conta_Complexa2",
  "Conta_Complexa", "Funcao", "Declaracao_Complexa", "Declaracao_Simples",
  "Expressao_Declaracao", "Declaracao", "Membro_Simples", "Dimensoes",
  "Objeto", "Casos_ID", "Casos_Objeto", "Membro", "Termo", "Conta",
  "Jump_IF", "Jump_While", "Jump_For", "SENAO", "Comando", "Expressao",
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
     275,   276,   277,   278,    44,    61,    45,    43,    62,    60,
      94,    33,    42,    47,    40,    41,   125,    91,    93,    46,
      59,   123
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     317,    30,   -28,   -19,  -117,  -117,  -117,   409,    21,    21,
      21,     8,    12,   409,   409,   409,    11,  -117,  -117,  -117,
      -7,  -117,  -117,    10,   129,   342,   193,    26,    52,    40,
      43,   425,   384,   409,    68,  -117,   367,    77,  -117,    49,
      -2,  -117,  -117,  -117,  -117,    77,  -117,  -117,    39,  -117,
      50,    51,   409,  -117,   409,   409,   409,   409,  -117,  -117,
     409,   409,   409,   409,   409,  -117,  -117,   168,   168,    37,
    -117,   193,  -117,   409,  -117,   129,   228,  -117,  -117,    47,
      53,    55,    48,    54,   409,    84,   409,  -117,  -117,    62,
    -117,   409,  -117,  -117,  -117,    -4,  -117,  -117,  -117,   -11,
    -117,   129,   129,   129,   129,   129,  -117,  -117,   168,  -117,
    -117,  -117,   425,  -117,    61,   409,   367,   218,  -117,    33,
      78,   253,  -117,   409,    10,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,   409,  -117,    63,    65,   292,  -117,    66,   106,
     409,  -117,  -117,   292,  -117,    73,  -117,  -117,    81,  -117,
      77,    79,   114,    98,    78,    87,  -117,    61,    89,   114,
     168,  -117,  -117,  -117,  -117,   126,  -117,  -117,   292,  -117,
      85,    92,  -117,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      64,    14,     0,     0,    42,    43,    41,     4,     0,     0,
       0,     0,     0,    64,    64,    64,     0,    58,    79,    57,
       8,    60,    59,    23,    20,    64,    64,     0,     0,     0,
       0,    64,    64,    64,     0,    51,    64,    64,    29,     2,
      32,    37,    38,    39,    44,    64,    62,    61,     0,    45,
       0,     0,    64,    54,    64,    64,    64,    64,    26,    65,
      64,    64,    64,    64,    64,    66,    80,    64,    64,     0,
      86,    64,     1,    64,    52,    20,    14,    13,    12,     0,
       0,    48,     0,     0,    64,     0,    64,    36,    30,     0,
      63,    64,    55,    56,     7,     8,     6,    21,    22,    23,
      25,    20,    20,    20,    20,    20,    83,    82,    64,    85,
       9,    53,    64,    28,    47,    64,    64,    64,     3,    34,
      32,    64,    10,    64,    23,    19,    15,    16,    17,    18,
      81,    11,    64,    50,     0,     0,    64,    76,     0,     0,
      64,    33,    35,    64,    78,     0,     5,    24,     0,    49,
      64,     0,    75,    34,    32,     0,    69,    47,     0,    75,
      64,    67,    31,    70,    46,    64,    68,    74,    64,    77,
       0,     0,    71,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,   100,    13,  -117,  -117,  -117,    29,  -117,   -72,    38,
      14,  -117,  -116,  -114,    25,  -117,  -117,   -10,   -51,  -117,
    -117,    90,    -1,    -5,  -117,  -117,  -117,    -8,   154,     0,
     -60,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    94,    53,    74,    92,    77,    35,    65,    58,
      59,    17,    87,    88,    41,    18,    19,   133,    20,    21,
      22,    23,    24,    25,   137,   144,   169,   161,    68,    69,
      70,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    95,    39,   111,   142,   141,    36,   106,   107,    47,
      48,   109,    46,    50,    51,    37,    50,    51,    52,    54,
      55,   123,    85,    86,    40,    66,    78,    39,    80,   125,
     126,   127,   128,   129,    42,    43,    82,    83,   162,   141,
      54,    55,    56,    57,    44,    89,    45,    96,   130,    49,
      29,    30,    72,    97,    98,    31,   100,   139,   140,   101,
     102,   103,   104,   105,    32,    73,    71,    33,   110,    34,
      75,    81,    95,    84,    90,    91,   151,   108,    93,   118,
       1,   120,   113,   155,     4,     5,   122,   119,   116,   117,
       6,   114,   115,     7,     8,     9,    10,   121,   132,    11,
     167,   149,    85,    13,    14,   150,   152,    78,   171,   153,
     134,    15,   -40,   156,    16,   159,   135,   138,    96,   157,
     160,   145,   139,   163,   165,   172,   -73,   148,   173,     1,
     -73,   -73,    79,     4,     5,   154,   146,   124,   147,     6,
      60,   131,     7,     8,     9,    10,    99,   164,    11,   -73,
     158,   166,    13,    14,    26,    61,    62,    63,    64,     0,
      15,     0,   -73,    16,     0,   170,   -40,   168,   -84,     0,
       0,     1,     2,     3,     0,     4,     5,     0,     0,     0,
       0,     6,     0,     0,     7,     8,     9,    10,     0,     0,
      11,    12,     0,   -84,    13,    14,     1,     2,     3,     0,
       4,     5,    15,     0,   -84,    16,     6,     0,    67,     7,
       8,     9,    10,     0,     0,    11,    12,     0,     0,    13,
      14,     1,     0,     0,     0,     4,     5,    15,     0,     0,
      16,     6,     0,    67,     7,     8,     9,    10,     0,     0,
      11,     0,     0,     0,    13,    14,     0,     0,    29,    30,
       0,     0,    15,   112,     0,    16,     1,     0,   -40,   136,
       4,     5,    32,     0,     0,    33,     6,    34,     0,     7,
       8,     9,    10,     0,     0,    11,     0,     0,     0,    13,
      14,     0,     0,     0,     0,     0,     0,    15,     0,     0,
      16,     0,     0,   -40,   143,     1,     2,     3,     0,     4,
       5,     0,     0,     0,     0,     6,     0,     0,     7,     8,
       9,    10,     0,     0,    11,    12,     0,     0,    13,    14,
       1,     2,     3,     0,     4,     5,    15,     0,   -84,    16,
       6,     0,    67,     7,     8,     9,    10,     0,     0,    11,
      12,     0,     0,    13,    14,     1,     0,     0,     0,     4,
       5,    15,     0,     0,    16,     6,     0,   -40,     7,     8,
       9,    10,     0,     0,    11,     0,     0,     0,    13,    14,
       1,     0,     0,     0,     4,     5,    15,   -40,     0,    16,
       6,     0,   -40,     7,     8,     9,    10,     1,     0,    11,
       0,     4,     5,    13,    14,     0,     0,     6,     0,     0,
       7,    15,     0,     0,    16,     0,    11,   -40,     0,     0,
      13,    14,     1,     0,     0,     0,     4,     5,    15,    -4,
       0,    16,     6,     0,     0,     7,     0,     0,    76,     0,
       0,    11,     4,     5,     0,    13,    14,     0,     6,     0,
       0,     7,     0,    15,     0,     0,    16,    11,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16
};

static const yytype_int16 yycheck[] =
{
       0,    52,     7,    75,   120,   119,    34,    67,    68,    14,
      15,    71,    13,    20,    21,    34,    20,    21,    25,    30,
      31,    25,    24,    25,     3,    25,    31,    32,    33,   101,
     102,   103,   104,   105,     9,    10,    36,    37,   154,   153,
      30,    31,    32,    33,    36,    45,    34,    52,   108,    38,
      20,    21,     0,    54,    55,    25,    57,    24,    25,    60,
      61,    62,    63,    64,    34,    25,    40,    37,    73,    39,
      27,     3,   123,    24,    35,    25,   136,    40,    27,    84,
       3,    86,    35,   143,     7,     8,    91,     3,    40,    35,
      13,    38,    37,    16,    17,    18,    19,    35,    37,    22,
     160,    38,    24,    26,    27,    40,    40,   112,   168,     3,
     115,    34,    35,    40,    37,    36,   116,   117,   123,    38,
       6,   121,    24,    36,    35,    40,     0,   132,    36,     3,
       4,     5,    32,     7,     8,   140,   123,    99,   124,    13,
      11,   112,    16,    17,    18,    19,    56,   157,    22,    23,
     150,   159,    26,    27,     0,    26,    27,    28,    29,    -1,
      34,    -1,    36,    37,    -1,   165,    40,    41,     0,    -1,
      -1,     3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    23,    -1,     0,    26,    27,     3,     4,     5,    -1,
       7,     8,    34,    -1,    36,    37,    13,    -1,    40,    16,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,
      27,     3,    -1,    -1,    -1,     7,     8,    34,    -1,    -1,
      37,    13,    -1,    40,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    20,    21,
      -1,    -1,    34,    25,    -1,    37,     3,    -1,    40,    41,
       7,     8,    34,    -1,    -1,    37,    13,    39,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
       3,     4,     5,    -1,     7,     8,    34,    -1,    36,    37,
      13,    -1,    40,    16,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,     3,    -1,    -1,    -1,     7,
       8,    34,    -1,    -1,    37,    13,    -1,    40,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
       3,    -1,    -1,    -1,     7,     8,    34,    35,    -1,    37,
      13,    -1,    40,    16,    17,    18,    19,     3,    -1,    22,
      -1,     7,     8,    26,    27,    -1,    -1,    13,    -1,    -1,
      16,    34,    -1,    -1,    37,    -1,    22,    40,    -1,    -1,
      26,    27,     3,    -1,    -1,    -1,     7,     8,    34,    35,
      -1,    37,    13,    -1,    -1,    16,    -1,    -1,     3,    -1,
      -1,    22,     7,     8,    -1,    26,    27,    -1,    13,    -1,
      -1,    16,    -1,    34,    -1,    -1,    37,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    13,    16,    17,    18,
      19,    22,    23,    26,    27,    34,    37,    53,    57,    58,
      60,    61,    62,    63,    64,    65,    70,    71,    73,    20,
      21,    25,    34,    37,    39,    49,    34,    34,    43,    65,
       3,    56,    56,    56,    36,    34,    64,    65,    65,    38,
      20,    21,    25,    45,    30,    31,    32,    33,    51,    52,
      11,    26,    27,    28,    29,    50,    71,    40,    70,    71,
      72,    40,     0,    25,    46,    27,     3,    48,    65,    43,
      65,     3,    71,    71,    24,    24,    25,    54,    55,    71,
      35,    25,    47,    27,    44,    60,    65,    64,    64,    63,
      64,    64,    64,    64,    64,    64,    72,    72,    40,    72,
      65,    50,    25,    35,    38,    37,    40,    35,    65,     3,
      65,    35,    65,    25,    51,    50,    50,    50,    50,    50,
      72,    48,    37,    59,    65,    71,    41,    66,    71,    24,
      25,    55,    54,    41,    67,    71,    44,    52,    65,    38,
      40,    72,    40,     3,    65,    72,    40,    38,    71,    36,
       6,    69,    54,    36,    59,    35,    69,    72,    41,    68,
      71,    72,    40,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    45,    46,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     3,     1,     2,     0,     2,
       2,     3,     1,     2,     0,     3,     3,     3,     3,     3,
       0,     2,     2,     0,     4,     2,     1,     0,     4,     2,
       1,     5,     0,     3,     0,     4,     2,     2,     2,     2,
       0,     1,     1,     1,     2,     2,     4,     0,     3,     6,
       5,     2,     3,     4,     2,     3,     3,     1,     1,     1,
       1,     2,     2,     3,     0,     2,     2,     3,     4,     2,
       3,     2,     3,     0,     2,     0,     5,     9,     5,     1,
       2,     3,     2,     2,     0,     3,     2
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
#line 65 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[0]).valor;}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 73 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " +(yyvsp[-2]).valor + (yyvsp[0]).valor + " " + (yyvsp[-2]).valor + "[@]" + " [=] ^";}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " [=] ^";}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "[@]";}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " + = ^";}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " + [=] ^";}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " +(yyvsp[-2]).valor + (yyvsp[0]).valor + " " + (yyvsp[-2]).valor + "@" + " = ^";}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 88 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " = ^";}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 92 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "@";}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 95 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + " -" + (yyvsp[0]).valor;}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + " +" + (yyvsp[0]).valor;}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " >";}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " <";}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor + " ==";}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 100 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " ^";}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " fat #" + (yyvsp[0]).valor;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 105 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-2]).valor + (yyvsp[-1]).valor + " *" + (yyvsp[0]).valor;}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 109 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[0]).valor + " /";}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 111 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 114 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + " " + (yyvsp[-3]).valor + " #";}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 115 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor + " print #";}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 118 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 119 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-3]).valor, linha);(yyval).valor = " " + (yyvsp[-3]).valor + "& " + (yyvsp[-3]).valor + " " + (yyvsp[-1]).valor + " = ^"+ (yyvsp[0]).valor;}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 120 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-1]).valor, linha);(yyval).valor = " " + (yyvsp[-1]).valor + "&" + (yyvsp[0]).valor;}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 127 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-3]).valor, linha); (yyval).valor = (yyvsp[-3]).valor + "& " + (yyvsp[-3]).valor + " " + (yyvsp[-1]).valor + " = ^" + (yyvsp[0]).valor;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 128 "miniJS.y" /* yacc.c:1646  */
    {setVar((yyvsp[-1]).valor, linha); (yyval).valor = (yyvsp[-1]).valor + "&" + (yyvsp[0]).valor;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 131 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 132 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 133 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 134 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 137 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 138 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 140 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "{}";}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 141 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "[]";}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor ="[@] " + (yyvsp[-2]).valor + (yyvsp[-2]).getRetorno() + (yyvsp[0]).valor;}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 148 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + "@ " + (yyvsp[0]).valor;}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-5]).valor + "@ " + (yyvsp[-3]).valor + "[@] " + (yyvsp[-1]).valor;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 150 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-4]).valor + "@ " + (yyvsp[-2]).valor + (yyvsp[-2]).getRetorno() + (yyvsp[0]).valor;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "miniJS.y" /* yacc.c:1646  */
    {checkVar((yyvsp[-1]).valor);(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor; (yyval).retorno = " " + (yyvsp[-1]).valor + "@";}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "@ " + (yyvsp[0]).valor;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 155 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-3]).valor + "@" + (yyvsp[0]).valor + " " + (yyvsp[-3]).valor + " " + (yyvsp[-3]).valor + "@ 1 + = ^";}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 158 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 159 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "[@] " + (yyvsp[0]).valor;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 160 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + (yyvsp[-2]).valor + "@ 1 + [=] ^ " + (yyvsp[-2]).valor + "@";}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 165 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 166 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 167 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 168 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;(yyval).retorno=(yyvsp[0]).retorno;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 169 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 170 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "0 " + (yyvsp[0]).valor + " -";}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 171 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor;}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 172 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 175 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;(yyval).retorno=(yyvsp[-1]).retorno;}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 178 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;(yyval).retorno=(yyvsp[-1]).retorno;}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = (yyvsp[0]).valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + (yyvsp[-2]).valor + " " + LABEL_RENDIF + to_string(count_label);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = (yyvsp[0]).valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + (yyvsp[-2]).valor + " "+ LABEL_RENDIF + to_string(count_label);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 189 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + " " + (yyvsp[-1]).valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 190 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + (yyvsp[-1]).valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 193 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + " " + (yyvsp[-1]).valor;}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 194 "miniJS.y" /* yacc.c:1646  */
    {count_label++; (yyval).valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + (yyvsp[-1]).valor;}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 200 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 201 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 204 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-2]).valor + " " + LABEL_IF + to_string(count_label) + " ?" + (yyvsp[0]).valor;}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 205 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-6]).valor + " " + LABEL_RFOR + to_string(count_label) + " " + (yyvsp[-4]).valor + " " + LABEL_CORPO_FOR + to_string(count_label) + " ? " + (yyvsp[0]).valor + " " + (yyvsp[-2]).valor + " " + LABEL_FOR + to_string(count_label) + " # " + LABEL_RENDFOR + to_string(count_label);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 206 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = LABEL_RWHILE + to_string(count_label) + " " + (yyvsp[-2]).valor + " " + LABEL_CORPO_WHILE + to_string(count_label) + " ? " + (yyvsp[0]).valor;}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 209 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 210 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 213 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-2]).valor + (yyvsp[0]).valor;}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 214 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = " " + (yyvsp[-1]).valor + (yyvsp[0]).valor;}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 215 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = (yyvsp[0]).valor;}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 216 "miniJS.y" /* yacc.c:1646  */
    {(yyval).valor = "";}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 219 "miniJS.y" /* yacc.c:1646  */
    {mostrar((yyvsp[-2]).valor + (yyvsp[0]).valor + " .");}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 220 "miniJS.y" /* yacc.c:1646  */
    {mostrar((yyvsp[-1]).valor + (yyvsp[0]).valor + " .");}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1975 "y.tab.c" /* yacc.c:1646  */
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
#line 222 "miniJS.y" /* yacc.c:1906  */


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
   bool palavra3 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; pc != valor.size() ; pc++) {
     
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
                }
                continue;
        }

        if(palavra){
                tk += valor[pc];
                continue;
        }

        if(valor[pc] == '\''){
                if(!palavra3 && !palavra){
                        palavra3 = true;
                }else{
                        if(!palavra){
                                palavra3 = false;
                        }
                }
                continue;
        }

        

        if(valor[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                        tk += valor[pc];
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
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
        }else{
                if(valor[pc] == '&' || valor[pc] == '@') {
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                        tk = valor[pc];
                        continue;
                }
        }

        tk += valor[pc];
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
  exit(0); //apenas para execucao local
  //exit(1); 
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
