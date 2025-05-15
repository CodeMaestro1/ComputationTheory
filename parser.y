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
%type <stringVal> literal
%type <stringVal> term
%type <stringVal> factor
%type <stringVal> expr
%type <stringVal> function_call
%type <stringVal> primary postfix
%type <stringVal> arg_list arg_list_opt
%type <stringVal> lvalue
%type <stringVal> compound_stmt
%type <stringVal> else_part
%type <stringVal> for_loop
%type <stringVal> return_opt
%type <stringVal> stmt stmts simple_stmt assignment_statement


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
        { $$ = ""; }
    | stmt stmts 
        { $$ = template("%s\n%s", $1, $2); }
    ;

stmt
    : simple_stmt
    | compound_stmt
    ;

simple_stmt
    : assignment_statement
        { $$ = $1; }
    | function_call SEMICOLON
        { $$ = template("%s;", $1); }
    | KEYWORD_BREAK SEMICOLON
        { $$ = template("break;"); }
    | KEYWORD_CONTINUE SEMICOLON
        { $$ = template("continue;"); }
    | SEMICOLON
        { $$ = ""; }
    ;

assignment_statement
    : lvalue OP_ASSIGN expr SEMICOLON
        
    | lvalue OP_PLUS_ASSIGN expr SEMICOLON
        
    | lvalue OP_MINUS_ASSIGN expr SEMICOLON
        
    | lvalue OP_MULT_ASSIGN expr SEMICOLON
        
    | lvalue OP_DIV_ASSIGN expr SEMICOLON
        
    | lvalue OP_MOD_ASSIGN expr SEMICOLON
        
    ;

lvalue
    : IDENTIFIER
        { $$ = $1; }
    | IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("%s[%s]", $1, $3); }
    | OP_HASH IDENTIFIER
        { $$ = template("#%s",$2); }
    | OP_HASH IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("#%s[%s]", $2, $4); }
    ;

compound_stmt
    : KEYWORD_IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts else_part 
      KEYWORD_ENDIF SEMICOLON
        { $$ = template("if(%s) {\n%s\n}%s", $3, $6, $7); }
    | KEYWORD_WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts 
    KEYWORD_ENDWHILE SEMICOLON
        { $$ = template("while(%s){\n%s}", $3, $6); }
    | for_loop
        { $$ = $1; }
    | id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON expr 
      RIGHT_BRACKET COLON type SEMICOLON
        { printf("Simple compact array construction\n"); }
    | id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type 
      KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON
        { printf("Compact array construction using another array\n"); }
    ;

for_loop
    : KEYWORD_FOR IDENTIFIER KEYWORD_IN 
      LEFT_BRACKET expr COLON expr RIGHT_BRACKET COLON stmts KEYWORD_ENDFOR SEMICOLON
        {
          /* 1) standard “for i in [start:stop]” */
          $$ = template(
            "for(int %s = %s; %s < %s; %s++) {\n%s}",
            $2,    /* loop var */  
            $5,    /* start */  
            $2,    /* loop var */  
            $7,    /* stop */  
            $2,    /* loop var */  
            $10    /* body (stmts) */
          );
        }
    | KEYWORD_FOR IDENTIFIER KEYWORD_IN 
      LEFT_BRACKET expr COLON expr COLON expr RIGHT_BRACKET COLON stmts KEYWORD_ENDFOR SEMICOLON
        {
          /* 2) “for i in [start:stop:step]” */
          $$ = template(
            "for(int %s = %s; %s < %s; %s += %s) {\n%s}",
            $2,    /* loop var */
            $5,    /* start */
            $2,    /* loop var */
            $7,    /* stop */
            $2,    /* loop var */
            $9,    /* step */
            $12    /* body */
          );
        }
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
      return_type_decl COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
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
        { $$ = ""; }
    | KEYWORD_ELSE COLON stmts
        { $$ = template("else {\n%s\n}", $3); }
    ;

function_call
    : primary LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
    | primary DOT IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { printf("Method call\n"); }
    ;

arg_list_opt
    : /*empty */
        { $$ = "" ;}
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
        {$$ = $1;}
    | term OP_MULT factor
        {$$ = template("%s * %s",$1, $3);}
    | term OP_DIV factor
        {$$ = template("%s / %s",$1, $3);}
    | term OP_MOD factor
        {$$ = template("%s %% %s",$1, $3);}
    ;


factor
    : postfix
        { $$ = $1; }
    | OP_MINUS factor %prec UMINUS
        { $$ = template("-%s",$2); }
    | OP_NOT factor
        { $$ = template("!%s",$2); }
    | factor OP_POWER postfix
        { $$ = template("pow(%s, %s)", $1, $3); }
    ;

primary
    : IDENTIFIER
        { $$ = $1; }
    | OP_HASH IDENTIFIER
        { $$ = template("#%s",$2); }
    | literal
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
        { $$ = template("(%s)", $2); }
    ;

postfix
    : primary
        { $$ = $1; }
    | postfix LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("%s[%s]", $1, $3); }
    | postfix DOT IDENTIFIER
        { $$ = template("%s.%s", $1, $3); }
    | postfix DOT OP_HASH IDENTIFIER
        { $$ = template("%s.#%s", $1, $4); }
    | postfix LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { $$ = template("%s(%s)", $1, $3); }
    ;

literal
    : CONST_INT
        {$$ = template("%d", $1);}
    | CONST_REAL
        {$$ = template("%f", $1);}
    | CONST_STRING
        {$$ = template("%s", $1);}
    | BOOL_TRUE
        {$$ = template("%s", "1");}
    | BOOL_FALSE
        {$$ = template("%s", "0");}
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