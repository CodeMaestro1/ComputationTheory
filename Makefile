CC      := gcc
CFLAGS  := -Wall
LEX     := flex
RM      := @rm -f

EXEC    := analyzer
SRC     := analyzer.l
LEXOUT  := lex.yy.c
TEST_IN := test_input.txt

.PHONY: all clean test

# Default target
all: $(EXEC)

# Compile analyzer
$(EXEC): $(LEXOUT)
	$(CC) $(CFLAGS) -o $@ $< -lfl
	@echo "Analyzer compiled successfully."
	@echo "Run './$(EXEC) < input_file>' to analyze your input."
	@echo "-------------------------------"
	@echo "To clean up generated files, run 'make clean'."
	@echo "To test the analyzer, run 'make test'."
	@echo "-------------------------------"

# Generate C code from the flex source
$(LEXOUT): $(SRC)
	$(LEX) $<

# Remove generated files
clean:
	$(RM) $(EXEC) $(LEXOUT) $(TEST_IN)

# Create test input and run analyzer
test: $(EXEC)
	@echo "def main()"              >  $(TEST_IN)
	@echo "   x := 123"            >> $(TEST_IN)
	@echo "   y := 3.14"           >> $(TEST_IN)
	@echo "   z := \"Hello, world!\"" >> $(TEST_IN)
	@echo "   if x > 100"          >> $(TEST_IN)
	@echo "       return True"     >> $(TEST_IN)
	@echo "   endif"               >> $(TEST_IN)
	@echo "enddef"                 >> $(TEST_IN)
	@echo "Running analyzer on test input:"
	@echo "-------------------------------"
	./$(EXEC) < $(TEST_IN)
