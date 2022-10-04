# Defines
#CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts
CXXFLAGS = -std=c++17 #-g -Wall -Wshadow -Wno-unused-result -Wno-sign-compare
CCOMPILER = g++

# Folder
BIN = ./bin
GRAMMAR = ./grammar
EXAM = ./examples
SCRIPTS = ./scripts
SRC = ./src

# Vars
clear = $(SCRIPTS)/clear_html.py
table = output_table.txt
auto_generate_iter = $(SCRIPTS)/script.py
iter_anal = analisador_iter.cpp
auto_generate_recur = $(SCRIPTS)/script.py
recur_anal = analisador_recur.cpp
iter = iter
recur = recur


all: compile link

generate: treat
	python3.10 $(auto_generate_iter) > $(SRC)/$(iter_anal)
	python3.10 $(auto_generate_recur) > $(SRC)/$(recur_anal)

treat:
	mkdir -p $(SRC)
	python3.10 $(clear) > $(table)


compile: genLex
	mkdir -p $(BIN)
	$(CCOMPILER) $(SRC)/$(iter_anal) $(CXXFLAGS) -o $(BIN)/$(iter)
	$(CCOMPILER) $(SRC)/$(recur_anal) $(CXXFLAGS) -o $(BIN)/$(recur)

genLex:
	lex -o $(SRC)/lex.yy.c tokenizer.l

link:
	ln -sfv $(BIN)/$(iter) $(iter)
	ln -sfv $(BIN)/$(recur) $(recur)

clean:
	rm -f $(SRC)/lex.yy.c
	rm -f $(table)
	rm -f $(iter)
	rm -f $(recur)
	rm -rf $(BIN)
