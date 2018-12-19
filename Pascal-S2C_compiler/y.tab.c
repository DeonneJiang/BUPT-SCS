
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "y.y"

    #include <cmath>
    #include <string>
	#include <cstring>
    #include <iostream>
    #include <vector>
	#include <stack>
	#include <map>
	#include <unordered_set>
	#include <fstream>
	#include <sstream>
    #include "dec.h"
	extern FILE* yyin;
	extern int yylineno;
    // std::string varout;
    int       yylex(void);
    void      yyerror(char const *);
	std::stack<symtabele> 	symtab;					//主符号表
	std::stack<symtabeleP> 	indextab;				//索引表
	std::map<std::string,typeAttri> customtypetab;	//全局自定义类型表
	std::map<std::string,funInfo> funtab;			//全局函数表
	std::map<std::string,paraInfo> protab;			//全剧过程表
	std::ofstream out;
    std::string record2struct(std::pair<std::string, typeAttri> recordin);
   


/* Line 189 of yacc.c  */
#line 101 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     RELOP = 260,
     TYPE = 261,
     PROGRAM = 262,
     PROCEDURE = 263,
     FUNCTION = 264,
     IF = 265,
     ELSE = 266,
     THEN = 267,
     CONST = 268,
     INTEGER = 269,
     BEGINpas = 270,
     END = 271,
     VAR = 272,
     WHILE = 273,
     REAL = 274,
     NOT = 275,
     TO = 276,
     UNTIL = 277,
     OF = 278,
     CHAR = 279,
     FOR = 280,
     BOOLEAN = 281,
     CASE = 282,
     DOWNTO = 283,
     ARRAY = 284,
     RECORD = 285,
     REPEAT = 286,
     OR = 287,
     MOD = 288,
     DIV = 289,
     AND = 290,
     DO = 291,
     COMMA = 292,
     SEMICOLON = 293,
     DOT = 294,
     COLON = 295,
     LEFTBRACKETS = 296,
     RIGHTBRACKETS = 297,
     LEFTSQUBRACKETS = 298,
     RIGHTSQUBRACKETS = 299,
     ASSIGNOP = 300,
     EQUSIGN = 301,
     PLUS = 302,
     MINUS = 303,
     DIVISION = 304,
     MULTIPLY = 305,
     LOWER_THAN_ELSE = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "y.y"

	terminalSAttriP 		terattrip;
	idlistAttriP			idlistattrip;
	typeAttrip				typeattrip;
	periodAttrip			periodattrip;
	periodsAttrip			periodsattrip;
	type_declarationAttrip 	type_declarationattrip;
	var_declarationAttrip 	var_declarationattrip;
	record_bodyAttrip		record_bodyattrip;
	id_varpartAttrip		id_varpartattrip;
	id_varpartsAttrip		id_varpartsattrip;
	expression_listAttrip	expression_listattrip;

	paraInfop				parainfop;		
	double					numer_val;
	TYPEKIND				typekind;
	strp					strAttri;
    int                     IINT;
    //std::string                  STRING;



/* Line 214 of yacc.c  */
#line 211 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 223 "y.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    14,    20,    24,    26,    30,    32,
      38,    42,    45,    48,    50,    53,    56,    58,    62,    64,
      70,    74,    76,    80,    87,    89,    91,    93,    95,    97,
      99,   103,   105,   110,   114,   116,   122,   128,   132,   136,
     140,   142,   145,   150,   157,   161,   163,   167,   169,   173,
     177,   181,   185,   187,   191,   193,   195,   200,   207,   213,
     218,   223,   232,   234,   237,   240,   242,   246,   249,   251,
     253,   257,   259,   263,   267,   269,   271,   276,   278,   280,
     284,   286,   290,   294,   296,   298,   301,   304,   308,   312,
     316,   318,   322,   326,   330,   334,   338,   340,   342,   347,
     351,   354
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    55,    39,    -1,     7,     3,    41,
      56,    42,    38,    -1,    57,    60,    67,    69,    76,    -1,
      56,    37,     3,    -1,     3,    -1,    13,    58,    38,    -1,
      93,    -1,    58,    38,     3,    46,    59,    -1,     3,    46,
      59,    -1,    47,     3,    -1,    48,     3,    -1,     3,    -1,
      47,     4,    -1,    48,     4,    -1,     4,    -1,     6,    61,
      38,    -1,    93,    -1,    61,    38,     3,    46,    62,    -1,
       3,    46,    62,    -1,    63,    -1,    30,    64,    16,    -1,
      29,    43,    65,    44,    23,    62,    -1,    14,    -1,    19,
      -1,    26,    -1,    24,    -1,    68,    -1,    93,    -1,    65,
      37,    66,    -1,    66,    -1,    59,    39,    39,    59,    -1,
      17,    68,    38,    -1,    93,    -1,    68,    38,    56,    40,
      62,    -1,    68,    38,    56,    40,     3,    -1,    56,    40,
      62,    -1,    56,    40,     3,    -1,    69,    70,    38,    -1,
      93,    -1,    71,    75,    -1,     8,     3,    72,    38,    -1,
       9,     3,    72,    40,    63,    38,    -1,    41,    73,    42,
      -1,    93,    -1,    73,    38,    74,    -1,    74,    -1,    56,
      40,    63,    -1,    57,    67,    76,    -1,    15,    77,    16,
      -1,    77,    38,    78,    -1,    78,    -1,    79,    45,    89,
      -1,    86,    -1,    76,    -1,    10,    89,    12,    78,    -1,
      10,    89,    12,    78,    11,    78,    -1,    27,    89,    23,
      82,    16,    -1,    18,    89,    36,    78,    -1,    31,    77,
      22,    89,    -1,    25,     3,    45,    89,    87,    89,    36,
      78,    -1,    93,    -1,     3,    80,    -1,    80,    81,    -1,
      93,    -1,    43,    88,    44,    -1,    39,     3,    -1,    83,
      -1,    93,    -1,    83,    38,    84,    -1,    84,    -1,    85,
      40,    78,    -1,    85,    37,    59,    -1,    59,    -1,     3,
      -1,     3,    41,    88,    42,    -1,    21,    -1,    28,    -1,
      88,    37,    89,    -1,    89,    -1,    90,     5,    90,    -1,
      90,    46,    90,    -1,    90,    -1,    91,    -1,    47,    91,
      -1,    48,    91,    -1,    90,    47,    91,    -1,    90,    48,
      91,    -1,    90,    32,    91,    -1,    92,    -1,    91,    50,
      92,    -1,    91,    49,    92,    -1,    91,    34,    92,    -1,
      91,    33,    92,    -1,    91,    35,    92,    -1,     4,    -1,
      79,    -1,     3,    41,    88,    42,    -1,    41,    89,    42,
      -1,    20,    92,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   151,   182,   192,   206,   219,   220,   224,
     237,   253,   274,   296,   318,   327,   336,   348,   349,   351,
     404,   454,   462,   471,   483,   484,   485,   486,   489,   500,
     508,   520,   531,   543,   559,   563,   682,   721,   839,   883,
     895,   899,   903,   949,  1020,  1028,  1036,  1047,  1058,  1071,
    1079,  1088,  1096,  1105,  1123,  1126,  1131,  1142,  1156,  1157,
    1167,  1168,  1219,  1225,  1290,  1300,  1308,  1316,  1326,  1327,
    1330,  1331,  1335,  1338,  1339,  1343,  1364,  1391,  1392,  1397,
    1406,  1418,  1437,  1447,  1455,  1460,  1468,  1476,  1485,  1494,
    1506,  1511,  1520,  1527,  1534,  1541,  1551,  1559,  1564,  1589,
    1596,  1604
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "RELOP", "TYPE", "PROGRAM",
  "PROCEDURE", "FUNCTION", "IF", "ELSE", "THEN", "CONST", "INTEGER",
  "BEGINpas", "END", "VAR", "WHILE", "REAL", "NOT", "TO", "UNTIL", "OF",
  "CHAR", "FOR", "BOOLEAN", "CASE", "DOWNTO", "ARRAY", "RECORD", "REPEAT",
  "OR", "MOD", "DIV", "AND", "DO", "COMMA", "SEMICOLON", "DOT", "COLON",
  "LEFTBRACKETS", "RIGHTBRACKETS", "LEFTSQUBRACKETS", "RIGHTSQUBRACKETS",
  "ASSIGNOP", "EQUSIGN", "PLUS", "MINUS", "DIVISION", "MULTIPLY",
  "LOWER_THAN_ELSE", "$accept", "programstruct", "program_head",
  "program_body", "idlist", "const_declarations", "const_declaration",
  "const_value", "type_declarations", "type_declaration", "type",
  "standard_type", "record_body", "periods", "period", "var_declarations",
  "var_declaration", "subprogram_declarations", "subprogram",
  "subprogram_head", "formal_parameter", "parameter_list", "parameter",
  "subprogram_body", "compound_statement", "statement_list", "statement",
  "variable", "id_varparts", "id_varpart", "case_body", "branch_list",
  "branch", "const_list", "procedure_call", "updown", "expression_list",
  "expression", "simple_expression", "term", "factor", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    74,    75,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,     5,     3,     1,     3,     1,     5,
       3,     2,     2,     1,     2,     2,     1,     3,     1,     5,
       3,     1,     3,     6,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     3,     1,     5,     5,     3,     3,     3,
       1,     2,     4,     6,     3,     1,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     4,     6,     5,     4,
       4,     8,     1,     2,     2,     1,     3,     2,     1,     1,
       3,     1,     3,     3,     1,     1,     4,     1,     1,     3,
       1,     3,     3,     1,     1,     2,     2,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     4,     3,
       2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   101,     0,     1,     0,     0,   101,     8,
       0,     0,     0,     2,     0,   101,    18,     6,     0,     0,
       7,     0,     0,     0,   101,    34,     0,     0,    13,    16,
       0,     0,    10,     0,     0,    17,     0,     0,     0,    40,
       5,     3,    11,    14,    12,    15,     0,    24,    25,    27,
      26,     0,   101,    20,    21,     0,     0,    33,     0,     0,
     101,     0,   101,     4,     9,     0,     0,    28,    29,     0,
      38,    37,     0,   101,   101,    75,     0,     0,     0,     0,
     101,    55,     0,    52,     0,    54,    62,    39,   101,    41,
       0,     0,    31,    22,     0,    19,     0,     0,     0,    45,
       0,     0,    63,    65,   101,    96,     0,     0,     0,     0,
      97,     0,    83,    84,    90,     0,     0,     0,     0,    50,
     101,     0,     0,     0,     0,     0,    36,    35,     0,     0,
      47,    42,     0,     0,    80,     0,     0,    64,     0,   100,
       0,    85,    86,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,   101,     0,    51,    53,
      49,     0,    30,     0,     0,     0,    44,     0,     0,    76,
      67,     0,     0,    99,    56,    81,    89,    82,    87,    88,
      94,    93,    95,    92,    91,    59,     0,    74,     0,    68,
      71,     0,    69,    60,    32,    23,    48,    46,    43,    79,
      66,    98,   101,    77,    78,     0,    58,     0,     0,   101,
      57,     0,    70,    73,    72,   101,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    36,     8,    12,    90,    15,    22,
      53,    54,    66,    91,    92,    24,    37,    38,    61,    62,
      98,   129,   130,    89,    81,    82,    83,   110,   102,   137,
     188,   189,   190,   191,    85,   205,   133,   134,   112,   113,
     114,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
      12,    60,    36,    61,    50,  -125,   129,    53,   147,  -125,
     160,   128,   137,  -125,   165,   159,  -125,  -125,    97,    19,
     174,   132,   141,   160,  -125,  -125,   177,   143,  -125,  -125,
      79,   169,  -125,   136,   122,   180,    13,   146,    88,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    19,  -125,  -125,  -125,
    -125,   142,   160,  -125,  -125,   140,    99,   160,   184,   187,
      90,   153,    61,  -125,  -125,    19,   176,   155,  -125,   122,
    -125,  -125,    93,   154,   154,    81,    21,    21,   191,    21,
      90,  -125,     4,  -125,   151,  -125,  -125,  -125,   159,  -125,
     158,   -26,  -125,  -125,   160,  -125,   135,   160,   161,  -125,
     162,    21,   123,  -125,   157,  -125,    11,    21,    11,    11,
    -125,   188,    33,    -5,  -125,   167,   156,   181,    17,  -125,
      90,    21,   190,   168,    19,   183,  -125,  -125,   107,    89,
    -125,  -125,    85,   103,  -125,   205,    21,  -125,    21,  -125,
     170,    -5,    -5,    90,    21,    11,    21,    11,    11,    11,
      11,    11,    11,    11,    90,    21,    19,    21,  -125,  -125,
    -125,    19,  -125,   122,    85,   160,  -125,   171,    21,  -125,
    -125,    34,   118,  -125,   199,     0,    -5,     0,    -5,    -5,
    -125,  -125,  -125,  -125,  -125,  -125,    91,  -125,   195,   175,
    -125,   130,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,    90,  -125,  -125,    21,  -125,    19,    19,    90,
    -125,   178,  -125,  -125,  -125,    90,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,    -8,   163,  -125,   -19,  -125,  -125,
     -53,  -124,  -125,  -125,    92,   127,   166,  -125,  -125,  -125,
     145,  -125,    52,  -125,   -34,   144,  -108,   -59,  -125,  -125,
    -125,  -125,    14,  -125,  -125,  -125,   -22,   -70,    25,   -75,
     -93,     2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
      32,    84,    18,    71,    63,     9,   111,   115,   167,   117,
      16,   124,   158,   139,   104,   105,    95,    25,   125,     1,
     119,    84,    28,    29,   104,   105,    39,    64,   149,   150,
     151,   106,   145,   141,   142,   174,     5,   140,   144,   157,
     196,   106,   120,   127,   152,   153,   185,   147,   148,    72,
      26,   159,   107,    56,    68,   120,   180,   181,   182,   183,
     184,    84,   107,     4,     9,   145,    30,    31,   108,   109,
     176,   168,   178,   179,     6,    99,    99,   103,   200,   146,
     147,   148,    42,    43,    84,   186,    72,   193,   160,   128,
      25,    10,    13,    75,   210,    84,    58,    59,   199,    47,
      76,   214,    70,    60,    48,    60,   103,   216,    77,    49,
     195,    50,   203,    47,   171,    78,   172,    79,    48,   204,
    -101,    80,   101,    49,  -101,    50,  -101,   165,    51,    52,
      26,   166,    11,    96,    26,   211,    47,   187,   126,    27,
     168,    48,   194,    84,    26,   169,    49,   164,    50,    47,
      84,    51,    52,    14,    48,   168,    84,   128,   192,    49,
     201,    50,   135,    17,    51,    52,   136,   208,    21,   175,
     209,   177,    44,    45,    19,    20,    23,    33,    34,    35,
      40,    41,    46,    55,    57,    65,    69,    73,   187,   213,
      74,    87,    93,    94,   116,    97,   121,   123,   138,   131,
     143,   155,   132,   154,   156,    60,   163,   161,   170,   198,
     202,   206,   173,   207,   215,   122,   162,   197,    67,   100,
       0,   212,     0,     0,   118,    88
};

static const yytype_int16 yycheck[] =
{
      19,    60,    10,    56,    38,     3,    76,    77,   132,    79,
       8,    37,   120,   106,     3,     4,    69,    15,    44,     7,
      16,    80,     3,     4,     3,     4,    24,    46,    33,    34,
      35,    20,    32,   108,   109,   143,     0,   107,     5,    22,
     164,    20,    38,    96,    49,    50,   154,    47,    48,    57,
      37,   121,    41,    40,    52,    38,   149,   150,   151,   152,
     153,   120,    41,     3,    62,    32,    47,    48,    47,    48,
     145,    37,   147,   148,    13,    73,    74,    75,    44,    46,
      47,    48,     3,     4,   143,   155,    94,   157,   122,    97,
      88,    41,    39,     3,   202,   154,     8,     9,   168,    14,
      10,   209,     3,    15,    19,    15,   104,   215,    18,    24,
     163,    26,    21,    14,   136,    25,   138,    27,    19,    28,
      39,    31,    41,    24,    43,    26,    45,    38,    29,    30,
      37,    42,     3,    40,    37,   205,    14,   156,     3,    42,
      37,    19,   161,   202,    37,    42,    24,    40,    26,    14,
     209,    29,    30,     6,    19,    37,   215,   165,   156,    24,
      42,    26,    39,     3,    29,    30,    43,    37,     3,   144,
      40,   146,     3,     4,    46,    38,    17,     3,    46,    38,
       3,    38,    46,     3,    38,    43,    46,     3,   207,   208,
       3,    38,    16,    38,     3,    41,    45,    39,    41,    38,
      12,    45,    40,    36,    23,    15,    23,    39,     3,    38,
      11,    16,    42,    38,    36,    88,   124,   165,    52,    74,
      -1,   207,    -1,    -1,    80,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    53,    54,     3,     0,    13,    55,    57,    93,
      41,     3,    58,    39,     6,    60,    93,     3,    56,    46,
      38,     3,    61,    17,    67,    93,    37,    42,     3,     4,
      47,    48,    59,     3,    46,    38,    56,    68,    69,    93,
       3,    38,     3,     4,     3,     4,    46,    14,    19,    24,
      26,    29,    30,    62,    63,     3,    40,    38,     8,     9,
      15,    70,    71,    76,    59,    43,    64,    68,    93,    46,
       3,    62,    56,     3,     3,     3,    10,    18,    25,    27,
      31,    76,    77,    78,    79,    86,    93,    38,    57,    75,
      59,    65,    66,    16,    38,    62,    40,    41,    72,    93,
      72,    41,    80,    93,     3,     4,    20,    41,    47,    48,
      79,    89,    90,    91,    92,    89,     3,    89,    77,    16,
      38,    45,    67,    39,    37,    44,     3,    62,    56,    73,
      74,    38,    40,    88,    89,    39,    43,    81,    41,    92,
      89,    91,    91,    12,     5,    32,    46,    47,    48,    33,
      34,    35,    49,    50,    36,    45,    23,    22,    78,    89,
      76,    39,    66,    23,    40,    38,    42,    63,    37,    42,
       3,    88,    88,    42,    78,    90,    91,    90,    91,    91,
      92,    92,    92,    92,    92,    78,    89,    59,    82,    83,
      84,    85,    93,    89,    59,    62,    63,    74,    38,    89,
      44,    42,    11,    21,    28,    87,    16,    38,    37,    40,
      78,    89,    84,    59,    78,    36,    78
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 145 "y.y"
    { 
									out.close();
								;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 152 "y.y"
    {
									//注：input和output暂时没有处理
                                	symtabele * tabelep = new symtabele();
                                	tabelep->name = (yyvsp[(2) - (6)].terattrip)->id_name;
                                	tabelep->kind = PROGRAMt;
                                	tabelep->constornot = false;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
                                	delete(tabelep);							//这delete的顺序不能随意改变
                                  	tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									/*-----以上为语义分析部分，已完成--------*/

									out << "#include <stdlib.h>\n";
									out << "#include <stdio.h>\n";
                                    out << "\n";
                                    out << "#define bool int\n";
                                    out << "#define true 1\n";
                                    out << "#define false 0\n";
                                    out << "\n";

								
                                    delete((yyvsp[(2) - (6)].terattrip));
									delete((yyvsp[(4) - (6)].idlistattrip));
                                ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 183 "y.y"
    {
									out << "int main()\n";
									out << "{\n";
									out << *((yyvsp[(5) - (5)].strAttri));
									out << "\nreturn 0;\n}";
								;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 193 "y.y"
    { 
									(yyval.idlistattrip) = new(idlistAttri);
                                  	for( auto & i: (yyvsp[(1) - (3)].idlistattrip)->ids ){
                                	 	(yyval.idlistattrip)->ids.push_back(i);
                                  	}
                                    (yyval.idlistattrip)->ids.push_back((yyvsp[(3) - (3)].terattrip)->id_name);
                                    //out << $3->id_name;

									/*-----以上为语义分析部分，已完成--------*/

									delete((yyvsp[(1) - (3)].idlistattrip));
									delete((yyvsp[(3) - (3)].terattrip));
                                ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 207 "y.y"
    {
									(yyval.idlistattrip) = new(idlistAttri);
									(yyval.idlistattrip)->ids.push_back((yyvsp[(1) - (1)].terattrip)->id_name);

									/*-----以上为语义分析部分，已完成--------*/
                                    //out << $1->id_name;

									delete((yyvsp[(1) - (1)].terattrip));
                                ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 225 "y.y"
    {
                                  	symtabele * tabelep = new symtabele();
                                	tabelep->name = (yyvsp[(3) - (5)].terattrip)->id_name;
                                	tabelep->kind = REALt;
                                	tabelep->constornot = true;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
									/*-----以上为语义分析部分，已完成--------*/
									 out << "const double " << (yyvsp[(3) - (5)].terattrip)->id_name << "=" << (yyvsp[(5) - (5)].numer_val) << ";\n";
                                    /*------代码生成部分------*/
                                    delete(tabelep);
                                ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 238 "y.y"
    {
                                  	symtabele * tabelep = new symtabele();
                                	tabelep->name = (yyvsp[(1) - (3)].terattrip)->id_name;
                                	tabelep->kind = REALt;
                                	tabelep->constornot = true;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "const double " << (yyvsp[(1) - (3)].terattrip)->id_name << "=" << (yyvsp[(3) - (3)].numer_val) << ";\n";
                                    /*------代码生成部分------*/


                                	delete(tabelep);
                                ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 254 "y.y"
    {
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == (yyvsp[(2) - (2)].terattrip)->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<(yyvsp[(2) - (2)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "+";
                                    //out << $2->id_name;
                                    /*------代码生成部分----有错误--*/
								;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 275 "y.y"
    {
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == (yyvsp[(2) - (2)].terattrip)->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<(yyvsp[(2) - (2)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "-";
                                    //out << $2->id_name;
                                    /*------代码生成部分------*/
                                    
								;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 297 "y.y"
    {
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == (yyvsp[(1) - (1)].terattrip)->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<(yyvsp[(1) - (1)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    
                                   // out << $1->id_name;
                                    /*------代码生成部分------*/
                                    
								;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 319 "y.y"
    { 
									(yyval.numer_val) = (yyvsp[(2) - (2)].terattrip)->val; 	
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "+";
                                    //out << $2->val;
                                    /*------代码生成部分------*/
                                    
								;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 328 "y.y"
    { 
									(yyval.numer_val) = -(yyvsp[(2) - (2)].terattrip)->val; 
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "-";
                                    //out << $2->val;
                                    /*------代码生成部分------*/
                                    
								;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 337 "y.y"
    { 
									(yyval.numer_val) = (yyvsp[(1) - (1)].terattrip)->val; 	
									/*-----以上为语义分析部分，完成--------*/
                                    //out << $1->val;
                                    /*------代码生成部分------*/
                                    
								;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 352 "y.y"
    {
									customtypetab.insert(std::pair<std::string,typeAttri>((yyvsp[(3) - (5)].terattrip)->id_name,*((yyvsp[(5) - (5)].typeattrip))));
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "typedef ";
                                    
                                    if( (yyvsp[(5) - (5)].typeattrip)->kind == RECORDt){
                                        out << record2struct(std::pair<std::string,typeAttri>((yyvsp[(3) - (5)].terattrip)->id_name,*((yyvsp[(5) - (5)].typeattrip)))) << "\n";}
                                    else if((yyvsp[(5) - (5)].typeattrip)->kind==INTEGERt)
                                    {
                                        out << "int " << (yyvsp[(3) - (5)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(5) - (5)].typeattrip)->kind==REALt)
                                    {
                                        out << "double " << (yyvsp[(3) - (5)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(5) - (5)].typeattrip)->kind==CHARt)
                                    {
                                        out << "char " << (yyvsp[(3) - (5)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(5) - (5)].typeattrip)->kind==BOOLEANt)
                                    {
                                        out << "bool " << (yyvsp[(3) - (5)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(5) - (5)].typeattrip)->kind==ARRAYt)
                                    {
                                        switch((yyvsp[(5) - (5)].typeattrip)->arraytp->kind){
                                            case INTEGER:
                                            out << "int ";
                                            break;
                                            case REALt:
                                            out << "double ";
                                            break;
                                            case CHARt:
                                            out << "char ";
                                            break;
                                            case BOOLEANt:
                                            out << "bool ";
                                            break;
                                        }
                                        out << (yyvsp[(3) - (5)].terattrip)->id_name << "[" << (yyvsp[(5) - (5)].typeattrip)->periods.size() << "]" <<";" << "\n";
                                        

                                    }



                                        //<< $5->kind << ";" << "\n";
                                    
                            
                                   /*-------代码生成部分-------*/
								;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 405 "y.y"
    {
									customtypetab.insert(std::pair<std::string,typeAttri>((yyvsp[(1) - (3)].terattrip)->id_name,*((yyvsp[(3) - (3)].typeattrip))));
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "typedef ";
                                    if( (yyvsp[(3) - (3)].typeattrip)->kind == RECORDt){
                                        out << record2struct(std::pair<std::string,typeAttri>((yyvsp[(1) - (3)].terattrip)->id_name,*((yyvsp[(3) - (3)].typeattrip)))) << "\n";}
                                    else if((yyvsp[(3) - (3)].typeattrip)->kind==INTEGERt)
                                    {
                                        out << "int " << (yyvsp[(1) - (3)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(3) - (3)].typeattrip)->kind==REALt)
                                    {
                                        out << "double " << (yyvsp[(1) - (3)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(3) - (3)].typeattrip)->kind==CHARt)
                                    {
                                        out << "char " << (yyvsp[(1) - (3)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(3) - (3)].typeattrip)->kind==BOOLEANt)
                                    {
                                        out << "bool " << (yyvsp[(1) - (3)].terattrip)->id_name << ";" << "\n";
                                    }
                                    else if((yyvsp[(3) - (3)].typeattrip)->kind==ARRAYt)
                                    {
                                        switch((yyvsp[(3) - (3)].typeattrip)->arraytp->kind){
                                            case INTEGER:
                                            out << "int ";
                                            break;
                                            case REALt:
                                            out << "double ";
                                            break;
                                            case CHARt:
                                            out << "char ";
                                            break;
                                            case BOOLEANt:
                                            out << "bool ";
                                            break;
                                        }
                                        out << (yyvsp[(1) - (3)].terattrip)->id_name << "[" << (yyvsp[(3) - (3)].typeattrip)->periods.size() << "]" << "\n";
                                    }
                                    

                                    
                                    
                                
                                    /*-------代码生成部分-------*/
								;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 455 "y.y"
    {
									(yyval.typeattrip) = new(typeAttri);
									(yyval.typeattrip)->kind = (yyvsp[(1) - (1)].typekind);
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*code generation*/
                            ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 463 "y.y"
    {
									(yyval.typeattrip) = new(typeAttri);
									(yyval.typeattrip)->kind = RECORDt;
									(yyval.typeattrip)->records = *(yyvsp[(2) - (3)].record_bodyattrip);
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*-------code generation-------*/
								;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 472 "y.y"
    {
									(yyval.typeattrip) = new(typeAttri);
									(yyval.typeattrip)->kind = ARRAYt;
									(yyval.typeattrip)->periods = *(yyvsp[(3) - (6)].periodsattrip);
									(yyval.typeattrip)->arraytp = (yyvsp[(6) - (6)].typeattrip);
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*-------code generation-------*/
								;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 483 "y.y"
    { (yyval.typekind) = INTEGERt	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 484 "y.y"
    { (yyval.typekind) = REALt	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 485 "y.y"
    { (yyval.typekind) = BOOLEANt ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 486 "y.y"
    { (yyval.typekind) = CHARt	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 490 "y.y"
    {
									(yyval.record_bodyattrip) = new(record_bodyAttri);
									//*($$) = *($1);
									*((yyval.record_bodyattrip)) = (yyvsp[(1) - (1)].var_declarationattrip)->var_declarationAttrimap;
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    //out << "struct{" << "\n";
                                    //out << "typedef" << " ";
                                    
																	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 501 "y.y"
    {
									(yyval.record_bodyattrip) = new(record_bodyAttri);
									/*-----以上为语义分析部分，已完成--------*/
									
								;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 509 "y.y"
    {
									(yyval.periodsattrip) = new(periodsAttri);
									for( auto &i : *((yyvsp[(1) - (3)].periodsattrip)) ){
										(yyval.periodsattrip)->push_back(i);
									}
									for( auto &i : *((yyvsp[(3) - (3)].periodattrip)) ){
										(yyval.periodsattrip)->push_back(i);
									}
									/*-----以上为语义分析部分，已完成--------*/
									
								;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 521 "y.y"
    {
									(yyval.periodsattrip) = new(periodsAttri);
									for( auto &i : *((yyvsp[(1) - (1)].periodattrip)) ){
                                    (yyval.periodsattrip)->push_back(i);
									}
									/*-----以上为语义分析部分，已完成--------*/
									
								;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 532 "y.y"
    {
									(yyval.periodattrip) = new(periodAttri);
									(yyval.periodattrip)->push_back((yyvsp[(1) - (4)].numer_val));
									(yyval.periodattrip)->push_back((yyvsp[(4) - (4)].numer_val));
									/*-----以上为语义分析部分，已完成--------*/
									
								;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 544 "y.y"
    {
									for( auto & i : (yyvsp[(2) - (3)].var_declarationattrip)->var_declarationAttrimap ){
										symtabele * tabelep = new symtabele();
                                    	tabelep->name = i.first;
                                		tabelep->kind = i.second->kind;
                                		tabelep->constornot = false;
                                		tabelep->tinfop = i.second;                                  
                                		symtab.push(*tabelep);
										
                                		delete(tabelep);
                                        
									}
									/*-----以上为语义分析部分，已完成--------*/
									out << (yyvsp[(2) - (3)].var_declarationattrip)->varout;
								;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 564 "y.y"
    {
									(yyval.var_declarationattrip) = new(var_declarationAttri);
									for( auto &i : (yyvsp[(1) - (5)].var_declarationattrip)->var_declarationAttrimap ){
										(yyval.var_declarationattrip)->var_declarationAttrimap.insert(i);
									}
									for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
										(yyval.var_declarationattrip)->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,(yyvsp[(5) - (5)].typeattrip)));
									}
									/*-----以上为语义分析部分，已完成--------*/

									(yyval.var_declarationattrip)->varout.append((yyvsp[(1) - (5)].var_declarationattrip)->varout);
									(yyval.var_declarationattrip)->varout.append("\n");

									switch( (yyvsp[(5) - (5)].typeattrip)->kind ){
										case INTEGERt:
											{
											(yyval.var_declarationattrip)->varout.append("int ");
											for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case REALt:
											{
											(yyval.var_declarationattrip)->varout.append("double ");
											for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case BOOLEANt:
											{
											(yyval.var_declarationattrip)->varout.append("bool ");
											for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case CHARt:
											{
											(yyval.var_declarationattrip)->varout.append("char ");
											for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										
										case RECORDt:
											{
                                                
                                                (yyval.var_declarationattrip)->varout.append(record2struct(std::pair<std::string,typeAttri>((yyvsp[(3) - (5)].idlistattrip)->ids[0],*((yyvsp[(5) - (5)].typeattrip)))) );//???
                                                (yyval.var_declarationattrip)->varout.append("\n");
                                            
											}
										break;
										case ARRAYt:
                                        {
                                            switch((yyvsp[(5) - (5)].typeattrip)->arraytp->kind){
                                                case INTEGERt:
                                                (yyval.var_declarationattrip)->varout.append("int ");
                                                break;
                                                case REALt:
                                                (yyval.var_declarationattrip)->varout.append("double ");
                                                break;
                                                case CHARt:
                                                (yyval.var_declarationattrip)->varout.append("char ");
                                                break;
                                                case BOOLEANt:
                                                (yyval.var_declarationattrip)->varout.append("bool");
                                                break;
                                            }
                                            for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids){
                                                (yyval.var_declarationattrip)->varout.append(i);
                                                (yyval.var_declarationattrip)->varout.append("[");
                                                //vector 容量表示
                                                int a1 = (int)((yyvsp[(5) - (5)].typeattrip)->periods)[1];
                                                std::stringstream ss11;
												a1++;
                                                ss11<<a1;
                                                std::string str1 = ss11.str();
                                                (yyval.var_declarationattrip)->varout.append(str1);
                                                (yyval.var_declarationattrip)->varout.append("]");
                                                (yyval.var_declarationattrip)->varout.append(",");//结构体表示？？？
                                            }
                                            auto tempiter = (yyval.var_declarationattrip)->varout.end();
                                            tempiter--;
                                            (yyval.var_declarationattrip)->varout.erase(tempiter);
                                            (yyval.var_declarationattrip)->varout.append(";");
                                            
                                        }
										break;
									}
                                    (yyval.var_declarationattrip)->varout.append("\n");


                                    //代码生成ddddd
								;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 683 "y.y"
    {
									(yyval.var_declarationattrip) = new(var_declarationAttri);
									for( auto &i : (yyvsp[(1) - (5)].var_declarationattrip)->var_declarationAttrimap ){
										(yyval.var_declarationattrip)->var_declarationAttrimap.insert(i);
									}
									//查全局的自定义类型表，把自定义类型的类型树
									/*-----以上为语义分析部分，完成--------*/
									auto iter = customtypetab.find((yyvsp[(5) - (5)].terattrip)->id_name);
									if( iter != customtypetab.end() ){
										
										for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
											(yyval.var_declarationattrip)->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,&((*iter).second)) );
										}
									}else{
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The type "<< '\'' <<(yyvsp[(5) - (5)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
                                
									/*-----以上为语义分析部分，完成--------*/
									
									(yyval.var_declarationattrip)->varout.append((yyvsp[(1) - (5)].var_declarationattrip)->varout);
									(yyval.var_declarationattrip)->varout.append("\n");

									(yyval.var_declarationattrip)->varout.append((yyvsp[(5) - (5)].terattrip)->id_name);

									(yyval.var_declarationattrip)->varout.append(" ");
									for( auto &i : (yyvsp[(3) - (5)].idlistattrip)->ids ){
										(yyval.var_declarationattrip)->varout.append(i);
										(yyval.var_declarationattrip)->varout.append(",");
									}
									auto tempiter = (yyval.var_declarationattrip)->varout.end();
									tempiter--;
									(yyval.var_declarationattrip)->varout.erase(tempiter);

									


                                    (yyval.var_declarationattrip)->varout.append(";\n\n");
                                ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 722 "y.y"
    {
									(yyval.var_declarationattrip) = new(var_declarationAttri);
									for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
										(yyval.var_declarationattrip)->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,(yyvsp[(3) - (3)].typeattrip)));
									}
									/*-----以上为语义分析部分，已完成--------*/
                                    
						

									switch( (yyvsp[(3) - (3)].typeattrip)->kind ){
										case INTEGERt:
											{
											(yyval.var_declarationattrip)->varout.append("int ");
											for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case REALt:
											{
											(yyval.var_declarationattrip)->varout.append("double ");
											for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case BOOLEANt:
											{
											(yyval.var_declarationattrip)->varout.append("bool ");
											for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										case CHARt:
											{
											(yyval.var_declarationattrip)->varout.append("char ");
											for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
												(yyval.var_declarationattrip)->varout.append(i);
												(yyval.var_declarationattrip)->varout.append(",");
											}
											auto tempiter = (yyval.var_declarationattrip)->varout.end();
											tempiter--;
											(yyval.var_declarationattrip)->varout.erase(tempiter);
											(yyval.var_declarationattrip)->varout.append(";");
											break;
											}
										
										case RECORDt:
											{
                                                (yyval.var_declarationattrip)->varout.append(record2struct(std::pair<std::string,typeAttri>((yyvsp[(1) - (3)].idlistattrip)->ids[0],*((yyvsp[(3) - (3)].typeattrip)))) );//???
                                                (yyval.var_declarationattrip)->varout.append("\n");
                                            }
										break;
										case ARRAYt:
                                        {
                                            switch((yyvsp[(3) - (3)].typeattrip)->arraytp->kind){
                                                case INTEGERt:
                                                (yyval.var_declarationattrip)->varout.append("int ");
                                                break;
                                                case REALt:
                                                (yyval.var_declarationattrip)->varout.append("double ");
                                                break;
                                                case CHARt:
                                                (yyval.var_declarationattrip)->varout.append("char ");
                                                break;
                                                case BOOLEANt:
                                                (yyval.var_declarationattrip)->varout.append("bool");
                                                break;
                                            }
                                            for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids){
                                                (yyval.var_declarationattrip)->varout.append(i);
                                                (yyval.var_declarationattrip)->varout.append("[");
                                                //vector 容量表示
                                                int a2 = (int)((yyvsp[(3) - (3)].typeattrip)->periods)[1];
												a2++;
                                                std::stringstream ss12;
                                                ss12<<a2;
                                                std::string str2 = ss12.str();
                                                (yyval.var_declarationattrip)->varout.append(str2);
                                                (yyval.var_declarationattrip)->varout.append("]");
                                                (yyval.var_declarationattrip)->varout.append(",");//结构体表示？？？
                                            }
                                            auto tempiter = (yyval.var_declarationattrip)->varout.end();
                                            tempiter--;
                                            (yyval.var_declarationattrip)->varout.erase(tempiter);
                                            (yyval.var_declarationattrip)->varout.append(";");
                                        }
										break;
									}
                                    (yyval.var_declarationattrip)->varout.append("\n");

                                 ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 840 "y.y"
    {
									(yyval.var_declarationattrip) = new(var_declarationAttri);
									//查全局的自定义类型表，把自定义类型的类型树
									
									auto iter = customtypetab.find((yyvsp[(3) - (3)].terattrip)->id_name);
									if( iter != customtypetab.end() ){
										
										for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
											(yyval.var_declarationattrip)->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,&((*iter).second)) );
										}
									}else{
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The type "<< '\'' <<(yyvsp[(3) - (3)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    
									(yyval.var_declarationattrip)->varout.append((yyvsp[(3) - (3)].terattrip)->id_name);

									(yyval.var_declarationattrip)->varout.append(" ");
									for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
										(yyval.var_declarationattrip)->varout.append(i);
										(yyval.var_declarationattrip)->varout.append(",");
									}
									auto tempiter = (yyval.var_declarationattrip)->varout.end();
									tempiter--;
									(yyval.var_declarationattrip)->varout.erase(tempiter);

									


                                    (yyval.var_declarationattrip)->varout.append(";\n\n");



                                    //代码生成
								;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 884 "y.y"
    {
									//释放块
									auto pointer = indextab.top();
									indextab.pop();
									while( &(symtab.top()) != pointer){
										symtab.pop();
                                        
									}
									symtab.pop();
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 904 "y.y"
    {
									symtabele * tabelep = new symtabele();
                                	tabelep->name = (yyvsp[(2) - (4)].terattrip)->id_name;
                                	tabelep->kind = PROCEDUREt;
                                	tabelep->constornot = false;
									tabelep->dimension = (yyvsp[(3) - (4)].parainfop)->size();
                                	tabelep->tinfop = NULL;
									tabelep->parainfop  =  (yyvsp[(3) - (4)].parainfop);                        
                                	symtab.push(*tabelep);
									tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									protab.insert(std::pair<std::string,paraInfo>((yyvsp[(2) - (4)].terattrip)->id_name,*(yyvsp[(3) - (4)].parainfop)));
									/*-----以上为语义分析部分，完成--------*/

									out << "void ";
									out << (yyvsp[(2) - (4)].terattrip)->id_name;
									out << "(";
									std::string tempstr;
									for( auto &i : *((yyvsp[(3) - (4)].parainfop)) ){
										switch(i.second){
											case REALt:
												tempstr.append("double ");
												break;
											case CHARt:
												tempstr.append("char ");
												break;
											case INTEGERt:
												tempstr.append("int ");
												break;
											case BOOLEANt:
												tempstr.append("bool ");
												break;
										}
										tempstr.append(i.first);
										tempstr.append(",");
									}
									auto eiter = tempstr.end();
									eiter--;
									tempstr.erase(eiter);
									out << tempstr;
									out << ")\n{\n";

								;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 950 "y.y"
    {
									symtabele * tabelep = new symtabele();
                                	tabelep->name = (yyvsp[(2) - (6)].terattrip)->id_name;
                                	tabelep->kind = FUNCTIONt;
                                	tabelep->constornot = false;
									tabelep->dimension = (yyvsp[(3) - (6)].parainfop)->size();
                                	tabelep->tinfop = NULL;
									tabelep->parainfop  =  (yyvsp[(3) - (6)].parainfop);
									tabelep->rekind = (yyvsp[(5) - (6)].typekind);                        
                                	symtab.push(*tabelep);
									tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									funInfop finfop = new(funInfo);
									finfop->returntype = (yyvsp[(5) - (6)].typekind);
									finfop->parainfo = *(yyvsp[(3) - (6)].parainfop);
									funtab.insert(std::pair<std::string,funInfo>((yyvsp[(2) - (6)].terattrip)->id_name,*finfop));
									delete finfop;
									/*-----以上为语义分析部分，完成--------*/


									switch((yyvsp[(5) - (6)].typekind)){
										case REALt:
										out << "double ";
										break;
										case CHARt:
										out << "char ";
										break;
										case INTEGERt:
										out << "int ";
										break;
										case BOOLEANt:
										out << "bool ";
										break;
									}
									out << (yyvsp[(2) - (6)].terattrip)->id_name;
									out << "(";
									std::string tempstr;
									for( auto &i : *((yyvsp[(3) - (6)].parainfop)) ){
										switch(i.second){
											case REALt:
												tempstr.append("double ");
												break;
											case CHARt:
												tempstr.append("char ");
												break;
											case INTEGERt:
												tempstr.append("int ");
												break;
											case BOOLEANt:
												tempstr.append("bool ");
												break;
										}
										tempstr.append(i.first);
										tempstr.append(",");
									}
									auto eiter = tempstr.end();
									eiter--;
									tempstr.erase(eiter);
									out << tempstr;
									out << ")\n{\n";



								;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1021 "y.y"
    {
									(yyval.parainfop) = new(paraInfo);
									for( auto &i : *((yyvsp[(2) - (3)].parainfop)) ){
										(yyval.parainfop)->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1029 "y.y"
    {
									(yyval.parainfop) = new(paraInfo);
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1037 "y.y"
    {
									(yyval.parainfop) = new(paraInfo);
									for( auto &i : *((yyvsp[(1) - (3)].parainfop)) ){
										(yyval.parainfop)->insert(i);
									}
									for( auto &i : *((yyvsp[(3) - (3)].parainfop)) ){
										(yyval.parainfop)->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1048 "y.y"
    {
									(yyval.parainfop) = new(paraInfo);
									for( auto &i : *((yyvsp[(1) - (1)].parainfop)) ){
										(yyval.parainfop)->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1059 "y.y"
    {
									(yyval.parainfop) = new(paraInfo);
									for( auto &i : (yyvsp[(1) - (3)].idlistattrip)->ids ){
										(yyval.parainfop)->insert(std::pair<std::string, TYPEKIND>(i,(yyvsp[(3) - (3)].typekind)));
									}
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1072 "y.y"
    {
									out << *((yyvsp[(3) - (3)].strAttri));
									out << "\n}\n";
								;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1080 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									*(yyval.strAttri)= *(yyvsp[(2) - (3)].strAttri);
								;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1089 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append("\n");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));

								;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1097 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1106 "y.y"
    {/*类型检查*/ 
									(yyval.strAttri) = new(std::string);
									auto iter = funtab.find(*(yyvsp[(1) - (3)].strAttri));
									if(  iter != funtab.end() ){
										(yyval.strAttri)->append("return ");
										(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
										(yyval.strAttri)->append(";");
									}else{
										(yyval.strAttri) = new(std::string);
										(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
										(yyval.strAttri)->append(" = ");
										(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
										(yyval.strAttri)->append(";");
									}

									
								;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1123 "y.y"
    {(yyval.strAttri) = new(std::string);
    (yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
    (yyval.strAttri)->append(";");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1127 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1132 "y.y"
    {
									/*类型检查*/ 
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append("if(");
									(yyval.strAttri)->append(*(yyvsp[(2) - (4)].strAttri));
									(yyval.strAttri)->append("){\n");
									(yyval.strAttri)->append(*(yyvsp[(4) - (4)].strAttri));
									(yyval.strAttri)->append("\n");
									(yyval.strAttri)->append("}");
								;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1143 "y.y"
    {
									/*类型检查*/
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append("if(");
									(yyval.strAttri)->append(*(yyvsp[(2) - (6)].strAttri));
									(yyval.strAttri)->append("){\n");
									(yyval.strAttri)->append(*(yyvsp[(4) - (6)].strAttri));
									(yyval.strAttri)->append("\n");
									(yyval.strAttri)->append("}");
									(yyval.strAttri)->append("else{\n");
									(yyval.strAttri)->append(*(yyvsp[(6) - (6)].strAttri));
									(yyval.strAttri)->append("\n}\n");
								;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1156 "y.y"
    {(yyval.strAttri) = new(std::string);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1158 "y.y"
    {
									/*类型检查*/ 
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append("while( ");
									(yyval.strAttri)->append(*(yyvsp[(2) - (4)].strAttri));
									(yyval.strAttri)->append(" ){\n");
									(yyval.strAttri)->append(*(yyvsp[(4) - (4)].strAttri));
									(yyval.strAttri)->append("\n}\n");
								;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1167 "y.y"
    { (yyval.strAttri) = new(std::string); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1169 "y.y"
    {/*类型检查*/
								
								
								(yyval.strAttri) = new(std::string);
								/*作用域检查*/
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == (yyvsp[(2) - (8)].terattrip)->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<(yyvsp[(2) - (8)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    (yyval.strAttri)->append("for");
                                    (yyval.strAttri)->append("(");
                                    (yyval.strAttri)->append((yyvsp[(2) - (8)].terattrip)->id_name);
                                    (yyval.strAttri)->append("=");
                                    (yyval.strAttri)->append(*(yyvsp[(4) - (8)].strAttri));
                                    (yyval.strAttri)->append(";");
                                    if((yyvsp[(5) - (8)].IINT)==0)
                                    {
                                        (yyval.strAttri)->append("<");
                                        (yyval.strAttri)->append(*(yyvsp[(6) - (8)].strAttri));
                                        (yyval.strAttri)->append(";");
                                        (yyval.strAttri)->append((yyvsp[(2) - (8)].terattrip)->id_name);
                                        (yyval.strAttri)->append("++");
                                    }
                                    else if ((yyvsp[(5) - (8)].IINT)==1)
                                    {
                                        
                                        (yyval.strAttri)->append(">");
                                        (yyval.strAttri)->append(*(yyvsp[(6) - (8)].strAttri));
                                        (yyval.strAttri)->append(";");
                                        (yyval.strAttri)->append((yyvsp[(2) - (8)].terattrip)->id_name);
                                        (yyval.strAttri)->append("--");

                                    }
                                    (yyval.strAttri)->append(")");
                                    (yyval.strAttri)->append("\n");
                                    (yyval.strAttri)->append("{");
                                    (yyval.strAttri)->append(*(yyvsp[(8) - (8)].strAttri));
                                    (yyval.strAttri)->append("}");
								;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1219 "y.y"
    { (yyval.strAttri) = new(std::string); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1226 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append((yyvsp[(1) - (2)].terattrip)->id_name);
									/*作用域检查*/
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == (yyvsp[(1) - (2)].terattrip)->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									//std::cout << "！！！！！ffffffffffffffffstruct decev \n";
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<(yyvsp[(1) - (2)].terattrip)->id_name << '\'' <<" has not been decleared yet.\n";
									}else{
										/*在这个地方进行数组维数检查，结构体成员变量检查*/
										//std::cout << "！！！！！ffdsfdsfgdffffffffstruct decev \n";
										//先进行结构体成员变量检查
										if( temps.top().kind  == RECORDt ){
											for( auto &i : (yyvsp[(2) - (2)].id_varpartsattrip)->ss){
												(yyval.strAttri)->append(".");
												(yyval.strAttri)->append(i);
											}
											//std::cout << "！！！！！struct decev \n";
											auto temppp = temps.top().tinfop;
											for( auto &i : (yyvsp[(2) - (2)].id_varpartsattrip)->ss){
												auto iter =  temppp->records.find(i);
												if( iter  != temppp->records.end() ){
													temppp = iter->second;
												}else{
													std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The member variables "<< '\'' << i << '\'' <<" has not been decleared yet.\n";
													break;
												}
											}
										}//结构体成员变量检查
										else{
											//std::cout << "！！！！！ffdsfdsfgdasdfasfdasfasdfasfasasdffffffffffstruct decev \n";
											if( temps.top().kind  == ARRAYt ){
												(yyval.strAttri)->append("[");
												for( auto &i : (yyvsp[(2) - (2)].id_varpartsattrip)->ss){
												(yyval.strAttri)->append(i);
												}
												(yyval.strAttri)->append("]");
												if( temps.top().tinfop->periods.size()/2 != (yyvsp[(2) - (2)].id_varpartsattrip)->dimension){
													std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The array variable "<< '\'' << (yyvsp[(1) - (2)].terattrip)->id_name << '\'' <<"\'s dimension is not correct.\n";
												}
											}//数组维数检查
										}
										

									}
									//std::cout << "！！！！hhhhhhhhhhhhhhhhhh！struct decev \n";

									/*-----以上为语义分析部分，完成--------*/

								;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1291 "y.y"
    {
									(yyval.id_varpartsattrip) = new(id_varpartsAttri);
									for( auto & i: (yyvsp[(1) - (2)].id_varpartsattrip)->ss ){
										(yyval.id_varpartsattrip)->ss.push_back(i);
									}
									(yyval.id_varpartsattrip)->ss.push_back((yyvsp[(2) - (2)].id_varpartattrip)->s);
									(yyval.id_varpartsattrip)->dimension = (yyvsp[(2) - (2)].id_varpartattrip)->dimension;
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1301 "y.y"
    {
									(yyval.id_varpartsattrip) = new(id_varpartsAttri);
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1309 "y.y"
    {
									(yyval.id_varpartattrip) = new(id_varpartAttri);
									(yyval.id_varpartattrip)->dimension = (yyvsp[(2) - (3)].expression_listattrip)->dimension;
									/*-----以上为语义分析部分，完成--------*/

									(yyval.id_varpartattrip)->s = (yyvsp[(2) - (3)].expression_listattrip)->outcode;
								;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1317 "y.y"
    {
									(yyval.id_varpartattrip) = new(id_varpartAttri);
									(yyval.id_varpartattrip)->s = (yyvsp[(2) - (2)].terattrip)->id_name;
									/*-----以上为语义分析部分，完成--------*/
								;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1344 "y.y"
    {
									auto iter1 = funtab.find((yyvsp[(1) - (1)].terattrip)->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find((yyvsp[(1) - (1)].terattrip)->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << (yyvsp[(1) - (1)].terattrip)->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != 0){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << (yyvsp[(1) - (1)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != 0){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << (yyvsp[(1) - (1)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/
                                    (yyval.strAttri)=new(std::string);
                                    (yyval.strAttri)->append((yyvsp[(1) - (1)].terattrip)->id_name);
								;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1365 "y.y"
    {
									auto iter1 = funtab.find((yyvsp[(1) - (4)].terattrip)->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find((yyvsp[(1) - (4)].terattrip)->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != (yyvsp[(3) - (4)].expression_listattrip)->dimension){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != (yyvsp[(3) - (4)].expression_listattrip)->dimension){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/
                                    (yyval.strAttri)=new(std::string);
                                    (yyval.strAttri)->append((yyvsp[(1) - (4)].terattrip)->id_name);
                                    (yyval.strAttri)->append("(");
                                    (yyval.strAttri)->append((yyvsp[(3) - (4)].expression_listattrip)->outcode);
                                    (yyval.strAttri)->append(")");
								;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1391 "y.y"
    {(yyval.IINT)=0;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1392 "y.y"
    {(yyval.IINT)=1;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1398 "y.y"
    {
									(yyval.expression_listattrip) = new(expression_listAttri);
									(yyval.expression_listattrip)->dimension = (yyvsp[(1) - (3)].expression_listattrip)->dimension  + 1;
									/*-----以上为语义分析部分，完成--------*/
									(yyval.expression_listattrip)->outcode.append((yyvsp[(1) - (3)].expression_listattrip)->outcode);
									(yyval.expression_listattrip)->outcode.append(",");
									(yyval.expression_listattrip)->outcode.append(*(yyvsp[(3) - (3)].strAttri))
								;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1407 "y.y"
    {
									(yyval.expression_listattrip) = new(expression_listAttri);
									(yyval.expression_listattrip)->dimension = 1;
									/*-----以上为语义分析部分，完成--------*/

									(yyval.expression_listattrip)->outcode.append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1419 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" ");
									if( strcmp((yyvsp[(2) - (3)].terattrip)->id_name.c_str(),"<") ){
										(yyval.strAttri)->append("<");
									}else if(strcmp((yyvsp[(2) - (3)].terattrip)->id_name.c_str(),">")){
										(yyval.strAttri)->append(">");
									}else if(strcmp((yyvsp[(2) - (3)].terattrip)->id_name.c_str(),"<=")){
										(yyval.strAttri)->append("<=");
									}else if(strcmp((yyvsp[(2) - (3)].terattrip)->id_name.c_str(),">=")){
										(yyval.strAttri)->append(">=");
									}else{//"<>"
										(yyval.strAttri)->append("!=");
									}
									(yyval.strAttri)->append(" ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
								;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1438 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" ");
									(yyval.strAttri)->append("==");
									(yyval.strAttri)->append(" ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));

								;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1447 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1456 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1461 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(" + ");
									(yyval.strAttri)->append(*(yyvsp[(2) - (2)].strAttri));
									//$$->append(")");
								;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1469 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(" - ");
									(yyval.strAttri)->append(*(yyvsp[(2) - (2)].strAttri));
									//$$->append(")");
								;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1477 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" + ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
									//$$->append(")");
								;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1486 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" - ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
									//$$->append(")");
								;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1495 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" || ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
									//$$->append(")");
								;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1507 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1512 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									//$$->append("(");
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" * ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
									//$$->append(" ) ");
								;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1521 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" / ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
								;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1528 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" / ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
								;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1535 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" % ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
								;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1542 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (3)].strAttri));
									(yyval.strAttri)->append(" && ");
									(yyval.strAttri)->append(*(yyvsp[(3) - (3)].strAttri));
								;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1552 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									std::ostringstream strstemp;
									strstemp << (yyvsp[(1) - (1)].terattrip)->val;
									std::string strnum = strstemp.str();
									(yyval.strAttri)->append(strnum);
								;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1560 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append(*(yyvsp[(1) - (1)].strAttri));
								;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1565 "y.y"
    {
									auto iter1 = funtab.find((yyvsp[(1) - (4)].terattrip)->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find((yyvsp[(1) - (4)].terattrip)->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != (yyvsp[(3) - (4)].expression_listattrip)->dimension){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != (yyvsp[(3) - (4)].expression_listattrip)->dimension){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << (yyvsp[(1) - (4)].terattrip)->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/

									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append((yyvsp[(1) - (4)].terattrip)->id_name);
									(yyval.strAttri)->append("(");
									(yyval.strAttri)->append((yyvsp[(3) - (4)].expression_listattrip)->outcode);
									(yyval.strAttri)->append(")");
								;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1590 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append("(");
									(yyval.strAttri)->append(*(yyvsp[(2) - (3)].strAttri));
									(yyval.strAttri)->append(")");
								;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1597 "y.y"
    {
									(yyval.strAttri) = new(std::string);
									(yyval.strAttri)->append("!");
									(yyval.strAttri)->append(*(yyvsp[(2) - (2)].strAttri));
								;}
    break;



/* Line 1455 of yacc.c  */
#line 3359 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 1606 "y.y"


#include <cctype>
#include <cstdio>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>



int main (int argc, char** argv)
{
	out.open("result.c",std::ios::out);
	if( argc <= 1 ){
		return yyparse ();
	}else{
		FILE * file = fopen (argv[1], "r");
		if( !file ){
			perror(argv[1]);
			return 1;
		}else{
			yyin = file;
			return yyparse();
		}
	}
}


/* Called by yyparse on error.  */

void yyerror (char const *s)
{
	std::cout << "line " << yylineno;
	fprintf (stderr, "%s\n", s);
}

std::string record2struct(std::pair<std::string, typeAttri> recordin) 
{
    std::string result;
    result.append("struct ");
    result.append(recordin.first);
    result.append(" {\n");
    for (auto &i : recordin.second.records) {
        
        switch ((i.second)->kind) {
            case REALt:
            result.append("double ");
            result.append(i.first);
            result.append(";\n");
            break;
            case CHARt:
            result.append("char ");
            result.append(i.first);
            result.append(";\n");
            break;
            case BOOLEANt:
            result.append("bool ");
            result.append(i.first);
            result.append(";\n");
            break;
            case INTEGERt:
            result.append("int ");
            result.append(i.first);
            result.append(";\n");
            break;
            case RECORDt:
            result.append(record2struct(std::pair<std::string, typeAttri>(i.first, *(i.second))));
            break;
            case ARRAYt:
            break;
        }
        
    }
    result.append("}");
    result.append(recordin.first);
    result.append(";\n");
    return result;
}


