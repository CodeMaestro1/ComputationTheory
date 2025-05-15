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

%define parse.error verbose

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

%token SEMICOLON COLON COMMA
%token ARROW
%token OP_HASH

%left DOT
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS
%left LEFT_BRACKET RIGHT_BRACKET
%right OP_POWER
%right UMINUS
%left OP_MULT OP_DIV OP_MOD
%left OP_PLUS OP_MINUS
%left OP_LT OP_LE
%left OP_GT OP_GE
%left OP_EQ OP_NEQ
%right OP_NOT
%left OP_AND
%left OP_OR
%right OP_ASSIGN 
%right OP_PLUS_ASSIGN OP_MINUS_ASSIGN OP_MULT_ASSIGN
%right OP_DIV_ASSIGN OP_MOD_ASSIGN OP_COLON_ASSIGN

%type <stringVal> id_decl
%type <stringVal> type
%type <stringVal> relational_expr
%type <stringVal> arithmetic_expr
%type <stringVal> logical_expr

%start program

%%

/* Grammar rules begin here */
program
    : comp_decls const_decls var_decls func_decls main_func
        { printf("Parsed complete program\n"); }
    ;


//Main function
main_func
    : KEYWORD_DEF KEYWORD_MAIN LEFT_PARENTHESIS RIGHT_PARENTHESIS
        COLON local_decls stmts KEYWORD_ENDDEF SEMICOLON
    ;

//Complex type declarations
comp_decls
    : /* empty */
    | comp_decls comp_decl
    ;

comp_decl
    : KEYWORD_COMP IDENTIFIER COLON member_decls method_decls KEYWORD_ENDCOMP SEMICOLON
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
        { 
            printf("Identifier %s\n", $1);
        }
    | IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { 
            printf("Array identifier %s\n", $1);
        }
    | IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
        { 
            printf("Array identifier %s with index\n", $1);
        }
    | OP_HASH IDENTIFIER
        {
            printf("Private identifier \n");
        }
    | OP_HASH IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        {
            printf("Private array identifier\n");
        }
    | OP_HASH IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
        {
            printf("Private array identifier with index\n");
        }
    
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
    : id_decl COLON type
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
    | local_decls var_decl
    | local_decls const_decl
    ;

stmts
    : /* empty */
    | stmt stmts 
    ;

stmt
    : simple_stmt
    | compound_stmt
    ;

simple_stmt
    : assignment_statement
        { printf("Assignment statement\n"); }
    | function_call SEMICOLON
        { printf("Function call statement\n"); }
    | KEYWORD_BREAK SEMICOLON
        { printf("Break statement\n"); }
    | KEYWORD_CONTINUE SEMICOLON
        { printf("Continue statement\n"); }
    | SEMICOLON
        { printf("Blank statement\n"); }
    ;

assignment_statement
    : lvalue OP_ASSIGN expr SEMICOLON
        { printf("Assignment statement with assignment operator\n"); }
    | lvalue OP_PLUS_ASSIGN expr SEMICOLON
        { printf("Assignment statement with plus assignment operator\n"); }
    | lvalue OP_MINUS_ASSIGN expr SEMICOLON
        { printf("Assignment statement with minus assignment operator\n"); }
    | lvalue OP_MULT_ASSIGN expr SEMICOLON
        { printf("Assignment statement with multiplication assignment operator\n"); }
    | lvalue OP_DIV_ASSIGN expr SEMICOLON
        { printf("Assignment statement with division assignment operator\n"); }
    | lvalue OP_MOD_ASSIGN expr SEMICOLON
        { printf("Assignment statement with modulo assignment operator\n"); }
    ;

lvalue
    : IDENTIFIER
    | IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
    | OP_HASH IDENTIFIER
    | OP_HASH IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
    ;

compound_stmt
    : KEYWORD_IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts else_part 
      KEYWORD_ENDIF SEMICOLON
        { printf("If statement with parentheses\n"); }
    | KEYWORD_WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts 
      KEYWORD_ENDWHILE SEMICOLON
        { printf("While loop with parentheses\n"); }
    | KEYWORD_FOR IDENTIFIER KEYWORD_IN range_expr COLON stmts KEYWORD_ENDFOR SEMICOLON
        { printf("For loop with range\n"); }
    | id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON expr 
      RIGHT_BRACKET COLON type SEMICOLON
        { printf("Simple compact array construction\n"); }
    | id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type 
      KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON
        { printf("Compact array construction using another array\n"); }
    ;


member_decls
    : /* empty */
    | member_decl_list
    ;

member_decl_list
    : member_decl
    | member_decl_list member_decl
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
    : KEYWORD_CONST IDENTIFIER OP_ASSIGN literal COLON type SEMICOLON
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
    : primary LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
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
    : logical_expr
    ;

logical_expr
    : relational_expr
        {$$ = $1;}
    | logical_expr OP_AND relational_expr
        {$$ = template("%s && %s",$1, $3);}
    | logical_expr OP_OR relational_expr
        {$$ = template("%s || %s",$1, $3);}
    ;

relational_expr
    : arithmetic_expr 
        {$$ = $1;}
    | relational_expr OP_LT arithmetic_expr
        {$$ = template("%s < %s",$1, $3);}
    | relational_expr OP_LE arithmetic_expr
        {$$ = template("%s <= %s",$1, $3);}
    | relational_expr OP_GT arithmetic_expr
        {$$ = template("%s > %s",$1, $3);}
    | relational_expr OP_GE arithmetic_expr
        {$$ = template("%s >= %s",$1, $3);}
    | relational_expr OP_EQ arithmetic_expr
        {$$ = template("%s == %s",$1, $3);}
    | relational_expr OP_NEQ arithmetic_expr
        {$$ = template("%s != %s",$1, $3);}
    ;

arithmetic_expr
    : term
        {$$ = $1;}
    | arithmetic_expr OP_PLUS term
        {$$ = template("%s + %s",$1, $3);}
    | arithmetic_expr OP_MINUS term
        {$$ = template("%s - %s",$1, $3);}
    ;

term
    : factor
    | term OP_MULT factor
    | term OP_DIV factor
    | term OP_MOD factor
    ;

factor
    : primary
    | OP_MINUS factor %prec UMINUS  /* Unary minus */
    | OP_NOT factor     /* Logical NOT */
    | factor OP_POWER primary  /* Exponentiation */
    ;

primary
    : IDENTIFIER
    | OP_HASH IDENTIFIER
    |primary DOT IDENTIFIER
        { printf("Member access: %s\n", $3); }
    | primary DOT IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { printf("Method call: %s\n", $3); }
    | IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
    | literal
    | function_call
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
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
        {$$ = template("%s", "int");}
    | KEYWORD_SCALAR
        {$$ = template("%s","double");}
    | KEYWORD_STR
        {$$ = template("%s", "char*");}
    | KEYWORD_BOOL
        {$$ = template("%s", "int");}
    | KEYWORD_COMP
        {$$ = template("%s", "typedef struct {");}
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