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

h|help { return TOKEN_HELP; }
up|u { std::cout << "up" << std::endl; return TOKEN_UP; }
down|d { std::cout << "down" << std::endl; return TOKEN_DOWN; }
left|l { std::cout << "left" << std::endl; return TOKEN_LEFT; }
right|r { std::cout << "right" << std::endl; return TOKEN_RIGHT; }
exit|e { return TOKEN_EXIT; }

.* { std::cout << "ERROR " << yytext << std::endl; return TOKEN_ERROR; }

%%
