#include <unordered_map>
#include <string>
#include <iostream>
#include "lexer.hh"
#include "Commands.h"


void PrintHelp() {
  std::cout << "Help" << std::endl;
  for (auto const& [key, value]: TOKEN_MAP) {
    std::cout << value << std::endl;
  }
}

int main() {
    Lexer lexer;
    lexer.set_debug(true);
	while (true) {
		int token = lexer.yylex();
		if (token == TOKEN_EXIT) {
			std::cout << "Good bye" << std::endl;
			return 0;
		} else if (token == TOKEN_HELP) {
		  PrintHelp();
		}
		std::cout << token << std::endl;
	}
	return 0;
}

