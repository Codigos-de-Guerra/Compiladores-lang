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
#line 1 "./src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tipos.hpp"

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

SymTable symtable;

void print_symtable(SymTable &symtable) {
  for (auto const &sym : symtable) {
    string key = sym.first;
    Symbol val = sym.second;

    cout << "{" << key << " = " << val << "}" << endl;
  }
}

#line 178 "./out/y.tab.cpp"

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
  YYSYMBOL_ID = 41,                        /* ID  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_QUESTION_MARK = 43,             /* QUESTION_MARK  */
  YYSYMBOL_COLON = 44,                     /* COLON  */
  YYSYMBOL_DOT = 45,                       /* DOT  */
  YYSYMBOL_POINTER_VAL = 46,               /* POINTER_VAL  */
  YYSYMBOL_ARROW = 47,                     /* ARROW  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_REFERENCE = 49,                 /* REFERENCE  */
  YYSYMBOL_TERNARY = 50,                   /* TERNARY  */
  YYSYMBOL_ASSIGN_PLUS = 51,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 52,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_MULT = 53,               /* ASSIGN_MULT  */
  YYSYMBOL_ASSIGN_DIV = 54,                /* ASSIGN_DIV  */
  YYSYMBOL_ASSIGN_MOD = 55,                /* ASSIGN_MOD  */
  YYSYMBOL_ASSIGN = 56,                    /* ASSIGN  */
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
  YYSYMBOL_cmd = 76,                       /* cmd  */
  YYSYMBOL_cmd_decl_var = 77,              /* cmd_decl_var  */
  YYSYMBOL_assign_expr_maybe = 78,         /* assign_expr_maybe  */
  YYSYMBOL_all_decl_var = 79,              /* all_decl_var  */
  YYSYMBOL_decl_var_prim = 80,             /* decl_var_prim  */
  YYSYMBOL_const_decl_var = 81,            /* const_decl_var  */
  YYSYMBOL_hashtagzeromais = 82,           /* hashtagzeromais  */
  YYSYMBOL_cochetezeromais = 83,           /* cochetezeromais  */
  YYSYMBOL_assign_expr = 84,               /* assign_expr  */
  YYSYMBOL_assign_extra = 85,              /* assign_extra  */
  YYSYMBOL_inc = 86,                       /* inc  */
  YYSYMBOL_inOut = 87,                     /* inOut  */
  YYSYMBOL_in = 88,                        /* in  */
  YYSYMBOL_out = 89,                       /* out  */
  YYSYMBOL_cmd_loop = 90,                  /* cmd_loop  */
  YYSYMBOL_cmd_cond = 91,                  /* cmd_cond  */
  YYSYMBOL_cmd_switch = 92,                /* cmd_switch  */
  YYSYMBOL_for = 93,                       /* for  */
  YYSYMBOL_loop = 94,                      /* loop  */
  YYSYMBOL_if = 95,                        /* if  */
  YYSYMBOL_else = 96,                      /* else  */
  YYSYMBOL_switch = 97,                    /* switch  */
  YYSYMBOL_casezeromais = 98,              /* casezeromais  */
  YYSYMBOL_case = 99,                      /* case  */
  YYSYMBOL_type = 100,                     /* type  */
  YYSYMBOL_typename = 101,                 /* typename  */
  YYSYMBOL_primitivos = 102,               /* primitivos  */
  YYSYMBOL_typedlpar = 103,                /* typedlpar  */
  YYSYMBOL_typedlparAfter = 104,           /* typedlparAfter  */
  YYSYMBOL_parameter = 105,                /* parameter  */
  YYSYMBOL_parameterAfter = 106,           /* parameterAfter  */
  YYSYMBOL_block = 107,                    /* block  */
  YYSYMBOL_expr = 108,                     /* expr  */
  YYSYMBOL_expr_tern = 109,                /* expr_tern  */
  YYSYMBOL_identifier = 110,               /* identifier  */
  YYSYMBOL_arrayAccess = 111,              /* arrayAccess  */
  YYSYMBOL_lpar = 112,                     /* lpar  */
  YYSYMBOL_lparAfter = 113,                /* lparAfter  */
  YYSYMBOL_pointerAccess = 114,            /* pointerAccess  */
  YYSYMBOL_literal = 115                   /* literal  */
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
       0,   135,   135,   138,   139,   141,   142,   144,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     159,   163,   164,   166,   168,   171,   174,   178,   179,   182,
     183,   185,   186,   187,   189,   190,   191,   192,   193,   195,
     196,   198,   199,   200,   201,   203,   204,   206,   208,   210,
     213,   215,   217,   218,   220,   222,   223,   225,   227,   228,
     229,   231,   232,   233,   234,   235,   236,   238,   239,   241,
     242,   244,   246,   247,   249,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   273,   277,   280,   281,
     282,   285,   286,   289,   290,   292,   293,   295,   296,   298,
     299,   300,   301,   302
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
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "ID", "SEMICOLON",
  "QUESTION_MARK", "COLON", "DOT", "POINTER_VAL", "ARROW", "COMMA",
  "REFERENCE", "TERNARY", "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULT",
  "ASSIGN_DIV", "ASSIGN_MOD", "ASSIGN", "'@'", "LEFT_PAREN", "RIGHT_PAREN",
  "INCREMENT", "DECREMENT", "NOT", "OR", "AND", "EQUALS", "DIFF", "LT",
  "GT", "LEQ", "GEQ", "$accept", "prog", "stmts", "stmt", "decl_fun",
  "cmd", "cmd_decl_var", "assign_expr_maybe", "all_decl_var",
  "decl_var_prim", "const_decl_var", "hashtagzeromais", "cochetezeromais",
  "assign_expr", "assign_extra", "inc", "inOut", "in", "out", "cmd_loop",
  "cmd_cond", "cmd_switch", "for", "loop", "if", "else", "switch",
  "casezeromais", "case", "type", "typename", "primitivos", "typedlpar",
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
static const yytype_uint8 yydefgoto[] =
{
       0,    32,    33,    34,    35,    36,    37,    96,    38,    39,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
#line 135 "./src/parser.y"
             {
}
#line 1506 "./out/y.tab.cpp"
    break;

  case 3: /* stmts: %empty  */
#line 138 "./src/parser.y"
                      {}
#line 1512 "./out/y.tab.cpp"
    break;

  case 4: /* stmts: stmt stmts  */
#line 139 "./src/parser.y"
                   {}
#line 1518 "./out/y.tab.cpp"
    break;

  case 5: /* stmt: decl_fun  */
#line 141 "./src/parser.y"
                {}
#line 1524 "./out/y.tab.cpp"
    break;

  case 6: /* stmt: cmd  */
#line 142 "./src/parser.y"
           {}
#line 1530 "./out/y.tab.cpp"
    break;

  case 7: /* decl_fun: FUNCTION type ID LEFT_PAREN typedlpar RIGHT_PAREN block  */
#line 144 "./src/parser.y"
                                                                   {}
#line 1536 "./out/y.tab.cpp"
    break;

  case 8: /* cmd: identifier assign_expr SEMICOLON  */
#line 146 "./src/parser.y"
                                       {(yyval.cmdRetorno) = new cmd((yyvsp[-2].identifierRetorno),(yyvsp[-1].assign_exprRetorno));}
#line 1542 "./out/y.tab.cpp"
    break;

  case 9: /* cmd: cmd_decl_var SEMICOLON  */
#line 147 "./src/parser.y"
                               {(yyval.cmdRetorno) = new cmd((yyvsp[-1].cmd_decl_varRetorno));}
#line 1548 "./out/y.tab.cpp"
    break;

  case 10: /* cmd: inOut SEMICOLON  */
#line 148 "./src/parser.y"
                        {}
#line 1554 "./out/y.tab.cpp"
    break;

  case 11: /* cmd: cmd_loop  */
#line 149 "./src/parser.y"
                 {}
#line 1560 "./out/y.tab.cpp"
    break;

  case 12: /* cmd: cmd_cond  */
#line 150 "./src/parser.y"
                 {}
#line 1566 "./out/y.tab.cpp"
    break;

  case 13: /* cmd: cmd_switch  */
#line 151 "./src/parser.y"
                   {}
#line 1572 "./out/y.tab.cpp"
    break;

  case 14: /* cmd: expr SEMICOLON  */
#line 152 "./src/parser.y"
                       {}
#line 1578 "./out/y.tab.cpp"
    break;

  case 15: /* cmd: RETURN expr SEMICOLON  */
#line 153 "./src/parser.y"
                              {}
#line 1584 "./out/y.tab.cpp"
    break;

  case 16: /* cmd: BREAK SEMICOLON  */
#line 154 "./src/parser.y"
                        {}
#line 1590 "./out/y.tab.cpp"
    break;

  case 17: /* cmd: CONTINUE SEMICOLON  */
#line 155 "./src/parser.y"
                           {}
#line 1596 "./out/y.tab.cpp"
    break;

  case 18: /* cmd: EXIT WHEN expr SEMICOLON  */
#line 156 "./src/parser.y"
                                 {}
#line 1602 "./out/y.tab.cpp"
    break;

  case 19: /* cmd: block  */
#line 157 "./src/parser.y"
              {}
#line 1608 "./out/y.tab.cpp"
    break;

  case 20: /* cmd_decl_var: all_decl_var assign_expr_maybe  */
#line 159 "./src/parser.y"
                                              {
      (yyval.cmd_decl_varRetorno) = new cmd_decl_var((yyvsp[-1].all_decl_varRetorno),(yyvsp[0].assign_expr_maybeRetorno));
}
#line 1616 "./out/y.tab.cpp"
    break;

  case 21: /* assign_expr_maybe: %empty  */
#line 163 "./src/parser.y"
                                {(yyval.assign_expr_maybeRetorno) = NULL;}
#line 1622 "./out/y.tab.cpp"
    break;

  case 22: /* assign_expr_maybe: assign_expr  */
#line 164 "./src/parser.y"
                    {(yyval.assign_expr_maybeRetorno) = new assign_expr_maybe();}
#line 1628 "./out/y.tab.cpp"
    break;

  case 23: /* all_decl_var: decl_var_prim  */
#line 166 "./src/parser.y"
                             {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].decl_var_primRetorno),symtable);
                              print_symtable(symtable);}
#line 1635 "./out/y.tab.cpp"
    break;

  case 24: /* all_decl_var: const_decl_var  */
#line 168 "./src/parser.y"
                              {(yyval.all_decl_varRetorno) = new all_decl_var((yyvsp[0].const_decl_varRetorno),symtable);
                              print_symtable(symtable);}
#line 1642 "./out/y.tab.cpp"
    break;

  case 25: /* decl_var_prim: primitivos hashtagzeromais cochetezeromais ID  */
#line 171 "./src/parser.y"
                                                              {
      (yyval.decl_var_primRetorno) = new decl_var_prim((yyvsp[-3].primitivosRetorno),(yyvsp[-2].hashtagzeromaisRetorno),(yyvsp[-1].cochetezeromaisRetorno),yytext);
}
#line 1650 "./out/y.tab.cpp"
    break;

  case 26: /* const_decl_var: CONST decl_var_prim  */
#line 174 "./src/parser.y"
                                     {
      (yyval.const_decl_varRetorno) = new const_decl_var((yyvsp[0].decl_var_primRetorno));
}
#line 1658 "./out/y.tab.cpp"
    break;

  case 27: /* hashtagzeromais: %empty  */
#line 178 "./src/parser.y"
                              {(yyval.hashtagzeromaisRetorno) = NULL;}
#line 1664 "./out/y.tab.cpp"
    break;

  case 28: /* hashtagzeromais: POINTER_VAL hashtagzeromais  */
#line 179 "./src/parser.y"
                                    {(yyval.hashtagzeromaisRetorno) = new hashtagzeromais((yyvsp[0].hashtagzeromaisRetorno));}
#line 1670 "./out/y.tab.cpp"
    break;

  case 29: /* cochetezeromais: %empty  */
#line 182 "./src/parser.y"
                              {(yyval.cochetezeromaisRetorno) = NULL;}
#line 1676 "./out/y.tab.cpp"
    break;

  case 30: /* cochetezeromais: LEFT_BRACKET expr RIGHT_BRACKET cochetezeromais  */
#line 183 "./src/parser.y"
                                                        {(yyval.cochetezeromaisRetorno) = new cochetezeromais((yyvsp[0].cochetezeromaisRetorno));}
#line 1682 "./out/y.tab.cpp"
    break;

  case 31: /* assign_expr: ASSIGN expr  */
#line 185 "./src/parser.y"
                          {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1688 "./out/y.tab.cpp"
    break;

  case 32: /* assign_expr: assign_extra expr  */
#line 186 "./src/parser.y"
                                {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1694 "./out/y.tab.cpp"
    break;

  case 33: /* assign_expr: inc  */
#line 187 "./src/parser.y"
                  {(yyval.assign_exprRetorno) = new assign_expr();}
#line 1700 "./out/y.tab.cpp"
    break;

  case 34: /* assign_extra: ASSIGN_PLUS  */
#line 189 "./src/parser.y"
                           {}
#line 1706 "./out/y.tab.cpp"
    break;

  case 35: /* assign_extra: ASSIGN_MINUS  */
#line 190 "./src/parser.y"
                     {}
#line 1712 "./out/y.tab.cpp"
    break;

  case 36: /* assign_extra: ASSIGN_MULT  */
#line 191 "./src/parser.y"
                    {}
#line 1718 "./out/y.tab.cpp"
    break;

  case 37: /* assign_extra: ASSIGN_DIV  */
#line 192 "./src/parser.y"
                   {}
#line 1724 "./out/y.tab.cpp"
    break;

  case 38: /* assign_extra: ASSIGN_MOD  */
#line 193 "./src/parser.y"
                   {}
#line 1730 "./out/y.tab.cpp"
    break;

  case 39: /* inc: DECREMENT  */
#line 195 "./src/parser.y"
                {}
#line 1736 "./out/y.tab.cpp"
    break;

  case 40: /* inc: INCREMENT  */
#line 196 "./src/parser.y"
                  {}
#line 1742 "./out/y.tab.cpp"
    break;

  case 41: /* inOut: in  */
#line 198 "./src/parser.y"
           {}
#line 1748 "./out/y.tab.cpp"
    break;

  case 42: /* inOut: out  */
#line 199 "./src/parser.y"
            {}
#line 1754 "./out/y.tab.cpp"
    break;

  case 43: /* in: READ LEFT_PAREN ID RIGHT_PAREN  */
#line 200 "./src/parser.y"
                                    {}
#line 1760 "./out/y.tab.cpp"
    break;

  case 44: /* out: WRITE LEFT_PAREN ID RIGHT_PAREN  */
#line 201 "./src/parser.y"
                                      {}
#line 1766 "./out/y.tab.cpp"
    break;

  case 45: /* cmd_loop: for  */
#line 203 "./src/parser.y"
               {}
#line 1772 "./out/y.tab.cpp"
    break;

  case 46: /* cmd_loop: loop  */
#line 204 "./src/parser.y"
             {}
#line 1778 "./out/y.tab.cpp"
    break;

  case 47: /* cmd_cond: if  */
#line 206 "./src/parser.y"
              {}
#line 1784 "./out/y.tab.cpp"
    break;

  case 48: /* cmd_switch: switch  */
#line 208 "./src/parser.y"
                    {}
#line 1790 "./out/y.tab.cpp"
    break;

  case 49: /* for: FOR LEFT_PAREN expr SEMICOLON expr SEMICOLON expr RIGHT_PAREN cmd  */
#line 210 "./src/parser.y"
                                                                        {}
#line 1796 "./out/y.tab.cpp"
    break;

  case 50: /* loop: LOOP cmd  */
#line 213 "./src/parser.y"
                {}
#line 1802 "./out/y.tab.cpp"
    break;

  case 51: /* if: IF LEFT_PAREN expr RIGHT_PAREN cmd ENDIF else  */
#line 215 "./src/parser.y"
                                                   {}
#line 1808 "./out/y.tab.cpp"
    break;

  case 52: /* else: %empty  */
#line 217 "./src/parser.y"
                    {}
#line 1814 "./out/y.tab.cpp"
    break;

  case 53: /* else: ELSE cmd  */
#line 218 "./src/parser.y"
                 {}
#line 1820 "./out/y.tab.cpp"
    break;

  case 54: /* switch: SWITCH LEFT_PAREN expr RIGHT_PAREN LEFT_BRACE casezeromais RIGHT_BRACE  */
#line 220 "./src/parser.y"
                                                                                {}
#line 1826 "./out/y.tab.cpp"
    break;

  case 55: /* casezeromais: %empty  */
#line 222 "./src/parser.y"
                           {}
#line 1832 "./out/y.tab.cpp"
    break;

  case 56: /* casezeromais: case casezeromais  */
#line 223 "./src/parser.y"
                          {}
#line 1838 "./out/y.tab.cpp"
    break;

  case 57: /* case: CASE literal COLON stmts  */
#line 225 "./src/parser.y"
                                {}
#line 1844 "./out/y.tab.cpp"
    break;

  case 58: /* type: typename  */
#line 227 "./src/parser.y"
                {}
#line 1850 "./out/y.tab.cpp"
    break;

  case 59: /* typename: primitivos  */
#line 228 "./src/parser.y"
                      {}
#line 1856 "./out/y.tab.cpp"
    break;

  case 60: /* typename: ID  */
#line 229 "./src/parser.y"
              {}
#line 1862 "./out/y.tab.cpp"
    break;

  case 61: /* primitivos: INT  */
#line 231 "./src/parser.y"
                 {(yyval.primitivosRetorno) = new primitivos("INT");}
#line 1868 "./out/y.tab.cpp"
    break;

  case 62: /* primitivos: REAL  */
#line 232 "./src/parser.y"
                  {(yyval.primitivosRetorno) = new primitivos("REAL");}
#line 1874 "./out/y.tab.cpp"
    break;

  case 63: /* primitivos: CHAR  */
#line 233 "./src/parser.y"
                  {(yyval.primitivosRetorno) = new primitivos("CHAR");}
#line 1880 "./out/y.tab.cpp"
    break;

  case 64: /* primitivos: BOOL  */
#line 234 "./src/parser.y"
                  {(yyval.primitivosRetorno) = new primitivos("BOOL");}
#line 1886 "./out/y.tab.cpp"
    break;

  case 65: /* primitivos: STR  */
#line 235 "./src/parser.y"
                 {(yyval.primitivosRetorno) = new primitivos("STRING");}
#line 1892 "./out/y.tab.cpp"
    break;

  case 66: /* primitivos: VOID  */
#line 236 "./src/parser.y"
                  {(yyval.primitivosRetorno) = new primitivos("VOID");}
#line 1898 "./out/y.tab.cpp"
    break;

  case 67: /* typedlpar: %empty  */
#line 238 "./src/parser.y"
                        {}
#line 1904 "./out/y.tab.cpp"
    break;

  case 68: /* typedlpar: parameter typedlparAfter  */
#line 239 "./src/parser.y"
                                 {}
#line 1910 "./out/y.tab.cpp"
    break;

  case 69: /* typedlparAfter: %empty  */
#line 241 "./src/parser.y"
                             {}
#line 1916 "./out/y.tab.cpp"
    break;

  case 70: /* typedlparAfter: COMMA parameter typedlparAfter  */
#line 242 "./src/parser.y"
                                       {}
#line 1922 "./out/y.tab.cpp"
    break;

  case 71: /* parameter: type parameterAfter  */
#line 244 "./src/parser.y"
                                {}
#line 1928 "./out/y.tab.cpp"
    break;

  case 72: /* parameterAfter: ID  */
#line 246 "./src/parser.y"
                    {}
#line 1934 "./out/y.tab.cpp"
    break;

  case 73: /* parameterAfter: REFERENCE ID  */
#line 247 "./src/parser.y"
                     {}
#line 1940 "./out/y.tab.cpp"
    break;

  case 74: /* block: LEFT_BRACE stmts RIGHT_BRACE  */
#line 249 "./src/parser.y"
                                     {}
#line 1946 "./out/y.tab.cpp"
    break;

  case 75: /* expr: INCREMENT expr  */
#line 251 "./src/parser.y"
                      {}
#line 1952 "./out/y.tab.cpp"
    break;

  case 76: /* expr: DECREMENT expr  */
#line 252 "./src/parser.y"
                      {}
#line 1958 "./out/y.tab.cpp"
    break;

  case 77: /* expr: LEFT_PAREN expr RIGHT_PAREN  */
#line 253 "./src/parser.y"
                                   {}
#line 1964 "./out/y.tab.cpp"
    break;

  case 78: /* expr: MINUS identifier  */
#line 254 "./src/parser.y"
                        {}
#line 1970 "./out/y.tab.cpp"
    break;

  case 79: /* expr: NOT expr  */
#line 255 "./src/parser.y"
                {}
#line 1976 "./out/y.tab.cpp"
    break;

  case 80: /* expr: expr AND expr  */
#line 256 "./src/parser.y"
                     {}
#line 1982 "./out/y.tab.cpp"
    break;

  case 81: /* expr: expr OR expr  */
#line 257 "./src/parser.y"
                    {}
#line 1988 "./out/y.tab.cpp"
    break;

  case 82: /* expr: expr PLUS expr  */
#line 258 "./src/parser.y"
                      {}
#line 1994 "./out/y.tab.cpp"
    break;

  case 83: /* expr: expr TIMES expr  */
#line 259 "./src/parser.y"
                       {}
#line 2000 "./out/y.tab.cpp"
    break;

  case 84: /* expr: expr DIV expr  */
#line 260 "./src/parser.y"
                     {}
#line 2006 "./out/y.tab.cpp"
    break;

  case 85: /* expr: expr MINUS expr  */
#line 261 "./src/parser.y"
                       {}
#line 2012 "./out/y.tab.cpp"
    break;

  case 86: /* expr: expr MOD expr  */
#line 262 "./src/parser.y"
                     {}
#line 2018 "./out/y.tab.cpp"
    break;

  case 87: /* expr: expr EQUALS expr  */
#line 263 "./src/parser.y"
                        {}
#line 2024 "./out/y.tab.cpp"
    break;

  case 88: /* expr: expr DIFF expr  */
#line 264 "./src/parser.y"
                      {}
#line 2030 "./out/y.tab.cpp"
    break;

  case 89: /* expr: expr LT expr  */
#line 265 "./src/parser.y"
                    {}
#line 2036 "./out/y.tab.cpp"
    break;

  case 90: /* expr: expr GT expr  */
#line 266 "./src/parser.y"
                    {}
#line 2042 "./out/y.tab.cpp"
    break;

  case 91: /* expr: expr LEQ expr  */
#line 267 "./src/parser.y"
                     {}
#line 2048 "./out/y.tab.cpp"
    break;

  case 92: /* expr: expr GEQ expr  */
#line 268 "./src/parser.y"
                     {}
#line 2054 "./out/y.tab.cpp"
    break;

  case 93: /* expr: expr_tern  */
#line 269 "./src/parser.y"
                 {}
#line 2060 "./out/y.tab.cpp"
    break;

  case 94: /* expr: literal  */
#line 270 "./src/parser.y"
               {}
#line 2066 "./out/y.tab.cpp"
    break;

  case 95: /* expr: identifier  */
#line 271 "./src/parser.y"
                  {}
#line 2072 "./out/y.tab.cpp"
    break;

  case 96: /* expr_tern: TERNARY expr QUESTION_MARK expr COLON expr TERNARY  */
#line 273 "./src/parser.y"
                                                               {}
#line 2078 "./out/y.tab.cpp"
    break;

  case 97: /* identifier: ID  */
#line 277 "./src/parser.y"
                {
            (yyval.identifierRetorno) = new identifier(yytext);
      }
#line 2086 "./out/y.tab.cpp"
    break;

  case 98: /* identifier: ID arrayAccess  */
#line 280 "./src/parser.y"
                           {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2092 "./out/y.tab.cpp"
    break;

  case 99: /* identifier: ID LEFT_PAREN lpar RIGHT_PAREN  */
#line 281 "./src/parser.y"
                                           {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2098 "./out/y.tab.cpp"
    break;

  case 100: /* identifier: ID pointerAccess  */
#line 282 "./src/parser.y"
                             {(yyval.identifierRetorno) = new identifier(yytext);}
#line 2104 "./out/y.tab.cpp"
    break;

  case 101: /* arrayAccess: LEFT_BRACKET expr RIGHT_BRACKET  */
#line 285 "./src/parser.y"
                                              {}
#line 2110 "./out/y.tab.cpp"
    break;

  case 102: /* arrayAccess: LEFT_BRACKET expr RIGHT_BRACKET arrayAccess  */
#line 286 "./src/parser.y"
                                                             {}
#line 2116 "./out/y.tab.cpp"
    break;

  case 103: /* lpar: %empty  */
#line 289 "./src/parser.y"
                   { }
#line 2122 "./out/y.tab.cpp"
    break;

  case 104: /* lpar: expr lparAfter  */
#line 290 "./src/parser.y"
                      {}
#line 2128 "./out/y.tab.cpp"
    break;

  case 105: /* lparAfter: %empty  */
#line 292 "./src/parser.y"
                         {}
#line 2134 "./out/y.tab.cpp"
    break;

  case 106: /* lparAfter: COMMA expr lparAfter  */
#line 293 "./src/parser.y"
                             {}
#line 2140 "./out/y.tab.cpp"
    break;

  case 107: /* pointerAccess: ARROW ID  */
#line 295 "./src/parser.y"
                         {}
#line 2146 "./out/y.tab.cpp"
    break;

  case 108: /* pointerAccess: ARROW ID pointerAccess  */
#line 296 "./src/parser.y"
                                        {}
#line 2152 "./out/y.tab.cpp"
    break;

  case 109: /* literal: NUMBER  */
#line 298 "./src/parser.y"
                 {(yyval.literalRetorno) = new literal("NUMBER",yytext);}
#line 2158 "./out/y.tab.cpp"
    break;

  case 110: /* literal: CHARACTER  */
#line 299 "./src/parser.y"
                  {(yyval.literalRetorno) = new literal("CHAR",yytext);}
#line 2164 "./out/y.tab.cpp"
    break;

  case 111: /* literal: TRUE  */
#line 300 "./src/parser.y"
             {(yyval.literalRetorno) = new literal("BOOL",yytext);}
#line 2170 "./out/y.tab.cpp"
    break;

  case 112: /* literal: FALSE  */
#line 301 "./src/parser.y"
              {(yyval.literalRetorno) = new literal("BOOL",yytext);}
#line 2176 "./out/y.tab.cpp"
    break;

  case 113: /* literal: STRING  */
#line 302 "./src/parser.y"
               {(yyval.literalRetorno) = new literal("STRING",yytext);}
#line 2182 "./out/y.tab.cpp"
    break;


#line 2186 "./out/y.tab.cpp"

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

#line 304 "./src/parser.y"
 /* Fim da segunda seção */

int main (void) {
      /* root = initialize(); */

      return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
