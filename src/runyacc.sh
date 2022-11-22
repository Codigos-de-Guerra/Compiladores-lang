set -e
lex -o lex.yy.cpp tokenizer.l
yacc -d -v parserYacc.y -o y.tab.cpp
g++ -Wreturn-type lex.yy.cpp y.tab.cpp