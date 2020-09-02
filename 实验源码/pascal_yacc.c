/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include"windows.h"
#include "ast.h"
#include "table.h"
#include "pascal_lex.h"

#define MAXSTR 50
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1

extern int yylex();
extern FILE* yyin;
extern char str1[50];
extern int line_no;
extern int NXQ;
extern int VarCount;
extern ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];//四元式
extern table_variable VarList[TABLE_MAX_VAR_NUM];//符号表

int flag_var_def = 0;


/* Line 371 of yacc.c  */
#line 98 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.c"

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
   by #include "pascal_yacc.h".  */
#ifndef YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED
# define YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Iden = 300,
     IntNo = 301,
     RealNo = 302,
     Program = 400,
     Begin = 401,
     End = 402,
     Var = 403,
     Integer = 404,
     Real = 405,
     While = 406,
     Do = 407,
     If = 408,
     Then = 409,
     Else = 410,
     For = 411,
     To = 412,
     Array = 413,
     Of = 414,
     Or = 415,
     And = 416,
     Not = 417,
     dian = 418,
     Until = 419,
     step = 420,
     LE = 500,
     GE = 501,
     NE = 502,
     UMINUS = 504
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 31 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"

    struct
    {
         int Iv;
         int CH;
         int NO;
         struct { int TC,FC;} _BExpr;
         struct {int place;int QUAD;int CH;} _forloop;
         struct { int QUAD,CH;} _WBD; //while
         struct { int type,place;union{int Iv;float Rv;} Value;} _Expr;
         char _Rop[5];
         int First;
         char str[50];
         struct node *trNode;
         struct { int PLACE, OFFSET;} _Var;
         struct { int NO, DIM, PLACE;} _Elist;
    }st;


/* Line 387 of yacc.c  */
#line 191 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 219 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   504

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      43,    44,    35,    33,    42,    34,    40,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    39,
      30,    32,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    45,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    29,     2,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    14,    18,    22,    24,    28,
      32,    34,    36,    40,    42,    45,    47,    50,    52,    55,
      58,    61,    63,    67,    68,    72,    77,    82,    86,    90,
      94,    96,   100,   103,   106,   109,   113,   116,   119,   123,
     127,   131,   135,   139,   142,   144,   146,   148,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   174,   178,   184,
     189,   193,   199
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,     6,     3,    49,    39,    50,    40,
      -1,    51,    59,    -1,     9,    52,    39,    -1,    52,    39,
      53,    -1,    53,    -1,    55,    41,    54,    -1,    72,    20,
      54,    -1,    10,    -1,    11,    -1,    55,    42,    69,    -1,
      69,    -1,    57,    58,    -1,    58,    -1,    56,    39,    -1,
      60,    -1,    61,    58,    -1,    62,    58,    -1,    63,    58,
      -1,    59,    -1,    76,    13,    58,    -1,    -1,     7,    56,
       8,    -1,     7,    56,    39,     8,    -1,    69,    41,    32,
      68,    -1,    62,    58,    16,    -1,    14,    65,    15,    -1,
      64,    65,    13,    -1,    12,    -1,    68,    71,    68,    -1,
      66,    65,    -1,    67,    65,    -1,    23,    65,    -1,    43,
      65,    44,    -1,    65,    22,    -1,    65,    21,    -1,    68,
      33,    68,    -1,    68,    34,    68,    -1,    68,    35,    68,
      -1,    68,    36,    68,    -1,    43,    68,    44,    -1,    34,
      68,    -1,    69,    -1,    70,    -1,     3,    -1,    74,    45,
      -1,     4,    -1,     5,    -1,    30,    -1,    31,    -1,    32,
      -1,    28,    -1,    29,    -1,    27,    -1,    55,    41,    19,
      46,    73,    45,    -1,    68,    24,    68,    -1,    73,    42,
      68,    24,    68,    -1,    69,    46,    68,    45,    -1,    74,
      46,    68,    -1,    17,    69,    41,    32,    68,    -1,    75,
      26,    68,    25,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   122,   132,   141,   151,   158,   163,   183,
     209,   219,   229,   239,   247,   255,   262,   271,   278,   286,
     295,   305,   312,   322,   326,   336,   348,   381,   396,   409,
     421,   432,   445,   456,   467,   476,   483,   490,   496,   508,
     520,   532,   544,   551,   563,   595,   612,   631,   643,   653,
     665,   670,   675,   680,   685,   690,   697,   709,   729,   753,
     760,   780,   791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Iden", "IntNo", "RealNo", "Program",
  "Begin", "End", "Var", "Integer", "Real", "While", "Do", "If", "Then",
  "Else", "For", "To", "Array", "Of", "Or", "And", "Not", "dian", "Until",
  "step", "LE", "GE", "NE", "'<'", "'>'", "'='", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UMINUS", "';'", "'.'", "':'", "','", "'('", "')'", "']'",
  "'['", "$accept", "ProgDef", "$@1", "SubProg", "VarDef", "VarDefList",
  "VarDefState", "Type", "VarList", "StateList", "StateLists", "Statement",
  "CompState", "AsignState", "ITE", "IT", "Wd", "W", "BoolExpr",
  "BoolExprAnd", "BoolExprOr", "Expr", "Variable", "Const", "RelationOp",
  "ArrayVar", "ArrayMSG", "ExprList", "ForLoop1", "ForLoop2", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   503,   300,   301,   302,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   500,   501,   502,
      60,    62,    61,    43,    45,    42,    47,    37,   504,    59,
      46,    58,    44,    40,    41,    93,    91
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    48,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    61,    62,    63,
      64,    65,    65,    65,    65,    65,    66,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    74,
      74,    75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     3,     3,     1,     3,     3,
       1,     1,     3,     1,     2,     1,     2,     1,     2,     2,
       2,     1,     3,     0,     3,     4,     4,     3,     3,     3,
       1,     3,     2,     2,     2,     3,     2,     2,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     3,     5,     4,
       3,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     0,     0,     0,
      46,     0,     7,     0,    13,     0,     0,     3,    23,     4,
       5,     0,     0,     0,     0,    47,     0,    30,     0,     0,
       0,    23,    15,    21,    17,    23,    23,    23,     0,     0,
       0,     0,     6,    10,    11,     0,     8,    12,    48,    49,
       0,     0,     0,    44,    45,     9,    60,     0,     0,     0,
       0,     0,     0,     0,    24,    16,    14,    18,    19,    20,
       0,     0,     0,    23,     0,    43,     0,     0,     0,     0,
       0,    59,    34,     0,     0,    28,    37,    36,    32,    33,
      55,    53,    54,    50,    51,    52,     0,     0,    25,    27,
      29,     0,     0,    22,     0,     0,    42,    38,    39,    40,
      41,    35,    31,     0,    26,     0,     0,     0,    56,    61,
      62,    57,     0,     0,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     8,     9,    11,    12,    46,    13,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    59,    60,
      61,    62,    53,    54,    96,    15,   105,    16,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int16 yypact[] =
{
       3,    10,    15,   -30,   -30,   -15,    17,    59,    18,    63,
     -30,    27,   -30,    69,    43,    71,    79,   -30,    57,   -30,
      59,    42,    59,    29,   116,   -30,    29,   -30,    16,    59,
      -3,    57,   -30,   -30,   -30,    57,    57,    57,    16,   -24,
      49,    86,   -30,   -30,   -30,    66,   -30,    43,   -30,   -30,
      29,    29,    68,    43,   -30,   -30,    12,    16,    16,   -11,
      16,    16,   107,    82,   -30,   140,   -30,   -30,   133,   -30,
      55,   118,    29,    57,    29,   -30,    85,    29,    29,    29,
      29,   -30,   -30,    21,    52,   -30,   -30,   -30,   123,   123,
     -30,   -30,   -30,   -30,   -30,   -30,    29,   119,   -30,   -30,
     -30,    29,    97,   -30,    73,    53,   -30,   111,   111,   -30,
     -30,   -30,    12,    29,    12,    29,    29,    29,   -30,    12,
      12,    12,    81,    29,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   -30,   -30,   -30,   -30,   132,   129,   -30,   -30,
     -30,   -29,   145,   -30,   -30,   -30,   -30,   -30,   -20,   -30,
     -30,   -23,    -6,   -30,   -30,   -30,   -30,   -30,   -30,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    14,    66,    56,    85,    64,    67,    68,    69,     1,
      86,    87,    39,     3,    14,     4,    47,    71,    70,    10,
      48,    49,    23,    63,     6,    39,     7,    75,    76,    39,
      39,    39,    10,    48,    49,    84,    65,    82,    83,    57,
      88,    89,    86,    87,   103,    77,    78,    79,    80,   102,
      50,   104,    43,    44,   107,   108,   109,   110,    17,    58,
      10,    45,    10,    50,    18,   111,    20,    39,   100,    27,
      18,    28,    51,   112,    29,    72,    86,    87,   114,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    23,
     119,    24,   120,   121,   122,   117,   106,   116,   118,    73,
     124,    77,    78,    79,    80,   123,    77,    78,    79,    80,
      21,    22,    74,    81,    77,    78,    79,    80,    77,    78,
      79,    80,   115,    97,    25,    26,    43,    44,    23,   106,
      77,    78,    79,    80,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    86,    87,    79,    80,    98,    99,
     101,   113,    42,    55,    19
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      23,     7,    31,    26,    15,     8,    35,    36,    37,     6,
      21,    22,    18,     3,    20,     0,    22,    41,    38,     3,
       4,     5,    46,    29,    39,    31,     9,    50,    51,    35,
      36,    37,     3,     4,     5,    58,    39,    57,    58,    23,
      60,    61,    21,    22,    73,    33,    34,    35,    36,    72,
      34,    74,    10,    11,    77,    78,    79,    80,    40,    43,
       3,    19,     3,    34,     7,    44,    39,    73,    13,    12,
       7,    14,    43,    96,    17,    26,    21,    22,   101,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    46,
     113,    20,   115,   116,   117,    42,    44,    24,    45,    13,
     123,    33,    34,    35,    36,    24,    33,    34,    35,    36,
      41,    42,    46,    45,    33,    34,    35,    36,    33,    34,
      35,    36,    25,    41,    45,    46,    10,    11,    46,    44,
      33,    34,    35,    36,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    21,    22,    35,    36,     8,    16,
      32,    32,    20,    24,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    48,     3,     0,    49,    39,     9,    50,    51,
       3,    52,    53,    55,    69,    72,    74,    40,     7,    59,
      39,    41,    42,    46,    20,    45,    46,    12,    14,    17,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    69,
      75,    76,    53,    10,    11,    19,    54,    69,     4,     5,
      34,    43,    68,    69,    70,    54,    68,    23,    43,    65,
      66,    67,    68,    69,     8,    39,    58,    58,    58,    58,
      65,    41,    26,    13,    46,    68,    68,    33,    34,    35,
      36,    45,    65,    65,    68,    15,    21,    22,    65,    65,
      27,    28,    29,    30,    31,    32,    71,    41,     8,    16,
      13,    32,    68,    58,    68,    73,    44,    68,    68,    68,
      68,    44,    68,    32,    68,    25,    24,    42,    45,    68,
      68,    68,    68,    24,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 122 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {set_node_val_str(&root,str1);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 123 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            printf("\nCompile successfully!\n");
            (yyval.st).trNode=&root;
            (yyval.st).trNode->type=e_program;
            add_son_node(&root,(yyvsp[(5) - (6)].st).trNode);
            printf("\n\n**** Program %s ****\n",root.val.str);
        }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 133 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_sub_prog;
            set_node_val_str((yyval.st).trNode, "SubProg");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (2)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (2)].st).trNode);
		}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 142 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            // 变量声明
            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_var_def;
            set_node_val_str((yyval.st).trNode, "Var");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (3)].st).trNode);

		}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 152 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 不同类型的多个变量声明
			struct node *last =get_last_node((yyvsp[(1) - (3)].st).trNode);
			add_brother_node(last,(yyvsp[(3) - (3)].st).trNode);
			(yyval.st).trNode=(yyvsp[(1) - (3)].st).trNode;
		}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 159 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st).trNode=(yyvsp[(1) - (1)].st).trNode;
        }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 164 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// VarList记录的多个变量指定类型
			int check = 0;
            while ((yyvsp[(1) - (3)].st).First)
            {
                VarList[(yyvsp[(1) - (3)].st).First].type = (yyvsp[(3) - (3)].st).Iv;
                (yyvsp[(1) - (3)].st).First = VarList[(yyvsp[(1) - (3)].st).First].addr;

                if(check++ > MAXMEMBER)
                {
                    yyerror("** Repeatly define variable **\n");
                }
            }

            struct node *last = get_last_node((yyvsp[(1) - (3)].st).trNode);
            add_brother_node(last, (yyvsp[(3) - (3)].st).trNode);
            (yyvsp[(1) - (3)].st).trNode->type = e_varlist;
            (yyval.st).trNode = (yyvsp[(1) - (3)].st).trNode;
		}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 184 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            int check = 0;
            int NO = (yyvsp[(1) - (3)].st).NO;

            if ((yyvsp[(3) - (3)].st).Iv == 1)
            {
                (yyvsp[(3) - (3)].st).Iv = 2;//real array
            }
            else
            {
                (yyvsp[(3) - (3)].st).Iv = 3;//int array
            }

            while (NO)
            {
                VarList[NO].type = (yyvsp[(3) - (3)].st).Iv;
                NO = VarList[NO].addr;

                if(check++ > MAXMEMBER)
                {
                    yyerror("** Repeatly define variable **\n");
                }
            }
        }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 210 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 整数类型
			(yyval.st).Iv = 0;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_type_int;
            set_node_val_str((yyval.st).trNode, "Integer");
		}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 220 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 实数类型
			(yyval.st).Iv = 1;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_type_real;
            set_node_val_str((yyval.st).trNode, "Real");
		}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 230 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 同一类型的多个变量通过逗号分割
			(yyval.st).First = (yyvsp[(3) - (3)].st)._Var.PLACE;
            VarList[(yyvsp[(3) - (3)].st)._Var.PLACE].addr = (yyvsp[(1) - (3)].st).First;

            struct node *last = get_last_node((yyvsp[(1) - (3)].st).trNode);
            add_brother_node(last, (yyvsp[(3) - (3)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (3)].st).trNode;
		}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 240 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st).First = (yyvsp[(1) - (1)].st)._Var.PLACE;
            VarList[(yyvsp[(1) - (1)].st)._Var.PLACE].addr = 0;

            (yyval.st).trNode = (yyvsp[(1) - (1)].st).trNode;
		}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 248 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st).CH = (yyvsp[(2) - (2)].st).CH;

            struct node *last = get_last_node((yyvsp[(1) - (2)].st).trNode);
            add_brother_node(last, (yyvsp[(2) - (2)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 256 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st).CH = (yyvsp[(1) - (1)].st).CH;

            (yyval.st).trNode = (yyvsp[(1) - (1)].st).trNode;
		}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 263 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

			// 多个语句之间通过分号分割
			backPatch((yyvsp[(1) - (2)].st).CH, NXQ);

            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 272 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 赋值语句是句子的一种
			(yyval.st).CH = 0;

			(yyval.st).trNode = (yyval.st).trNode;
		}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 279 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// If then Else语句是句子的一种
			(yyval.st).CH = merge((yyvsp[(1) - (2)].st).CH, (yyvsp[(2) - (2)].st).CH);

            add_son_node((yyvsp[(1) - (2)].st).trNode, (yyvsp[(2) - (2)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 287 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// If then语句是句子的一种
			(yyval.st).CH = merge((yyvsp[(1) - (2)].st).CH, (yyvsp[(2) - (2)].st).CH);

            add_son_node((yyvsp[(1) - (2)].st).trNode, (yyvsp[(2) - (2)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 296 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// While语句是句子的一种
			backPatch((yyvsp[(2) - (2)].st).CH, (yyvsp[(1) - (2)].st)._WBD.QUAD);
            gen("j", 0, 0, (yyvsp[(1) - (2)].st)._WBD.QUAD);
            (yyval.st).CH = (yyvsp[(1) - (2)].st)._WBD.CH;

            add_son_node((yyvsp[(1) - (2)].st).trNode, (yyvsp[(2) - (2)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 306 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// Begin End语句块
			(yyval.st).CH = (yyvsp[(1) - (1)].st).CH;

			(yyval.st).trNode = (yyvsp[(1) - (1)].st).trNode;
		}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 313 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            //For循环语句
            backPatch((yyvsp[(3) - (3)].st).CH,(yyvsp[(1) - (3)].st)._forloop.QUAD);
            gen("j",0,0,(yyvsp[(1) - (3)].st)._forloop.QUAD);
            (yyval.st).CH=(yyvsp[(1) - (3)].st).CH;

            add_son_node((yyvsp[(1) - (3)].st).trNode, (yyvsp[(3) - (3)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (3)].st).trNode;
        }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 322 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 327 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
            (yyval.st).CH = (yyvsp[(2) - (3)].st).CH;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_compstat;
            set_node_val_str((yyval.st).trNode, "begin_end");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (3)].st).trNode);
		}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 337 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
            (yyval.st).CH = (yyvsp[(2) - (4)].st).CH;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_compstat;
            set_node_val_str((yyval.st).trNode, "begin_end");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (4)].st).trNode);
  ;
		}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 349 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 赋值语句
			if (!(yyvsp[(1) - (4)].st)._Var.OFFSET)
			{
                gen(":=", (yyvsp[(4) - (4)].st)._Expr.place, 0, (yyvsp[(1) - (4)].st)._Var.PLACE);
            }
            else
            {
                gen("[]=", (yyvsp[(4) - (4)].st)._Expr.place, 0, (yyvsp[(1) - (4)].st)._Var.PLACE);
            }
            (yyvsp[(1) - (4)].st)._Expr.type=(yyvsp[(4) - (4)].st)._Expr.type;

            if (flag_var_def == 0)
            {
                char* s1="undefined variable:";
                char* s2=VarList[(yyvsp[(1) - (4)].st)._Var.PLACE].name;
                char *err = (char *) malloc(strlen(s1) + strlen(s2));
                strcpy(err,s1);
                strcat(err,s2);
                yyerror(err);

                /*printf("** undefined variable %s **", VarList[$1._Var.PLACE].name);
                exit(0);*/
            }

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_assign_stat;
            set_node_val_str((yyval.st).trNode, ":=");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (4)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(4) - (4)].st).trNode)
		;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 382 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// If Else语句
			int q = NXQ;
            gen("j", 0, 0, 0);
            backPatch((yyvsp[(1) - (3)].st).CH, NXQ);
            (yyval.st).CH = merge((yyvsp[(2) - (3)].st).CH, q);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_if_then_else_stat;
            set_node_val_str((yyval.st).trNode, "if_then_else");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (3)].st).trNode);
		}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 397 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// If Then 语句
			backPatch((yyvsp[(2) - (3)].st)._BExpr.TC, NXQ);
			(yyval.st).CH = (yyvsp[(2) - (3)].st)._BExpr.FC;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_if_then_stat;
            set_node_val_str((yyval.st).trNode, "if_then");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (3)].st).trNode);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 410 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// while循环
			backPatch((yyvsp[(2) - (3)].st)._BExpr.TC, NXQ);
            (yyval.st)._WBD.CH = (yyvsp[(2) - (3)].st)._BExpr.FC;
            (yyval.st)._WBD.QUAD = (yyvsp[(1) - (3)].st).CH;

            add_son_node((yyvsp[(1) - (3)].st).trNode, (yyvsp[(2) - (3)].st).trNode);
            (yyval.st).trNode = (yyvsp[(1) - (3)].st).trNode;
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 422 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 文法符号While对应关键字"while"
			(yyval.st).CH = NXQ;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_while_stat;
            set_node_val_str((yyval.st).trNode, "while");
        }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 433 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._BExpr.TC = NXQ;
            (yyval.st)._BExpr.FC = NXQ + 1;
            gen((yyvsp[(2) - (3)].st)._Rop, (yyvsp[(1) - (3)].st)._Expr.place, (yyvsp[(3) - (3)].st)._Expr.place, 0);
            gen("j", 0, 0, 0);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_bool_exp;
            set_node_val_str((yyval.st).trNode, &((yyvsp[(2) - (3)].st)._Rop[1]));
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(3) - (3)].st).trNode);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 446 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._BExpr.TC=(yyvsp[(2) - (2)].st)._BExpr.TC;
            (yyval.st)._BExpr.FC=merge((yyvsp[(1) - (2)].st)._BExpr.FC,(yyvsp[(2) - (2)].st)._BExpr.FC);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_bool_exp;
            set_node_val_str((yyval.st).trNode, "and");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (2)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (2)].st).trNode);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 457 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._BExpr.FC=(yyvsp[(2) - (2)].st)._BExpr.FC;
            (yyval.st)._BExpr.TC=merge((yyvsp[(1) - (2)].st)._BExpr.TC,(yyvsp[(2) - (2)].st)._BExpr.TC);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_bool_exp;
            set_node_val_str((yyval.st).trNode, "or");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (2)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (2)].st).trNode);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 468 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._BExpr.TC = (yyvsp[(2) - (2)].st)._BExpr.FC; (yyval.st)._BExpr.FC = (yyvsp[(2) - (2)].st)._BExpr.TC;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_bool_exp;
            set_node_val_str((yyval.st).trNode, "Not");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (2)].st).trNode);
		}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 477 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._BExpr.TC = (yyvsp[(2) - (3)].st)._BExpr.TC; (yyval.st)._BExpr.FC = (yyvsp[(2) - (3)].st)._BExpr.FC;

            (yyval.st).trNode = (yyvsp[(2) - (3)].st).trNode;
		}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 484 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            backPatch((yyvsp[(1) - (2)].st)._BExpr.TC, NXQ);
            (yyval.st)._BExpr.FC = (yyvsp[(1) - (2)].st)._BExpr.FC;

            (yyval.st).trNode = (yyvsp[(1) - (2)].st).trNode;
		}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 491 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            backPatch((yyvsp[(1) - (2)].st)._BExpr.FC,NXQ);
            (yyval.st)._BExpr.TC=(yyvsp[(1) - (2)].st)._BExpr.TC;

		}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 497 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = newTemp((yyvsp[(1) - (3)].st)._Expr.type);
            gen("+", (yyvsp[(1) - (3)].st)._Expr.place, (yyvsp[(3) - (3)].st)._Expr.place, (yyval.st)._Expr.place);
            (yyval.st)._Expr.type=(yyvsp[(1) - (3)].st)._Expr.type;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_exp;
            set_node_val_str((yyval.st).trNode, "+");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(3) - (3)].st).trNode);
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 509 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = newTemp((yyvsp[(1) - (3)].st)._Expr.type);
            gen("-", (yyvsp[(1) - (3)].st)._Expr.place, (yyvsp[(3) - (3)].st)._Expr.place, (yyval.st)._Expr.place);
            (yyval.st)._Expr.type=(yyvsp[(1) - (3)].st)._Expr.type;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_exp;
            set_node_val_str((yyval.st).trNode, "-");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(3) - (3)].st).trNode);
		}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 521 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = newTemp((yyvsp[(1) - (3)].st)._Expr.type);
            gen("*", (yyvsp[(1) - (3)].st)._Expr.place, (yyvsp[(3) - (3)].st)._Expr.place, (yyval.st)._Expr.place);
            (yyval.st)._Expr.type=(yyvsp[(1) - (3)].st)._Expr.type;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_exp;
            set_node_val_str((yyval.st).trNode, "*");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(3) - (3)].st).trNode);
		}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 533 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = newTemp((yyvsp[(1) - (3)].st)._Expr.type);
            gen("/", (yyvsp[(1) - (3)].st)._Expr.place, (yyvsp[(3) - (3)].st)._Expr.place, (yyval.st)._Expr.place);
            (yyval.st)._Expr.type=(yyvsp[(1) - (3)].st)._Expr.type;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_exp;
            set_node_val_str((yyval.st).trNode, "/");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (3)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(3) - (3)].st).trNode);
		}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 545 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = (yyvsp[(2) - (3)].st)._Expr.place;
            (yyval.st)._Expr.type=(yyvsp[(2) - (3)].st)._Expr.type;

            (yyval.st).trNode = (yyvsp[(2) - (3)].st).trNode;
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 552 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.place = newTemp((yyvsp[(2) - (2)].st)._Expr.type);
            (yyval.st)._Expr.type=(yyvsp[(2) - (2)].st)._Expr.type;

            gen("-", (yyvsp[(2) - (2)].st)._Expr.place, 0, (yyval.st)._Expr.place);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_exp;
            set_node_val_str((yyval.st).trNode, "-");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (2)].st).trNode);
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 564 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

            if (!(yyvsp[(1) - (1)].st)._Var.OFFSET)
            {
                (yyval.st)._Expr.place = (yyvsp[(1) - (1)].st)._Var.PLACE;
            }
            else
            {
                int T = newTemp((yyvsp[(1) - (1)].st)._Expr.type);
                gen("=[]", (yyvsp[(1) - (1)].st)._Var.PLACE, 0, T);
                (yyval.st)._Expr.place = T;
            }
            (yyval.st)._Expr.type=(yyvsp[(1) - (1)].st)._Expr.type;

            // undefined error
            if (flag_var_def == 0)
            {
                char* s1="undefined variable:";
                char* s2=VarList[(yyvsp[(1) - (1)].st)._Var.PLACE].name;
                char *err = (char *) malloc(strlen(s1) + strlen(s2));
                strcpy(err,s1);
                strcat(err,s2);
                yyerror(err);

                /*printf("** undefined variable %s **", VarList[$1._Var.PLACE].name);
                exit(0);*/
            }

            (yyval.st).trNode = (yyvsp[(1) - (1)].st).trNode;
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 596 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.type = (yyvsp[(1) - (1)].st)._Expr.type;
            (yyval.st)._Expr.place = (yyvsp[(1) - (1)].st)._Expr.place;
            if ((yyval.st)._Expr.type)
            {
                (yyval.st)._Expr.Value.Rv = (yyvsp[(1) - (1)].st)._Expr.Value.Rv;
            }
            else
            {
                (yyval.st)._Expr.Value.Iv = (yyvsp[(1) - (1)].st)._Expr.Value.Iv;
            }

            (yyval.st).trNode = (yyvsp[(1) - (1)].st).trNode;
		}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 613 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 文法符号Iden对应标识符，以字母或下划线开头后面是字母、数字或下划线组成的符号串
            if (lookUp(str1))
            {
                flag_var_def = 1;
                (yyval.st)._Expr.type=VarList[lookUp(str1)].type;
            }
            else
            {
                flag_var_def = 0;
            }
            (yyval.st)._Var.PLACE = entry(str1);
            (yyval.st)._Var.OFFSET = 0;


            new_node(&((yyval.st).trNode));
            set_node_val_str((yyval.st).trNode, str1);
		}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 632 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

			char Cstr[10], astr[10] = "ArrPtr";
			int T = newTemp((yyvsp[(1) - (2)].st)._Expr.type);

			gen("-", entry(astr), entry(Cstr),T);
			(yyval.st)._Elist.PLACE = T;
			(yyval.st)._Var.OFFSET = (yyvsp[(1) - (2)].st)._Elist.PLACE;
		}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 644 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.type = 0;
            (yyval.st)._Expr.place = entry(str1);
            VarList[(yyval.st)._Expr.place].type = 0;
            (yyval.st)._Expr.Value.Iv = atoi(str1);

            new_node(&((yyval.st).trNode));
            set_node_val_str((yyval.st).trNode, str1);
		}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 654 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            (yyval.st)._Expr.type = 1;
            (yyval.st)._Expr.place = entry(str1);
            VarList[(yyval.st)._Expr.place].type = 1;
            (yyval.st)._Expr.Value.Rv = (float)atof(str1);

            new_node(&((yyval.st).trNode));
            set_node_val_str((yyval.st).trNode, str1);
		}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 666 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 小于
			strcpy((yyval.st)._Rop, "j<");
		}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 671 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 大于
			strcpy((yyval.st)._Rop, "j>");
		}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 676 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 等于
			strcpy((yyval.st)._Rop, "j=");
		}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 681 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 文法符号GE对应大于等于，符号串为">=
			strcpy((yyval.st)._Rop, "j>=");
		}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 686 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 文法符号NE对应不等于，符号串为"<>""
			strcpy((yyval.st)._Rop, "j!=");
		}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 691 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			// 文法符号LE对应小于等于，符号串为"<=""
			strcpy((yyval.st)._Rop, "j<=");
		}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 698 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			//int NO = $1.NO;
			(yyval.st).NO = (yyvsp[(1) - (6)].st).First;

			/*while (NO)
			{
				FillArrMSG_C(NO);
				NO = VarList[NO].ADDR;
			}*/
		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 710 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

			int NO = (yyval.st).NO;
			int low = (yyvsp[(1) - (3)].st)._Expr.Value.Iv, high = (yyvsp[(3) - (3)].st)._Expr.Value.Iv;
			(yyval.st).NO = (yyvsp[(1) - (3)].st)._Expr.place;


			while (NO)
			{
                    VarList[NO].ADDR = malloc(sizeof(struct arr_info));
                    printf("error");
                    VarList[NO].ADDR->DIM = 1;
                    VarList[NO].ADDR->Vector = malloc(5*sizeof(int));
                    VarList[NO].ADDR->Vector[2] = low;
                    VarList[NO].ADDR->Vector[3] = high;
                    VarList[NO].ADDR->Vector[4] = (high - low) + 1;
                    VarList[NO].ADDR;
           }
		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 730 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

			/*int NO = $1.NO;

			int dim = VarList[NO].ADDR->DIM+1;

			int low = $3._Expr.Value.Iv, high = $5._Expr.Value.Iv;*/
			(yyval.st).NO = (yyvsp[(1) - (5)].st).NO;


			/*while (NO)
			{
                    VarList[NO].ADDR->DIM++;
                    VarList[NO].ADDR->Vector = realloc(VarList[NO].ADDR->Vector, (3 * dim + 2) * sizeof(int));
                    VarList[NO].ADDR->Vector[3*dim - 1] = low;
                    VarList[NO].ADDR->Vector[3*dim] = high;
                    VarList[NO].ADDR->Vector[3*dim + 1] = (high - low) + 1;
                    VarList[NO].ADDR;
            }*/

		}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 754 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
			(yyval.st)._Elist.PLACE = (yyvsp[(3) - (4)].st)._Expr.place;
			(yyval.st)._Elist.DIM = 1;

			(yyval.st)._Elist.NO = (yyvsp[(1) - (4)].st)._Var.PLACE;
		}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 761 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {

			char num[5];
			int k,d;
			int T = newTemp((yyvsp[(1) - (3)].st)._Expr.type);
			k = (yyvsp[(1) - (3)].st)._Elist.DIM + 1;
			//d = Access_d($1._Elist.NO, k);


			printf(num, "%d", d);
			gen("*", (yyvsp[(1) - (3)].st)._Elist.PLACE, entry(num), T);
			gen("+", (yyvsp[(3) - (3)].st)._Expr.place, T, T);
			(yyval.st)._Elist.NO = (yyvsp[(1) - (3)].st)._Elist.NO;
			(yyval.st)._Elist.PLACE = T;
			//$$._Elist.DIM = k;

		}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 781 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            gen("=",(yyvsp[(5) - (5)].st)._Expr.place,0,(yyvsp[(2) - (5)].st)._Var.PLACE);
            (yyval.st)._Expr.place=(yyvsp[(2) - (5)].st)._Var.PLACE;

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_forloop1_stat;
            set_node_val_str((yyval.st).trNode, ":=");
            add_son_node((yyval.st).trNode, (yyvsp[(2) - (5)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(5) - (5)].st).trNode);
		}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 792 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"
    {
            int p = NXQ;
            (yyval.st)._forloop.QUAD = NXQ;
            gen( "j≤", (yyvsp[(1) - (5)].st)._Expr.place,(yyvsp[(5) - (5)].st)._Expr.place,p+2);
            (yyval.st)._Expr.place=(yyvsp[(1) - (5)].st)._Expr.place;
            (yyval.st).CH=NXQ;
            gen( "j", 0, 0, 0);
            gen("+",(yyvsp[(1) - (5)].st)._Expr.place,(yyvsp[(3) - (5)].st)._Expr.place,(yyvsp[(1) - (5)].st)._Expr.place);

            new_node(&((yyval.st).trNode));
            (yyval.st).trNode->type = e_forloop2_stat;
            set_node_val_str((yyval.st).trNode, "for_step_until");
            add_son_node((yyval.st).trNode, (yyvsp[(1) - (5)].st).trNode);
            add_son_node((yyval.st).trNode, (yyvsp[(5) - (5)].st).trNode);
        }
    break;


/* Line 1792 of yacc.c  */
#line 2439 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 807 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"


int yyerror(char *errstr)
{
    printf("Syntax error: %s\n",errstr);

    exit(0);
}
