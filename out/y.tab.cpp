/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 171 "./out/y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '['  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ENDIF = 5,                      /* ENDIF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_CASE = 8,                       /* CASE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_LOOP = 10,                      /* LOOP  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_CONST = 13,                     /* CONST  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_READ = 16,                      /* READ  */
  YYSYMBOL_WRITE = 17,                     /* WRITE  */
  YYSYMBOL_EXIT = 18,                      /* EXIT  */
  YYSYMBOL_WHEN = 19,                      /* WHEN  */
  YYSYMBOL_FUNCTION = 20,                  /* FUNCTION  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_REAL = 22,                      /* REAL  */
  YYSYMBOL_CHAR = 23,                      /* CHAR  */
  YYSYMBOL_STR = 24,                       /* STR  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_VOID = 26,                      /* VOID  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_TIMES = 29,                     /* TIMES  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_MOD = 31,                       /* MOD  */
  YYSYMBOL_TRUE = 32,                      /* TRUE  */
  YYSYMBOL_FALSE = 33,                     /* FALSE  */
  YYSYMBOL_NUMBER = 34,                    /* NUMBER  */
  YYSYMBOL_CHARACTER = 35,                 /* CHARACTER  */
  YYSYMBOL_STRING = 36,                    /* STRING  */
  YYSYMBOL_LEFT_BRACE = 37,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 38,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 39,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 40,             /* RIGHT_BRACKET  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_QUESTION_MARK = 42,             /* QUESTION_MARK  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_POINTER_VAL = 45,               /* POINTER_VAL  */
  YYSYMBOL_ARROW = 46,                     /* ARROW  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_REFERENCE = 48,                 /* REFERENCE  */
  YYSYMBOL_TERNARY = 49,                   /* TERNARY  */
  YYSYMBOL_ASSIGN_PLUS = 50,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 51,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_MULT = 52,               /* ASSIGN_MULT  */
  YYSYMBOL_ASSIGN_DIV = 53,                /* ASSIGN_DIV  */
  YYSYMBOL_ASSIGN_MOD = 54,                /* ASSIGN_MOD  */
  YYSYMBOL_ASSIGN = 55,                    /* ASSIGN  */
  YYSYMBOL_ID = 56,                        /* ID  */
  YYSYMBOL_57_ = 57,                       /* '@'  */
  YYSYMBOL_LEFT_PAREN = 58,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 59,               /* RIGHT_PAREN  */
  YYSYMBOL_INCREMENT = 60,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 61,                 /* DECREMENT  */
  YYSYMBOL_NOT = 62,                       /* NOT  */
  YYSYMBOL_OR = 63,                        /* OR  */
  YYSYMBOL_AND = 64,                       /* AND  */
  YYSYMBOL_EQUALS = 65,                    /* EQUALS  */
  YYSYMBOL_DIFF = 66,                      /* DIFF  */
  YYSYMBOL_LT = 67,                        /* LT  */
  YYSYMBOL_GT = 68,                        /* GT  */
  YYSYMBOL_LEQ = 69,                       /* LEQ  */
  YYSYMBOL_GEQ = 70,                       /* GEQ  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_prog = 72,                      /* prog  */
  YYSYMBOL_stmts = 73,                     /* stmts  */
  YYSYMBOL_stmt = 74,                      /* stmt  */
  YYSYMBOL_decl_fun = 75,                  /* decl_fun  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_cmd = 77,                       /* cmd  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_cmd_decl_var = 79,              /* cmd_decl_var  */
  YYSYMBOL_all_decl_var = 80,              /* all_decl_var  */
  YYSYMBOL_assign_expr_maybe = 81,         /* assign_expr_maybe  */
  YYSYMBOL_decl_var_prim = 82,             /* decl_var_prim  */
  YYSYMBOL_const_decl_var = 83,            /* const_decl_var  */
  YYSYMBOL_hashtagzeromais = 84,           /* hashtagzeromais  */
  YYSYMBOL_cochetezeromais = 85,           /* cochetezeromais  */
  YYSYMBOL_assign_expr = 86,               /* assign_expr  */
  YYSYMBOL_assign_extra = 87,              /* assign_extra  */
  YYSYMBOL_inc = 88,                       /* inc  */
  YYSYMBOL_inOut = 89,                     /* inOut  */
  YYSYMBOL_in = 90,                        /* in  */
  YYSYMBOL_out = 91,                       /* out  */
  YYSYMBOL_cmd_loop = 92,                  /* cmd_loop  */
  YYSYMBOL_cmd_cond = 93,                  /* cmd_cond  */
  YYSYMBOL_cmd_switch = 94,                /* cmd_switch  */
  YYSYMBOL_for = 95,                       /* for  */
  YYSYMBOL_para_for = 96,                  /* para_for  */
  YYSYMBOL_loop = 97,                      /* loop  */
  YYSYMBOL_if = 98,                        /* if  */
  YYSYMBOL_else = 99,                      /* else  */
  YYSYMBOL_switch = 100,                   /* switch  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_casezeromais = 102,             /* casezeromais  */
  YYSYMBOL_case = 103,                     /* case  */
  YYSYMBOL_104_4 = 104,                    /* $@4  */
  YYSYMBOL_typename = 105,                 /* typename  */
  YYSYMBOL_primitive = 106,                /* primitive  */
  YYSYMBOL_type = 107,                     /* type  */
  YYSYMBOL_typedlpar = 108,                /* typedlpar  */
  YYSYMBOL_typedlparAfter = 109,           /* typedlparAfter  */
  YYSYMBOL_parameter = 110,                /* parameter  */
  YYSYMBOL_parameterAfter = 111,           /* parameterAfter  */
  YYSYMBOL_block = 112,                    /* block  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_expr_tern = 114,                /* expr_tern  */
  YYSYMBOL_identifier = 115,               /* identifier  */
  YYSYMBOL_arrayAccess = 116,              /* arrayAccess  */
  YYSYMBOL_lpar = 117,                     /* lpar  */
  YYSYMBOL_lparAfter = 118,                /* lparAfter  */
  YYSYMBOL_pointerAccess = 119,            /* pointerAccess  */
  YYSYMBOL_literal = 120                   /* literal  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
       0,   199,   199,   201,   202,   204,   205,   207,   207,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   224,   226,   228,   229,   231,   232,   234,   238,
     240,   241,   243,   244,   246,   247,   248,   250,   251,   252,
     253,   254,   256,   257,   259,   260,   262,   264,   266,   267,
     269,   271,   273,   275,   276,   277,   278,   280,   283,   287,
     288,   290,   290,   295,   296,   298,   298,   303,   304,   306,
     307,   308,   309,   310,   311,   313,   315,   316,   318,   319,
     323,   325,   326,   328,   333,   334,   335,   336,   337,   338,
     339,   340,   343,   346,   347,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   360,   362,   363,   364,   365,
     367,   368,   370,   371,   373,   374,   376,   377,   379,   380,
     381,   382,   383
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
  "\"end of file\"", "error", "\"invalid token\"", "'['", "IF", "ENDIF",
  "ELSE", "SWITCH", "CASE", "FOR", "LOOP", "RETURN", "STRUCT", "CONST",
  "BREAK", "CONTINUE", "READ", "WRITE", "EXIT", "WHEN", "FUNCTION", "INT",
  "REAL", "CHAR", "STR", "BOOL", "VOID", "PLUS", "MINUS", "TIMES", "DIV",
  "MOD", "TRUE", "FALSE", "NUMBER", "CHARACTER", "STRING", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "SEMICOLON",
  "QUESTION_MARK", "COLON", "DOT", "POINTER_VAL", "ARROW", "COMMA",
  "REFERENCE", "TERNARY", "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULT",
  "ASSIGN_DIV", "ASSIGN_MOD", "ASSIGN", "ID", "'@'", "LEFT_PAREN",
  "RIGHT_PAREN", "INCREMENT", "DECREMENT", "NOT", "OR", "AND", "EQUALS",
  "DIFF", "LT", "GT", "LEQ", "GEQ", "$accept", "prog", "stmts", "stmt",
  "decl_fun", "$@1", "cmd", "$@2", "cmd_decl_var", "all_decl_var",
  "assign_expr_maybe", "decl_var_prim", "const_decl_var",
  "hashtagzeromais", "cochetezeromais", "assign_expr", "assign_extra",
  "inc", "inOut", "in", "out", "cmd_loop", "cmd_cond", "cmd_switch", "for",
  "para_for", "loop", "if", "else", "switch", "$@3", "casezeromais",
  "case", "$@4", "typename", "primitive", "type", "typedlpar",
  "typedlparAfter", "parameter", "parameterAfter", "block", "expr",
  "expr_tern", "identifier", "arrayAccess", "lpar", "lparAfter",
  "pointerAccess", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
static const yytype_uint8 yydefgoto[] =
{
       0,    31,    32,    33,    34,   165,    35,    36,    37,    38,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* prog: stmts  */
#line 199 "parser.y"
             {(yyval.programaRet) = new programa(estado, (yyvsp[0].statementsRet));}
#line 1520 "./out/y.tab.cpp"
    break;

  case 3: /* stmts: %empty  */
#line 201 "parser.y"
                      {(yyval.statementsRet) = NULL;}
#line 1526 "./out/y.tab.cpp"
    break;

  case 4: /* stmts: stmt stmts  */
#line 202 "parser.y"
                   {(yyval.statementsRet) = new statements((yyvsp[-1].statementRet),(yyvsp[0].statementsRet));}
#line 1532 "./out/y.tab.cpp"
    break;

  case 5: /* stmt: decl_fun  */
#line 204 "parser.y"
                {(yyval.statementRet) = new statement((yyvsp[0].decl_funRet));}
#line 1538 "./out/y.tab.cpp"
    break;

  case 6: /* stmt: cmd  */
#line 205 "parser.y"
           {(yyval.statementRet) = new statement((yyvsp[0].cmdRet));}
#line 1544 "./out/y.tab.cpp"
    break;

  case 7: /* $@1: %empty  */
#line 207 "parser.y"
                            {
    add_sym(estado.tables, *(yyvsp[0].name), {(yyvsp[-1].type_nameRet)->name, false});
    push_scope(estado.tables);
}
#line 1553 "./out/y.tab.cpp"
    break;

  case 8: /* decl_fun: FUNCTION type ID $@1 LEFT_PAREN typedlpar RIGHT_PAREN block  */
#line 210 "parser.y"
                                         {(yyval.decl_funRet) = new decl_fun(/*$2,$6,$8*/);}
#line 1559 "./out/y.tab.cpp"
    break;

  case 9: /* cmd: identifier assign_expr SEMICOLON  */
#line 212 "parser.y"
                                       {}
#line 1565 "./out/y.tab.cpp"
    break;

  case 10: /* cmd: cmd_decl_var SEMICOLON  */
#line 213 "parser.y"
                             {(yyval.cmdRet) = new cmd((yyvsp[-1].cmd_decl_varRet));}
#line 1571 "./out/y.tab.cpp"
    break;

  case 11: /* cmd: inOut SEMICOLON  */
#line 214 "parser.y"
                      {}
#line 1577 "./out/y.tab.cpp"
    break;

  case 12: /* cmd: cmd_loop  */
#line 215 "parser.y"
               {}
#line 1583 "./out/y.tab.cpp"
    break;

  case 13: /* cmd: cmd_cond  */
#line 216 "parser.y"
               {}
#line 1589 "./out/y.tab.cpp"
    break;

  case 14: /* cmd: cmd_switch  */
#line 217 "parser.y"
                 {}
#line 1595 "./out/y.tab.cpp"
    break;

  case 15: /* cmd: expr SEMICOLON  */
#line 218 "parser.y"
                     {}
#line 1601 "./out/y.tab.cpp"
    break;

  case 16: /* cmd: RETURN expr SEMICOLON  */
#line 219 "parser.y"
                            {}
#line 1607 "./out/y.tab.cpp"
    break;

  case 17: /* cmd: RETURN SEMICOLON  */
#line 220 "parser.y"
                       {}
#line 1613 "./out/y.tab.cpp"
    break;

  case 18: /* cmd: BREAK SEMICOLON  */
#line 221 "parser.y"
                      {}
#line 1619 "./out/y.tab.cpp"
    break;

  case 19: /* cmd: CONTINUE SEMICOLON  */
#line 222 "parser.y"
                         {}
#line 1625 "./out/y.tab.cpp"
    break;

  case 20: /* cmd: EXIT WHEN expr SEMICOLON  */
#line 223 "parser.y"
                               {}
#line 1631 "./out/y.tab.cpp"
    break;

  case 21: /* $@2: %empty  */
#line 224 "parser.y"
      {push_scope(estado.tables);}
#line 1637 "./out/y.tab.cpp"
    break;

  case 22: /* cmd: $@2 block  */
#line 224 "parser.y"
                                         {(yyval.cmdRet) = new cmd((yyvsp[0].blockRet));}
#line 1643 "./out/y.tab.cpp"
    break;

  case 23: /* cmd_decl_var: all_decl_var assign_expr_maybe  */
#line 226 "parser.y"
                                              {(yyval.cmd_decl_varRet) = new cmd_decl_var(estado,(yyvsp[-1].all_decl_varRet),(yyvsp[0].assign_expr_maybeRet));}
#line 1649 "./out/y.tab.cpp"
    break;

  case 24: /* all_decl_var: decl_var_prim  */
#line 228 "parser.y"
                             {(yyval.all_decl_varRet) = new all_decl_var(estado,(yyvsp[0].decl_var_primRet));}
#line 1655 "./out/y.tab.cpp"
    break;

  case 25: /* all_decl_var: const_decl_var  */
#line 229 "parser.y"
                              {(yyval.all_decl_varRet) = new all_decl_var(estado,(yyvsp[0].const_decl_varRet));}
#line 1661 "./out/y.tab.cpp"
    break;

  case 26: /* assign_expr_maybe: %empty  */
#line 231 "parser.y"
                                {(yyval.assign_expr_maybeRet) = NULL;}
#line 1667 "./out/y.tab.cpp"
    break;

  case 27: /* assign_expr_maybe: assign_expr  */
#line 232 "parser.y"
                                {(yyval.assign_expr_maybeRet) = new assign_expr_maybe((yyvsp[0].assign_exprRet));}
#line 1673 "./out/y.tab.cpp"
    break;

  case 28: /* decl_var_prim: primitive hashtagzeromais cochetezeromais ID  */
#line 234 "parser.y"
                                                             {
    (yyval.decl_var_primRet) = new decl_var_prim((yyvsp[-3].primitiveRet),*(yyvsp[0].name));
}
#line 1681 "./out/y.tab.cpp"
    break;

  case 29: /* const_decl_var: CONST decl_var_prim  */
#line 238 "parser.y"
                                     {(yyval.const_decl_varRet) = new const_decl_var((yyvsp[0].decl_var_primRet));}
#line 1687 "./out/y.tab.cpp"
    break;

  case 30: /* hashtagzeromais: %empty  */
#line 240 "parser.y"
                              {(yyval.hashtagzeromaisRet) = NULL;}
#line 1693 "./out/y.tab.cpp"
    break;

  case 31: /* hashtagzeromais: POINTER_VAL hashtagzeromais  */
#line 241 "parser.y"
                                              {(yyval.hashtagzeromaisRet) = new hashtagzeromais((yyvsp[0].hashtagzeromaisRet));}
#line 1699 "./out/y.tab.cpp"
    break;

  case 32: /* cochetezeromais: %empty  */
#line 243 "parser.y"
                              {(yyval.cochetezeromaisRet) = NULL;}
#line 1705 "./out/y.tab.cpp"
    break;

  case 33: /* cochetezeromais: LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais  */
#line 244 "parser.y"
                                                                  {(yyval.cochetezeromaisRet) = new cochetezeromais((yyvsp[0].cochetezeromaisRet));}
#line 1711 "./out/y.tab.cpp"
    break;

  case 34: /* assign_expr: ASSIGN expr  */
#line 246 "parser.y"
                          {(yyval.assign_exprRet) = new assign_expr((yyvsp[0].exprRet));}
#line 1717 "./out/y.tab.cpp"
    break;

  case 35: /* assign_expr: assign_extra expr  */
#line 247 "parser.y"
                                {(yyval.assign_exprRet) = new assign_expr();}
#line 1723 "./out/y.tab.cpp"
    break;

  case 36: /* assign_expr: inc  */
#line 248 "parser.y"
                  {(yyval.assign_exprRet) = new assign_expr();}
#line 1729 "./out/y.tab.cpp"
    break;

  case 37: /* assign_extra: ASSIGN_PLUS  */
#line 250 "parser.y"
                           {}
#line 1735 "./out/y.tab.cpp"
    break;

  case 38: /* assign_extra: ASSIGN_MINUS  */
#line 251 "parser.y"
                            {}
#line 1741 "./out/y.tab.cpp"
    break;

  case 39: /* assign_extra: ASSIGN_MULT  */
#line 252 "parser.y"
                           {}
#line 1747 "./out/y.tab.cpp"
    break;

  case 40: /* assign_extra: ASSIGN_DIV  */
#line 253 "parser.y"
                          {}
#line 1753 "./out/y.tab.cpp"
    break;

  case 41: /* assign_extra: ASSIGN_MOD  */
#line 254 "parser.y"
                          {}
#line 1759 "./out/y.tab.cpp"
    break;

  case 42: /* inc: DECREMENT  */
#line 256 "parser.y"
                {}
#line 1765 "./out/y.tab.cpp"
    break;

  case 43: /* inc: INCREMENT  */
#line 257 "parser.y"
                  {}
#line 1771 "./out/y.tab.cpp"
    break;

  case 44: /* inOut: in  */
#line 259 "parser.y"
           {}
#line 1777 "./out/y.tab.cpp"
    break;

  case 45: /* inOut: out  */
#line 260 "parser.y"
            {}
#line 1783 "./out/y.tab.cpp"
    break;

  case 46: /* in: READ LEFT_PAREN ID RIGHT_PAREN  */
#line 262 "parser.y"
                                    {}
#line 1789 "./out/y.tab.cpp"
    break;

  case 47: /* out: WRITE LEFT_PAREN ID RIGHT_PAREN  */
#line 264 "parser.y"
                                      {}
#line 1795 "./out/y.tab.cpp"
    break;

  case 48: /* cmd_loop: for  */
#line 266 "parser.y"
               {}
#line 1801 "./out/y.tab.cpp"
    break;

  case 49: /* cmd_loop: loop  */
#line 267 "parser.y"
             {}
#line 1807 "./out/y.tab.cpp"
    break;

  case 50: /* cmd_cond: if  */
#line 269 "parser.y"
              {}
#line 1813 "./out/y.tab.cpp"
    break;

  case 51: /* cmd_switch: switch  */
#line 271 "parser.y"
                    {}
#line 1819 "./out/y.tab.cpp"
    break;

  case 52: /* for: FOR LEFT_PAREN para_for SEMICOLON para_for SEMICOLON para_for RIGHT_PAREN cmd  */
#line 273 "parser.y"
                                                                                    {}
#line 1825 "./out/y.tab.cpp"
    break;

  case 53: /* para_for: cmd_decl_var  */
#line 275 "parser.y"
                       {}
#line 1831 "./out/y.tab.cpp"
    break;

  case 54: /* para_for: expr  */
#line 276 "parser.y"
               {}
#line 1837 "./out/y.tab.cpp"
    break;

  case 55: /* para_for: expr INCREMENT  */
#line 277 "parser.y"
                         {}
#line 1843 "./out/y.tab.cpp"
    break;

  case 56: /* para_for: expr DECREMENT  */
#line 278 "parser.y"
                         {}
#line 1849 "./out/y.tab.cpp"
    break;

  case 57: /* loop: LOOP cmd  */
#line 280 "parser.y"
                {}
#line 1855 "./out/y.tab.cpp"
    break;

  case 58: /* if: IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else  */
#line 283 "parser.y"
                                                   {
    (yyval.ifRet) = new ifa(estado, (yyvsp[-4].exprRet), (yyvsp[-2].cmdRet), (yyvsp[0].elseRet));
}
#line 1863 "./out/y.tab.cpp"
    break;

  case 59: /* else: %empty  */
#line 287 "parser.y"
                    {(yyval.elseRet) = NULL;}
#line 1869 "./out/y.tab.cpp"
    break;

  case 60: /* else: ELSE cmd  */
#line 288 "parser.y"
                 {}
#line 1875 "./out/y.tab.cpp"
    break;

  case 61: /* $@3: %empty  */
#line 290 "parser.y"
                                            {push_scope(estado.tables);}
#line 1881 "./out/y.tab.cpp"
    break;

  case 62: /* switch: SWITCH LEFT_PAREN expr RIGHT_PAREN $@3 LEFT_BRACE casezeromais RIGHT_BRACE  */
#line 290 "parser.y"
                                                                                                             {
    pop_scope(estado.tables);
    (yyval.switchaRet) = new switcha(estado,(yyvsp[-5].exprRet),(yyvsp[-1].cazeZeroRet));
    }
#line 1890 "./out/y.tab.cpp"
    break;

  case 63: /* casezeromais: %empty  */
#line 295 "parser.y"
                           {(yyval.cazeZeroRet) = new cazezeromais();}
#line 1896 "./out/y.tab.cpp"
    break;

  case 64: /* casezeromais: case casezeromais  */
#line 296 "parser.y"
                          {(yyval.cazeZeroRet) = new cazezeromais(estado,(yyvsp[-1].cazeRet),(yyvsp[0].cazeZeroRet));}
#line 1902 "./out/y.tab.cpp"
    break;

  case 65: /* $@4: %empty  */
#line 298 "parser.y"
       {push_scope(estado.tables);}
#line 1908 "./out/y.tab.cpp"
    break;

  case 66: /* case: $@4 CASE literal COLON stmts  */
#line 298 "parser.y"
                                                             {
    pop_scope(estado.tables);
    (yyval.cazeRet) = new caze((yyvsp[-2].literalRet));
    }
#line 1917 "./out/y.tab.cpp"
    break;

  case 67: /* typename: primitive  */
#line 303 "parser.y"
                     {(yyval.type_nameRet) = new type_name((yyvsp[0].primitiveRet));}
#line 1923 "./out/y.tab.cpp"
    break;

  case 68: /* typename: ID  */
#line 304 "parser.y"
              {(yyval.type_nameRet) = new type_name(*(yyvsp[0].name));}
#line 1929 "./out/y.tab.cpp"
    break;

  case 69: /* primitive: INT  */
#line 306 "parser.y"
                {(yyval.primitiveRet) = new primitive("INT");}
#line 1935 "./out/y.tab.cpp"
    break;

  case 70: /* primitive: REAL  */
#line 307 "parser.y"
                 {(yyval.primitiveRet) = new primitive("REAL");}
#line 1941 "./out/y.tab.cpp"
    break;

  case 71: /* primitive: CHAR  */
#line 308 "parser.y"
                 {(yyval.primitiveRet) = new primitive("CHAR");}
#line 1947 "./out/y.tab.cpp"
    break;

  case 72: /* primitive: BOOL  */
#line 309 "parser.y"
                 {(yyval.primitiveRet) = new primitive("BOOL");}
#line 1953 "./out/y.tab.cpp"
    break;

  case 73: /* primitive: STR  */
#line 310 "parser.y"
                {(yyval.primitiveRet) = new primitive("STRING");}
#line 1959 "./out/y.tab.cpp"
    break;

  case 74: /* primitive: VOID  */
#line 311 "parser.y"
                 {(yyval.primitiveRet) = new primitive("VOID");}
#line 1965 "./out/y.tab.cpp"
    break;

  case 75: /* type: typename hashtagzeromais cochetezeromais  */
#line 313 "parser.y"
                                                {(yyval.type_nameRet) = (yyvsp[-2].type_nameRet);}
#line 1971 "./out/y.tab.cpp"
    break;

  case 76: /* typedlpar: %empty  */
#line 315 "parser.y"
                        {}
#line 1977 "./out/y.tab.cpp"
    break;

  case 77: /* typedlpar: parameter typedlparAfter  */
#line 316 "parser.y"
                                     {(yyval.typedlparRet) = new typedlpar(estado, (yyvsp[-1].parameterRet), (yyvsp[0].typedlparRet));}
#line 1983 "./out/y.tab.cpp"
    break;

  case 78: /* typedlparAfter: %empty  */
#line 318 "parser.y"
                             {}
#line 1989 "./out/y.tab.cpp"
    break;

  case 79: /* typedlparAfter: COMMA parameter typedlparAfter  */
#line 319 "parser.y"
                                                {
    (yyval.typedlparRet) = new typedlpar(estado, (yyvsp[-1].parameterRet), (yyvsp[0].typedlparRet));
}
#line 1997 "./out/y.tab.cpp"
    break;

  case 80: /* parameter: type parameterAfter  */
#line 323 "parser.y"
                                {(yyval.parameterRet) = new parameter((yyvsp[-1].type_nameRet), *(yyvsp[0].name));}
#line 2003 "./out/y.tab.cpp"
    break;

  case 81: /* parameterAfter: ID  */
#line 325 "parser.y"
                    {(yyval.name) = (yyvsp[0].name);}
#line 2009 "./out/y.tab.cpp"
    break;

  case 82: /* parameterAfter: REFERENCE ID  */
#line 326 "parser.y"
                              {(yyval.name) = (yyvsp[0].name);}
#line 2015 "./out/y.tab.cpp"
    break;

  case 83: /* block: LEFT_BRACE stmts RIGHT_BRACE  */
#line 328 "parser.y"
                                     {
    pop_scope(estado.tables);
    (yyval.blockRet) = new block((yyvsp[-1].statementsRet));
}
#line 2024 "./out/y.tab.cpp"
    break;

  case 84: /* expr: INCREMENT expr  */
#line 333 "parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2030 "./out/y.tab.cpp"
    break;

  case 85: /* expr: DECREMENT expr  */
#line 334 "parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2036 "./out/y.tab.cpp"
    break;

  case 86: /* expr: LEFT_PAREN expr RIGHT_PAREN  */
#line 335 "parser.y"
                                   {(yyval.exprRet) = new expr(estado, (yyvsp[-1].exprRet));}
#line 2042 "./out/y.tab.cpp"
    break;

  case 87: /* expr: MINUS identifier  */
#line 336 "parser.y"
                        {(yyval.exprRet) = new expr(estado, (yyvsp[0].identifierRet));}
#line 2048 "./out/y.tab.cpp"
    break;

  case 88: /* expr: NOT expr  */
#line 337 "parser.y"
                {(yyval.exprRet) = new expr(estado, (yyvsp[0].exprRet));}
#line 2054 "./out/y.tab.cpp"
    break;

  case 89: /* expr: expr AND expr  */
#line 338 "parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"&", (yyvsp[0].exprRet));}
#line 2060 "./out/y.tab.cpp"
    break;

  case 90: /* expr: expr OR expr  */
#line 339 "parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"|", (yyvsp[0].exprRet));}
#line 2066 "./out/y.tab.cpp"
    break;

  case 91: /* expr: expr PLUS expr  */
#line 340 "parser.y"
                      {
        
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"+", (yyvsp[0].exprRet));}
#line 2074 "./out/y.tab.cpp"
    break;

  case 92: /* expr: expr TIMES expr  */
#line 343 "parser.y"
                       {
        
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"*", (yyvsp[0].exprRet));}
#line 2082 "./out/y.tab.cpp"
    break;

  case 93: /* expr: expr DIV expr  */
#line 346 "parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"/", (yyvsp[0].exprRet));}
#line 2088 "./out/y.tab.cpp"
    break;

  case 94: /* expr: expr MINUS expr  */
#line 347 "parser.y"
                       {
        (yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"-", (yyvsp[0].exprRet));}
#line 2095 "./out/y.tab.cpp"
    break;

  case 95: /* expr: expr MOD expr  */
#line 349 "parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"%", (yyvsp[0].exprRet));}
#line 2101 "./out/y.tab.cpp"
    break;

  case 96: /* expr: expr EQUALS expr  */
#line 350 "parser.y"
                        {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"=", (yyvsp[0].exprRet));}
#line 2107 "./out/y.tab.cpp"
    break;

  case 97: /* expr: expr DIFF expr  */
#line 351 "parser.y"
                      {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"!=", (yyvsp[0].exprRet));}
#line 2113 "./out/y.tab.cpp"
    break;

  case 98: /* expr: expr LT expr  */
#line 352 "parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"<", (yyvsp[0].exprRet));}
#line 2119 "./out/y.tab.cpp"
    break;

  case 99: /* expr: expr GT expr  */
#line 353 "parser.y"
                    {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),">", (yyvsp[0].exprRet));}
#line 2125 "./out/y.tab.cpp"
    break;

  case 100: /* expr: expr LEQ expr  */
#line 354 "parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),"<=", (yyvsp[0].exprRet));}
#line 2131 "./out/y.tab.cpp"
    break;

  case 101: /* expr: expr GEQ expr  */
#line 355 "parser.y"
                     {(yyval.exprRet) = new expr(estado, (yyvsp[-2].exprRet),">=", (yyvsp[0].exprRet));}
#line 2137 "./out/y.tab.cpp"
    break;

  case 102: /* expr: expr_tern  */
#line 356 "parser.y"
                 {}
#line 2143 "./out/y.tab.cpp"
    break;

  case 103: /* expr: literal  */
#line 357 "parser.y"
               {(yyval.exprRet) = new expr(estado, (yyvsp[0].literalRet));}
#line 2149 "./out/y.tab.cpp"
    break;

  case 104: /* expr: identifier  */
#line 358 "parser.y"
                  {(yyval.exprRet) = new expr(estado, (yyvsp[0].identifierRet));}
#line 2155 "./out/y.tab.cpp"
    break;

  case 105: /* expr_tern: TERNARY expr QUESTION_MARK expr COLON expr TERNARY  */
#line 360 "parser.y"
                                                               {}
#line 2161 "./out/y.tab.cpp"
    break;

  case 106: /* identifier: ID  */
#line 362 "parser.y"
                {(yyval.identifierRet) = new identifier(*(yyvsp[0].name));}
#line 2167 "./out/y.tab.cpp"
    break;

  case 107: /* identifier: ID arrayAccess  */
#line 363 "parser.y"
                            {(yyval.identifierRet) = new identifier(*(yyvsp[-1].name));}
#line 2173 "./out/y.tab.cpp"
    break;

  case 108: /* identifier: ID LEFT_PAREN lpar RIGHT_PAREN  */
#line 364 "parser.y"
                                            {(yyval.identifierRet) = new identifier(*(yyvsp[-3].name));}
#line 2179 "./out/y.tab.cpp"
    break;

  case 109: /* identifier: ID pointerAccess  */
#line 365 "parser.y"
                              {(yyval.identifierRet) = new identifier(*(yyvsp[-1].name));}
#line 2185 "./out/y.tab.cpp"
    break;

  case 110: /* arrayAccess: LEFT_BRACKET expr RIGHT_BRACKET  */
#line 367 "parser.y"
                                              {}
#line 2191 "./out/y.tab.cpp"
    break;

  case 111: /* arrayAccess: LEFT_BRACKET expr RIGHT_BRACKET arrayAccess  */
#line 368 "parser.y"
                                                            {}
#line 2197 "./out/y.tab.cpp"
    break;

  case 112: /* lpar: %empty  */
#line 370 "parser.y"
                   {}
#line 2203 "./out/y.tab.cpp"
    break;

  case 113: /* lpar: expr lparAfter  */
#line 371 "parser.y"
                      {}
#line 2209 "./out/y.tab.cpp"
    break;

  case 114: /* lparAfter: %empty  */
#line 373 "parser.y"
                        {}
#line 2215 "./out/y.tab.cpp"
    break;

  case 115: /* lparAfter: COMMA expr lparAfter  */
#line 374 "parser.y"
                                 {}
#line 2221 "./out/y.tab.cpp"
    break;

  case 116: /* pointerAccess: ARROW ID  */
#line 376 "parser.y"
                         {}
#line 2227 "./out/y.tab.cpp"
    break;

  case 117: /* pointerAccess: ARROW ID pointerAccess  */
#line 377 "parser.y"
                                       {}
#line 2233 "./out/y.tab.cpp"
    break;

  case 118: /* literal: NUMBER  */
#line 379 "parser.y"
                 {(yyval.literalRet) = new literal("NUMBER",yytext,estado);}
#line 2239 "./out/y.tab.cpp"
    break;

  case 119: /* literal: CHARACTER  */
#line 380 "parser.y"
                    {(yyval.literalRet) = new literal("CHAR",yytext,estado);}
#line 2245 "./out/y.tab.cpp"
    break;

  case 120: /* literal: TRUE  */
#line 381 "parser.y"
               {(yyval.literalRet) = new literal("BOOL",yytext,estado);}
#line 2251 "./out/y.tab.cpp"
    break;

  case 121: /* literal: FALSE  */
#line 382 "parser.y"
                {(yyval.literalRet) = new literal("BOOL",yytext,estado);}
#line 2257 "./out/y.tab.cpp"
    break;

  case 122: /* literal: STRING  */
#line 383 "parser.y"
                 {(yyval.literalRet) = new literal("STRING",yytext,estado);}
#line 2263 "./out/y.tab.cpp"
    break;


#line 2267 "./out/y.tab.cpp"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 385 "parser.y"
 /* Fim da segunda seção */

int main (void) {
      /* root = initialize(); */

    yyparse();
    if (estado.deuErro) {
        cout << "ERRO DE COMPILACAO\n";
    }
    else cout << estado.arquivoEscrita;
    return 0;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    
	return 0;
}
