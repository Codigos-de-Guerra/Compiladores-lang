#ifndef TIPOS
#define TIPOS

#include "classes.hpp"
typedef union{
    literal* literalRetorno;
  
	string* name;
} YYSTYPE;

extern YYSTYPE yylval;


#endif