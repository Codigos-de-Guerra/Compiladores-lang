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
    SEMICOLON = 295,
    QUESTION_MARK = 296,
    COLON = 297,
    DOT = 298,
    POINTER_VAL = 299,
    ARROW = 300,
    COMMA = 301,
    REFERENCE = 302,
    TERNARY = 303,
    ASSIGN_PLUS = 304,
    ASSIGN_MINUS = 305,
    ASSIGN_MULT = 306,
    ASSIGN_DIV = 307,
    ASSIGN_MOD = 308,
    ASSIGN = 309,
    ID = 310,
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
#define SEMICOLON 295
#define QUESTION_MARK 296
#define COLON 297
#define DOT 298
#define POINTER_VAL 299
#define ARROW 300
#define COMMA 301
#define REFERENCE 302
#define TERNARY 303
#define ASSIGN_PLUS 304
#define ASSIGN_MINUS 305
#define ASSIGN_MULT 306
#define ASSIGN_DIV 307
#define ASSIGN_MOD 308
#define ASSIGN 309
#define ID 310
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
#define YYLAST   565

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
       0,   136,   136,   139,   140,   142,   143,   145,   147,   150,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     163,   167,   168,   171,   172,   174,   177,   181,   182,   185,
     186,   188,   190,   191,   193,   194,   195,   196,   197,   199,
     200,   202,   203,   204,   205,   207,   208,   210,   212,   214,
     217,   219,   221,   222,   224,   226,   227,   229,   231,   232,
     233,   235,   236,   237,   238,   239,   240,   242,   243,   245,
     246,   248,   250,   251,   253,   255,   256,   257,   258,   259,
     260,   261,   262,   264,   265,   266,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   282,   286,   289,   290,
     291,   294,   295,   298,   299,   301,   302,   304,   305,   307,
     308,   309,   310,   311
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
  "LEFT_BRACKET", "RIGHT_BRACKET", "SEMICOLON", "QUESTION_MARK", "COLON",
  "DOT", "POINTER_VAL", "ARROW", "COMMA", "REFERENCE", "TERNARY",
  "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULT", "ASSIGN_DIV", "ASSIGN_MOD",
  "ASSIGN", "ID", "'@'", "LEFT_PAREN", "RIGHT_PAREN", "INCREMENT",
  "DECREMENT", "NOT", "OR", "AND", "EQUALS", "DIFF", "LT", "GT", "LEQ",
  "GEQ", "$accept", "prog", "stmts", "stmt", "decl_fun", "cmd",
  "cmd_decl_var", "assign_expr_maybe", "all_decl_var", "decl_var_prim",
  "const_decl_var", "hashtagzeromais", "cochetezeromais", "assign_expr",
  "assign_extra", "inc", "inOut", "in", "out", "cmd_loop", "cmd_cond",
  "cmd_switch", "for", "loop", "if", "else", "switch", "casezeromais",
  "case", "type", "typename", "primitivos", "typedlpar", "typedlparAfter",
  "parameter", "parameterAfter", "block", "expr", "expr_tern",
  "identifier", "arrayAccess", "lpar", "lparAfter", "pointerAccess",
  "literal", YY_NULLPTR
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

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   -53,   -50,   -49,   197,   503,    49,   -29,   -20,   -35,
     -34,     7,    -8,   -54,   -54,   -54,   -54,   -54,   -54,   -21,
     -54,   -54,   -54,   -54,   -54,    29,   503,   -36,   503,   503,
     503,   503,    37,   -54,    29,   -54,   -54,    15,   310,   -54,
     -54,    26,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,    -4,   -54,   102,   -54,   310,   -54,   503,   503,   503,
     -54,   208,   -54,   -54,   -54,   -54,    12,    20,   503,   -54,
      30,   -54,   -54,   -54,    50,   237,   503,    36,   503,   -54,
     -54,   253,   460,   460,   460,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   503,   -54,   -54,   -54,   -54,   503,   -54,
     -54,    -4,    54,   503,   503,   503,   503,   503,   -54,   503,
     503,   503,   503,   503,   503,   503,   503,    55,   265,   309,
     317,   -54,    38,    39,   325,    42,   -54,   503,   369,    56,
     129,    44,   -54,   460,   460,   -54,   503,    45,   221,   221,
     175,   175,   175,    53,    53,   361,   361,   361,   361,   361,
     361,   -54,   197,    58,   503,   -54,   -54,   -54,    -8,   377,
      70,   -54,   503,   -54,   -54,   385,   -54,   119,   117,   429,
     -28,    67,    80,   503,   -54,   129,    54,   128,   106,    97,
     117,   503,    88,   -54,   -54,    99,    -8,   -54,   437,   -54,
     -54,   197,   -54,   103,   -54,   -54,   449,   -54,   -54,    80,
     -54,   -54,    29,   197,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    65,    64,    66,     0,
     111,   112,   109,   110,   113,     3,     0,    97,     0,     0,
       0,     0,     0,     2,     3,     5,     6,     0,    21,    23,
      24,     0,    41,    42,    11,    12,    13,    45,    46,    47,
      48,    27,    19,     0,    93,    95,    94,     0,     0,     0,
      50,     0,    95,    26,    16,    17,     0,     0,     0,    60,
       0,    58,    59,    78,     0,     0,     0,     0,   103,    98,
     100,     0,    75,    76,    79,     1,     4,     9,    34,    35,
      36,    37,    38,     0,    40,    39,    20,    22,     0,    33,
      10,    27,    29,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    74,     0,     0,   107,
     105,     0,    77,    31,    32,    28,     0,     0,    82,    85,
      83,    84,    86,    81,    80,    87,    88,    89,    90,    91,
      92,     8,     0,     0,     0,    43,    44,    18,    67,     0,
     101,   108,     0,   104,    99,     0,    25,     0,    55,     0,
       0,     0,    69,     0,   102,   105,    29,    52,     0,     0,
      55,     0,     0,    72,    71,     0,     0,    68,     0,   106,
      30,     0,    51,     0,    54,    56,     0,    73,     7,    69,
      96,    53,     3,     0,    70,    57,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -23,   -54,   -54,    -3,   -54,   -54,   -54,   139,
     -54,    46,   -26,    93,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -19,   -54,   142,
     -54,    -5,   -54,   -48,   -24,   -54,   -12,     1,   -54,     0,
       4,   -54,     2,    51,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    34,    35,    36,    37,    96,    38,    39,
      40,   102,   137,    97,    98,    99,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   192,    50,   179,   180,   170,
      71,    51,   171,   187,   172,   184,    52,    53,    54,    62,
      79,   131,   163,    80,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    60,    74,    76,    55,    57,    61,    72,    58,    59,
      77,    86,    64,    13,    14,    15,    16,    17,    18,    73,
     182,    65,    78,    66,    67,    55,    68,    75,   183,    81,
      82,    83,    84,     1,    55,    27,     2,    85,     3,     4,
       5,   101,     6,     7,     8,     9,    10,    11,    69,    12,
      13,    14,    15,    16,    17,    18,    87,    19,   118,   119,
     120,    20,    21,    22,    23,    24,    25,   100,   122,   124,
      13,    14,    15,    16,    17,    18,   123,   128,    26,   130,
     103,   104,   105,   106,   107,    27,   125,    28,   126,    29,
      30,    31,   129,   136,   133,   168,   151,   155,   156,   134,
     158,   166,    77,   164,   138,   139,   140,   141,   142,    76,
     143,   144,   145,   146,   147,   148,   149,   150,   111,   112,
     113,   114,   115,   116,   177,   178,   185,   186,   159,   103,
     104,   105,   106,   107,   191,   194,    25,   165,    20,    21,
      22,    23,    24,   108,   197,    63,   202,   135,   117,   167,
     190,   204,    55,    72,    70,   169,   103,   104,   105,   106,
     107,   195,   199,   175,   174,   109,   110,   111,   112,   113,
     114,   115,   116,   198,   188,     0,   162,   189,     0,   205,
     161,    72,   196,   193,     0,     0,     0,     0,   201,     0,
       0,    55,   109,   110,   111,   112,   113,   114,   115,   116,
     206,     1,    55,    55,     2,     0,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    11,     0,     0,    13,    14,
      15,    16,    17,    18,     0,    19,     0,     0,     0,    20,
      21,    22,    23,    24,    25,   103,   104,   105,   106,   107,
     111,   112,   113,   114,   115,   116,    26,     0,     0,   121,
     105,   106,   107,    27,     0,    28,     0,    29,    30,    31,
       0,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   127,
     103,   104,   105,   106,   107,     0,   111,   112,   113,   114,
     115,   116,   103,   104,   105,   106,   107,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   132,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   152,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   103,   104,   105,   106,
     107,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,   103,   104,   105,   106,   107,     0,   154,     0,
      88,    89,    90,    91,    92,    93,   157,     0,   153,     0,
      94,    95,   109,   110,   111,   112,   113,   114,   115,   116,
     109,   110,   111,   112,   113,   114,   115,   116,   109,   110,
     111,   112,   113,   114,   115,   116,   103,   104,   105,   106,
     107,     0,     0,     0,   103,   104,   105,   106,   107,   160,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
     173,     0,     0,     0,     0,   176,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     109,   110,   111,   112,   113,   114,   115,   116,   109,   110,
     111,   112,   113,   114,   115,   116,   103,   104,   105,   106,
     107,     0,     0,     0,   103,   104,   105,   106,   107,     0,
     181,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,   200,   103,   104,   105,
     106,   107,   109,   110,   111,   112,   113,   114,   115,   116,
     109,   110,   111,   112,   113,   114,   115,   116,   203,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,    19,     0,     0,     0,    20,    21,    22,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
       0,     4,    25,    39,     4,    58,     5,    12,    58,    58,
      46,    34,    41,    21,    22,    23,    24,    25,    26,    19,
      48,    41,    58,    58,    58,    25,    19,    26,    56,    28,
      29,    30,    31,     4,    34,    56,     7,     0,     9,    10,
      11,    45,    13,    14,    15,    16,    17,    18,    56,    20,
      21,    22,    23,    24,    25,    26,    41,    28,    57,    58,
      59,    32,    33,    34,    35,    36,    37,    41,    56,    68,
      21,    22,    23,    24,    25,    26,    56,    76,    49,    78,
      27,    28,    29,    30,    31,    56,    56,    58,    38,    60,
      61,    62,    56,    39,    93,    37,    41,    59,    59,    98,
      58,    56,    46,    59,   103,   104,   105,   106,   107,    39,
     109,   110,   111,   112,   113,   114,   115,   116,    65,    66,
      67,    68,    69,    70,     5,     8,    59,    47,   127,    27,
      28,    29,    30,    31,     6,    38,    37,   136,    32,    33,
      34,    35,    36,    41,    56,     6,    43,   101,    55,   152,
     176,   199,   152,   158,    12,   154,    27,    28,    29,    30,
      31,   180,   186,   162,   160,    63,    64,    65,    66,    67,
      68,    69,    70,   185,   173,    -1,    47,   175,    -1,   202,
     129,   186,   181,   178,    -1,    -1,    -1,    -1,   191,    -1,
      -1,   191,    63,    64,    65,    66,    67,    68,    69,    70,
     203,     4,   202,   203,     7,    -1,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    27,    28,    29,    30,    31,
      65,    66,    67,    68,    69,    70,    49,    -1,    -1,    41,
      29,    30,    31,    56,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    42,
      27,    28,    29,    30,    31,    -1,    65,    66,    67,    68,
      69,    70,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    41,    -1,
      50,    51,    52,    53,    54,    55,    41,    -1,    59,    -1,
      60,    61,    63,    64,    65,    66,    67,    68,    69,    70,
      63,    64,    65,    66,    67,    68,    69,    70,    63,    64,
      65,    66,    67,    68,    69,    70,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    27,    28,    29,    30,    31,    40,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    40,    65,    66,    67,    68,
      69,    70,    63,    64,    65,    66,    67,    68,    69,    70,
      63,    64,    65,    66,    67,    68,    69,    70,    63,    64,
      65,    66,    67,    68,    69,    70,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    49,    27,    28,    29,
      30,    31,    63,    64,    65,    66,    67,    68,    69,    70,
      63,    64,    65,    66,    67,    68,    69,    70,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    -1,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     7,     9,    10,    11,    13,    14,    15,    16,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    28,
      32,    33,    34,    35,    36,    37,    49,    56,    58,    60,
      61,    62,    72,    73,    74,    75,    76,    77,    79,    80,
      81,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      97,   102,   107,   108,   109,   110,   115,    58,    58,    58,
      76,   108,   110,    80,    41,    41,    58,    58,    19,    56,
     100,   101,   102,   110,    73,   108,    39,    46,    58,   111,
     114,   108,   108,   108,   108,     0,    73,    41,    50,    51,
      52,    53,    54,    55,    60,    61,    78,    84,    85,    86,
      41,    45,    82,    27,    28,    29,    30,    31,    41,    63,
      64,    65,    66,    67,    68,    69,    70,    84,   108,   108,
     108,    41,    56,    56,   108,    56,    38,    42,   108,    56,
     108,   112,    59,   108,   108,    82,    39,    83,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,    41,    59,    59,    41,    59,    59,    41,    58,   108,
      40,   114,    47,   113,    59,   108,    56,    76,    37,   108,
     100,   103,   105,    43,   111,   108,    40,     5,     8,    98,
      99,    41,    48,    56,   106,    59,    47,   104,   108,   113,
      83,     6,    96,   115,    38,    98,   108,    56,   107,   105,
      49,    76,    43,    59,   104,    73,    76
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
#line 136 "parserYacc.y"
             {
}
#line 1758 "y.tab.cpp"
    break;

  case 3:
#line 139 "parserYacc.y"
                      {}
#line 1764 "y.tab.cpp"
    break;

  case 4:
#line 140 "parserYacc.y"
                   {}
#line 1770 "y.tab.cpp"
    break;

  case 5:
#line 142 "parserYacc.y"
                {}
#line 1776 "y.tab.cpp"
    break;

  case 6:
#line 143 "parserYacc.y"
            {}
#line 1782 "y.tab.cpp"
    break;

  case 7:
#line 145 "parserYacc.y"
                                                                   {}
#line 1788 "y.tab.cpp"
    break;

  case 8:
#line 147 "parserYacc.y"
                                        {
            (yyval.cmdRetorno) = new cmd((yyvsp[-2].identifierRetorno),(yyvsp[-1].assign_exprRetorno));
      }
#line 1796 "y.tab.cpp"
    break;

  case 9:
#line 150 "parserYacc.y"
                              {
            (yyval.cmdRetorno) = new cmd((yyvsp[-1].cmd_decl_varRetorno));}
#line 1803 "y.tab.cpp"
    break;

  case 10:
#line 152 "parserYacc.y"
                        {}
#line 1809 "y.tab.cpp"
    break;

  case 11:
#line 153 "parserYacc.y"
                 {}
#line 1815 "y.tab.cpp"
    break;

  case 12:
#line 154 "parserYacc.y"
                 {}
#line 1821 "y.tab.cpp"
    break;

  case 13:
#line 155 "parserYacc.y"
                   {}
#line 1827 "y.tab.cpp"
    break;

  case 14:
#line 156 "parserYacc.y"
                       {}
#line 1833 "y.tab.cpp"
    break;

  case 15:
#line 157 "parserYacc.y"
                              {}
#line 1839 "y.tab.cpp"
    break;

  case 16:
#line 158 "parserYacc.y"
                        {}
#line 1845 "y.tab.cpp"
    break;

  case 17:
#line 159 "parserYacc.y"
                           {}
#line 1851 "y.tab.cpp"
    break;

  case 18:
#line 160 "parserYacc.y"
                                 {}
#line 1857 "y.tab.cpp"
    break;

  case 19:
#line 161 "parserYacc.y"
              {}
#line 1863 "y.tab.cpp"
    break;

  case 20:
#line 163 "parserYacc.y"
                                              {
      (yyval.cmd_decl_varRetorno) = new cmd_decl_var((yyvsp[-1].all_decl_varRetorno),(yyvsp[0].assign_expr_maybeRetorno));
      }
#line 1871 "y.tab.cpp"
    break;

  case 21:
#line 167 "parserYacc.y"
                                {(yyval.assign_expr_maybeRetorno) = NULL;}
#line 1877 "y.tab.cpp"
    break;

  case 22:
#line 168 "parserYacc.y"
                    {
            (yyval.assign_expr_maybeRetorno) = new assign_expr_maybe();}
#line 1884 "y.tab.cpp"
    break;

  case 23:
#line 171 "parserYacc.y"
                             {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].decl_var_primRetorno),symtable);}
#line 1890 "y.tab.cpp"
    break;

  case 24:
#line 172 "parserYacc.y"
                             {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].const_decl_varRetorno),symtable);}
#line 1896 "y.tab.cpp"
    break;

  case 25:
#line 174 "parserYacc.y"
                                                              {
      (yyval.decl_var_primRetorno) = new decl_var_prim((yyvsp[-3].primitivosRetorno),(yyvsp[-2].hashtagzeromaisRetorno),(yyvsp[-1].cochetezeromaisRetorno),*(yyvsp[0].name));
}
#line 1904 "y.tab.cpp"
    break;

  case 26:
#line 177 "parserYacc.y"
                                     {
      (yyval.const_decl_varRetorno) = new const_decl_var((yyvsp[0].decl_var_primRetorno));
}
#line 1912 "y.tab.cpp"
    break;

  case 27:
#line 181 "parserYacc.y"
                              {(yyval.hashtagzeromaisRetorno) = NULL;}
#line 1918 "y.tab.cpp"
    break;

  case 28:
#line 182 "parserYacc.y"
                                    {(yyval.hashtagzeromaisRetorno) = new hashtagzeromais((yyvsp[0].hashtagzeromaisRetorno));}
#line 1924 "y.tab.cpp"
    break;

  case 29:
#line 185 "parserYacc.y"
                              {(yyval.cochetezeromaisRetorno) = NULL;}
#line 1930 "y.tab.cpp"
    break;

  case 30:
#line 186 "parserYacc.y"
                                                        {(yyval.cochetezeromaisRetorno) = new cochetezeromais((yyvsp[0].cochetezeromaisRetorno));}
#line 1936 "y.tab.cpp"
    break;

  case 31:
#line 188 "parserYacc.y"
                          {
                  (yyval.assign_exprRetorno) = new assign_expr();}
#line 1943 "y.tab.cpp"
    break;

  case 32:
#line 190 "parserYacc.y"
                                {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1949 "y.tab.cpp"
    break;

  case 33:
#line 191 "parserYacc.y"
                  {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1955 "y.tab.cpp"
    break;

  case 34:
#line 193 "parserYacc.y"
                           {}
#line 1961 "y.tab.cpp"
    break;

  case 35:
#line 194 "parserYacc.y"
                     {}
#line 1967 "y.tab.cpp"
    break;

  case 36:
#line 195 "parserYacc.y"
                    {}
#line 1973 "y.tab.cpp"
    break;

  case 37:
#line 196 "parserYacc.y"
                   {}
#line 1979 "y.tab.cpp"
    break;

  case 38:
#line 197 "parserYacc.y"
                   {}
#line 1985 "y.tab.cpp"
    break;

  case 39:
#line 199 "parserYacc.y"
                {}
#line 1991 "y.tab.cpp"
    break;

  case 40:
#line 200 "parserYacc.y"
                  {}
#line 1997 "y.tab.cpp"
    break;

  case 41:
#line 202 "parserYacc.y"
           {}
#line 2003 "y.tab.cpp"
    break;

  case 42:
#line 203 "parserYacc.y"
            {}
#line 2009 "y.tab.cpp"
    break;

  case 43:
#line 204 "parserYacc.y"
                                    {}
#line 2015 "y.tab.cpp"
    break;

  case 44:
#line 205 "parserYacc.y"
                                      {}
#line 2021 "y.tab.cpp"
    break;

  case 45:
#line 207 "parserYacc.y"
               {}
#line 2027 "y.tab.cpp"
    break;

  case 46:
#line 208 "parserYacc.y"
             {}
#line 2033 "y.tab.cpp"
    break;

  case 47:
#line 210 "parserYacc.y"
              {}
#line 2039 "y.tab.cpp"
    break;

  case 48:
#line 212 "parserYacc.y"
                    {}
#line 2045 "y.tab.cpp"
    break;

  case 49:
#line 214 "parserYacc.y"
                                                                        {}
#line 2051 "y.tab.cpp"
    break;

  case 50:
#line 217 "parserYacc.y"
                {}
#line 2057 "y.tab.cpp"
    break;

  case 51:
#line 219 "parserYacc.y"
                                                   {}
#line 2063 "y.tab.cpp"
    break;

  case 52:
#line 221 "parserYacc.y"
                    {}
#line 2069 "y.tab.cpp"
    break;

  case 53:
#line 222 "parserYacc.y"
                 {}
#line 2075 "y.tab.cpp"
    break;

  case 54:
#line 224 "parserYacc.y"
                                                                                {}
#line 2081 "y.tab.cpp"
    break;

  case 55:
#line 226 "parserYacc.y"
                           {}
#line 2087 "y.tab.cpp"
    break;

  case 56:
#line 227 "parserYacc.y"
                          {}
#line 2093 "y.tab.cpp"
    break;

  case 57:
#line 229 "parserYacc.y"
                                {}
#line 2099 "y.tab.cpp"
    break;

  case 58:
#line 231 "parserYacc.y"
                {}
#line 2105 "y.tab.cpp"
    break;

  case 59:
#line 232 "parserYacc.y"
                      {}
#line 2111 "y.tab.cpp"
    break;

  case 60:
#line 233 "parserYacc.y"
           {}
#line 2117 "y.tab.cpp"
    break;

  case 61:
#line 235 "parserYacc.y"
                 {(yyval.primitivosRetorno) = new primitivos("INT");}
#line 2123 "y.tab.cpp"
    break;

  case 62:
#line 236 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("REAL");}
#line 2129 "y.tab.cpp"
    break;

  case 63:
#line 237 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("CHAR");}
#line 2135 "y.tab.cpp"
    break;

  case 64:
#line 238 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("BOOL");}
#line 2141 "y.tab.cpp"
    break;

  case 65:
#line 239 "parserYacc.y"
            {(yyval.primitivosRetorno) = new primitivos("STRING");}
#line 2147 "y.tab.cpp"
    break;

  case 66:
#line 240 "parserYacc.y"
             {(yyval.primitivosRetorno) = new primitivos("VOID");}
#line 2153 "y.tab.cpp"
    break;

  case 67:
#line 242 "parserYacc.y"
                        {}
#line 2159 "y.tab.cpp"
    break;

  case 68:
#line 243 "parserYacc.y"
                                 {}
#line 2165 "y.tab.cpp"
    break;

  case 69:
#line 245 "parserYacc.y"
                             {}
#line 2171 "y.tab.cpp"
    break;

  case 70:
#line 246 "parserYacc.y"
                                       {}
#line 2177 "y.tab.cpp"
    break;

  case 71:
#line 248 "parserYacc.y"
                                {}
#line 2183 "y.tab.cpp"
    break;

  case 72:
#line 250 "parserYacc.y"
                    {}
#line 2189 "y.tab.cpp"
    break;

  case 73:
#line 251 "parserYacc.y"
                     {}
#line 2195 "y.tab.cpp"
    break;

  case 74:
#line 253 "parserYacc.y"
                                     {}
#line 2201 "y.tab.cpp"
    break;

  case 75:
#line 255 "parserYacc.y"
                      {(yyval.exprRetorno) = new expr((yyvsp[0].exprRetorno),symtable);}
#line 2207 "y.tab.cpp"
    break;

  case 76:
#line 256 "parserYacc.y"
                      {(yyval.exprRetorno) = new expr((yyvsp[0].exprRetorno),symtable);}
#line 2213 "y.tab.cpp"
    break;

  case 77:
#line 257 "parserYacc.y"
                                   {(yyval.exprRetorno) = new expr((yyvsp[-1].exprRetorno),symtable);}
#line 2219 "y.tab.cpp"
    break;

  case 78:
#line 258 "parserYacc.y"
                        {(yyval.exprRetorno) = new expr((yyvsp[0].identifierRetorno),symtable);}
#line 2225 "y.tab.cpp"
    break;

  case 79:
#line 259 "parserYacc.y"
                {(yyval.exprRetorno) = new expr((yyvsp[0].exprRetorno),symtable);}
#line 2231 "y.tab.cpp"
    break;

  case 80:
#line 260 "parserYacc.y"
                     {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2237 "y.tab.cpp"
    break;

  case 81:
#line 261 "parserYacc.y"
                    {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2243 "y.tab.cpp"
    break;

  case 82:
#line 262 "parserYacc.y"
                      {
                  (yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2250 "y.tab.cpp"
    break;

  case 83:
#line 264 "parserYacc.y"
                       {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2256 "y.tab.cpp"
    break;

  case 84:
#line 265 "parserYacc.y"
                     {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2262 "y.tab.cpp"
    break;

  case 85:
#line 266 "parserYacc.y"
                       {
                        
                        (yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2270 "y.tab.cpp"
    break;

  case 86:
#line 269 "parserYacc.y"
                     {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2276 "y.tab.cpp"
    break;

  case 87:
#line 270 "parserYacc.y"
                        {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2282 "y.tab.cpp"
    break;

  case 88:
#line 271 "parserYacc.y"
                      {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2288 "y.tab.cpp"
    break;

  case 89:
#line 272 "parserYacc.y"
                    {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2294 "y.tab.cpp"
    break;

  case 90:
#line 273 "parserYacc.y"
                    {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2300 "y.tab.cpp"
    break;

  case 91:
#line 274 "parserYacc.y"
                     {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2306 "y.tab.cpp"
    break;

  case 92:
#line 275 "parserYacc.y"
                     {(yyval.exprRetorno) = new expr((yyvsp[-2].exprRetorno),(yyvsp[0].exprRetorno),symtable);}
#line 2312 "y.tab.cpp"
    break;

  case 93:
#line 276 "parserYacc.y"
                 {}
#line 2318 "y.tab.cpp"
    break;

  case 94:
#line 277 "parserYacc.y"
               {(yyval.exprRetorno) = new expr((yyvsp[0].literalRetorno),symtable);}
#line 2324 "y.tab.cpp"
    break;

  case 95:
#line 278 "parserYacc.y"
                  {
            (yyval.exprRetorno) = new expr((yyvsp[0].identifierRetorno),symtable);
      }
#line 2332 "y.tab.cpp"
    break;

  case 96:
#line 282 "parserYacc.y"
                                                               {}
#line 2338 "y.tab.cpp"
    break;

  case 97:
#line 286 "parserYacc.y"
                {
            (yyval.identifierRetorno) = new identifier(*(yyvsp[0].name));
      }
#line 2346 "y.tab.cpp"
    break;

  case 98:
#line 289 "parserYacc.y"
                           {(yyval.identifierRetorno) = new identifier(*(yyvsp[-1].name));}
#line 2352 "y.tab.cpp"
    break;

  case 99:
#line 290 "parserYacc.y"
                                           {(yyval.identifierRetorno) = new identifier(*(yyvsp[-3].name));}
#line 2358 "y.tab.cpp"
    break;

  case 100:
#line 291 "parserYacc.y"
                             {(yyval.identifierRetorno) = new identifier(*(yyvsp[-1].name));}
#line 2364 "y.tab.cpp"
    break;

  case 101:
#line 294 "parserYacc.y"
                                              {}
#line 2370 "y.tab.cpp"
    break;

  case 102:
#line 295 "parserYacc.y"
                                                             {}
#line 2376 "y.tab.cpp"
    break;

  case 103:
#line 298 "parserYacc.y"
                   { }
#line 2382 "y.tab.cpp"
    break;

  case 104:
#line 299 "parserYacc.y"
                      {}
#line 2388 "y.tab.cpp"
    break;

  case 105:
#line 301 "parserYacc.y"
                         {}
#line 2394 "y.tab.cpp"
    break;

  case 106:
#line 302 "parserYacc.y"
                             {}
#line 2400 "y.tab.cpp"
    break;

  case 107:
#line 304 "parserYacc.y"
                         {}
#line 2406 "y.tab.cpp"
    break;

  case 108:
#line 305 "parserYacc.y"
                                        {}
#line 2412 "y.tab.cpp"
    break;

  case 109:
#line 307 "parserYacc.y"
                 {(yyval.literalRetorno) = new literal("NUMBER");}
#line 2418 "y.tab.cpp"
    break;

  case 110:
#line 308 "parserYacc.y"
                  {(yyval.literalRetorno) = new literal("CHAR");}
#line 2424 "y.tab.cpp"
    break;

  case 111:
#line 309 "parserYacc.y"
             {(yyval.literalRetorno) = new literal("BOOL");}
#line 2430 "y.tab.cpp"
    break;

  case 112:
#line 310 "parserYacc.y"
              {(yyval.literalRetorno) = new literal("BOOL");}
#line 2436 "y.tab.cpp"
    break;

  case 113:
#line 311 "parserYacc.y"
               {(yyval.literalRetorno) = new literal("STRING");}
#line 2442 "y.tab.cpp"
    break;


#line 2446 "y.tab.cpp"

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
#line 313 "parserYacc.y"
 /* Fim da segunda seção */





int main (void) {
    
      root = initialize();

      return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
