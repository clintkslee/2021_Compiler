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

#include "type.h"
#define YYSTYPE_IS_DECLARED  1
typedef union{ 
	char cval; 
	int ival; 
	char* pval; 
	A_NODE* anode;
	A_TYPE* atype;
	A_SPECIFIER* aspec;
	A_ID* aid;
	S_KIND skind;
	T_KIND tkind;
} YYSTYPE;

A_NODE* makeNode(NODE_NAME, A_NODE*, A_NODE*, A_NODE*);
A_NODE* makeNodeList(NODE_NAME, A_NODE*, A_NODE*);
A_ID* makeIdentifier(char*);
A_ID* makeDummyIdentifier();
A_TYPE* makeType(T_KIND);
A_SPECIFIER* makeSpecifier(A_TYPE*, S_KIND);
A_ID* searchIdentifier(char*, A_ID*);
A_ID* searchIdentifierAtCurrentLevel(char*, A_ID*);
A_SPECIFIER* updateSpecifier(A_SPECIFIER*, A_TYPE*, S_KIND);
void checkForwardReference();
void setDefaultSpecifier(A_SPECIFIER*);
A_ID* linkDeclaratorList(A_ID*, A_ID*);
A_ID* getIdentifierDeclared(char*);
A_TYPE* getTypeOfStructOrEnumRefIdentifier(T_KIND, char*, ID_KIND);
A_ID* setDeclaratorInit(A_ID*, A_NODE*);
A_ID* setDeclaratorKind(A_ID*, ID_KIND);
A_ID* setDeclaratorType(A_ID*, A_TYPE*);
A_ID* setDeclaratorElementType(A_ID*, A_TYPE*);
A_ID* setDeclaratorTypeAndKind(A_ID*, A_TYPE*, ID_KIND);
A_ID* setDeclaratorListSpecifier(A_ID*, A_SPECIFIER*);
A_ID* setFunctionDeclaratorSpecifier(A_ID*, A_SPECIFIER*);
A_ID* setFunctionDeclaratorBody(A_ID*, A_NODE*);
A_ID* setParameterDeclaratorSpecifier(A_ID*, A_SPECIFIER*);
A_ID* setStructDeclaratorListSpecifier(A_ID*, A_TYPE*);
A_TYPE* setTypeNameSpecifier(A_TYPE*, A_SPECIFIER*);
A_TYPE* setTypeElementType(A_TYPE*, A_TYPE*);
A_TYPE* setTypeField(A_TYPE*, A_ID*);
A_TYPE* setTypeExpr(A_TYPE*, A_NODE*);
A_TYPE* setTypeAndKindOfDeclarator(A_TYPE*, ID_KIND, A_ID*);
A_TYPE* setTypeStructOrEnumIdentifier(T_KIND, char*, ID_KIND);
BOOLEAN isNotSameFormalParameters(A_ID*, A_ID*);
BOOLEAN isNotSameType(A_TYPE*, A_TYPE*);
BOOLEAN isPointerOrArrayType(A_TYPE*);
void syntax_error(int, char*);
void initialize();

/////////////////////////////////////////////////

void print_ast(A_NODE *);
void prt_program(A_NODE *, int);
void prt_initializer(A_NODE *, int);
void prt_arg_expr_list(A_NODE *, int);
void prt_statement(A_NODE *, int);
void prt_statement_list(A_NODE *, int);
void prt_for_expression(A_NODE *, int);
void prt_expression(A_NODE *, int);
void prt_A_TYPE(A_TYPE *, int);
void prt_A_ID_LIST(A_ID *, int);
void prt_A_ID(A_ID *, int);
void prt_A_ID_NAME(A_ID *, int);
void prt_STRING(char *, int);
void prt_integer(int, int);
void print_node(A_NODE *,int);
void print_space(int);

///////////////////////////////////////////////////

void yyerror(char*);
int yywrap(void);
extern int yylex (void);
extern char *yytext;
A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;
A_NODE *root;
A_ID *current_id=NIL;
int syntax_err=0;
int line_no=1;
int current_level=0;

#line 154 "y.tab.c"

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
    BAR = 268,
    AMP = 269,
    BARBAR = 270,
    AMPAMP = 271,
    ARROW = 272,
    SEMICOLON = 273,
    LSS = 274,
    GTR = 275,
    LEQ = 276,
    GEQ = 277,
    EQL = 278,
    NEQ = 279,
    DOTDOTDOT = 280,
    LP = 281,
    RP = 282,
    LB = 283,
    RB = 284,
    LR = 285,
    RR = 286,
    PERIOD = 287,
    COMMA = 288,
    EXCL = 289,
    STAR = 290,
    SLASH = 291,
    PERCENT = 292,
    ASSIGN = 293,
    COLON = 294,
    AUTO_SYM = 295,
    STATIC_SYM = 296,
    TYPEDEF_SYM = 297,
    STRUCT_SYM = 298,
    ENUM_SYM = 299,
    SIZEOF_SYM = 300,
    UNION_SYM = 301,
    IF_SYM = 302,
    ELSE_SYM = 303,
    WHILE_SYM = 304,
    DO_SYM = 305,
    FOR_SYM = 306,
    CONTINUE_SYM = 307,
    BREAK_SYM = 308,
    RETURN_SYM = 309,
    SWITCH_SYM = 310,
    CASE_SYM = 311,
    DEFAULT_SYM = 312
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
#define BAR 268
#define AMP 269
#define BARBAR 270
#define AMPAMP 271
#define ARROW 272
#define SEMICOLON 273
#define LSS 274
#define GTR 275
#define LEQ 276
#define GEQ 277
#define EQL 278
#define NEQ 279
#define DOTDOTDOT 280
#define LP 281
#define RP 282
#define LB 283
#define RB 284
#define LR 285
#define RR 286
#define PERIOD 287
#define COMMA 288
#define EXCL 289
#define STAR 290
#define SLASH 291
#define PERCENT 292
#define ASSIGN 293
#define COLON 294
#define AUTO_SYM 295
#define STATIC_SYM 296
#define TYPEDEF_SYM 297
#define STRUCT_SYM 298
#define ENUM_SYM 299
#define SIZEOF_SYM 300
#define UNION_SYM 301
#define IF_SYM 302
#define ELSE_SYM 303
#define WHILE_SYM 304
#define DO_SYM 305
#define FOR_SYM 306
#define CONTINUE_SYM 307
#define BREAK_SYM 308
#define RETURN_SYM 309
#define SWITCH_SYM 310
#define CASE_SYM 311
#define DEFAULT_SYM 312

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
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

#define YYUNDEFTOK  2
#define YYMAXUTOK   312


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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   113,   114,   117,   118,   121,   121,   123,
     123,   127,   128,   131,   132,   135,   138,   139,   140,   141,
     144,   145,   146,   149,   150,   153,   154,   157,   158,   161,
     162,   165,   166,   169,   170,   171,   174,   175,   174,   177,
     178,   177,   180,   183,   184,   187,   188,   191,   194,   195,
     198,   201,   201,   203,   203,   205,   208,   209,   212,   213,
     213,   217,   218,   221,   222,   225,   226,   227,   228,   228,
     232,   233,   236,   237,   240,   241,   244,   245,   248,   249,
     252,   253,   254,   257,   258,   259,   260,   261,   264,   265,
     268,   269,   272,   273,   274,   275,   276,   277,   280,   281,
     284,   284,   290,   291,   294,   295,   296,   299,   300,   301,
     304,   307,   308,   311,   312,   313,   316,   317,   320,   321,
     324,   325,   328,   331,   334,   337,   338,   341,   344,   345,
     348,   349,   352,   355,   358,   361,   362,   363,   366,   367,
     368,   369,   370,   373,   376,   377,   378,   381,   382,   383,
     384,   387,   388,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   403,   404,   405,   406,   407,   408,   409,
     412,   413,   414,   415,   416,   417,   420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT_CONSTANT", "STRING_LITERAL",
  "IDENTIFIER", "CHARACTER_CONSTANT", "TYPE_IDENTIFIER",
  "INTEGER_CONSTANT", "PLUS", "MINUS", "PLUSPLUS", "MINUSMINUS", "BAR",
  "AMP", "BARBAR", "AMPAMP", "ARROW", "SEMICOLON", "LSS", "GTR", "LEQ",
  "GEQ", "EQL", "NEQ", "DOTDOTDOT", "LP", "RP", "LB", "RB", "LR", "RR",
  "PERIOD", "COMMA", "EXCL", "STAR", "SLASH", "PERCENT", "ASSIGN", "COLON",
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
     305,   306,   307,   308,   309,   310,   311,   312
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
     176,  -220,  -220,    25,    15,  -220,  -220,  -220,  -220,    57,
    -220,   100,   176,  -220,  -220,  -220,    25,    92,    92,  -220,
      98,  -220,  -220,    23,    19,   110,  -220,    67,    94,  -220,
    -220,   109,   107,  -220,    50,  -220,  -220,   129,   131,   133,
      19,  -220,    29,  -220,   140,   141,  -220,    25,   359,   133,
     144,  -220,  -220,  -220,    92,  -220,  -220,  -220,  -220,  -220,
      29,    29,   372,   372,    29,   315,    29,    29,   410,   120,
    -220,  -220,  -220,  -220,  -220,   151,   168,  -220,  -220,  -220,
      52,   311,  -220,   101,    70,  -220,   147,   270,  -220,   141,
     148,    54,  -220,  -220,   159,   359,  -220,  -220,  -220,  -220,
      35,    92,   116,   171,  -220,   166,  -220,  -220,  -220,  -220,
      29,  -220,  -220,  -220,     1,   177,   178,  -220,  -220,   315,
    -220,  -220,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,  -220,  -220,   201,    29,
      29,   204,    58,   172,  -220,   141,  -220,    63,    35,    25,
      85,  -220,   260,    92,  -220,    25,   136,    29,  -220,    39,
    -220,  -220,    97,  -220,   385,   186,   119,  -220,  -220,    29,
     188,   168,  -220,   311,   311,  -220,  -220,  -220,  -220,    70,
      70,  -220,  -220,  -220,  -220,  -220,   196,   180,  -220,   195,
    -220,  -220,    29,  -220,  -220,   359,   200,    36,  -220,  -220,
    -220,  -220,  -220,   199,   207,   260,   209,   219,   220,    29,
     213,    29,   202,   211,   260,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,   227,  -220,   221,   222,   238,    97,    92,    29,
    -220,  -220,  -220,  -220,  -220,    29,  -220,  -220,  -220,  -220,
    -220,    25,    29,    29,   224,    29,  -220,  -220,   257,  -220,
      29,   237,   260,  -220,  -220,  -220,  -220,  -220,  -220,   250,
     251,  -220,  -220,   252,   256,   258,   261,   267,  -220,   262,
     260,  -220,  -220,  -220,   260,   260,    29,   260,    29,   260,
    -220,   243,  -220,   265,  -220,   275,  -220,   260,   281,    29,
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
    -220,  -220,  -220,   288,  -220,  -220,  -220,  -220,  -220,   -80,
       7,  -220,  -220,  -220,   254,   -83,  -220,   -92,  -220,  -220,
    -220,  -220,  -220,  -220,   155,  -130,  -220,    65,  -220,  -220,
    -220,   215,   163,  -220,    -1,     0,   -20,  -220,   -53,  -220,
    -220,   164,   225,  -134,   -73,  -220,  -220,  -157,  -220,    22,
    -220,  -220,  -220,  -220,  -220,  -219,  -220,  -220,  -220,  -139,
     -43,   -42,  -220,  -126,  -220,  -220,   216,   217,  -220,  -220,
    -220,    33,   208,  -220,    42,   -50,   128,  -220,  -220,   223
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
     201,   154,   225,   115,    35,    36,   267,   165,     1,   157,
       1,   225,    55,    56,    57,    58,     4,    59,    60,    61,
      62,    63,     2,    64,     1,    41,    94,    42,   244,     3,
       4,     3,    97,    71,   240,    65,   149,   254,   149,   285,
       4,    53,    27,    66,    67,   156,   201,   157,   115,   241,
     292,    98,   114,   223,    68,   124,   125,   115,     8,     9,
      -7,    10,   181,   182,   183,   144,   227,   145,    48,   191,
     260,   145,     2,   227,   194,   271,   195,   -51,   189,     2,
      29,   158,   159,    37,   149,   132,   133,   134,   155,   261,
     130,   131,   238,   280,   166,    71,   200,   281,   282,   232,
     284,     1,   286,   228,    45,   229,   114,    46,     8,     9,
     290,    10,     5,     6,     7,     8,     9,    43,    10,    40,
      47,     1,   156,     2,   157,   165,    90,   157,   199,   121,
     237,     4,    97,    71,    94,    25,   159,   173,   174,   -36,
     155,    51,   156,    52,   157,   166,   122,   249,   251,    71,
      89,     4,   179,   180,    99,   259,     5,     6,     7,     8,
       9,     1,    10,     2,   123,   135,   -59,    71,   108,   108,
     111,   112,   108,     2,   108,   108,   120,    48,   163,   164,
     263,   264,     3,   249,   168,   169,   185,     2,   269,   190,
     192,     4,   165,   235,   157,   233,     5,     6,     7,     8,
       9,     4,    10,   234,   236,   242,     5,     6,     7,     8,
       9,   239,    10,   243,   283,   245,   249,   246,   247,   250,
     199,   252,   253,     8,     9,   255,    10,   249,   256,   257,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    55,    56,    57,    58,   258,    59,    60,
      61,    62,    63,   265,    64,   268,   270,   272,   202,   274,
     273,   136,   137,   275,   276,   278,    65,   138,   277,   279,
      52,   287,   288,   289,    66,    67,   139,   108,   140,   291,
      30,    93,   141,   196,   142,    68,   262,   203,   193,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    55,    56,
      57,    58,     2,    59,    60,    61,    62,    63,   231,    64,
     126,   127,   128,   129,   175,   176,   177,   178,   171,   167,
     172,    65,   170,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      68,    10,    55,    56,    57,    58,     0,    59,    60,    61,
      62,    63,     0,    64,     0,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    65,    64,     0,     0,    95,
       0,     0,     2,    66,    67,     0,     0,     0,   110,     0,
       0,     0,     0,     0,    68,     0,    66,    67,     0,     0,
     230,     0,     0,    55,    56,    57,    58,    68,    59,    60,
      61,    62,    63,     0,    64,     5,     6,     7,     8,     9,
       0,    10,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      42,    54,     3,    23,     4,    48,    48,     0,   100,   135,
      60,    61,    95,   139,    64,    16,    66,    67,   157,    12,
     150,   101,   156,    65,    17,    18,   245,    26,     5,    28,
       5,   165,     3,     4,     5,     6,    35,     8,     9,    10,
      11,    12,     7,    14,     5,    26,    47,    28,   205,    26,
      35,    26,    95,    95,    18,    26,   148,   214,   150,   278,
      35,    39,     5,    34,    35,    26,   196,    28,   110,    33,
     289,    49,    65,   153,    45,    23,    24,   119,    43,    44,
      30,    46,   132,   133,   134,    31,   159,    33,    38,    31,
     229,    33,     7,   166,    31,   252,    33,    30,   140,     7,
       0,   102,   102,     5,   196,    35,    36,    37,   101,   235,
       9,    10,   195,   270,   114,   157,    31,   274,   275,   169,
     277,     5,   279,    26,    30,    28,   119,    18,    43,    44,
     287,    46,    40,    41,    42,    43,    44,    27,    46,   159,
      33,     5,    26,     7,    28,    26,     5,    28,   149,    29,
     192,    35,   195,   195,   155,   156,   156,   124,   125,    30,
     153,    30,    26,    30,    28,   165,    15,   209,   211,   211,
      30,    35,   130,   131,    30,   228,    40,    41,    42,    43,
      44,     5,    46,     7,    16,    38,    38,   229,    60,    61,
      62,    63,    64,     7,    66,    67,    68,    38,    27,    33,
     242,   243,    26,   245,    27,    27,     5,     7,   250,     5,
      38,    35,    26,    33,    28,    27,    40,    41,    42,    43,
      44,    35,    46,    27,    29,    26,    40,    41,    42,    43,
      44,    31,    46,    26,   276,    26,   278,    18,    18,    26,
     241,    39,    31,    43,    44,    18,    46,   289,    27,    27,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     3,     4,     5,     6,    29,     8,     9,
      10,    11,    12,    49,    14,    18,    39,    27,    18,    27,
      29,    11,    12,    27,    26,    18,    26,    17,    27,    27,
      30,    48,    27,    18,    34,    35,    26,   169,    28,    18,
      12,    47,    32,   148,    89,    45,   241,    47,   145,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   164,    14,
      19,    20,    21,    22,   126,   127,   128,   129,   122,   114,
     123,    26,   119,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    14,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    12,    26,    14,    -1,    -1,    30,
      -1,    -1,     7,    34,    35,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    34,    35,    -1,    -1,
      25,    -1,    -1,     3,     4,     5,     6,    45,     8,     9,
      10,    11,    12,    -1,    14,    40,    41,    42,    43,    44,
      -1,    46,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    26,    35,    40,    41,    42,    43,    44,
      46,    59,    60,    61,    62,    67,    68,    69,    75,    76,
      81,    86,    92,    93,    94,    92,    93,     5,    88,     0,
      61,    70,    71,    72,    92,    68,    68,     5,    79,    64,
      94,    26,    28,    27,    87,    30,    18,    33,    38,    63,
      77,    30,    30,   107,    95,     3,     4,     5,     6,     8,
       9,    10,    11,    12,    14,    26,    34,    35,    45,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    30,
       5,    89,    90,    72,    92,    30,    73,   118,   107,    30,
      80,   108,    68,    96,    97,    98,    99,   133,   134,   133,
      26,   134,   134,   133,    68,   119,   137,   133,   133,    26,
     134,    29,    15,    16,    23,    24,    19,    20,    21,    22,
       9,    10,    35,    36,    37,    38,    11,    12,    17,    26,
      28,    32,    89,    91,    31,    33,    73,    74,    78,    75,
      82,    83,    65,    66,    67,    68,    26,    28,    92,    93,
     100,   101,   102,    27,    33,    26,    93,   100,    27,    27,
     137,   124,   125,   129,   129,   130,   130,   130,   130,   132,
     132,   133,   133,   133,   121,     5,   115,   116,   121,   119,
       5,    31,    38,    90,    31,    33,    82,    84,    85,    92,
      31,    83,    18,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   103,   104,   105,   106,   107,   109,   110,
     111,   114,   119,    67,    96,   101,   117,   102,    26,    28,
      25,    99,   133,    27,    27,    33,    29,   119,    73,    31,
      18,    33,    26,    26,   105,    26,    18,    18,   113,   119,
      26,   118,    39,    31,   105,    18,    27,    27,    29,    96,
     117,   121,    85,   119,   119,    49,   112,   113,    18,   119,
      39,   105,    27,    29,    27,    27,    26,    27,    18,    27,
     105,   105,   105,   119,   105,   113,   105,    48,    27,    18,
     105,    18,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    63,    62,    64,
      62,    65,    65,    66,    66,    67,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    77,    78,    76,    79,
      80,    76,    76,    81,    81,    82,    82,    83,    84,    84,
      85,    87,    86,    88,    86,    86,    89,    89,    90,    91,
      90,    92,    92,    93,    93,    94,    94,    94,    95,    94,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   106,
     108,   107,   109,   109,   110,   110,   110,   111,   111,   111,
     112,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   119,   120,   121,   121,   122,   123,   123,
     124,   124,   125,   126,   127,   128,   128,   128,   129,   129,
     129,   129,   129,   130,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   137
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
#line 110 "kim.y"
                                {root=makeNode(N_PROGRAM, NIL, (yyvsp[0].aid), NIL); checkForwardReference();}
#line 1758 "y.tab.c"
    break;

  case 3:
#line 113 "kim.y"
                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1764 "y.tab.c"
    break;

  case 4:
#line 114 "kim.y"
                                                {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 1770 "y.tab.c"
    break;

  case 5:
#line 117 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1776 "y.tab.c"
    break;

  case 6:
#line 118 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1782 "y.tab.c"
    break;

  case 7:
#line 121 "kim.y"
                                                {(yyval.aid)=setFunctionDeclaratorSpecifier((yyvsp[0].aid), (yyvsp[-1].aspec));}
#line 1788 "y.tab.c"
    break;

  case 8:
#line 122 "kim.y"
                                                {(yyval.aid)=setFunctionDeclaratorBody((yyvsp[-1].aid), (yyvsp[0].anode));}
#line 1794 "y.tab.c"
    break;

  case 9:
#line 123 "kim.y"
                                                {(yyval.aid)=setFunctionDeclaratorSpecifier((yyvsp[0].aid), makeSpecifier(int_type, 0));}
#line 1800 "y.tab.c"
    break;

  case 10:
#line 124 "kim.y"
                                                {(yyval.aid)=setFunctionDeclaratorBody((yyvsp[-1].aid), (yyvsp[0].anode));}
#line 1806 "y.tab.c"
    break;

  case 11:
#line 127 "kim.y"
                                {(yyval.aid)=NIL;}
#line 1812 "y.tab.c"
    break;

  case 12:
#line 128 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1818 "y.tab.c"
    break;

  case 13:
#line 131 "kim.y"
                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1824 "y.tab.c"
    break;

  case 14:
#line 132 "kim.y"
                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 1830 "y.tab.c"
    break;

  case 15:
#line 135 "kim.y"
                                                                        {(yyval.aid)=setDeclaratorListSpecifier((yyvsp[-1].aid), (yyvsp[-2].aspec));}
#line 1836 "y.tab.c"
    break;

  case 16:
#line 138 "kim.y"
                                                        {(yyval.aspec)=makeSpecifier((yyvsp[0].atype), 0);}
#line 1842 "y.tab.c"
    break;

  case 17:
#line 139 "kim.y"
                                                                {(yyval.aspec)=makeSpecifier(0, (yyvsp[0].skind));}
#line 1848 "y.tab.c"
    break;

  case 18:
#line 140 "kim.y"
                                                        {(yyval.aspec)=updateSpecifier((yyvsp[0].aspec), (yyvsp[-1].atype), 0);}
#line 1854 "y.tab.c"
    break;

  case 19:
#line 141 "kim.y"
                                                        {(yyval.aspec)=updateSpecifier((yyvsp[0].aspec), 0, (yyvsp[-1].skind));}
#line 1860 "y.tab.c"
    break;

  case 20:
#line 144 "kim.y"
                        {(yyval.skind)=S_AUTO;}
#line 1866 "y.tab.c"
    break;

  case 21:
#line 145 "kim.y"
                        {(yyval.skind)=S_STATIC;}
#line 1872 "y.tab.c"
    break;

  case 22:
#line 146 "kim.y"
                        {(yyval.skind)=S_TYPEDEF;}
#line 1878 "y.tab.c"
    break;

  case 23:
#line 149 "kim.y"
                                {(yyval.aid)=makeDummyIdentifier();}
#line 1884 "y.tab.c"
    break;

  case 24:
#line 150 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1890 "y.tab.c"
    break;

  case 25:
#line 153 "kim.y"
                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 1896 "y.tab.c"
    break;

  case 26:
#line 154 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 1902 "y.tab.c"
    break;

  case 27:
#line 157 "kim.y"
                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 1908 "y.tab.c"
    break;

  case 28:
#line 158 "kim.y"
                                        {(yyval.aid)=setDeclaratorInit((yyvsp[-2].aid), (yyvsp[0].anode));}
#line 1914 "y.tab.c"
    break;

  case 29:
#line 161 "kim.y"
                                        {(yyval.anode)=makeNode(N_INIT_LIST_ONE, NIL, (yyvsp[0].anode), NIL);}
#line 1920 "y.tab.c"
    break;

  case 30:
#line 162 "kim.y"
                                {(yyval.anode)=(yyvsp[-1].anode);}
#line 1926 "y.tab.c"
    break;

  case 31:
#line 165 "kim.y"
                                                {(yyval.anode)=makeNode(N_INIT_LIST, (yyvsp[0].anode), NIL, makeNode(N_INIT_LIST_NIL, NIL, NIL, NIL));}
#line 1932 "y.tab.c"
    break;

  case 32:
#line 166 "kim.y"
                                                {(yyval.anode)=makeNodeList(N_INIT_LIST, (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 1938 "y.tab.c"
    break;

  case 33:
#line 169 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 1944 "y.tab.c"
    break;

  case 34:
#line 170 "kim.y"
                        {(yyval.atype)=(yyvsp[0].atype);}
#line 1950 "y.tab.c"
    break;

  case 35:
#line 171 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 1956 "y.tab.c"
    break;

  case 36:
#line 174 "kim.y"
                                        {(yyval.atype)=setTypeStructOrEnumIdentifier((yyvsp[-1].tkind), (yyvsp[0].pval), ID_STRUCT);}
#line 1962 "y.tab.c"
    break;

  case 37:
#line 175 "kim.y"
                                        {(yyval.aid)=current_id; current_level++;}
#line 1968 "y.tab.c"
    break;

  case 38:
#line 176 "kim.y"
                                        {checkForwardReference(); (yyval.atype)=setTypeField((yyvsp[-4].atype), (yyvsp[-1].aid)); current_level--; current_id=(yyvsp[-2].aid);}
#line 1974 "y.tab.c"
    break;

  case 39:
#line 177 "kim.y"
                                        {(yyval.atype)=makeType((yyvsp[0].tkind));}
#line 1980 "y.tab.c"
    break;

  case 40:
#line 178 "kim.y"
                                        {(yyval.aid)=current_id; current_level++;}
#line 1986 "y.tab.c"
    break;

  case 41:
#line 179 "kim.y"
                                        {checkForwardReference(); (yyval.atype)=setTypeField((yyvsp[-4].atype), (yyvsp[-1].aid)); current_level--; current_id=(yyvsp[-2].aid);}
#line 1992 "y.tab.c"
    break;

  case 42:
#line 180 "kim.y"
                                        {getTypeOfStructOrEnumRefIdentifier((yyvsp[-1].tkind), (yyvsp[0].pval), ID_STRUCT);}
#line 1998 "y.tab.c"
    break;

  case 43:
#line 183 "kim.y"
                        {(yyval.tkind)=T_STRUCT;}
#line 2004 "y.tab.c"
    break;

  case 44:
#line 184 "kim.y"
                        {(yyval.tkind)=T_UNION;}
#line 2010 "y.tab.c"
    break;

  case 45:
#line 187 "kim.y"
                                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2016 "y.tab.c"
    break;

  case 46:
#line 188 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-1].aid), (yyvsp[0].aid));}
#line 2022 "y.tab.c"
    break;

  case 47:
#line 191 "kim.y"
                                                                {(yyval.aid)=setStructDeclaratorListSpecifier((yyvsp[-1].aid), (yyvsp[-2].atype));}
#line 2028 "y.tab.c"
    break;

  case 48:
#line 194 "kim.y"
                                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 2034 "y.tab.c"
    break;

  case 49:
#line 195 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 2040 "y.tab.c"
    break;

  case 50:
#line 198 "kim.y"
                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2046 "y.tab.c"
    break;

  case 51:
#line 201 "kim.y"
                                {(yyval.atype)=setTypeStructOrEnumIdentifier(T_ENUM, (yyvsp[0].pval), ID_ENUM);}
#line 2052 "y.tab.c"
    break;

  case 52:
#line 202 "kim.y"
                                {(yyval.atype)=setTypeField((yyvsp[-3].atype), (yyvsp[-1].aid));}
#line 2058 "y.tab.c"
    break;

  case 53:
#line 203 "kim.y"
                                {(yyval.atype)=makeType(T_ENUM);}
#line 2064 "y.tab.c"
    break;

  case 54:
#line 204 "kim.y"
                                {(yyval.atype)=setTypeField((yyvsp[-3].atype), (yyvsp[-1].aid));}
#line 2070 "y.tab.c"
    break;

  case 55:
#line 205 "kim.y"
                                {(yyval.atype)=getTypeOfStructOrEnumRefIdentifier(T_ENUM, (yyvsp[0].pval), ID_ENUM);}
#line 2076 "y.tab.c"
    break;

  case 56:
#line 208 "kim.y"
                                                {(yyval.aid)=(yyvsp[0].aid);}
#line 2082 "y.tab.c"
    break;

  case 57:
#line 209 "kim.y"
                                                {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 2088 "y.tab.c"
    break;

  case 58:
#line 212 "kim.y"
                                {(yyval.aid)=setDeclaratorKind(makeIdentifier((yyvsp[0].pval)), ID_ENUM_LITERAL);}
#line 2094 "y.tab.c"
    break;

  case 59:
#line 213 "kim.y"
                                {(yyval.aid)=setDeclaratorKind(makeIdentifier((yyvsp[0].pval)), ID_ENUM_LITERAL);}
#line 2100 "y.tab.c"
    break;

  case 60:
#line 214 "kim.y"
                                {(yyval.aid)=setDeclaratorInit((yyvsp[-2].aid), (yyvsp[0].anode));}
#line 2106 "y.tab.c"
    break;

  case 61:
#line 217 "kim.y"
                                        {(yyval.aid)=setDeclaratorElementType((yyvsp[0].aid), (yyvsp[-1].atype));}
#line 2112 "y.tab.c"
    break;

  case 62:
#line 218 "kim.y"
                                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2118 "y.tab.c"
    break;

  case 63:
#line 221 "kim.y"
                        {(yyval.atype)=makeType(T_POINTER);}
#line 2124 "y.tab.c"
    break;

  case 64:
#line 222 "kim.y"
                        {(yyval.atype)=setTypeElementType((yyvsp[0].atype), makeType(T_POINTER));}
#line 2130 "y.tab.c"
    break;

  case 65:
#line 225 "kim.y"
                                        {(yyval.aid)=makeIdentifier((yyvsp[0].pval));}
#line 2136 "y.tab.c"
    break;

  case 66:
#line 226 "kim.y"
                                        {(yyval.aid)=(yyvsp[-1].aid);}
#line 2142 "y.tab.c"
    break;

  case 67:
#line 227 "kim.y"
                                                                {(yyval.aid)=setDeclaratorElementType((yyvsp[-3].aid), setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode)));}
#line 2148 "y.tab.c"
    break;

  case 68:
#line 228 "kim.y"
                                        {(yyval.aid)=current_id; current_level++;}
#line 2154 "y.tab.c"
    break;

  case 69:
#line 229 "kim.y"
                                        {checkForwardReference(); current_id=(yyvsp[-2].aid); current_level--; (yyval.aid)=setDeclaratorElementType((yyvsp[-4].aid), setTypeField(makeType(T_FUNC), (yyvsp[-1].aid)));}
#line 2160 "y.tab.c"
    break;

  case 70:
#line 232 "kim.y"
                                {(yyval.aid)=NIL;}
#line 2166 "y.tab.c"
    break;

  case 71:
#line 233 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 2172 "y.tab.c"
    break;

  case 72:
#line 236 "kim.y"
                        {(yyval.aid)=(yyvsp[0].aid);}
#line 2178 "y.tab.c"
    break;

  case 73:
#line 237 "kim.y"
                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), setDeclaratorKind(makeDummyIdentifier(), ID_PARM));}
#line 2184 "y.tab.c"
    break;

  case 74:
#line 240 "kim.y"
                                {(yyval.aid)=(yyvsp[0].aid);}
#line 2190 "y.tab.c"
    break;

  case 75:
#line 241 "kim.y"
                                                        {(yyval.aid)=linkDeclaratorList((yyvsp[-2].aid), (yyvsp[0].aid));}
#line 2196 "y.tab.c"
    break;

  case 76:
#line 244 "kim.y"
                                                {(yyval.aid)=setParameterDeclaratorSpecifier((yyvsp[0].aid), (yyvsp[-1].aspec));}
#line 2202 "y.tab.c"
    break;

  case 77:
#line 245 "kim.y"
                                                        {(yyval.aid)=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(), (yyvsp[0].atype)), (yyvsp[-1].aspec));}
#line 2208 "y.tab.c"
    break;

  case 78:
#line 248 "kim.y"
                                {(yyval.atype)=NIL;}
#line 2214 "y.tab.c"
    break;

  case 79:
#line 249 "kim.y"
                                {(yyval.atype)=(yyvsp[0].atype);}
#line 2220 "y.tab.c"
    break;

  case 80:
#line 252 "kim.y"
                                        {(yyval.atype)=makeType(T_POINTER);}
#line 2226 "y.tab.c"
    break;

  case 81:
#line 253 "kim.y"
                                        {(yyval.atype)=(yyvsp[0].atype);}
#line 2232 "y.tab.c"
    break;

  case 82:
#line 254 "kim.y"
                                                {(yyval.atype)=setTypeElementType((yyvsp[0].atype), makeType(T_POINTER));}
#line 2238 "y.tab.c"
    break;

  case 83:
#line 257 "kim.y"
                                                                        {(yyval.atype)=(yyvsp[-1].atype);}
#line 2244 "y.tab.c"
    break;

  case 84:
#line 258 "kim.y"
                                                                {(yyval.atype)=setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode));}
#line 2250 "y.tab.c"
    break;

  case 85:
#line 259 "kim.y"
                                                                        {(yyval.atype)=setTypeElementType((yyvsp[-3].atype), setTypeExpr(makeType(T_ARRAY), (yyvsp[-1].anode)));}
#line 2256 "y.tab.c"
    break;

  case 86:
#line 260 "kim.y"
                                                                {(yyval.atype)=setTypeField(makeType(T_FUNC), (yyvsp[-1].aid));}
#line 2262 "y.tab.c"
    break;

  case 87:
#line 261 "kim.y"
                                                                        {(yyval.atype)=setTypeElementType((yyvsp[-3].atype), setTypeField(makeType(T_FUNC), (yyvsp[-1].aid)));}
#line 2268 "y.tab.c"
    break;

  case 88:
#line 264 "kim.y"
                        {(yyval.anode)=makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL);}
#line 2274 "y.tab.c"
    break;

  case 89:
#line 265 "kim.y"
                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2280 "y.tab.c"
    break;

  case 90:
#line 268 "kim.y"
                                        {(yyval.anode)=makeNode(N_STMT_LIST, (yyvsp[0].anode), NIL, makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL));}
#line 2286 "y.tab.c"
    break;

  case 91:
#line 269 "kim.y"
                                        {(yyval.anode)=makeNodeList(N_STMT_LIST, (yyvsp[-1].anode), (yyvsp[0].anode));}
#line 2292 "y.tab.c"
    break;

  case 92:
#line 272 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2298 "y.tab.c"
    break;

  case 93:
#line 273 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2304 "y.tab.c"
    break;

  case 94:
#line 274 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2310 "y.tab.c"
    break;

  case 95:
#line 275 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2316 "y.tab.c"
    break;

  case 96:
#line 276 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2322 "y.tab.c"
    break;

  case 97:
#line 277 "kim.y"
                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2328 "y.tab.c"
    break;

  case 98:
#line 280 "kim.y"
                                                        {(yyval.anode)=makeNode(N_STMT_LABEL_CASE, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2334 "y.tab.c"
    break;

  case 99:
#line 281 "kim.y"
                                        {(yyval.anode)=makeNode(N_STMT_LABEL_DEFAULT, NIL, (yyvsp[0].anode), NIL);}
#line 2340 "y.tab.c"
    break;

  case 100:
#line 284 "kim.y"
            {(yyval.aid)=current_id; current_level++;}
#line 2346 "y.tab.c"
    break;

  case 101:
#line 285 "kim.y"
                                {checkForwardReference();
	(yyval.anode)=makeNode(N_STMT_COMPOUND, (yyvsp[-2].aid), NIL, (yyvsp[-1].anode)); current_id=(yyvsp[-3].aid);
	current_level--;}
#line 2354 "y.tab.c"
    break;

  case 102:
#line 290 "kim.y"
                                {(yyval.anode)=makeNode(N_STMT_EMPTY, NIL, NIL, NIL);}
#line 2360 "y.tab.c"
    break;

  case 103:
#line 291 "kim.y"
                                {(yyval.anode)=makeNode(N_STMT_EXPRESSION, NIL, (yyvsp[-1].anode), NIL);}
#line 2366 "y.tab.c"
    break;

  case 104:
#line 294 "kim.y"
                                                                        {(yyval.anode)=makeNode(N_STMT_IF, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2372 "y.tab.c"
    break;

  case 105:
#line 295 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_IF_ELSE, (yyvsp[-4].anode), (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2378 "y.tab.c"
    break;

  case 106:
#line 296 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_SWITCH, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2384 "y.tab.c"
    break;

  case 107:
#line 299 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_WHILE, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2390 "y.tab.c"
    break;

  case 108:
#line 300 "kim.y"
                                                                {(yyval.anode)=makeNode(N_STMT_DO, (yyvsp[-5].anode), NIL, (yyvsp[-2].anode));}
#line 2396 "y.tab.c"
    break;

  case 109:
#line 301 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_FOR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2402 "y.tab.c"
    break;

  case 110:
#line 304 "kim.y"
                                                                                {(yyval.anode)=makeNode(N_FOR_EXP, (yyvsp[-4].anode), (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2408 "y.tab.c"
    break;

  case 111:
#line 307 "kim.y"
                        {(yyval.anode)=NIL;}
#line 2414 "y.tab.c"
    break;

  case 112:
#line 308 "kim.y"
                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2420 "y.tab.c"
    break;

  case 113:
#line 311 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_RETURN, NIL, (yyvsp[-1].anode), NIL);}
#line 2426 "y.tab.c"
    break;

  case 114:
#line 312 "kim.y"
                                        {(yyval.anode)=makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
#line 2432 "y.tab.c"
    break;

  case 115:
#line 313 "kim.y"
                                                {(yyval.anode)=makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
#line 2438 "y.tab.c"
    break;

  case 116:
#line 316 "kim.y"
                                {(yyval.anode)=makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL);}
#line 2444 "y.tab.c"
    break;

  case 117:
#line 317 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2450 "y.tab.c"
    break;

  case 118:
#line 320 "kim.y"
                                {(yyval.anode)=makeNode(N_ARG_LIST, (yyvsp[0].anode), NIL, makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL));}
#line 2456 "y.tab.c"
    break;

  case 119:
#line 321 "kim.y"
                                                                {(yyval.anode)=makeNodeList(N_ARG_LIST, (yyvsp[-2].anode), (yyvsp[0].anode));}
#line 2462 "y.tab.c"
    break;

  case 120:
#line 324 "kim.y"
                        {(yyval.anode)=NIL;}
#line 2468 "y.tab.c"
    break;

  case 121:
#line 325 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2474 "y.tab.c"
    break;

  case 122:
#line 328 "kim.y"
                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2480 "y.tab.c"
    break;

  case 123:
#line 331 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2486 "y.tab.c"
    break;

  case 124:
#line 334 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2492 "y.tab.c"
    break;

  case 125:
#line 337 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2498 "y.tab.c"
    break;

  case 126:
#line 338 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_ASSIGN, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2504 "y.tab.c"
    break;

  case 127:
#line 341 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2510 "y.tab.c"
    break;

  case 128:
#line 344 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2516 "y.tab.c"
    break;

  case 129:
#line 345 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_OR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2522 "y.tab.c"
    break;

  case 130:
#line 348 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2528 "y.tab.c"
    break;

  case 131:
#line 349 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_AND, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2534 "y.tab.c"
    break;

  case 132:
#line 352 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2540 "y.tab.c"
    break;

  case 133:
#line 355 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2546 "y.tab.c"
    break;

  case 134:
#line 358 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2552 "y.tab.c"
    break;

  case 135:
#line 361 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2558 "y.tab.c"
    break;

  case 136:
#line 362 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_EQL, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2564 "y.tab.c"
    break;

  case 137:
#line 363 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_NEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2570 "y.tab.c"
    break;

  case 138:
#line 366 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2576 "y.tab.c"
    break;

  case 139:
#line 367 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_LSS, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2582 "y.tab.c"
    break;

  case 140:
#line 368 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_GTR, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2588 "y.tab.c"
    break;

  case 141:
#line 369 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_LEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2594 "y.tab.c"
    break;

  case 142:
#line 370 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_GEQ, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2600 "y.tab.c"
    break;

  case 143:
#line 373 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2606 "y.tab.c"
    break;

  case 144:
#line 376 "kim.y"
                                        {(yyval.anode)=(yyvsp[0].anode);}
#line 2612 "y.tab.c"
    break;

  case 145:
#line 377 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_ADD, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2618 "y.tab.c"
    break;

  case 146:
#line 378 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_SUB, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2624 "y.tab.c"
    break;

  case 147:
#line 381 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2630 "y.tab.c"
    break;

  case 148:
#line 382 "kim.y"
                                                        {(yyval.anode)=makeNode(N_EXP_MUL, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2636 "y.tab.c"
    break;

  case 149:
#line 383 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_DIV, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2642 "y.tab.c"
    break;

  case 150:
#line 384 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_MOD, (yyvsp[-2].anode), NIL, (yyvsp[0].anode));}
#line 2648 "y.tab.c"
    break;

  case 151:
#line 387 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2654 "y.tab.c"
    break;

  case 152:
#line 388 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_CAST, (yyvsp[-2].atype), NIL, (yyvsp[0].anode));}
#line 2660 "y.tab.c"
    break;

  case 153:
#line 391 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2666 "y.tab.c"
    break;

  case 154:
#line 392 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_PRE_INC, NIL, (yyvsp[0].anode), NIL);}
#line 2672 "y.tab.c"
    break;

  case 155:
#line 393 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_PRE_DEC, NIL, (yyvsp[0].anode), NIL);}
#line 2678 "y.tab.c"
    break;

  case 156:
#line 394 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_AMP, NIL, (yyvsp[0].anode), NIL);}
#line 2684 "y.tab.c"
    break;

  case 157:
#line 395 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_STAR, NIL, (yyvsp[0].anode), NIL);}
#line 2690 "y.tab.c"
    break;

  case 158:
#line 396 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_NOT, NIL, (yyvsp[0].anode), NIL);}
#line 2696 "y.tab.c"
    break;

  case 159:
#line 397 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_MINUS, NIL, (yyvsp[0].anode), NIL);}
#line 2702 "y.tab.c"
    break;

  case 160:
#line 398 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_PLUS, NIL, (yyvsp[0].anode), NIL);}
#line 2708 "y.tab.c"
    break;

  case 161:
#line 399 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_SIZE_EXP, NIL, (yyvsp[0].anode), NIL);}
#line 2714 "y.tab.c"
    break;

  case 162:
#line 400 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_SIZE_TYPE, NIL, (yyvsp[-1].atype), NIL);}
#line 2720 "y.tab.c"
    break;

  case 163:
#line 403 "kim.y"
                                {(yyval.anode)=(yyvsp[0].anode);}
#line 2726 "y.tab.c"
    break;

  case 164:
#line 404 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_ARRAY, (yyvsp[-3].anode), NIL, (yyvsp[-1].anode));}
#line 2732 "y.tab.c"
    break;

  case 165:
#line 405 "kim.y"
                                                                {(yyval.anode)=makeNode(N_EXP_FUNCTION_CALL, (yyvsp[-3].anode), NIL, (yyvsp[-1].anode));}
#line 2738 "y.tab.c"
    break;

  case 166:
#line 406 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_STRUCT, (yyvsp[-2].anode), NIL, (yyvsp[0].pval));}
#line 2744 "y.tab.c"
    break;

  case 167:
#line 407 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_ARROW, (yyvsp[-2].anode), NIL, (yyvsp[0].pval));}
#line 2750 "y.tab.c"
    break;

  case 168:
#line 408 "kim.y"
                                                {(yyval.anode)=makeNode(N_EXP_POST_INC, NIL, (yyvsp[-1].anode), NIL);}
#line 2756 "y.tab.c"
    break;

  case 169:
#line 409 "kim.y"
                                        {(yyval.anode)=makeNode(N_EXP_POST_DEC, NIL, (yyvsp[-1].anode), NIL);}
#line 2762 "y.tab.c"
    break;

  case 170:
#line 412 "kim.y"
                        {(yyval.anode)=makeNode(N_EXP_IDENT, NIL, getIdentifierDeclared((yyvsp[0].pval)), NIL);}
#line 2768 "y.tab.c"
    break;

  case 171:
#line 413 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_INT_CONST, NIL, (yyvsp[0].ival), NIL);}
#line 2774 "y.tab.c"
    break;

  case 172:
#line 414 "kim.y"
                        {(yyval.anode)=makeNode(N_EXP_FLOAT_CONST, NIL, (yyvsp[0].pval), NIL);}
#line 2780 "y.tab.c"
    break;

  case 173:
#line 415 "kim.y"
                                {(yyval.anode)=makeNode(N_EXP_CHAR_CONST, NIL, (yyvsp[0].cval), NIL);}
#line 2786 "y.tab.c"
    break;

  case 174:
#line 416 "kim.y"
                        {(yyval.anode)=makeNode(N_EXP_STRING_LITERAL, NIL, (yyvsp[0].pval), NIL);}
#line 2792 "y.tab.c"
    break;

  case 175:
#line 417 "kim.y"
                                {(yyval.anode)=(yyvsp[-1].anode);}
#line 2798 "y.tab.c"
    break;

  case 176:
#line 420 "kim.y"
                                                        {(yyval.atype)=setTypeNameSpecifier((yyvsp[0].atype), (yyvsp[-1].aspec));}
#line 2804 "y.tab.c"
    break;


#line 2808 "y.tab.c"

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
#line 423 "kim.y"


#include <stdio.h>
#include "y.tab.h"

extern char *yytext;

void yyerror(char *s) {
	//printf("yyerror called\n");
	syntax_err++;
	printf("line %d: %s near %s \n", line_no, s, yytext);
}
int yywrap(void) {
	//printf("yywrap called\n");
	return(1);
}

int main()
{	
	initialize();
	yyparse();
	print_ast(root);
	return 0;
}
/////////////////////////////////////////////////////////////////////////
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

BOOLEAN isPointerOrArrayType(A_TYPE* t) {
	//printf("isPointerOrArrayType called\n");
	if(t->kind==T_POINTER || t->kind==T_ARRAY)
		return(TRUE);
	else
		return(FALSE);
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
	string_type->size=4;	int_type->check=TRUE;
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
	"N_INIT_LIST",
	"N_STMT_LIST_NIL",
	"N_INIT_LIST_NIL",
	"N_INIT_LIST_ONE"};

extern A_TYPE *int_type, *float_type, *char_type, *void_type, *string_type;
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
	printf("=======  syntax tree  ==========\n");
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
		printf("****syntax tree error******");
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
		printf("****syntax tree error******");
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
		printf("****syntax tree error******");
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
		printf("****syntax tree error******");
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
		printf("****syntax tree error******");
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
		printf("****syntax tree error******");
		
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
		printf("****syntax tree error******");
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
		printf("(void)");
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
			else 
				print_space(s+2); printf("(none)\n");
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
