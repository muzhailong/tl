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
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_block = 33,                     /* block  */
  YYSYMBOL_stmt = 34,                      /* stmt  */
  YYSYMBOL_var_decl = 35,                  /* var_decl  */
  YYSYMBOL_assign_stmt = 36,               /* assign_stmt  */
  YYSYMBOL_value_expr = 37,                /* value_expr  */
  YYSYMBOL_slice_expr = 38,                /* slice_expr  */
  YYSYMBOL_slice_lt = 39,                  /* slice_lt  */
  YYSYMBOL_lt_init = 40,                   /* lt_init  */
  YYSYMBOL_str_lt_init = 41,               /* str_lt_init  */
  YYSYMBOL_fp64_lt_init = 42,              /* fp64_lt_init  */
  YYSYMBOL_si64_lt_init = 43,              /* si64_lt_init  */
  YYSYMBOL_shape_lt = 44,                  /* shape_lt  */
  YYSYMBOL_si64_lt = 45,                   /* si64_lt  */
  YYSYMBOL_fp64_lt = 46,                   /* fp64_lt  */
  YYSYMBOL_str_lt = 47,                    /* str_lt  */
  YYSYMBOL_single_val = 48,                /* single_val  */
  YYSYMBOL_literal_val = 49                /* literal_val  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 12 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
       
    std::shared_ptr<common_impl::Node>programBlock; /* the top level root node of our final AST */
    extern int yylex();
    void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }

#line 159 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"

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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   79

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  78

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   105,   109,   112,   113,   116,   125,   135,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   154,   160,   165,   170,   175,   180,   190,   191,   192,
     193,   196,   199,   202,   205,   206,   209,   213,   219,   223,
     229,   233,   240,   241,   242,   245,   246,   247
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
  "SY_RIGHT_PAREN", "V_SI64", "V_FP64", "V_STR", "T_IDENTIFIER", "$accept",
  "program", "block", "stmt", "var_decl", "assign_stmt", "value_expr",
  "slice_expr", "slice_lt", "lt_init", "str_lt_init", "fp64_lt_init",
  "si64_lt_init", "shape_lt", "si64_lt", "fp64_lt", "str_lt", "single_val",
  "literal_val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,    36,    22,   -22,   -24,   -24,   -24,   -23,     4,    18,
     -24,   -24,   -24,   -24,   -24,    48,    -3,   -24,   -24,   -24,
     -24,    32,     8,    28,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -24,   -24,    40,   -23,    34,    44,
     -24,   -24,   -24,    42,    49,    39,    59,    59,   -24,   -24,
      29,    29,    29,    29,    29,    29,   -24,    12,   -24,   -24,
       0,    33,    37,   -24,   -24,    45,   -24,    28,   -24,   -24,
      43,   -24,    46,   -24,   -24,    53,   -24,   -24
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    34,     0,     2,     3,     5,     6,     0,     0,     0,
       1,     4,    45,    46,    47,    43,     0,    44,    10,    42,
      36,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    35,     0,     0,     0,     0,
      30,    29,    28,     0,    22,     0,    13,    14,    11,    12,
      15,    16,    17,    18,    19,    20,    37,     0,    38,    40,
       0,     0,     0,     7,    24,    23,    21,     0,     8,    33,
       0,    32,     0,    31,    25,    26,    39,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,    71,   -24,   -24,    13,   -24,     9,   -24,
     -24,   -24,   -24,   -24,    41,   -24,   -24,   -24,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,    16,    17,    45,    39,
      40,    41,    42,     9,    21,    61,    62,    18,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    25,    26,    27,    12,    13,    14,    15,     1,    28,
      29,    30,    31,    32,    33,    24,    25,    26,    27,    37,
      36,    34,    10,    69,    28,    29,    30,    31,    32,    33,
      38,    20,    24,    25,    26,    27,    68,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     7,    22,    43,
      57,    35,    36,    70,     8,    44,    71,    72,    66,    67,
      73,    20,    58,    59,    26,    27,    23,    56,    63,    64,
      65,    76,    74,    67,    11,    77,    75,     0,     0,    60
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    27,    28,    29,    30,    30,    12,
      13,    14,    15,    16,    17,     3,     4,     5,     6,    11,
      20,    24,     0,    23,    12,    13,    14,    15,    16,    17,
      22,    27,     3,     4,     5,     6,    24,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    11,    30,    21,
      37,    19,    20,    20,    18,    27,    23,    20,    19,    20,
      23,    27,    28,    29,     5,     6,    18,    27,    24,    27,
      21,    28,    27,    20,     3,    29,    67,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    11,    18,    44,
       0,    34,    27,    28,    29,    30,    37,    38,    48,    49,
      27,    45,    30,    18,     3,     4,     5,     6,    12,    13,
      14,    15,    16,    17,    24,    19,    20,    11,    22,    40,
      41,    42,    43,    21,    27,    39,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    27,    37,    28,    29,
      45,    46,    47,    24,    27,    21,    19,    20,    24,    23,
      20,    23,    20,    23,    27,    39,    28,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    39,    39,    39,    39,    39,    40,    40,    40,
      40,    41,    42,    43,    44,    44,    45,    45,    46,    46,
      47,    47,    48,    48,    48,    49,    49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     5,     6,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     2,     2,     3,     3,     0,     1,     1,
       1,     3,     3,     3,     0,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: block  */
#line 102 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                { programBlock.reset((yyvsp[0].block)); }
#line 1159 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 3: /* block: stmt  */
#line 105 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
             { 
                (yyval.block)=new common_impl::Block();
                (yyval.block)->AppendNode((yyvsp[0].node));
                }
#line 1168 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 4: /* block: block stmt  */
#line 109 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      { (yyvsp[-1].block)->AppendNode((yyvsp[0].node)); }
#line 1174 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 5: /* stmt: var_decl  */
#line 112 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
               {(yyval.node)=(yyvsp[0].var_decl_node);}
#line 1180 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 6: /* stmt: assign_stmt  */
#line 113 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {(yyval.node)=(yyvsp[0].assign_stmt);}
#line 1186 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 7: /* var_decl: T_IDENTIFIER shape_lt T_IDENTIFIER lt_init SY_SEMICOLON  */
#line 117 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
        {
            (yyval.var_decl_node)=new common_impl::VarDeclarationNode(
                (yyvsp[-4].token_info)->GetIdent(),
                (yyvsp[-3].si64_list_node),
                (yyvsp[-2].token_info)->GetIdent(),
                (yyvsp[-1].node)
            );
        }
#line 1199 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 8: /* var_decl: T_IDENTIFIER shape_lt T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON  */
#line 126 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
        {
            (yyval.var_decl_node)=new common_impl::VarDeclarationNode(
                (yyvsp[-5].token_info)->GetIdent(),
                (yyvsp[-4].si64_list_node),
                (yyvsp[-3].token_info)->GetIdent(),
                (yyvsp[-1].value_expr)
            );
        }
#line 1212 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 9: /* assign_stmt: T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON  */
#line 136 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.assign_stmt) = new common_impl::AssignStatement((yyvsp[-3].token_info)->GetIdent(),(yyvsp[-1].value_expr));
            }
#line 1220 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 10: /* value_expr: single_val  */
#line 141 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                         { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[0].node),-1,nullptr); }
#line 1226 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 11: /* value_expr: value_expr SY_MUL value_expr  */
#line 142 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                           { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1232 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 12: /* value_expr: value_expr SY_DIV value_expr  */
#line 143 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1238 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 13: /* value_expr: value_expr SY_PLUS value_expr  */
#line 144 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1244 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 14: /* value_expr: value_expr SY_MINUS value_expr  */
#line 145 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                              { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1250 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 15: /* value_expr: value_expr SY_CEQ value_expr  */
#line 146 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1256 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 16: /* value_expr: value_expr SY_CNE value_expr  */
#line 147 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1262 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 17: /* value_expr: value_expr SY_CGT value_expr  */
#line 148 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                           { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1268 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 18: /* value_expr: value_expr SY_CLT value_expr  */
#line 149 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1274 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 19: /* value_expr: value_expr SY_CGE value_expr  */
#line 150 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                            { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1280 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 20: /* value_expr: value_expr SY_CLE value_expr  */
#line 151 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                           { (yyval.value_expr)= new common_impl::ExpressionNode((yyvsp[-2].value_expr),(yyvsp[-1].token_info)->GetTokenId(),(yyvsp[0].value_expr));}
#line 1286 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 21: /* slice_expr: T_IDENTIFIER SY_LEFT_BRACKET slice_lt SY_RIGHT_BRACKET  */
#line 155 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_expr) = new common_impl::SliceExpression((yyvsp[-3].token_info)->GetIdent(),(yyvsp[-1].slice_list_node));
            }
#line 1294 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 22: /* slice_lt: V_SI64  */
#line 161 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList();
                (yyval.slice_list_node)->AppendIndex((yyvsp[0].token_info)->GetValue<int64_t>());
            }
#line 1303 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 23: /* slice_lt: V_SI64 SY_COLON  */
#line 166 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList();
                (yyval.slice_list_node)->AppendIndex((yyvsp[-1].token_info)->GetValue<int64_t>(),common_impl::SliceList::Position::TO_END);
            }
#line 1312 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 24: /* slice_lt: SY_COLON V_SI64  */
#line 171 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList();
                (yyval.slice_list_node)->AppendIndex(common_impl::SliceList::Position::TO_BEGIN,(yyvsp[-1].token_info)->GetValue<int64_t>());
            }
#line 1321 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 25: /* slice_lt: V_SI64 SY_COLON V_SI64  */
#line 176 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node)=new common_impl::SliceList();
                (yyval.slice_list_node)->AppendIndex((yyvsp[-2].token_info)->GetValue<int64_t>(),(yyvsp[0].token_info)->GetValue<int64_t>());
            }
#line 1330 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 26: /* slice_lt: slice_lt SY_COMMA slice_lt  */
#line 181 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
            {
                (yyval.slice_list_node) = new common_impl::SliceList();
                (yyval.slice_list_node)->AppendIndex((yyvsp[-2].slice_list_node),(yyvsp[0].slice_list_node));
                free((yyvsp[-2].slice_list_node));
                free((yyvsp[0].slice_list_node));
            }
#line 1341 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 27: /* lt_init: %empty  */
#line 190 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {(yyval.node)=nullptr;}
#line 1347 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 28: /* lt_init: si64_lt_init  */
#line 191 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      {(yyval.node)=(yyvsp[0].si64_list_node);}
#line 1353 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 29: /* lt_init: fp64_lt_init  */
#line 192 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                      {(yyval.node)=(yyvsp[0].fp64_list_node);}
#line 1359 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 30: /* lt_init: str_lt_init  */
#line 193 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                     {(yyval.node)=(yyvsp[0].str_list_node);}
#line 1365 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 31: /* str_lt_init: SY_LEFT_BRACE str_lt SY_RIGHT_BRACE  */
#line 196 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                                 {(yyval.str_list_node)=(yyvsp[-1].str_list_node);}
#line 1371 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 32: /* fp64_lt_init: SY_LEFT_BRACE fp64_lt SY_RIGHT_BRACE  */
#line 199 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                                    {(yyval.fp64_list_node)=(yyvsp[-1].fp64_list_node);}
#line 1377 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 33: /* si64_lt_init: SY_LEFT_BRACE si64_lt SY_RIGHT_BRACE  */
#line 202 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                                   {(yyval.si64_list_node)=(yyvsp[-1].si64_list_node);}
#line 1383 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 34: /* shape_lt: %empty  */
#line 205 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                  {(yyval.si64_list_node)=nullptr;}
#line 1389 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 35: /* shape_lt: SY_LEFT_BRACKET si64_lt SY_RIGHT_BRACKET  */
#line 206 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                                                   {(yyval.si64_list_node)=(yyvsp[-1].si64_list_node);}
#line 1395 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 36: /* si64_lt: V_SI64  */
#line 209 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                 {
                    (yyval.si64_list_node)=new common_impl::SI64ListNode();
                    (yyval.si64_list_node)->Append((yyvsp[0].token_info)->GetValue<int64_t>());
                }
#line 1404 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 37: /* si64_lt: si64_lt SY_COMMA V_SI64  */
#line 214 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyvsp[-2].si64_list_node)->Append((yyvsp[0].token_info)->GetValue<int64_t>());
                }
#line 1412 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 38: /* fp64_lt: V_FP64  */
#line 219 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyval.fp64_list_node)=new common_impl::FP64ListNode();
                    (yyval.fp64_list_node)->Append((yyvsp[0].token_info)->GetValue<double>());
                }
#line 1421 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 39: /* fp64_lt: fp64_lt SY_COMMA V_FP64  */
#line 224 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyvsp[-2].fp64_list_node)->Append((yyvsp[0].token_info)->GetValue<double>());
                }
#line 1429 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 40: /* str_lt: V_STR  */
#line 229 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
              {
                    (yyval.str_list_node)=new common_impl::STRListNode();
                    (yyval.str_list_node)->Append((yyvsp[0].token_info)->GetValue<std::string>());
                }
#line 1438 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 41: /* str_lt: str_lt SY_COMMA V_STR  */
#line 234 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                {
                    (yyvsp[-2].str_list_node)->Append((yyvsp[0].token_info)->GetValue<std::string>());
                }
#line 1446 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 42: /* single_val: literal_val  */
#line 240 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        { (yyval.node)=(yyvsp[0].node);}
#line 1452 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 43: /* single_val: T_IDENTIFIER  */
#line 241 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                           {(yyval.node) =new common_impl::IdentifierNode((yyvsp[0].token_info)->GetIdent()); }
#line 1458 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 44: /* single_val: slice_expr  */
#line 242 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                         {(yyval.node)=(yyvsp[0].slice_expr);}
#line 1464 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 45: /* literal_val: V_SI64  */
#line 245 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        {(yyval.node) = new common_impl::SI64Node((yyvsp[0].token_info)->GetValue<int64_t>());}
#line 1470 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 46: /* literal_val: V_FP64  */
#line 246 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        {(yyval.node) = new common_impl::FP64Node((yyvsp[0].token_info)->GetValue<double>());}
#line 1476 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;

  case 47: /* literal_val: V_STR  */
#line 247 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"
                        {(yyval.node) = new common_impl::StrNode((yyvsp[0].token_info)->GetValue<std::string>());}
#line 1482 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"
    break;


#line 1486 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.cpp"

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

#line 249 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"

