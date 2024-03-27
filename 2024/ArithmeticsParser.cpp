
// Generated from Arithmetics.g4 by ANTLR 4.7.2


#include "ArithmeticsListener.h"

#include "ArithmeticsParser.h"


using namespace antlrcpp;
using namespace antlr4;

ArithmeticsParser::ArithmeticsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ArithmeticsParser::~ArithmeticsParser() {
  delete _interpreter;
}

std::string ArithmeticsParser::getGrammarFileName() const {
  return "Arithmetics.g4";
}

const std::vector<std::string>& ArithmeticsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ArithmeticsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ExpressionContext ------------------------------------------------------------------

ArithmeticsParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ArithmeticsParser::ExpressionContext *> ArithmeticsParser::ExpressionContext::expression() {
  return getRuleContexts<ArithmeticsParser::ExpressionContext>();
}

ArithmeticsParser::ExpressionContext* ArithmeticsParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<ArithmeticsParser::ExpressionContext>(i);
}

tree::TerminalNode* ArithmeticsParser::ExpressionContext::NUM() {
  return getToken(ArithmeticsParser::NUM, 0);
}


size_t ArithmeticsParser::ExpressionContext::getRuleIndex() const {
  return ArithmeticsParser::RuleExpression;
}

void ArithmeticsParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ArithmeticsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ArithmeticsParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ArithmeticsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


ArithmeticsParser::ExpressionContext* ArithmeticsParser::expression() {
   return expression(0);
}

ArithmeticsParser::ExpressionContext* ArithmeticsParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ArithmeticsParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ArithmeticsParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, ArithmeticsParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(8);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ArithmeticsParser::T__0: {
        setState(3);
        match(ArithmeticsParser::T__0);
        setState(4);
        expression(0);
        setState(5);
        match(ArithmeticsParser::T__1);
        break;
      }

      case ArithmeticsParser::NUM: {
        setState(7);
        match(ArithmeticsParser::NUM);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(24);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(22);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(10);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(11);
          match(ArithmeticsParser::T__2);
          setState(12);
          expression(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(13);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(14);
          match(ArithmeticsParser::T__3);
          setState(15);
          expression(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(16);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(17);
          match(ArithmeticsParser::T__4);
          setState(18);
          expression(4);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(19);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(20);
          match(ArithmeticsParser::T__5);
          setState(21);
          expression(3);
          break;
        }

        } 
      }
      setState(26);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ArithmeticsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ArithmeticsParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ArithmeticsParser::_decisionToDFA;
atn::PredictionContextCache ArithmeticsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ArithmeticsParser::_atn;
std::vector<uint16_t> ArithmeticsParser::_serializedATN;

std::vector<std::string> ArithmeticsParser::_ruleNames = {
  "expression"
};

std::vector<std::string> ArithmeticsParser::_literalNames = {
  "", "'('", "')'", "'*'", "'/'", "'-'", "'+'"
};

std::vector<std::string> ArithmeticsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "SPACES", "NUM"
};

dfa::Vocabulary ArithmeticsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ArithmeticsParser::_tokenNames;

ArithmeticsParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa, 0x1e, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xb, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x19, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x1c, 0xb, 0x2, 0x3, 0x2, 0x2, 0x3, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 
    0x21, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0x5, 0x8, 0x2, 0x1, 0x2, 0x5, 
    0x6, 0x7, 0x3, 0x2, 0x2, 0x6, 0x7, 0x5, 0x2, 0x2, 0x2, 0x7, 0x8, 0x7, 
    0x4, 0x2, 0x2, 0x8, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9, 0xb, 0x7, 0xa, 0x2, 
    0x2, 0xa, 0x4, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0xc, 0x7, 0x2, 0x2, 0xd, 0xe, 0x7, 
    0x5, 0x2, 0x2, 0xe, 0x19, 0x5, 0x2, 0x2, 0x8, 0xf, 0x10, 0xc, 0x6, 0x2, 
    0x2, 0x10, 0x11, 0x7, 0x6, 0x2, 0x2, 0x11, 0x19, 0x5, 0x2, 0x2, 0x7, 
    0x12, 0x13, 0xc, 0x5, 0x2, 0x2, 0x13, 0x14, 0x7, 0x7, 0x2, 0x2, 0x14, 
    0x19, 0x5, 0x2, 0x2, 0x6, 0x15, 0x16, 0xc, 0x4, 0x2, 0x2, 0x16, 0x17, 
    0x7, 0x8, 0x2, 0x2, 0x17, 0x19, 0x5, 0x2, 0x2, 0x5, 0x18, 0xc, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xf, 0x3, 0x2, 0x2, 0x2, 0x18, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x15, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x1b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x5, 
    0xa, 0x18, 0x1a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ArithmeticsParser::Initializer ArithmeticsParser::_init;
