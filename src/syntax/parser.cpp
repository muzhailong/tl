/* A Bison parser, made by GNU Bison 3.8.  */

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
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SY_PLUS = 3,                    /* SY_PLUS  */
  YYSYMBOL_SY_MINUS = 4,                   /* SY_MINUS  */
  YYSYMBOL_SY_MUL = 5,                     /* SY_MUL  */
  YYSYMBOL_SY_DIV = 6,                     /* SY_DIV  */
  YYSYMBOL_BOP_PLUS = 7,                   /* BOP_PLUS  */
  YYSYMBOL_BOP_MINUS = 8,                  /* BOP_MINUS  */
  YYSYMBOL_BOP_MUL = 9,                    /* BOP_MUL  */
  YYSYMBOL_BOP_DIV = 10,                   /* BOP_DIV  */
  YYSYMBOL_SY_EQUAL = 11,                  /* SY_EQUAL  */
  YYSYMBOL_SY_CEQ = 12,                    /* SY_CEQ  */
  YYSYMBOL_SY_CNE = 13,                    /* SY_CNE  */
  YYSYMBOL_SY_CGT = 14,                    /* SY_CGT  */
  YYSYMBOL_SY_CLT = 15,                    /* SY_CLT  */
  YYSYMBOL_SY_CGE = 16,                    /* SY_CGE  */
  YYSYMBOL_SY_CLE = 17,                    /* SY_CLE  */
  YYSYMBOL_SY_LEFT_BRACKET = 18,           /* SY_LEFT_BRACKET  */
  YYSYMBOL_SY_RIGHT_BRACKET = 19,          /* SY_RIGHT_BRACKET  */
  YYSYMBOL_SY_COMMA = 20,                  /* SY_COMMA  */
  YYSYMBOL_SY_COLON = 21,                  /* SY_COLON  */
  YYSYMBOL_SY_LEFT_BRACE = 22,             /* SY_LEFT_BRACE  */
  YYSYMBOL_SY_RIGHT_BRACE = 23,            /* SY_RIGHT_BRACE  */
  YYSYMBOL_SY_SEMICOLON = 24,              /* SY_SEMICOLON  */
  YYSYMBOL_SY_LEFT_PAREN = 25,             /* SY_LEFT_PAREN  */
  YYSYMBOL_SY_RIGHT_PAREN = 26,            /* SY_RIGHT_PAREN  */
  YYSYMBOL_V_SI64 = 27,                    /* V_SI64  */
  YYSYMBOL_V_FP64 = 28,                    /* V_FP64  */
  YYSYMBOL_V_STR = 29,                     /* V_STR  */
  YYSYMBOL_T_IDENTIFIER = 30,              /* T_IDENTIFIER  */
  YYSYMBOL_KW_IF = 31,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 32,                   /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 33,                  /* KW_WHILE  */
  YYSYMBOL_KW_RETURN = 34,                 /* KW_RETURN  */
  YYSYMBOL_KW_BREAK = 35,                  /* KW_BREAK  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_module = 38,                    /* module  */
  YYSYMBOL_block = 39,                     /* block  */
  YYSYMBOL_stmt = 40,                      /* stmt  */
  YYSYMBOL_var_decl = 41,                  /* var_decl  */
  YYSYMBOL_assign_stmt = 42,               /* assign_stmt  */
  YYSYMBOL_if_else_stmt = 43,              /* if_else_stmt  */
  YYSYMBOL_while_stmt = 44,                /* while_stmt  */
  YYSYMBOL_func_decl = 45,                 /* func_decl  */
  YYSYMBOL_return_stmt = 46,               /* return_stmt  */
  YYSYMBOL_break_stmt = 47,                /* break_stmt  */
  YYSYMBOL_formal_args_lt_with_empty = 48, /* formal_args_lt_with_empty  */
  YYSYMBOL_if_sub_stmt = 49,               /* if_sub_stmt  */
  YYSYMBOL_func_call = 50,                 /* func_call  */
  YYSYMBOL_actual_args_lt_with_empty = 51, /* actual_args_lt_with_empty  */
  YYSYMBOL_value_expr_with_empty = 52,     /* value_expr_with_empty  */
  YYSYMBOL_value_expr = 53,                /* value_expr  */
  YYSYMBOL_slice_expr = 54,                /* slice_expr  */
  YYSYMBOL_slice_lt = 55,                  /* slice_lt  */
  YYSYMBOL_lt_init_with_empty = 56,        /* lt_init_with_empty  */
  YYSYMBOL_str_lt_init = 57,               /* str_lt_init  */
  YYSYMBOL_fp64_lt_init = 58,              /* fp64_lt_init  */
  YYSYMBOL_si64_lt_init = 59,              /* si64_lt_init  */
  YYSYMBOL_shape_lt_with_empty = 60,       /* shape_lt_with_empty  */
  YYSYMBOL_si64_lt = 61,                   /* si64_lt  */
  YYSYMBOL_fp64_lt = 62,                   /* fp64_lt  */
  YYSYMBOL_str_lt = 63,                    /* str_lt  */
  YYSYMBOL_single_val = 64,                /* single_val  */
  YYSYMBOL_literal_val = 65                /* literal_val  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 13 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
       
    std::shared_ptr<common_impl::ModuleNode>program; /* the top level root node of our final AST */
    extern int yylex();
    void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }

#line 175 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   131,   137,   144,   148,   151,   152,   153,
     154,   155,   156,   159,   173,   189,   202,   203,   216,   229,
     244,   256,   264,   265,   280,   294,   304,   311,   324,   325,
     333,   344,   345,   348,   359,   371,   383,   395,   407,   419,
     431,   443,   455,   467,   481,   495,   503,   514,   525,   537,
     549,   560,   561,   562,   563,   567,   575,   583,   591,   592,
     600,   607,   617,   624,   634,   641,   652,   653,   661,   662,
     666,   674,   682
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
  "\"end of file\"", "error", "\"invalid token\"", "SY_PLUS", "SY_MINUS",
  "SY_MUL", "SY_DIV", "BOP_PLUS", "BOP_MINUS", "BOP_MUL", "BOP_DIV",
  "SY_EQUAL", "SY_CEQ", "SY_CNE", "SY_CGT", "SY_CLT", "SY_CGE", "SY_CLE",
  "SY_LEFT_BRACKET", "SY_RIGHT_BRACKET", "SY_COMMA", "SY_COLON",
  "SY_LEFT_BRACE", "SY_RIGHT_BRACE", "SY_SEMICOLON", "SY_LEFT_PAREN",
  "SY_RIGHT_PAREN", "V_SI64", "V_FP64", "V_STR", "T_IDENTIFIER", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_RETURN", "KW_BREAK", "$accept", "program",
  "module", "block", "stmt", "var_decl", "assign_stmt", "if_else_stmt",
  "while_stmt", "func_decl", "return_stmt", "break_stmt",
  "formal_args_lt_with_empty", "if_sub_stmt", "func_call",
  "actual_args_lt_with_empty", "value_expr_with_empty", "value_expr",
  "slice_expr", "slice_lt", "lt_init_with_empty", "str_lt_init",
  "fp64_lt_init", "si64_lt_init", "shape_lt_with_empty", "si64_lt",
  "fp64_lt", "str_lt", "single_val", "literal_val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,     7,    46,   -17,   -74,    64,    62,   -74,   -74,   -74,
      -9,    82,   -74,    89,    85,   -74,     7,   115,    90,   101,
     108,   -74,     7,   120,   113,    59,   131,   135,    32,   121,
      79,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   132,   -74,
      32,   133,    32,    32,   -74,   -74,   -74,   114,   -74,   137,
       2,   -74,   -74,   -74,   -74,   -74,   -74,   -10,    69,    -2,
      37,    52,   119,    32,   -74,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,   120,   -74,   -74,    32,   130,
     138,   -74,   -74,   -74,   143,   144,   140,   147,     3,   122,
       2,    74,    74,   -74,   -74,   100,   100,   100,   100,   100,
     100,    88,    84,   -74,   -74,    25,   124,   129,   -74,   120,
     120,   -74,   142,   -74,   119,    32,   -74,   -74,   -74,   -74,
     145,   -74,   141,   -74,    94,   103,   -74,   -74,     2,   -74,
     -74,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    58,     0,     2,     3,     0,     0,     1,     4,    60,
       0,     0,    59,     0,    22,    61,    58,     0,     0,     0,
       0,    23,    58,     0,     0,    58,     0,     0,    31,     0,
       0,     5,     7,     8,     9,    10,    11,    12,    16,    24,
       0,     0,     0,     0,    70,    71,    72,    67,    69,     0,
      32,    68,    33,    66,    21,    19,     6,     0,     0,    51,
       0,     0,     0,    28,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    15,     0,     0,
       0,    54,    53,    52,     0,     0,    48,    45,     0,     0,
      29,    36,    37,    34,    35,    38,    39,    40,    41,    42,
      43,     0,     0,    62,    64,     0,     0,     0,    13,     0,
       0,    47,    46,    44,     0,     0,    27,    17,    14,    57,
       0,    56,     0,    55,     0,     0,    49,    50,    30,    63,
      65,    25,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -73,   -30,   -74,   -74,   -74,   -74,   168,
     -74,   -74,   -74,   117,   -74,   -74,   -74,   -39,   -74,    58,
     -74,   -74,   -74,   -74,    22,    96,   -74,   -74,   -74,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    30,    31,    32,    33,    34,    35,     4,
      36,    37,    17,    38,    48,    89,    49,    50,    51,    88,
      80,    81,    82,    83,     6,    10,   106,   107,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    58,   101,    60,    61,    65,    66,    67,    68,    78,
      12,    13,    75,     1,    69,    70,    71,    72,    73,    74,
      79,    26,   113,   114,    90,     5,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   124,   125,    18,   102,
      65,    66,    67,    68,    24,    13,     7,    41,   119,    69,
      70,    71,    72,    73,    74,    65,    66,    67,    68,    44,
      45,    46,    47,    84,    69,    70,    71,    72,    73,    74,
      40,    56,    65,    66,    67,    68,   128,     5,    85,    67,
      68,    69,    70,    71,    72,    73,    74,    65,    66,    67,
      68,     9,    11,    77,    56,    56,    69,    70,    71,    72,
      73,    74,    55,    65,    66,    67,    68,    14,   118,    25,
      26,   117,    27,    28,    29,    16,    15,   131,    25,    26,
      21,    27,    28,    29,    25,    26,   132,    27,    28,    29,
      23,    22,    62,    25,    26,    19,    27,    28,    29,    63,
      86,    20,   115,    39,   120,    54,    87,   121,   116,   122,
      25,    26,   123,    27,    28,    29,    42,     9,   103,   104,
      43,    64,   108,    59,    57,   109,   110,   111,   112,   126,
     130,     8,   127,   129,    76,   105
};

static const yytype_int8 yycheck[] =
{
      30,    40,    75,    42,    43,     3,     4,     5,     6,    11,
      19,    20,    22,    30,    12,    13,    14,    15,    16,    17,
      22,    31,    19,    20,    63,    18,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   109,   110,    16,    78,
       3,     4,     5,     6,    22,    20,     0,    25,    23,    12,
      13,    14,    15,    16,    17,     3,     4,     5,     6,    27,
      28,    29,    30,    26,    12,    13,    14,    15,    16,    17,
      11,   101,     3,     4,     5,     6,   115,    18,    26,     5,
       6,    12,    13,    14,    15,    16,    17,     3,     4,     5,
       6,    27,    30,    24,   124,   125,    12,    13,    14,    15,
      16,    17,    23,     3,     4,     5,     6,    25,    24,    30,
      31,    23,    33,    34,    35,    30,    27,    23,    30,    31,
      30,    33,    34,    35,    30,    31,    23,    33,    34,    35,
      22,    30,    18,    30,    31,    20,    33,    34,    35,    25,
      21,    26,    20,    30,    20,    24,    27,    23,    26,    20,
      30,    31,    23,    33,    34,    35,    25,    27,    28,    29,
      25,    24,    24,    30,    32,    22,    22,    27,    21,    27,
      29,     3,   114,    28,    57,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    37,    38,    45,    18,    60,     0,    45,    27,
      61,    30,    19,    20,    25,    27,    30,    48,    60,    20,
      26,    30,    30,    22,    60,    30,    31,    33,    34,    35,
      39,    40,    41,    42,    43,    44,    46,    47,    49,    30,
      11,    60,    25,    25,    27,    28,    29,    30,    50,    52,
      53,    54,    64,    65,    24,    23,    40,    32,    53,    30,
      53,    53,    18,    25,    24,     3,     4,     5,     6,    12,
      13,    14,    15,    16,    17,    22,    49,    24,    11,    22,
      56,    57,    58,    59,    26,    26,    21,    27,    55,    51,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    39,    53,    28,    29,    61,    62,    63,    24,    22,
      22,    27,    21,    19,    20,    20,    26,    23,    24,    23,
      20,    23,    20,    23,    39,    39,    27,    55,    53,    28,
      29,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    40,
      40,    40,    40,    41,    41,    42,    43,    43,    44,    45,
      46,    47,    48,    48,    48,    49,    49,    50,    51,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    57,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     5,     6,     4,     1,     5,     7,     9,
       3,     2,     0,     3,     5,     7,     3,     4,     0,     1,
       3,     0,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     2,     2,     1,     3,
       3,     0,     1,     1,     1,     3,     3,     3,     0,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1
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
  case 2: /* program: module  */
#line 129 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 { program.reset((yyvsp[0].module));}
#line 1229 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 3: /* module: func_decl  */
#line 132 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.module) = new common_impl::ModuleNode(
                        "module",(yyvsp[0].func_decl)->GetLocation());
                    (yyval.module)->Append((yyvsp[0].func_decl)); 
                }
#line 1239 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 4: /* module: module func_decl  */
#line 138 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.module) = (yyvsp[-1].module);
                    (yyval.module)->Append((yyvsp[0].func_decl));
                }
#line 1248 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 5: /* block: stmt  */
#line 144 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
             { 
                (yyval.block)=new common_impl::Block("block",(yyvsp[0].node)->GetLocation());
                (yyval.block)->Append((yyvsp[0].node));
                }
#line 1257 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 6: /* block: block stmt  */
#line 148 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      { (yyvsp[-1].block)->Append((yyvsp[0].node)); }
#line 1263 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 7: /* stmt: var_decl  */
#line 151 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
               {(yyval.node)=(yyvsp[0].var_decl_node);}
#line 1269 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 8: /* stmt: assign_stmt  */
#line 152 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {(yyval.node)=(yyvsp[0].assign_stmt);}
#line 1275 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 9: /* stmt: if_else_stmt  */
#line 153 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                   {(yyval.node)=(yyvsp[0].if_else_stmt);}
#line 1281 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 10: /* stmt: while_stmt  */
#line 154 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {(yyval.node)=(yyvsp[0].while_stmt);}
#line 1287 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 11: /* stmt: return_stmt  */
#line 155 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                  {(yyval.node)=(yyvsp[0].return_stmt);}
#line 1293 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 12: /* stmt: break_stmt  */
#line 156 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {(yyval.node)=(yyvsp[0].break_stmt);}
#line 1299 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 13: /* var_decl: T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER lt_init_with_empty SY_SEMICOLON  */
#line 160 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
        {
            common_impl::Location loc=(yyvsp[-4].token_info)->GetLocation();
            loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
            (yyval.var_decl_node)=new common_impl::VarDeclarationNode(
                "var_decl",
                loc,
                (yyvsp[-4].token_info)->GetIdent(),
                std::shared_ptr<common_impl::SI64ListNode>((yyvsp[-3].si64_list_node)),
                (yyvsp[-2].token_info)->GetIdent(),
                std::shared_ptr<common_impl::Node>((yyvsp[-1].node)),
                nullptr
            );
        }
#line 1317 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 14: /* var_decl: T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON  */
#line 174 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
        {
            common_impl::Location loc=(yyvsp[-5].token_info)->GetLocation();
            loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
            (yyval.var_decl_node)=new common_impl::VarDeclarationNode(
                "var_decl",
                loc,
                (yyvsp[-5].token_info)->GetIdent(),
                std::shared_ptr<common_impl::SI64ListNode>((yyvsp[-4].si64_list_node)),
                (yyvsp[-3].token_info)->GetIdent(),
                nullptr,
                std::shared_ptr<common_impl::ExpressionNode>((yyvsp[-1].value_expr))
            );
        }
#line 1335 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 15: /* assign_stmt: T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON  */
#line 190 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc=(yyvsp[-3].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.assign_stmt) = new common_impl::AssignStatement(
                    "assign_stmt",
                    loc,
                    (yyvsp[-3].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::ExpressionNode>((yyvsp[-1].value_expr))
                );
            }
#line 1350 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 16: /* if_else_stmt: if_sub_stmt  */
#line 202 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                          { (yyval.if_else_stmt)=(yyvsp[0].if_else_stmt);}
#line 1356 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 17: /* if_else_stmt: if_sub_stmt KW_ELSE SY_LEFT_BRACE block SY_RIGHT_BRACE  */
#line 204 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc=(yyvsp[-4].if_else_stmt)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.if_else_stmt) = new common_impl::IfElseStatement(
                    "ifelse_stmt",
                    loc
                );
                (yyval.if_else_stmt)->Append((yyvsp[-4].if_else_stmt));
                (yyval.if_else_stmt)->Append(nullptr,(yyvsp[-1].block));
            }
#line 1371 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 18: /* while_stmt: KW_WHILE SY_LEFT_PAREN value_expr SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE  */
#line 217 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc=(yyvsp[-6].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.while_stmt) = new common_impl::WhileStatement(
                    "while_stmt",
                    loc,
                    std::shared_ptr<common_impl::ExpressionNode>((yyvsp[-4].value_expr)),
                    std::shared_ptr<common_impl::Block>((yyvsp[-1].block))
                );
            }
#line 1386 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 19: /* func_decl: T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER SY_LEFT_PAREN formal_args_lt_with_empty SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE  */
#line 230 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                auto loc=(yyvsp[-8].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.func_decl) = new common_impl::FunctionDeclaration(
                    "func_decl",
                    loc,
                    (yyvsp[-8].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>((yyvsp[-7].si64_list_node)),
                    (yyvsp[-6].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::ArgumentList>((yyvsp[-4].arg_list)),
                    std::shared_ptr<common_impl::Block>((yyvsp[-1].block))
                );
            }
#line 1404 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 20: /* return_stmt: KW_RETURN value_expr_with_empty SY_SEMICOLON  */
#line 245 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc = (yyvsp[-2].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.return_stmt) = new common_impl::ReturnStatement(
                    "return_stmt",
                    loc,
                    std::shared_ptr<common_impl::ExpressionNode>((yyvsp[-1].value_expr))
                );
            }
#line 1418 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 21: /* break_stmt: KW_BREAK SY_SEMICOLON  */
#line 257 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                auto loc=(yyvsp[-1].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.break_stmt)=new common_impl::BreakStatement("break_stmt",loc);
            }
#line 1428 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 22: /* formal_args_lt_with_empty: %empty  */
#line 264 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                    {(yyval.arg_list)=nullptr;}
#line 1434 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 23: /* formal_args_lt_with_empty: T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER  */
#line 266 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            { 
                auto loc=(yyvsp[-2].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.arg_list)= new common_impl::ArgumentList(
                    "arg",
                    loc
                );
                (yyval.arg_list)->Append(
                    (yyvsp[-2].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>((yyvsp[-1].si64_list_node)),
                    (yyvsp[0].token_info)->GetIdent(),
                    loc
                );
            }
#line 1453 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 24: /* formal_args_lt_with_empty: formal_args_lt_with_empty SY_COMMA T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER  */
#line 281 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc = (yyvsp[-4].arg_list)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.arg_list) = (yyvsp[-4].arg_list);
                (yyval.arg_list)->Append(
                    (yyvsp[-2].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>((yyvsp[-1].si64_list_node)),
                    (yyvsp[0].token_info)->GetIdent(),
                    loc    
                );
            }
#line 1469 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 25: /* if_sub_stmt: KW_IF SY_LEFT_PAREN value_expr SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE  */
#line 295 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                auto loc = (yyvsp[-6].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.if_else_stmt) = new common_impl::IfElseStatement(
                    "ifelse+_stmt",
                    loc
                );
                (yyval.if_else_stmt)->Append((yyvsp[-4].value_expr),(yyvsp[-1].block));
            }
#line 1483 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 26: /* if_sub_stmt: if_sub_stmt KW_ELSE if_sub_stmt  */
#line 305 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.if_else_stmt) = (yyvsp[-2].if_else_stmt);
                (yyval.if_else_stmt) -> Append((yyvsp[0].if_else_stmt));
            }
#line 1492 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 27: /* func_call: T_IDENTIFIER SY_LEFT_PAREN actual_args_lt_with_empty SY_RIGHT_PAREN  */
#line 312 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc=(yyvsp[-3].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());
                (yyval.func_call)=new common_impl::FunctionCall(
                    "func_call",
                    loc,
                    (yyvsp[-3].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::ExpressionList>((yyvsp[-1].expr_list))
                );
            }
#line 1507 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 28: /* actual_args_lt_with_empty: %empty  */
#line 324 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                   {(yyval.expr_list)=nullptr;}
#line 1513 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 29: /* actual_args_lt_with_empty: value_expr  */
#line 326 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.expr_list)=new common_impl::ExpressionList(
                    "expr_lt",
                    (yyvsp[0].value_expr)->GetLocation()
                );
                (yyval.expr_list)->Append((yyvsp[0].value_expr));
            }
#line 1525 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 30: /* actual_args_lt_with_empty: actual_args_lt_with_empty SY_COMMA value_expr  */
#line 334 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.expr_list)=new common_impl::ExpressionList(
                    "expr_lt",
                    (yyvsp[-2].expr_list)->GetLocation()
                );
                (yyval.expr_list)->Append((yyvsp[-2].expr_list));
                (yyval.expr_list)->Append((yyvsp[0].value_expr));
            }
#line 1538 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 31: /* value_expr_with_empty: %empty  */
#line 344 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                               {(yyval.value_expr)=nullptr;}
#line 1544 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 32: /* value_expr_with_empty: value_expr  */
#line 345 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                    {(yyval.value_expr)=(yyvsp[0].value_expr);}
#line 1550 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 33: /* value_expr: single_val  */
#line 349 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc = (yyvsp[0].node)->GetLocation();
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[0].node)),
                        -1,
                        nullptr
                    ); 
                }
#line 1565 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 34: /* value_expr: value_expr SY_MUL value_expr  */
#line 360 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1581 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 35: /* value_expr: value_expr SY_DIV value_expr  */
#line 372 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                { 
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1597 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 36: /* value_expr: value_expr SY_PLUS value_expr  */
#line 384 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1613 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 37: /* value_expr: value_expr SY_MINUS value_expr  */
#line 396 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                { 
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1629 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 38: /* value_expr: value_expr SY_CEQ value_expr  */
#line 408 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1645 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 39: /* value_expr: value_expr SY_CNE value_expr  */
#line 420 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1661 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 40: /* value_expr: value_expr SY_CGT value_expr  */
#line 432 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1677 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 41: /* value_expr: value_expr SY_CLT value_expr  */
#line 444 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1693 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 42: /* value_expr: value_expr SY_CGE value_expr  */
#line 456 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1709 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 43: /* value_expr: value_expr SY_CLE value_expr  */
#line 468 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                { 
                    common_impl::Location loc=(yyvsp[-2].value_expr)->GetLocation();
                    loc.UpdateLocation((yyvsp[0].value_expr)->GetLocation());
                    (yyval.value_expr)= new common_impl::ExpressionNode(
                        "expr",
                        loc,
                        std::shared_ptr<common_impl::Node>((yyvsp[-2].value_expr)),
                        (yyvsp[-1].token_info)->GetTokenId(),
                        std::shared_ptr<common_impl::Node>((yyvsp[0].value_expr))
                    );
                }
#line 1725 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 44: /* slice_expr: T_IDENTIFIER SY_LEFT_BRACKET slice_lt SY_RIGHT_BRACKET  */
#line 482 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                common_impl::Location loc = (yyvsp[-3].token_info)->GetLocation();
                loc.UpdateLocation((yyvsp[0].token_info)->GetLocation());

                (yyval.slice_expr) = new common_impl::SliceExpression(
                    std::string("slice_expr"),
                    loc,
                    (yyvsp[-3].token_info)->GetIdent(),
                    std::shared_ptr<common_impl::SliceList>((yyvsp[-1].slice_list_node))
                );
            }
#line 1741 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 45: /* slice_lt: V_SI64  */
#line 496 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node) = new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[0].token_info)->GetLocation()
                );
                (yyval.slice_list_node)->Append((yyvsp[0].token_info)->GetValue<int64_t>(),(yyvsp[0].token_info)->GetLocation());
            }
#line 1753 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 46: /* slice_lt: V_SI64 SY_COLON  */
#line 504 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[0].token_info)->GetLocation()
                );
                (yyval.slice_list_node)->Append(
                        (yyvsp[-1].token_info)->GetValue<int64_t>(),common_impl::SliceList::Position::TO_END,
                        (yyvsp[-1].token_info)->GetLocation()
                    );
            }
#line 1768 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 47: /* slice_lt: SY_COLON V_SI64  */
#line 515 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[-1].token_info)->GetLocation()
                );
                (yyval.slice_list_node)->Append(
                    common_impl::SliceList::Position::TO_BEGIN,(yyvsp[0].token_info)->GetValue<int64_t>(),
                    (yyvsp[0].token_info)->GetLocation()
                );
            }
#line 1783 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 48: /* slice_lt: SY_COLON  */
#line 526 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[0].token_info)->GetLocation()
                );
                (yyval.slice_list_node)->Append(
                    common_impl::SliceList::Position::TO_BEGIN,
                    common_impl::SliceList::Position::TO_END,
                    (yyvsp[0].token_info)->GetLocation()
                );
            }
#line 1799 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 49: /* slice_lt: V_SI64 SY_COLON V_SI64  */
#line 538 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[-2].token_info)->GetLocation()
                );
                (yyval.slice_list_node)->Append(
                    (yyvsp[-2].token_info)->GetValue<int64_t>(),
                    (yyvsp[0].token_info)->GetValue<int64_t>(),
                    (yyvsp[0].token_info)->GetLocation()
                );
            }
#line 1815 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 50: /* slice_lt: slice_lt SY_COMMA slice_lt  */
#line 550 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node) = new common_impl::SliceList(
                    std::string("slice_lt"),
                    (yyvsp[-2].slice_list_node)->GetLocation()
                );
                (yyval.slice_list_node)->Append((yyvsp[-2].slice_list_node),(yyvsp[0].slice_list_node));
            }
#line 1827 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 51: /* lt_init_with_empty: %empty  */
#line 560 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                            {(yyval.node)=nullptr;}
#line 1833 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 52: /* lt_init_with_empty: si64_lt_init  */
#line 561 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      {(yyval.node)=(yyvsp[0].si64_list_node);}
#line 1839 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 53: /* lt_init_with_empty: fp64_lt_init  */
#line 562 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      {(yyval.node)=(yyvsp[0].fp64_list_node);}
#line 1845 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 54: /* lt_init_with_empty: str_lt_init  */
#line 563 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                     {(yyval.node)=(yyvsp[0].str_list_node);}
#line 1851 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 55: /* str_lt_init: SY_LEFT_BRACE str_lt SY_RIGHT_BRACE  */
#line 568 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.str_list_node) = (yyvsp[-1].str_list_node);
                    (yyval.str_list_node)->GetLocation().UpdateLocation((yyvsp[-2].token_info)->GetLocation());
                    (yyval.str_list_node)->GetLocation().UpdateLocation((yyvsp[0].token_info)->GetLocation());
                }
#line 1861 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 56: /* fp64_lt_init: SY_LEFT_BRACE fp64_lt SY_RIGHT_BRACE  */
#line 576 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.fp64_list_node) = (yyvsp[-1].fp64_list_node);
                    (yyval.fp64_list_node)->GetLocation().UpdateLocation((yyvsp[-2].token_info)->GetLocation());
                    (yyval.fp64_list_node)->GetLocation().UpdateLocation((yyvsp[0].token_info)->GetLocation());
                }
#line 1871 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 57: /* si64_lt_init: SY_LEFT_BRACE si64_lt SY_RIGHT_BRACE  */
#line 584 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.si64_list_node) = (yyvsp[-1].si64_list_node);
                    (yyval.si64_list_node)->GetLocation().UpdateLocation((yyvsp[-2].token_info)->GetLocation());
                    (yyval.si64_list_node)->GetLocation().UpdateLocation((yyvsp[0].token_info)->GetLocation());
                }
#line 1881 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 58: /* shape_lt_with_empty: %empty  */
#line 591 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                             {(yyval.si64_list_node)=nullptr;}
#line 1887 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 59: /* shape_lt_with_empty: SY_LEFT_BRACKET si64_lt SY_RIGHT_BRACKET  */
#line 593 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.si64_list_node) = (yyvsp[-1].si64_list_node);
                    (yyval.si64_list_node)->GetLocation().UpdateLocation((yyvsp[-2].token_info)->GetLocation());
                    (yyval.si64_list_node)->GetLocation().UpdateLocation((yyvsp[0].token_info)->GetLocation());
                }
#line 1897 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 60: /* si64_lt: V_SI64  */
#line 600 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {
                    (yyval.si64_list_node)=new common_impl::SI64ListNode(
                        "si64_lt",
                        (yyvsp[0].token_info)->GetLocation()
                    );
                    (yyval.si64_list_node)->Append((yyvsp[0].token_info)->GetValue<int64_t>(),(yyvsp[0].token_info)->GetLocation());
                }
#line 1909 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 61: /* si64_lt: si64_lt SY_COMMA V_SI64  */
#line 608 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.si64_list_node) = (yyvsp[-2].si64_list_node);
                    (yyvsp[-2].si64_list_node)->Append(
                        (yyvsp[0].token_info)->GetValue<int64_t>(),
                        (yyvsp[0].token_info)->GetLocation()
                    );
                }
#line 1921 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 62: /* fp64_lt: V_FP64  */
#line 617 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.fp64_list_node)=new common_impl::FP64ListNode(
                        "fp64_list",
                        (yyvsp[0].token_info)->GetLocation()
                    );
                    (yyval.fp64_list_node)->Append((yyvsp[0].token_info)->GetValue<double>(),(yyvsp[0].token_info)->GetLocation());
                }
#line 1933 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 63: /* fp64_lt: fp64_lt SY_COMMA V_FP64  */
#line 625 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.fp64_list_node) = (yyvsp[-2].fp64_list_node);
                    (yyvsp[-2].fp64_list_node)->Append(
                            (yyvsp[0].token_info)->GetValue<double>(),
                            (yyvsp[0].token_info)->GetLocation()
                        );
                }
#line 1945 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 64: /* str_lt: V_STR  */
#line 634 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
              {
                    (yyval.str_list_node)=new common_impl::STRListNode(
                        "str_list",
                        (yyvsp[0].token_info)->GetLocation()
                    );
                    (yyval.str_list_node)->Append((yyvsp[0].token_info)->GetValue<std::string>(),(yyvsp[0].token_info)->GetLocation());
                }
#line 1957 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 65: /* str_lt: str_lt SY_COMMA V_STR  */
#line 642 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.str_list_node) = (yyvsp[-2].str_list_node);
                    (yyvsp[-2].str_list_node)->Append(
                            (yyvsp[0].token_info)->GetValue<std::string>(),
                            (yyvsp[-2].str_list_node)->GetLocation()
                        );
                }
#line 1969 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 66: /* single_val: literal_val  */
#line 652 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        { (yyval.node)=(yyvsp[0].node);}
#line 1975 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 67: /* single_val: T_IDENTIFIER  */
#line 654 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.node) =new common_impl::IdentifierNode(
                            "identifier",
                            (yyvsp[0].token_info)->GetLocation(),
                            (yyvsp[0].token_info)->GetIdent()
                        ); 
                }
#line 1987 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 68: /* single_val: slice_expr  */
#line 661 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                         {(yyval.node)=(yyvsp[0].slice_expr);}
#line 1993 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 69: /* single_val: func_call  */
#line 662 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        {(yyval.node)=(yyvsp[0].func_call);}
#line 1999 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 70: /* literal_val: V_SI64  */
#line 667 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.node) = new common_impl::SI64Node(
                        std::string("si64"),
                        (yyvsp[0].token_info)->GetLocation(),
                        (yyvsp[0].token_info)->GetValue<int64_t>()
                    );
                }
#line 2011 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 71: /* literal_val: V_FP64  */
#line 675 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.node) = new common_impl::FP64Node(
                        std::string("fp64"),
                        (yyvsp[0].token_info)->GetLocation(),
                        (yyvsp[0].token_info)->GetValue<double>()
                    );
                }
#line 2023 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 72: /* literal_val: V_STR  */
#line 683 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.node) = new common_impl::StrNode(
                        std::string("str"),
                        (yyvsp[0].token_info)->GetLocation(),
                        (yyvsp[0].token_info)->GetValue<std::string>()
                    );
                }
#line 2035 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;


#line 2039 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"

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

#line 691 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"

