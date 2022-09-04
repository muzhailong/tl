%{
#include <string>
#include <memory>
#include <iostream>

#include "common/node.hpp"
#include "common/token.hpp"
#include "syntax/parser.hpp"

using tl::common::TokenInfo;
%}

%option noyywrap
%%
[ \t\n]                      ;
[a-zA-Z_][a-zA-Z0-9_]*      {
                                yylval.token_info = new TokenInfo(T_IDENTIFIER,std::string(yytext,yyleng));
                                return T_IDENTIFIER;
                            }

[0-9]*\.[0-9]+              {
                                yylval.token_info = new TokenInfo(V_FP64);
                                yylval.token_info->SetValue<double>(std::stod(std::string(yytext,yyleng)));
                                return V_FP64;
                            }

[1-9][0-9]*                 {
                                yylval.token_info = new TokenInfo(V_SI64);
                                yylval.token_info->SetValue<int64_t>(std::stol(std::string(yytext,yyleng)));
                                return V_SI64;
                            }

\"[^\"]*\"    {
                                yylval.token_info = new TokenInfo(V_STR);
                                yylval.token_info->SetValue<std::string>(std::string(yytext+1,yyleng-2));
                                return V_STR;
                            }

"="                         {
                                yylval.token_info = new TokenInfo(SY_EQUAL);
                                return SY_EQUAL;
                            }

"=="                        {
                                yylval.token_info = new TokenInfo(SY_CEQ);
                                return SY_CEQ;
                            }

"!="                        {
                                yylval.token_info = new TokenInfo(SY_CNE);
                                return SY_CNE;
                            }

"<"                         {
                                yylval.token_info = new TokenInfo(SY_CLT);
                                return SY_CLT;
                            }

"<="                        {
                                yylval.token_info = new TokenInfo(SY_CLE);
                                return SY_CLE;
                            }

">"                         {
                                yylval.token_info = new TokenInfo(SY_CGT);
                                return SY_CGT;
                            }

">="                        {
                                yylval.token_info = new TokenInfo(SY_CGE);
                                return SY_CGE;
                            }

"["                         {
                                yylval.token_info = new TokenInfo(SY_LEFT_BRACKET);
                                return SY_LEFT_BRACKET;
                            }

"]"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACKET);
                                return SY_RIGHT_BRACKET;
                            }

"("                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACKET);
                                return SY_LEFT_PAREN;
                            }

")"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACKET);
                                return SY_RIGHT_PAREN;
                            }

"{"                         {
                                yylval.token_info = new TokenInfo(SY_LEFT_BRACE);
                                return SY_LEFT_BRACE;
                            }

"}"                         {
                                yylval.token_info = new TokenInfo(SY_RIGHT_BRACE);
                                return SY_RIGHT_BRACE;
                            }

","                         {
                                yylval.token_info = new TokenInfo(SY_COMMA);
                                return SY_COMMA;
                            }
                            
":"                         {
                                yylval.token_info = new TokenInfo(SY_COLON);
                                return SY_COLON;
                            }

";"                         {
                                yylval.token_info = new TokenInfo(SY_SEMICOLON);
                                return SY_SEMICOLON;
                            }

"+"                         {
                                yylval.token_info = new TokenInfo(SY_PLUS);
                                return SY_PLUS;
                            }

"-"                         {
                                yylval.token_info = new TokenInfo(SY_MINUS);
                                return SY_MINUS;
                            }
"*"                         {
                                yylval.token_info = new TokenInfo(SY_MUL);
                                return SY_MUL;
                            }
"/"                         {
                                yylval.token_info = new TokenInfo(SY_DIV);
                                return SY_DIV;
                            }
.                           {
                                std::cout<<std::string(yytext,yyleng)<<std::endl;
                                printf("Unknown token!\n"); 
                                yyterminate();
                            }
%%