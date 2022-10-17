/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    LEFT_PAREN = 291,
    RIGHT_PAREN = 292,
    LEFT_BRACE = 293,
    RIGHT_BRACE = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    ID = 297,
    SEMICOLON = 298,
    QUESTION_MARK = 299,
    COLON = 300,
    DOT = 301,
    POINTER_VAL = 302,
    ARROW = 303,
    COMMA = 304,
    REFERENCE = 305,
    TERNARY = 306,
    ASSIGN_PLUS = 307,
    ASSIGN_MINUS = 308,
    ASSIGN_MULT = 309,
    ASSIGN_DIV = 310,
    ASSIGN_MOD = 311,
    ASSIGN = 312,
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
#define LEFT_PAREN 291
#define RIGHT_PAREN 292
#define LEFT_BRACE 293
#define RIGHT_BRACE 294
#define LEFT_BRACKET 295
#define RIGHT_BRACKET 296
#define ID 297
#define SEMICOLON 298
#define QUESTION_MARK 299
#define COLON 300
#define DOT 301
#define POINTER_VAL 302
#define ARROW 303
#define COMMA 304
#define REFERENCE 305
#define TERNARY 306
#define ASSIGN_PLUS 307
#define ASSIGN_MINUS 308
#define ASSIGN_MULT 309
#define ASSIGN_DIV 310
#define ASSIGN_MOD 311
#define ASSIGN 312
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
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */