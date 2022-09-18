%{
#include <string>
#include <memory>
#include <iostream>
#include <string>

#include "common/node.hpp"
#include "common/token.hpp"
#include "syntax/parser.hpp"

using tl::common::TokenInfo;
extern std::string filename;

static int64_t yycolumn = 1;

#define YY_USER_ACTION yycolumn+=yyleng-1;

inline void SetLocation(TokenInfo*token_info){
    token_info->SetLocation(filename,yylineno,yylineno,yycolumn,yycolumn+yyleng);
}

%}

%option noyywrap
%option yylineno

%%
[ \t]                       ;
\n                          {yycolumn=1;}
"if"                        {
                                yylval.token_info = new TokenInfo(KW_IF,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return KW_IF;
                            }

"else"                      {
                                yylval.token_info = new TokenInfo(KW_ELSE,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return KW_ELSE;
                            }

"while"                     {
                                yylval.token_info = new TokenInfo(KW_WHILE,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return KW_WHILE;
                            }

"return"                    {
                                yylval.token_info = new TokenInfo(KW_RETURN,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return KW_RETURN;
                            }
"break"                     {
                                yylval.token_info = new TokenInfo(KW_BREAK,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return KW_BREAK;
                            }

[a-zA-Z_][a-zA-Z0-9_]*      {
                                yylval.token_info = new TokenInfo(T_IDENTIFIER,std::string(yytext,yyleng));
                                SetLocation(yylval.token_info);
                                return T_IDENTIFIER;
                            }

[0-9]*\.[0-9]+              {
                                yylval.token_info = new TokenInfo(V_FP64);
                                yylval.token_info->SetValue<double>(std::stod(std::string(yytext,yyleng)));
                                SetLocation(yylval.token_info);
                                return V_FP64;
                            }

[1-9][0-9]*                 {
                                yylval.token_info = new TokenInfo(V_SI64);
                                yylval.token_info->SetValue<int64_t>(std::stol(std::string(yytext,yyleng)));
                                SetLocation(yylval.token_info);
                                return V_SI64;
                            }

\"[^\"]*\"    {
                                yylval.token_info = new TokenInfo(V_STR);
                                yylval.token_info->SetValue<std::string>(std::string(yytext+1,yyleng-2));
                                SetLocation(yylval.token_info);
                                return V_STR;
                            }

"="                         {
                                yylval.token_info = new TokenInfo(SY_EQUAL);
                                SetLocation(yylval.token_info);
                                return SY_EQUAL;
                            }

"=="                        {
                                yylval.token_info = new TokenInfo(SY_CEQ);
                                SetLocation(yylval.token_info);
                                return SY_CEQ;
                            }

"!="                        {
                                yylval.token_info = new TokenInfo(SY_CNE);
                                SetLocation(yylval.token_info);
                                return SY_CNE;
                            }

"<"                         {
                                yylval.token_info = new TokenInfo(SY_CLT);
                                SetLocation(yylval.token_info);
                                return SY_CLT;
                            }

"<="                        {
                                yylval.token_info = new TokenInfo(SY_CLE);
                                SetLocation(yylval.token_info);
                                return SY_CLE;
                            }

">"                         {
                                yylval.token_info = new TokenInfo(SY_CGT);
                                SetLocation(yylval.token_info);
                                return SY_CGT;
                            }

">="                        {
                                yylval.token_info = new TokenInfo(SY_CGE);
                                SetLocation(yylval.token_info);
                                return SY_CGE;
                            }

"["                         {
                                yylval.token_info = new TokenInfo(SY_LEFT_BRACKET);
                                SetLocation(yylval.token_info);
                                return SY_LEFT_BRACKET;
                            }

"]"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACKET);
                                SetLocation(yylval.token_info);
                                return SY_RIGHT_BRACKET;
                            }

"("                         {
                                yylval.token_info = new TokenInfo(SY_LEFT_PAREN);
                                SetLocation(yylval.token_info);
                                return SY_LEFT_PAREN;
                            }

")"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_PAREN);
                                SetLocation(yylval.token_info);
                                return SY_RIGHT_PAREN;
                            }

"{"                         {
                                yylval.token_info = new TokenInfo(SY_LEFT_BRACE);
                                SetLocation(yylval.token_info);
                                return SY_LEFT_BRACE;
                            }

"}"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACE);
                                SetLocation(yylval.token_info);
                                return SY_RIGHT_BRACE;
                            }

","                         {
                                yylval.token_info = new TokenInfo(SY_COMMA);
                                SetLocation(yylval.token_info);
                                return SY_COMMA;
                            }

":"                         {
                                yylval.token_info = new TokenInfo(SY_COLON);
                                SetLocation(yylval.token_info);
                                return SY_COLON;
                            }

";"                         {
                                yylval.token_info = new TokenInfo(SY_SEMICOLON);
                                SetLocation(yylval.token_info);
                                return SY_SEMICOLON;
                            }

"+"                         {
                                yylval.token_info = new TokenInfo(SY_PLUS);
                                SetLocation(yylval.token_info);
                                return SY_PLUS;
                            }

"-"                         {
                                yylval.token_info = new TokenInfo(SY_MINUS);
                                SetLocation(yylval.token_info);
                                return SY_MINUS;
                            }
"*"                         {
                                yylval.token_info = new TokenInfo(SY_MUL);
                                SetLocation(yylval.token_info);
                                return SY_MUL;
                            }
"/"                         {
                                yylval.token_info = new TokenInfo(SY_DIV);
                                SetLocation(yylval.token_info);
                                return SY_DIV;
                            }
.                           {
                                std::cout<<std::string(yytext,yyleng)<<std::endl;
                                printf("Unknown token!\n"); 
                                yyterminate();
                            }
%%