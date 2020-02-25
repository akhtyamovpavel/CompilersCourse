#include <unordered_map>
#include <string>
#include <iostream>
#include "lexer.hh"
#include "Commands.h"


int main() {
    Lexer lexer;
	while (true) {
		int token = lexer.ScanToken();
		if (token == TOKEN_EXIT) {
			std::cout << "Good bye" << std::endl;
			return 0;
		}
		std::cout << token << std::endl;
	}
	return 0;
}

