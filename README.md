# Lambda Programming Language Compiler

This project implements a compiler for the Lambda programming language, translating Lambda code into C99. The compiler is built using Flex (lexical analyzer) and Bison (parser generator).

## Project Structure

- `mylexer.l` - Flex lexical analyzer definition
- `myanalyzer.y` - Bison parser and code generator
- `cgen.c/h` - Code generation utilities
- `lambdalib.h` - Runtime library for Lambda programs
- `LambdaExamples/` - Example Lambda programs:
  - `bookstore.la` - Object-oriented bookstore management system
  - `prime.la` - Prime number generator
  - `qsort.la` - Quicksort implementation
  - `qsort_comprehension.la` - Quicksort using list comprehensions
  - `test_input.la` - Simple I/O example

## Features

- Object-oriented programming with `comp` (component) definitions
- List comprehensions
- Built-in types: integer, scalar (float), string, boolean
- Control structures: if-else, while, for
- Arrays and array operations
- Function definitions with return types
- Macro support with `@defmacro`
- Rich standard library for I/O operations

## Building

```bash
make
```

## Usage

```bash
./analyzer <input_file.la>
```

This will generate a Result.c containing the C99 code for the Lambda program.

Cleaning Up:

```bash
make clean
```

## Examples

Check the `LambdaExamples/` directory for example Lambda programs. You can run them by compiling the generated C code:

## Requirements

If you run the project on a Linux system, you need to have the following packages installed:

- `flex`
- `bison`

You can run the project on Windows using WSL (Windows Subsystem for Linux) but keep in mind that you have to install the required packages in WSL.

## License

This project is licensed under the [GNU General Public License v3.0 (GPL-3.0)](https://www.gnu.org/licenses/gpl-3.0.en.html). See the [LICENSE](./LICENSE) file for details.

This project was developed as part of the Computation Theory course at the Technical University of Crete.
