%option noyywrap
%option c++
%option yyclass="Lexer"


%{

/* noyywrap - disables call of yywrap - indicator of EOF */
/* yyclass - set name of mapped class */
#include <cstdio>
#include <iostream>
#include "Commands.h"
#include "lexer.hh"

%}


%%
[ \t\r\n]+ {}

[h|help] { return TOKEN_HELP; }
[u|up] { std::cout << "up" << std::endl; return TOKEN_UP; }
[d|down] { std::cout << "down" << std::endl; return TOKEN_DOWN; }
[l|left] { std::cout << "left" << std::endl; return TOKEN_LEFT; }
[r|right] { std::cout << "right" << std::endl; return TOKEN_RIGHT; }
[e|exit] { return TOKEN_EXIT; }

.* { std::cout << "ERROR " << yytext << std::endl; return TOKEN_ERROR; }

%%
