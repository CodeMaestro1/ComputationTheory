%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "cgen.h"

  void yyerror(char const* pat, ...);
  int yylex(void);
  extern int yylineno;
  extern void add_macro(const char *name, const char *replacement);
  extern void free_macro_table(void);
%}

/* Union for semantic values */
%union {
    int    integerVal;
    float  floatVal;
    char  *stringVal;
}

/* Tokens (sync with analyzer.l) */

%token <stringVal> IDENTIFIER CONST_STRING
%token <integerVal> CONST_INT
%token <floatVal>  CONST_REAL
%token  KEYWORD_SCALAR
%token <stringVal> KEYWORD_STR
%token <stringVal> OP_COLON_ASSIGN

%token <integerVal> KEYWORD_INTEGER

%token KEYWORD_IF KEYWORD_ELSE KEYWORD_ENDIF
%token KEYWORD_WHILE KEYWORD_ENDWHILE
%token KEYWORD_FOR KEYWORD_IN KEYWORD_ENDFOR
%token KEYWORD_DEF KEYWORD_ENDDEF KEYWORD_MAIN KEYWORD_RETURN
%token KEYWORD_CONST
%token KEYWORD_COMP KEYWORD_ENDCOMP KEYWORD_OF
%token KEYWORD_BOOL BOOL_TRUE BOOL_FALSE


%token KEYWORD_BREAK KEYWORD_CONTINUE


%token OP_PLUS OP_MINUS OP_MULT OP_DIV OP_MOD OP_POWER
%token OP_EQ OP_NEQ OP_LT OP_LE OP_GT OP_GE
%token OP_AND OP_OR OP_NOT
%token OP_ASSIGN OP_PLUS_ASSIGN OP_MINUS_ASSIGN
%token OP_MULT_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN

%token SEMICOLON COLON COMMA DOT
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token LEFT_BRACKET RIGHT_BRACKET
%token ARROW

%start program

/* Operator precedence */
%left DOT
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS
%left LEFT_BRACKET RIGHT_BRACKET 
%right OP_POWER
%left OP_MULT OP_DIV OP_MOD
%left OP_PLUS OP_MINUS
%left OP_LT OP_LE OP_GT OP_GE
%left OP_EQ OP_NEQ
%right OP_NOT
%left OP_AND
%left OP_OR
%right OP_ASSIGN OP_PLUS_ASSIGN OP_MINUS_ASSIGN
%right OP_MULT_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN OP_COLON_ASSIGN


%%

/* Grammar rules begin here */
program
    : comp_decls const_decls var_decls func_decls main_func
        { printf("Parsed complete program\n"); }
    ;


//Main function
main_func
    : KEYWORD_DEF KEYWORD_MAIN LEFT_PARENTHESIS RIGHT_PARENTHESIS
      COLON stmts KEYWORD_ENDDEF SEMICOLON
    ;

//Type declarations
type_decls
    : /* empty */
    | type_decls type_basic_decl
    | type_decls complex_type_decls
    ;

type_basic_decl
    : KEYWORD_INTEGER
    | KEYWORD_SCALAR
    | KEYWORD_STR
    | KEYWORD_BOOL
    ;

//Complex type declarations
complex_type_decls
    : comp_decls
    | array_decls
    ;

comp_decls
    : /* empty */
    | comp_decls comp_decl
    ;

comp_decl
    : KEYWORD_COMP IDENTIFIER COLON member_decls method_decls KEYWORD_ENDCOMP SEMICOLON
    ;

array_decls
    : IDENTIFIER LEFT_BRACKET CONST_INT RIGHT_BRACKET COLON type SEMICOLON
        { printf("Array declaration with fixed size %d\n", $3); }
    | IDENTIFIER LEFT_BRACKET RIGHT_BRACKET COLON type SEMICOLON
        { printf("Array declaration with unspecified size\n"); }
    ;


//variable declarations
var_decls
    : /* empty */
    | var_decls var_decl
    ;

var_decl
    : id_list COLON type SEMICOLON
    ;

id_list
    : id_decl
    | id_list COMMA id_decl
    ;

id_decl
    : IDENTIFIER
    | IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
    | IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    ;


//function declarations
func_decls
    : /* empty */
    | func_decls func_decl
    ;

func_decl
    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS 
    return_type_decl
    COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
    ;

return_type_decl
    : /* empty */
    | ARROW return_type_opt
    ;

param
    : IDENTIFIER COLON type
    | IDENTIFIER LEFT_BRACKET RIGHT_BRACKET COLON type
    ;

param_list_opt
    : /* empty */
    | param_list
    ;

param_list
    : param
    | param_list COMMA param
    ;

local_decls
    : /* empty */
    | local_decls const_decl
    | local_decls var_decl
    ;

stmts
    : /* empty */
    | stmts stmt
    ;

stmt
    : IDENTIFIER OP_ASSIGN expr SEMICOLON
        { printf("Assignment statement\n"); }
    | IDENTIFIER OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON expr 
      RIGHT_BRACKET COLON type SEMICOLON
        { printf("Simple compact array construction\n"); }
    | IDENTIFIER OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type 
      KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON
        { printf("Compact array construction using another array\n"); }
    | KEYWORD_IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts else_part 
      KEYWORD_ENDIF SEMICOLON
        { printf("If statement with parentheses\n"); }
    | KEYWORD_WHILE expr COLON stmts KEYWORD_ENDWHILE SEMICOLON
        { printf("While loop\n"); }
    | KEYWORD_WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts 
      KEYWORD_ENDWHILE SEMICOLON
        { printf("While loop with parentheses\n"); }
    | KEYWORD_FOR IDENTIFIER KEYWORD_IN range_expr COLON stmts KEYWORD_ENDFOR SEMICOLON
        { printf("For loop with range\n"); }
    | KEYWORD_BREAK SEMICOLON
        { printf("Break statement\n"); }
    | KEYWORD_CONTINUE SEMICOLON
        { printf("Continue statement\n"); }
    | function_call SEMICOLON
        { printf("Function call statement\n"); }
    | SEMICOLON
        { printf("Blank statement\n"); }
    ;


member_decls
    : /* empty */
    | member_decls member_decl
    ;

member_decl
    : id_list COLON type SEMICOLON
    ;

method_decls
    : /* empty */
    | method_decls method_decl
    ;

method_decl
    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS
      return_type_opt COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
    ;


const_decls
    : /* empty */
    | const_decls const_decl
    ;

const_decl
    : KEYWORD_CONST IDENTIFIER COLON type OP_ASSIGN literal SEMICOLON
    ;

return_type_opt
    : /* empty */
    | type
    ;

return_opt
    : /* empty */
        { printf("No return statement\n"); }
    | KEYWORD_RETURN SEMICOLON
        { printf("Return statement with no value\n"); }
    | KEYWORD_RETURN expr SEMICOLON
        { printf("Return statement with value\n"); }
    ;

else_part
    : /* empty */
    | KEYWORD_ELSE COLON stmts
    ;

function_call
    : IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
    ;

arg_list_opt
    : /* empty */
    | arg_list
    ;

arg_list
    : expr
    | arg_list COMMA expr
    ;

expr
    : expr OP_PLUS expr
    | expr OP_MINUS expr
    | expr OP_MULT expr
    | expr OP_DIV expr
    | expr OP_MOD expr
    | expr OP_POWER expr
    | expr OP_EQ expr
    | expr OP_NEQ expr
    | expr OP_LT expr
    | expr OP_LE expr
    | expr OP_GT expr
    | expr OP_GE expr
    | expr OP_AND expr
    | expr OP_OR expr
    | OP_NOT expr
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
    | literal
    | IDENTIFIER
    | function_call
    ;

range_expr
    : LEFT_BRACKET expr COLON expr RIGHT_BRACKET
        { printf("Range with start:stop\n"); }
    | LEFT_BRACKET expr COLON expr COLON expr RIGHT_BRACKET
        { printf("Range with start:stop:step\n"); }
    ;

literal
    : CONST_INT
    | CONST_REAL
    | CONST_STRING
    | BOOL_TRUE
    | BOOL_FALSE
    ;

type
    : KEYWORD_INTEGER
        { printf("Type: integer\n"); }
    | KEYWORD_SCALAR
        { printf("Type: scalar\n"); }
    | KEYWORD_STR
        { printf("Type: string\n"); }
    | KEYWORD_BOOL
        { printf("Type: boolean\n"); }
    | KEYWORD_COMP
        { printf("Type: complex formula\n"); }
    | IDENTIFIER
        { printf("Type: user-defined type %s\n", $1); }
    | LEFT_BRACKET CONST_INT RIGHT_BRACKET COLON type
        { printf("Type: array of size %d\n", $2); }
    | LEFT_BRACKET RIGHT_BRACKET COLON type
        { printf("Type: array of unspecified size\n"); }
    ;

%%

int main() {
    if (yyparse() == 0) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }

    free_macro_table();

    return 0;
}