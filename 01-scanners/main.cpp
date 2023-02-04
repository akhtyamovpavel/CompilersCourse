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
        Command* token = lexer.ScanToken();

        if (token->command == TOKEN_EXIT) {
            std::cout << "Good bye" << std::endl;
            return 0;
        } else if (token->command == TOKEN_HELP) {
	          PrintHelp();
        } else {
          Command* new_token = lexer.ScanToken();
          std::cout << "Steps" << new_token->steps << std::endl;
        }
        std::cout << token->command << std::endl;
    }
    return 0;
}

