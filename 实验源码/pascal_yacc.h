/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED
# define YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Iden = 300,
     IntNo = 301,
     RealNo = 302,
     Program = 400,
     Begin = 401,
     End = 402,
     Var = 403,
     Integer = 404,
     Real = 405,
     While = 406,
     Do = 407,
     If = 408,
     Then = 409,
     Else = 410,
     For = 411,
     To = 412,
     Array = 413,
     Of = 414,
     Or = 415,
     And = 416,
     Not = 417,
     dian = 418,
     Until = 419,
     step = 420,
     LE = 500,
     GE = 501,
     NE = 502,
     UMINUS = 504
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 31 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.y"

    struct
    {
         int Iv;
         int CH;
         int NO;
         struct { int TC,FC;} _BExpr;
         struct {int place;int QUAD;int CH;} _forloop;
         struct { int QUAD,CH;} _WBD; //while
         struct { int type,place;union{int Iv;float Rv;} Value;} _Expr;
         char _Rop[5];
         int First;
         char str[50];
         struct node *trNode;
         struct { int PLACE, OFFSET;} _Var;
         struct { int NO, DIM, PLACE;} _Elist;
    }st;


/* Line 2058 of yacc.c  */
#line 107 "C:\\Users\\a\\Desktop\\MiniPascal/pascal_yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_USERS_A_DESKTOP_MINIPASCAL_PASCAL_YACC_H_INCLUDED  */
