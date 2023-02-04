%option noyywrap
%option c++
%option yyclass="Lexer"

%option debug


%{

/* noyywrap - disables call of yywrap - indicator of EOF */
/* yyclass - set name of mapped class */
#include <cstdio>
#include <iostream>
#include "Commands.h"
#include "lexer.hh"

%}

int   [0-9]+


%%
[ \t\r\n]+ {}

h|help {
    Command* command = new Command();
    command->command = TOKEN_HELP;
    return command;
}
up|u {
    std::cout << "up" << std::endl;
    Command* command = new Command();
    command->command = TOKEN_UP;
    return command;
}
down|d {
    std::cout << "down" << std::endl;
    Command* command = new Command();
    command->command = TOKEN_DOWN; 
    return command;
}
left|l {
    std::cout << "left" << std::endl;
    Command* command = new Command();
    command->command = TOKEN_LEFT; 
    return command;
}
right|r {
    std::cout << "right" << std::endl;
    Command* command = new Command();
    command->command = TOKEN_RIGHT; 
    return command;
}
exit|e {
    Command* command = new Command();
    command->command = TOKEN_EXIT; 
    return command;
}

{int} {
    std::cout << yytext << std::endl;
    Command* command = new Command();
    command->command = TOKEN_EXIT;
    command->steps = std::stoi(yytext);
    return command;
}

.* { std::cout << "ERROR " << yytext << std::endl;
    Command* command = new Command();
    command->command = TOKEN_ERROR;
    return command; 
}
%%
