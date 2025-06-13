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

#ifndef YY_YY_TRANSLATE_TAB_H_INCLUDED
# define YY_YY_TRANSLATE_TAB_H_INCLUDED
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
    TOKEN_TIPO_INT = 258,          /* TOKEN_TIPO_INT  */
    TOKEN_TIPO_STRING = 259,       /* TOKEN_TIPO_STRING  */
    TOKEN_TIPO_BOOLEAN = 260,      /* TOKEN_TIPO_BOOLEAN  */
    TOKEN_FOR = 261,               /* TOKEN_FOR  */
    TOKEN_WHILE = 262,             /* TOKEN_WHILE  */
    TOKEN_IF = 263,                /* TOKEN_IF  */
    TOKEN_ELSE = 264,              /* TOKEN_ELSE  */
    TOKEN_RETURN = 265,            /* TOKEN_RETURN  */
    TOKEN_ABRE_BLOCO = 266,        /* TOKEN_ABRE_BLOCO  */
    TOKEN_FECHA_BLOCO = 267,       /* TOKEN_FECHA_BLOCO  */
    TOKEN_ABRE_PARENTESES = 268,   /* TOKEN_ABRE_PARENTESES  */
    TOKEN_FECHA_PARENTESES = 269,  /* TOKEN_FECHA_PARENTESES  */
    TOKEN_ATRIBUICAO = 270,        /* TOKEN_ATRIBUICAO  */
    TOKEN_ADICAO = 271,            /* TOKEN_ADICAO  */
    TOKEN_SUBTRACAO = 272,         /* TOKEN_SUBTRACAO  */
    TOKEN_MULTIPLICACAO = 273,     /* TOKEN_MULTIPLICACAO  */
    TOKEN_DIVISAO = 274,           /* TOKEN_DIVISAO  */
    TOKEN_CONST = 275,             /* TOKEN_CONST  */
    TOKEN_IMPORT = 276,            /* TOKEN_IMPORT  */
    TOKEN_FUNCTION = 277,          /* TOKEN_FUNCTION  */
    TOKEN_STRING_LITERAL = 278,    /* TOKEN_STRING_LITERAL  */
    TOKEN_IDENTIFICADOR = 279,     /* TOKEN_IDENTIFICADOR  */
    TOKEN_NUMERO = 280,            /* TOKEN_NUMERO  */
    TOKEN_IGUALDADE = 281,         /* TOKEN_IGUALDADE  */
    TOKEN_DIFERENTE = 282,         /* TOKEN_DIFERENTE  */
    TOKEN_MAIOR = 283,             /* TOKEN_MAIOR  */
    TOKEN_MENOR = 284,             /* TOKEN_MENOR  */
    TOKEN_MAIOR_IGUAL = 285,       /* TOKEN_MAIOR_IGUAL  */
    TOKEN_MENOR_IGUAL = 286,       /* TOKEN_MENOR_IGUAL  */
    TOKEN_TRUE = 287,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 288,             /* TOKEN_FALSE  */
    TOKEN_PRINT = 289,             /* TOKEN_PRINT  */
    TOKEN_READ = 290,              /* TOKEN_READ  */
    TOKEN_MAIN = 291,              /* TOKEN_MAIN  */
    TOKEN_ERRO = 292               /* TOKEN_ERRO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "translate.y"

    int valor;
    char* str;

#line 106 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
