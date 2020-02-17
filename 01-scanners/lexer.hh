#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int Lexer::ScanToken()

class Lexer: public yyFlexLexer {
 public:
	virtual ~Lexer() {}
	virtual int ScanToken();
};
