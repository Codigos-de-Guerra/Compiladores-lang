set -e
lex -o lex.yy.c tokenizer.l
yacc -d -v parserYacc.y -o y.tab.c
cc lex.yy.c y.tab.c