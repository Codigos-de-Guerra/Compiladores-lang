/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OUT_Y_TAB_HPP_INCLUDED
# define YY_YY_OUT_Y_TAB_HPP_INCLUDED
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
    IF = 258,                      /* IF  */
    ENDIF = 259,                   /* ENDIF  */
    ELSE = 260,                    /* ELSE  */
    SWITCH = 261,                  /* SWITCH  */
    CASE = 262,                    /* CASE  */
    FOR = 263,                     /* FOR  */
    LOOP = 264,                    /* LOOP  */
    RETURN = 265,                  /* RETURN  */
    STRUCT = 266,                  /* STRUCT  */
    CONST = 267,                   /* CONST  */
    BREAK = 268,                   /* BREAK  */
    CONTINUE = 269,                /* CONTINUE  */
    READ = 270,                    /* READ  */
    WRITE = 271,                   /* WRITE  */
    EXIT = 272,                    /* EXIT  */
    WHEN = 273,                    /* WHEN  */
    FUNCTION = 274,                /* FUNCTION  */
    INT = 275,                     /* INT  */
    REAL = 276,                    /* REAL  */
    CHAR = 277,                    /* CHAR  */
    STR = 278,                     /* STR  */
    BOOL = 279,                    /* BOOL  */
    VOID = 280,                    /* VOID  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    TIMES = 283,                   /* TIMES  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    TRUE = 286,                    /* TRUE  */
    FALSE = 287,                   /* FALSE  */
    NUMBER = 288,                  /* NUMBER  */
    CHARACTER = 289,               /* CHARACTER  */
    STRING = 290,                  /* STRING  */
    LEFT_BRACE = 291,              /* LEFT_BRACE  */
    RIGHT_BRACE = 292,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 293,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 294,           /* RIGHT_BRACKET  */
    ID = 295,                      /* ID  */
    SEMICOLON = 296,               /* SEMICOLON  */
    QUESTION_MARK = 297,           /* QUESTION_MARK  */
    COLON = 298,                   /* COLON  */
    DOT = 299,                     /* DOT  */
    POINTER_VAL = 300,             /* POINTER_VAL  */
    ARROW = 301,                   /* ARROW  */
    COMMA = 302,                   /* COMMA  */
    REFERENCE = 303,               /* REFERENCE  */
    TERNARY = 304,                 /* TERNARY  */
    ASSIGN_PLUS = 305,             /* ASSIGN_PLUS  */
    ASSIGN_MINUS = 306,            /* ASSIGN_MINUS  */
    ASSIGN_MULT = 307,             /* ASSIGN_MULT  */
    ASSIGN_DIV = 308,              /* ASSIGN_DIV  */
    ASSIGN_MOD = 309,              /* ASSIGN_MOD  */
    ASSIGN = 310,                  /* ASSIGN  */
    LEFT_PAREN = 311,              /* LEFT_PAREN  */
    RIGHT_PAREN = 312,             /* RIGHT_PAREN  */
    INCREMENT = 313,               /* INCREMENT  */
    DECREMENT = 314,               /* DECREMENT  */
    NOT = 315,                     /* NOT  */
    OR = 316,                      /* OR  */
    AND = 317,                     /* AND  */
    EQUALS = 318,                  /* EQUALS  */
    DIFF = 319,                    /* DIFF  */
    LT = 320,                      /* LT  */
    GT = 321,                      /* GT  */
    LEQ = 322,                     /* LEQ  */
    GEQ = 323                      /* GEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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


#endif /* !YY_YY_OUT_Y_TAB_HPP_INCLUDED  */