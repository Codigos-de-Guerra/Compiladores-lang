# Folders
OUT = ./out
GRAMMAR = ./grammar
EXAM = ./examples
SRC = ./src
INC = ./include

# Defines
#CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts
CXXFLAGS = -std=c++17 -Wno-write-strings
INCLUDES = -I$(SRC) -I$(OUT) -I$(INC)
CXX = g++

# Vars
TOKENIZER = tokenizer.l
PARSER = parser.y
LEX_OUT = $(OUT)/lex.yy.cpp
YACC_OUT = $(OUT)/y.tab.cpp
OBJS = $(OUT)/symbol.o 
CMM = $(OUT)/c--

.PHONY: all
all: compile

lex:
	mkdir -p $(OUT)
	lex -o $(LEX_OUT) $(TOKENIZER)

yacc: lex
	bison -d -v $(PARSER) -o $(YACC_OUT)

compile: yacc #$(OUT)/symbol.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LEX_OUT) $(YACC_OUT) -o $(CMM)

#$(OUT)/new_rules.o: $(INC)/new_rules.hpp $(SRC)/new_rules.cpp | $(OUT)
#	$(CXX) -c -o $(OUT)/new_rules.o $(SRC)/new_rules.cpp $(INCLUDES) $(CXXFLAGS)

#$(OUT)/symbol.o: $(INC)/symbol.hpp $(SRC)/symbol.cpp | $(OUT)
#	$(CXX) -c -o $(OUT)/symbol.o $(SRC)/symbol.cpp $(INCLUDES) $(CXXFLAGS)

test:
	$(CMM) < $(EXAM)/t1.cmm

clean:
	rm -rf $(OUT)
