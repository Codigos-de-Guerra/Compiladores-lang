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
#line 1 "./src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "value.hpp"
#include "symbol.cpp"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char* yytext;

/*
struct lval {
    int line;
    int col;
    // the value of the token. if it is the number 0, this is going to be 0
    string lexeme;
    int token;
    lval() {}
};


// all we have as symbols for the symbol table are identifiers. other possible
// symbols are, for example, goto labels
struct old_symbol {
    int scope = 0;
    // this is the actual name of the symbol. an id 'foo' has the name foo
    string name = "";
    string type = "";
    bool is_const= false;
    lval val;
    symbol() {}
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
        // get the relative position in the alphabet list

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
    // searches for word in the trie
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
*/


state estado;

#line 170 "./out/y.tab.cpp"

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
#ifndef YY_YY_OUT_Y_TAB_HPP_INCLUDED
# define YY_YY_OUT_Y_TAB_HPP_INCLUDED
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

#endif /* !YY_YY_OUT_Y_TAB_HPP_INCLUDED  */



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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   623

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

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
       0,   194,   194,   196,   197,   199,   200,   202,   202,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   219,   221,   223,   224,   226,   227,   229,   233,
     235,   236,   238,   239,   241,   242,   243,   245,   246,   247,
     248,   249,   251,   252,   254,   255,   257,   259,   261,   262,
     264,   266,   268,   270,   271,   272,   273,   275,   278,   282,
     283,   285,   285,   290,   291,   293,   293,   298,   299,   301,
     302,   303,   304,   305,   306,   308,   310,   311,   313,   314,
     318,   320,   321,   323,   325,   326,   327,   328,   329,   330,
     331,   332,   335,   338,   339,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   352,   354,   355,   356,   357,
     359,   360,   362,   363,   365,   366,   368,   369,   371,   372,
     373,   374,   375
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
  "GEQ", "$accept", "prog", "stmts", "stmt", "decl_fun", "$@1", "cmd",
  "$@2", "cmd_decl_var", "all_decl_var", "assign_expr_maybe",
  "decl_var_prim", "const_decl_var", "hashtagzeromais", "cochetezeromais",
  "assign_expr", "assign_extra", "inc", "inOut", "in", "out", "cmd_loop",
  "cmd_cond", "cmd_switch", "for", "para_for", "loop", "if", "else",
  "switch", "$@3", "casezeromais", "case", "$@4", "typename", "primitive",
  "type", "typedlpar", "typedlparAfter", "parameter", "parameterAfter",
  "block", "expr", "expr_tern", "identifier", "arrayAccess", "lpar",
  "lparAfter", "pointerAccess", "literal", YY_NULLPTR
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

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     204,   -50,   -40,   -26,   263,   551,    58,    -1,    15,   -20,
     -17,    23,    41,  -143,  -143,  -143,  -143,  -143,  -143,   -10,
    -143,  -143,  -143,  -143,  -143,   561,   -19,   561,   561,   561,
     561,    68,  -143,   204,  -143,  -143,    40,    19,    94,  -143,
    -143,    44,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,    47,    60,  -143,    94,  -143,   561,   561,   139,  -143,
    -143,   273,  -143,  -143,  -143,  -143,    37,    38,   561,  -143,
      47,  -143,    42,  -143,   302,   561,    43,   561,  -143,  -143,
     318,   464,   464,   464,  -143,  -143,   204,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,   561,  -143,  -143,  -143,  -143,   561,
    -143,  -143,    47,    57,   561,   561,   561,   561,   561,  -143,
     561,   561,   561,   561,   561,   561,   561,   561,    61,   330,
     374,  -143,    62,   -16,  -143,    45,    63,   382,    57,  -143,
     561,   390,    73,   434,    74,  -143,    82,   464,   464,  -143,
     561,    65,     5,     5,   177,   177,   177,   508,   508,   189,
     189,   189,   189,   189,   189,  -143,   263,  -143,   139,  -143,
    -143,  -143,  -143,  -143,  -143,    76,   442,    93,  -143,   561,
    -143,  -143,  -143,   486,  -143,   130,    99,    97,    41,   561,
    -143,   434,    57,   133,   132,   139,   -39,    83,    96,   494,
    -143,  -143,   263,  -143,   112,   132,   143,    98,   102,  -143,
    -143,    40,    41,  -143,  -143,  -143,  -143,  -143,   -11,   263,
    -143,  -143,    96,   123,  -143,  -143,   204,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    73,    72,    74,     0,
     120,   121,   118,   119,   122,     0,   106,     0,     0,     0,
       0,     0,     2,     3,     5,     6,     0,     0,    26,    24,
      25,     0,    44,    45,    12,    13,    14,    48,    49,    50,
      51,    30,     0,   102,   104,   103,     0,     0,     0,    57,
      17,     0,   104,    29,    18,    19,     0,     0,     0,    68,
      30,    67,     0,    87,     0,     0,     0,   112,   107,   109,
       0,    84,    85,    88,     1,     4,     3,    22,    10,    37,
      38,    39,    40,    41,     0,    43,    42,    23,    27,     0,
      36,    11,    30,    32,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    16,     0,     0,     0,    32,     7,
       0,     0,   116,   114,     0,    86,     0,    34,    35,    31,
       0,     0,    91,    94,    92,    93,    95,    90,    89,    96,
      97,    98,    99,   100,   101,     9,    21,    61,     0,    55,
      56,    46,    47,    20,    75,     0,     0,   110,   117,     0,
     113,   108,    83,     0,    28,     0,     0,     0,    76,     0,
     111,   114,    32,    59,    63,     0,     0,     0,    78,     0,
     115,    33,    21,    58,     0,    63,     0,     0,     0,    81,
      80,     0,     0,    77,   105,    60,    62,    64,     0,    21,
      82,     8,    78,     0,    52,    79,     3,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   -31,  -143,  -143,  -143,    -3,  -143,   -48,  -143,
    -143,   162,  -143,   -65,  -121,   122,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -142,  -143,  -143,  -143,  -143,
    -143,   -18,  -143,  -143,  -143,    -9,   166,  -143,   -33,   -21,
    -143,   -14,     1,  -143,     0,    16,  -143,     3,    50,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,    33,    34,   165,    35,    36,    37,    38,
      97,    39,    40,   103,   141,    98,    99,   100,    41,    42,
      43,    44,    45,    46,    47,   122,    48,    49,   193,    50,
     176,   194,   195,   196,    70,    51,   186,   187,   203,   188,
     200,    87,    52,    53,    62,    78,   134,   170,    79,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    59,    85,    71,    54,   128,    61,   164,    56,   198,
     121,   104,   105,   106,   107,   108,   177,   199,    57,    73,
      75,    20,    21,    22,    23,    24,    74,    76,    80,    81,
      82,    83,    58,    54,   106,   107,   108,   139,    66,    77,
      64,    67,    68,   197,   159,   160,    26,   110,   111,   112,
     113,   114,   115,   116,   117,   136,    65,   119,   120,   123,
      88,   191,    13,    14,    15,    16,    17,    18,    84,   127,
     112,   113,   114,   115,   116,   117,   131,    86,   133,    13,
      14,    15,    16,    17,    18,   101,    54,   104,   105,   106,
     107,   108,   102,   125,   126,   137,   140,    69,   129,   132,
     138,   109,   155,   158,   161,   142,   143,   144,   145,   146,
     121,   147,   148,   149,   150,   151,   152,   153,   154,    76,
     172,   174,   162,   110,   111,   112,   113,   114,   115,   116,
     117,   166,    75,   171,   178,   183,   184,   121,   185,   192,
     -65,   173,   201,   202,    89,    90,    91,    92,    93,    94,
     206,   208,     6,   175,    95,    96,    54,   209,   210,   123,
      13,    14,    15,    16,    17,    18,   216,    19,    63,    71,
     181,    20,    21,    22,    23,    24,   118,   207,    72,   215,
     189,   212,   168,   180,   190,   217,   123,   211,    25,   205,
       0,     0,    54,    71,     0,    26,   213,    27,     0,    28,
      29,    30,     0,     0,     0,     0,   214,     0,     1,    54,
       0,     2,     0,     3,     4,     5,    54,     6,     7,     8,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,     0,    19,     0,     0,     0,    20,    21,    22,    23,
      24,   -21,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,    25,   -66,   -66,   -66,   -66,   -66,   -66,
      26,     0,    27,     0,    28,    29,    30,     1,     0,     0,
       2,     0,     3,     4,     5,     0,     6,     7,     8,     9,
      10,    11,     0,     0,    13,    14,    15,    16,    17,    18,
       0,    19,     0,     0,     0,    20,    21,    22,    23,    24,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,    25,     0,   124,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   130,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,     0,   135,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   156,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   104,   105,   106,   107,   108,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,   104,   105,   106,
     107,   108,     0,   163,     0,     0,     0,     0,     0,     0,
     167,     0,     0,   157,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   110,   111,   112,   113,   114,
     115,   116,   117,   110,   111,   112,   113,   114,   115,   116,
     117,   104,   105,   106,   107,   108,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,   179,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   110,   111,   112,   113,   114,
     115,   116,   117,   104,   105,   106,   107,   108,     0,     0,
       0,   104,   105,   106,   107,   108,   182,   110,   111,   112,
     113,   114,   115,   116,   117,   104,   105,   106,   107,   108,
       0,     0,     0,   204,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,    19,
       0,     0,     0,    20,    21,    22,    23,    24,     0,    19,
       0,     0,    60,    20,    21,    22,    23,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      25,    28,    29,    30,     0,     0,     0,    26,     0,    27,
       0,    28,    29,    30
};

static const yytype_int16 yycheck[] =
{
       0,     4,    33,    12,     4,    70,     5,   128,    58,    48,
      58,    27,    28,    29,    30,    31,   158,    56,    58,    19,
      39,    32,    33,    34,    35,    36,    25,    46,    27,    28,
      29,    30,    58,    33,    29,    30,    31,   102,    58,    58,
      41,    58,    19,   185,    60,    61,    56,    63,    64,    65,
      66,    67,    68,    69,    70,    86,    41,    56,    57,    58,
      41,   182,    21,    22,    23,    24,    25,    26,     0,    68,
      65,    66,    67,    68,    69,    70,    75,    37,    77,    21,
      22,    23,    24,    25,    26,    41,    86,    27,    28,    29,
      30,    31,    45,    56,    56,    94,    39,    56,    56,    56,
      99,    41,    41,    41,    59,   104,   105,   106,   107,   108,
     158,   110,   111,   112,   113,   114,   115,   116,   117,    46,
      38,    56,    59,    63,    64,    65,    66,    67,    68,    69,
      70,   130,    39,    59,    58,     5,    37,   185,    41,     6,
       8,   140,    59,    47,    50,    51,    52,    53,    54,    55,
      38,     8,    13,   156,    60,    61,   156,    59,    56,   158,
      21,    22,    23,    24,    25,    26,    43,    28,     6,   178,
     169,    32,    33,    34,    35,    36,    54,   195,    12,   212,
     179,   202,   132,   167,   181,   216,   185,   201,    49,   192,
      -1,    -1,   192,   202,    -1,    56,   208,    58,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,   209,    -1,     4,   209,
      -1,     7,    -1,     9,    10,    11,   216,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    49,    65,    66,    67,    68,    69,    70,
      56,    -1,    58,    -1,    60,    61,    62,     4,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    41,    -1,    -1,    -1,    -1,    56,
      -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    42,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    59,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    27,    28,    29,    30,    31,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    59,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    63,    64,    65,    66,    67,
      68,    69,    70,    63,    64,    65,    66,    67,    68,    69,
      70,    27,    28,    29,    30,    31,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    63,    64,    65,    66,    67,
      68,    69,    70,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    40,    63,    64,    65,
      66,    67,    68,    69,    70,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    28,
      -1,    -1,    41,    32,    33,    34,    35,    36,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      49,    60,    61,    62,    -1,    -1,    -1,    56,    -1,    58,
      -1,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     7,     9,    10,    11,    13,    14,    15,    16,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    28,
      32,    33,    34,    35,    36,    49,    56,    58,    60,    61,
      62,    72,    73,    74,    75,    77,    78,    79,    80,    82,
      83,    89,    90,    91,    92,    93,    94,    95,    97,    98,
     100,   106,   113,   114,   115,   120,    58,    58,    58,    77,
      41,   113,   115,    82,    41,    41,    58,    58,    19,    56,
     105,   106,   107,   115,   113,    39,    46,    58,   116,   119,
     113,   113,   113,   113,     0,    73,    37,   112,    41,    50,
      51,    52,    53,    54,    55,    60,    61,    81,    86,    87,
      88,    41,    45,    84,    27,    28,    29,    30,    31,    41,
      63,    64,    65,    66,    67,    68,    69,    70,    86,   113,
     113,    79,    96,   113,    41,    56,    56,   113,    84,    56,
      42,   113,    56,   113,   117,    59,    73,   113,   113,    84,
      39,    85,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,    41,    59,    59,    41,    60,
      61,    59,    59,    41,    85,    76,   113,    40,   119,    47,
     118,    59,    38,   113,    56,    77,   101,    96,    58,    43,
     116,   113,    40,     5,    37,    41,   107,   108,   110,   113,
     118,    85,     6,    99,   102,   103,   104,    96,    48,    56,
     111,    59,    47,   109,    49,    77,    38,   102,     8,    59,
      56,   112,   110,   120,    77,   109,    43,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    76,    75,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    77,    79,    80,    80,    81,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    91,    92,    92,
      93,    94,    95,    96,    96,    96,    96,    97,    98,    99,
      99,   101,   100,   102,   102,   104,   103,   105,   105,   106,
     106,   106,   106,   106,   106,   107,   108,   108,   109,   109,
     110,   111,   111,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     0,     8,     3,
       2,     2,     1,     1,     1,     2,     3,     2,     2,     2,
       4,     0,     2,     2,     1,     1,     0,     1,     4,     2,
       0,     2,     0,     4,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     9,     1,     1,     2,     2,     2,     7,     0,
       2,     0,     8,     0,     2,     0,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     2,     0,     3,
       2,     1,     2,     3,     2,     2,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     7,     1,     2,     4,     2,
       3,     4,     0,     2,     0,     3,     2,     3,     1,     1,
       1,     1,     1
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
#line 194 "./src/parser.y"
             {}
#line 1772 "./out/y.tab.cpp"
    break;

  case 3:
#line 196 "./src/parser.y"
                      {}
#line 1778 "./out/y.tab.cpp"
    break;

  case 4:
#line 197 "./src/parser.y"
                   {}
#line 1784 "./out/y.tab.cpp"
    break;

  case 5:
#line 199 "./src/parser.y"
                {}
#line 1790 "./out/y.tab.cpp"
    break;

  case 6:
#line 200 "./src/parser.y"
           {}
#line 1796 "./out/y.tab.cpp"
    break;

  case 7:
#line 202 "./src/parser.y"
                            {
    add_sym(estado.tables, *(yyvsp[0].name), {(yyvsp[-1].type_nameRet)->name, false});
    push_scope(estado.tables);
}
#line 1805 "./out/y.tab.cpp"
    break;

  case 9:
#line 207 "./src/parser.y"
                                       {}
#line 1811 "./out/y.tab.cpp"
    break;

  case 10:
#line 208 "./src/parser.y"
                             {}
#line 1817 "./out/y.tab.cpp"
    break;

  case 11:
#line 209 "./src/parser.y"
                      {}
#line 1823 "./out/y.tab.cpp"
    break;

  case 12:
#line 210 "./src/parser.y"
               {}
#line 1829 "./out/y.tab.cpp"
    break;

  case 13:
#line 211 "./src/parser.y"
               {}
#line 1835 "./out/y.tab.cpp"
    break;

  case 14:
#line 212 "./src/parser.y"
                 {}
#line 1841 "./out/y.tab.cpp"
    break;

  case 15:
#line 213 "./src/parser.y"
                     {}
#line 1847 "./out/y.tab.cpp"
    break;

  case 16:
#line 214 "./src/parser.y"
                            {}
#line 1853 "./out/y.tab.cpp"
    break;

  case 17:
#line 215 "./src/parser.y"
                       {}
#line 1859 "./out/y.tab.cpp"
    break;

  case 18:
#line 216 "./src/parser.y"
                      {}
#line 1865 "./out/y.tab.cpp"
    break;

  case 19:
#line 217 "./src/parser.y"
                         {}
#line 1871 "./out/y.tab.cpp"
    break;

  case 20:
#line 218 "./src/parser.y"
                               {}
#line 1877 "./out/y.tab.cpp"
    break;

  case 21:
#line 219 "./src/parser.y"
      {push_scope(estado.tables);}
#line 1883 "./out/y.tab.cpp"
    break;

  case 22:
#line 219 "./src/parser.y"
                                         {(yyval.cmdRet) = NULL;}
#line 1889 "./out/y.tab.cpp"
    break;

  case 23:
#line 221 "./src/parser.y"
                                              {(yyval.cmd_decl_varRet) = new cmd_decl_var(estado,(yyvsp[-1].all_decl_varRet),(yyvsp[0].assign_expr_maybeRet));}
#line 1895 "./out/y.tab.cpp"
    break;

  case 24:
#line 223 "./src/parser.y"
                             {(yyval.all_decl_varRet) = new all_decl_var(estado,(yyvsp[0].decl_var_primRet));}
#line 1901 "./out/y.tab.cpp"
    break;

  case 25:
#line 224 "./src/parser.y"
                              {(yyval.all_decl_varRet) = new all_decl_var(estado,(yyvsp[0].const_decl_varRet));}
#line 1907 "./out/y.tab.cpp"
    break;

  case 26:
#line 226 "./src/parser.y"
                                {(yyval.assign_expr_maybeRet) = NULL;}
#line 1913 "./out/y.tab.cpp"
    break;

  case 27:
#line 227 "./src/parser.y"
                                {(yyval.assign_expr_maybeRet) = new assign_expr_maybe((yyvsp[0].assign_exprRet));}
#line 1919 "./out/y.tab.cpp"
    break;

  case 28:
#line 229 "./src/parser.y"
                                                             {
    (yyval.decl_var_primRet) = new decl_var_prim((yyvsp[-3].primitiveRet),*(yyvsp[0].name));
}
#line 1927 "./out/y.tab.cpp"
    break;

  case 29:
#line 233 "./src/parser.y"
                                     {(yyval.const_decl_varRet) = new const_decl_var((yyvsp[0].decl_var_primRet));}
#line 1933 "./out/y.tab.cpp"
    break;

  case 30:
#line 235 "./src/parser.y"
                              {(yyval.hashtagzeromaisRet) = NULL;}
#line 1939 "./out/y.tab.cpp"
    break;

  case 31:
#line 236 "./src/parser.y"
                                              {(yyval.hashtagzeromaisRet) = new hashtagzeromais((yyvsp[0].hashtagzeromaisRet));}
#line 1945 "./out/y.tab.cpp"
    break;

  case 32:
#line 238 "./src/parser.y"
                              {(yyval.cochetezeromaisRet) = NULL;}
#line 1951 "./out/y.tab.cpp"
    break;

  case 33:
#line 239 "./src/parser.y"
                                                                  {(yyval.cochetezeromaisRet) = new cochetezeromais((yyvsp[0].cochetezeromaisRet));}
#line 1957 "./out/y.tab.cpp"
    break;

  case 34:
#line 241 "./src/parser.y"
                          {(yyval.assign_exprRet) = new assign_expr((yyvsp[0].exprRet));}
#line 1963 "./out/y.tab.cpp"
    break;

  case 35:
#line 242 "./src/parser.y"
                                {(yyval.assign_exprRet) = new assign_expr();}
#line 1969 "./out/y.tab.cpp"
    break;

  case 36:
#line 243 "./src/parser.y"
                  {(yyval.assign_exprRet) = new assign_expr();}
#line 1975 "./out/y.tab.cpp"
    break;

  case 37:
#line 245 "./src/parser.y"
                           {}
#line 1981 "./out/y.tab.cpp"
    break;

  case 38:
#line 246 "./src/parser.y"
                            {}
#line 1987 "./out/y.tab.cpp"
    break;

  case 39:
#line 247 "./src/parser.y"
                           {}
#line 1993 "./out/y.tab.cpp"
    break;

  case 40:
#line 248 "./src/parser.y"
                          {}
#line 1999 "./out/y.tab.cpp"
    break;

  case 41:
#line 249 "./src/parser.y"
                          {}
#line 2005 "./out/y.tab.cpp"
    break;

  case 42:
#line 251 "./src/parser.y"
                {}
#line 2011 "./out/y.tab.cpp"
    break;

  case 43:
#line 252 "./src/parser.y"
                  {}
#line 2017 "./out/y.tab.cpp"
    break;

  case 44:
#line 254 "./src/parser.y"
           {}
#line 2023 "./out/y.tab.cpp"
    break;

  case 45:
#line 255 "./src/parser.y"
            {}
#line 2029 "./out/y.tab.cpp"
    break;

  case 46:
#line 257 "./src/parser.y"
                                    {}
#line 2035 "./out/y.tab.cpp"
    break;

  case 47:
#line 259 "./src/parser.y"
                                      {}
#line 2041 "./out/y.tab.cpp"
    break;

  case 48:
#line 261 "./src/parser.y"
               {}
#line 2047 "./out/y.tab.cpp"
    break;

  case 49:
#line 262 "./src/parser.y"
             {}
#line 2053 "./out/y.tab.cpp"
    break;

  case 50:
#line 264 "./src/parser.y"
              {}
#line 2059 "./out/y.tab.cpp"
    break;

  case 51:
#line 266 "./src/parser.y"
                    {}
#line 2065 "./out/y.tab.cpp"
    break;

  case 52:
#line 268 "./src/parser.y"
                                                                                    {}
#line 2071 "./out/y.tab.cpp"
    break;

  case 53:
#line 270 "./src/parser.y"
                       {}
#line 2077 "./out/y.tab.cpp"
    break;

  case 54:
#line 271 "./src/parser.y"
               {}
#line 2083 "./out/y.tab.cpp"
    break;

  case 55:
#line 272 "./src/parser.y"
                         {}
#line 2089 "./out/y.tab.cpp"
    break;

  case 56:
#line 273 "./src/parser.y"
                         {}
#line 2095 "./out/y.tab.cpp"
    break;

  case 57:
#line 275 "./src/parser.y"
                {}
#line 2101 "./out/y.tab.cpp"
    break;

  case 58:
#line 278 "./src/parser.y"
                                                   {
    (yyval.ifRet) = new ifa(estado, (yyvsp[-4].exprRet), (yyvsp[-2].cmdRet), (yyvsp[0].elseRet));
}
#line 2109 "./out/y.tab.cpp"
    break;

  case 59:
#line 282 "./src/parser.y"
                    {}
#line 2115 "./out/y.tab.cpp"
    break;

  case 60:
#line 283 "./src/parser.y"
                 {}
#line 2121 "./out/y.tab.cpp"
    break;

  case 61:
#line 285 "./src/parser.y"
                                            {push_scope(estado.tables);}
#line 2127 "./out/y.tab.cpp"
    break;

  case 62:
#line 285 "./src/parser.y"
                                                                                                             {
    pop_scope(estado.tables);
    (yyval.switchaRet) = new switcha((yyvsp[-5].exprRet),(yyvsp[-1].cazeZeroRet));
    }
#line 2136 "./out/y.tab.cpp"
    break;

  case 63:
#line 290 "./src/parser.y"
                           {(yyval.cazeZeroRet) = new cazezeromais();}
#line 2142 "./out/y.tab.cpp"
    break;

  case 64:
#line 291 "./src/parser.y"
                          {(yyval.cazeZeroRet) = new cazezeromais((yyvsp[-1].cazeRet),(yyvsp[0].cazeZeroRet));}
#line 2148 "./out/y.tab.cpp"
    break;

  case 65:
#line 293 "./src/parser.y"
       {push_scope(estado.tables);}
#line 2154 "./out/y.tab.cpp"
    break;

  case 66:
#line 293 "./src/parser.y"
                                                             {
    pop_scope(estado.tables);
    (yyval.cazeRet) = new caze((yyvsp[-2].literalRet));
    }
#line 2163 "./out/y.tab.cpp"
    break;

  case 67:
#line 298 "./src/parser.y"
                     {(yyval.type_nameRet) = new type_name((yyvsp[0].primitiveRet));}
#line 2169 "./out/y.tab.cpp"
    break;

  case 68:
#line 299 "./src/parser.y"
              {(yyval.type_nameRet) = new type_name(*(yyvsp[0].name));}
#line 2175 "./out/y.tab.cpp"
    break;

  case 69:
#line 301 "./src/parser.y"
                {(yyval.primitiveRet) = new primitive("INT");}
#line 2181 "./out/y.tab.cpp"
    break;

  case 70:
#line 302 "./src/parser.y"
                 {(yyval.primitiveRet) = new primitive("REAL");}
#line 2187 "./out/y.tab.cpp"
    break;

  case 71:
#line 303 "./src/parser.y"
                 {(yyval.primitiveRet) = new primitive("CHAR");}
#line 2193 "./out/y.tab.cpp"
    break;

  case 72:
#line 304 "./src/parser.y"
                 {(yyval.primitiveRet) = new primitive("BOOL");}
#line 2199 "./out/y.tab.cpp"
    break;

  case 73:
#line 305 "./src/parser.y"
                {(yyval.primitiveRet) = new primitive("STRING");}
#line 2205 "./out/y.tab.cpp"
    break;

  case 74:
#line 306 "./src/parser.y"
                 {(yyval.primitiveRet) = new primitive("VOID");}
#line 2211 "./out/y.tab.cpp"
    break;

  case 75:
#line 308 "./src/parser.y"
                                                {(yyval.type_nameRet) = (yyvsp[-2].type_nameRet);}
#line 2217 "./out/y.tab.cpp"
    break;

  case 76:
#line 310 "./src/parser.y"
                        {}
#line 2223 "./out/y.tab.cpp"
    break;

  case 77:
#line 311 "./src/parser.y"
                                     {(yyval.typedlparRet) = new typedlpar(estado, (yyvsp[-1].parameterRet), (yyvsp[0].typedlparRet));}
#line 2229 "./out/y.tab.cpp"
    break;

  case 78:
#line 313 "./src/parser.y"
                             {}
#line 2235 "./out/y.tab.cpp"
    break;

  case 79:
#line 314 "./src/parser.y"
                                                {
    (yyval.typedlparRet) = new typedlpar(estado, (yyvsp[-1].parameterRet), (yyvsp[0].typedlparRet));
}
#line 2243 "./out/y.tab.cpp"
    break;

  case 80:
#line 318 "./src/parser.y"
                                {(yyval.parameterRet) = new parameter((yyvsp[-1].type_nameRet), *(yyvsp[0].name));}
#line 2249 "./out/y.tab.cpp"
    break;

  case 81:
#line 320 "./src/parser.y"
                    {(yyval.name) = (yyvsp[0].name);}
#line 2255 "./out/y.tab.cpp"
    break;

  case 82:
#line 321 "./src/parser.y"
                              {(yyval.name) = (yyvsp[0].name);}
#line 2261 "./out/y.tab.cpp"
    break;

  case 83:
#line 323 "./src/parser.y"
                                     {pop_scope(estado.tables);}
#line 2267 "./out/y.tab.cpp"
    break;

  case 84:
#line 325 "./src/parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2273 "./out/y.tab.cpp"
    break;

  case 85:
#line 326 "./src/parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2279 "./out/y.tab.cpp"
    break;

  case 86:
#line 327 "./src/parser.y"
                                   {(yyval.exprRet) = new expr(estado, (yyvsp[-1].exprRet));}
#line 2285 "./out/y.tab.cpp"
    break;

  case 87:
#line 328 "./src/parser.y"
                        {(yyval.exprRet) = new expr(estado, (yyvsp[0].identifierRet));}
#line 2291 "./out/y.tab.cpp"
    break;

  case 88:
#line 329 "./src/parser.y"
                {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2297 "./out/y.tab.cpp"
    break;

  case 89:
#line 330 "./src/parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"&", (yyvsp[0].exprRet));}
#line 2303 "./out/y.tab.cpp"
    break;

  case 90:
#line 331 "./src/parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"|", (yyvsp[0].exprRet));}
#line 2309 "./out/y.tab.cpp"
    break;

  case 91:
#line 332 "./src/parser.y"
                      {
        
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"+", (yyvsp[0].exprRet));}
#line 2317 "./out/y.tab.cpp"
    break;

  case 92:
#line 335 "./src/parser.y"
                       {
        
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"*", (yyvsp[0].exprRet));}
#line 2325 "./out/y.tab.cpp"
    break;

  case 93:
#line 338 "./src/parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"/", (yyvsp[0].exprRet));}
#line 2331 "./out/y.tab.cpp"
    break;

  case 94:
#line 339 "./src/parser.y"
                       {
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"-", (yyvsp[0].exprRet));}
#line 2338 "./out/y.tab.cpp"
    break;

  case 95:
#line 341 "./src/parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"%", (yyvsp[0].exprRet));}
#line 2344 "./out/y.tab.cpp"
    break;

  case 96:
#line 342 "./src/parser.y"
                        {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"=", (yyvsp[0].exprRet));}
#line 2350 "./out/y.tab.cpp"
    break;

  case 97:
#line 343 "./src/parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"!=", (yyvsp[0].exprRet));}
#line 2356 "./out/y.tab.cpp"
    break;

  case 98:
#line 344 "./src/parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"<", (yyvsp[0].exprRet));}
#line 2362 "./out/y.tab.cpp"
    break;

  case 99:
#line 345 "./src/parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),">", (yyvsp[0].exprRet));}
#line 2368 "./out/y.tab.cpp"
    break;

  case 100:
#line 346 "./src/parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"<=", (yyvsp[0].exprRet));}
#line 2374 "./out/y.tab.cpp"
    break;

  case 101:
#line 347 "./src/parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),">=", (yyvsp[0].exprRet));}
#line 2380 "./out/y.tab.cpp"
    break;

  case 102:
#line 348 "./src/parser.y"
                 {}
#line 2386 "./out/y.tab.cpp"
    break;

  case 103:
#line 349 "./src/parser.y"
               {(yyval.exprRet) = new expr(estado, (yyvsp[0].literalRet));}
#line 2392 "./out/y.tab.cpp"
    break;

  case 104:
#line 350 "./src/parser.y"
                  {(yyval.exprRet) = new expr(estado, (yyvsp[0].identifierRet));}
#line 2398 "./out/y.tab.cpp"
    break;

  case 105:
#line 352 "./src/parser.y"
                                                               {}
#line 2404 "./out/y.tab.cpp"
    break;

  case 106:
#line 354 "./src/parser.y"
                {(yyval.identifierRet) = new identifier(*(yyvsp[0].name));}
#line 2410 "./out/y.tab.cpp"
    break;

  case 107:
#line 355 "./src/parser.y"
                            {(yyval.identifierRet) = new identifier(*(yyvsp[-1].name));}
#line 2416 "./out/y.tab.cpp"
    break;

  case 108:
#line 356 "./src/parser.y"
                                            {(yyval.identifierRet) = new identifier(*(yyvsp[-3].name));}
#line 2422 "./out/y.tab.cpp"
    break;

  case 109:
#line 357 "./src/parser.y"
                              {(yyval.identifierRet) = new identifier(*(yyvsp[-1].name));}
#line 2428 "./out/y.tab.cpp"
    break;

  case 110:
#line 359 "./src/parser.y"
                                              {}
#line 2434 "./out/y.tab.cpp"
    break;

  case 111:
#line 360 "./src/parser.y"
                                                            {}
#line 2440 "./out/y.tab.cpp"
    break;

  case 112:
#line 362 "./src/parser.y"
                   {}
#line 2446 "./out/y.tab.cpp"
    break;

  case 113:
#line 363 "./src/parser.y"
                      {}
#line 2452 "./out/y.tab.cpp"
    break;

  case 114:
#line 365 "./src/parser.y"
                        {}
#line 2458 "./out/y.tab.cpp"
    break;

  case 115:
#line 366 "./src/parser.y"
                                 {}
#line 2464 "./out/y.tab.cpp"
    break;

  case 116:
#line 368 "./src/parser.y"
                         {}
#line 2470 "./out/y.tab.cpp"
    break;

  case 117:
#line 369 "./src/parser.y"
                                       {}
#line 2476 "./out/y.tab.cpp"
    break;

  case 118:
#line 371 "./src/parser.y"
                 {(yyval.literalRet) = new literal("NUMBER",yytext,estado);}
#line 2482 "./out/y.tab.cpp"
    break;

  case 119:
#line 372 "./src/parser.y"
                    {(yyval.literalRet) = new literal("CHAR",yytext,estado);}
#line 2488 "./out/y.tab.cpp"
    break;

  case 120:
#line 373 "./src/parser.y"
               {(yyval.literalRet) = new literal("BOOL",yytext,estado);}
#line 2494 "./out/y.tab.cpp"
    break;

  case 121:
#line 374 "./src/parser.y"
                {(yyval.literalRet) = new literal("BOOL",yytext,estado);}
#line 2500 "./out/y.tab.cpp"
    break;

  case 122:
#line 375 "./src/parser.y"
                 {(yyval.literalRet) = new literal("STRING",yytext,estado);}
#line 2506 "./out/y.tab.cpp"
    break;


#line 2510 "./out/y.tab.cpp"

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
#line 377 "./src/parser.y"
 /* Fim da segunda seção */

int main (void) {
      /* root = initialize(); */

    yyparse();
    if(estado.deuErro){
        cout<<"ERRO DE COMPILACAO\n";
    }
    else cout<<estado.arquivoEscrita;
    return 0;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    
	return 0;
}
