#!/bin/sh

python3.10 scripts/clear_html.py > data/output_table.txt
python3.10 scripts/script.py > teste.cpp
rm data/output_table.txt
lex tokenizer.l
g++ teste.cpp -o teste
