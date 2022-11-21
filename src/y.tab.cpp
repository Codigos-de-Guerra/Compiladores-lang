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
#line 1 "parserYacc.y"

#include <stdio.h>
#include<stdlib.h>
#include<string>
#include "tipos.hpp"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;


 struct lval {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    string lexeme;
    int token;
    lval(){

    }
};


/* all we have as symbols for the symbol table are identifiers. other possible
   symbols are, for example, goto labels */
struct symbol {
    int scope = 0;
    /* this is the actual name of the symbol. an id 'foo' has the name foo */
    string name = "";
    string type = "";
    bool is_const= false;
    lval val;
    symbol(){

    }
};

// since we have 128 ASCII characters, that's the max number of children our
// trie can have, even though we won't use all of them
#define N 128

struct node {
    struct node *children[N];
    symbol sym;
    bool is_leaf;
};

node* root;

node *initialize()
{
    node *novo = (node*) calloc(1, sizeof(node));
    for (int i = 0; i < N; i++) novo->children[i] = NULL;
    novo->is_leaf = 0;

    return novo;
}

void adiciona(symbol simbolo)
{
    node *tmp = root;
    string word = simbolo.name;
    for (int i = 0; i<word.size(); i++) {
        /* get the relative position in the alphabet list */
        
        int position = (int) word[i] - 'a';

        if (tmp->children[position] == NULL){
            
            tmp->children[position] = initialize();
        }

        tmp = tmp->children[position];
    }

      
      tmp->is_leaf = 1;
      tmp->sym.name =  simbolo.name;
}

node *acha(symbol simbolo)
{
    /* searches for word in the trie */
    node *tmp = root;
    string word = simbolo.name;
    for(int i = 0; i<word.size(); i++)
    {
        int position = word[i] - 'a';
        if (tmp->children[position] == NULL) return NULL;
        tmp = tmp->children[position];
    }

    if (tmp != NULL && tmp->is_leaf == 1) return tmp;

    return NULL;
}


map<string,string> symtable;


#line 173 "y.tab.cpp"

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
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    IF = 258,
    ENDIF = 259,
    ELSE = 260,
    SWITCH = 261,
    CASE = 262,
    FOR = 263,
    LOOP = 264,
    RETURN = 265,
    STRUCT = 266,
    CONST = 267,
    BREAK = 268,
    CONTINUE = 269,
    READ = 270,
    WRITE = 271,
    EXIT = 272,
    WHEN = 273,
    FUNCTION = 274,
    INT = 275,
    REAL = 276,
    CHAR = 277,
    STR = 278,
    BOOL = 279,
    VOID = 280,
    PLUS = 281,
    MINUS = 282,
    TIMES = 283,
    DIV = 284,
    MOD = 285,
    TRUE = 286,
    FALSE = 287,
    NUMBER = 288,
    CHARACTER = 289,
    STRING = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_BRACKET = 293,
    RIGHT_BRACKET = 294,
    ID = 295,
    SEMICOLON = 296,
    QUESTION_MARK = 297,
    COLON = 298,
    DOT = 299,
    POINTER_VAL = 300,
    ARROW = 301,
    COMMA = 302,
    REFERENCE = 303,
    TERNARY = 304,
    ASSIGN_PLUS = 305,
    ASSIGN_MINUS = 306,
    ASSIGN_MULT = 307,
    ASSIGN_DIV = 308,
    ASSIGN_MOD = 309,
    ASSIGN = 310,
    LEFT_PAREN = 311,
    RIGHT_PAREN = 312,
    INCREMENT = 313,
    DECREMENT = 314,
    NOT = 315,
    OR = 316,
    AND = 317,
    EQUALS = 318,
    DIFF = 319,
    LT = 320,
    GT = 321,
    LEQ = 322,
    GEQ = 323
  };
#endif
/* Tokens.  */
#define IF 258
#define ENDIF 259
#define ELSE 260
#define SWITCH 261
#define CASE 262
#define FOR 263
#define LOOP 264
#define RETURN 265
#define STRUCT 266
#define CONST 267
#define BREAK 268
#define CONTINUE 269
#define READ 270
#define WRITE 271
#define EXIT 272
#define WHEN 273
#define FUNCTION 274
#define INT 275
#define REAL 276
#define CHAR 277
#define STR 278
#define BOOL 279
#define VOID 280
#define PLUS 281
#define MINUS 282
#define TIMES 283
#define DIV 284
#define MOD 285
#define TRUE 286
#define FALSE 287
#define NUMBER 288
#define CHARACTER 289
#define STRING 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_BRACKET 293
#define RIGHT_BRACKET 294
#define ID 295
#define SEMICOLON 296
#define QUESTION_MARK 297
#define COLON 298
#define DOT 299
#define POINTER_VAL 300
#define ARROW 301
#define COMMA 302
#define REFERENCE 303
#define TERNARY 304
#define ASSIGN_PLUS 305
#define ASSIGN_MINUS 306
#define ASSIGN_MULT 307
#define ASSIGN_DIV 308
#define ASSIGN_MOD 309
#define ASSIGN 310
#define LEFT_PAREN 311
#define RIGHT_PAREN 312
#define INCREMENT 313
#define DECREMENT 314
#define NOT 315
#define OR 316
#define AND 317
#define EQUALS 318
#define DIFF 319
#define LT 320
#define GT 321
#define LEQ 322
#define GEQ 323

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



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
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

#define YYUNDEFTOK  2
#define YYMAXUTOK   323


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
       2,     2,     2,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   137,   138,   140,   141,   143,   145,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   164,   165,   167,   168,   170,   173,   177,   178,   181,
     182,   184,   185,   186,   188,   189,   190,   191,   192,   194,
     195,   197,   198,   199,   200,   202,   203,   205,   207,   209,
     212,   214,   216,   217,   219,   221,   222,   224,   226,   227,
     228,   230,   231,   232,   233,   234,   235,   237,   238,   240,
     241,   243,   245,   246,   248,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   272,   276,   279,   280,
     281,   284,   285,   288,   289,   291,   292,   294,   295,   297,
     298,   299,   300,   301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'['", "IF", "ENDIF", "ELSE", "SWITCH",
  "CASE", "FOR", "LOOP", "RETURN", "STRUCT", "CONST", "BREAK", "CONTINUE",
  "READ", "WRITE", "EXIT", "WHEN", "FUNCTION", "INT", "REAL", "CHAR",
  "STR", "BOOL", "VOID", "PLUS", "MINUS", "TIMES", "DIV", "MOD", "TRUE",
  "FALSE", "NUMBER", "CHARACTER", "STRING", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "ID", "SEMICOLON", "QUESTION_MARK",
  "COLON", "DOT", "POINTER_VAL", "ARROW", "COMMA", "REFERENCE", "TERNARY",
  "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULT", "ASSIGN_DIV", "ASSIGN_MOD",
  "ASSIGN", "'@'", "LEFT_PAREN", "RIGHT_PAREN", "INCREMENT", "DECREMENT",
  "NOT", "OR", "AND", "EQUALS", "DIFF", "LT", "GT", "LEQ", "GEQ",
  "$accept", "prog", "stmts", "stmt", "decl_fun", "cmd", "cmd_decl_var",
  "assign_expr_maybe", "all_decl_var", "decl_var_prim", "const_decl_var",
  "hashtagzeromais", "cochetezeromais", "assign_expr", "assign_extra",
  "inc", "inOut", "in", "out", "cmd_loop", "cmd_cond", "cmd_switch", "for",
  "loop", "if", "else", "switch", "casezeromais", "case", "type",
  "typename", "primitivos", "typedlpar", "typedlparAfter", "parameter",
  "parameterAfter", "block", "expr", "expr_tern", "identifier",
  "arrayAccess", "lpar", "lparAfter", "pointerAccess", "literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    91,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    64,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323
};
# endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   -55,   -49,   -48,   197,   505,   122,   -30,   -28,   -43,
     -41,    -1,   501,   -61,   -61,   -61,   -61,   -61,   -61,   -21,
     -61,   -61,   -61,   -61,   -61,    29,   -34,   505,   505,   505,
     505,   505,    21,   -61,    29,   -61,   -61,   -20,   517,   -61,
     -61,   -19,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -11,   -61,    55,   -61,   517,   -61,   505,   505,   505,
     -61,   100,   -61,   -61,   -61,   -61,   -15,   -14,   505,   -61,
      -4,   -61,   -61,   -61,     3,   505,     7,   505,   -61,   -61,
     129,   212,   484,   484,   484,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   505,   -61,   -61,   -61,   -61,   505,   -61,
     -61,   -11,    17,   505,   505,   505,   505,   505,   -61,   505,
     505,   505,   505,   505,   505,   505,   505,    25,   233,   256,
     300,   -61,     9,    18,   308,    22,   -61,   316,    34,   360,
      33,   505,   -61,   484,   484,   -61,   505,    47,   451,   451,
     183,   183,   183,   239,   239,   292,   292,   292,   292,   292,
     292,   -61,   197,    56,   505,   -61,   -61,   -61,   501,    57,
     -61,   505,   -61,   -61,   368,   376,   -61,    90,    92,   420,
     -33,    42,    50,   -61,   360,   505,    17,    96,    39,    65,
      92,   505,   -61,    68,   -61,    89,   501,   -61,   -61,   428,
     -61,   197,   -61,    91,   -61,   -61,   440,   -61,   -61,    50,
     -61,   -61,    29,   197,   -61,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    65,    64,    66,     0,
     111,   112,   109,   110,   113,     3,    97,     0,     0,     0,
       0,     0,     0,     2,     3,     5,     6,     0,    21,    23,
      24,     0,    41,    42,    11,    12,    13,    45,    46,    47,
      48,    27,    19,     0,    93,    95,    94,     0,     0,     0,
      50,     0,    95,    26,    16,    17,     0,     0,     0,    60,
       0,    58,    59,    78,     0,     0,     0,   103,    98,   100,
       0,     0,    75,    76,    79,     1,     4,     9,    34,    35,
      36,    37,    38,     0,    40,    39,    20,    22,     0,    33,
      10,    27,    29,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    74,     0,   107,   105,
       0,     0,    77,    31,    32,    28,     0,     0,    82,    85,
      83,    84,    86,    81,    80,    87,    88,    89,    90,    91,
      92,     8,     0,     0,     0,    43,    44,    18,    67,   101,
     108,     0,   104,    99,     0,     0,    25,     0,    55,     0,
       0,     0,    69,   102,   105,     0,    29,    52,     0,     0,
      55,     0,    72,     0,    71,     0,     0,    68,   106,     0,
      30,     0,    51,     0,    54,    56,     0,    73,     7,    69,
      96,    53,     3,     0,    70,    57,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -23,   -61,   -61,    -3,   -61,   -61,   -61,   127,
     -61,    35,   -42,    83,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -40,   -61,   138,
     -61,    -5,   -61,   -60,   -45,   -61,   -31,     1,   -61,     0,
      -8,   -61,   -13,    43,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    34,    35,    36,    37,    96,    38,    39,
      40,   102,   137,    97,    98,    99,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   192,    50,   179,   180,   170,
      71,    51,   171,   187,   172,   184,    52,    53,    54,    62,
      78,   130,   162,    79,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    60,    74,    57,    55,    75,    61,    72,   182,    58,
      59,    86,    64,    76,    65,    66,   183,    67,    68,    73,
      26,    85,    87,   100,    77,    55,   122,   123,    80,    81,
      82,    83,    84,     1,    55,   101,     2,   125,     3,     4,
       5,   126,     6,     7,     8,     9,    10,    11,   128,    12,
      13,    14,    15,    16,    17,    18,   136,    19,   118,   119,
     120,    20,    21,    22,    23,    24,    25,   151,   155,   124,
      26,    20,    21,    22,    23,    24,   127,   156,   129,    27,
     158,    76,   103,   104,   105,   106,   107,    28,   166,    29,
      30,    31,   163,   168,   133,   177,    75,   108,   186,   134,
     178,   185,   191,   194,   138,   139,   140,   141,   142,   197,
     143,   144,   145,   146,   147,   148,   149,   150,   109,   110,
     111,   112,   113,   114,   115,   116,    25,   103,   104,   105,
     106,   107,   164,    63,   190,   202,   135,   165,   117,   204,
     195,   199,   121,    13,    14,    15,    16,    17,    18,   167,
      70,   173,    55,    72,   198,   169,   103,   104,   105,   106,
     107,   188,   174,   109,   110,   111,   112,   113,   114,   115,
     116,   160,   131,     0,     0,     0,   189,     0,     0,   205,
     193,    72,   196,     0,     0,     0,     0,     0,   201,     0,
       0,    55,   109,   110,   111,   112,   113,   114,   115,   116,
     206,     1,    55,    55,     2,     0,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    11,     0,     0,    13,    14,
      15,    16,    17,    18,     0,    19,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,    26,   103,
     104,   105,   106,   107,     0,     0,     0,    27,   111,   112,
     113,   114,   115,   116,     0,    28,     0,    29,    30,    31,
     103,   104,   105,   106,   107,     0,   103,   104,   105,   106,
     107,   132,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   152,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   103,   104,   105,
     106,   107,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,   154,   103,   104,   105,   106,   107,     0,     0,
     157,     0,     0,     0,     0,     0,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   109,   110,   111,   112,   113,   114,   115,   116,   109,
     110,   111,   112,   113,   114,   115,   116,   103,   104,   105,
     106,   107,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   103,   104,   105,   106,   107,   161,     0,
       0,     0,   175,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   109,   110,   111,   112,   113,   114,   115,   116,   109,
     110,   111,   112,   113,   114,   115,   116,   103,   104,   105,
     106,   107,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,   181,     0,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   200,     0,
     105,   106,   107,   109,   110,   111,   112,   113,   114,   115,
     116,   109,   110,   111,   112,   113,   114,   115,   116,   203,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   103,   104,   105,   106,   107,   111,   112,   113,   114,
     115,   116,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,     0,     0,     0,    20,    21,    22,
      23,    24,    69,     0,     0,     0,    26,   109,   110,   111,
     112,   113,   114,   115,   116,    27,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    29,    30,    31,    88,    89,
      90,    91,    92,    93,     0,     0,     0,    94,    95
};

static const yytype_int16 yycheck[] =
{
       0,     4,    25,    58,     4,    39,     5,    12,    41,    58,
      58,    34,    42,    47,    42,    58,    49,    58,    19,    19,
      41,     0,    42,    42,    58,    25,    41,    41,    27,    28,
      29,    30,    31,     4,    34,    46,     7,    41,     9,    10,
      11,    38,    13,    14,    15,    16,    17,    18,    41,    20,
      21,    22,    23,    24,    25,    26,    39,    28,    57,    58,
      59,    32,    33,    34,    35,    36,    37,    42,    59,    68,
      41,    32,    33,    34,    35,    36,    75,    59,    77,    50,
      58,    47,    27,    28,    29,    30,    31,    58,    41,    60,
      61,    62,    59,    37,    93,     5,    39,    42,    48,    98,
       8,    59,     6,    38,   103,   104,   105,   106,   107,    41,
     109,   110,   111,   112,   113,   114,   115,   116,    63,    64,
      65,    66,    67,    68,    69,    70,    37,    27,    28,    29,
      30,    31,   131,     6,   176,    44,   101,   136,    55,   199,
     180,   186,    42,    21,    22,    23,    24,    25,    26,   152,
      12,   159,   152,   158,   185,   154,    27,    28,    29,    30,
      31,   174,   161,    63,    64,    65,    66,    67,    68,    69,
      70,   128,    43,    -1,    -1,    -1,   175,    -1,    -1,   202,
     178,   186,   181,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,   191,    63,    64,    65,    66,    67,    68,    69,    70,
     203,     4,   202,   203,     7,    -1,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    50,    65,    66,
      67,    68,    69,    70,    -1,    58,    -1,    60,    61,    62,
      27,    28,    29,    30,    31,    -1,    27,    28,    29,    30,
      31,    59,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    42,    27,    28,    29,    30,    31,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    40,    65,    66,    67,
      68,    69,    70,    63,    64,    65,    66,    67,    68,    69,
      70,    63,    64,    65,    66,    67,    68,    69,    70,    63,
      64,    65,    66,    67,    68,    69,    70,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    48,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    63,    64,    65,    66,    67,    68,    69,    70,    63,
      64,    65,    66,    67,    68,    69,    70,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      29,    30,    31,    63,    64,    65,    66,    67,    68,    69,
      70,    63,    64,    65,    66,    67,    68,    69,    70,    59,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    27,    28,    29,    30,    31,    65,    66,    67,    68,
      69,    70,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    41,    -1,    -1,    -1,    41,    63,    64,    65,
      66,    67,    68,    69,    70,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    62,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     7,     9,    10,    11,    13,    14,    15,    16,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    28,
      32,    33,    34,    35,    36,    37,    41,    50,    58,    60,
      61,    62,    72,    73,    74,    75,    76,    77,    79,    80,
      81,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      97,   102,   107,   108,   109,   110,   115,    58,    58,    58,
      76,   108,   110,    80,    42,    42,    58,    58,    19,    41,
     100,   101,   102,   110,    73,    39,    47,    58,   111,   114,
     108,   108,   108,   108,   108,     0,    73,    42,    51,    52,
      53,    54,    55,    56,    60,    61,    78,    84,    85,    86,
      42,    46,    82,    27,    28,    29,    30,    31,    42,    63,
      64,    65,    66,    67,    68,    69,    70,    84,   108,   108,
     108,    42,    41,    41,   108,    41,    38,   108,    41,   108,
     112,    43,    59,   108,   108,    82,    39,    83,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,    42,    59,    59,    42,    59,    59,    42,    58,    40,
     114,    48,   113,    59,   108,   108,    41,    76,    37,   108,
     100,   103,   105,   111,   108,    44,    40,     5,     8,    98,
      99,    42,    41,    49,   106,    59,    48,   104,   113,   108,
      83,     6,    96,   115,    38,    98,   108,    41,   107,   105,
      50,    76,    44,    59,   104,    73,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    78,    78,    79,    79,    80,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    89,    90,    90,    91,    92,    93,
      94,    95,    96,    96,    97,    98,    98,    99,   100,   101,
     101,   102,   102,   102,   102,   102,   102,   103,   103,   104,
     104,   105,   106,   106,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     7,     3,     2,
       2,     1,     1,     1,     2,     3,     2,     2,     4,     1,
       2,     0,     1,     1,     1,     4,     2,     0,     2,     0,
       4,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     9,
       2,     7,     0,     2,     7,     0,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       3,     2,     1,     2,     3,     2,     2,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     7,     1,     2,     4,
       2,     3,     4,     0,     2,     0,     3,     2,     3,     1,
       1,     1,     1,     1
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
#line 134 "parserYacc.y"
             {
}
#line 1759 "y.tab.cpp"
    break;

  case 3:
#line 137 "parserYacc.y"
                      {}
#line 1765 "y.tab.cpp"
    break;

  case 4:
#line 138 "parserYacc.y"
                   {}
#line 1771 "y.tab.cpp"
    break;

  case 5:
#line 140 "parserYacc.y"
                {}
#line 1777 "y.tab.cpp"
    break;

  case 6:
#line 141 "parserYacc.y"
            {}
#line 1783 "y.tab.cpp"
    break;

  case 7:
#line 143 "parserYacc.y"
                                                                   {}
#line 1789 "y.tab.cpp"
    break;

  case 8:
#line 145 "parserYacc.y"
                                        {
            (yyval.cmdRetorno) = new cmd((yyvsp[-2].identifierRetorno),(yyvsp[-1].assign_exprRetorno));
      }
#line 1797 "y.tab.cpp"
    break;

  case 9:
#line 148 "parserYacc.y"
                              {(yyval.cmdRetorno) = new cmd((yyvsp[-1].cmd_decl_varRetorno));}
#line 1803 "y.tab.cpp"
    break;

  case 10:
#line 149 "parserYacc.y"
                        {}
#line 1809 "y.tab.cpp"
    break;

  case 11:
#line 150 "parserYacc.y"
                 {}
#line 1815 "y.tab.cpp"
    break;

  case 12:
#line 151 "parserYacc.y"
                 {}
#line 1821 "y.tab.cpp"
    break;

  case 13:
#line 152 "parserYacc.y"
                   {}
#line 1827 "y.tab.cpp"
    break;

  case 14:
#line 153 "parserYacc.y"
                       {}
#line 1833 "y.tab.cpp"
    break;

  case 15:
#line 154 "parserYacc.y"
                              {}
#line 1839 "y.tab.cpp"
    break;

  case 16:
#line 155 "parserYacc.y"
                        {}
#line 1845 "y.tab.cpp"
    break;

  case 17:
#line 156 "parserYacc.y"
                           {}
#line 1851 "y.tab.cpp"
    break;

  case 18:
#line 157 "parserYacc.y"
                                 {}
#line 1857 "y.tab.cpp"
    break;

  case 19:
#line 158 "parserYacc.y"
              {}
#line 1863 "y.tab.cpp"
    break;

  case 20:
#line 160 "parserYacc.y"
                                              {
      (yyval.cmd_decl_varRetorno) = new cmd_decl_var((yyvsp[-1].all_decl_varRetorno),(yyvsp[0].assign_expr_maybeRetorno));
      }
#line 1871 "y.tab.cpp"
    break;

  case 21:
#line 164 "parserYacc.y"
                                {(yyval.assign_expr_maybeRetorno) = NULL;}
#line 1877 "y.tab.cpp"
    break;

  case 22:
#line 165 "parserYacc.y"
                    {(yyval.assign_expr_maybeRetorno) = new assign_expr_maybe();}
#line 1883 "y.tab.cpp"
    break;

  case 23:
#line 167 "parserYacc.y"
                             {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].decl_var_primRetorno),symtable);}
#line 1889 "y.tab.cpp"
    break;

  case 24:
#line 168 "parserYacc.y"
                             {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].const_decl_varRetorno),symtable);}
#line 1895 "y.tab.cpp"
    break;

  case 25:
#line 170 "parserYacc.y"
                                                              {
      (yyval.decl_var_primRetorno) = new decl_var_prim((yyvsp[-3].primitivosRetorno),(yyvsp[-2].hashtagzeromaisRetorno),(yyvsp[-1].cochetezeromaisRetorno),yytext);
}
#line 1903 "y.tab.cpp"
    break;

  case 26:
#line 173 "parserYacc.y"
                                     {
      (yyval.const_decl_varRetorno) = new const_decl_var((yyvsp[0].decl_var_primRetorno));
}
#line 1911 "y.tab.cpp"
    break;

  case 27:
#line 177 "parserYacc.y"
                              {(yyval.hashtagzeromaisRetorno) = NULL;}
#line 1917 "y.tab.cpp"
    break;

  case 28:
#line 178 "parserYacc.y"
                                    {(yyval.hashtagzeromaisRetorno) = new hashtagzeromais((yyvsp[0].hashtagzeromaisRetorno));}
#line 1923 "y.tab.cpp"
    break;

  case 29:
#line 181 "parserYacc.y"
                              {(yyval.cochetezeromaisRetorno) = NULL;}
#line 1929 "y.tab.cpp"
    break;

  case 30:
#line 182 "parserYacc.y"
                                                        {(yyval.cochetezeromaisRetorno) = new cochetezeromais((yyvsp[0].cochetezeromaisRetorno));}
#line 1935 "y.tab.cpp"
    break;

  case 31:
#line 184 "parserYacc.y"
                          {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1941 "y.tab.cpp"
    break;

  case 32:
#line 185 "parserYacc.y"
                                {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1947 "y.tab.cpp"
    break;

  case 33:
#line 186 "parserYacc.y"
                  {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1953 "y.tab.cpp"
    break;

  case 34:
#line 188 "parserYacc.y"
                           {}
#line 1959 "y.tab.cpp"
    break;

  case 35:
#line 189 "parserYacc.y"
                     {}
#line 1965 "y.tab.cpp"
    break;

  case 36:
#line 190 "parserYacc.y"
                    {}
#line 1971 "y.tab.cpp"
    break;

  case 37:
#line 191 "parserYacc.y"
                   {}
#line 1977 "y.tab.cpp"
    break;

  case 38:
#line 192 "parserYacc.y"
                   {}
#line 1983 "y.tab.cpp"
    break;

  case 39:
#line 194 "parserYacc.y"
                {}
#line 1989 "y.tab.cpp"
    break;

  case 40:
#line 195 "parserYacc.y"
                  {}
#line 1995 "y.tab.cpp"
    break;

  case 41:
#line 197 "parserYacc.y"
           {}
#line 2001 "y.tab.cpp"
    break;

  case 42:
#line 198 "parserYacc.y"
            {}
#line 2007 "y.tab.cpp"
    break;

  case 43:
#line 199 "parserYacc.y"
                                    {}
#line 2013 "y.tab.cpp"
    break;

  case 44:
#line 200 "parserYacc.y"
                                      {}
#line 2019 "y.tab.cpp"
    break;

  case 45:
#line 202 "parserYacc.y"
               {}
#line 2025 "y.tab.cpp"
    break;

  case 46:
#line 203 "parserYacc.y"
             {}
#line 2031 "y.tab.cpp"
    break;

  case 47:
#line 205 "parserYacc.y"
              {}
#line 2037 "y.tab.cpp"
    break;

  case 48:
#line 207 "parserYacc.y"
                    {}
#line 2043 "y.tab.cpp"
    break;

  case 49:
#line 209 "parserYacc.y"
                                                                        {}
#line 2049 "y.tab.cpp"
    break;

  case 50:
#line 212 "parserYacc.y"
                {}
#line 2055 "y.tab.cpp"
    break;

  case 51:
#line 214 "parserYacc.y"
                                                   {}
#line 2061 "y.tab.cpp"
    break;

  case 52:
#line 216 "parserYacc.y"
                    {}
#line 2067 "y.tab.cpp"
    break;

  case 53:
#line 217 "parserYacc.y"
                 {}
#line 2073 "y.tab.cpp"
    break;

  case 54:
#line 219 "parserYacc.y"
                                                                                {}
#line 2079 "y.tab.cpp"
    break;

  case 55:
#line 221 "parserYacc.y"
                           {}
#line 2085 "y.tab.cpp"
    break;

  case 56:
#line 222 "parserYacc.y"
                          {}
#line 2091 "y.tab.cpp"
    break;

  case 57:
#line 224 "parserYacc.y"
                                {}
#line 2097 "y.tab.cpp"
    break;

  case 58:
#line 226 "parserYacc.y"
                {}
#line 2103 "y.tab.cpp"
    break;

  case 59:
#line 227 "parserYacc.y"
                      {}
#line 2109 "y.tab.cpp"
    break;

  case 60:
#line 228 "parserYacc.y"
           {}
#line 2115 "y.tab.cpp"
    break;

  case 61:
#line 230 "parserYacc.y"
                 {(yyval.primitivosRetorno) = new primitivos("INT");}
#line 2121 "y.tab.cpp"
    break;

  case 62:
#line 231 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("REAL");}
#line 2127 "y.tab.cpp"
    break;

  case 63:
#line 232 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("CHAR");}
#line 2133 "y.tab.cpp"
    break;

  case 64:
#line 233 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("BOOL");}
#line 2139 "y.tab.cpp"
    break;

  case 65:
#line 234 "parserYacc.y"
            {(yyval.primitivosRetorno) = new primitivos("STRING");}
#line 2145 "y.tab.cpp"
    break;

  case 66:
#line 235 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("VOID");}
#line 2151 "y.tab.cpp"
    break;

  case 67:
#line 237 "parserYacc.y"
                        {}
#line 2157 "y.tab.cpp"
    break;

  case 68:
#line 238 "parserYacc.y"
                                 {}
#line 2163 "y.tab.cpp"
    break;

  case 69:
#line 240 "parserYacc.y"
                             {}
#line 2169 "y.tab.cpp"
    break;

  case 70:
#line 241 "parserYacc.y"
                                       {}
#line 2175 "y.tab.cpp"
    break;

  case 71:
#line 243 "parserYacc.y"
                                {}
#line 2181 "y.tab.cpp"
    break;

  case 72:
#line 245 "parserYacc.y"
                    {}
#line 2187 "y.tab.cpp"
    break;

  case 73:
#line 246 "parserYacc.y"
                     {}
#line 2193 "y.tab.cpp"
    break;

  case 74:
#line 248 "parserYacc.y"
                                     {}
#line 2199 "y.tab.cpp"
    break;

  case 75:
#line 250 "parserYacc.y"
                      {}
#line 2205 "y.tab.cpp"
    break;

  case 76:
#line 251 "parserYacc.y"
                      {}
#line 2211 "y.tab.cpp"
    break;

  case 77:
#line 252 "parserYacc.y"
                                   {}
#line 2217 "y.tab.cpp"
    break;

  case 78:
#line 253 "parserYacc.y"
                        {}
#line 2223 "y.tab.cpp"
    break;

  case 79:
#line 254 "parserYacc.y"
                {}
#line 2229 "y.tab.cpp"
    break;

  case 80:
#line 255 "parserYacc.y"
                     {}
#line 2235 "y.tab.cpp"
    break;

  case 81:
#line 256 "parserYacc.y"
                    {}
#line 2241 "y.tab.cpp"
    break;

  case 82:
#line 257 "parserYacc.y"
                      {}
#line 2247 "y.tab.cpp"
    break;

  case 83:
#line 258 "parserYacc.y"
                       {}
#line 2253 "y.tab.cpp"
    break;

  case 84:
#line 259 "parserYacc.y"
                     {}
#line 2259 "y.tab.cpp"
    break;

  case 85:
#line 260 "parserYacc.y"
                       {}
#line 2265 "y.tab.cpp"
    break;

  case 86:
#line 261 "parserYacc.y"
                     {}
#line 2271 "y.tab.cpp"
    break;

  case 87:
#line 262 "parserYacc.y"
                        {}
#line 2277 "y.tab.cpp"
    break;

  case 88:
#line 263 "parserYacc.y"
                      {}
#line 2283 "y.tab.cpp"
    break;

  case 89:
#line 264 "parserYacc.y"
                    {}
#line 2289 "y.tab.cpp"
    break;

  case 90:
#line 265 "parserYacc.y"
                    {}
#line 2295 "y.tab.cpp"
    break;

  case 91:
#line 266 "parserYacc.y"
                     {}
#line 2301 "y.tab.cpp"
    break;

  case 92:
#line 267 "parserYacc.y"
                     {}
#line 2307 "y.tab.cpp"
    break;

  case 93:
#line 268 "parserYacc.y"
                 {}
#line 2313 "y.tab.cpp"
    break;

  case 94:
#line 269 "parserYacc.y"
               {}
#line 2319 "y.tab.cpp"
    break;

  case 95:
#line 270 "parserYacc.y"
                  {}
#line 2325 "y.tab.cpp"
    break;

  case 96:
#line 272 "parserYacc.y"
                                                               {}
#line 2331 "y.tab.cpp"
    break;

  case 97:
#line 276 "parserYacc.y"
                {
            (yyval.identifierRetorno) = new identifier(yytext);
      }
#line 2339 "y.tab.cpp"
    break;

  case 98:
#line 279 "parserYacc.y"
                           {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2345 "y.tab.cpp"
    break;

  case 99:
#line 280 "parserYacc.y"
                                           {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2351 "y.tab.cpp"
    break;

  case 100:
#line 281 "parserYacc.y"
                             {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2357 "y.tab.cpp"
    break;

  case 101:
#line 284 "parserYacc.y"
                                              {}
#line 2363 "y.tab.cpp"
    break;

  case 102:
#line 285 "parserYacc.y"
                                                             {}
#line 2369 "y.tab.cpp"
    break;

  case 103:
#line 288 "parserYacc.y"
                   { }
#line 2375 "y.tab.cpp"
    break;

  case 104:
#line 289 "parserYacc.y"
                      {}
#line 2381 "y.tab.cpp"
    break;

  case 105:
#line 291 "parserYacc.y"
                         {}
#line 2387 "y.tab.cpp"
    break;

  case 106:
#line 292 "parserYacc.y"
                             {}
#line 2393 "y.tab.cpp"
    break;

  case 107:
#line 294 "parserYacc.y"
                         {}
#line 2399 "y.tab.cpp"
    break;

  case 108:
#line 295 "parserYacc.y"
                                        {}
#line 2405 "y.tab.cpp"
    break;

  case 109:
#line 297 "parserYacc.y"
                 {(yyval.literalRetorno) = new literal("NUMBER",yytext);}
#line 2411 "y.tab.cpp"
    break;

  case 110:
#line 298 "parserYacc.y"
                  {(yyval.literalRetorno) = new literal("CHAR",yytext);}
#line 2417 "y.tab.cpp"
    break;

  case 111:
#line 299 "parserYacc.y"
             {(yyval.literalRetorno) = new literal("BOOL",yytext);}
#line 2423 "y.tab.cpp"
    break;

  case 112:
#line 300 "parserYacc.y"
              {(yyval.literalRetorno) = new literal("BOOL",yytext);}
#line 2429 "y.tab.cpp"
    break;

  case 113:
#line 301 "parserYacc.y"
               {(yyval.literalRetorno) = new literal("STRING",yytext);}
#line 2435 "y.tab.cpp"
    break;


#line 2439 "y.tab.cpp"

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
#line 303 "parserYacc.y"
 /* Fim da segunda seção */





int main (void) {
    
      root = initialize();

      return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
