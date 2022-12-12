# Folders
OUT = ./out
GRAMMAR = ./grammar
EXAM = ./examples
SRC = ./src

# Defines
#CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts
CXXFLAGS = -std=c++17 -Wno-write-strings
INCLUDES = -I$(SRC) -I$(OUT)
CXX = g++

# Vars
TOKENIZER = $(SRC)/tokenizer.l
LEX_OUT = $(OUT)/lex.yy.cpp
YACC_OUT = $(OUT)/y.tab.cpp
CMM = $(OUT)/c--

.PHONY: all
all: compile

lex:
	mkdir -p $(OUT)
	lex -o $(LEX_OUT) $(TOKENIZER)

yacc: lex
	yacc -d -v $(SRC)/parser.y -o $(YACC_OUT)

compile: yacc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LEX_OUT) $(YACC_OUT) -o $(CMM)

test:
	$(CMM) < $(EXAM)/t1.cmm 

clean:
	rm -rf $(OUT)
