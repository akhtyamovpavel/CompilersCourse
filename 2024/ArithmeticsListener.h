
// Generated from Arithmetics.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ArithmeticsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ArithmeticsParser.
 */
class  ArithmeticsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExpression(ArithmeticsParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ArithmeticsParser::ExpressionContext *ctx) = 0;


};

