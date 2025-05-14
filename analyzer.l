%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

#define MULTIPLIER 37
#define HASH_SIZE 101

typedef struct Macro {
    char *name;
    char *replacement;
    struct Macro *next;
} Macro;


Macro *macroTable[HASH_SIZE] = {NULL};


unsigned long hash(const char *s)
{
    unsigned long h = 0;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    while(*us != '\0') {
        h = h * MULTIPLIER + *us;
        us++;
    } 

    return h;
}

void add_macro(const char *name, const char *replacement)
{
    unsigned long h = hash(name) % HASH_SIZE;
    Macro *new_macro = (Macro *)malloc(sizeof(Macro));
    new_macro->name = strdup(name);
    new_macro->replacement = strdup(replacement);
    new_macro->next = macroTable[h];
    macroTable[h] = new_macro;
}

char *lookup_macro(const char *name)
{
    unsigned long h = hash(name) % HASH_SIZE;
    Macro *macro = macroTable[h];
    while (macro != NULL) {
        if (strcmp(macro->name, name) == 0) {
            return macro->replacement;
        }
        macro = macro->next;
    }
    return NULL;
}

void free_macro_table(void) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Macro *current = macroTable[i];
        while (current != NULL) {
            Macro *next = current->next;
            free(current->name);
            free(current->replacement);
            free(current);
            current = next;
        }
        macroTable[i] = NULL;
    }
}


%}

%option yylineno
%option noyywrap
%option noinput
%option nounput

INT_PART    (0|[1-9][0-9]*)      
FRAC_PART   [0-9]+               
EXP_PART    [eE][+-]?[0-9]+      

%%

"--".*                  ; /* Ignore line comments */
[ \t\n\r]+              ; /* Ignore whitespace */


"@defmacro".*$ {
    char *name = strdup(yytext + 10); // Skip "@defmacro " (10 characters)
    char *repl = strchr(name, ' ');
    if (repl) {
        *repl = '\0'; // Terminate macro name
        repl++; // Move to replacement text
        add_macro(name, repl);
        printf("Macro defined: %s -> %s\n", name, repl);
    } else {
        printf("Error: Invalid macro definition at line %d\n", yylineno);
    }
    free(name);
}


"integer"               { printf("Token KEYWORD_INTEGER: %s\n", yytext); return KEYWORD_INTEGER;}
"scalar"                { printf("Token KEYWORD_SCALAR: %s\n", yytext); return KEYWORD_SCALAR;}
"str"                   { printf("Token KEYWORD_STR: %s\n", yytext); return KEYWORD_STR;}
"bool"                  { printf("Token KEYWORD_BOOL: %s\n", yytext); return KEYWORD_BOOL;}
"True"                  { printf("Token BOOL_TRUE: %s\n", yytext);  return BOOL_TRUE;}
"False"                 { printf("Token BOOL_FALSE: %s\n", yytext);  return BOOL_FALSE;}
"const"                 { printf("Token KEYWORD_CONST: %s\n", yytext);  return KEYWORD_CONST;}
"if"                    { printf("Token KEYWORD_IF: %s\n", yytext); return KEYWORD_IF;}
"else"                  { printf("Token KEYWORD_ELSE: %s\n", yytext); return KEYWORD_ELSE;}    
"endif"                 { printf("Token KEYWORD_ENDIF: %s\n", yytext); return KEYWORD_ENDIF;}
"for"                   { printf("Token KEYWORD_FOR: %s\n", yytext); return KEYWORD_FOR;}
"in"                    { printf("Token KEYWORD_IN: %s\n", yytext); return KEYWORD_IN;}
"endfor"                { printf("Token KEYWORD_ENDFOR: %s\n", yytext); return KEYWORD_ENDFOR;}
"while"                 { printf("Token KEYWORD_WHILE: %s\n", yytext); return KEYWORD_WHILE;}
"endwhile"              { printf("Token KEYWORD_ENDWHILE: %s\n", yytext); return KEYWORD_ENDWHILE;}
"break"                 { printf("Token KEYWORD_BREAK: %s\n", yytext); return KEYWORD_BREAK;}    
"continue"              { printf("Token KEYWORD_CONTINUE: %s\n", yytext); return KEYWORD_CONTINUE;}
"def"                   { printf("Token KEYWORD_DEF: %s\n", yytext); return KEYWORD_DEF;}
"enddef"                { printf("Token KEYWORD_ENDDEF: %s\n", yytext); return KEYWORD_ENDDEF;}
"main"                  { printf("Token KEYWORD_MAIN: %s\n", yytext); return KEYWORD_MAIN;}
"return"                { printf("Token KEYWORD_RETURN: %s\n", yytext); return KEYWORD_RETURN;}
"comp"                  { printf("Token KEYWORD_COMP: %s\n", yytext); return KEYWORD_COMP;}
"endcomp"               { printf("Token KEYWORD_ENDCOMP: %s\n", yytext); return KEYWORD_ENDCOMP;}
"of"                    { printf("Token KEYWORD_OF: %s\n", yytext); return KEYWORD_OF;}

"and"                   { printf("Token OP_AND: %s\n", yytext); return OP_AND;}
"or"                    { printf("Token OP_OR: %s\n", yytext); return OP_OR;}
"not"                   { printf("Token OP_NOT: %s\n", yytext); return OP_NOT;}



[a-zA-Z_][a-zA-Z0-9_]*  { 
    char *macro_replacement = lookup_macro(yytext);
    if (macro_replacement) {
        YY_BUFFER_STATE buffer_state = yy_scan_string(macro_replacement);
        yypush_buffer_state(buffer_state);
    } else {
        yylval.stringVal = strdup(yytext);
        printf("Token IDENTIFIER: %s\n", yytext);
        return IDENTIFIER;
    }
}

0                       { printf("Token CONST_INT: %s\n", yytext); 
                        yylval.integerVal = 0;
                        return CONST_INT;
                        }

[1-9][0-9]*            { printf("Token CONST_INT: %s\n", yytext); 
                            yylval.integerVal = atoi(yytext);
                            return CONST_INT;
                        }



{INT_PART}\.{FRAC_PART}  { printf("Token CONST_REAL: %s\n", yytext);
                            yylval.floatVal = atof(yytext);
                            return CONST_REAL; 
                        }
{INT_PART}{EXP_PART}       { printf("Token CONST_REAL: %s\n", yytext);
                            yylval.floatVal = atof(yytext);
                            return CONST_REAL; 
                            }
{INT_PART}\.{FRAC_PART}{EXP_PART}  { printf("Token CONST_REAL: %s\n", yytext);
                                    yylval.floatVal = atof(yytext);
                                    return CONST_REAL; 
                                    }




\"(\\.|[^"\\])*\"      {
    /* Remove quotes and process escapes */
    char *s = yytext;
    s++; /* Skip opening " */
    int len = yyleng - 2; /* Exclude quotes */
    char *content = strndup(s, len);
    yylval.stringVal = content;
    printf("Token CONST_STRING: %s\n", content); 
    return CONST_STRING;
}



"="                     { printf("Token OP_ASSIGN: %s\n", yytext); return OP_ASSIGN;}
"+="                    { printf("Token OP_PLUS_ASSIGN: %s\n", yytext); return OP_PLUS_ASSIGN;}
"-="                    { printf("Token OP_MINUS_ASSIGN: %s\n", yytext); return OP_MINUS_ASSIGN;}
"*="                    { printf("Token OP_MULT_ASSIGN: %s\n", yytext); return OP_MULT_ASSIGN;}
"/="                    { printf("Token OP_DIV_ASSIGN: %s\n", yytext); return OP_DIV_ASSIGN;}
"%="                    { printf("Token OP_MOD_ASSIGN: %s\n", yytext); return OP_MOD_ASSIGN;}
":="                    { printf("Token OP_COLON_ASSIGN: %s\n", yytext); return OP_COLON_ASSIGN;}



"+"                     { printf("Token OP_PLUS: %s\n", yytext); return OP_PLUS;}
"-"                     { printf("Token OP_MINUS: %s\n", yytext); return OP_MINUS;}
"**"                    { printf("Token OP_POWER: %s\n", yytext); return OP_POWER;}
"*"                     { printf("Token OP_MULT: %s\n", yytext); return OP_MULT;}
"/"                     { printf("Token OP_DIV: %s\n", yytext); return OP_DIV;}
"%"                     { printf("Token OP_MOD: %s\n", yytext); return OP_MOD;}





"=="                    { printf("Token OP_EQ: %s\n", yytext); return OP_EQ;}
"!="                    { printf("Token OP_NEQ: %s\n", yytext); return OP_NEQ;}
"<"                     { printf("Token OP_LT: %s\n", yytext); return OP_LT;}
"<="                    { printf("Token OP_LE: %s\n", yytext); return OP_LE;}
">"                     { printf("Token OP_GT: %s\n", yytext); return OP_GT;}
">="                    { printf("Token OP_GE: %s\n", yytext); return OP_GE;}

";"                     { printf("Token SEMICOLON: %s\n", yytext); return SEMICOLON;}
"("                     { printf("Token LEFT_PARENTHESIS: %s\n", yytext); return LEFT_PARENTHESIS;}
")"                     { printf("Token RIGHT_PARENTHESIS: %s\n", yytext); return RIGHT_PARENTHESIS;}
","                     { printf("Token COMMA: %s\n", yytext); return COMMA;}
"["                     { printf("Token LEFT_BRACKET: %s\n", yytext); return LEFT_BRACKET;}
"]"                     { printf("Token RIGHT_BRACKET: %s\n", yytext); return RIGHT_BRACKET;}
":"                     { printf("Token COLON: %s\n", yytext); return COLON;}
"."                     { printf("Token DOT: %s\n", yytext); return DOT;}
"->"                    { printf("Token ARROW: %s\n", yytext); return ARROW;}    


[ -~] { printf("Found printable ASCII: %c (ASCII: %d)\n", yytext[0], (int)yytext[0]); }
. { 
    printf("Unrecognized character: %c (ASCII: %d) at line %d\n", 
           yytext[0], (int)yytext[0], yylineno);
    // Comment out exit(1) temporarily for debugging
}


%%