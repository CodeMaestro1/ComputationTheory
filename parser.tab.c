/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "cgen.h"

  void yyerror(char const* pat, ...);
  int yylex(void);
  extern int yylineno;
  extern void add_macro(const char *name, const char *replacement);
  extern void free_macro_table(void);

#line 83 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONST_STRING = 4,               /* CONST_STRING  */
  YYSYMBOL_CONST_INT = 5,                  /* CONST_INT  */
  YYSYMBOL_CONST_REAL = 6,                 /* CONST_REAL  */
  YYSYMBOL_KEYWORD_SCALAR = 7,             /* KEYWORD_SCALAR  */
  YYSYMBOL_KEYWORD_STR = 8,                /* KEYWORD_STR  */
  YYSYMBOL_OP_COLON_ASSIGN = 9,            /* OP_COLON_ASSIGN  */
  YYSYMBOL_KEYWORD_INTEGER = 10,           /* KEYWORD_INTEGER  */
  YYSYMBOL_KEYWORD_IF = 11,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 12,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_ENDIF = 13,             /* KEYWORD_ENDIF  */
  YYSYMBOL_KEYWORD_WHILE = 14,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_ENDWHILE = 15,          /* KEYWORD_ENDWHILE  */
  YYSYMBOL_KEYWORD_FOR = 16,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_IN = 17,                /* KEYWORD_IN  */
  YYSYMBOL_KEYWORD_ENDFOR = 18,            /* KEYWORD_ENDFOR  */
  YYSYMBOL_KEYWORD_DEF = 19,               /* KEYWORD_DEF  */
  YYSYMBOL_KEYWORD_ENDDEF = 20,            /* KEYWORD_ENDDEF  */
  YYSYMBOL_KEYWORD_MAIN = 21,              /* KEYWORD_MAIN  */
  YYSYMBOL_KEYWORD_RETURN = 22,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_CONST = 23,             /* KEYWORD_CONST  */
  YYSYMBOL_KEYWORD_COMP = 24,              /* KEYWORD_COMP  */
  YYSYMBOL_KEYWORD_ENDCOMP = 25,           /* KEYWORD_ENDCOMP  */
  YYSYMBOL_KEYWORD_OF = 26,                /* KEYWORD_OF  */
  YYSYMBOL_KEYWORD_BOOL = 27,              /* KEYWORD_BOOL  */
  YYSYMBOL_BOOL_TRUE = 28,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 29,                /* BOOL_FALSE  */
  YYSYMBOL_KEYWORD_BREAK = 30,             /* KEYWORD_BREAK  */
  YYSYMBOL_KEYWORD_CONTINUE = 31,          /* KEYWORD_CONTINUE  */
  YYSYMBOL_OP_PLUS = 32,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 33,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 34,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 35,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 36,                    /* OP_MOD  */
  YYSYMBOL_OP_POWER = 37,                  /* OP_POWER  */
  YYSYMBOL_OP_EQ = 38,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 39,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 40,                     /* OP_LT  */
  YYSYMBOL_OP_LE = 41,                     /* OP_LE  */
  YYSYMBOL_OP_GT = 42,                     /* OP_GT  */
  YYSYMBOL_OP_GE = 43,                     /* OP_GE  */
  YYSYMBOL_OP_AND = 44,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 45,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 46,                    /* OP_NOT  */
  YYSYMBOL_OP_ASSIGN = 47,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUS_ASSIGN = 48,            /* OP_PLUS_ASSIGN  */
  YYSYMBOL_OP_MINUS_ASSIGN = 49,           /* OP_MINUS_ASSIGN  */
  YYSYMBOL_OP_MULT_ASSIGN = 50,            /* OP_MULT_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 51,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 52,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_SEMICOLON = 53,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 54,                     /* COLON  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_DOT = 56,                       /* DOT  */
  YYSYMBOL_LEFT_PARENTHESIS = 57,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 58,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_LEFT_BRACKET = 59,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 60,             /* RIGHT_BRACKET  */
  YYSYMBOL_ARROW = 61,                     /* ARROW  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_main_func = 64,                 /* main_func  */
  YYSYMBOL_comp_decls = 65,                /* comp_decls  */
  YYSYMBOL_comp_decl = 66,                 /* comp_decl  */
  YYSYMBOL_var_decls = 67,                 /* var_decls  */
  YYSYMBOL_var_decl = 68,                  /* var_decl  */
  YYSYMBOL_id_list = 69,                   /* id_list  */
  YYSYMBOL_id_decl = 70,                   /* id_decl  */
  YYSYMBOL_func_decls = 71,                /* func_decls  */
  YYSYMBOL_func_decl = 72,                 /* func_decl  */
  YYSYMBOL_return_type_decl = 73,          /* return_type_decl  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_param_list_opt = 75,            /* param_list_opt  */
  YYSYMBOL_param_list = 76,                /* param_list  */
  YYSYMBOL_local_decls = 77,               /* local_decls  */
  YYSYMBOL_stmts = 78,                     /* stmts  */
  YYSYMBOL_stmt = 79,                      /* stmt  */
  YYSYMBOL_simple_stmt = 80,               /* simple_stmt  */
  YYSYMBOL_assignment_statement = 81,      /* assignment_statement  */
  YYSYMBOL_lvalue = 82,                    /* lvalue  */
  YYSYMBOL_compound_stmt = 83,             /* compound_stmt  */
  YYSYMBOL_member_decls = 84,              /* member_decls  */
  YYSYMBOL_member_decl_list = 85,          /* member_decl_list  */
  YYSYMBOL_member_decl = 86,               /* member_decl  */
  YYSYMBOL_method_decls = 87,              /* method_decls  */
  YYSYMBOL_method_decl = 88,               /* method_decl  */
  YYSYMBOL_const_decls = 89,               /* const_decls  */
  YYSYMBOL_const_decl = 90,                /* const_decl  */
  YYSYMBOL_return_type_opt = 91,           /* return_type_opt  */
  YYSYMBOL_return_opt = 92,                /* return_opt  */
  YYSYMBOL_else_part = 93,                 /* else_part  */
  YYSYMBOL_function_call = 94,             /* function_call  */
  YYSYMBOL_arg_list_opt = 95,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 96,                  /* arg_list  */
  YYSYMBOL_expr = 97,                      /* expr  */
  YYSYMBOL_logical_expr = 98,              /* logical_expr  */
  YYSYMBOL_relational_expr = 99,           /* relational_expr  */
  YYSYMBOL_arithmetic_expr = 100,          /* arithmetic_expr  */
  YYSYMBOL_term = 101,                     /* term  */
  YYSYMBOL_factor = 102,                   /* factor  */
  YYSYMBOL_primary = 103,                  /* primary  */
  YYSYMBOL_range_expr = 104,               /* range_expr  */
  YYSYMBOL_literal = 105,                  /* literal  */
  YYSYMBOL_type = 106                      /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    90,   115,   116,   120,   133,   134,   138,
     142,   143,   147,   152,   157,   166,   167,   171,   177,   178,
     182,   186,   187,   191,   192,   196,   197,   198,   202,   203,
     207,   208,   212,   214,   216,   218,   220,   225,   227,   229,
     231,   233,   235,   240,   241,   245,   248,   250,   253,   255,
     258,   265,   266,   270,   271,   275,   279,   280,   284,   290,
     291,   295,   299,   300,   305,   306,   308,   313,   314,   318,
     322,   323,   327,   328,   332,   336,   337,   338,   342,   343,
     344,   345,   346,   347,   348,   352,   353,   354,   358,   359,
     360,   361,   365,   366,   367,   368,   372,   373,   374,   375,
     379,   381,   386,   387,   388,   389,   390,   394,   396,   398,
     400,   402,   404,   406,   408
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONST_STRING", "CONST_INT", "CONST_REAL", "KEYWORD_SCALAR",
  "KEYWORD_STR", "OP_COLON_ASSIGN", "KEYWORD_INTEGER", "KEYWORD_IF",
  "KEYWORD_ELSE", "KEYWORD_ENDIF", "KEYWORD_WHILE", "KEYWORD_ENDWHILE",
  "KEYWORD_FOR", "KEYWORD_IN", "KEYWORD_ENDFOR", "KEYWORD_DEF",
  "KEYWORD_ENDDEF", "KEYWORD_MAIN", "KEYWORD_RETURN", "KEYWORD_CONST",
  "KEYWORD_COMP", "KEYWORD_ENDCOMP", "KEYWORD_OF", "KEYWORD_BOOL",
  "BOOL_TRUE", "BOOL_FALSE", "KEYWORD_BREAK", "KEYWORD_CONTINUE",
  "OP_PLUS", "OP_MINUS", "OP_MULT", "OP_DIV", "OP_MOD", "OP_POWER",
  "OP_EQ", "OP_NEQ", "OP_LT", "OP_LE", "OP_GT", "OP_GE", "OP_AND", "OP_OR",
  "OP_NOT", "OP_ASSIGN", "OP_PLUS_ASSIGN", "OP_MINUS_ASSIGN",
  "OP_MULT_ASSIGN", "OP_DIV_ASSIGN", "OP_MOD_ASSIGN", "SEMICOLON", "COLON",
  "COMMA", "DOT", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_BRACKET",
  "RIGHT_BRACKET", "ARROW", "$accept", "program", "main_func",
  "comp_decls", "comp_decl", "var_decls", "var_decl", "id_list", "id_decl",
  "func_decls", "func_decl", "return_type_decl", "param", "param_list_opt",
  "param_list", "local_decls", "stmts", "stmt", "simple_stmt",
  "assignment_statement", "lvalue", "compound_stmt", "member_decls",
  "member_decl_list", "member_decl", "method_decls", "method_decl",
  "const_decls", "const_decl", "return_type_opt", "return_opt",
  "else_part", "function_call", "arg_list_opt", "arg_list", "expr",
  "logical_expr", "relational_expr", "arithmetic_expr", "term", "factor",
  "primary", "range_expr", "literal", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -156,    22,   -14,  -156,    16,  -156,     1,   -10,    44,    46,
    -156,    46,     6,   -19,  -156,   -28,  -156,    43,    -3,  -156,
      46,  -156,   109,    10,   109,    46,    14,  -156,  -156,   109,
      23,  -156,  -156,  -156,  -156,  -156,  -156,  -156,     3,    29,
       7,  -156,  -156,  -156,  -156,  -156,   150,   150,   150,  -156,
    -156,    13,    37,   229,    54,    59,    32,  -156,  -156,    25,
    -156,    27,    34,    48,    96,    51,  -156,    50,    64,   295,
     150,    32,  -156,    62,  -156,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   103,  -156,
      46,    70,  -156,    73,  -156,    80,   109,    82,    79,    88,
    -156,  -156,   229,   229,    54,    54,    54,    54,    54,    54,
      59,    59,    32,    32,    32,  -156,    90,  -156,    87,    92,
      94,    46,   109,  -156,  -156,  -156,   150,   109,    89,    46,
    -156,    91,  -156,  -156,  -156,   109,    97,  -156,   202,   109,
    -156,  -156,  -156,     9,   100,   169,   155,   108,   110,   113,
    -156,   153,  -156,  -156,  -156,   255,  -156,   114,   116,    18,
      10,   150,   150,   117,   159,  -156,  -156,  -156,   121,   150,
     150,   150,   150,   150,   150,  -156,  -156,  -156,   209,  -156,
     124,   123,   127,  -156,   128,   150,   135,   137,   141,   142,
     146,   147,    18,   136,   181,   194,   154,   156,   227,   150,
     160,   188,  -156,  -156,  -156,  -156,  -156,  -156,   209,  -156,
     164,   166,  -156,  -156,   168,   170,  -156,   206,   207,  -156,
    -156,   233,   245,  -156,   150,   263,   175,   184,   180,   239,
     193,    17,   200,    26,  -156,  -156,   201,  -156,   150,  -156,
    -156,   -11,   205,   256,   281,  -156,   218,   228,   280,  -156,
     109,   259,   234,   150,  -156,   236,   254,   109,   235,  -156
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    59,     1,     0,     5,     7,     0,     0,    15,
      60,    51,     0,    12,     8,     0,    10,     0,     0,    56,
      52,    53,     0,     0,     0,     0,     0,     2,    16,     0,
       0,    54,   112,   108,   109,   107,   111,   110,     0,     0,
      96,   104,   102,   103,   105,   106,     0,     0,     0,    14,
      98,     0,    74,    75,    78,    85,    88,    92,    97,     0,
      11,     0,     0,     0,     0,     0,    57,     0,     0,     0,
      70,    93,    94,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      21,     0,    55,     0,     6,     0,     0,     0,     0,    71,
      72,    99,    76,    77,    83,    84,    79,    80,    81,    82,
      86,    87,    89,    90,    91,    95,     0,    23,     0,    22,
       0,    21,     0,   114,    61,    69,     0,     0,    18,     0,
      28,     0,   113,    73,    20,    62,     0,    24,     0,    62,
      19,    63,    25,    43,     0,     0,     0,     0,     0,     0,
      36,     0,    29,    30,    32,     0,    31,     0,     0,    28,
       0,     0,     0,     0,     0,     3,    34,    35,     0,     0,
       0,     0,     0,     0,     0,    33,    25,    27,    64,    26,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    44,     0,    99,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    64,    65,
       0,     0,    28,    28,     0,     0,    28,     0,     0,    66,
      17,    67,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    28,     0,    47,     0,   100,
      48,    96,     0,     0,    68,    45,     0,     0,     0,   101,
       0,     0,     0,     0,    49,     0,     0,     0,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,  -156,  -156,  -156,   300,    -8,     0,  -156,
    -156,  -156,   185,   189,  -156,   139,  -155,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,   293,  -156,  -156,  -156,   319,   187,
     119,  -156,  -133,  -156,  -156,   -47,  -156,    21,   240,    19,
     204,   241,  -156,   261,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    27,     2,     5,     9,   177,    15,   151,    17,
      28,   136,   117,   118,   119,   159,   138,   152,   153,   154,
     155,   156,    19,    20,    21,    30,    66,     6,   179,   140,
     194,   229,    50,    98,    99,    51,    52,    53,    54,    55,
      56,    57,   200,    58,   141
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    73,    59,    18,   178,   157,  -112,    63,    67,    16,
       4,    16,    18,    40,    41,    42,    43,    61,   -12,     7,
      16,    13,     3,   100,     8,    60,    24,    25,   198,   241,
      41,    42,    43,    33,    34,    62,    35,   208,    44,    45,
      23,     8,    64,    46,    11,   157,    70,    12,    65,    13,
      36,    29,    25,    37,    44,    45,    47,   221,   222,    46,
      22,   225,    26,    68,    70,   157,    70,    48,   160,    88,
      49,   238,    47,    74,   123,   157,    69,   239,    89,   133,
     244,    75,    76,    48,    90,    38,    83,    84,   157,   157,
     116,    91,   157,    85,    86,    87,   102,   103,   163,    93,
     132,    92,   110,   111,    94,   134,    40,    41,    42,    43,
      95,   157,    32,   180,   181,   182,    33,    34,    96,    35,
     101,   116,   186,   187,   188,   189,   190,   191,   120,   116,
     121,    44,    45,    36,   122,   124,    37,   125,   201,    40,
      41,    42,    43,   126,   127,   128,   210,   129,   130,   139,
     135,   142,   215,    40,    41,    42,    43,   161,   164,    16,
      48,   165,   168,   166,    44,    45,   167,   175,    38,    46,
     176,   183,    40,    41,    42,    43,   184,   231,    44,    45,
     185,   196,    47,    46,   195,   197,   242,   199,   202,   209,
     203,   246,    16,    48,   204,   205,    47,    44,    45,   206,
     207,   211,    46,   -13,   217,   143,   255,    48,   212,   226,
     213,   243,   143,   144,   216,    47,   145,   219,   146,   220,
     144,   223,   147,   145,   224,   146,   162,   227,   252,   233,
     143,   193,   148,   149,   235,   258,   143,   234,   144,   148,
     149,   145,   214,   146,   144,   228,   237,   145,   143,   146,
      71,    72,   236,   240,   245,   150,   144,   148,   149,   145,
     230,   146,   150,   148,   149,   247,   143,    77,    78,    79,
      80,    81,    82,   248,   144,   148,   149,   145,   249,   146,
     150,   232,   250,   251,   143,   253,   150,   254,   259,   112,
     113,   114,   144,   148,   149,   145,   256,   146,   150,    41,
      42,    43,   169,   170,   171,   172,   173,   174,   257,    14,
     131,   148,   149,    31,   137,   192,   150,   104,   105,   106,
     107,   108,   109,    44,    45,    10,   158,   218,     0,   115,
      97,     0,     0,     0,   150
};

static const yytype_int16 yycheck[] =
{
      22,    48,    24,    11,   159,   138,    17,    29,     5,     9,
      24,    11,    20,     3,     4,     5,     6,     3,     9,     3,
      20,     3,     0,    70,    23,    25,    54,    55,   183,     3,
       4,     5,     6,     7,     8,    21,    10,   192,    28,    29,
      59,    23,    19,    33,    54,   178,    57,     3,    25,     3,
      24,    54,    55,    27,    28,    29,    46,   212,   213,    33,
      54,   216,    19,    60,    57,   198,    57,    57,    59,    37,
      60,    54,    46,    60,    96,   208,    47,    60,    53,   126,
     235,    44,    45,    57,    57,    59,    32,    33,   221,   222,
      90,    57,   225,    34,    35,    36,    75,    76,   145,     3,
     122,    53,    83,    84,    53,   127,     3,     4,     5,     6,
      60,   244,     3,   160,   161,   162,     7,     8,    54,    10,
      58,   121,   169,   170,   171,   172,   173,   174,    58,   129,
      57,    28,    29,    24,    54,    53,    27,    58,   185,     3,
       4,     5,     6,    55,    54,    58,   193,    55,    54,    58,
      61,    54,   199,     3,     4,     5,     6,    57,     3,   159,
      57,    53,     9,    53,    28,    29,    53,    53,    59,    33,
      54,    54,     3,     4,     5,     6,    17,   224,    28,    29,
      59,    58,    46,    33,    60,    58,   233,    59,    53,    53,
      53,   238,   192,    57,    53,    53,    46,    28,    29,    53,
      53,    20,    33,     9,    16,     3,   253,    57,    54,     3,
      54,   233,     3,    11,    54,    46,    14,    53,    16,    53,
      11,    53,    20,    14,    54,    16,    57,    20,   250,    54,
       3,    22,    30,    31,    54,   257,     3,    53,    11,    30,
      31,    14,    15,    16,    11,    12,    53,    14,     3,    16,
      46,    47,    13,    53,    53,    53,    11,    30,    31,    14,
      15,    16,    53,    30,    31,    60,     3,    38,    39,    40,
      41,    42,    43,    17,    11,    30,    31,    14,    60,    16,
      53,    18,    54,     3,     3,    26,    53,    53,    53,    85,
      86,    87,    11,    30,    31,    14,    60,    16,    53,     4,
       5,     6,    47,    48,    49,    50,    51,    52,    54,     9,
     121,    30,    31,    20,   129,   176,    53,    77,    78,    79,
      80,    81,    82,    28,    29,     6,   139,   208,    -1,    88,
      69,    -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    65,     0,    24,    66,    89,     3,    23,    67,
      90,    54,     3,     3,    68,    69,    70,    71,    69,    84,
      85,    86,    54,    59,    54,    55,    19,    64,    72,    54,
      87,    86,     3,     7,     8,    10,    24,    27,    59,   106,
       3,     4,     5,     6,    28,    29,    33,    46,    57,    60,
      94,    97,    98,    99,   100,   101,   102,   103,   105,   106,
      70,     3,    21,   106,    19,    25,    88,     5,    60,    47,
      57,   102,   102,    97,    60,    44,    45,    38,    39,    40,
      41,    42,    43,    32,    33,    34,    35,    36,    37,    53,
      57,    57,    53,     3,    53,    60,    54,   105,    95,    96,
      97,    58,    99,    99,   100,   100,   100,   100,   100,   100,
     101,   101,   102,   102,   102,   103,    70,    74,    75,    76,
      58,    57,    54,   106,    53,    58,    55,    54,    58,    55,
      54,    75,   106,    97,   106,    61,    73,    74,    78,    58,
      91,   106,    54,     3,    11,    14,    16,    20,    30,    31,
      53,    70,    79,    80,    81,    82,    83,    94,    91,    77,
      59,    57,    57,    97,     3,    53,    53,    53,     9,    47,
      48,    49,    50,    51,    52,    53,    54,    68,    78,    90,
      97,    97,    97,    54,    17,    59,    97,    97,    97,    97,
      97,    97,    77,    22,    92,    60,    58,    58,    78,    59,
     104,    97,    53,    53,    53,    53,    53,    53,    78,    53,
      97,    20,    54,    54,    15,    97,    54,    16,    92,    53,
      53,    78,    78,    53,    54,    78,     3,    20,    12,    93,
      15,    97,    18,    54,    53,    54,    13,    53,    54,    60,
      53,     3,    97,   106,    78,    53,    97,    60,    17,    60,
      54,     3,   106,    26,    53,    97,    60,    54,   106,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    89,
      89,    90,    91,    91,    92,    92,    92,    93,    93,    94,
      95,    95,    96,    96,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     8,     0,     2,     7,     0,     2,     4,
       1,     3,     1,     4,     3,     0,     2,    12,     0,     2,
       3,     0,     1,     1,     3,     0,     2,     2,     0,     2,
       1,     1,     1,     2,     2,     2,     1,     4,     4,     4,
       4,     4,     4,     1,     4,     9,     6,     8,     8,    12,
      16,     0,     1,     1,     2,     4,     0,     2,    12,     0,
       2,     7,     0,     1,     0,     2,     3,     0,     3,     4,
       0,     1,     1,     3,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     3,     1,     1,     1,     3,
       5,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: comp_decls const_decls var_decls func_decls main_func  */
#line 84 "parser.y"
        { printf("Parsed complete program\n"); }
#line 1641 "parser.tab.c"
    break;

  case 12: /* id_decl: IDENTIFIER  */
#line 148 "parser.y"
        { 
            printf("Identifier %s\n", (yyvsp[0].stringVal));
            (yyval.stringVal) = (yyvsp[0].stringVal);
        }
#line 1650 "parser.tab.c"
    break;

  case 13: /* id_decl: IDENTIFIER LEFT_BRACKET expr RIGHT_BRACKET  */
#line 153 "parser.y"
        { 
            printf("Array identifier %s\n", (yyvsp[-3].stringVal));
            (yyval.stringVal) = (yyvsp[-3].stringVal);
        }
#line 1659 "parser.tab.c"
    break;

  case 14: /* id_decl: IDENTIFIER LEFT_BRACKET RIGHT_BRACKET  */
#line 158 "parser.y"
        { 
            printf("Array identifier %s with index\n", (yyvsp[-2].stringVal));
            (yyval.stringVal) = (yyvsp[-2].stringVal);
        }
#line 1668 "parser.tab.c"
    break;

  case 32: /* simple_stmt: assignment_statement  */
#line 213 "parser.y"
        { printf("Assignment statement\n"); }
#line 1674 "parser.tab.c"
    break;

  case 33: /* simple_stmt: function_call SEMICOLON  */
#line 215 "parser.y"
        { printf("Function call statement\n"); }
#line 1680 "parser.tab.c"
    break;

  case 34: /* simple_stmt: KEYWORD_BREAK SEMICOLON  */
#line 217 "parser.y"
        { printf("Break statement\n"); }
#line 1686 "parser.tab.c"
    break;

  case 35: /* simple_stmt: KEYWORD_CONTINUE SEMICOLON  */
#line 219 "parser.y"
        { printf("Continue statement\n"); }
#line 1692 "parser.tab.c"
    break;

  case 36: /* simple_stmt: SEMICOLON  */
#line 221 "parser.y"
        { printf("Blank statement\n"); }
#line 1698 "parser.tab.c"
    break;

  case 37: /* assignment_statement: lvalue OP_ASSIGN expr SEMICOLON  */
#line 226 "parser.y"
        { printf("Assignment statement with assignment operator\n"); }
#line 1704 "parser.tab.c"
    break;

  case 38: /* assignment_statement: lvalue OP_PLUS_ASSIGN expr SEMICOLON  */
#line 228 "parser.y"
        { printf("Assignment statement with plus assignment operator\n"); }
#line 1710 "parser.tab.c"
    break;

  case 39: /* assignment_statement: lvalue OP_MINUS_ASSIGN expr SEMICOLON  */
#line 230 "parser.y"
        { printf("Assignment statement with minus assignment operator\n"); }
#line 1716 "parser.tab.c"
    break;

  case 40: /* assignment_statement: lvalue OP_MULT_ASSIGN expr SEMICOLON  */
#line 232 "parser.y"
        { printf("Assignment statement with multiplication assignment operator\n"); }
#line 1722 "parser.tab.c"
    break;

  case 41: /* assignment_statement: lvalue OP_DIV_ASSIGN expr SEMICOLON  */
#line 234 "parser.y"
        { printf("Assignment statement with division assignment operator\n"); }
#line 1728 "parser.tab.c"
    break;

  case 42: /* assignment_statement: lvalue OP_MOD_ASSIGN expr SEMICOLON  */
#line 236 "parser.y"
        { printf("Assignment statement with modulo assignment operator\n"); }
#line 1734 "parser.tab.c"
    break;

  case 45: /* compound_stmt: KEYWORD_IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts else_part KEYWORD_ENDIF SEMICOLON  */
#line 247 "parser.y"
        { printf("If statement with parentheses\n"); }
#line 1740 "parser.tab.c"
    break;

  case 46: /* compound_stmt: KEYWORD_WHILE expr COLON stmts KEYWORD_ENDWHILE SEMICOLON  */
#line 249 "parser.y"
        { printf("While loop\n"); }
#line 1746 "parser.tab.c"
    break;

  case 47: /* compound_stmt: KEYWORD_WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts KEYWORD_ENDWHILE SEMICOLON  */
#line 252 "parser.y"
        { printf("While loop with parentheses\n"); }
#line 1752 "parser.tab.c"
    break;

  case 48: /* compound_stmt: KEYWORD_FOR IDENTIFIER KEYWORD_IN range_expr COLON stmts KEYWORD_ENDFOR SEMICOLON  */
#line 254 "parser.y"
        { printf("For loop with range\n"); }
#line 1758 "parser.tab.c"
    break;

  case 49: /* compound_stmt: id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON expr RIGHT_BRACKET COLON type SEMICOLON  */
#line 257 "parser.y"
        { printf("Simple compact array construction\n"); }
#line 1764 "parser.tab.c"
    break;

  case 50: /* compound_stmt: id_decl OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON  */
#line 260 "parser.y"
        { printf("Compact array construction using another array\n"); }
#line 1770 "parser.tab.c"
    break;

  case 64: /* return_opt: %empty  */
#line 305 "parser.y"
        { printf("No return statement\n"); }
#line 1776 "parser.tab.c"
    break;

  case 65: /* return_opt: KEYWORD_RETURN SEMICOLON  */
#line 307 "parser.y"
        { printf("Return statement with no value\n"); }
#line 1782 "parser.tab.c"
    break;

  case 66: /* return_opt: KEYWORD_RETURN expr SEMICOLON  */
#line 309 "parser.y"
        { printf("Return statement with value\n"); }
#line 1788 "parser.tab.c"
    break;

  case 100: /* range_expr: LEFT_BRACKET expr COLON expr RIGHT_BRACKET  */
#line 380 "parser.y"
        { printf("Range with start:stop\n"); }
#line 1794 "parser.tab.c"
    break;

  case 101: /* range_expr: LEFT_BRACKET expr COLON expr COLON expr RIGHT_BRACKET  */
#line 382 "parser.y"
        { printf("Range with start:stop:step\n"); }
#line 1800 "parser.tab.c"
    break;

  case 107: /* type: KEYWORD_INTEGER  */
#line 395 "parser.y"
        { printf("Type: integer\n"); }
#line 1806 "parser.tab.c"
    break;

  case 108: /* type: KEYWORD_SCALAR  */
#line 397 "parser.y"
        { printf("Type: scalar\n"); }
#line 1812 "parser.tab.c"
    break;

  case 109: /* type: KEYWORD_STR  */
#line 399 "parser.y"
        { printf("Type: string\n"); }
#line 1818 "parser.tab.c"
    break;

  case 110: /* type: KEYWORD_BOOL  */
#line 401 "parser.y"
        { printf("Type: boolean\n"); }
#line 1824 "parser.tab.c"
    break;

  case 111: /* type: KEYWORD_COMP  */
#line 403 "parser.y"
        { printf("Type: complex formula\n"); }
#line 1830 "parser.tab.c"
    break;

  case 112: /* type: IDENTIFIER  */
#line 405 "parser.y"
        { printf("Type: user-defined type %s\n", (yyvsp[0].stringVal)); }
#line 1836 "parser.tab.c"
    break;

  case 113: /* type: LEFT_BRACKET CONST_INT RIGHT_BRACKET COLON type  */
#line 407 "parser.y"
        { printf("Type: array of size %d\n", (yyvsp[-3].integerVal)); }
#line 1842 "parser.tab.c"
    break;

  case 114: /* type: LEFT_BRACKET RIGHT_BRACKET COLON type  */
#line 409 "parser.y"
        { printf("Type: array of unspecified size\n"); }
#line 1848 "parser.tab.c"
    break;


#line 1852 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 412 "parser.y"


int main() {
    if (yyparse() == 0) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }

    free_macro_table();

    return 0;
}
