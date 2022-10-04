# Compiladores-lang
Creation of a C-based language compiler

## How to compile

Inside repo base folder, run:
```
make
```

The lexer will be compiled and our syntactic analysers, one iterative and another recursive, will be generated.

## How to run

Executables for iterative and recursive will be generated in base folder.
Just run one of them passing a desirable input file to test.

Example:
```
# Running iterative syntactic analyser with a mergesort as input
./iter < examples/mergesort

# Running recursive syntactic analyser with a quicksort as input
./recur < examples/quicksort
```
