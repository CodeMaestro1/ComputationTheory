CC = gcc
FLEX = flex
BISON = bison
LEX_SRC = mylexer.l
YACC_SRC = myanalyzer.y
GEN_C = cgen.c
OUT = analyzer

.PHONY: all clean

all: $(OUT)

myanalyzer.tab.c myanalyzer.tab.h: $(YACC_SRC)
	$(BISON) -d -v -r all $(YACC_SRC)

lex.yy.c: $(LEX_SRC) myanalyzer.tab.h
	$(FLEX) $(LEX_SRC)

$(OUT): lex.yy.c myanalyzer.tab.c $(GEN_C)
	$(CC) -o $(OUT) lex.yy.c myanalyzer.tab.c $(GEN_C) -lfl

clean:
	rm -f $(OUT) lex.yy.c myanalyzer.tab.c myanalyzer.tab.h myanalyzer.output