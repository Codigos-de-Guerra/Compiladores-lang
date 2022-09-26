#!/bin/sh

python3 scripts/clear_html.py > data/output_table.txt
python3 scripts/script.py > teste.cpp
rm data/output_table.txt
lex tokenizer.l
gcc teste.cpp -o teste
