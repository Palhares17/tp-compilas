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
#line 1 "./src/yacc.y"

    #include "./src/arvore.h"
    #include "./src/tabela.h"
    #include "./src/lib.h"
    #include "y.tab.h"
    void defineDataType();
    char dataType[18];
    void handleError(const char *str);

#line 81 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    VOID = 258,                    /* VOID  */
    CHARACTER = 259,               /* CHARACTER  */
    PRINT = 260,                   /* PRINT  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    CHAR = 263,                    /* CHAR  */
    FOR = 264,                     /* FOR  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    TRUE = 267,                    /* TRUE  */
    FALSE = 268,                   /* FALSE  */
    NUMBER = 269,                  /* NUMBER  */
    FLOAT_NUM = 270,               /* FLOAT_NUM  */
    ID = 271,                      /* ID  */
    LE = 272,                      /* LE  */
    GE = 273,                      /* GE  */
    EQ = 274,                      /* EQ  */
    NE = 275,                      /* NE  */
    GT = 276,                      /* GT  */
    LT = 277,                      /* LT  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    STR = 280,                     /* STR  */
    ADD = 281,                     /* ADD  */
    MULTIPLY = 282,                /* MULTIPLY  */
    DIVIDE = 283,                  /* DIVIDE  */
    SUBTRACT = 284,                /* SUBTRACT  */
    UNARY = 285,                   /* UNARY  */
    RETURN = 286,                  /* RETURN  */
    WHILE = 287,                   /* WHILE  */
    FUNCTION = 288,                /* FUNCTION  */
    CONST = 289,                   /* CONST  */
    CONTINUE = 290,                /* CONTINUE  */
    BREAK = 291                    /* BREAK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define CHARACTER 259
#define PRINT 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define FOR 264
#define IF 265
#define ELSE 266
#define TRUE 267
#define FALSE 268
#define NUMBER 269
#define FLOAT_NUM 270
#define ID 271
#define LE 272
#define GE 273
#define EQ 274
#define NE 275
#define GT 276
#define LT 277
#define AND 278
#define OR 279
#define STR 280
#define ADD 281
#define MULTIPLY 282
#define DIVIDE 283
#define SUBTRACT 284
#define UNARY 285
#define RETURN 286
#define WHILE 287
#define FUNCTION 288
#define CONST 289
#define CONTINUE 290
#define BREAK 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./src/yacc.y"

  struct lexval {
    char name[100];
    char type[20];
    TipoApontador node;
    char gotoLabel[10];
    char nextGotoLabel[10];
  } lexval;

#line 216 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_TRUE = 12,                      /* TRUE  */
  YYSYMBOL_FALSE = 13,                     /* FALSE  */
  YYSYMBOL_NUMBER = 14,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 15,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_STR = 25,                       /* STR  */
  YYSYMBOL_ADD = 26,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 27,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 28,                    /* DIVIDE  */
  YYSYMBOL_SUBTRACT = 29,                  /* SUBTRACT  */
  YYSYMBOL_UNARY = 30,                     /* UNARY  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_FUNCTION = 33,                  /* FUNCTION  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 36,                     /* BREAK  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_begin = 44,                     /* begin  */
  YYSYMBOL_main = 45,                      /* main  */
  YYSYMBOL_datatype = 46,                  /* datatype  */
  YYSYMBOL_body = 47,                      /* body  */
  YYSYMBOL_else = 48,                      /* else  */
  YYSYMBOL_condition = 49,                 /* condition  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_init = 52,                      /* init  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_arithmetic = 54,                /* arithmetic  */
  YYSYMBOL_relop = 55,                     /* relop  */
  YYSYMBOL_value = 56,                     /* value  */
  YYSYMBOL_return = 57                     /* return  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      37,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    36,    43,    44,    45,    46,    50,    64,
      79,    82,    85,    90,   104,   107,   113,   120,   124,   128,
     134,   134,   141,   146,   152,   157,   164,   171,   177,   177,
     177,   177,   178,   178,   178,   178,   178,   178,   180,   185,
     190,   196,   201
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "CHARACTER",
  "PRINT", "INT", "FLOAT", "CHAR", "FOR", "IF", "ELSE", "TRUE", "FALSE",
  "NUMBER", "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT", "LT", "AND",
  "OR", "STR", "ADD", "MULTIPLY", "DIVIDE", "SUBTRACT", "UNARY", "RETURN",
  "WHILE", "FUNCTION", "CONST", "CONTINUE", "BREAK", "'('", "')'", "'{'",
  "'}'", "';'", "'='", "$accept", "begin", "main", "datatype", "body",
  "else", "condition", "statement", "$@1", "init", "expression",
  "arithmetic", "relop", "value", "return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      29,   -29,   -29,   -29,   -29,    24,     3,    25,   -29,     4,
     -29,    13,   110,    18,    21,    33,   114,    48,    34,    98,
      28,    37,    22,    32,   -29,   -29,   -29,   -29,   -29,   -29,
      -3,    -3,    32,   -29,    -3,   110,    19,   -29,    49,    47,
     -29,   -29,   -29,   -29,   -29,    51,    74,    55,   -29,    55,
      59,    57,    68,   -29,    71,    32,    61,    -3,   -29,   -29,
     -29,   -29,    -3,    72,    -3,   -29,   -29,   -29,    80,   110,
     -29,    55,   110,   -29,    22,    -1,    11,    84,   112,   -29,
      85,    86,   -29,   110,   110,    58,    70,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     4,     5,     6,     0,     0,     0,     1,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,    19,    34,    35,    36,    37,    33,    32,
       0,     0,    19,    20,     0,    11,     0,    10,     0,     0,
      17,    18,    38,    39,    40,     0,     0,    22,    27,    23,
       0,    25,     0,     2,     0,    19,     0,     0,    28,    30,
      31,    29,     0,     0,     0,    21,    41,    12,     0,     0,
      16,    26,     0,    24,     0,     0,     0,     0,    15,    13,
       0,     0,     9,     0,     0,     0,     0,     8,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   127,   -12,   -29,   -22,   -21,   -29,   -29,
     -28,   -29,    82,    -8,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    18,    35,    82,    45,    20,    51,    65,
      47,    62,    31,    46,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    39,     1,    49,    13,     2,     3,     4,    14,    15,
      50,    42,    43,    44,     1,    16,    13,     2,     3,     4,
      14,    15,    48,    48,     8,     1,    52,    16,     2,     3,
       4,    17,     1,    68,    71,     2,     3,     4,    16,    78,
       9,    10,    11,    17,    40,    41,    42,    43,    44,    70,
      33,    79,    12,    77,    48,    21,    73,    75,    22,    53,
      76,     1,    38,    13,     2,     3,     4,    14,    15,    37,
      23,    85,    86,     1,    16,    13,     2,     3,     4,    14,
      15,    58,    59,    60,    61,    32,    16,    54,    55,    56,
      17,    24,    25,    26,    27,    28,    29,    63,    87,    64,
      69,     1,    17,    13,     2,     3,     4,    14,    15,    66,
      88,    72,    67,     1,    16,    13,     2,     3,     4,    14,
      15,    74,    80,    81,    83,    84,    16,     7,    57,    34,
      17,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30
};

static const yytype_int8 yycheck[] =
{
      12,    22,     3,    31,     5,     6,     7,     8,     9,    10,
      32,    14,    15,    16,     3,    16,     5,     6,     7,     8,
       9,    10,    30,    31,     0,     3,    34,    16,     6,     7,
       8,    32,     3,    55,    62,     6,     7,     8,    16,    40,
      37,    16,    38,    32,    12,    13,    14,    15,    16,    57,
      16,    40,    39,    74,    62,    37,    64,    69,    37,    40,
      72,     3,    25,     5,     6,     7,     8,     9,    10,    41,
      37,    83,    84,     3,    16,     5,     6,     7,     8,     9,
      10,    26,    27,    28,    29,    37,    16,    38,    41,    38,
      32,    17,    18,    19,    20,    21,    22,    38,    40,    42,
      39,     3,    32,     5,     6,     7,     8,     9,    10,    41,
      40,    39,    41,     3,    16,     5,     6,     7,     8,     9,
      10,    41,    38,    11,    39,    39,    16,     0,    46,    31,
      32,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,    44,    45,    46,     0,    37,
      16,    38,    39,     5,     9,    10,    16,    32,    46,    47,
      50,    37,    37,    37,    17,    18,    19,    20,    21,    22,
      42,    55,    37,    16,    31,    47,    57,    41,    25,    50,
      12,    13,    14,    15,    16,    49,    56,    53,    56,    53,
      49,    51,    56,    40,    38,    41,    38,    55,    26,    27,
      28,    29,    54,    38,    42,    52,    41,    41,    49,    39,
      56,    53,    39,    56,    41,    47,    47,    50,    40,    40,
      38,    11,    48,    39,    39,    47,    47,    40,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    49,    49,    49,
      51,    50,    50,    50,    52,    52,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     1,     1,     1,     1,    11,     8,
       2,     2,     5,     7,     4,     0,     3,     1,     1,     0,
       0,     4,     3,     3,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0
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
  case 2: /* begin: main '(' ')' '{' body return '}'  */
#line 29 "./src/yacc.y"
                                        {
  (yyvsp[-6].lexval).node = Insere("main", (yyvsp[-2].lexval).node, (yyvsp[-1].lexval).node);
  (yyval.lexval).node = Insere("begin", (yyvsp[-6].lexval).node, NULL);
  head = (yyval.lexval).node;
}
#line 1320 "y.tab.c"
    break;

  case 3: /* main: datatype ID  */
#line 36 "./src/yacc.y"
                  {
  addToSymbolTable(&st, FUNCT, yylineno, dataType, yytext);
  (yyvsp[0].lexval).node = Insere((yyvsp[0].lexval).name, NULL, NULL);
  (yyval.lexval).node = Insere("fun-decl", (yyvsp[0].lexval).node, NULL);
}
#line 1330 "y.tab.c"
    break;

  case 4: /* datatype: INT  */
#line 43 "./src/yacc.y"
              { defineDataType(); }
#line 1336 "y.tab.c"
    break;

  case 5: /* datatype: FLOAT  */
#line 44 "./src/yacc.y"
                { defineDataType(); }
#line 1342 "y.tab.c"
    break;

  case 6: /* datatype: CHAR  */
#line 45 "./src/yacc.y"
               { defineDataType(); }
#line 1348 "y.tab.c"
    break;

  case 7: /* datatype: VOID  */
#line 46 "./src/yacc.y"
               { defineDataType(); }
#line 1354 "y.tab.c"
    break;

  case 8: /* body: FOR '(' statement ';' condition ';' statement ')' '{' body '}'  */
#line 50 "./src/yacc.y"
                                                                   {
        TipoApontador loopCond = Insere("for-cond", (yyvsp[-6].lexval).node, (yyvsp[-4].lexval).node);
        TipoApontador loopHead = Insere("for-init", (yyvsp[-8].lexval).node, loopCond);
        (yyval.lexval).node = Insere("for", loopHead, (yyvsp[-1].lexval).node);
        char labelStart[20], labelEnd[20];
        sprintf(labelStart, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("LABEL", labelStart, "-", "-");
        addThreeAddressCode("IF_FALSE", (yyvsp[-6].lexval).name, labelEnd, "-");

        // ... corpo do for ...
        addThreeAddressCode("GOTO", labelStart, "-", "-");
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
#line 1373 "y.tab.c"
    break;

  case 9: /* body: IF '(' condition ')' '{' body '}' else  */
#line 64 "./src/yacc.y"
                                           {
        TipoApontador nodeIf = Insere("if", (yyvsp[-5].lexval).node, (yyvsp[-2].lexval).node);
        (yyval.lexval).node = Insere("if-else", nodeIf, (yyvsp[0].lexval).node);
        char labelElse[20], labelEnd[20];
        sprintf(labelElse, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("IF_FALSE", (yyvsp[-5].lexval).name, labelElse, "-");

        // ... corpo do if ...
        addThreeAddressCode("GOTO", labelEnd, "-", "-");
        addThreeAddressCode("LABEL", labelElse, "-", "-");
        
        // ... corpo do else ...
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
#line 1393 "y.tab.c"
    break;

  case 10: /* body: statement ';'  */
#line 79 "./src/yacc.y"
                  {
        (yyval.lexval).node = (yyvsp[-1].lexval).node;
    }
#line 1401 "y.tab.c"
    break;

  case 11: /* body: body body  */
#line 82 "./src/yacc.y"
              {
        (yyval.lexval).node = Insere("block", (yyvsp[-1].lexval).node, (yyvsp[0].lexval).node);
    }
#line 1409 "y.tab.c"
    break;

  case 12: /* body: PRINT '(' STR ')' ';'  */
#line 85 "./src/yacc.y"
                          {
        TipoApontador strNode = Insere((yyvsp[-2].lexval).name, NULL, NULL);
        (yyval.lexval).node = Insere("print", strNode, NULL);
        addThreeAddressCode("PRINT", (yyvsp[-2].lexval).name, "-", "-");
    }
#line 1419 "y.tab.c"
    break;

  case 13: /* body: WHILE '(' condition ')' '{' body '}'  */
#line 90 "./src/yacc.y"
                                         {
        (yyval.lexval).node = Insere("while", (yyvsp[-4].lexval).node, (yyvsp[-1].lexval).node);
        char labelStart[20], labelEnd[20];
        sprintf(labelStart, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("LABEL", labelStart, "-", "-");
        addThreeAddressCode("IF_FALSE", (yyvsp[-4].lexval).name, labelEnd, "-");
        // ... corpo do while ...
        addThreeAddressCode("GOTO", labelStart, "-", "-");
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
#line 1435 "y.tab.c"
    break;

  case 14: /* else: ELSE '{' body '}'  */
#line 104 "./src/yacc.y"
                      {
        (yyval.lexval).node = Insere("else", (yyvsp[-1].lexval).node, NULL);
    }
#line 1443 "y.tab.c"
    break;

  case 15: /* else: %empty  */
#line 107 "./src/yacc.y"
    {
        (yyval.lexval).node = NULL;
    }
#line 1451 "y.tab.c"
    break;

  case 16: /* condition: value relop value  */
#line 113 "./src/yacc.y"
                      {
        (yyval.lexval).node = Insere((yyvsp[-1].lexval).name, (yyvsp[-2].lexval).node, (yyvsp[0].lexval).node);
        char tempVar[20];
        sprintf(tempVar, "t%d", tempReg++);
        strcpy((yyval.lexval).name, tempVar);
        addThreeAddressCode((yyvsp[-1].lexval).name, (yyvsp[-2].lexval).name, (yyvsp[0].lexval).name, tempVar);
    }
#line 1463 "y.tab.c"
    break;

  case 17: /* condition: TRUE  */
#line 120 "./src/yacc.y"
         {
        (yyval.lexval).node = Insere("true", NULL, NULL);
        strcpy((yyval.lexval).name, "true");
    }
#line 1472 "y.tab.c"
    break;

  case 18: /* condition: FALSE  */
#line 124 "./src/yacc.y"
          {
        (yyval.lexval).node = Insere("false", NULL, NULL);
        strcpy((yyval.lexval).name, "false");
    }
#line 1481 "y.tab.c"
    break;

  case 19: /* condition: %empty  */
#line 128 "./src/yacc.y"
    {
        (yyval.lexval).node = NULL;
    }
#line 1489 "y.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 134 "./src/yacc.y"
                { addToSymbolTable(&st, IDTYPE, yylineno, dataType, yytext); }
#line 1495 "y.tab.c"
    break;

  case 21: /* statement: datatype ID $@1 init  */
#line 134 "./src/yacc.y"
                                                                                    {
        (yyvsp[-2].lexval).node = Insere((yyvsp[-2].lexval).name, NULL, NULL);
        (yyval.lexval).node = Insere("declaration", (yyvsp[-2].lexval).node, (yyvsp[0].lexval).node);
        if (strcmp((yyvsp[0].lexval).name, "NULL") != 0) {
            addThreeAddressCode("ASSIGN", (yyvsp[0].lexval).name, "-", (yyvsp[-2].lexval).name);
        }
    }
#line 1507 "y.tab.c"
    break;

  case 22: /* statement: ID '=' expression  */
#line 141 "./src/yacc.y"
                      {
        (yyvsp[-2].lexval).node = Insere((yyvsp[-2].lexval).name, NULL, NULL);
        (yyval.lexval).node = Insere("=", (yyvsp[-2].lexval).node, (yyvsp[0].lexval).node);
        addThreeAddressCode("ASSIGN", (yyvsp[0].lexval).name, "-", (yyvsp[-2].lexval).name);
    }
#line 1517 "y.tab.c"
    break;

  case 23: /* statement: ID relop expression  */
#line 146 "./src/yacc.y"
                        {
        (yyvsp[-2].lexval).node = Insere((yyvsp[-2].lexval).name, NULL, NULL);
        (yyval.lexval).node = Insere((yyvsp[-1].lexval).name, (yyvsp[-2].lexval).node, (yyvsp[0].lexval).node);
    }
#line 1526 "y.tab.c"
    break;

  case 24: /* init: '=' value  */
#line 152 "./src/yacc.y"
                {
  (yyval.lexval).node = (yyvsp[0].lexval).node;
  strcpy((yyval.lexval).type, (yyvsp[0].lexval).type);
  strcpy((yyval.lexval).name, (yyvsp[0].lexval).name);
}
#line 1536 "y.tab.c"
    break;

  case 25: /* init: %empty  */
#line 157 "./src/yacc.y"
  {
  strcpy((yyval.lexval).type, "null");
  strcpy((yyval.lexval).name, "NULL");
  (yyval.lexval).node = Insere("NULL", NULL, NULL);
}
#line 1546 "y.tab.c"
    break;

  case 26: /* expression: expression arithmetic expression  */
#line 164 "./src/yacc.y"
                                             {
  (yyval.lexval).node = Insere((yyvsp[-1].lexval).name, (yyvsp[-2].lexval).node, (yyvsp[0].lexval).node);
  char tempVar[20];
  sprintf(tempVar, "t%d", tempReg++);
  strcpy((yyval.lexval).name, tempVar);
  addThreeAddressCode((yyvsp[-1].lexval).name, (yyvsp[-2].lexval).name, (yyvsp[0].lexval).name, tempVar);
}
#line 1558 "y.tab.c"
    break;

  case 27: /* expression: value  */
#line 171 "./src/yacc.y"
        {
  (yyval.lexval).node = (yyvsp[0].lexval).node;
  strcpy((yyval.lexval).name, (yyvsp[0].lexval).name);
}
#line 1567 "y.tab.c"
    break;

  case 38: /* value: NUMBER  */
#line 180 "./src/yacc.y"
              {
  (yyval.lexval).node = Insere((yyvsp[0].lexval).name, NULL, NULL);
  strcpy((yyval.lexval).name, (yyvsp[0].lexval).name);
  strcpy((yyval.lexval).type, "int");
}
#line 1577 "y.tab.c"
    break;

  case 39: /* value: FLOAT_NUM  */
#line 185 "./src/yacc.y"
            {
  (yyval.lexval).node = Insere((yyvsp[0].lexval).name, NULL, NULL);
  strcpy((yyval.lexval).name, (yyvsp[0].lexval).name);
  strcpy((yyval.lexval).type, "float");
}
#line 1587 "y.tab.c"
    break;

  case 40: /* value: ID  */
#line 190 "./src/yacc.y"
     {
  (yyval.lexval).node = Insere((yyvsp[0].lexval).name, NULL, NULL);
  strcpy((yyval.lexval).name, (yyvsp[0].lexval).name);
}
#line 1596 "y.tab.c"
    break;

  case 41: /* return: RETURN value ';'  */
#line 196 "./src/yacc.y"
                         {
  (yyvsp[-2].lexval).node = Insere("return", NULL, NULL);
  (yyval.lexval).node = Insere("RETURN", (yyvsp[-2].lexval).node, (yyvsp[-1].lexval).node);
  addThreeAddressCode("RETURN", (yyvsp[-1].lexval).name, "-", "-");
}
#line 1606 "y.tab.c"
    break;

  case 42: /* return: %empty  */
#line 201 "./src/yacc.y"
  {
  (yyval.lexval).node = NULL;
}
#line 1614 "y.tab.c"
    break;


#line 1618 "y.tab.c"

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

#line 206 "./src/yacc.y"


void defineDataType() {
  strcpy(dataType, yytext);
}

int main(int argc, char *argv[]) {
  return begin();
}

void yyerror(const char* msg) {
  handleError(msg);
}
