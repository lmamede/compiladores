/* A Bison parser, made by GNU Bison 3.7.3.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniJS.y"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int count_label = 0;
int linha = 1;
int coluna = 1;

int recuperarValor(int tk);
void mostrar(string valor);
void erro(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);
void setVar(string var, int linha);
void checkVar(string var);
string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);

map<string,int> var_declaradas;

string retorno_default = "undefined @ '&retorno' @ ~";

string funcoes = "";
map<string, string> retornos;

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


#line 137 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _ID = 258,                     /* _ID  */
    _FOR = 259,                    /* _FOR  */
    _IF = 260,                     /* _IF  */
    _ELSE = 261,                   /* _ELSE  */
    _INT = 262,                    /* _INT  */
    _FLOAT = 263,                  /* _FLOAT  */
    _MAIG = 264,                   /* _MAIG  */
    _MEIG = 265,                   /* _MEIG  */
    _IG = 266,                     /* _IG  */
    _DIF = 267,                    /* _DIF  */
    _STRING = 268,                 /* _STRING  */
    _STRING2 = 269,                /* _STRING2  */
    _COMENTARIO = 270,             /* _COMENTARIO  */
    _PRINT = 271,                  /* _PRINT  */
    _LET = 272,                    /* _LET  */
    _CONST = 273,                  /* _CONST  */
    _VAR = 274,                    /* _VAR  */
    _CONC = 275,                   /* _CONC  */
    _MAISMAIS = 276,               /* _MAISMAIS  */
    _NEWOBJECT = 277,              /* _NEWOBJECT  */
    _WHILE = 278,                  /* _WHILE  */
    _FUNCTION = 279,               /* _FUNCTION  */
    _TRUE = 280,                   /* _TRUE  */
    _FALSE = 281,                  /* _FALSE  */
    _RETURN = 282                  /* _RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define _FUNCTION 279
#define _TRUE 280
#define _FALSE 281
#define _RETURN 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__ID = 3,                        /* _ID  */
  YYSYMBOL__FOR = 4,                       /* _FOR  */
  YYSYMBOL__IF = 5,                        /* _IF  */
  YYSYMBOL__ELSE = 6,                      /* _ELSE  */
  YYSYMBOL__INT = 7,                       /* _INT  */
  YYSYMBOL__FLOAT = 8,                     /* _FLOAT  */
  YYSYMBOL__MAIG = 9,                      /* _MAIG  */
  YYSYMBOL__MEIG = 10,                     /* _MEIG  */
  YYSYMBOL__IG = 11,                       /* _IG  */
  YYSYMBOL__DIF = 12,                      /* _DIF  */
  YYSYMBOL__STRING = 13,                   /* _STRING  */
  YYSYMBOL__STRING2 = 14,                  /* _STRING2  */
  YYSYMBOL__COMENTARIO = 15,               /* _COMENTARIO  */
  YYSYMBOL__PRINT = 16,                    /* _PRINT  */
  YYSYMBOL__LET = 17,                      /* _LET  */
  YYSYMBOL__CONST = 18,                    /* _CONST  */
  YYSYMBOL__VAR = 19,                      /* _VAR  */
  YYSYMBOL__CONC = 20,                     /* _CONC  */
  YYSYMBOL__MAISMAIS = 21,                 /* _MAISMAIS  */
  YYSYMBOL__NEWOBJECT = 22,                /* _NEWOBJECT  */
  YYSYMBOL__WHILE = 23,                    /* _WHILE  */
  YYSYMBOL__FUNCTION = 24,                 /* _FUNCTION  */
  YYSYMBOL__TRUE = 25,                     /* _TRUE  */
  YYSYMBOL__FALSE = 26,                    /* _FALSE  */
  YYSYMBOL__RETURN = 27,                   /* _RETURN  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '^'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '%'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_Argumentos = 48,                /* Argumentos  */
  YYSYMBOL_Atribuicao_Objeto2 = 49,        /* Atribuicao_Objeto2  */
  YYSYMBOL_Atribuicao_Objeto = 50,         /* Atribuicao_Objeto  */
  YYSYMBOL_Atribuicao_MIGUAL = 51,         /* Atribuicao_MIGUAL  */
  YYSYMBOL_AtribuicaoObj_MIGUAL = 52,      /* AtribuicaoObj_MIGUAL  */
  YYSYMBOL_Atribuicao_ID2 = 53,            /* Atribuicao_ID2  */
  YYSYMBOL_Atribuicao_ID = 54,             /* Atribuicao_ID  */
  YYSYMBOL_Conta_Simples = 55,             /* Conta_Simples  */
  YYSYMBOL_Conta_Complexa2 = 56,           /* Conta_Complexa2  */
  YYSYMBOL_Conta_Complexa = 57,            /* Conta_Complexa  */
  YYSYMBOL_Parametros = 58,                /* Parametros  */
  YYSYMBOL_Funcao = 59,                    /* Funcao  */
  YYSYMBOL_Declaracao_Complexa = 60,       /* Declaracao_Complexa  */
  YYSYMBOL_Declaracao_Simples = 61,        /* Declaracao_Simples  */
  YYSYMBOL_Expressao_Declaracao = 62,      /* Expressao_Declaracao  */
  YYSYMBOL_Declaracao = 63,                /* Declaracao  */
  YYSYMBOL_Membro_Simples = 64,            /* Membro_Simples  */
  YYSYMBOL_Dimensoes = 65,                 /* Dimensoes  */
  YYSYMBOL_Objeto = 66,                    /* Objeto  */
  YYSYMBOL_Casos_ID = 67,                  /* Casos_ID  */
  YYSYMBOL_Casos_Objeto = 68,              /* Casos_Objeto  */
  YYSYMBOL_Boolean = 69,                   /* Boolean  */
  YYSYMBOL_Membro = 70,                    /* Membro  */
  YYSYMBOL_Termo = 71,                     /* Termo  */
  YYSYMBOL_Conta = 72,                     /* Conta  */
  YYSYMBOL_Jump_IF = 73,                   /* Jump_IF  */
  YYSYMBOL_Jump_While = 74,                /* Jump_While  */
  YYSYMBOL_Jump_For = 75,                  /* Jump_For  */
  YYSYMBOL_SENAO = 76,                     /* SENAO  */
  YYSYMBOL_Comando = 77,                   /* Comando  */
  YYSYMBOL_Bloco = 78,                     /* Bloco  */
  YYSYMBOL_Expressao = 79,                 /* Expressao  */
  YYSYMBOL_Continuacao = 80,               /* Continuacao  */
  YYSYMBOL_Entrada = 81                    /* Entrada  */
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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,    35,     2,     2,     2,    38,     2,     2,
      39,    40,    36,    31,    28,    30,    45,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      33,    29,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    75,    78,    79,    82,    83,    86,
      89,    92,    93,    96,    97,   100,   101,   102,   103,   104,
     105,   108,   109,   110,   113,   114,   115,   116,   117,   120,
     121,   128,   131,   132,   135,   136,   137,   140,   141,   144,
     145,   148,   149,   150,   151,   154,   155,   156,   157,   158,
     161,   162,   165,   166,   167,   170,   171,   172,   175,   176,
     177,   180,   181,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   195,   198,   201,   202,   205,   206,   209,   210,
     211,   214,   215,   218,   219,   220,   223,   226,   227,   228,
     231,   232,   233,   234,   237,   238
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
  "\"end of file\"", "error", "\"invalid token\"", "_ID", "_FOR", "_IF",
  "_ELSE", "_INT", "_FLOAT", "_MAIG", "_MEIG", "_IG", "_DIF", "_STRING",
  "_STRING2", "_COMENTARIO", "_PRINT", "_LET", "_CONST", "_VAR", "_CONC",
  "_MAISMAIS", "_NEWOBJECT", "_WHILE", "_FUNCTION", "_TRUE", "_FALSE",
  "_RETURN", "','", "'='", "'-'", "'+'", "'>'", "'<'", "'^'", "'!'", "'*'",
  "'/'", "'%'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'.'", "';'",
  "$accept", "Argumentos", "Atribuicao_Objeto2", "Atribuicao_Objeto",
  "Atribuicao_MIGUAL", "AtribuicaoObj_MIGUAL", "Atribuicao_ID2",
  "Atribuicao_ID", "Conta_Simples", "Conta_Complexa2", "Conta_Complexa",
  "Parametros", "Funcao", "Declaracao_Complexa", "Declaracao_Simples",
  "Expressao_Declaracao", "Declaracao", "Membro_Simples", "Dimensoes",
  "Objeto", "Casos_ID", "Casos_Objeto", "Boolean", "Membro", "Termo",
  "Conta", "Jump_IF", "Jump_While", "Jump_For", "SENAO", "Comando",
  "Bloco", "Expressao", "Continuacao", "Entrada", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    44,    61,
      45,    43,    62,    60,    94,    33,    42,    47,    37,    40,
      41,   123,   125,    91,    93,    46,    59
};
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     479,     2,   -30,   -27,  -126,  -126,  -126,   614,    13,    13,
      13,   -22,   -15,    26,  -126,  -126,   614,   614,   614,   435,
       5,  -126,  -126,  -126,    60,  -126,  -126,  -126,   113,     7,
     516,   391,   516,    -2,    46,    28,    30,   639,    75,   614,
      73,  -126,   557,   594,  -126,    39,    -3,  -126,  -126,  -126,
    -126,   594,    55,  -126,  -126,    56,   215,   215,    52,    62,
    -126,    79,    81,   614,  -126,   614,   614,   614,   614,   614,
    -126,  -126,   614,   614,   614,   614,   614,  -126,  -126,  -126,
    -126,   391,  -126,   614,  -126,     7,    64,  -126,  -126,    76,
      69,    74,    77,    80,   614,   119,   614,  -126,  -126,    85,
      13,  -126,  -126,  -126,   215,  -126,   614,  -126,  -126,  -126,
      90,  -126,  -126,  -126,    19,  -126,    19,     7,     7,     7,
       7,     7,  -126,  -126,  -126,   639,  -126,    83,   614,   557,
     557,  -126,    45,    99,   557,    88,  -126,  -126,  -126,   614,
     113,   113,  -126,  -126,  -126,  -126,  -126,  -126,   614,  -126,
      87,    86,  -126,   171,    91,   130,   614,  -126,  -126,  -126,
     259,    92,    95,  -126,  -126,  -126,    97,  -126,   594,   215,
    -126,   133,   114,    99,  -126,   435,    83,   103,  -126,  -126,
    -126,   112,  -126,   303,  -126,  -126,   347,   109,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      71,    14,     0,     0,    46,    47,    45,     4,     0,     0,
       0,     0,     0,     0,    61,    62,    71,    71,    71,    71,
       0,    64,    87,    63,     8,    66,    65,    70,    23,    20,
      71,    71,    71,     0,     0,     0,     0,    71,    71,    71,
       0,    55,    71,    71,    32,     2,    36,    41,    42,    43,
      48,    71,     0,    68,    67,     0,    71,    71,     0,     0,
      49,     0,     0,    71,    58,    71,    71,    71,    71,    71,
      27,    72,    71,    71,    71,    71,    71,    73,    88,    95,
      89,    71,     1,    71,    56,    20,    14,    13,    12,     0,
       0,    52,     0,     0,    71,     0,    71,    40,    34,     0,
      30,    69,    92,    91,    71,    86,    71,    59,    60,     7,
       8,     6,    21,    22,    23,    25,    23,    20,    20,    20,
      20,    20,    94,     9,    57,    71,    33,    51,    71,    71,
      71,     3,    38,    36,    71,     0,    29,    90,    10,    71,
      23,    23,    19,    15,    16,    17,    18,    11,    71,    54,
       0,     0,    83,    71,     0,     0,    71,    37,    39,    85,
      71,     0,     0,     5,    24,    26,     0,    53,    71,    71,
      75,    82,    38,    36,    76,    71,    51,     0,    81,    74,
      35,     0,    50,    71,    31,    84,    71,     0,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,   107,    17,  -126,  -126,  -126,    32,  -126,   -49,   -99,
     -54,  -126,  -126,  -125,  -122,    -5,  -126,  -126,   -18,   -62,
    -126,  -126,  -126,   -48,   -10,    -4,  -126,  -126,  -126,   -12,
     161,  -123,     0,   -29,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,   109,    64,    84,   107,    87,    41,    77,    70,
      71,   135,    21,    97,    98,    47,    22,    23,   149,    24,
      25,    26,    27,    28,    29,    30,   152,   159,   185,   170,
      57,    32,    58,    59,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   110,    79,    45,    48,    49,    53,   153,   158,    42,
     157,   160,    43,    54,    55,   140,    46,   141,    72,   114,
      50,   116,    35,    36,    51,    95,    96,   102,   103,    52,
      78,    37,    80,    88,    45,    90,   124,    73,    74,    75,
      76,    38,    92,    93,    81,    39,    82,    40,   180,    60,
     157,    99,   122,    65,    66,   112,   113,    83,   115,   111,
     186,    85,   117,   118,   119,   120,   121,    94,   142,   143,
     144,   145,   146,   155,   156,   137,    91,   110,     1,   123,
      61,    62,     4,     5,    35,    36,   164,   165,     6,    63,
     131,     7,   133,   125,   100,   136,   101,    11,   104,    13,
      14,    15,   138,    38,   105,    16,    17,    39,   106,    40,
      61,    62,   108,   127,    18,    -4,   126,   128,    20,   139,
     130,    88,   132,   129,   150,   134,   148,    95,   162,   151,
     154,   167,   168,   172,   161,   111,   175,   171,   174,   169,
     178,   176,   155,   183,   166,    89,   181,    65,    66,    67,
      68,    69,   173,    80,   184,   188,   163,   147,   182,   179,
      80,    31,     0,     0,     0,     0,     0,     0,   177,     0,
       0,   -82,     0,     0,     1,   -82,   -82,   169,     4,     5,
       0,     0,     0,   187,     6,     0,    80,     7,     8,     9,
      10,     0,     0,    11,   -82,    13,    14,    15,     0,     0,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,   -82,    20,   -93,     0,   -44,     1,     2,
       3,     0,     4,     5,     0,     0,     0,     0,     6,     0,
       0,     7,     8,     9,    10,     0,     0,    11,    12,    13,
      14,    15,     0,     0,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    19,   -93,    20,   -77,
       0,    56,     1,   -77,   -77,     0,     4,     5,     0,     0,
       0,     0,     6,     0,     0,     7,     8,     9,    10,     0,
       0,    11,   -77,    13,    14,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,   -77,    20,   -80,     0,   -44,     1,   -80,   -80,     0,
       4,     5,     0,     0,     0,     0,     6,     0,     0,     7,
       8,     9,    10,     0,     0,    11,   -80,    13,    14,    15,
       0,     0,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,   -80,    20,   -79,     0,   -44,
       1,   -79,   -79,     0,     4,     5,     0,     0,     0,     0,
       6,     0,     0,     7,     8,     9,    10,     0,     0,    11,
     -79,    13,    14,    15,     0,     0,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    19,   -79,
      20,   -93,     0,   -44,     1,     2,     3,     0,     4,     5,
       0,     0,     0,     0,     6,     0,     0,     7,     8,     9,
      10,     0,     0,    11,    12,    13,    14,    15,     0,     0,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,     0,    20,     0,     0,    56,     1,     2,
       3,     0,     4,     5,     0,     0,     0,     0,     6,     0,
       0,     7,     8,     9,    10,     0,     0,    11,    12,    13,
      14,    15,     0,     0,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    19,   -93,    20,     0,
       0,    56,     1,     2,     3,     0,     4,     5,     0,     0,
       0,     0,     6,     0,     0,     7,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,     1,
      19,     0,    20,     4,     5,   -44,     0,     0,     0,     6,
       0,     0,     7,     8,     9,    10,     0,     0,    11,     0,
      13,    14,    15,     0,     0,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,    18,   -44,    19,     0,    20,
       1,     0,   -44,     0,     4,     5,     0,     0,     0,     0,
       6,     0,     0,     7,     8,     9,    10,     0,     0,    11,
       0,    13,    14,    15,     0,     0,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,    18,     1,    19,     0,
      20,     4,     5,   -44,     0,     0,     0,     6,     0,     0,
       7,     8,     9,    10,     0,     0,    11,     1,    13,    14,
      15,     4,     5,     0,    16,    17,     0,     6,     0,     0,
       7,     0,     0,    18,   -44,    19,    11,    20,    13,    14,
      15,     0,    86,     0,    16,    17,     4,     5,     0,     0,
       0,     0,     6,    18,     0,     7,     0,    20,     0,     0,
       0,    11,     0,    13,    14,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    20
};

static const yytype_int16 yycheck[] =
{
       0,    63,    31,     7,     9,    10,    16,   130,   133,    39,
     132,   134,    39,    17,    18,   114,     3,   116,    11,    67,
      42,    69,    20,    21,    39,    28,    29,    56,    57,     3,
      30,    29,    32,    37,    38,    39,    85,    30,    31,    32,
      33,    39,    42,    43,    46,    43,     0,    45,   173,    44,
     172,    51,    81,    34,    35,    65,    66,    29,    68,    63,
     183,    31,    72,    73,    74,    75,    76,    28,   117,   118,
     119,   120,   121,    28,    29,   104,     3,   139,     3,    83,
      20,    21,     7,     8,    20,    21,   140,   141,    13,    29,
      94,    16,    96,    29,    39,   100,    40,    22,    46,    24,
      25,    26,   106,    39,    42,    30,    31,    43,    29,    45,
      20,    21,    31,    44,    39,    40,    40,    43,    43,    29,
      40,   125,     3,    46,   128,    40,    43,    28,    40,   129,
     130,    44,    46,     3,   134,   139,    41,    46,    46,     6,
     169,    44,    28,    40,   148,    38,   175,    34,    35,    36,
      37,    38,   156,   153,    42,    46,   139,   125,   176,   171,
     160,     0,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,   183,    13,    -1,   186,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,     0,    -1,    46,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,     0,
      -1,    46,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,     0,    -1,    46,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,     0,    -1,    46,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,     0,    -1,    46,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    -1,    43,    -1,    -1,    46,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,    -1,
      -1,    46,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     3,
      41,    -1,    43,     7,     8,    46,    -1,    -1,    -1,    13,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    43,
       3,    -1,    46,    -1,     7,     8,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,     3,    41,    -1,
      43,     7,     8,    46,    -1,    -1,    -1,    13,    -1,    -1,
      16,    17,    18,    19,    -1,    -1,    22,     3,    24,    25,
      26,     7,     8,    -1,    30,    31,    -1,    13,    -1,    -1,
      16,    -1,    -1,    39,    40,    41,    22,    43,    24,    25,
      26,    -1,     3,    -1,    30,    31,     7,     8,    -1,    -1,
      -1,    -1,    13,    39,    -1,    16,    -1,    43,    -1,    -1,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    13,    16,    17,    18,
      19,    22,    23,    24,    25,    26,    30,    31,    39,    41,
      43,    59,    63,    64,    66,    67,    68,    69,    70,    71,
      72,    77,    78,    79,    81,    20,    21,    29,    39,    43,
      45,    54,    39,    39,    48,    72,     3,    62,    62,    62,
      42,    39,     3,    71,    72,    72,    46,    77,    79,    80,
      44,    20,    21,    29,    50,    34,    35,    36,    37,    38,
      56,    57,    11,    30,    31,    32,    33,    55,    79,    80,
      79,    46,     0,    29,    51,    31,     3,    53,    72,    48,
      72,     3,    79,    79,    28,    28,    29,    60,    61,    79,
      39,    40,    80,    80,    46,    42,    29,    52,    31,    49,
      66,    72,    71,    71,    70,    71,    70,    71,    71,    71,
      71,    71,    80,    72,    55,    29,    40,    44,    43,    46,
      40,    72,     3,    72,    40,    58,    62,    80,    72,    29,
      56,    56,    55,    55,    55,    55,    55,    53,    43,    65,
      72,    79,    73,    78,    79,    28,    29,    61,    60,    74,
      78,    79,    40,    49,    57,    57,    72,    44,    46,     6,
      76,    46,     3,    72,    46,    41,    44,    79,    80,    76,
      60,    80,    65,    40,    42,    75,    78,    79,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    73,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    79,    79,    79,
      80,    80,    80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     0,     3,     1,     2,     0,     2,
       2,     3,     1,     2,     0,     3,     3,     3,     3,     3,
       0,     2,     2,     0,     4,     2,     4,     1,     0,     1,
       0,     8,     2,     4,     1,     5,     0,     3,     0,     4,
       2,     2,     2,     2,     0,     1,     1,     1,     2,     2,
       4,     0,     3,     6,     5,     2,     3,     4,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     0,     2,     2,     3,     2,     2,     1,     2,     1,
       0,     2,     0,     5,     9,     5,     3,     1,     2,     2,
       3,     2,     2,     0,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  case 2: /* Argumentos: Conta  */
#line 73 "miniJS.y"
                                  {yyval.valor = yyvsp[0].valor;}
#line 1516 "y.tab.c"
    break;

  case 3: /* Argumentos: Conta ',' Conta  */
#line 74 "miniJS.y"
                                  {yyval.valor = yyvsp[-2].valor + " " + yyvsp[0].valor;}
#line 1522 "y.tab.c"
    break;

  case 4: /* Argumentos: %empty  */
#line 75 "miniJS.y"
                                  {yyval.valor = "";}
#line 1528 "y.tab.c"
    break;

  case 5: /* Atribuicao_Objeto2: Objeto '=' Atribuicao_Objeto2  */
#line 78 "miniJS.y"
                                                         {yyval.valor = " " +yyvsp[-2].valor + yyvsp[0].valor + " " + yyvsp[-2].valor + "[@]" + " [=] ^";}
#line 1534 "y.tab.c"
    break;

  case 6: /* Atribuicao_Objeto2: Conta  */
#line 79 "miniJS.y"
                                                         {yyval.valor = " " + yyvsp[0].valor + " [=] ^";}
#line 1540 "y.tab.c"
    break;

  case 7: /* Atribuicao_Objeto: '=' Atribuicao_Objeto2  */
#line 82 "miniJS.y"
                                                    {yyval.valor = yyvsp[0].valor;}
#line 1546 "y.tab.c"
    break;

  case 8: /* Atribuicao_Objeto: %empty  */
#line 83 "miniJS.y"
                                                    {yyval.valor = "[@]";}
#line 1552 "y.tab.c"
    break;

  case 9: /* Atribuicao_MIGUAL: '=' Conta  */
#line 86 "miniJS.y"
                                         {yyval.valor = yyvsp[0].valor + " + = ^";}
#line 1558 "y.tab.c"
    break;

  case 10: /* AtribuicaoObj_MIGUAL: '=' Conta  */
#line 89 "miniJS.y"
                                         {yyval.valor = yyvsp[0].valor + " + [=] ^";}
#line 1564 "y.tab.c"
    break;

  case 11: /* Atribuicao_ID2: _ID '=' Atribuicao_ID2  */
#line 92 "miniJS.y"
                                         {yyval.valor = " " +yyvsp[-2].valor + yyvsp[0].valor + " " + yyvsp[-2].valor + "@" + " = ^";}
#line 1570 "y.tab.c"
    break;

  case 12: /* Atribuicao_ID2: Conta  */
#line 93 "miniJS.y"
                                         {yyval.valor = " " + yyvsp[0].valor + " = ^";}
#line 1576 "y.tab.c"
    break;

  case 13: /* Atribuicao_ID: '=' Atribuicao_ID2  */
#line 96 "miniJS.y"
                                          {yyval.valor = yyvsp[0].valor;}
#line 1582 "y.tab.c"
    break;

  case 14: /* Atribuicao_ID: %empty  */
#line 97 "miniJS.y"
                                          {yyval.valor = "@";}
#line 1588 "y.tab.c"
    break;

  case 15: /* Conta_Simples: '-' Termo Conta_Simples  */
#line 100 "miniJS.y"
                                                        {yyval.valor = " " + yyvsp[-1].valor + " -" + yyvsp[0].valor;}
#line 1594 "y.tab.c"
    break;

  case 16: /* Conta_Simples: '+' Termo Conta_Simples  */
#line 101 "miniJS.y"
                                                        {yyval.valor = " " + yyvsp[-1].valor + " +" + yyvsp[0].valor;}
#line 1600 "y.tab.c"
    break;

  case 17: /* Conta_Simples: '>' Termo Conta_Simples  */
#line 102 "miniJS.y"
                                                        {yyval.valor = " " + yyvsp[-1].valor + yyvsp[0].valor + " >";}
#line 1606 "y.tab.c"
    break;

  case 18: /* Conta_Simples: '<' Termo Conta_Simples  */
#line 103 "miniJS.y"
                                                        {yyval.valor = " " + yyvsp[-1].valor + yyvsp[0].valor + " <";}
#line 1612 "y.tab.c"
    break;

  case 19: /* Conta_Simples: _IG Termo Conta_Simples  */
#line 104 "miniJS.y"
                                                        {yyval.valor = " " + yyvsp[-1].valor + yyvsp[0].valor + " ==";}
#line 1618 "y.tab.c"
    break;

  case 20: /* Conta_Simples: %empty  */
#line 105 "miniJS.y"
                                                        {yyval.valor = "";}
#line 1624 "y.tab.c"
    break;

  case 21: /* Conta_Complexa2: '^' Termo  */
#line 108 "miniJS.y"
                                {yyval.valor = " " + yyvsp[0].valor + " ^";}
#line 1630 "y.tab.c"
    break;

  case 22: /* Conta_Complexa2: '!' Termo  */
#line 109 "miniJS.y"
                                {yyval.valor = " fat #" + yyvsp[0].valor;}
#line 1636 "y.tab.c"
    break;

  case 23: /* Conta_Complexa2: %empty  */
#line 110 "miniJS.y"
                                {yyval.valor = "";}
#line 1642 "y.tab.c"
    break;

  case 24: /* Conta_Complexa: '*' Membro Conta_Complexa2 Conta_Complexa  */
#line 113 "miniJS.y"
                                                                {yyval.valor = " " + yyvsp[-2].valor + yyvsp[-1].valor + " *" + yyvsp[0].valor;}
#line 1648 "y.tab.c"
    break;

  case 25: /* Conta_Complexa: '/' Termo  */
#line 114 "miniJS.y"
                                                                {yyval.valor = " " + yyvsp[0].valor + " /";}
#line 1654 "y.tab.c"
    break;

  case 26: /* Conta_Complexa: '%' Membro Conta_Complexa2 Conta_Complexa  */
#line 115 "miniJS.y"
                                                                {yyval.valor = " " + yyvsp[-2].valor + yyvsp[-1].valor + " *" + yyvsp[0].valor;}
#line 1660 "y.tab.c"
    break;

  case 27: /* Conta_Complexa: Conta_Complexa2  */
#line 116 "miniJS.y"
                                                                {yyval.valor = yyvsp[0].valor;}
#line 1666 "y.tab.c"
    break;

  case 28: /* Conta_Complexa: %empty  */
#line 117 "miniJS.y"
                                                                {yyval.valor = "";}
#line 1672 "y.tab.c"
    break;

  case 29: /* Parametros: Expressao_Declaracao  */
#line 120 "miniJS.y"
                                  {yyval.valor = yyvsp[0].valor;}
#line 1678 "y.tab.c"
    break;

  case 30: /* Parametros: %empty  */
#line 121 "miniJS.y"
                                  {yyval.valor = "";}
#line 1684 "y.tab.c"
    break;

  case 31: /* Funcao: _FUNCTION _ID '(' Parametros ')' '{' Continuacao '}'  */
#line 128 "miniJS.y"
                                                                { string label = enderecoPraFrente(yyvsp[-6].valor);
                                                                   funcoes = funcoes + enderecoResolvido(yyvsp[-6].valor) + yyvsp[-4].valor + " " + yyvsp[-1].valor + " ";
                                                                   yyval.valor = yyvsp[-6].valor + "& " + yyvsp[-6].valor + " {} = '&funcao' " + label + " [=] ^ ";}
#line 1692 "y.tab.c"
    break;

  case 32: /* Funcao: _PRINT Argumentos  */
#line 131 "miniJS.y"
                                                              {yyval.valor = yyvsp[0].valor + " print #";}
#line 1698 "y.tab.c"
    break;

  case 33: /* Funcao: _ID '(' Argumentos ')'  */
#line 132 "miniJS.y"
                                                              {yyval.valor = yyvsp[-1].valor + " " + yyvsp[-3].valor + "@ $";}
#line 1704 "y.tab.c"
    break;

  case 34: /* Declaracao_Complexa: Declaracao_Simples  */
#line 135 "miniJS.y"
                                                                {yyval.valor = yyvsp[0].valor;}
#line 1710 "y.tab.c"
    break;

  case 35: /* Declaracao_Complexa: ',' _ID '=' Conta Declaracao_Complexa  */
#line 136 "miniJS.y"
                                                                {setVar(yyvsp[-3].valor, linha);yyval.valor = " " + yyvsp[-3].valor + "& " + yyvsp[-3].valor + " " + yyvsp[-1].valor + " = ^"+ yyvsp[0].valor;}
#line 1716 "y.tab.c"
    break;

  case 36: /* Declaracao_Complexa: %empty  */
#line 137 "miniJS.y"
                                                                {yyval.valor = "";}
#line 1722 "y.tab.c"
    break;

  case 37: /* Declaracao_Simples: ',' _ID Declaracao_Simples  */
#line 140 "miniJS.y"
                                                  {setVar(yyvsp[-1].valor, linha);yyval.valor = " " + yyvsp[-1].valor + "&" + yyvsp[0].valor;}
#line 1728 "y.tab.c"
    break;

  case 38: /* Declaracao_Simples: %empty  */
#line 141 "miniJS.y"
                                                  {yyval.valor = "";}
#line 1734 "y.tab.c"
    break;

  case 39: /* Expressao_Declaracao: _ID '=' Conta Declaracao_Complexa  */
#line 144 "miniJS.y"
                                                              {setVar(yyvsp[-3].valor, linha); yyval.valor = yyvsp[-3].valor + "& " + yyvsp[-3].valor + " " + yyvsp[-1].valor + " = ^" + yyvsp[0].valor;}
#line 1740 "y.tab.c"
    break;

  case 40: /* Expressao_Declaracao: _ID Declaracao_Complexa  */
#line 145 "miniJS.y"
                                                              {setVar(yyvsp[-1].valor, linha); yyval.valor = yyvsp[-1].valor + "&" + yyvsp[0].valor;}
#line 1746 "y.tab.c"
    break;

  case 41: /* Declaracao: _LET Expressao_Declaracao  */
#line 148 "miniJS.y"
                                              {yyval.valor = yyvsp[0].valor;}
#line 1752 "y.tab.c"
    break;

  case 42: /* Declaracao: _CONST Expressao_Declaracao  */
#line 149 "miniJS.y"
                                              {yyval.valor = yyvsp[0].valor;}
#line 1758 "y.tab.c"
    break;

  case 43: /* Declaracao: _VAR Expressao_Declaracao  */
#line 150 "miniJS.y"
                                              {yyval.valor = yyvsp[0].valor;}
#line 1764 "y.tab.c"
    break;

  case 44: /* Declaracao: %empty  */
#line 151 "miniJS.y"
                                              {yyval.valor = "";}
#line 1770 "y.tab.c"
    break;

  case 45: /* Membro_Simples: _STRING  */
#line 154 "miniJS.y"
                                   {yyval.valor = yyvsp[0].valor;}
#line 1776 "y.tab.c"
    break;

  case 46: /* Membro_Simples: _INT  */
#line 155 "miniJS.y"
                                   {yyval.valor = yyvsp[0].valor;}
#line 1782 "y.tab.c"
    break;

  case 47: /* Membro_Simples: _FLOAT  */
#line 156 "miniJS.y"
                                   {yyval.valor = yyvsp[0].valor;}
#line 1788 "y.tab.c"
    break;

  case 48: /* Membro_Simples: _NEWOBJECT '}'  */
#line 157 "miniJS.y"
                                   {yyval.valor = "{}";}
#line 1794 "y.tab.c"
    break;

  case 49: /* Membro_Simples: '[' ']'  */
#line 158 "miniJS.y"
                                   {yyval.valor = "[]";}
#line 1800 "y.tab.c"
    break;

  case 50: /* Dimensoes: '[' Conta ']' Dimensoes  */
#line 161 "miniJS.y"
                                            {yyval.valor ="[@] " + yyvsp[-2].valor + yyvsp[-2].getRetorno() + yyvsp[0].valor;}
#line 1806 "y.tab.c"
    break;

  case 51: /* Dimensoes: %empty  */
#line 162 "miniJS.y"
                                            {yyval.valor = "";}
#line 1812 "y.tab.c"
    break;

  case 52: /* Objeto: _ID '.' _ID  */
#line 165 "miniJS.y"
                                         {yyval.valor = yyvsp[-2].valor + "@ " + yyvsp[0].valor;}
#line 1818 "y.tab.c"
    break;

  case 53: /* Objeto: _ID '.' _ID '[' Conta ']'  */
#line 166 "miniJS.y"
                                         {yyval.valor = yyvsp[-5].valor + "@ " + yyvsp[-3].valor + "[@] " + yyvsp[-1].valor;}
#line 1824 "y.tab.c"
    break;

  case 54: /* Objeto: _ID '[' Conta ']' Dimensoes  */
#line 167 "miniJS.y"
                                         {yyval.valor = yyvsp[-4].valor + "@ " + yyvsp[-2].valor + yyvsp[-2].getRetorno() + yyvsp[0].valor;}
#line 1830 "y.tab.c"
    break;

  case 55: /* Casos_ID: _ID Atribuicao_ID  */
#line 170 "miniJS.y"
                                                    {checkVar(yyvsp[-1].valor);yyval.valor = yyvsp[-1].valor + yyvsp[0].valor; yyval.retorno = " " + yyvsp[-1].valor + "@";}
#line 1836 "y.tab.c"
    break;

  case 56: /* Casos_ID: _ID _CONC Atribuicao_MIGUAL  */
#line 171 "miniJS.y"
                                                    {yyval.valor = yyvsp[-2].valor + " " + yyvsp[-2].valor + "@ " + yyvsp[0].valor;}
#line 1842 "y.tab.c"
    break;

  case 57: /* Casos_ID: _ID _MAISMAIS '+' Conta_Simples  */
#line 172 "miniJS.y"
                                                    {yyval.valor = yyvsp[-3].valor + "@" + yyvsp[0].valor + " " + yyvsp[-3].valor + " " + yyvsp[-3].valor + "@ 1 + = ^";}
#line 1848 "y.tab.c"
    break;

  case 58: /* Casos_Objeto: Objeto Atribuicao_Objeto  */
#line 175 "miniJS.y"
                                                        {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 1854 "y.tab.c"
    break;

  case 59: /* Casos_Objeto: Objeto _CONC AtribuicaoObj_MIGUAL  */
#line 176 "miniJS.y"
                                                        {yyval.valor = yyvsp[-2].valor + " " + yyvsp[-2].valor + "[@] " + yyvsp[0].valor;}
#line 1860 "y.tab.c"
    break;

  case 60: /* Casos_Objeto: Objeto _MAISMAIS '+'  */
#line 177 "miniJS.y"
                                                        {yyval.valor = yyvsp[-2].valor + " " + yyvsp[-2].valor + "@ 1 + [=] ^ " + yyvsp[-2].valor + "@";}
#line 1866 "y.tab.c"
    break;

  case 61: /* Boolean: _TRUE  */
#line 180 "miniJS.y"
                 {yyval.valor = yyvsp[0].valor;}
#line 1872 "y.tab.c"
    break;

  case 62: /* Boolean: _FALSE  */
#line 181 "miniJS.y"
                 {yyval.valor = yyvsp[0].valor;}
#line 1878 "y.tab.c"
    break;

  case 63: /* Membro: Membro_Simples  */
#line 184 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1884 "y.tab.c"
    break;

  case 64: /* Membro: Funcao  */
#line 185 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1890 "y.tab.c"
    break;

  case 65: /* Membro: Casos_Objeto  */
#line 186 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1896 "y.tab.c"
    break;

  case 66: /* Membro: Casos_ID  */
#line 187 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;yyval.retorno=yyvsp[0].retorno;}
#line 1902 "y.tab.c"
    break;

  case 67: /* Membro: '+' Conta  */
#line 188 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1908 "y.tab.c"
    break;

  case 68: /* Membro: '-' Termo  */
#line 189 "miniJS.y"
                                                  {yyval.valor = "0 " + yyvsp[0].valor + " -";}
#line 1914 "y.tab.c"
    break;

  case 69: /* Membro: '(' Conta ')'  */
#line 190 "miniJS.y"
                                                  {yyval.valor = yyvsp[-1].valor;}
#line 1920 "y.tab.c"
    break;

  case 70: /* Membro: Boolean  */
#line 191 "miniJS.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1926 "y.tab.c"
    break;

  case 71: /* Membro: %empty  */
#line 192 "miniJS.y"
                                                  {yyval.valor = "";}
#line 1932 "y.tab.c"
    break;

  case 72: /* Termo: Membro Conta_Complexa  */
#line 195 "miniJS.y"
                                  {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;yyval.retorno=yyvsp[-1].retorno;}
#line 1938 "y.tab.c"
    break;

  case 73: /* Conta: Termo Conta_Simples  */
#line 198 "miniJS.y"
                                  {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;yyval.retorno=yyvsp[-1].retorno;}
#line 1944 "y.tab.c"
    break;

  case 74: /* Jump_IF: Expressao ';' SENAO  */
#line 201 "miniJS.y"
                                            {count_label++; yyval.valor = yyvsp[0].valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + yyvsp[-2].valor + " " + LABEL_RENDIF + to_string(count_label);}
#line 1950 "y.tab.c"
    break;

  case 75: /* Jump_IF: Bloco SENAO  */
#line 202 "miniJS.y"
                                             {count_label++; yyval.valor = yyvsp[0].valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + yyvsp[-1].valor + " "+ LABEL_RENDIF + to_string(count_label);}
#line 1956 "y.tab.c"
    break;

  case 76: /* Jump_While: Expressao ';'  */
#line 205 "miniJS.y"
                                           {count_label++; yyval.valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + " " + yyvsp[-1].valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
#line 1962 "y.tab.c"
    break;

  case 77: /* Jump_While: Bloco  */
#line 206 "miniJS.y"
                                           {count_label++; yyval.valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + yyvsp[0].valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
#line 1968 "y.tab.c"
    break;

  case 78: /* Jump_For: Expressao ';'  */
#line 209 "miniJS.y"
                                           {count_label++; yyval.valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + yyvsp[-1].valor;}
#line 1974 "y.tab.c"
    break;

  case 79: /* Jump_For: Bloco  */
#line 210 "miniJS.y"
                                           {count_label++; yyval.valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + yyvsp[0].valor;}
#line 1980 "y.tab.c"
    break;

  case 81: /* SENAO: _ELSE Continuacao  */
#line 214 "miniJS.y"
                              {yyval.valor = yyvsp[0].valor;}
#line 1986 "y.tab.c"
    break;

  case 82: /* SENAO: %empty  */
#line 215 "miniJS.y"
                              {yyval.valor = "";}
#line 1992 "y.tab.c"
    break;

  case 83: /* Comando: _IF '(' Expressao ')' Jump_IF  */
#line 218 "miniJS.y"
                                                                         {yyval.valor = yyvsp[-2].valor + " " + LABEL_IF + to_string(count_label) + " ?" + yyvsp[0].valor;}
#line 1998 "y.tab.c"
    break;

  case 84: /* Comando: _FOR '(' Expressao ';' Expressao ';' Expressao ')' Jump_For  */
#line 219 "miniJS.y"
                                                                         {yyval.valor = yyvsp[-6].valor + " " + LABEL_RFOR + to_string(count_label) + " " + yyvsp[-4].valor + " " + LABEL_CORPO_FOR + to_string(count_label) + " ? " + yyvsp[0].valor + " " + yyvsp[-2].valor + " " + LABEL_FOR + to_string(count_label) + " # " + LABEL_RENDFOR + to_string(count_label);}
#line 2004 "y.tab.c"
    break;

  case 85: /* Comando: _WHILE '(' Expressao ')' Jump_While  */
#line 220 "miniJS.y"
                                                                         {yyval.valor = LABEL_RWHILE + to_string(count_label) + " " + yyvsp[-2].valor + " " + LABEL_CORPO_WHILE + to_string(count_label) + " ? " + yyvsp[0].valor;}
#line 2010 "y.tab.c"
    break;

  case 86: /* Bloco: '{' Continuacao '}'  */
#line 223 "miniJS.y"
                            {yyval.valor = yyvsp[-1].valor;}
#line 2016 "y.tab.c"
    break;

  case 87: /* Expressao: Declaracao  */
#line 226 "miniJS.y"
                                            {yyval.valor = yyvsp[0].valor;}
#line 2022 "y.tab.c"
    break;

  case 88: /* Expressao: Conta Expressao  */
#line 227 "miniJS.y"
                                            {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 2028 "y.tab.c"
    break;

  case 89: /* Expressao: Bloco Expressao  */
#line 228 "miniJS.y"
                                            {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 2034 "y.tab.c"
    break;

  case 90: /* Continuacao: Expressao ';' Continuacao  */
#line 231 "miniJS.y"
                                                 {yyval.valor = " " + yyvsp[-2].valor + yyvsp[0].valor;}
#line 2040 "y.tab.c"
    break;

  case 91: /* Continuacao: Comando Continuacao  */
#line 232 "miniJS.y"
                                                 {yyval.valor = " " + yyvsp[-1].valor + yyvsp[0].valor;}
#line 2046 "y.tab.c"
    break;

  case 92: /* Continuacao: ';' Continuacao  */
#line 233 "miniJS.y"
                                                 {yyval.valor = yyvsp[0].valor;}
#line 2052 "y.tab.c"
    break;

  case 93: /* Continuacao: %empty  */
#line 234 "miniJS.y"
                                                 {yyval.valor = "";}
#line 2058 "y.tab.c"
    break;

  case 94: /* Entrada: Expressao ';' Continuacao  */
#line 237 "miniJS.y"
                                              {mostrar(yyvsp[-2].valor + yyvsp[0].valor + " ." + funcoes);}
#line 2064 "y.tab.c"
    break;

  case 95: /* Entrada: Comando Continuacao  */
#line 238 "miniJS.y"
                                              {mostrar(yyvsp[-1].valor + yyvsp[0].valor + " ." + funcoes);}
#line 2070 "y.tab.c"
    break;


#line 2074 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 240 "miniJS.y"


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

string enderecoPraFrente(string nome){
        return ":" + nome + to_string(count_label);
}

string enderecoResolvido(string nome){
        return ";" + nome + to_string(count_label);
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
   printf( "Proximo a: %s\nCoord: %d-%d\n", yytext, linha, coluna);
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}
