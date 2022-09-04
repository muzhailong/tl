/* A Bison parser, made by GNU Bison 3.8.  */

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

#ifndef YY_YY_HOME_MUZHAILONG_PROJECTS_WORKSPACE_TL_SRC_SYNTAX_PARSER_HPP_INCLUDED
# define YY_YY_HOME_MUZHAILONG_PROJECTS_WORKSPACE_TL_SRC_SYNTAX_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"

    #include <cstdio>
    #include <cstdlib>
    #include <memory>

    #include "common/node.hpp"
    #include "common/token.hpp"

    namespace common_impl = tl::common;

#line 60 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SY_PLUS = 258,                 /* SY_PLUS  */
    SY_MINUS = 259,                /* SY_MINUS  */
    SY_MUL = 260,                  /* SY_MUL  */
    SY_DIV = 261,                  /* SY_DIV  */
    BOP_PLUS = 262,                /* BOP_PLUS  */
    BOP_MINUS = 263,               /* BOP_MINUS  */
    BOP_MUL = 264,                 /* BOP_MUL  */
    BOP_DIV = 265,                 /* BOP_DIV  */
    SY_EQUAL = 266,                /* SY_EQUAL  */
    SY_CEQ = 267,                  /* SY_CEQ  */
    SY_CNE = 268,                  /* SY_CNE  */
    SY_CGT = 269,                  /* SY_CGT  */
    SY_CLT = 270,                  /* SY_CLT  */
    SY_CGE = 271,                  /* SY_CGE  */
    SY_CLE = 272,                  /* SY_CLE  */
    SY_LEFT_BRACKET = 273,         /* SY_LEFT_BRACKET  */
    SY_RIGHT_BRACKET = 274,        /* SY_RIGHT_BRACKET  */
    SY_COMMA = 275,                /* SY_COMMA  */
    SY_COLON = 276,                /* SY_COLON  */
    SY_LEFT_BRACE = 277,           /* SY_LEFT_BRACE  */
    SY_RIGHT_BRACE = 278,          /* SY_RIGHT_BRACE  */
    SY_SEMICOLON = 279,            /* SY_SEMICOLON  */
    SY_LEFT_PAREN = 280,           /* SY_LEFT_PAREN  */
    SY_RIGHT_PAREN = 281,          /* SY_RIGHT_PAREN  */
    V_SI64 = 282,                  /* V_SI64  */
    V_FP64 = 283,                  /* V_FP64  */
    V_STR = 284,                   /* V_STR  */
    T_IDENTIFIER = 285             /* T_IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.y"

    common_impl::Node* node;
    common_impl::Block* block;
    common_impl::SI64ListNode* si64_list_node;
    common_impl::FP64ListNode* fp64_list_node;
    common_impl::STRListNode* str_list_node;
    common_impl::VarDeclarationNode* var_decl_node;
    common_impl::TokenInfo* token_info;
    common_impl::ExpressionNode* value_expr;
    common_impl::AssignStatement* assign_stmt;
    common_impl::SliceList* slice_list_node;
    common_impl::SliceExpression* slice_expr;

#line 121 "/home/muzhailong/Projects/workspace/tl/src/syntax/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_MUZHAILONG_PROJECTS_WORKSPACE_TL_SRC_SYNTAX_PARSER_HPP_INCLUDED  */
