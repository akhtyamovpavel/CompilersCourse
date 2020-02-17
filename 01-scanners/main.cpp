#include <unordered_map>
#include <string>
#include <iostream>
#include "lexer.hh"


int main() {
    Lexer lexer;
	while (true) {
		int token = lexer.ScanToken();
		std::cout << token << std::endl;
	}
	return 0;
}

