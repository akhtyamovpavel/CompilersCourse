#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int Lexer::ScanToken()

// ScanToken is function that calls Scanner; It returns int values, we will use enums!
class Lexer: public yyFlexLexer {
 public:
	virtual ~Lexer() {}
	virtual int ScanToken();
};
