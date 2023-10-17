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
#line 1 "kim.y"

#define YYSTYPE_IS_DECLARED  1
#define LIT_MAX 100 //sem
#include "type.h"

extern char* yytext;
int line_no=1;
int syntax_err=0;
A_NODE *root;
A_ID *current_id=NIL;
int current_level=0;
A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;

//sem
int global_address=12;
int semantic_err=0;
A_LITERAL literal_table[LIT_MAX];
int literal_no=0;
int literal_size=0;

//gen
int label_no=0;
int gen_err=0;


#line 96 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    FLOAT_CONSTANT = 258,
    STRING_LITERAL = 259,
    IDENTIFIER = 260,
    CHARACTER_CONSTANT = 261,
    TYPE_IDENTIFIER = 262,
    INTEGER_CONSTANT = 263,
    PLUS = 264,
    MINUS = 265,
    PLUSPLUS = 266,
    MINUSMINUS = 267,
    AMP = 268,
    BARBAR = 269,
    AMPAMP = 270,
    ARROW = 271,
    SEMICOLON = 272,
    LSS = 273,
    GTR = 274,
    LEQ = 275,
    GEQ = 276,
    EQL = 277,
    NEQ = 278,
    DOTDOTDOT = 279,
    LP = 280,
    RP = 281,
    LB = 282,
    RB = 283,
    LR = 284,
    RR = 285,
    PERIOD = 286,
    COMMA = 287,
    EXCL = 288,
    STAR = 289,
    SLASH = 290,
    PERCENT = 291,
    ASSIGN = 292,
    COLON = 293,
    AUTO_SYM = 294,
    STATIC_SYM = 295,
    TYPEDEF_SYM = 296,
    STRUCT_SYM = 297,
    ENUM_SYM = 298,
    SIZEOF_SYM = 299,
    UNION_SYM = 300,
    IF_SYM = 301,
    ELSE_SYM = 302,
    WHILE_SYM = 303,
    DO_SYM = 304,
    FOR_SYM = 305,
    CONTINUE_SYM = 306,
    BREAK_SYM = 307,
    RETURN_SYM = 308,
    SWITCH_SYM = 309,
    CASE_SYM = 310,
    DEFAULT_SYM = 311
  };
#endif
/* Tokens.  */
#define FLOAT_CONSTANT 258
#define STRING_LITERAL 259
#define IDENTIFIER 260
#define CHARACTER_CONSTANT 261
#define TYPE_IDENTIFIER 262
#define INTEGER_CONSTANT 263
#define PLUS 264
#define MINUS 265
#define PLUSPLUS 266
#define MINUSMINUS 267
#define AMP 268
#define BARBAR 269
#define AMPAMP 270
#define ARROW 271
#define SEMICOLON 272
#define LSS 273
#define GTR 274
#define LEQ 275
#define GEQ 276
#define EQL 277
#define NEQ 278
#define DOTDOTDOT 279
#define LP 280
#define RP 281
#define LB 282
#define RB 283
#define LR 284
#define RR 285
#define PERIOD 286
#define COMMA 287
#define EXCL 288
#define STAR 289
#define SLASH 290
#define PERCENT 291
#define ASSIGN 292
#define COLON 293
#define AUTO_SYM 294
#define STATIC_SYM 295
#define TYPEDEF_SYM 296
#define STRUCT_SYM 297
#define ENUM_SYM 298
#define SIZEOF_SYM 299
#define UNION_SYM 300
#define IF_SYM 301
#define ELSE_SYM 302
#define WHILE_SYM 303
#define DO_SYM 304
#define FOR_SYM 305
#define CONTINUE_SYM 306
#define BREAK_SYM 307
#define RETURN_SYM 308
#define SWITCH_SYM 309
#define CASE_SYM 310
#define DEFAULT_SYM 311

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    59,    60,    63,    64,    67,    67,    69,
      69,    73,    74,    77,    78,    81,    84,    85,    86,    87,
      90,    91,    92,    95,    96,    99,   100,   103,   104,   107,
     108,   111,   112,   115,   116,   117,   121,   122,   120,   125,
     125,   125,   128,   132,   133,   136,   137,   140,   144,   145,
     148,   152,   151,   154,   154,   156,   160,   161,   164,   167,
     166,   171,   172,   175,   176,   179,   180,   181,   183,   183,
     189,   190,   193,   194,   197,   198,   201,   203,   207,   208,
     211,   212,   213,   217,   218,   220,   222,   224,   228,   229,
     232,   233,   236,   237,   238,   239,   240,   241,   244,   245,
     248,   248,   254,   255,   258,   259,   260,   263,   264,   265,
     268,   271,   272,   275,   276,   277,   280,   281,   284,   286,
     290,   291,   294,   297,   300,   303,   304,   307,   310,   311,
     314,   315,   318,   321,   324,   327,   328,   329,   332,   333,
     334,   335,   336,   339,   342,   343,   344,   347,   348,   349,
     350,   353,   354,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   369,   370,   371,   372,   373,   374,   375,
     378,   379,   380,   381,   382,   383,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT_CONSTANT", "STRING_LITERAL",
  "IDENTIFIER", "CHARACTER_CONSTANT", "TYPE_IDENTIFIER",
  "INTEGER_CONSTANT", "PLUS", "MINUS", "PLUSPLUS", "MINUSMINUS", "AMP",
  "BARBAR", "AMPAMP", "ARROW", "SEMICOLON", "LSS", "GTR", "LEQ", "GEQ",
  "EQL", "NEQ", "DOTDOTDOT", "LP", "RP", "LB", "RB", "LR", "RR", "PERIOD",
  "COMMA", "EXCL", "STAR", "SLASH", "PERCENT", "ASSIGN", "COLON",
  "AUTO_SYM", "STATIC_SYM", "TYPEDEF_SYM", "STRUCT_SYM", "ENUM_SYM",
  "SIZEOF_SYM", "UNION_SYM", "IF_SYM", "ELSE_SYM", "WHILE_SYM", "DO_SYM",
  "FOR_SYM", "CONTINUE_SYM", "BREAK_SYM", "RETURN_SYM", "SWITCH_SYM",
  "CASE_SYM", "DEFAULT_SYM", "$accept", "program", "translation_unit",
  "external_declaration", "function_definition", "@1", "@2",
  "declaration_list_opt", "declaration_list", "declaration",
  "declaration_specifiers", "storage_class_specifier",
  "init_declarator_list_opt", "init_declarator_list", "init_declarator",
  "initializer", "initializer_list", "type_specifier", "struct_specifier",
  "@3", "@4", "@5", "@6", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "enum_specifier", "@7", "@8", "enumerator_list", "enumerator", "@9",
  "declarator", "pointer", "direct_declarator", "@10",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator",
  "statement_list_opt", "statement_list", "statement", "labeled_statement",
  "compound_statement", "@11", "expression_statement",
  "selection_statement", "iteration_statement", "for_expression",
  "expression_opt", "jump_statement", "arg_expression_list_opt",
  "arg_expression_list", "constant_expression_opt", "constant_expression",
  "expression", "comma_expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "bitwise_or_expression",
  "bitwise_xor_expression", "bitwise_and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "type_name", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     391,  -220,  -220,    26,    -7,  -220,  -220,  -220,  -220,    27,
    -220,    44,   391,  -220,  -220,  -220,    26,   239,   239,  -220,
      60,  -220,  -220,    24,     3,    49,  -220,    52,    65,  -220,
    -220,    93,    84,  -220,    63,  -220,  -220,   108,   113,   141,
       3,  -220,    30,  -220,   144,   119,  -220,    26,   314,   141,
     176,  -220,  -220,  -220,   239,  -220,  -220,  -220,  -220,  -220,
      30,    30,   351,   351,    30,   173,    30,    30,   369,   181,
    -220,  -220,  -220,  -220,  -220,   197,   206,  -220,  -220,  -220,
      39,   114,  -220,   131,    71,  -220,   185,   208,  -220,   119,
     193,    67,  -220,  -220,   195,   314,  -220,  -220,  -220,  -220,
      43,   239,    42,   211,  -220,   191,  -220,  -220,  -220,  -220,
      30,  -220,  -220,  -220,    53,   212,   219,  -220,  -220,   173,
    -220,  -220,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,  -220,  -220,   243,    30,
      30,   244,    91,   230,  -220,   119,  -220,    95,    43,    26,
     121,  -220,   260,   239,  -220,    26,   381,    30,  -220,    66,
    -220,  -220,   172,  -220,   186,   104,   177,  -220,  -220,    30,
     248,   206,  -220,   114,   114,  -220,  -220,  -220,  -220,    71,
      71,  -220,  -220,  -220,  -220,  -220,   249,   251,  -220,   258,
    -220,  -220,    30,  -220,  -220,   314,   129,     5,  -220,  -220,
    -220,  -220,  -220,   262,   263,   260,   265,   259,   274,    30,
     267,    30,   257,   266,   260,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,   281,  -220,   273,   275,   272,   172,   239,    30,
    -220,  -220,  -220,  -220,  -220,    30,  -220,  -220,  -220,  -220,
    -220,    26,    30,    30,   254,    30,  -220,  -220,   286,  -220,
      30,   269,   260,  -220,  -220,  -220,  -220,  -220,  -220,   279,
     293,  -220,  -220,   302,   303,   305,   306,   316,  -220,   308,
     260,  -220,  -220,  -220,   260,   260,    30,   260,    30,   260,
    -220,   284,  -220,   309,  -220,   319,  -220,   260,   320,    30,
    -220,  -220,  -220
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,    35,     0,    63,    20,    21,    22,    43,    53,
      44,     0,     2,     3,     5,     6,    23,    17,    16,    33,
      39,    34,     9,     0,    62,     0,    64,    55,     0,     1,
       4,     0,    24,    25,    27,    19,    18,    42,     0,     0,
      61,    68,   120,    66,     0,     0,    15,     0,     0,     0,
       0,    40,   100,    10,    70,   172,   174,   170,   173,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   127,   128,   130,   132,   133,
     134,   135,   138,   143,   144,   147,   151,   153,   163,     0,
      58,     0,    56,    26,    27,     0,    28,    29,     8,    37,
       0,    11,    78,     0,    71,    72,    74,   160,   151,   159,
       0,   154,   155,   156,    78,     0,     0,   158,   157,     0,
     161,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,     0,   116,
       0,     0,     0,     0,    54,     0,    31,     0,     0,     0,
       0,    45,    88,    12,    13,    23,    70,   120,    76,    80,
      77,    79,    81,    69,     0,    70,    80,   176,   175,     0,
       0,   129,   131,   136,   137,   139,   140,   141,   142,   145,
     146,   148,   149,   150,   126,   167,     0,   117,   118,     0,
     166,    52,     0,    57,    30,     0,     0,     0,    48,    50,
      41,    46,   102,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,    89,    90,    92,    93,    94,    95,
      96,    97,     0,    14,     0,     0,     0,    82,    70,   120,
      73,    75,   152,   162,   165,     0,   164,    60,    32,    38,
      47,     0,     0,     0,     0,   111,   114,   115,     0,   112,
       0,     0,     0,   101,    91,   103,    86,    83,    84,     0,
       0,   119,    49,     0,     0,     0,     0,     0,   113,     0,
       0,    99,    87,    85,     0,     0,     0,     0,   111,     0,
      98,   104,   107,     0,   109,     0,   106,     0,     0,   111,
     105,   108,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,   326,  -220,  -220,  -220,  -220,  -220,   -80,
       7,  -220,  -220,  -220,   294,   -83,  -220,   -92,  -220,  -220,
    -220,  -220,  -220,  -220,   192,  -130,  -220,   101,  -220,  -220,
    -220,   255,   200,  -220,    -1,     0,   -20,  -220,   -53,  -220,
    -220,   182,   235,  -111,   -63,  -220,  -220,  -157,  -220,    40,
    -220,  -220,  -220,  -220,  -220,  -219,  -220,  -220,  -220,  -139,
     -43,   -42,  -220,  -126,  -220,  -220,   228,   229,  -220,  -220,
    -220,    33,   115,  -220,    31,   -50,   128,  -220,  -220,   232
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    49,    39,   152,   153,    15,
     102,    17,    31,    32,    33,    96,   147,    18,    19,    50,
     148,    38,   100,    20,   150,   151,   197,   198,    21,    44,
      28,    91,    92,   143,    22,    23,    24,    54,   224,   104,
     105,   106,   160,   161,   162,   213,   214,   215,   216,   217,
     101,   218,   219,   220,   266,   248,   221,   186,   187,    69,
      70,   222,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   103,    25,    40,    26,    97,    71,    16,   149,   184,
     107,   109,   146,   188,   113,    34,   117,   118,   226,    16,
     201,   154,   240,   115,    35,    36,   267,     4,    41,     1,
      42,     1,    27,    55,    56,    57,    58,   241,    59,    60,
      61,    62,    63,    64,    29,   225,    94,     1,   244,     3,
       2,     3,    97,    71,   225,    65,   149,   254,   149,   285,
       4,   124,   125,    66,    67,    37,   201,   156,   115,   157,
     292,     1,   114,   223,    68,    43,     4,   115,   165,    53,
     157,   -51,   181,   182,   183,     8,     9,     4,    10,    98,
     260,   156,    -7,   157,    45,   271,   227,   144,   189,   145,
      48,   158,   159,   227,   149,   132,   133,   134,   155,   261,
      46,     2,   238,   280,   166,    71,    47,   281,   282,   232,
     284,   191,   286,   145,    90,   194,   114,   195,     2,   165,
     290,   157,   126,   127,   128,   129,     2,   -36,     4,    40,
     130,   131,    51,     5,     6,     7,     8,     9,   199,    10,
     237,   200,    97,    71,    94,    25,   159,   173,   174,   239,
     155,   179,   180,     8,     9,   166,    10,   249,   251,    71,
      52,     8,     9,    89,    10,   259,    55,    56,    57,    58,
       2,    59,    60,    61,    62,    63,    64,    71,   108,   108,
     111,   112,   108,     2,   108,   108,   120,   228,    65,   229,
     263,   264,   165,   249,   157,    99,    66,    67,   269,   121,
     230,   122,     5,     6,     7,     8,     9,    68,    10,   136,
     137,   123,   135,   164,   138,     5,     6,     7,     8,     9,
     -59,    10,    48,   139,   283,   140,   249,   163,   168,   141,
     199,   175,   176,   177,   178,   169,     2,   249,   185,   190,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    55,    56,    57,    58,   192,    59,    60,
      61,    62,    63,    64,   233,   234,   246,   202,     5,     6,
       7,     8,     9,   235,    10,    65,   236,   242,   243,    52,
     245,   247,   250,    66,    67,   252,   253,   108,   255,   256,
     258,   257,   265,   268,    68,   272,   203,   270,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    55,    56,    57,
      58,   273,    59,    60,    61,    62,    63,    64,   274,   275,
     276,   287,   277,   278,   279,   288,   289,   291,    30,    65,
     196,    93,   262,    95,   142,   193,   231,    66,    67,   167,
     171,   170,   172,     0,    55,    56,    57,    58,    68,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,   110,    59,    60,    61,
      62,    63,    64,     0,    66,    67,     1,     0,     2,     0,
       0,     0,     0,     0,   119,    68,     1,     0,     2,     0,
       0,     0,    66,    67,     0,     0,   156,     0,   157,     0,
       0,     0,     0,    68,     0,     4,     3,     0,     0,     0,
       5,     6,     7,     8,     9,     4,    10,     0,     0,     0,
       5,     6,     7,     8,     9,     0,    10
};

static const yytype_int16 yycheck[] =
{
      42,    54,     3,    23,     4,    48,    48,     0,   100,   135,
      60,    61,    95,   139,    64,    16,    66,    67,   157,    12,
     150,   101,    17,    65,    17,    18,   245,    34,    25,     5,
      27,     5,     5,     3,     4,     5,     6,    32,     8,     9,
      10,    11,    12,    13,     0,   156,    47,     5,   205,    25,
       7,    25,    95,    95,   165,    25,   148,   214,   150,   278,
      34,    22,    23,    33,    34,     5,   196,    25,   110,    27,
     289,     5,    65,   153,    44,    26,    34,   119,    25,    39,
      27,    29,   132,   133,   134,    42,    43,    34,    45,    49,
     229,    25,    29,    27,    29,   252,   159,    30,   140,    32,
      37,   102,   102,   166,   196,    34,    35,    36,   101,   235,
      17,     7,   195,   270,   114,   157,    32,   274,   275,   169,
     277,    30,   279,    32,     5,    30,   119,    32,     7,    25,
     287,    27,    18,    19,    20,    21,     7,    29,    34,   159,
       9,    10,    29,    39,    40,    41,    42,    43,   149,    45,
     192,    30,   195,   195,   155,   156,   156,   124,   125,    30,
     153,   130,   131,    42,    43,   165,    45,   209,   211,   211,
      29,    42,    43,    29,    45,   228,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   229,    60,    61,
      62,    63,    64,     7,    66,    67,    68,    25,    25,    27,
     242,   243,    25,   245,    27,    29,    33,    34,   250,    28,
      24,    14,    39,    40,    41,    42,    43,    44,    45,    11,
      12,    15,    37,    32,    16,    39,    40,    41,    42,    43,
      37,    45,    37,    25,   276,    27,   278,    26,    26,    31,
     241,   126,   127,   128,   129,    26,     7,   289,     5,     5,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     3,     4,     5,     6,    37,     8,     9,
      10,    11,    12,    13,    26,    26,    17,    17,    39,    40,
      41,    42,    43,    32,    45,    25,    28,    25,    25,    29,
      25,    17,    25,    33,    34,    38,    30,   169,    17,    26,
      28,    26,    48,    17,    44,    26,    46,    38,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     3,     4,     5,
       6,    28,     8,     9,    10,    11,    12,    13,    26,    26,
      25,    47,    26,    17,    26,    26,    17,    17,    12,    25,
     148,    47,   241,    29,    89,   145,   164,    33,    34,   114,
     122,   119,   123,    -1,     3,     4,     5,     6,    44,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    25,     8,     9,    10,
      11,    12,    13,    -1,    33,    34,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    25,    44,     5,    -1,     7,    -1,
      -1,    -1,    33,    34,    -1,    -1,    25,    -1,    27,    -1,
      -1,    -1,    -1,    44,    -1,    34,    25,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    34,    45,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    25,    34,    39,    40,    41,    42,    43,
      45,    58,    59,    60,    61,    66,    67,    68,    74,    75,
      80,    85,    91,    92,    93,    91,    92,     5,    87,     0,
      60,    69,    70,    71,    91,    67,    67,     5,    78,    63,
      93,    25,    27,    26,    86,    29,    17,    32,    37,    62,
      76,    29,    29,   106,    94,     3,     4,     5,     6,     8,
       9,    10,    11,    12,    13,    25,    33,    34,    44,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    29,
       5,    88,    89,    71,    91,    29,    72,   117,   106,    29,
      79,   107,    67,    95,    96,    97,    98,   132,   133,   132,
      25,   133,   133,   132,    67,   118,   136,   132,   132,    25,
     133,    28,    14,    15,    22,    23,    18,    19,    20,    21,
       9,    10,    34,    35,    36,    37,    11,    12,    16,    25,
      27,    31,    88,    90,    30,    32,    72,    73,    77,    74,
      81,    82,    64,    65,    66,    67,    25,    27,    91,    92,
      99,   100,   101,    26,    32,    25,    92,    99,    26,    26,
     136,   123,   124,   128,   128,   129,   129,   129,   129,   131,
     131,   132,   132,   132,   120,     5,   114,   115,   120,   118,
       5,    30,    37,    89,    30,    32,    81,    83,    84,    91,
      30,    82,    17,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   102,   103,   104,   105,   106,   108,   109,
     110,   113,   118,    66,    95,   100,   116,   101,    25,    27,
      24,    98,   132,    26,    26,    32,    28,   118,    72,    30,
      17,    32,    25,    25,   104,    25,    17,    17,   112,   118,
      25,   117,    38,    30,   104,    17,    26,    26,    28,    95,
     116,   120,    84,   118,   118,    48,   111,   112,    17,   118,
      38,   104,    26,    28,    26,    26,    25,    26,    17,    26,
     104,   104,   104,   118,   104,   112,   104,    47,    26,    17,
     104,    17,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    62,    61,    63,
      61,    64,    64,    65,    65,    66,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    76,    77,    75,    78,
      79,    75,    75,    80,    80,    81,    81,    82,    83,    83,
      84,    86,    85,    87,    85,    85,    88,    88,    89,    90,
      89,    91,    91,    92,    92,    93,    93,    93,    94,    93,
      95,    95,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   105,   105,
     107,   106,   108,   108,   109,   109,   109,   110,   110,   110,
     111,   112,   112,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   118,   119,   120,   120,   121,   122,   122,
     123,   123,   124,   125,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   130,   130,   130,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     0,     0,     7,     0,
       0,     6,     2,     1,     1,     1,     2,     3,     1,     3,
       1,     0,     6,     0,     5,     2,     1,     3,     1,     0,
       4,     2,     1,     1,     2,     1,     3,     4,     0,     5,
       0,     1,     1,     3,     1,     3,     2,     2,     0,     1,
       1,     1,     2,     3,     3,     4,     3,     4,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     5,     1,     2,     5,     7,     5,     5,     7,     5,
       5,     0,     1,     3,     2,     2,     0,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     4,     4,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     3,     2
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
#line 56 "kim.y"
    {root=makeNode(N_PROGRAM, NIL, (yyvsp[0].aid), NIL); checkForwardReference();}
#line 1694 "y.tab.c"
    break;

  case 3:
#line 59 "kim.y"
                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1700 "y.tab.c"
    break;

  case 4:
#line 60 "kim.y"
                                                {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 1706 "y.tab.c"
    break;

  case 5:
#line 63 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1712 "y.tab.c"
    break;

  case 6:
#line 64 "kim.y"
                                    {(yyval.aid)=(yyvsp[0].aid);}
#line 1718 "y.tab.c"
    break;

  case 7:
#line 67 "kim.y"
                                                {(yyval.aid)=setFunctionDeclaratorSpecifier((yyvsp[0].aid), (yyvsp[-1].aspec));}
#line 1724 "y.tab.c"
    break;

  case 8:
#line 68 "kim.y"
                                                        {(yyval.aid)=setFunctionDeclaratorBody((yyvsp[-1].aid), (yyvsp[0].anode));}
#line 1730 "y.tab.c"
    break;

  case 9:
#line 69 "kim.y"
                                                            {(yyval.aid)=setFunctionDeclaratorSpecifier((yyvsp[0].aid), makeSpecifier(int_type, 0));}
#line 1736 "y.tab.c"
    break;

  case 10:
#line 70 "kim.y"
                                                        {(yyval.aid)=setFunctionDeclaratorBody((yyvsp[-1].aid), (yyvsp[0].anode));}
#line 1742 "y.tab.c"
    break;

  case 11:
#line 73 "kim.y"
                                {(yyval.aid)=NIL;}
#line 1748 "y.tab.c"
    break;

  case 12:
#line 74 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1754 "y.tab.c"
    break;

  case 13:
#line 77 "kim.y"
                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1760 "y.tab.c"
    break;

  case 14:
#line 78 "kim.y"
                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 1766 "y.tab.c"
    break;

  case 15:
#line 81 "kim.y"
                                                                            {(yyval.aid)=setDeclaratorListSpecifier((yyvsp[-1].aid), (yyvsp[-2].aspec));}
#line 1772 "y.tab.c"
    break;

  case 16:
#line 84 "kim.y"
                                                                        {(yyval.aspec)=makeSpecifier((yyvsp[0].atype), 0);}
#line 1778 "y.tab.c"
    break;

  case 17:
#line 85 "kim.y"
                                                                        {(yyval.aspec)=makeSpecifier(0, (yyvsp[0].skind));}
#line 1784 "y.tab.c"
    break;

  case 18:
#line 86 "kim.y"
                                                        {(yyval.aspec)=updateSpecifier((yyvsp[0].aspec), (yyvsp[-1].atype), 0);}
#line 1790 "y.tab.c"
    break;

  case 19:
#line 87 "kim.y"
                                                        {(yyval.aspec)=updateSpecifier((yyvsp[0].aspec), 0, (yyvsp[-1].skind));}
#line 1796 "y.tab.c"
    break;

  case 20:
#line 90 "kim.y"
                                {(yyval.skind)=S_AUTO;}
#line 1802 "y.tab.c"
    break;

  case 21:
#line 91 "kim.y"
                                {(yyval.skind)=S_STATIC;}
#line 1808 "y.tab.c"
    break;

  case 22:
#line 92 "kim.y"
                                {(yyval.skind)=S_TYPEDEF;}
#line 1814 "y.tab.c"
    break;

  case 23:
#line 95 "kim.y"
                                {(yyval.aid)=makeDummyIdentifier();}
#line 1820 "y.tab.c"
    break;

  case 24:
#line 96 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1826 "y.tab.c"
    break;

  case 25:
#line 99 "kim.y"
                                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1832 "y.tab.c"
    break;

  case 26:
#line 100 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 1838 "y.tab.c"
    break;

  case 27:
#line 103 "kim.y"
                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1844 "y.tab.c"
    break;

  case 28:
#line 104 "kim.y"
                                        {(yyval.aid)=setDeclaratorInit((yyvsp[-2].aid), (yyvsp[0].anode));}
#line 1850 "y.tab.c"
    break;

  case 29:
#line 107 "kim.y"
                                        {(yyval.anode)=makeNode(N_INIT_LIST_ONE, NIL, (yyvsp[0].anode), NIL);}
#line 1856 "y.tab.c"
    break;

  case 30:
#line 108 "kim.y"
                                    {(yyval.anode)=(yyvsp[-1].anode);}
#line 1862 "y.tab.c"
    break;

  case 31:
#line 111 "kim.y"
                                                        {(yyval.anode)=makeNode(N_INIT_LIST, (yyvsp[0].anode), NIL, makeNode(N_INIT_LIST_NIL, NIL, NIL, NIL));}
#line 1868 "y.tab.c"
    break;

  case 32:
#line 112 "kim.y"
                                                {(yyval.anode)=makeNodeList(N_INIT_LIST, (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 1874 "y.tab.c"
    break;

  case 33:
#line 115 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 1880 "y.tab.c"
    break;

  case 34:
#line 116 "kim.y"
                            {(yyval.atype)=(yyvsp[0].atype);}
#line 1886 "y.tab.c"
    break;

  case 35:
#line 117 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 1892 "y.tab.c"
    break;

  case 36:
#line 121 "kim.y"
    {(yyval.atype)=setTypeStructOrEnumIdentifier((yyvsp[-1].tkind), (yyvsp[0].pval), ID_STRUCT);}
#line 1898 "y.tab.c"
    break;

  case 37:
#line 122 "kim.y"
            {(yyval.aid)=current_id; current_level++;}
#line 1904 "y.tab.c"
    break;

  case 38:
#line 123 "kim.y"
    {checkForwardReference(); (yyval.atype)=setTypeField((yyvsp[-4].atype), (yyvsp[-1].aid)); current_level--; 
    current_id=(yyvsp[-2].aid);}
#line 1911 "y.tab.c"
    break;

  case 39:
#line 125 "kim.y"
                            {(yyval.atype)=makeType((yyvsp[0].tkind));}
#line 1917 "y.tab.c"
    break;

  case 40:
#line 125 "kim.y"
                                                           {(yyval.aid)=current_id; current_level++;}
#line 1923 "y.tab.c"
    break;

  case 41:
#line 126 "kim.y"
                                    {checkForwardReference(); (yyval.atype)=setTypeField((yyvsp[-4].atype), (yyvsp[-1].aid)); 
    current_level--; current_id=(yyvsp[-2].aid);}
#line 1930 "y.tab.c"
    break;

  case 42:
#line 129 "kim.y"
    {(yyval.atype)=getTypeOfStructOrEnumRefIdentifier((yyvsp[-1].tkind), (yyvsp[0].pval), ID_STRUCT);}
#line 1936 "y.tab.c"
    break;

  case 43:
#line 132 "kim.y"
                            {(yyval.tkind)=T_STRUCT;}
#line 1942 "y.tab.c"
    break;

  case 44:
#line 133 "kim.y"
                            {(yyval.tkind)=T_UNION;}
#line 1948 "y.tab.c"
    break;

  case 45:
#line 136 "kim.y"
                                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1954 "y.tab.c"
    break;

  case 46:
#line 137 "kim.y"
                                                            {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 1960 "y.tab.c"
    break;

  case 47:
#line 141 "kim.y"
    {(yyval.aid)=setStructDeclaratorListSpecifier((yyvsp[-1].aid), (yyvsp[-2].atype));}
#line 1966 "y.tab.c"
    break;

  case 48:
#line 144 "kim.y"
                                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1972 "y.tab.c"
    break;

  case 49:
#line 145 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 1978 "y.tab.c"
    break;

  case 50:
#line 148 "kim.y"
                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1984 "y.tab.c"
    break;

  case 51:
#line 152 "kim.y"
    {(yyval.atype)=setTypeStructOrEnumIdentifier(T_ENUM, (yyvsp[0].pval), ID_ENUM);}
#line 1990 "y.tab.c"
    break;

  case 52:
#line 153 "kim.y"
                                {(yyval.atype)=setTypeField((yyvsp[-3].atype), (yyvsp[-1].aid));}
#line 1996 "y.tab.c"
    break;

  case 53:
#line 154 "kim.y"
                                        {(yyval.atype)=makeType(T_ENUM);}
#line 2002 "y.tab.c"
    break;

  case 54:
#line 155 "kim.y"
                                {(yyval.atype)=setTypeField((yyvsp[-3].atype), (yyvsp[-1].aid));}
#line 2008 "y.tab.c"
    break;

  case 55:
#line 157 "kim.y"
    {(yyval.atype)=getTypeOfStructOrEnumRefIdentifier(T_ENUM, (yyvsp[0].pval), ID_ENUM);}
#line 2014 "y.tab.c"
    break;

  case 56:
#line 160 "kim.y"
                                                            {(yyval.aid)=(yyvsp[0].aid);}
#line 2020 "y.tab.c"
    break;

  case 57:
#line 161 "kim.y"
                                                {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 2026 "y.tab.c"
    break;

  case 58:
#line 165 "kim.y"
    {(yyval.aid)=setDeclaratorKind(makeIdentifier((yyvsp[0].pval)), ID_ENUM_LITERAL);}
#line 2032 "y.tab.c"
    break;

  case 59:
#line 167 "kim.y"
    {(yyval.aid)=setDeclaratorKind(makeIdentifier((yyvsp[0].pval)), ID_ENUM_LITERAL);}
#line 2038 "y.tab.c"
    break;

  case 60:
#line 168 "kim.y"
                                {(yyval.aid)=setDeclaratorInit((yyvsp[-2].aid), (yyvsp[0].anode));}
#line 2044 "y.tab.c"
    break;

  case 61:
#line 171 "kim.y"
                                        {(yyval.aid)=setDeclaratorElementType((yyvsp[0].aid), (yyvsp[-1].atype));}
#line 2050 "y.tab.c"
    break;

  case 62:
#line 172 "kim.y"
                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2056 "y.tab.c"
    break;

  case 63:
#line 175 "kim.y"
                        {(yyval.atype)=makeType(T_POINTER);}
#line 2062 "y.tab.c"
    break;

  case 64:
#line 176 "kim.y"
                        {(yyval.atype)=setTypeElementType((yyvsp[0].atype), makeType(T_POINTER));}
#line 2068 "y.tab.c"
    break;

  case 65:
#line 179 "kim.y"
                                            {(yyval.aid)=makeIdentifier((yyvsp[0].pval));}
#line 2074 "y.tab.c"
    break;

  case 66:
#line 180 "kim.y"
                                        {(yyval.aid)=(yyvsp[-1].aid);}
#line 2080 "y.tab.c"
    break;

  case 67:
#line 182 "kim.y"
    {(yyval.aid)=setDeclaratorElementType((yyvsp[-3].aid), setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode)));}
#line 2086 "y.tab.c"
    break;

  case 68:
#line 183 "kim.y"
                                {(yyval.aid)=current_id; current_level++;}
#line 2092 "y.tab.c"
    break;

  case 69:
#line 185 "kim.y"
    {checkForwardReference(); current_id=(yyvsp[-2].aid); current_level--; 
    (yyval.aid)=setDeclaratorElementType((yyvsp[-4].aid), setTypeField(makeType(T_FUNC), (yyvsp[-1].aid)));}
#line 2099 "y.tab.c"
    break;

  case 70:
#line 189 "kim.y"
                                {(yyval.aid)=NIL;}
#line 2105 "y.tab.c"
    break;

  case 71:
#line 190 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 2111 "y.tab.c"
    break;

  case 72:
#line 193 "kim.y"
                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2117 "y.tab.c"
    break;

  case 73:
#line 194 "kim.y"
                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), setDeclaratorKind(makeDummyIdentifier(), ID_PARM));}
#line 2123 "y.tab.c"
    break;

  case 74:
#line 197 "kim.y"
                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2129 "y.tab.c"
    break;

  case 75:
#line 198 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 2135 "y.tab.c"
    break;

  case 76:
#line 202 "kim.y"
    {(yyval.aid)=setParameterDeclaratorSpecifier((yyvsp[0].aid), (yyvsp[-1].aspec));}
#line 2141 "y.tab.c"
    break;

  case 77:
#line 204 "kim.y"
    {(yyval.aid)=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(), (yyvsp[0].atype)), (yyvsp[-1].aspec));}
#line 2147 "y.tab.c"
    break;

  case 78:
#line 207 "kim.y"
                                    {(yyval.atype)=NIL;}
#line 2153 "y.tab.c"
    break;

  case 79:
#line 208 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 2159 "y.tab.c"
    break;

  case 80:
#line 211 "kim.y"
                                                {(yyval.atype)=makeType(T_POINTER);}
#line 2165 "y.tab.c"
    break;

  case 81:
#line 212 "kim.y"
                                        {(yyval.atype)=(yyvsp[0].atype);}
#line 2171 "y.tab.c"
    break;

  case 82:
#line 214 "kim.y"
    {(yyval.atype)=setTypeElementType((yyvsp[0].atype), makeType(T_POINTER));}
#line 2177 "y.tab.c"
    break;

  case 83:
#line 217 "kim.y"
                                                                        {(yyval.atype)=(yyvsp[-1].atype);}
#line 2183 "y.tab.c"
    break;

  case 84:
#line 219 "kim.y"
    {(yyval.atype)=setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode));}
#line 2189 "y.tab.c"
    break;

  case 85:
#line 221 "kim.y"
    {(yyval.atype)=setTypeElementType((yyvsp[-3].atype), setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode)));}
#line 2195 "y.tab.c"
    break;

  case 86:
#line 223 "kim.y"
    {(yyval.atype)=setTypeField(makeType(T_FUNC), (yyvsp[-1].aid));}
#line 2201 "y.tab.c"
    break;

  case 87:
#line 225 "kim.y"
    {(yyval.atype)=setTypeElementType((yyvsp[-3].atype), setTypeField(makeType(T_FUNC), (yyvsp[-1].aid)));}
#line 2207 "y.tab.c"
    break;

  case 88:
#line 228 "kim.y"
                        {(yyval.anode)=makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL);}
#line 2213 "y.tab.c"
    break;

  case 89:
#line 229 "kim.y"
                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2219 "y.tab.c"
    break;

  case 90:
#line 232 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_LIST, (yyvsp[0].anode), NIL, makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL));}
#line 2225 "y.tab.c"
    break;

  case 91:
#line 233 "kim.y"
                                        {(yyval.anode)=makeNodeList(N_STMT_LIST, (yyvsp[-1].anode), (yyvsp[0].anode));}
#line 2231 "y.tab.c"
    break;

  case 92:
#line 236 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2237 "y.tab.c"
    break;

  case 93:
#line 237 "kim.y"
                                    {(yyval.anode)=(yyvsp[0].anode);}
#line 2243 "y.tab.c"
    break;

  case 94:
#line 238 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2249 "y.tab.c"
    break;

  case 95:
#line 239 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2255 "y.tab.c"
    break;

  case 96:
#line 240 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2261 "y.tab.c"
    break;

  case 97:
#line 241 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2267 "y.tab.c"
    break;

  case 98:
#line 244 "kim.y"
                                                        {(yyval.anode)=makeNode(N_STMT_LABEL_CASE, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2273 "y.tab.c"
    break;

  case 99:
#line 245 "kim.y"
                                                        {(yyval.anode)=makeNode(N_STMT_LABEL_DEFAULT, NIL, (yyvsp[0].anode), NIL);}
#line 2279 "y.tab.c"
    break;

  case 100:
#line 248 "kim.y"
            {(yyval.aid)=current_id; current_level++;}
#line 2285 "y.tab.c"
    break;

  case 101:
#line 249 "kim.y"
                                {checkForwardReference();
	(yyval.anode)=makeNode(N_STMT_COMPOUND, (yyvsp[-2].aid), NIL, (yyvsp[-1].anode)); current_id=(yyvsp[-3].aid);
	current_level--;}
#line 2293 "y.tab.c"
    break;

  case 102:
#line 254 "kim.y"
                                {(yyval.anode)=makeNode(N_STMT_EMPTY, NIL, NIL, NIL);}
#line 2299 "y.tab.c"
    break;

  case 103:
#line 255 "kim.y"
                                {(yyval.anode)=makeNode(N_STMT_EXPRESSION, NIL, (yyvsp[-1].anode), NIL);}
#line 2305 "y.tab.c"
    break;

  case 104:
#line 258 "kim.y"
                                                                                {(yyval.anode)=makeNode(N_STMT_IF, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2311 "y.tab.c"
    break;

  case 105:
#line 259 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_IF_ELSE, (yyvsp[-4].anode), (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2317 "y.tab.c"
    break;

  case 106:
#line 260 "kim.y"
                                                                        {(yyval.anode)=makeNode(N_STMT_SWITCH, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2323 "y.tab.c"
    break;

  case 107:
#line 263 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_WHILE, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2329 "y.tab.c"
    break;

  case 108:
#line 264 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_DO, (yyvsp[-5].anode), NIL, (yyvsp[-2].anode));}
#line 2335 "y.tab.c"
    break;

  case 109:
#line 265 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_FOR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2341 "y.tab.c"
    break;

  case 110:
#line 268 "kim.y"
                                                                                {(yyval.anode)=makeNode(N_FOR_EXP, (yyvsp[-4].anode), (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2347 "y.tab.c"
    break;

  case 111:
#line 271 "kim.y"
                        {(yyval.anode)=NIL;}
#line 2353 "y.tab.c"
    break;

  case 112:
#line 272 "kim.y"
                            {(yyval.anode)=(yyvsp[0].anode);}
#line 2359 "y.tab.c"
    break;

  case 113:
#line 275 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_RETURN, NIL, (yyvsp[-1].anode), NIL);}
#line 2365 "y.tab.c"
    break;

  case 114:
#line 276 "kim.y"
                                                    {(yyval.anode)=makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
#line 2371 "y.tab.c"
    break;

  case 115:
#line 277 "kim.y"
                                                        {(yyval.anode)=makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
#line 2377 "y.tab.c"
    break;

  case 116:
#line 280 "kim.y"
                                    {(yyval.anode)=makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL);}
#line 2383 "y.tab.c"
    break;

  case 117:
#line 281 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2389 "y.tab.c"
    break;

  case 118:
#line 285 "kim.y"
    {(yyval.anode)=makeNode(N_ARG_LIST, (yyvsp[0].anode), NIL, makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL));}
#line 2395 "y.tab.c"
    break;

  case 119:
#line 287 "kim.y"
    {(yyval.anode)=makeNodeList(N_ARG_LIST, (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2401 "y.tab.c"
    break;

  case 120:
#line 290 "kim.y"
                                {(yyval.anode)=NIL;}
#line 2407 "y.tab.c"
    break;

  case 121:
#line 291 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2413 "y.tab.c"
    break;

  case 122:
#line 294 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2419 "y.tab.c"
    break;

  case 123:
#line 297 "kim.y"
                                    {(yyval.anode)=(yyvsp[0].anode);}
#line 2425 "y.tab.c"
    break;

  case 124:
#line 300 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2431 "y.tab.c"
    break;

  case 125:
#line 303 "kim.y"
                                                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2437 "y.tab.c"
    break;

  case 126:
#line 304 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_ASSIGN, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2443 "y.tab.c"
    break;

  case 127:
#line 307 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2449 "y.tab.c"
    break;

  case 128:
#line 310 "kim.y"
                                                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2455 "y.tab.c"
    break;

  case 129:
#line 311 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_OR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2461 "y.tab.c"
    break;

  case 130:
#line 314 "kim.y"
                                                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2467 "y.tab.c"
    break;

  case 131:
#line 315 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_AND, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2473 "y.tab.c"
    break;

  case 132:
#line 318 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2479 "y.tab.c"
    break;

  case 133:
#line 321 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2485 "y.tab.c"
    break;

  case 134:
#line 324 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2491 "y.tab.c"
    break;

  case 135:
#line 327 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2497 "y.tab.c"
    break;

  case 136:
#line 328 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_EQL, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2503 "y.tab.c"
    break;

  case 137:
#line 329 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_NEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2509 "y.tab.c"
    break;

  case 138:
#line 332 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2515 "y.tab.c"
    break;

  case 139:
#line 333 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_LSS, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2521 "y.tab.c"
    break;

  case 140:
#line 334 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_GTR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2527 "y.tab.c"
    break;

  case 141:
#line 335 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_LEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2533 "y.tab.c"
    break;

  case 142:
#line 336 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_GEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2539 "y.tab.c"
    break;

  case 143:
#line 339 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2545 "y.tab.c"
    break;

  case 144:
#line 342 "kim.y"
                                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2551 "y.tab.c"
    break;

  case 145:
#line 343 "kim.y"
                                                                    {(yyval.anode)=makeNode(N_EXP_ADD, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2557 "y.tab.c"
    break;

  case 146:
#line 344 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_SUB, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2563 "y.tab.c"
    break;

  case 147:
#line 347 "kim.y"
                                                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2569 "y.tab.c"
    break;

  case 148:
#line 348 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_MUL, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2575 "y.tab.c"
    break;

  case 149:
#line 349 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_DIV, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2581 "y.tab.c"
    break;

  case 150:
#line 350 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_MOD, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2587 "y.tab.c"
    break;

  case 151:
#line 353 "kim.y"
                                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2593 "y.tab.c"
    break;

  case 152:
#line 354 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_CAST, (yyvsp[-2].atype), NIL, (yyvsp[0].anode));}
#line 2599 "y.tab.c"
    break;

  case 153:
#line 357 "kim.y"
                                            {(yyval.anode)=(yyvsp[0].anode);}
#line 2605 "y.tab.c"
    break;

  case 154:
#line 358 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_PRE_INC, NIL, (yyvsp[0].anode), NIL);}
#line 2611 "y.tab.c"
    break;

  case 155:
#line 359 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_PRE_DEC, NIL, (yyvsp[0].anode), NIL);}
#line 2617 "y.tab.c"
    break;

  case 156:
#line 360 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_AMP, NIL, (yyvsp[0].anode), NIL);}
#line 2623 "y.tab.c"
    break;

  case 157:
#line 361 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_STAR, NIL, (yyvsp[0].anode), NIL);}
#line 2629 "y.tab.c"
    break;

  case 158:
#line 362 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_NOT, NIL, (yyvsp[0].anode), NIL);}
#line 2635 "y.tab.c"
    break;

  case 159:
#line 363 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_MINUS, NIL, (yyvsp[0].anode), NIL);}
#line 2641 "y.tab.c"
    break;

  case 160:
#line 364 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_PLUS, NIL, (yyvsp[0].anode), NIL);}
#line 2647 "y.tab.c"
    break;

  case 161:
#line 365 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_SIZE_EXP, NIL, (yyvsp[0].anode), NIL);}
#line 2653 "y.tab.c"
    break;

  case 162:
#line 366 "kim.y"
                                            {(yyval.anode)=makeNode(N_EXP_SIZE_TYPE, NIL, (yyvsp[-1].atype), NIL);}
#line 2659 "y.tab.c"
    break;

  case 163:
#line 369 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2665 "y.tab.c"
    break;

  case 164:
#line 370 "kim.y"
                                                            {(yyval.anode)=makeNode(N_EXP_ARRAY, (yyvsp[-3].anode), NIL, (yyvsp[-1].anode));}
#line 2671 "y.tab.c"
    break;

  case 165:
#line 371 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_FUNCTION_CALL, (yyvsp[-3].anode), NIL, (yyvsp[-1].anode));}
#line 2677 "y.tab.c"
    break;

  case 166:
#line 372 "kim.y"
                                                            {(yyval.anode)=makeNode(N_EXP_STRUCT, (yyvsp[-2].anode), NIL, (yyvsp[0].pval));}
#line 2683 "y.tab.c"
    break;

  case 167:
#line 373 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_ARROW, (yyvsp[-2].anode), NIL, (yyvsp[0].pval));}
#line 2689 "y.tab.c"
    break;

  case 168:
#line 374 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_POST_INC, NIL, (yyvsp[-1].anode), NIL);}
#line 2695 "y.tab.c"
    break;

  case 169:
#line 375 "kim.y"
                                                            {(yyval.anode)=makeNode(N_EXP_POST_DEC, NIL, (yyvsp[-1].anode), NIL);}
#line 2701 "y.tab.c"
    break;

  case 170:
#line 378 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_IDENT, NIL, getIdentifierDeclared((yyvsp[0].pval)), NIL);}
#line 2707 "y.tab.c"
    break;

  case 171:
#line 379 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_INT_CONST, NIL, (yyvsp[0].ival), NIL);}
#line 2713 "y.tab.c"
    break;

  case 172:
#line 380 "kim.y"
                            {(yyval.anode)=makeNode(N_EXP_FLOAT_CONST, NIL, (yyvsp[0].pval), NIL);}
#line 2719 "y.tab.c"
    break;

  case 173:
#line 381 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_CHAR_CONST, NIL, (yyvsp[0].cval), NIL);}
#line 2725 "y.tab.c"
    break;

  case 174:
#line 382 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_STRING_LITERAL, NIL, (yyvsp[0].pval), NIL);}
#line 2731 "y.tab.c"
    break;

  case 175:
#line 383 "kim.y"
                                {(yyval.anode)=(yyvsp[-1].anode);}
#line 2737 "y.tab.c"
    break;

  case 176:
#line 386 "kim.y"
                                                        {(yyval.atype)=setTypeNameSpecifier((yyvsp[0].atype), (yyvsp[-1].aspec));}
#line 2743 "y.tab.c"
    break;


#line 2747 "y.tab.c"

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
#line 389 "kim.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "y.tab.h"

//included from yacc
extern char *yytext;

FILE* fout;

void yyerror(char *s) {
	syntax_err++;
	printf("line %d: %s near %s \n", line_no, s, yytext);
}
int yywrap(void) {
	return(1);
}

int main()
{	
    fout=fopen("a.asm", "w");
	initialize();
    
	yyparse();
    if(syntax_err) exit(1);
	print_ast(root);
	printf("=========== syntax analysis fin\n");
	
	semantic_analysis(root);
    if(semantic_err) exit(1);
	print_sem_ast(root);
    printf("=========== semantic analysis fin\n");
	
    code_generation(root);
    printf("=========== code generation fin\n");

    fclose(fout);
	return 0;
}

//A4 Supporting Functions for Syntax Analysis

A_NODE* makeNode(NODE_NAME n, A_NODE* a, A_NODE* b, A_NODE* c) {
	//printf("makeNode called\n");
	A_NODE* m;
	m=(A_NODE*)malloc(sizeof(A_NODE));
	m->name=n;
	m->llink=a;
	m->clink=b;
	m->rlink=c;
	m->type=NIL;
	m->line=line_no;
	m->value=0;
	return(m);
}

A_NODE* makeNodeList(NODE_NAME n, A_NODE* a, A_NODE* b) {
	//printf("makeNodeList called\n");
	A_NODE *m, *k;
	k=a;
	while(k->rlink)
		k=k->rlink;
	m=(A_NODE*)malloc(sizeof(A_NODE));
	m->name=k->name;
	m->llink=NIL;
	m->clink=NIL;
	m->rlink=NIL;
	m->type=NIL;
	m->line=line_no;
	m->value=0;
	k->name=n;
	k->llink=b;
	k->rlink=m;
	return(a);
}

A_ID* makeIdentifier(char* s) {
	//printf("makeIdentifier called\n");
	A_ID *id;
	id=(A_ID*)malloc(sizeof(A_ID));
	id->name=s;
	id->kind=0;
	id->specifier=0;
	id->level=current_level;
	id->address=0;
	id->init=NIL;
	id->type=NIL;
	id->link=NIL;
	id->line=line_no;
	id->value=0;
	id->prev=current_id;
	current_id=id;
	return(id);
}

A_ID* makeDummyIdentifier() {
	//printf("makeDummyIdentifier called\n");
	A_ID *id;
	id=malloc(sizeof(A_ID));
	id->name="";
	id->kind=0;
	id->specifier=0;
	id->level=current_level;
	id->address=0;
	id->init=NIL;
	id->type=NIL;
	id->link=NIL;
	id->line=line_no;
	id->value=0;
	id->prev=0;
	return(id);
}

A_TYPE* makeType(T_KIND k) {
	//printf("makeType called\n");
	A_TYPE* t;
	t=malloc(sizeof(A_TYPE));
	t->kind=k;
	t->size=0;
	t->local_var_size=0;
	t->element_type=NIL;
	t->field=NIL;
	t->expr=NIL;
	t->check=FALSE;
	t->prt=FALSE;
	t->line=line_no;
	return(t);
}

A_SPECIFIER* makeSpecifier(A_TYPE* t, S_KIND s) {
	//printf("makeSpecifier called\n");
	A_SPECIFIER* p;
	p=malloc(sizeof(A_SPECIFIER));
	p->type=t;
	p->stor=s;
	p->line=line_no;
	return(p);
}

A_ID* searchIdentifier(char* s, A_ID* id) {
	//printf("searchIdentifier called\n");
	while(id) {
		if(strcmp(id->name, s)==0)
			break;
		id=id->prev;
	}
	return(id);
}

A_ID* searchIdentifierAtCurrentLevel(char* s, A_ID* id) {
	//printf("searchIdentifierAtCurrentLevel called\n");
	while(id) {
		if(id->level<current_level)
			return(NIL);
		if(strcmp(id->name, s)==0)
			break;
		id=id->prev;
	}
	return(id);
}

A_SPECIFIER* updateSpecifier(A_SPECIFIER* p, A_TYPE* t, S_KIND s) {
	//printf("updateSpecifier called\n");
	if(t) {
		if(p->type) {
			if(p->type==t) ;
			else syntax_error(24, 0);
		}
		else
			p->type=t;
	}
	if(s) {
		if(p->stor) {
			if(s==p->stor) ;
			else syntax_error(24, 0);
		}
		else
			p->stor=s;
	}
	return(p);
}
				
void checkForwardReference() {
	//printf("checkForwardReference called\n");
	A_ID* id;
	A_TYPE* t;
	id=current_id;
	while(id) {
		if(id->level<current_level)
			break;
		t=id->type;
		if(id->kind==ID_NULL)
			syntax_error(31, id->name);
		else if((id->kind==ID_STRUCT||id->kind==ID_ENUM)&&t->field==NIL)
			syntax_error(32, id->name);
		id=id->prev;
	}
}

void setDefaultSpecifier(A_SPECIFIER* p) {
	//printf("setDefaultSpecifier called\n");
	A_TYPE* t;
	if(p->type==NIL)
		p->type=int_type;
	if(p->stor==S_NULL)
		p->stor=S_AUTO;
}

A_ID* linkDeclaratorList(A_ID* id1, A_ID* id2) {
	//printf("linkDeclaratorList called\n");
	A_ID* m=id1;
	if(id1==NIL)
		return(id2);
	while(m->link)
		m=m->link;
	m->link=id2;
	return(id1);
}	

A_ID* getIdentifierDeclared(char* s) {
	//printf("getIdentifierDeclared called\n");
	A_ID* id;
	id=searchIdentifier(s, current_id);
	if(id==NIL)
		syntax_error(13, s);
	return(id);	
}

A_TYPE* getTypeOfStructOrEnumRefIdentifier(T_KIND k, char* s, ID_KIND kk) {
	//printf("getTypeOfStructOrEnumRefIdentifier called\n");
	A_TYPE* t;
	A_ID* id;
	id=searchIdentifier(s, current_id);
	if(id) {
		if(id->kind==kk && id->type->kind==k)
			return(id->type);
		else
			syntax_error(11, s);
	}
	t=makeType(k);
	id=makeIdentifier(s);
	id->kind=kk;
	id->type=t;
	return(t);
}

A_ID* setDeclaratorInit(A_ID* id, A_NODE* n) {
	//printf("setDeclaratorInit called\n");
	id->init=n;
	return(id);
}

A_ID* setDeclaratorKind(A_ID* id, ID_KIND k) {
	//printf("setDeclaratorKind called\n");
	A_ID* a;
	a=searchIdentifierAtCurrentLevel(id->name, id->prev);
	if(a)
		syntax_error(12, id->name);
	id->kind=k;
	return(id);
}	

A_ID* setDeclaratorType(A_ID* id, A_TYPE* t) {
	//printf("setDeclaratorType called\n");
	id->type=t;
	return(id);
}

A_ID* setDeclaratorElementType(A_ID* id, A_TYPE* t) {
	//printf("setDeclaratorElementType called\n");
	A_TYPE* tt;
	if(id->type==NIL)
		id->type=t;
	else {
		tt=id->type;
		while(tt->element_type)
			tt=tt->element_type;
		tt->element_type=t;
	}
	return(id);
}

A_ID* setDeclaratorTypeAndKind(A_ID* id, A_TYPE* t, ID_KIND k) {
	//printf("setDeclaratorTypeAndKind called\n");
	id=setDeclaratorElementType(id, t);
	id=setDeclaratorKind(id, k);
	return(id);
}

A_ID* setDeclaratorListSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setDeclaratorListSpecifier called\n");
	A_ID* a;
	setDefaultSpecifier(p);
	a=id;
	while(a) {
		if(strlen(a->name) && searchIdentifierAtCurrentLevel(a->name, a->prev))
			syntax_error(12, a->name);
		a=setDeclaratorElementType(a, p->type);
		if(p->stor==S_TYPEDEF)
			a->kind=ID_TYPE;
		else if(a->type->kind==T_FUNC)
			a->kind=ID_FUNC;
		else
			a->kind=ID_VAR;
		a->specifier=p->stor;
		if(a->specifier==S_NULL)
			a->specifier=S_AUTO;
		a=a->link;
	}
	return(id);
}

A_ID* setFunctionDeclaratorSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setFunctionDeclaratorSpecifier called\n");
	A_ID* a;
	if(p->stor)
		syntax_error(25, 0);
	setDefaultSpecifier(p);
	if(id->type->kind!=T_FUNC) {
		syntax_error(21, 0);
		return(id);
	}
	else {
		id=setDeclaratorElementType(id, p->type);
		id->kind=ID_FUNC;
	}
	a=searchIdentifierAtCurrentLevel(id->name, id->prev);
	if(a) {
		if(a->kind!=ID_FUNC || a->type->expr)
			syntax_error(12, id->name);
		else {
			if(isNotSameFormalParameters(a->type->field, id->type->field))
				syntax_error(22, id->name);
			if(isNotSameType(a->type->element_type, id->type->element_type))
				syntax_error(26, a->name);
		}
	}
	a=id->type->field;
	while(a) {
		if(strlen(a->name))
			current_id=a;
		else if(a->type)
			syntax_error(23, 0);
		a=a->link;
	}
	return(id);
}

A_ID* setFunctionDeclaratorBody(A_ID* id, A_NODE* n) {
	//printf("setFunctionDeclaratorBody called\n");
	id->type->expr=n;
	return(id);
}

A_ID* setParameterDeclaratorSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setParameterDeclaratorSpecifier called\n");
	if(searchIdentifierAtCurrentLevel(id->name, id->prev))
		syntax_error(12, id->name);
	if(p->stor || p->type==void_type)
		syntax_error(14, 0);
	setDefaultSpecifier(p);
	id=setDeclaratorElementType(id, p->type);
	id->kind=ID_PARM;
	return(id);
}

A_ID* setStructDeclaratorListSpecifier(A_ID* id, A_TYPE* t) {
	//printf("setStructDeclaratorListSpecifier called\n");
	A_ID *a;
	a=id;
	while(a) {
		if(searchIdentifierAtCurrentLevel(a->name, a->prev))
			syntax_error(12, a->name);
		a=setDeclaratorElementType(a, t);
		a->kind=ID_FIELD;
		a=a->link;
	}
	return(id);
}

A_TYPE* setTypeNameSpecifier(A_TYPE* t, A_SPECIFIER* p) {
	//printf("setTypeNameSpecifier called\n");
	if(p->stor)
		syntax_error(20, 0);
	setDefaultSpecifier(p);
	t=setTypeElementType(t, p-> type);
	return(t);
}

A_TYPE* setTypeElementType(A_TYPE* t, A_TYPE* s) {
	//printf("setTypeElementType called\n");
	A_TYPE* q;
	if(t==NIL)
		return(s);
	q=t;
	while(q->element_type)
		q=q->element_type;
	q->element_type=s;
	return(t);
}

A_TYPE* setTypeField(A_TYPE* t, A_ID* n) {
	//printf("setTypeField called\n");
	t->field=n;
	return(t);
}

A_TYPE* setTypeExpr(A_TYPE* t, A_NODE* n) {
	//printf("setTypeExpr called\n");
	t->expr=n;
	return(t);
}

A_TYPE* setTypeAndKindOfDeclarator(A_TYPE* t, ID_KIND k, A_ID* id) {
	//printf("setTypeAndKindOfDeclarator called\n");
	if(searchIdentifierAtCurrentLevel(id->name, id->prev))
		syntax_error(12, id->name);
	id->type=t;
	id->kind=k;
	return(t);
}

A_TYPE* setTypeStructOrEnumIdentifier(T_KIND k, char* s, ID_KIND kk) {
	//printf("setTypeStructOrEnumIdentifier called\n");
	A_TYPE* t;
	A_ID *id, *a;
	a=searchIdentifierAtCurrentLevel(s, current_id);
	if(a) {
		if(a->kind==kk && a->type->kind==k) {
			if(a->type->field)
				syntax_error(12, s);
			else
				return(a->type);
		}
		else
			syntax_error(12, s);
	}
	id=makeIdentifier(s);
	t=makeType(k);
	id->type=t;
	id->kind=kk;
	return(t);
}

BOOLEAN isNotSameFormalParameters(A_ID* a, A_ID* b) {
	//printf("isNotSameFormalParameters called\n");
	if(a==NIL)
		return(FALSE);
	while(a) {
		if(b==NIL || isNotSameType(a->type, b->type))
			return(TRUE);
		a=a->link;
		b=b->link;
	}
	if(b)
		return(TRUE);
	else
		return(FALSE);	
}

BOOLEAN isNotSameType(A_TYPE* t1, A_TYPE* t2) {
	//printf("isNotSameType called\n");
	if(isPointerOrArrayType(t1) || isPointerOrArrayType(t2))
		return(isNotSameType(t1->element_type, t2->element_type));
	else
		return(t1!=t2);
}


void initialize() {
	int_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("int"));
	float_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("float"));
	char_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("char"));
	void_type=setTypeAndKindOfDeclarator(makeType(T_VOID), ID_TYPE, makeIdentifier("void"));
	string_type=setTypeElementType(makeType(T_POINTER), char_type);
	int_type->size=4;	int_type->check=TRUE;
	float_type->size=4;	float_type->check=TRUE;
	char_type->size=1;	char_type->check=TRUE;
	void_type->size=0;	void_type->check=TRUE;
	string_type->size=4;	string_type->check=TRUE;
	setDeclaratorTypeAndKind(
		makeIdentifier("printf"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), void_type), 
			linkDeclaratorList(
				setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
				setDeclaratorKind(makeDummyIdentifier(), ID_PARM))), 
		ID_FUNC);
	setDeclaratorTypeAndKind(
		makeIdentifier("scanf"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), void_type), 
			linkDeclaratorList(
				setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
				setDeclaratorKind(makeDummyIdentifier(), ID_PARM))), 
		ID_FUNC);
	setDeclaratorTypeAndKind(
		makeIdentifier("malloc"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), string_type), 
			setDeclaratorTypeAndKind(makeDummyIdentifier(), int_type, ID_PARM)),
		ID_FUNC);		
}

void syntax_error(int i, char* s) {
	syntax_err++;
	printf("line %d: syntax error: ", line_no);
	switch(i) {
		case 11: printf("illegal referencing struct or union identifier %s", s); break;
		case 12: printf("redeclaration of identifier %s", s); break;
		case 13: printf("undefined identifier %s", s); break;
		case 14: printf("illegal type specifier in formal parameter"); break;
		case 20: printf("illegal storage class in type specifiers"); break;
		case 21: printf("illegal function declarator"); break;
		case 22: printf("conflicting parameter type in prototype function %s", s); break;
		case 23: printf("empty parameter name"); break;
		case 24: printf("illegal declaration specifiers"); break;
		case 25: printf("illegal function specifiers"); break;
		case 26: printf("illegal or conflicting return type in function %s", s); break;
		case 31: printf("undefined type for identifier %s", s); break;
		case 32: printf("incomplete forward reference for identifier %s", s); break;
		default: printf("unknown"); break;
	}
	if(strlen(yytext)==0)
		printf(" at end\n");
	else
		printf(" near %s\n", yytext);
}

////////////////////////////// print syntax tree

char * node_name[] = {
	"N_NULL",
	"N_PROGRAM",
	"N_EXP_IDENT",
	"N_EXP_INT_CONST",
	"N_EXP_FLOAT_CONST",
	"N_EXP_CHAR_CONST",
	"N_EXP_STRING_LITERAL",
	"N_EXP_ARRAY",
	"N_EXP_FUNCTION_CALL",
	"N_EXP_STRUCT",	
    "N_EXP_ARROW",
	"N_EXP_POST_INC",
	"N_EXP_POST_DEC",
	"N_EXP_PRE_INC",
	"N_EXP_PRE_DEC",
	"N_EXP_AMP",
	"N_EXP_STAR",
	"N_EXP_NOT",
	"N_EXP_PLUS",
	"N_EXP_MINUS",	
    "N_EXP_SIZE_EXP",
	"N_EXP_SIZE_TYPE",
	"N_EXP_CAST",
	"N_EXP_MUL",
	"N_EXP_DIV",
	"N_EXP_MOD",
	"N_EXP_ADD",
	"N_EXP_SUB",
	"N_EXP_LSS",
	"N_EXP_GTR",	
    "N_EXP_LEQ",
	"N_EXP_GEQ",
	"N_EXP_NEQ",
	"N_EXP_EQL",
	"N_EXP_AND",
	"N_EXP_OR",
	"N_EXP_ASSIGN",
	"N_ARG_LIST",
	"N_ARG_LIST_NIL",
	"N_STMT_LABEL_CASE",	
    "N_STMT_LABEL_DEFAULT",
	"N_STMT_COMPOUND",
	"N_STMT_EMPTY",
	"N_STMT_EXPRESSION",
	"N_STMT_IF",
	"N_STMT_IF_ELSE",
	"N_STMT_SWITCH",
	"N_STMT_WHILE",
	"N_STMT_DO",
	"N_STMT_FOR",	
    "N_STMT_RETURN",
	"N_STMT_CONTINUE",
	"N_STMT_BREAK",
	"N_FOR_EXP",
	"N_STMT_LIST",
	"N_STMT_LIST_NIL",
	"N_INIT_LIST",
	"N_INIT_LIST_ONE",
	"N_INIT_LIST_NIL"};

void print_node(A_NODE *node, int s) {
	print_space(s);
	printf("%s (%x,%d)\n", node_name[node->name],node->type,node->value);
}
void print_space(int s)
{
	int i;
	for(i=1; i<=s; i++) printf("|  ");
}
void print_ast(A_NODE *node) 
{
	printf("==========  syntax tree  ==========\n");
	prt_program(node,0);
}
void prt_program(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_PROGRAM:
		prt_A_ID_LIST(node->clink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_initializer(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_INIT_LIST:
		prt_initializer(node->llink, s+1);
		prt_initializer(node->rlink, s+1);
		break;
	   case N_INIT_LIST_ONE:
		prt_expression(node->clink, s+1);
		break;
	   case N_INIT_LIST_NIL:
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_expression(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_EXP_IDENT : 
		prt_A_ID_NAME(node->clink, s+1);
		break;
	   case N_EXP_INT_CONST :
		prt_integer(node->clink, s+1);
		break;
	   case N_EXP_FLOAT_CONST :
 		prt_STRING(node->clink, s+1);
		break;
	   case N_EXP_CHAR_CONST :
 		prt_integer(node->clink, s+1);
		break;
	   case N_EXP_STRING_LITERAL :
		prt_STRING(node->clink, s+1);
		break;
	   case N_EXP_ARRAY :
		prt_expression(node->llink, s+1);
		prt_expression(node->rlink, s+1);
		break;
	   case N_EXP_FUNCTION_CALL : 
		prt_expression(node->llink, s+1);
		prt_arg_expr_list(node->rlink, s+1);
		break;
	   case N_EXP_STRUCT : 
	   case N_EXP_ARROW : 
		prt_expression(node->llink, s+1);
		prt_STRING(node->rlink, s+1);
		break;
	   case N_EXP_POST_INC :
	   case N_EXP_POST_DEC :
	   case N_EXP_PRE_INC :
	   case N_EXP_PRE_DEC :
	   case N_EXP_AMP :
	   case N_EXP_STAR :
	   case N_EXP_NOT :
	   case N_EXP_PLUS :
	   case N_EXP_MINUS :
	   case N_EXP_SIZE_EXP :
		prt_expression(node->clink, s+1);
   		break;
	   case N_EXP_SIZE_TYPE :
		prt_A_TYPE(node->clink, s+1);
   		break;
	   case N_EXP_CAST :
		prt_A_TYPE(node->llink, s+1);
		prt_expression(node->rlink, s+1);
   		break;
	   case N_EXP_MUL :
	   case N_EXP_DIV :
	   case N_EXP_MOD :
	   case N_EXP_ADD :
	   case N_EXP_SUB : 
	   case N_EXP_LSS :
	   case N_EXP_GTR :
	   case N_EXP_LEQ :
	   case N_EXP_GEQ :
	   case N_EXP_NEQ :
	   case N_EXP_EQL :
	   case N_EXP_AND :
	   case N_EXP_OR :
	   case N_EXP_ASSIGN :
		prt_expression(node->llink, s+1);
		prt_expression(node->rlink, s+1);
   		break;
	   default : 
		printf("****** syntax tree error ******");
	}
}
void prt_arg_expr_list(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_ARG_LIST : 
		prt_expression(node->llink, s+1);
		prt_arg_expr_list(node->rlink, s+1);
		break;
	   case N_ARG_LIST_NIL : 
		break;
	   default :
		printf("****** syntax tree error ******");
	}	
}
void prt_statement(A_NODE *node, int s)
{
	print_node(node,s);
	 
	switch(node->name) {
	   case N_STMT_LABEL_CASE :
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_LABEL_DEFAULT :
		prt_statement(node->clink, s+1);
		break;
	   case N_STMT_COMPOUND:
		if(node->llink) 
			prt_A_ID_LIST(node->llink, s+1);
		prt_statement_list(node->rlink, s+1);
		break;
	   case N_STMT_EMPTY:
		break;
	   case N_STMT_EXPRESSION:
		prt_expression(node->clink, s+1);
		break;
	   case N_STMT_IF_ELSE:
		prt_expression(node->llink, s+1);
		prt_statement(node->clink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_IF:
	   case N_STMT_SWITCH:
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_WHILE:
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_DO:
		prt_statement(node->llink, s+1);
		prt_expression(node->rlink, s+1);
		break;
	   case N_STMT_FOR:
		prt_for_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_CONTINUE:
		break;
	   case N_STMT_BREAK:
		break;
	   case N_STMT_RETURN:
		if(node->clink) 
			prt_expression(node->clink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_statement_list(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	case N_STMT_LIST:
		prt_statement(node->llink, s+1);
		prt_statement_list(node->rlink, s+1);
		break;
	case N_STMT_LIST_NIL:
		break;
	default :
		printf("****** syntax tree error ******");
		
	}
}
void prt_for_expression(A_NODE *node, int s)
{
	print_node(node,s);
	
	switch(node->name) {
		
	   case N_FOR_EXP :
		if(node->llink) 
			prt_expression(node->llink, s+1);
		if(node->clink) 
			prt_expression(node->clink, s+1);
		if(node->rlink) 
			prt_expression(node->rlink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_integer(int a, int s)
{
	print_space(s);
	printf("%d\n", a);
}
void prt_STRING(char *str, int s) {
	print_space(s);
	printf("%s\n", str);
}
char *type_kind_name[]={"NULL","ENUM","ARRAY","STRUCT","UNION","FUNC","POINTER","VOID"};
	
void prt_A_TYPE(A_TYPE *t, int s) 
{
	print_space(s);
	if (t==int_type) 
		printf("(int)\n");
	else if (t==float_type) 
		printf("(float)\n");
	else if (t==char_type) 
		printf("(char %d)\n",t->size);
	else if (t==void_type)
		printf("(void)\n");
	else if (t->kind==T_NULL)
		printf("(null)");
	else if (t->prt)
		printf("(DONE:%p)\n",t);
	else 
	   switch (t->kind) {
		case T_ENUM:
			t->prt=TRUE;
			printf("ENUM\n");
			print_space(s); printf("|  ENUMERATORS\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_POINTER:
			t->prt=TRUE;
			printf("POINTER\n");
			print_space(s); printf("|  ELEMENT_TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			break;
		case T_ARRAY:
			t->prt=TRUE;
			printf("ARRAY\n");
			print_space(s); printf("|  INDEX\n");
			if (t->expr)
				prt_expression(t->expr,s+2);
			else {
				print_space(s+2); 
				printf("(none)\n");
			}
			print_space(s); printf("|  ELEMENT_TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			break;
		case T_STRUCT:
			t->prt=TRUE;
			printf("STRUCT\n");
			print_space(s); printf("|  FIELD\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_UNION:
			t->prt=TRUE;
			printf("UNION\n");
			print_space(s); printf("|  FIELD\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_FUNC:
			t->prt=TRUE;
			printf("FUNCTION\n");
			print_space(s); printf("|  PARAMETER\n");
			prt_A_ID_LIST(t->field,s+2);
			print_space(s); printf("|  TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			if (t->expr) {
				print_space(s); printf("|  BODY\n");
				prt_statement(t->expr,s+2);}
	   }
}
void prt_A_ID_LIST(A_ID *id, int s)
{
	while (id) {
		prt_A_ID(id,s);
		id=id->link;
	}
}
char *id_kind_name[]={"NULL","VAR","FUNC","PARM","FIELD","TYPE","ENUM", "STRUCT","ENUM_LITERAL"};
char *spec_name[]={"NULL","AUTO","STATIC","TYPEDEF"};
void prt_A_ID_NAME(A_ID *id, int s)
{
	print_space(s);
	printf("(ID=\"%s\") TYPE:%p KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
		id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier], id->level, id->value, id->address);
}
void prt_A_ID(A_ID *id, int s)
{
	print_space(s);
	printf("(ID=\"%s\") TYPE:%p KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
		id->name, id->type,id_kind_name[id->kind], spec_name[id->specifier],id->level, id->value, id->address);
	if (id->type) {
		print_space(s);
		printf("|  TYPE\n");
		prt_A_TYPE(id->type,s+2);}
	if (id->init) {
		print_space(s);
		printf("|  INIT\n");
		if (id->kind==ID_ENUM_LITERAL)
			prt_expression(id->init,s+2);
		else 
			prt_initializer(id->init,s+2); }
}

// A6 semantic analyzer /////////////////////////////////////////////////

void semantic_analysis(A_NODE* node) {
    sem_program(node);
    set_literal_address(node);	
}

void set_literal_address(A_NODE* node) {
    int i;
    for(i=1; i<=literal_no; i++)
        literal_table[i].addr+=node->value;
    node->value+=literal_size;
}

void sem_program(A_NODE* node) {
    int i;
    switch(node->name) {
        case N_PROGRAM:
            i=sem_declaration_list(node->clink, 12);
            node->value=global_address;
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
   }
}
int put_literal(A_LITERAL lit, int ll) {
    float ff;
    if(literal_no>=LIT_MAX) 
        semantic_error(93, ll, 0);
    else
        literal_no++;
    literal_table[literal_no]=lit;
    literal_table[literal_no].addr=literal_size;
    if(lit.type->kind==T_ENUM)
        literal_size+=4;
    else if(isStringType(lit.type))
        literal_size+=strlen(lit.value.s)+1;
    if(literal_size%4)
        literal_size=literal_size/4*4+4;
    return (literal_no);
}
A_TYPE* sem_expression(A_NODE* node) {
    A_TYPE* result=NIL, *t, *t1, *t2;
    A_ID *id;
    A_LITERAL lit;
    int i;
    BOOLEAN lvalue=FALSE;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    result=id->type;
                    if(!isArrayType(result))
                        lvalue=TRUE;
                    break;
                case ID_FUNC:
                    result=id->type;
                    break;
                case ID_ENUM_LITERAL:
                    result=int_type;
                    break;
                default:
                    semantic_error(38, node->line, id->name);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            result=int_type;
            break;
        case N_EXP_FLOAT_CONST:
            lit.type=float_type;
            lit.value.f=atof(node->clink);
            node->clink=put_literal(lit, node->line); //index of literal table
            result=float_type;
            break;
        case N_EXP_CHAR_CONST:
            result=char_type;
            break;
        case N_EXP_STRING_LITERAL:
            lit.type=string_type;
            lit.value.s=node->clink;
            node->clink=put_literal(lit, node->line); //index of literal table
            result=string_type;
            break;
        case N_EXP_ARRAY:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            //usual binary conversion
            t=convertUsualBinaryConversion(node);
            t1=node->llink->type;
            t2=node->rlink->type;
            if(isPointerOrArrayType(t1))
                result=t1->element_type;
            else   
                semantic_error(32, node->line, 0);
            if(!isIntegralType(t2))
                semantic_error(29, node->line, 0);
            if(!isArrayType(result))
                lvalue=TRUE;
            break;
        case N_EXP_STRUCT:
            t=sem_expression(node->llink);
            id=getStructFieldIdentifier(t, node->rlink);
            if(id) {
                result=id->type;
                if(node->llink->value && !isArrayType(result))
                    lvalue=TRUE;
            }
            else
                semantic_error(37, node->line, 0);
            node->rlink=id;
            break;
        case N_EXP_ARROW:
            t=sem_expression(node->llink);
            id=getPointerFieldIdentifier(t, node->rlink);
            if(id) {
                result=id->type;
                if(!isArrayType(result))
                    lvalue=TRUE;
            }
            else    
                semantic_error(37, node->line, 0);
            node->rlink=id;
            break;
        case N_EXP_FUNCTION_CALL:
            t=sem_expression(node->llink);
            //usual unary conversion
            node->llink=convertUsualUnaryConversion(node->llink);
            t=node->llink->type;
            if(isPointerType(t) && isFunctionType(t->element_type)) {
                sem_arg_expr_list(node->rlink, t->element_type->field);
                result=t->element_type->element_type;
            }
            else
                semantic_error(21, node->line, 0);
            break;
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
            result=sem_expression(node->clink);
            //usual binary conversion between the expression and 1
            if(!isScalarType(result)) 
                semantic_error(27, node->line, 0);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->clink))
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_CAST:
            result=node->llink;
            i=sem_A_TYPE(result);
            t=sem_expression(node->rlink);
            //check allowable casting conversion
            if(!isAllowableCastingConversion(result, t))
                semantic_error(58, node->line, 0);
            break;
        case N_EXP_SIZE_TYPE:
            t=node->clink;
            i=sem_A_TYPE(t);
            //check if incomplete array, function, void
            if(isArrayType(t) && t->size==0 || isFunctionType(t) || isVoidType(t))
                semantic_error(39, node->line, 0);
            else    
                node->clink=i;
            result=int_type;
            break;
        case N_EXP_SIZE_EXP:
            t=sem_expression(node->clink);
            //check if incomplete array, function
            if((node->clink->name!=N_EXP_IDENT || ((A_ID*)node->clink->clink)->kind!=ID_PARM) && (isArrayType(t)&&t->size==0||isFunctionType(t)))
                semantic_error(39, node->line, 0);
            else
                node->clink=t->size;
            result=int_type;
            break;
        case N_EXP_PLUS:
        case N_EXP_MINUS:
            t=sem_expression(node->clink);
            if(isArithmeticType(t)) {
                    node->clink=convertUsualUnaryConversion(node->clink);
                    result=node->clink->type;
            }
            else    
                semantic_error(13, node->line, 0);
            break;
        case N_EXP_NOT:
            t=sem_expression(node->clink);
            if(isScalarType(t)) {
                node->clink=convertUsualUnaryConversion(node->clink);
                result=int_type;
            }
            else
                semantic_error(27, node->line, 0);
            break;
        case N_EXP_AMP:
            t=sem_expression(node->clink);
            if(node->clink->value==TRUE||isFunctionType(t)) {
                result=setTypeElementType(makeType(T_POINTER), t);
                result->size=4;
            }
            else
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_STAR:
            t=sem_expression(node->clink);
            node->clink=convertUsualUnaryConversion(node->clink);
            if(isPointerType(t)) {
                result=t->element_type;
                //lvalue if points to an object
                if(isStructOrUnionType(result) || isScalarType(result))
                    lvalue=TRUE;
            }
            else
                semantic_error(31, node->line, 0);
            break;
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
            result=sem_expression(node->clink);
            //usual binary conversion between the expression and 1
            if(!isScalarType(result))
                semantic_error(27, node->line, 0);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->clink))
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_MUL:
        case N_EXP_DIV:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isArithmeticType(t1) && isArithmeticType(t2))
                result=convertUsualBinaryConversion(node);
            else
                semantic_error(28, node->line, 0);
            break;
        case N_EXP_MOD:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isIntegralType(t1) && isIntegralType(t2))
                result=convertUsualBinaryConversion(node);
            else
                semantic_error(29, node->line, 0);
        case N_EXP_ADD:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                result=convertUsualBinaryConversion(node); 
            else if(isPointerType(t1) && isIntegralType(t2))
                result=t1;
            else if(isIntegralType(t1) && isPointerType(t2))
                result=t2;
            else
                semantic_error(24, node->line, 0);
            break;
        case N_EXP_SUB:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);     
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                result=convertUsualBinaryConversion(node);    
            else if(isPointerType(t1) && isIntegralType(t2))
                result=t1;
            else if(isCompatiblePointerType(t1, t2))
                result=t1;
            else
                semantic_error(24, node->line, 0);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);  
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                t=convertUsualBinaryConversion(node);    
            else if(!isCompatiblePointerType(t1, t2))
                semantic_error(40, node->line, 0);
            result=int_type;
            break;
        case N_EXP_NEQ:
        case N_EXP_EQL:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);  
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                t=convertUsualBinaryConversion(node);      
            else if(!isCompatiblePointerType(t1, t2) &&
                    (!isPointerType(t1) || !isConstantZeroExp(node->rlink)) &&
                    (!isPointerType(t2) || !isConstantZeroExp(node->llink)))
                    semantic_error(40, node->line, 0);
            result=int_type;
            break;
        case N_EXP_AND:
        case N_EXP_OR:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertUsualUnaryConversion(node->llink);
            else
                semantic_error(27, node->line, 0);
            t=sem_expression(node->rlink);
            if(isScalarType(t))
                node->rlink=convertUsualUnaryConversion(node->rlink);
            else
                semantic_error(27, node->line, 0);
            result=int_type;
            break;
        case N_EXP_ASSIGN:
            result=sem_expression(node->llink);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->llink))
                semantic_error(60, node->line, 0);
            t=sem_expression(node->rlink);
            if(isAllowableAssignmentConversion(result, t, node->rlink)) {
                if(isArithmeticType(result) && isArithmeticType(t)) 
                    node->rlink=convertUsualAssignmentConversion(result, node->rlink);
            }
            else
                semantic_error(58, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->type=result;
    node->value=lvalue;
    return (result);
}

//check argument-expression-list in function call expression
void sem_arg_expr_list(A_NODE* node, A_ID* id) {
    A_TYPE* t;
    A_ID* a;
    int arg_size=0;
    switch(node->name) {
        case N_ARG_LIST:
            if(id==0)
                semantic_error(34, node->line, 0);
            else {
                if(id->type) {
                    t=sem_expression(node->llink);
                    node->llink=convertUsualUnaryConversion(node->llink);
                    if(isAllowableCastingConversion(id->type, node->llink->type))
                        node->llink=convertCastingConversion(node->llink, id->type);
                    else
                        semantic_error(59, node->line, 0);
                    sem_arg_expr_list(node->rlink, id->link);
                }
                else { //DOTDOT parameter : no conversion
                    t=sem_expression(node->llink);
                    sem_arg_expr_list(node->rlink, id);
                }
                arg_size=node->llink->type->size+node->rlink->value;
            }
            break;
        case N_ARG_LIST_NIL:
            if(id && id->type) //check if '...' argument
                semantic_error(35, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    if(arg_size%4) arg_size=arg_size/4*4+4;
    node->value=arg_size;
}
BOOLEAN isModifiableLvalue(A_NODE* node) {
    if(node->value==FALSE || isVoidType(node->type) || isFunctionType(node->type))
        return (FALSE);
    else
        return (TRUE);
}
//check statement and return local variable size
int sem_statement(A_NODE* node, int addr, A_TYPE* ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int local_size=0, i;
    A_LITERAL lit;
    A_TYPE* t;
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            if(sw==FALSE)
                semantic_error(71, node->line, 0);
            lit=getTypeAndValueOfExpression(node->llink);
            if(isIntegralType(lit.type))
                node->llink=lit.value.i;
            else    
                semantic_error(51, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, sw, brk, cnt);
            break;
        case N_STMT_LABEL_DEFAULT:
            if(sw==FALSE)
                semantic_error(72, node->line, 0);
            local_size=sem_statement(node->clink, addr, ret, sw, brk, cnt);
            break;
        case N_STMT_COMPOUND:
            if(node->llink)
                local_size=sem_declaration_list(node->llink, addr);
            local_size+=sem_statement_list(node->rlink, local_size+addr, ret, sw, brk, cnt);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            t=sem_expression(node->clink);
            break;
        case N_STMT_IF:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, brk, cnt);
            break;
        case N_STMT_IF_ELSE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->clink, addr, ret, FALSE, brk, cnt);
            i=sem_statement(node->rlink, addr, ret, FALSE, brk, cnt);
            if(local_size<i)
                local_size=i;
            break;
        case N_STMT_SWITCH:
            t=sem_expression(node->llink);
            if(!isIntegralType(t))
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, TRUE, TRUE, cnt);
            break;
        case N_STMT_WHILE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_DO:
            local_size=sem_statement(node->llink, addr, ret, FALSE, TRUE, TRUE);
            t=sem_expression(node->rlink);
            if(isScalarType(t))
                node->rlink=convertScalarToInteger(node->rlink);
            else
                semantic_error(50, node->line, 0);
            break;
        case N_STMT_FOR:
            sem_for_expression(node->llink);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_CONTINUE:
            if(cnt==FALSE)
                semantic_error(74, node->line, 0);
            break;
        case N_STMT_BREAK:
            if(brk==FALSE)
                semantic_error(73, node->line, 0);
            break;    
        case N_STMT_RETURN:
            if(node->clink) {
                t=sem_expression(node->clink);
                if(isAllowableCastingConversion(ret, t))
                    node->clink=convertCastingConversion(node->clink, ret);
                else    
                    semantic_error(57, node->line, 0);
            }
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->value=local_size;
    return (local_size);
}
void sem_for_expression(A_NODE*node) {
    A_TYPE* t;
    switch(node->name) {
        case N_FOR_EXP:
            if(node->llink)
                t=sem_expression(node->llink);
            if(node->clink) {
                t=sem_expression(node->clink);
                if(isScalarType(t))
                    node->clink=convertScalarToInteger(node->clink);
                else
                    semantic_error(49, node->line, 0);
            }
            if(node->rlink)
                t=sem_expression(node->rlink);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
}

//check statement-list and return local variable size
int sem_statement_list(A_NODE* node, int addr, A_TYPE* ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int size, i;
    switch(node->name) {
        case N_STMT_LIST:
            size=sem_statement(node->llink, addr, ret, sw, brk, cnt);
            i=sem_statement_list(node->rlink, addr, ret, sw, brk, cnt);
            if(size<i)
              size=i;
            break;
        case N_STMT_LIST_NIL:
            size=0;
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->value=size;
    return (size);
}

//check type and return its size(size of incomplete type is 0)
int sem_A_TYPE(A_TYPE* t) {
    A_ID* id;
    A_TYPE* tt;
    A_LITERAL lit;
    int result=0, i;
    if(t->check)
        return (t->size);
    t->check=1;
    switch(t->kind) {
        case T_NULL:
            semantic_error(80, t->line, 0);
            break;
        case T_ENUM:
            i=0;
            id=t->field;
            while(id) { //enumerators
                if(id->init) {
                    lit=getTypeAndValueOfExpression(id->init);
                    if(!isIntType(lit.type))
                        semantic_error(81, id->line, 0);
                    i=lit.value.i;
                }
                id->init=i++;
                id=id->link;
            }
            result=4;
            break;
        case T_ARRAY:
            if(t->expr) {
                lit=getTypeAndValueOfExpression(t->expr);
                if(!isIntType(lit.type) || lit.value.i<=0) {
                    semantic_error(82, t->line, 0);
                    t->expr=0;
                }
                else
                    t->expr=lit.value.i;
            }
            i=sem_A_TYPE(t->element_type)*(int)t->expr;
            if(isVoidType(t->element_type) || isFunctionType(t->element_type))
                semantic_error(83, t->line, 0);
            else
                result=i;
            break;
        case T_STRUCT:
            id=t->field;
            while(id) {
                result+=sem_declaration(id, result);
                id=id->link;
            }
            break;
        case T_UNION:
            id=t->field;
            while(id) {
                i=sem_declaration(id, 0);
                if(i>result)
                    result=i;
                id=id->link;
            }
            break;
        case T_FUNC:
            tt=t->element_type;
            i=sem_A_TYPE(tt);
            if(isArrayType(tt) || isFunctionType(tt)) //check return type
                semantic_error(85, t->line, 0);
            i=sem_declaration_list(t->field, 12)+12; //parameter type and size;
            if(t->expr) { //skip prototype declaration
                i=i+sem_statement(t->expr, i, t->element_type, FALSE, FALSE, FALSE);}
            t->local_var_size=i;
            break;
        case T_POINTER:
            i=sem_A_TYPE(t->element_type);
            result=4;
            break;
        case T_VOID:
            break;
        default:
            semantic_error(90, t->line, 0);
            break;        
    }
    t->size=result;
    return (result);
}

//set variable address in declaration list, and return its total variable size
int sem_declaration_list(A_ID* id, int addr) {
    int i=addr;
    while(id) {
        addr+=sem_declaration(id, addr);
        id=id->link;
    }
    return (addr-i);
}

//check declaration(identifier), set address, and return its size
int sem_declaration(A_ID* id, int addr) {
    A_TYPE* t;
    int size=0, i;
    A_LITERAL lit;
    switch(id->kind) {
        case ID_VAR:
            i=sem_A_TYPE(id->type);
            //check empty array
            if(isArrayType(id->type) && id->type->expr==NIL)
                semantic_error(86, id->line, 0);
            if(i%4) i=i/4*4+4;
            if(id->specifier==S_STATIC)
                id->level=0;
            if(id->level==0) {
                id->address=global_address;
                global_address+=i;
            }
            else {
                id->address=addr;
                size=i;
            }
            break;
        case ID_FIELD:
            i=sem_A_TYPE(id->type);
            if(isFunctionType(id->type) || isVoidType(id->type))
                semantic_error(84, id->line, 0);
            if(i%4)
                i=i/4*4+4;
            id->address=addr;
            size=i;
            break;
        case ID_FUNC:
            i=sem_A_TYPE(id->type);
            break;
        case ID_PARM:
            if(id->type) {
                size=sem_A_TYPE(id->type);
                //usual unary convention of parm type
                if(id->type==char_type)
                    id->type=int_type;
                else if(isArrayType(id->type)) {
                    id->type->kind=T_POINTER;
                    id->type->size=4;
                }
                else if(isFunctionType(id->type)) {
                    t=makeType(T_POINTER);
                    t->element_type=id->type;
                    t->size=4;
                    id->type=t;
                }
                size=id->type->size;
                if(size%4)
                    size=size/4*4+4;
                id->address=addr;
            }
            break;
        case ID_TYPE:
            i=sem_A_TYPE(id->type);
            break;
        default:
            semantic_error(89, id->line, id->name);
            break;
    }
    return (size);
}
A_ID* getStructFieldIdentifier(A_TYPE* t, char* s) {
    A_ID *id=NIL;
    if(isStructOrUnionType(t)) {
        id=t->field;
        while(id) {
            if(strcmp(id->name, s)==0)
                break;
            id=id->link;
        }
    }
    return (id);
}
A_ID* getPointerFieldIdentifier(A_TYPE* t, char* s) {
    A_ID* id=NIL;
    if(t && t->kind == T_POINTER) {
        t=t->element_type;
        if(isStructOrUnionType(t)) {
            id=t->field;
            while(id) {
                if(strcmp(id->name, s)==0)
                    break;
                id=id->link;
            }
        }
    }
    return (id);
}
BOOLEAN isSameParameterType(A_ID* a, A_ID* b) {
    while(a) {
        if(b==NIL || isNotSameType(a->type, b->type))
            return (FALSE);
        a=a->link;
        b=b->link;
    }
    if(b) return (FALSE);
    else return (TRUE);
}

BOOLEAN isCompatibleType(A_TYPE* t1, A_TYPE* t2) {
    if(isArrayType(t1) && isArrayType(t2)) {
        if(t1->size==0 || t2->size==0 || t1->size == t2-> size)
            return (isCompatibleType(t1->element_type, t2->element_type));
        else
            return (FALSE);
    }
    else if(isFunctionType(t1) && isPointerType(t2)) {
        if(isSameParameterType(t1->field, t2->field))
            return (isCompatibleType(t1->element_type, t2->element_type));
        else   
            return (FALSE);
    }
    else if(isPointerType(t1) && isPointerType(t2))
        return(isCompatibleType(t1->element_type, t2->element_type));
    else
        return (t1==t2);
}

BOOLEAN isConstantZeroExp(A_NODE* node) {
    if(node->name==N_EXP_INT_CONST && node->clink==0)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isCompatiblePointerType(A_TYPE* t1, A_TYPE* t2) {
    if(isPointerType(t1) && isPointerType(t2))
        return (isCompatibleType(t1->element_type, t2->element_type));
    else
        return (FALSE);
}

A_NODE* convertScalarToInteger(A_NODE* node) {
    if(isFloatType(node->type)) {
        semantic_warning(16, node->line);
        node=makeNode(N_EXP_CAST, int_type, NIL, node);
    }
    node->type=int_type;
    return (node);
}

A_NODE* convertUsualAssignmentConversion(A_TYPE* t1, A_NODE* node) {
    A_TYPE* t2;
    t2=node->type;
    if(!isCompatibleType(t1, t2)) {
        semantic_warning(11, node->line);
        node=makeNode(N_EXP_CAST, t1, NIL, node);
        node->type=t1;
    }
    return (node);
}

A_NODE* convertUsualUnaryConversion(A_NODE* node) {
    A_TYPE* t;
    t=node->type;
    if(t==char_type) {
        t=int_type;
        node=makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isArrayType(t)) {
        t=setTypeElementType(makeType(T_POINTER), t->element_type);
        t->size=4;
        node=makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isFunctionType(t)) {
        t=setTypeElementType(makeType(T_POINTER), t);
        t->size=4;
        node=makeNode(N_EXP_AMP, NIL, node, NIL);
        node->type=t;
    }
    return (node);
}

A_TYPE* convertUsualBinaryConversion(A_NODE* node) {
    A_TYPE *t1, *t2, *result=NIL;
    t1=node->llink->type;
    t2=node->rlink->type;
    if(isFloatType(t1) && !isFloatType(t2)) {
        semantic_warning(14, node->line);
        node->rlink=makeNode(N_EXP_CAST, t1, NIL, node->rlink);
        node->rlink->type=t1;
        result=t1;
    }
    else if(!isFloatType(t1) && isFloatType(t2)) {
        semantic_warning(14, node->line);
        node->llink=makeNode(N_EXP_CAST, t2, NIL, node->llink);
        node->llink->type=t2;
        result=t2;
    }
    else if(t1==t2) 
        result=t1;
    else
        result=int_type;
    return (result);
}

A_NODE* convertCastingConversion(A_NODE* node, A_TYPE* t1) {
    A_TYPE* t2;
    t2=node->type;
    if(!isCompatibleType(t1, t2)) {
        semantic_warning(12, node->line);
        node=makeNode(N_EXP_CAST, t1, NIL, node);
        node->type=t1;
    }
    return (node);
}
BOOLEAN isAllowableAssignmentConversion(A_TYPE* t1, A_TYPE* t2, A_NODE* node) { //t1 <-- t2
    if(isArithmeticType(t1) && isArithmeticType(t2))
        return (TRUE);
    else if(isStructOrUnionType(t1) && isCompatibleType(t1, t2))
        return (TRUE);
    else if(isPointerType(t1) && (isConstantZeroExp(node) || isCompatiblePointerType(t1, t2)))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isAllowableCastingConversion(A_TYPE* t1, A_TYPE* t2) { // t1 <-- t2
    if(isAnyIntegerType(t1) && (isAnyIntegerType(t2) || isFloatType(t2) || isPointerType(t2)))
        return (TRUE);
    else if(isFloatType(t1) && isArithmeticType(t2))
        return (TRUE);
    else if(isPointerType(t1) && (isAnyIntegerType(t2) || isPointerType(t2)))
        return (TRUE);
    else if(isVoidType(t1))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isFloatType(A_TYPE*t) {
    if(t==float_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isArithmeticType(A_TYPE*t) {
    if(t && t->kind==T_ENUM)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isScalarType(A_TYPE*t) {
    if(t && ((t->kind==T_ENUM) || (t->kind==T_POINTER)))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isAnyIntegerType(A_TYPE* t) {
    if(t && (t==int_type || t==char_type))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isIntegralType(A_TYPE* t) {
    if(t && t->kind==T_ENUM && t!=float_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isFunctionType(A_TYPE* t) {
    if(t && t->kind==T_FUNC)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isStructOrUnionType(A_TYPE* t) {
    if(t && (t->kind==T_STRUCT || t->kind==T_UNION))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isPointerType(A_TYPE* t) {
    if(t && t->kind==T_POINTER)
        return (TRUE);
    else
        return (FALSE);

}

BOOLEAN isPointerOrArrayType(A_TYPE* t) {
    if(t && (t->kind==T_POINTER || t->kind==T_ARRAY))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isIntType(A_TYPE* t) {
    if(t && t==int_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isVoidType(A_TYPE* t) {
    if(t && t==void_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isArrayType(A_TYPE* t) {
    if(t && t->kind==T_ARRAY)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isStringType(A_TYPE* t) {
    if(t && (t->kind==T_POINTER||t->kind==T_ARRAY) && t->element_type==char_type)
        return (TRUE);
    else
        return (FALSE);
}

//convert literal type
A_LITERAL checkTypeAndConvertLiteral(A_LITERAL result, A_TYPE* t, int ll) {
    if(result.type==int_type && t==int_type ||
    result.type==char_type && t==char_type ||
    result.type==float_type && t==float_type);
    else if(result.type==int_type && t==float_type) {
        result.type=float_type;
        result.value.f=result.value.i;
    }
    else if(result.type==int_type && t==char_type) {
        result.type=char_type;
        result.value.c=result.value.i;
    }
    else if(result.type==float_type && t==int_type) {
        result.type=int_type;
        result.value.i=result.value.f;
    }
    else if(result.type==char_type && t==int_type) {
        result.type=int_type;
        result.value.i=result.value.c;
    }
    else
        semantic_error(41, ll, 0);
    return (result);
}

A_LITERAL getTypeAndValueOfExpression(A_NODE* node) {
	A_TYPE* t;
	A_ID* id;
	A_LITERAL result, r;
	result.type=NIL;
	switch(node->name) {
		case N_EXP_IDENT:
            id=node->clink;
            if(id->kind!=ID_ENUM_LITERAL)
                semantic_error(19, node->line, id->name);
            else {
                result.type=int_type;
                result.value.i=id->init;
            }
            break;
        case N_EXP_INT_CONST:
            result.type=int_type;
            result.value.i=(int)node->clink;
            break;
        case N_EXP_CHAR_CONST:
            result.type=char_type;
            result.value.c=(char)node->clink;
            break;
        case N_EXP_FLOAT_CONST:
            result.type=float_type;
            result.value.f=atof(node->clink);
            break;
        case N_EXP_STRING_LITERAL:
        case N_EXP_ARRAY:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_STRUCT:
        case N_EXP_ARROW:
        case N_EXP_POST_INC:
        case N_EXP_PRE_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_DEC:
        case N_EXP_AMP:
        case N_EXP_STAR:
        case N_EXP_NOT:
            semantic_error(18, node->line, 0);
            break;
        case N_EXP_MINUS:
            result=getTypeAndValueOfExpression(node->clink);
            if(result.type==int_type)
                result.value.i=-result.value.i;
            else if(result.type==float_type)
                result.value.f=-result.value.f;
            else    
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_SIZE_EXP:
            t=sem_expression(node->clink);
            result.type=int_type;
            result.value.i=t->size;
            break;
        case N_EXP_SIZE_TYPE:
            result.type=int_type;
            result.value.i=sem_A_TYPE(node->clink);
            break;
        case N_EXP_CAST:
            result=getTypeAndValueOfExpression(node->rlink);
            result=checkTypeAndConvertLiteral(result,(A_TYPE*)node->llink, node->line);
            break;
        case N_EXP_MUL:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i * r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i * r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f * r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f * r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_DIV:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i / r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i / r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f / r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f / r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_MOD:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type)
                result.value.i=result.value.i % r.value.i;
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_ADD:
             result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i + r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i + r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f + r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f + r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_SUB:
             result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i - r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i - r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f - r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f - r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            semantic_error(18, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    return (result);	
}
void semantic_error(int i, int ll, char* s) {
    semantic_err++;
    printf("*** semantic error at line %d: ",ll);
    switch(i) {
    //errors in expression
        case 13:
            printf("arith type expr required in unary expression\n");
            break;
        case 18:
            printf("illegal constant expression\n");
            break;
        case 19:
            printf("illegal indentifier %s in constant expression\n", s);
            break;
        case 21:
            printf("illegal type in function call expression\n");
            break;
        case 24:
            printf("incompatible type in additive expression\n");
            break;
        case 27:
            printf("scalar type expr required in expression\n");
            break;
        case 28:
            printf("arith type expression required in binary operation\n");
            break;
        case 29:
            printf("integral type expression required in expression\n");
            break;
        case 31:
            printf("pointer type expr required in pointer operation\n");
            break;
        case 32:
            printf("array type required in array expression\n");
            break;
        case 34:
            printf("too many arguments in function call\n");
            break;
        case 35:
            printf("too few arguments in function call\n");
            break;
        case 37:
            printf("illegal struct field identifier in struct reference expr\n");
            break;
        case 38:
            printf("illegal kind of identifier %s in expression\n", s);
            break;
        case 39:
            printf("illegal type size in sizeof operation\n");
            break;
        case 40:
            printf("illegal expression type in relational operation\n");
            break;
        case 41:
            printf("incompatible type in literal\n");
            break;
    //errors in statement
        case 49:
            printf("scalar type expr required in middle of for_expr\n"); 
            break;
        case 50:
            printf("integral type expression required in statement\n");
            break;
        case 51:
            printf("illegal expression type in case label\n");
            break;
        case 57:
            printf("not permitted type conversion in return expression\n");
            break;
        case 58:
            printf("not permitted type casting in expression\n");
            break;
        case 59:
            printf("not permitted type conversion in argument\n");
            break;
        case 60:
            printf("expression is not an lvalue\n");
            break;
        case 71:
            printf("case label not within a switch statement\n");
            break;
        case 72:
            printf("default label not within a switch statement\n");
            break;
        case 73:
            printf("break statement not within loop or switch stmt\n");
            break;
        case 74:
            printf("continue statement not within a loop\n");
            break;
    //errors in type & declarator
        case 80:
            printf("undefined type\n");
            break;
        case 81:
            printf("integer type expression required in enumerator\n");
            break;
        case 82:
            printf("illegal array size or type\n");
            break;
        case 83:
            printf("illegal element type of array declarator\n");
            break;
        case 84:
            printf("illegal type in struct or union field\n");
            break;
        case 85:
            printf("invalid function return type\n");
            break;
        case 86:
            printf("illegal array size or empty array\n");
            break;
        case 89:
            printf("unknown identifier kind: %s\n", s);
            break;
    //misc errors
        case 90:
            printf("fatal compiler error in parse result\n");
            break;
        case 93:
            printf("too many literals in source program\n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}
void semantic_warning(int i, int ll) {
    printf("--- warning at line %d:", ll);
    switch(i) {
        case 11:
            printf("incompatible types in assignment expression\n");
            break;
        case 12:
            printf("incompatible types in argument or return expr\n");
            break;
        case 14:
            printf("incompatible types in binary expression\n");
            break;
        case 16:
            printf("integer type expression is required\n");
            break;
        default:
            printf("unknown\n");
            break;
    }

}

void setTypeSize(A_TYPE* t, int i) {;} //호출된 적이 없음

// A7 Semantic tree printer /////////////////////////

void print_sem_ast(A_NODE* node){
    printf("========== semantic tree ==========\n");
    prt_sem_program(node, 0);
}
void prt_sem_program(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_PROGRAM:
            prt_sem_A_ID_LIST(node->clink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}
void prt_sem_initializer(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name){
        case N_INIT_LIST:
            prt_sem_initializer(node->llink, s+1);
            prt_sem_initializer(node->rlink, s+1);
            break;
        case N_INIT_LIST_ONE:
            prt_sem_expression(node->clink, s+1);
            break;
        case N_INIT_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");
    } 
}
void prt_sem_expression(A_NODE* node, int s){
    print_node(node,s);
    switch(node->name) {
        case N_EXP_IDENT : 
	        prt_sem_A_ID_NAME(node->clink, s+1);
		    break;
	    case N_EXP_INT_CONST :
		    prt_sem_integer(node->clink, s+1);
		    break;
	    case N_EXP_FLOAT_CONST :
 		    prt_sem_LITERAL(node->clink, s+1);
		    break;
	    case N_EXP_CHAR_CONST :
 		    prt_sem_integer(node->clink, s+1);
		    break;
	    case N_EXP_STRING_LITERAL :
		    prt_sem_LITERAL(node->clink, s+1);
		    break;
	    case N_EXP_ARRAY :
	    	prt_sem_expression(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
		    break;
	    case N_EXP_FUNCTION_CALL : 
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_arg_expr_list(node->rlink, s+1);
		    break;
	    case N_EXP_STRUCT :
            prt_sem_expression(node->llink, s+1);
            prt_sem_A_ID_NAME(node->rlink, s+1); 
            break;
        case N_EXP_ARROW : 
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_A_ID_NAME(node->rlink, s+1);
		    break;
	    case N_EXP_POST_INC :
	    case N_EXP_POST_DEC :
	    case N_EXP_PRE_INC :
	    case N_EXP_PRE_DEC :
	    case N_EXP_AMP :
	    case N_EXP_STAR :
	    case N_EXP_NOT :
	    case N_EXP_PLUS :
	    case N_EXP_MINUS :
            prt_sem_expression(node->clink, s+1);
            break;
	    case N_EXP_SIZE_EXP :
	    case N_EXP_SIZE_TYPE :
		    prt_sem_integer(node->clink, s+1);
   		    break;
	    case N_EXP_CAST :
		    prt_sem_A_TYPE(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
   		    break;
	    case N_EXP_MUL :
	    case N_EXP_DIV :
	    case N_EXP_MOD :
	    case N_EXP_ADD :
	    case N_EXP_SUB : 
	    case N_EXP_LSS :
	    case N_EXP_GTR :
	    case N_EXP_LEQ :
	    case N_EXP_GEQ :
	    case N_EXP_NEQ :
	    case N_EXP_EQL :
	    case N_EXP_AND :
	    case N_EXP_OR :
	    case N_EXP_ASSIGN :
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
   		    break;
	    default : 
		    printf("****** syntax tree error ******");
	}
}

void prt_sem_arg_expr_list(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_ARG_LIST:
            prt_sem_expression(node->llink, s+1);
            prt_sem_arg_expr_list(node->rlink, s+1);
            break;
        case N_ARG_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}

void prt_sem_statement(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            prt_sem_integer(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_LABEL_DEFAULT:
            prt_sem_statement(node->clink, s+1);
            break;
        case N_STMT_COMPOUND:
            if(node->llink) prt_sem_A_ID_LIST(node->llink, s+1);
            prt_sem_statement_list(node->rlink, s+1);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            prt_sem_expression(node->clink, s+1);
            break;
        case N_STMT_IF:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_IF_ELSE:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->clink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_SWITCH:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_WHILE:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_DO:
            prt_sem_statement(node->llink, s+1);
            prt_sem_expression(node->rlink, s+1);
            break;
        case N_STMT_FOR:
            prt_sem_for_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_CONTINUE:
            break;
        case N_STMT_BREAK:
            break;
        case N_STMT_RETURN:
            if(node->clink) prt_sem_expression(node->clink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}

void prt_sem_statement_list(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_STMT_LIST:
            prt_sem_statement(node->llink, s+1);
            prt_sem_statement_list(node->rlink, s+1);
            break;
        case N_STMT_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");            
    }

}

void prt_sem_for_expression(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_FOR_EXP:
            if(node->llink) prt_sem_expression(node->llink, s+1);
            if(node->clink) prt_sem_expression(node->clink, s+1);
            if(node->rlink) prt_sem_expression(node->rlink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");         
    } 
}

void prt_sem_integer(int a, int s){
    print_space(s);
    printf("INT=%d\n", a);
}

void prt_sem_LITERAL(int lit, int s){
    print_space(s);
    printf("LITERAL: ");
    if(literal_table[lit].type==int_type)
        printf("%d\n", literal_table[lit].value.i);
    if(literal_table[lit].type==float_type)
        printf("%f\n", literal_table[lit].value.f);
    else if(literal_table[lit].type==string_type)
        printf("%s\n", literal_table[lit].value.s);
}

void prt_sem_A_TYPE(A_TYPE* t, int s){
    print_space(s);
    if(t==int_type)
        printf("(int)\n");
    else if(t==float_type)
        printf("(float)\n");
    else if(t==char_type)
        printf("(char %d)\n", t->size);
    else if(t==void_type)
        printf("(void)\n");
    else if(t->kind==T_NULL)
        printf("(null)\n");
    else if(t->prt==FALSE)
        printf("(DONE:%x)\n", t);
    else {
        switch(t->kind) {
            case T_ENUM:
                t->prt=FALSE;
                printf("ENUM\n");
                print_space(s); printf("| ENUMERATORS\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_POINTER:
                t->prt=FALSE;
                printf("POINTER\n");
                print_space(s); printf("| ELEMENT_TYPE\n");
                prt_sem_A_TYPE(t->element_type, s+2);
                break;
            case T_ARRAY:
                t->prt=FALSE;
                printf("ARRAY\n");
                print_space(s); printf("| INDEX\n");
                prt_sem_integer(t->expr, s+2);
                print_space(s); printf("| ELEMENT_TYPE\n");
                prt_sem_A_TYPE(t->element_type,s+2);
                break;
            case T_STRUCT:
                t->prt=FALSE;
                printf("STRUCT\n");
                print_space(s); printf("| FIELD\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_UNION:
                t->prt=FALSE;
                printf("UNION\n");
                print_space(s); printf("| FIELD\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_FUNC:
                t->prt=FALSE;
                printf("FUNCTION\n");
                print_space(s); printf("| PARAMETER\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                print_space(s); printf("| TYPE\n");
                prt_sem_A_TYPE(t->element_type, s+2);
                if(t->expr) {
                    print_space(s); printf("| BODY\n");
                    prt_sem_statement(t->expr, s+2);
                }
                break;
        }
    }
}
void prt_sem_A_ID_LIST(A_ID* id, int s){
    while(id) {
        prt_sem_A_ID(id, s);
        id=id->link;
    }
}
void prt_sem_A_ID_NAME(A_ID* id, int s){
    print_space(s);
    printf("(ID=\"%s\") TYPE:%x KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
    id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier],
    id->level, id->value, id->address);
}

void prt_sem_A_ID(A_ID* id, int s){
    print_space(s);
    printf("(ID=\"%s\") TYPE:%x KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
    id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier],
    id->level, id->value, id->address);

    if(id->type) {
        print_space(s);
        printf("| TYPE\n");
        prt_sem_A_TYPE(id->type, s+2);
    }
    if(id->init) {
        print_space(s);
        printf("| INIT\n");
        if(id->kind==ID_ENUM_LITERAL) {
            if(id->init)
                prt_sem_integer(id->init, s+2);
            else
                prt_sem_initializer(id->init, s+2);
        }
    }
}

// A8 Code generator /////////////////////////////////////////////////

char* opcode_name[]={"OP_NULL", "LOD", "LDX", "LDXB", "LDA", "LITI", "STO", "STOB", "STX", "STXB", 
                "SUBI", "SUBF", "DIVI", "DIVF", "ADDI", "ADDF", "OFFSET", "MULI", "MULF", "MOD",
                "LSSI", "LSSF", "GTRI", "GTRF", "LEQI", "LEQF", "GEQI", "GEQF", "NEQI", "NEQF", "EQLI", "EQLF",
                "NOT", "OR", "AND", "CVTI", "CVTF", "JPC", "JPCR", "JMP", "JPT", "JPTR", "INT",
                "INCI", "INCF", "DECI", "DECF", "SUP", "CAL", "ADDR", "RET", "MINUSI", "MINUSF", "CHK",
                "LDI", "LDIB", "SWITCH", "SWVALUE", "SWDEFAULT", "SWLABEL", "SWEND",
                "POP", "POPB"};

void code_generation(A_NODE* node) {
    gen_program(node);
    gen_literal_table();
}

void gen_literal_table() {
    int i;
    for(i=1; i<=literal_no; i++) {
        fprintf(fout, ".literal %5d ", literal_table[i].addr);
        if(literal_table[i].type==int_type)
            fprintf(fout, "%d\n", literal_table[i].value.i);
        if(literal_table[i].type==float_type)
            fprintf(fout, "%f\n", literal_table[i].value.f);
        if(literal_table[i].type==char_type)
            fprintf(fout, "%d\n", literal_table[i].value.c);        
        if(literal_table[i].type==string_type)
            fprintf(fout, "%s\n", literal_table[i].value.s);                      
    }
}

void gen_program(A_NODE* node) {
    switch(node->name) {
        case N_PROGRAM:
            gen_code_i(INT, 0, node->value);
            gen_code_s(SUP, 0, "main");
            gen_code_i(RET, 0, 0);
            gen_declaration_list(node->clink);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }    
}

void gen_expression(A_NODE* node) {
    A_ID* id;
    A_TYPE* t;
    int i, ll;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            t=id->type;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    switch(t->kind) {
                        case T_ENUM:
                        case T_POINTER:
                            gen_code_i(LOD, id->level, id->address);
                            break;
                        case T_ARRAY:
                            if(id->kind==ID_VAR)
                                gen_code_i(LDA, id->level, id->address);
                            else
                                gen_code_i(LOD, id->level, id->address);
                            break;
                        case T_STRUCT:
                        case T_UNION:
                            gen_code_i(LDA, id->level, id->address);
                            i=id->type->size;
                            gen_code_i(LDI, 0, i%4?i/4+1:i/4);
                            break;
                        default:
                            gen_error(11, id->line, 0);
                            break;
                    }
                    break;
                case ID_ENUM_LITERAL:
                    gen_code_i(LITI, 0, id->init);
                    break;
                default:
                    gen_error(11, node->line, 0);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_FLOAT_CONST:
            i=node->clink;
            gen_code_i(LOD, 0, literal_table[i].addr);
            break;
        case N_EXP_CHAR_CONST:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_STRING_LITERAL:
            i=node->clink;
            gen_code_i(LDA, 0, literal_table[i].addr);
            break;
        case N_EXP_ARRAY:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            //gen_code_i(CHK, 0, node->llink->type->expr);
            if(node->type->size>1) {
                gen_code_i(LITI, 0, node->type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_code_i(OFFSET, 0, 0);
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_FUNCTION_CALL:
            t=node->llink->type;
            i=t->element_type->element_type->size;
            if(i%4) i=i/4*4+4;
            if(node->rlink) {
                gen_code_i(INT, 0, 12+i);
                gen_arg_expression(node->rlink);
                gen_code_i(POP, 0, node->rlink->value/4+3);
            }
            else
                gen_code_i(INT, 0, i);
            gen_expression(node->llink);
            gen_code_i(CAL, 0, 0);
            break;
        case N_EXP_STRUCT:
            gen_expression_left(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_ARROW:
            gen_expression(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_POST_INC:
            gen_expression(node->clink);
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(ADDI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(INCF, 0, 0);
            else
                gen_code_i(INCI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STOB, 0, 0);
            else
                gen_code_i(STO, 0, 1);
            break;
        case N_EXP_POST_DEC:
            gen_expression(node->clink);
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(SUBI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(DECF, 0, 0);
            else
                gen_code_i(DECI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STOB, 0, 0);
            else
                gen_code_i(STO, 0, 1);
            break;        
        case N_EXP_PRE_INC:
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(ADDI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(INCF, 0, 0);
            else
                gen_code_i(INCI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, 1);
            break;            
        case N_EXP_PRE_DEC:
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(SUBI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(DECF, 0, 0);
            else
                gen_code_i(DECI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, 1);
            break; 
        case N_EXP_NOT:
            gen_expression(node->clink);
            gen_code_i(NOT, 0, 0);
            break;
        case N_EXP_PLUS:
            gen_expression(node->clink);
            break;
        case N_EXP_MINUS:
            gen_expression(node->clink);
            if(isFloatType(node->clink))
                gen_code_i(MINUSF, 0, 0);
            else
                gen_code_i(MINUSI, 0, 0);
            break;
        case N_EXP_AMP:
            gen_expression_left(node->clink);
            break;
        case N_EXP_STAR:
            gen_expression(node->clink);
            i=node->type->size;
            if(i==1)
                gen_code_i(LDIB, 0, 0);
            else
                gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            break;
        case N_EXP_SIZE_EXP:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_SIZE_TYPE:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_CAST:
            gen_expression(node->rlink);
            if(node->type!=node->rlink->type)
                if(isFloatType(node->type))
                    gen_code_i(CVTF, 0, 0);
                else if(isFloatType(node->rlink->type))
                    gen_code_i(CVTI, 0, 0);
            break;
        case N_EXP_MUL:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->type))
                gen_code_i(MULF, 0, 0);
            else
                gen_code_i(MULI, 0, 0);
            break;
        case N_EXP_DIV:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->type))
                gen_code_i(DIVF, 0, 0);
            else
                gen_code_i(DIVI, 0, 0);
            break;
        case N_EXP_MOD:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            gen_code_i(MOD, 0, 0);
            break;
        case N_EXP_ADD:
            gen_expression(node->llink);
            if(isPointerOrArrayType(node->rlink->type)) {
                gen_code_i(LITI, 0, node->rlink->type->element_type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_expression(node->rlink);
            if(isPointerOrArrayType(node->llink->type)) {
                gen_code_i(LITI, 0, node->llink->type->element_type->size);
                gen_code_i(MULI, 0, 0);
            }
            if(isFloatType(node->type))
                gen_code_i(ADDF, 0, 0);
            else
                gen_code_i(ADDI, 0, 0);
            break;
        case N_EXP_SUB:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isPointerOrArrayType(node->llink->type) && !isPointerOrArrayType(node->rlink->type)) {
                    gen_code_i(LITI, 0, node->llink->type->element_type->size);
                    gen_code_i(MULI, 0, 0);
                }
            if(isFloatType(node->type))
                gen_code_i(SUBF, 0, 0);
            else
                gen_code_i(SUBI, 0, 0);
            break;
        case N_EXP_LSS:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(LSSF, 0, 0);
            else
                gen_code_i(LSSI, 0, 0);
            break;
        case N_EXP_GTR:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(GTRF, 0, 0);
            else
                gen_code_i(GTRI, 0, 0);
            break;            
        case N_EXP_LEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(LEQF, 0, 0);
            else
                gen_code_i(LEQI, 0, 0);
            break;
        case N_EXP_GEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(GEQF, 0, 0);
            else
                gen_code_i(GEQI, 0, 0);
            break;
        case N_EXP_NEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(NEQF, 0, 0);
            else
                gen_code_i(NEQI, 0, 0);
            break;
        case N_EXP_EQL:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(EQLF, 0, 0);
            else
                gen_code_i(EQLI, 0, 0);
            break;        
        case N_EXP_AND:
            gen_expression(node->llink);
            gen_code_l(JPCR, 0, i=get_label());
            gen_expression(node->rlink);
            gen_label_number(i);
            break;
        case N_EXP_OR:
            gen_expression(node->llink);
            gen_code_l(JPCR, 0, i=get_label());
            gen_expression(node->rlink);
            gen_label_number(i);
            break;
        case N_EXP_ASSIGN:
            gen_expression_left(node->llink);
            gen_expression(node->rlink);
            i=node->type->size;
            if(i==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, i%4?i/4+1:i/4);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_expression_left(A_NODE* node) {
    A_ID* id;
    A_TYPE* t;
    int result;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            t=id->type;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    switch(t->kind) {
                        case T_ENUM:
                        case T_POINTER:
                        case T_STRUCT:
                        case T_UNION:
                            gen_code_i(LDA, id->level, id->address);
                            break;                             
                        case T_ARRAY:                    
                            if(id->kind==ID_VAR)
                                gen_code_i(LDA, id->level, id->address);
                            else
                                gen_code_i(LOD, id->level, id->address);
                            break;
                        default:
                            gen_error(13, node->line, id->name);
                            break;
                    }
                    break;
                case ID_FUNC:
                    gen_code_s(ADDR, 0, id->name);
                    break;
                default:
                    gen_error(13, node->line, id->name);
                    break;
            }
            break;
        case N_EXP_ARRAY:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            //gen_code_i(CHK, 0, node->llink->type->expr);
            if(node->type->size>1) {
                gen_code_i(LITI, 0, node->type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_code_i(OFFSET, 0, 0);
            break;
        case N_EXP_STRUCT:
            gen_expression_left(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }         
            break;            
        case N_EXP_ARROW:
            gen_expression(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            break;
        case N_EXP_STAR:
            gen_expression(node->clink);
            break;   
        case N_EXP_INT_CONST: 
        case N_EXP_FLOAT_CONST:
        case N_EXP_CHAR_CONST:
        case N_EXP_STRING_LITERAL:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
        case N_EXP_NOT:
        case N_EXP_MINUS:
        case N_EXP_SIZE_EXP:
        case N_EXP_SIZE_TYPE:
        case N_EXP_CAST:
        case N_EXP_MUL:
        case N_EXP_DIV:
        case N_EXP_MOD:
        case N_EXP_ADD:
        case N_EXP_SUB:
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AMP:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            gen_error(12, node->line, 0);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_arg_expression(A_NODE* node) {
    A_NODE* n;
    switch(node->name) {
        case N_ARG_LIST:
            gen_expression(node->llink);
            gen_arg_expression(node->rlink);
            break;
        case N_ARG_LIST_NIL:
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

int get_label() {
    label_no++;
    return(label_no);
}

void gen_statement(A_NODE* node, int cont_label, int break_label, A_SWITCH sw[], int* sn) {
    A_SWITCH switch_table[100];
    int switch_no=0;
    A_NODE* n;
    int i, l1, l2, l3;
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            if(sw) {
                *sn=*sn+1;
                sw[*sn].kind=SW_VALUE;
                sw[*sn].val=node->llink;
                sw[*sn].label=l1=get_label();
                gen_label_number(l1);
            }
            else
                gen_error(21, node->line, 0);
            gen_statement(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_LABEL_DEFAULT:
            if(sw) {
                *sn=*sn+1;
                sw[*sn].kind=SW_DEFAULT;
                sw[*sn].label=l1=get_label();
                gen_label_number(l1); 
            }
            else
                gen_error(20, node->line, 0);
            gen_statement(node->clink, cont_label, break_label, sw, sn);
            break;           
        case N_STMT_COMPOUND:
            if(node->llink)
                gen_declaration_list(node->llink);
            gen_statement_list(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            n=node->clink;
            gen_expression(n);
            i=n->type->size;
            if(i)
                gen_code_i(POP, 0, i%4?i/4+1:i/4);
            break;
        case N_STMT_IF:
            gen_expression(node->llink);
            gen_code_l(JPC,0, l1=get_label());
            gen_statement(node->rlink, cont_label, break_label, 0, 0);
            gen_label_number(l1);
            break;
        case N_STMT_IF_ELSE:
            gen_expression(node->llink);
            gen_code_l(JPC,0, l1=get_label());
            gen_statement(node->clink, cont_label, break_label, 0, 0);
            gen_code_l(JMP, 0, l2=get_label());
            gen_label_number(l1);
            gen_statement(node->rlink, cont_label, break_label, 0, 0);
            gen_label_number(l2);
            break;
        case N_STMT_SWITCH:
            gen_expression(node->llink);
            gen_code_l(SWITCH, 0, l1=get_label());
            gen_code_l(JMP, 0, l2=get_label());
            gen_statement(node->rlink, cont_label, l2, switch_table, &switch_no);
            gen_label_number(l1);
            for(i=1; i<=switch_no; i++) {
                if(switch_table[i].kind==SW_VALUE)
                    gen_code_i(SWVALUE, 0, switch_table[i].val);
                else
                    gen_code_i(SWDEFAULT, 0, 0);
                gen_code_l(SWLABEL, 0, switch_table[i].label);
            }
            gen_code_i(SWEND, 0, 0);
            gen_label_number(l2);
            break;
        case N_STMT_WHILE:
            l3=get_label();
            gen_label_number(l1=get_label());
            gen_expression(node->llink);
            gen_code_l(JPC, 0, l2=get_label());
            gen_statement(node->rlink, l3, l2, 0, 0);
            gen_label_number(l3);
            gen_code_l(JMP, 0, l1);
            gen_label_number(l2);
            break;
        case N_STMT_DO:
            l3=get_label();
            l2=get_label();
            gen_label_number(l1=get_label());
            gen_statement(node->llink, l2, l3, 0, 0);
            gen_label_number(l2);
            gen_expression(node->rlink);
            gen_code_l(JPT, 0, l1);
            gen_label_number(l3);
            break;
        case N_STMT_FOR:
            n=node->llink;
            l3=get_label();
            if(n->llink) {
                gen_expression(n->llink);
                i=n->llink->type->size;
                if(i)
                    gen_code_i(POP, 0, i%4?i/4+1:i/4);
            }
            gen_label_number(l1=get_label());
            l2=get_label();
            if(n->clink) {
                gen_expression(n->clink);
                gen_code_l(JPC, 0, l2);
            }
            gen_statement(node->rlink, l3, l2, 0, 0);
            gen_label_number(l3);
            if(n->rlink) {
                gen_expression(n->rlink);
                i=n->rlink->type->size;
                if(i)
                    gen_code_i(POP, 0, i%4?i/4+1:i/4);
            }
            gen_code_l(JMP, 0, l1);
            gen_label_number(l2);
            break;
        case N_STMT_CONTINUE:
            if(cont_label)
                gen_code_l(JMP, 0, cont_label);
            else
                gen_error(22, node->line, 0);
            break;
        case N_STMT_BREAK:
            if(break_label)
                gen_code_l(JMP, 0, break_label);
            else
                gen_error(23, node->line, 0);
            break;
        case N_STMT_RETURN:
            n=node->clink;
            if(n) {
                i=n->type->size;
                if(i%4) i=i/4*4+4;
                gen_code_i(LDA, 1, -i);
                gen_expression(n);
                gen_code_i(STO, 0, i/4);
            }
            gen_code_i(RET, 0, 0);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_statement_list(A_NODE* node, int cont_label, int break_label, A_SWITCH sw[], int* sn) {
    switch(node->name) {
        case N_STMT_LIST:
            gen_statement(node->llink, cont_label, break_label, sw, sn);
            gen_statement_list(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_LIST_NIL:
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_initializer_global(A_NODE* node, A_TYPE* t, int addr) {
    ;
}

void gen_initializer_local(A_NODE* node, A_TYPE* t, int addr) {
    ;
}

void gen_declaration_list(A_ID* id) {
    while(id) {
        gen_declaration(id);
        id=id->link;
    }
}

void gen_declaration(A_ID* id) {
    int i;
    A_NODE* node;
    switch(id->kind) {
        case ID_VAR:
            if(id->init) {
                if(id->level==0)
                    gen_initializer_global(id->init, id->type, id->address);
                else
                    gen_initializer_local(id->init, id->type, id->address);
            }
            break;                
        case ID_FUNC:
            if(id->type->expr) {
                gen_label_name(id->name);
                gen_code_i(INT, 0, id->type->local_var_size);
                gen_statement(id->type->expr, 0, 0, 0, 0);
                gen_code_i(RET, 0, 0);
            }
            break;
        case ID_PARM:
        case ID_TYPE:
        case ID_ENUM:
        case ID_STRUCT:
        case ID_FIELD:
        case ID_ENUM_LITERAL:
        case ID_NULL:
            break;
        default:
            gen_error(100, id->line, 0);
            break;
    }
}

void gen_error(int i, int ll, char*s) {
    gen_err++;
    printf("*** error at line %d: ", ll);
    switch(i) {
        case 11:
            printf("illegal identifier in expression \n");
            break;
        case 12:
            printf("illegal l-value expression \n");
            break;
        case 13:
            printf("identifier %s not l-value expression \n", s);
            break;
        case 20:
            printf("illegal default label in switch statement \n");
            break;
        case 21:
            printf("illegal case label in switch statement \n");
            break;
        case 22:
            printf("no destination for continue statement \n");
            break;
        case 23:
            printf("no destination for break statement \n");
            break;
        case 100:
            printf("fatal compiler error during code generation \n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}

void gen_code_i(OPCODE op, int l, int a) {
    fprintf(fout, "\t%9s  %d, %d\n", opcode_name[op], l, a);
}

void gen_code_f(OPCODE op, int l, float a) {
    fprintf(fout, "\t%9s  %d, %f\n", opcode_name[op], l, a);
}

void gen_code_s(OPCODE op, int l, char* a) {
    fprintf(fout, "\t%9s  %d, %s\n", opcode_name[op], l, a);
}

void gen_code_l(OPCODE op, int l, int a) {
    fprintf(fout, "\t%9s  %d, L%d\n", opcode_name[op], l, a);
}

void gen_label_number(int i) {
    fprintf(fout, "L%d:\n", i);
} 

void gen_label_name(char* s) {
    fprintf(fout, "%s:\n", s);
}                
