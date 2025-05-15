/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONST_STRING = 259,            /* CONST_STRING  */
    CONST_INT = 260,               /* CONST_INT  */
    CONST_REAL = 261,              /* CONST_REAL  */
    KEYWORD_SCALAR = 262,          /* KEYWORD_SCALAR  */
    KEYWORD_STR = 263,             /* KEYWORD_STR  */
    OP_COLON_ASSIGN = 264,         /* OP_COLON_ASSIGN  */
    KEYWORD_INTEGER = 265,         /* KEYWORD_INTEGER  */
    KEYWORD_IF = 266,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 267,            /* KEYWORD_ELSE  */
    KEYWORD_ENDIF = 268,           /* KEYWORD_ENDIF  */
    KEYWORD_WHILE = 269,           /* KEYWORD_WHILE  */
    KEYWORD_ENDWHILE = 270,        /* KEYWORD_ENDWHILE  */
    KEYWORD_FOR = 271,             /* KEYWORD_FOR  */
    KEYWORD_IN = 272,              /* KEYWORD_IN  */
    KEYWORD_ENDFOR = 273,          /* KEYWORD_ENDFOR  */
    KEYWORD_DEF = 274,             /* KEYWORD_DEF  */
    KEYWORD_ENDDEF = 275,          /* KEYWORD_ENDDEF  */
    KEYWORD_MAIN = 276,            /* KEYWORD_MAIN  */
    KEYWORD_RETURN = 277,          /* KEYWORD_RETURN  */
    KEYWORD_CONST = 278,           /* KEYWORD_CONST  */
    KEYWORD_COMP = 279,            /* KEYWORD_COMP  */
    KEYWORD_ENDCOMP = 280,         /* KEYWORD_ENDCOMP  */
    KEYWORD_OF = 281,              /* KEYWORD_OF  */
    KEYWORD_BOOL = 282,            /* KEYWORD_BOOL  */
    BOOL_TRUE = 283,               /* BOOL_TRUE  */
    BOOL_FALSE = 284,              /* BOOL_FALSE  */
    KEYWORD_BREAK = 285,           /* KEYWORD_BREAK  */
    KEYWORD_CONTINUE = 286,        /* KEYWORD_CONTINUE  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COLON = 288,                   /* COLON  */
    COMMA = 289,                   /* COMMA  */
    ARROW = 290,                   /* ARROW  */
    DOT = 291,                     /* DOT  */
    LEFT_PARENTHESIS = 292,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 293,       /* RIGHT_PARENTHESIS  */
    LEFT_BRACKET = 294,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 295,           /* RIGHT_BRACKET  */
    OP_POWER = 296,                /* OP_POWER  */
    UMINUS = 297,                  /* UMINUS  */
    OP_MULT = 298,                 /* OP_MULT  */
    OP_DIV = 299,                  /* OP_DIV  */
    OP_MOD = 300,                  /* OP_MOD  */
    OP_PLUS = 301,                 /* OP_PLUS  */
    OP_MINUS = 302,                /* OP_MINUS  */
    OP_LT = 303,                   /* OP_LT  */
    OP_LE = 304,                   /* OP_LE  */
    OP_GT = 305,                   /* OP_GT  */
    OP_GE = 306,                   /* OP_GE  */
    OP_EQ = 307,                   /* OP_EQ  */
    OP_NEQ = 308,                  /* OP_NEQ  */
    OP_NOT = 309,                  /* OP_NOT  */
    OP_AND = 310,                  /* OP_AND  */
    OP_OR = 311,                   /* OP_OR  */
    OP_ASSIGN = 312,               /* OP_ASSIGN  */
    OP_PLUS_ASSIGN = 313,          /* OP_PLUS_ASSIGN  */
    OP_MINUS_ASSIGN = 314,         /* OP_MINUS_ASSIGN  */
    OP_MULT_ASSIGN = 315,          /* OP_MULT_ASSIGN  */
    OP_DIV_ASSIGN = 316,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 317            /* OP_MOD_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    int    integerVal;
    float  floatVal;
    char  *stringVal;

#line 132 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
