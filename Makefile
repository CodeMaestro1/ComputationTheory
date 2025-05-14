# Makefile for Lambda-to-C compiler

CC = gcc
FLEX = flex
BISON = bison
LEX_SRC = analyzer.l
YACC_SRC = parser.y
GEN_C = cgen.c
OUT = analyzer

.PHONY: all clean

all: $(OUT)

parser.tab.c parser.tab.h: $(YACC_SRC)
	$(BISON) -d -v -r all $(YACC_SRC)

lex.yy.c: $(LEX_SRC) parser.tab.h
	$(FLEX) $(LEX_SRC)

$(OUT): lex.yy.c parser.tab.c $(GEN_C)
	$(CC) -o $(OUT) lex.yy.c parser.tab.c $(GEN_C) -lfl

clean:
	rm -f $(OUT) lex.yy.c parser.tab.c parser.tab.h parser.output
