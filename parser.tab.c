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

  //void yyerror(char const* pat, ...);
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
  YYSYMBOL_member_decls = 80,              /* member_decls  */
  YYSYMBOL_member_decl = 81,               /* member_decl  */
  YYSYMBOL_method_decls = 82,              /* method_decls  */
  YYSYMBOL_method_decl = 83,               /* method_decl  */
  YYSYMBOL_const_decls = 84,               /* const_decls  */
  YYSYMBOL_const_decl = 85,                /* const_decl  */
  YYSYMBOL_return_type_opt = 86,           /* return_type_opt  */
  YYSYMBOL_return_opt = 87,                /* return_opt  */
  YYSYMBOL_else_part = 88,                 /* else_part  */
  YYSYMBOL_function_call = 89,             /* function_call  */
  YYSYMBOL_arg_list_opt = 90,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 91,                  /* arg_list  */
  YYSYMBOL_expr = 92,                      /* expr  */
  YYSYMBOL_range_expr = 93,                /* range_expr  */
  YYSYMBOL_literal = 94,                   /* literal  */
  YYSYMBOL_type = 95                       /* type  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

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
       0,    76,    76,    83,   108,   109,   113,   126,   127,   131,
     135,   136,   140,   141,   142,   148,   149,   153,   159,   160,
     164,   165,   169,   170,   174,   175,   179,   180,   181,   185,
     186,   190,   192,   195,   198,   201,   203,   206,   208,   210,
     212,   214,   220,   221,   225,   229,   230,   234,   240,   241,
     245,   249,   250,   255,   256,   258,   263,   264,   268,   272,
     273,   277,   278,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   304,   306,   311,   312,   313,   314,   315,   319,
     321,   323,   325,   327,   329,   331,   333
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "param_list", "local_decls", "stmts", "stmt", "member_decls",
  "member_decl", "method_decls", "method_decl", "const_decls",
  "const_decl", "return_type_opt", "return_opt", "else_part",
  "function_call", "arg_list_opt", "arg_list", "expr", "range_expr",
  "literal", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,     4,     7,  -116,    48,  -116,    30,     9,    53,    65,
    -116,  -116,    20,    16,  -116,   -43,  -116,    57,    65,    -2,
      55,    -2,    65,     6,  -116,  -116,   -26,  -116,     5,  -116,
    -116,  -116,  -116,  -116,  -116,     2,    31,    22,  -116,  -116,
    -116,  -116,  -116,   160,   160,  -116,  -116,   303,  -116,    24,
    -116,    23,    29,    -2,    84,    36,  -116,    32,    41,   272,
     160,    27,   389,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,  -116,  -116,    87,
      38,    44,    43,  -116,    49,    -2,    54,    51,    56,   560,
    -116,   282,   282,   574,   574,   574,   560,    27,    27,   -25,
     -25,   -25,   -25,    61,  -116,   -33,  -116,    58,    59,    63,
    -116,    87,    -2,  -116,  -116,  -116,   160,    -2,    60,    64,
      87,  -116,    68,  -116,   560,  -116,    67,    -2,    79,  -116,
      88,    -2,    -2,  -116,  -116,  -116,     8,    83,   169,   140,
      91,    92,    93,  -116,  -116,    94,    96,  -116,     0,    95,
     160,   160,   160,   470,   138,  -116,  -116,  -116,  -116,  -116,
    -116,   188,  -116,   160,   516,   416,   443,  -116,    97,     0,
     133,   137,   253,  -116,   104,   105,   197,   160,   106,   188,
    -116,   538,   114,   166,  -116,  -116,   123,   493,  -116,   157,
    -116,  -116,   128,   218,   222,  -116,   160,   228,   125,   124,
     131,   174,   139,   274,   141,  -116,    -7,   317,   176,  -116,
     142,  -116,   160,  -116,  -116,   149,   202,   252,  -116,   346,
      -2,   181,  -116,   161,   160,  -116,   360,   162,    -2,   167,
    -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    48,     1,     0,     5,     7,     0,     0,    15,
      49,    42,     0,    12,     8,     0,    10,     0,    45,     0,
       0,     0,     0,     0,     2,    16,     0,    43,     0,    94,
      90,    91,    89,    93,    92,     0,     0,    80,    86,    84,
      85,    87,    88,     0,     0,    14,    81,     0,    79,     0,
      11,     0,     0,     0,     0,     0,    46,     0,     0,     0,
      59,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     9,    22,
       0,     0,     0,     6,     0,     0,     0,     0,    60,    61,
      78,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    24,     0,    23,     0,
      44,    22,     0,    96,    50,    58,     0,     0,     0,    18,
       0,    29,     0,    95,    62,    20,     0,    51,     0,    25,
       0,    51,     0,    19,    52,    26,     0,     0,     0,     0,
       0,     0,     0,    41,    30,     0,     0,    21,    29,     0,
       0,     0,     0,     0,     0,     3,    38,    39,    40,    26,
      28,    53,    27,     0,     0,     0,     0,    29,     0,    29,
       0,     0,     0,    31,     0,    78,     0,     0,     0,    53,
      54,     0,     0,     0,    29,    29,     0,     0,    29,     0,
      55,    17,     0,    56,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    80,     0,     0,    29,
       0,    36,     0,    82,    37,     0,     0,    57,    34,     0,
       0,     0,    83,     0,     0,    32,     0,     0,     0,     0,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,  -116,  -116,   213,   205,   221,  -116,
    -116,  -116,   115,   113,  -116,    81,  -115,  -116,  -116,  -116,
    -116,  -116,  -116,   239,   116,    72,  -116,  -112,  -116,  -116,
     -28,  -116,   195,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    24,     2,     5,     9,   160,    15,    16,    17,
      25,   128,   106,   107,   108,   148,   130,   144,    18,    27,
      28,    56,     6,   162,   133,   171,   201,    46,    87,    88,
      47,   178,    48,   134
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    29,    49,    13,     3,    30,    31,    57,    32,    51,
     -94,    21,    22,    69,    70,    61,    62,   149,   145,    75,
      76,   117,    33,     8,    54,    34,   118,    52,    53,    22,
      55,     4,    89,   161,    81,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   145,
      60,     7,   176,     8,   179,   150,    12,    35,    37,    38,
      39,    40,    58,    11,   145,    60,   113,   145,    13,   193,
     194,    75,    76,   197,    19,    20,    23,    78,    59,    60,
      79,   145,   145,    41,    42,   145,    80,    82,   124,    83,
     105,   136,    84,   123,   217,    85,   109,   110,   125,   137,
     111,    43,   138,   112,   139,   145,    76,   114,   140,   115,
     153,   116,    44,   147,   120,    45,   119,   121,   141,   142,
     126,   132,   164,   165,   166,   127,   131,   206,    38,    39,
      40,    30,    31,   135,    32,   172,    37,    38,    39,    40,
     151,   143,   181,   154,   155,   156,   157,   158,    33,   187,
     159,    34,    41,    42,   163,   168,   177,   182,   184,   185,
     188,    41,    42,    37,    38,    39,    40,   191,   203,   192,
      43,   207,    37,    38,    39,    40,   195,   198,   205,    43,
     208,    44,   199,    35,   219,   209,   180,   210,    41,    42,
      44,   136,   211,   216,   214,   218,   226,    41,    42,   137,
     136,   223,   138,   220,   139,   221,    43,   224,   137,   229,
     170,   138,   186,   139,   225,    43,   228,    44,   141,   142,
     230,   136,    14,    26,   122,   136,   152,   141,   142,   137,
     200,   136,   138,   137,   139,   129,   138,   202,   139,   137,
     169,   143,   138,    50,   139,    10,   204,   146,   141,   142,
     143,   189,   141,   142,    86,   136,     0,     0,   141,   142,
       0,     0,     0,   137,     0,     0,   138,     0,   139,   183,
       0,   143,     0,     0,     0,   143,    38,    39,    40,     0,
       0,   143,   141,   142,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
      41,    42,     0,     0,     0,   143,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      69,    70,    71,    72,    73,    74,    75,    76,   212,     0,
       0,     0,     0,     0,   213,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   174,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,   167,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,   196,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,   173,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,   190,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    63,    64,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      19,     3,    21,     3,     0,     7,     8,     5,    10,     3,
      17,    54,    55,    38,    39,    43,    44,     9,   130,    44,
      45,    54,    24,    23,    19,    27,    59,    21,    54,    55,
      25,    24,    60,   148,    53,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   161,
      57,     3,   167,    23,   169,    47,     3,    59,     3,     4,
       5,     6,    60,    54,   176,    57,    85,   179,     3,   184,
     185,    44,    45,   188,    54,    59,    19,    53,    47,    57,
      57,   193,   194,    28,    29,   197,    57,     3,   116,    53,
       3,     3,    60,   112,   209,    54,    58,    53,   117,    11,
      57,    46,    14,    54,    16,   217,    45,    53,    20,    58,
     138,    55,    57,   132,    55,    60,    58,    54,    30,    31,
      60,    54,   150,   151,   152,    61,    58,     3,     4,     5,
       6,     7,     8,    54,    10,   163,     3,     4,     5,     6,
      57,    53,   170,     3,    53,    53,    53,    53,    24,   177,
      54,    27,    28,    29,    59,    17,    59,    20,    54,    54,
      54,    28,    29,     3,     4,     5,     6,    53,   196,     3,
      46,   199,     3,     4,     5,     6,    53,    20,    53,    46,
     199,    57,    54,    59,   212,    54,    53,    13,    28,    29,
      57,     3,    53,    17,    53,    53,   224,    28,    29,    11,
       3,   220,    14,    54,    16,     3,    46,    26,    11,   228,
      22,    14,    15,    16,    53,    46,    54,    57,    30,    31,
      53,     3,     9,    18,   111,     3,    57,    30,    31,    11,
      12,     3,    14,    11,    16,   120,    14,    15,    16,    11,
     159,    53,    14,    22,    16,     6,    18,   131,    30,    31,
      53,   179,    30,    31,    59,     3,    -1,    -1,    30,    31,
      -1,    -1,    -1,    11,    -1,    -1,    14,    -1,    16,    16,
      -1,    53,    -1,    -1,    -1,    53,     4,     5,     6,    -1,
      -1,    53,    30,    31,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      28,    29,    -1,    -1,    -1,    53,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      38,    39,    40,    41,    42,    43,    44,    45,    54,    -1,
      -1,    -1,    -1,    -1,    60,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    65,     0,    24,    66,    84,     3,    23,    67,
      85,    54,     3,     3,    68,    69,    70,    71,    80,    54,
      59,    54,    55,    19,    64,    72,    69,    81,    82,     3,
       7,     8,    10,    24,    27,    59,    95,     3,     4,     5,
       6,    28,    29,    46,    57,    60,    89,    92,    94,    95,
      70,     3,    21,    54,    19,    25,    83,     5,    60,    47,
      57,    92,    92,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    60,    53,    57,
      57,    95,     3,    53,    60,    54,    94,    90,    91,    92,
      58,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,     3,    74,    75,    76,    58,
      53,    57,    54,    95,    53,    58,    55,    54,    59,    58,
      55,    54,    75,    95,    92,    95,    60,    61,    73,    74,
      78,    58,    54,    86,    95,    54,     3,    11,    14,    16,
      20,    30,    31,    53,    79,    89,    86,    95,    77,     9,
      47,    57,    57,    92,     3,    53,    53,    53,    53,    54,
      68,    78,    85,    59,    92,    92,    92,    54,    17,    77,
      22,    87,    92,    53,    58,    58,    78,    59,    93,    78,
      53,    92,    20,    16,    54,    54,    15,    92,    54,    87,
      53,    53,     3,    78,    78,    53,    54,    78,    20,    54,
      12,    88,    15,    92,    18,    53,     3,    92,    95,    54,
      13,    53,    54,    60,    53,    60,    17,    78,    53,    92,
      54,     3,    60,    95,    26,    53,    92,    60,    54,    95,
      53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    82,    82,    83,    84,    84,
      85,    86,    86,    87,    87,    87,    88,    88,    89,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     8,     0,     2,     7,     0,     2,     4,
       1,     3,     1,     4,     3,     0,     2,    12,     0,     2,
       3,     5,     0,     1,     1,     3,     0,     2,     2,     0,
       2,     4,    12,    16,     9,     6,     8,     8,     2,     2,
       2,     1,     0,     2,     4,     0,     2,    12,     0,     2,
       7,     0,     1,     0,     2,     3,     0,     3,     4,     0,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     5,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4
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
#line 77 "parser.y"
        { printf("Parsed complete program\n"); }
#line 1400 "parser.tab.c"
    break;

  case 31: /* stmt: IDENTIFIER OP_ASSIGN expr SEMICOLON  */
#line 191 "parser.y"
        { printf("Assignment statement\n"); }
#line 1406 "parser.tab.c"
    break;

  case 32: /* stmt: IDENTIFIER OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON expr RIGHT_BRACKET COLON type SEMICOLON  */
#line 194 "parser.y"
        { printf("Simple compact array construction\n"); }
#line 1412 "parser.tab.c"
    break;

  case 33: /* stmt: IDENTIFIER OP_COLON_ASSIGN LEFT_BRACKET expr KEYWORD_FOR IDENTIFIER COLON type KEYWORD_IN IDENTIFIER KEYWORD_OF expr RIGHT_BRACKET COLON type SEMICOLON  */
#line 197 "parser.y"
        { printf("Compact array construction using another array\n"); }
#line 1418 "parser.tab.c"
    break;

  case 34: /* stmt: KEYWORD_IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts else_part KEYWORD_ENDIF SEMICOLON  */
#line 200 "parser.y"
        { printf("If statement with parentheses\n"); }
#line 1424 "parser.tab.c"
    break;

  case 35: /* stmt: KEYWORD_WHILE expr COLON stmts KEYWORD_ENDWHILE SEMICOLON  */
#line 202 "parser.y"
        { printf("While loop\n"); }
#line 1430 "parser.tab.c"
    break;

  case 36: /* stmt: KEYWORD_WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS COLON stmts KEYWORD_ENDWHILE SEMICOLON  */
#line 205 "parser.y"
        { printf("While loop with parentheses\n"); }
#line 1436 "parser.tab.c"
    break;

  case 37: /* stmt: KEYWORD_FOR IDENTIFIER KEYWORD_IN range_expr COLON stmts KEYWORD_ENDFOR SEMICOLON  */
#line 207 "parser.y"
        { printf("For loop with range\n"); }
#line 1442 "parser.tab.c"
    break;

  case 38: /* stmt: KEYWORD_BREAK SEMICOLON  */
#line 209 "parser.y"
        { printf("Break statement\n"); }
#line 1448 "parser.tab.c"
    break;

  case 39: /* stmt: KEYWORD_CONTINUE SEMICOLON  */
#line 211 "parser.y"
        { printf("Continue statement\n"); }
#line 1454 "parser.tab.c"
    break;

  case 40: /* stmt: function_call SEMICOLON  */
#line 213 "parser.y"
        { printf("Function call statement\n"); }
#line 1460 "parser.tab.c"
    break;

  case 41: /* stmt: SEMICOLON  */
#line 215 "parser.y"
        { printf("Blank statement\n"); }
#line 1466 "parser.tab.c"
    break;

  case 53: /* return_opt: %empty  */
#line 255 "parser.y"
        { printf("No return statement\n"); }
#line 1472 "parser.tab.c"
    break;

  case 54: /* return_opt: KEYWORD_RETURN SEMICOLON  */
#line 257 "parser.y"
        { printf("Return statement with no value\n"); }
#line 1478 "parser.tab.c"
    break;

  case 55: /* return_opt: KEYWORD_RETURN expr SEMICOLON  */
#line 259 "parser.y"
        { printf("Return statement with value\n"); }
#line 1484 "parser.tab.c"
    break;

  case 82: /* range_expr: LEFT_BRACKET expr COLON expr RIGHT_BRACKET  */
#line 305 "parser.y"
        { printf("Range with start:stop\n"); }
#line 1490 "parser.tab.c"
    break;

  case 83: /* range_expr: LEFT_BRACKET expr COLON expr COLON expr RIGHT_BRACKET  */
#line 307 "parser.y"
        { printf("Range with start:stop:step\n"); }
#line 1496 "parser.tab.c"
    break;

  case 89: /* type: KEYWORD_INTEGER  */
#line 320 "parser.y"
        { printf("Type: integer\n"); }
#line 1502 "parser.tab.c"
    break;

  case 90: /* type: KEYWORD_SCALAR  */
#line 322 "parser.y"
        { printf("Type: scalar\n"); }
#line 1508 "parser.tab.c"
    break;

  case 91: /* type: KEYWORD_STR  */
#line 324 "parser.y"
        { printf("Type: string\n"); }
#line 1514 "parser.tab.c"
    break;

  case 92: /* type: KEYWORD_BOOL  */
#line 326 "parser.y"
        { printf("Type: boolean\n"); }
#line 1520 "parser.tab.c"
    break;

  case 93: /* type: KEYWORD_COMP  */
#line 328 "parser.y"
        { printf("Type: complex formula\n"); }
#line 1526 "parser.tab.c"
    break;

  case 94: /* type: IDENTIFIER  */
#line 330 "parser.y"
        { printf("Type: user-defined type %s\n", (yyvsp[0].stringVal)); }
#line 1532 "parser.tab.c"
    break;

  case 95: /* type: LEFT_BRACKET CONST_INT RIGHT_BRACKET COLON type  */
#line 332 "parser.y"
        { printf("Type: array of size %d\n", (yyvsp[-3].integerVal)); }
#line 1538 "parser.tab.c"
    break;

  case 96: /* type: LEFT_BRACKET RIGHT_BRACKET COLON type  */
#line 334 "parser.y"
        { printf("Type: array of unspecified size\n"); }
#line 1544 "parser.tab.c"
    break;


#line 1548 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 337 "parser.y"


int main() {
    if (yyparse() == 0) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }

    free_macro_table();

    return 0;
}
