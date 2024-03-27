
// Generated from Arithmetics.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ArithmeticsListener.h"


/**
 * This class provides an empty implementation of ArithmeticsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ArithmeticsBaseListener : public ArithmeticsListener {
public:

  virtual void enterExpression(ArithmeticsParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ArithmeticsParser::ExpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

