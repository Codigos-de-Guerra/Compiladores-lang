#!/usr/bin/env python3

from re import match
from tokenize import group

filename = "data/output_table.txt"
rules_dict = dict()

non_terminals = []

token_names = {
    "if": "IF",
    "endif": "ENDIF",
    "else": "ELSE",
    "switch": "SWITCH",
    "case": "CASE",
    "for": "FOR",
    "loop": "LOOP",
    "function": "FUNCTION",
    "return": "RETURN",
    "receba": "RETURN",
    "struct": "STRUCT",
    "const": "CONST",
    "break": "BREAK",
    "continue": "CONTINUE",
    "read": "READ",
    "write": "WRITE",
    "exit": "EXIT",
    "when": "WHEN",
    "int": "INT",
    "real": "REAL",
    "char": "CHAR",
    "string": "STRING",
    "bool": "BOOL",
    "void": "VOID",
    "+": "PLUS",
    "-": "MINUS",
    "*": "TIMES",
    "/": "DIV",
    "%": "MOD",
    "=": "ASSIGN",
    "+=": "ASSIGN_PLUS",
    "-=": "ASSIGN_MINUS",
    "*=": "ASSIGN_MULT",
    "/=": "ASSIGN_DIV",
    "%=": "ASSIGN_MOD",
    "==": "EQUALS",
    "!=": "DIFF",
    "<": "LT",
    ">": "GT",
    "<=": "LEQ",
    ">=": "GEQ",
    "or": "OR",
    "||": "OR",
    "and": "AND",
    "&&": "AND",
    "not": "NOT",
    "!": "NOT",
    "true": "TRUE",
    "pdc": "TRUE",
    "false": "FALSE",
    "sqn": "FALSE",
    "NUMBER": "NUMBER",
    "CHARACTER": "CHARACTER",
    "STRING": "STRING",
    "(": "LEFT_PAREN",
    ")": "RIGHT_PAREN",
    "{": "LEFT_BRACE",
    "}": "RIGHT_BRACE",
    "[": "LEFT_BRACKET",
    "]": "RIGHT_BRACKET",
    "id": "ID",
    ";": "SEMICOLON",
    "?": "QUESTION_MARK",
    ":": "COLON",
    ".": "DOT",
    "#": "POINTER_VAL",
    "->": "ARROW",
    ",": "COMMA",
    "++": "INCREMENT",
    "--": "DECREMENT",
    "&": "REFERENCE",
    "$": "TERNARY",
    "digit": "DIGIT",
}


def trata(line):
    ans = match("(.*) => .* ::= (.*)\n", line)
    nomeToken = ans.group(1)
    stripa = ans.group(2).split(" ")
    return (nomeToken, stripa)


def fun(string):
    return "T_" + string.upper()


def printa(regra):
    token = regra[0]
    if regra[0][-1] == " ":
        token = regra[0][:-1]
        if token[0] == '"':
            token = token[1:]
        if token[-1] == '"':
            token = token[:-1]
    if token == "$":
        return
    if token in token_names.keys():
        token = token_names[token]

    # return
    # print(type(token))
    if token != "Îµ" and token != "Â¬" and token != "//":
        print("    case " + token + ":")
        for string in regra[1]:
            if match('([a-zA-Z_0-9"])+', string):
                if string.isupper():
                    if string in token_names.keys():
                        string = token_names[string]
                    print("      EAT(" + string + ");")
                else:
                    if string in non_terminals:
                        print("      " + fun(string) + "();")
            #else:
                #print("      error2();")
        print("      break;")


print(
    """
#include <iostream>
#include "lex.yy.c"

int tok;
void advance() {
  tok = yylex();
}
void error() {
  1/0;
}
void error2(){
    printf("erro2");
}
void EAT(tokens t) {
  if (tok == t) advance();
  else error();
}
"""
)


with open(filename) as f:
    follow_lst = list()
    function_name = ""
    for line in f.readlines():
        result = match("\d+ ([a-zA-Z_]*)\n", line)
        if result:
            function_name = result.group(1)
            rules_dict[function_name] = list()
        elif line[0] == "=" or line[0] == "#":
            continue
        else:
            rules_dict[function_name].append(trata(line))


for x in rules_dict.items():
    non_terminals.append(x[0])
    print("void " + fun(x[0]) + "(void);")

for x in rules_dict.items():
    print("void " + fun(x[0]) + "(void){")
    print("printf(\"fun("+x[0]+")\\n\");")
    #print("printf(\"%d\",tok);")
    #print("printf(\"\\n\");")
    print("  switch(tok){")
    for regra in x[1]:
        printa(regra)
    print("    default: error();")
    print("  }\n}\n")


print('''int main(){
    advance();
    T_S();
}

''')
