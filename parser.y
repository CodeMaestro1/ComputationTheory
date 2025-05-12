%{
  #include <stdio.h>
  #include <stdlib.h>

  void yyerror(const char *s);
  int yylex(void);
  extern int yylineno;
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


%token <integerVal> KEYWORD_INTEGER 
KEYWORD_SCALAR 
KEYWORD_STR 

%token KEYWORD_IF KEYWORD_ELSE KEYWORD_ENDIF
%token KEYWORD_WHILE KEYWORD_ENDWHILE
%token KEYWORD_FOR KEYWORD_IN KEYWORD_ENDFOR
%token KEYWORD_DEF KEYWORD_ENDDEF KEYWORD_MAIN KEYWORD_RETURN
%token KEYWORD_CONST
%token KEYWORD_COMP KEYWORD_ENDCOMP KEYWORD_OF
%token KEYWORD_DEFMACRO KEYWORD_ENDMACRO
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

%start program

/* Operator precedence */
%left DOT
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS
%left LEFT_BRACKET RIGHT_BRACKET 
%right OP_POWER
%right OP_PLUS_ASSIGN OP_MINUS_ASSIGN
%left OP_MULT_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN
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
%%

/* Grammar rules begin here */
program
    : comp_decls macro_decls const_decls var_decls func_decls main_func
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
    | type_decls type__basic_decl
    ;

type__basic_decl
    : KEYWORD_INTEGER
    | KEYWORD_SCALAR
    | KEYWORD_STR
    | KEYWORD_BOOL
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
    : IDENTIFIER
    | id_list COMMA IDENTIFIER
    ;

//function declarations
func_decls
    : /* empty */
    | func_decls func_decl
    ;

func_decl
    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS 
    return_type_opt COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
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
    | KEYWORD_IF expr COLON stmts else_part KEYWORD_ENDIF SEMICOLON
    | KEYWORD_WHILE expr COLON stmts KEYWORD_ENDWHILE SEMICOLON
    | KEYWORD_FOR IDENTIFIER KEYWORD_IN expr COLON stmts KEYWORD_ENDFOR SEMICOLON
    | KEYWORD_BREAK SEMICOLON
    | KEYWORD_CONTINUE SEMICOLON
    | function_call SEMICOLON
    ;

macro_decls
    : /* empty */
    | macro_decls macro_decl
    ;

macro_decl
    : KEYWORD_DEFMACRO IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS
      stmts KEYWORD_ENDMACRO SEMICOLON
    ;

param_list_opt
    : /* empty */
    | param_list
    ;

param_list
    : IDENTIFIER
    | param_list COMMA IDENTIFIER
    ;

comp_decls
    : /* empty */
    | comp_decls comp_decl
    ;

comp_decl
    : KEYWORD_COMP IDENTIFIER COLON member_decls method_decls KEYWORD_ENDCOMP SEMICOLON
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
    | COLON type
    ;

return_opt
    : /* empty */
    | KEYWORD_RETURN expr SEMICOLON
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

literal
    : CONST_INT
    | CONST_REAL
    | CONST_STRING
    | BOOL_TRUE
    | BOOL_FALSE
    ;

type
    : KEYWORD_INTEGER
    | KEYWORD_SCALAR
    | KEYWORD_STR
    | KEYWORD_BOOL
    ;

%%

/* Error handler */
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

int main() {
    if (yyparse() == 0) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }
    return 0;
}