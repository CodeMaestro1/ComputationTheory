%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "cgen.h"
  #include <stdbool.h>

  extern char* yytext;
  char* current_struct_name = NULL;
  void yyerror(char const* pat, ...);
  int yylex(void);
  extern int yylineno;
  extern void add_macro(const char *name, const char *replacement);
  extern void free_macro_table(void);


    bool needs_constructor(const char* type) {
        return (strcmp(type, "int") != 0 
                && strcmp(type, "double") != 0 
                && strcmp(type, "char*") != 0
                && strcmp(type, "void") != 0
                && strstr(type, "[") == NULL);
    }

%}



/* Union for semantic values */
%union {
    int    integerVal;
    float  floatVal;
    char  *stringVal;
    struct {
        char* func_ptr;
        char* func_impl;
        char* func_init;
    } methodParts;
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

//%left DOT
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

%nonassoc REDUCE_MEMBER
%nonassoc DOT

%type <stringVal> arg_list arg_list_opt
%type <stringVal> arithmetic_expr
%type <stringVal> array_access member_access
%type <stringVal> array_dims
%type <stringVal> assignment_statement
%type <stringVal> comp_decl comp_decls
%type <stringVal> compound_stmt
%type <stringVal> const_decl const_decls
%type <stringVal> else_part
%type <stringVal> expr
%type <stringVal> factor
%type <stringVal> for_loop
%type <stringVal> func_decl
%type <stringVal> func_decls
%type <stringVal> function_call
%type <stringVal> id_decl
%type <stringVal> id_list
%type <stringVal> list_comp
%type <stringVal> list_comp_array
%type <stringVal> literal
%type <stringVal> local_decls
%type <stringVal> logical_expr
%type <stringVal> lvalue
%type <stringVal> main_func
%type <stringVal> member_decl member_decl_list
%type <stringVal> member_decls
%type <methodParts> method_decl method_decls
%type <stringVal> param param_list param_list_opt return_type_decl
%type <stringVal> postfix
%type <stringVal> primary
%type <stringVal> relational_expr
%type <stringVal> return_opt
%type <stringVal> simple_id array_id
%type <stringVal> simple_stmt
%type <stringVal> stmt stmts
%type <stringVal> term
%type <stringVal> type
%type <stringVal> var_decl var_decls



%start program
%%

program
    : comp_decls const_decls var_decls func_decls main_func
        {
            FILE *fp = fopen("Result.c", "w");
            if (fp == NULL) {
                fprintf(stderr, "Error opening file for writing\n");
                exit(1);
            }
            // Write the C99 program
            fprintf(fp, "#include <stdio.h>\n"
                       "#include <stdlib.h>\n"
                       "#include <math.h>\n\n"
                       "#include \"lambdalib.h\"\n\n"
                       "%s\n"  // Complex type declarations
                       "%s\n"  // Global constants
                       "%s\n"  // Global variables
                       "%s\n"  // Function declarations
                       "int main() {\n"
                       "%s\n"  // Main function body
                       "    return 0;\n"
                       "}\n",
                       $1, $2, $3, $4, $5);
            fclose(fp);
            printf("C99 code generated successfully in Result.c\n");
        }
    ;

//Main function
main_func
    : KEYWORD_DEF KEYWORD_MAIN LEFT_PARENTHESIS RIGHT_PARENTHESIS
        COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
        {
            /* Transform Lambda main function to C99 main function body */
            $$ = template("%s\n%s",
                $6,    /* local declarations */
                $7     /* statements */
            );
            /* Note: We're not including the return_opt because in C99 main(),
               we'll add a default "return 0;" if needed */
        }
    ;

//Complex type declarations
comp_decls
    : /* empty */
        { $$ = ""; }  // Empty string for no complex type declarations
    | comp_decls comp_decl
        { $$ = template("%s\n%s", $1, $2); }  // Concatenate complex type declarations
    ;

// Modify comp_decl rule:
comp_decl
    : KEYWORD_COMP IDENTIFIER 
        { current_struct_name = strdup($2);
            if(!current_struct_name) {
                yyerror("Memory allocation error\n");
                YYABORT;
            }}
      COLON member_decls method_decls KEYWORD_ENDCOMP SEMICOLON
        { 
            // Split function pointers (in struct) from implementations (outside struct)
            $$ = template(
                "typedef struct %s {\n"
                "%s\n"  // member declarations
                "%s\n"  // method declarations (only function pointers)
                "} %s;\n\n"
                "%s\n"  // method implementations (actual functions)
                "// Initialize struct with function pointers\n"
                "const %s ctor_%s = {\n"
                "    %s\n"  // function pointer initializations
                "};\n",
                $2,    // struct name (1)
                $5,    // member declarations
                $6.func_ptr,    // method declarations (function pointers)
                $2,    // typedef name
                $6.func_impl,   // method implementations
                $2,    // struct name (2) for initializer
                $2,    // struct name (3) for initializer variable
                $6.func_init    // function pointer initializations
            );
            free(current_struct_name);
            current_struct_name = NULL;
        }
    ;

//variable declarations
var_decls
    : /* empty */
        { $$ = ""; }
    | var_decls var_decl
        { $$ = template("%s\n%s", $1, $2);}
    ;

var_decl
    : id_list COLON type SEMICOLON
        { 
            // Simple ternary to handle constructor initialization
            $$ = needs_constructor($3) ? 
                template("%s %s = ctor_%s;", $3, $1, $3) :
                template("%s %s;", $3, $1);
        }
    | IDENTIFIER OP_ASSIGN expr SEMICOLON
        { $$ = template("%s = %s;", $1, $3); }
    ;

id_list
    : id_decl
        { $$ = $1; }
    | id_list COMMA id_decl
        { $$ = template("%s, %s", $1, $3); }
    ;

id_decl
    : simple_id
        { $$ = $1; }
    | array_id
        { $$ = $1; }
    ;

simple_id
    : IDENTIFIER
        { $$ = $1; }
    | OP_HASH IDENTIFIER  
        { $$ = $2; }
    ;

array_id
    : IDENTIFIER array_dims
        { $$ = template("%s%s", $1, $2); }
    | OP_HASH IDENTIFIER array_dims
        { 
            // Check if we're inside member_decl rule
            if (strstr(yytext, ":")) {
                // This is a declaration (has a colon)
                $$ = template("%s%s", $2, $3);
            } else {
                // This is a member access (no colon)
                $$ = template("%s%s", $2, $3);
            }
        }
    ;

array_dims
    : LEFT_BRACKET expr RIGHT_BRACKET
        { 
            // For constant array sizes
            if (strstr($2, "CONST_INT")) {
                int size = atoi($2);
                if (size <= 0) {
                    yyerror("Array size must be positive\n");
                    YYABORT;
                }
                $$ = template("[%s]", $2);
            } else {
                // For variable sizes, we'll need to handle this as a VLA
                $$ = template("[%s]", $2);
            }
        }
    | LEFT_BRACKET RIGHT_BRACKET
        { $$ = template("[]"); }
    ;

//function declarations
func_decls
    : /* empty */
        { $$ = ""; }  // Empty string for no function declarations
    | func_decls func_decl
        { $$ = template("%s\n\n%s", $1, $2);}
    ;

func_decl
    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS 
    return_type_decl
    COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
    {
        /* Transform Lambda function to C99 function */
        $$ = template(
            "%s %s(%s) {\n%s\n%s\n%s\n}",
            $6,    /* return type */
            $2,    /* function name */
            $4,    /* parameter list (empty string if no parameters) */
            $8,    /* local declarations */
            $9,     /* function body statements */
            $10   /* return statement */
        );
    }
    ;

return_type_decl
    : /* empty */
        { $$ = "void"; }
    | ARROW type
        { $$ = $2; }
    ;

param
    : id_decl COLON type
        { $$ = template("%s %s", $3, $1); }
    ;

param_list_opt
    : /* empty */
        { $$ = ""; }
    | param_list
        { $$ = $1; }
    ;

param_list
    : param
        { $$ = $1; }
    | param_list COMMA param
        { $$ = template("%s, %s", $1, $3); }
    ;

local_decls
    : /* empty */
        { $$ = ""; }  // Empty declarations -> empty string
    | local_decls var_decl
        { $$ = template("%s\n%s", $1, $2);}
    | local_decls const_decl
        { $$ = template("%s\n%s", $1, $2);}
    ;

stmts
    : /* empty */
        { $$ = ""; }
    | stmt stmts 
        { $$ = template("%s\n%s", $1, $2); }
    ;

stmt
    : simple_stmt
        { $$ = $1; }  
    | compound_stmt  
        { $$ = $1; }
    ;

simple_stmt
    : assignment_statement
        { $$ = $1; }
    | postfix SEMICOLON
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
        { $$ = template("%s = %s;", $1, $3); }
    | lvalue OP_PLUS_ASSIGN expr SEMICOLON
        { $$ = template("%s += %s;", $1, $3); }
    | lvalue OP_MINUS_ASSIGN expr SEMICOLON
        {$$ = template("%s -= %s;", $1, $3); }
    | lvalue OP_MULT_ASSIGN expr SEMICOLON
        { $$ = template("%s *= %s;", $1, $3); }
    | lvalue OP_DIV_ASSIGN expr SEMICOLON
        { $$ = template("%s /= %s;", $1, $3); }
    | lvalue OP_MOD_ASSIGN expr SEMICOLON
        { $$ = template("%s %%= %s;", $1, $3); }
    ;

lvalue
    : IDENTIFIER
        { $$ = $1; }
    | array_access
        { $$ = $1; }
    | member_access  
        { $$ = $1; }
    ;

postfix
    : primary
        { $$ = $1; }
    | array_access
        { $$ = $1; } 
    | member_access
        { $$ = $1; }
    | function_call
        { $$ = $1; }
    ;


/* Modify the member_access rule to use precedence */
member_access
    : OP_HASH IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("self->%s", $2); }
    | primary DOT IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $3); }
    | primary DOT OP_HASH IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $4); }  
    | array_access DOT OP_HASH IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $4); }  
    | array_access DOT IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $3); }
    | member_access DOT IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $3); }
    | member_access DOT OP_HASH IDENTIFIER %prec REDUCE_MEMBER
        { $$ = template("%s.%s", $1, $4); } 
    ;


array_access
    : IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("%s[%s]", $1, $3); }
    | OP_HASH IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("self->%s[%s]", $2, $4); }
    | primary DOT IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("%s.%s[%s]", $1, $3, $5); }
    | member_access DOT IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET
        { $$ = template("%s.%s[%s]", $1, $3, $5); }
    ;

function_call
    : IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { $$ = template("%s(%s)", $1, $3); }
    | primary DOT IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { 
            // Only add comma if there are arguments
            $$ = template("%s.%s(&%s%s%s)", 
                $1, $3, $1,
                ($5[0] != '\0') ? ", " : "",
                $5); 
        }
    | OP_HASH IDENTIFIER DOT IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { 
            // Only add comma if there are arguments
            $$ = template("self->%s.%s(&self->%s%s%s)", 
                $2, $4, $2,
                ($6[0] != '\0') ? ", " : "",
                $6); 
        }
    | array_access DOT IDENTIFIER LEFT_PARENTHESIS arg_list_opt RIGHT_PARENTHESIS
        { 
            // Only add comma if there are arguments
            $$ = template("%s.%s(&%s%s%s)", 
                $1, $3, $1,
                ($5[0] != '\0') ? ", " : "",
                $5); 
        }
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
    | list_comp
        { $$ = $1; }
    | list_comp_array
        { $$ = $1; }
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

list_comp
  : id_decl OP_COLON_ASSIGN 
    LEFT_BRACKET expr        /* $4: the “value” expression */
    KEYWORD_FOR IDENTIFIER   /* $6: loop variable */
    COLON expr               /* $8: the bound (length) */
    RIGHT_BRACKET COLON type /* $11: C element type */ 
    SEMICOLON
    {
      /* 1) Allocate: */
      $$ = template(
        "%s *%s = malloc(sizeof(%s) * (%s));\n"
        "for(int %s = 0; %s < %s; %s++) {\n"
        "    %s[%s] = %s;\n"
        "}",
        $11,   /* C type */
        $1,    /* array name */
        $11,   /* element C type */
        $8,    /* number of elements */
        $6,    /* loop var */
        $6,    /* loop var */
        $8,    /* bound */
        $6,    /* loop var increment */
        $1,    /* array name */
        $6,    /* index */
        $4     /* expression for each element */
    );
    }
;


list_comp_array
    :id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type 
      KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON
    {
      /* Generate C code for array comprehension using another array
         Format: new_array := [expr for elm: type in array of size] : new_type; */
      $$ = template(
          "%s* %s = (%s*)malloc(%s * sizeof(%s));\n"
          "for(int %s_i = 0; %s_i < %s; ++%s_i) {\n"
          "    %s %s = %s[%s_i];\n"      /* Create temporary variable for the element */
          "    %s[%s_i] = %s;\n"         /* Use that variable in the expression */
          "}",
          $15,   /* new_type (target type) */
          $1,    /* new_array name */
          $15,   /* new_type for casting */
          $12,   /* size of source array */
          $15,   /* new_type for sizeof */
          $10,   /* source array name for iterator */
          $10,   /* source array name for iterator */
          $12,   /* size for loop condition */
          $10,   /* source array name for iterator increment */
          $8,    /* element type */
          $6,    /* element variable name (like 'x' in example) */
          $10,   /* source array name */
          $10,   /* source array name for iterator */
          $1,    /* new_array name for assignment */
          $10,   /* source array name for iterator */
          $4     /* The original expression - will use the temporary variable */
      );
    }

member_decls
    : /* empty */
        { $$ = ""; }  // Empty struct has no members
    | member_decl_list
        { $$ = $1; }  // Pass up member declarations
    ;

member_decl_list
    : member_decl
        { $$ = $1; }  // Single member
    | member_decl_list member_decl
        { $$ = template("%s\n%s", $1, $2); }  // Multiple members
    ;

member_decl
    : id_list COLON type SEMICOLON
        { $$ = template("%s %s;", $3, $1); }  // Member declaration in C struct format
    ;

method_decls
    : /* empty */
        { 
            $$.func_ptr = "";
            $$.func_impl = "";
            $$.func_init = ""; 
        }
    | method_decls method_decl
        { 
            $$.func_ptr = template("%s\n%s", $1.func_ptr, $2.func_ptr);
            $$.func_impl = template("%s\n%s", $1.func_impl, $2.func_impl);
            $$.func_init = template("%s%s%s",
                $1.func_init,
                ($1.func_init[0] != '\0' && $2.func_init[0] != '\0') ? ",\n    " : "",
                $2.func_init);
        }
    ;

method_decl
    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHESIS param_list_opt RIGHT_PARENTHESIS
      return_type_decl COLON local_decls stmts return_opt KEYWORD_ENDDEF SEMICOLON
    {
        $$.func_ptr = template(
            "%s (*%s)(struct %s *self%s%s);",
            $6, $2, current_struct_name,
            ($4[0] != '\0') ? ", " : "", $4
        );

        $$.func_impl = template(
            "\n%s %s(struct %s *self%s%s) {\n%s\n%s\n%s\n}",
            $6,                 // return type
            $2,                 // method name
            current_struct_name, // self parameter type
            ($4[0] != '\0') ? ", " : "", $4,  // other parameters
            $8, 
            $9, 
            $10 
        );

        $$.func_init = template(
            ".%s = %s ",
            $2, // struct name
            $2  // function pointer
        );
    }
;

const_decls
    : /* empty */
        {$$ = "";}
    | const_decls const_decl
        { $$ = template("%s\n%s", $1, $2); }
    ;

const_decl
    : KEYWORD_CONST IDENTIFIER OP_ASSIGN literal COLON type SEMICOLON
        {
          // Transform Lambda constant to C99 const
          $$ = template("const %s %s = %s;", $6, $2, $4);
        }
    ;

return_opt
    : /* empty */
        { $$ = ""; }  // No return statement
    | KEYWORD_RETURN SEMICOLON
        { $$ = template("return;"); }  // Void return
    | KEYWORD_RETURN expr SEMICOLON
        { $$ = template("return %s;", $2); }  // Return with value
    ;

else_part
    : /* empty */
        { $$ = ""; }
    | KEYWORD_ELSE COLON stmts
        { $$ = template("else {\n%s\n}", $3); }
    ;


arg_list_opt
    : /*empty */
        { $$ = "" ;}
    | arg_list
        { $$ = $1 ;}
    ;

arg_list
    : expr
        {$$ = $1;}
    | arg_list COMMA expr
        {$$ = template("%s, %s", $1, $3);}
    ;

expr
    : logical_expr
        {$$ = $1;}
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
    | literal
        { $$ = $1; }
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
        { $$ = template("(%s)", $2); }
    ;


literal
    : CONST_INT
        {$$ = template("%d", $1);}
    | CONST_REAL
        {$$ = template("%f", $1);}
    | CONST_STRING
        {$$ = template("\"%s\"", $1);}
    | BOOL_TRUE
        {$$ = template("%s", "1");}
    | BOOL_FALSE
        {$$ = template("%s", "0");}
    ;

type
    : KEYWORD_INTEGER
        {$$ = template("int");}
    | KEYWORD_SCALAR
        {$$ = template("double");}
    | KEYWORD_STR
        {$$ = template("char*");}
    | KEYWORD_BOOL
        {$$ = template("int");}
    | KEYWORD_COMP
        {$$ = template("");}
    | IDENTIFIER
        {$$ = template("%s", $1);} 
    | LEFT_BRACKET CONST_INT RIGHT_BRACKET COLON type
        {$$ = template("%s[%d]", $5, $2);}
    | LEFT_BRACKET RIGHT_BRACKET COLON type
        {$$ = template("%s[]", $4);}
    ;

%%

int main() {
    int result = yyparse();
    
    // Cleanup any remaining allocated memory
    if (current_struct_name != NULL) {
        free(current_struct_name);
        current_struct_name = NULL;
    }
    
    free_macro_table();
    
    if (result == 0) {
        printf("Accepted!\n");
        return 0;
    } else {
        printf("Rejected!\n");
        return 1;
    }
}