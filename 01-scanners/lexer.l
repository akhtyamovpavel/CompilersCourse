%option noyywrap
%option c++
%option yyclass="Lexer"

%{

#include <cstdio>
#include <iostream>
#include "Commands.h"
#include "lexer.hh"

%}

%%

[ \t\r\n]+ {}

"help" { return TOKEN_HELP; }
"up" { return TOKEN_UP; }
"down" { return TOKEN_DOWN; }
"left" { return TOKEN_LEFT; }
"right" { return TOKEN_RIGHT; }
"exit" { return TOKEN_EXIT; }

.* { std::cout << "ERROR " << yytext << std::endl; return TOKEN_ERROR; }

%%
