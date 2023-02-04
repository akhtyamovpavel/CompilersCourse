#pragma once

#include "Commands.h"

struct Command {
	Token command;
	int steps;
};

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL Command* Lexer::ScanToken()

// ScanToken is function that calls Scanner; It returns int values, we will use enums!
class Lexer: public yyFlexLexer {
 public:
	virtual ~Lexer() {}
//	virtual int yylex();
	virtual Command* ScanToken();
};
