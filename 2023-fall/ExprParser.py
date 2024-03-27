# Generated from Expr.g4 by ANTLR 4.7.2
# encoding: utf-8
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys

def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\23")
        buf.write(":\4\2\t\2\4\3\t\3\4\4\t\4\3\2\3\2\3\2\3\2\3\2\3\2\3\2")
        buf.write("\3\2\3\2\7\2\22\n\2\f\2\16\2\25\13\2\3\2\3\2\3\3\3\3\3")
        buf.write("\3\3\3\3\3\3\3\3\3\5\3 \n\3\3\4\3\4\3\4\3\4\3\4\3\4\3")
        buf.write("\4\5\4)\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7")
        buf.write("\4\65\n\4\f\4\16\48\13\4\3\4\2\3\6\5\2\4\6\2\4\3\2\t\n")
        buf.write("\3\2\13\f\2=\2\b\3\2\2\2\4\37\3\2\2\2\6(\3\2\2\2\b\t\7")
        buf.write("\16\2\2\t\n\7\20\2\2\n\13\7\3\2\2\13\f\7\4\2\2\f\r\7\5")
        buf.write("\2\2\r\23\7\21\2\2\16\17\5\4\3\2\17\20\7\21\2\2\20\22")
        buf.write("\3\2\2\2\21\16\3\2\2\2\22\25\3\2\2\2\23\21\3\2\2\2\23")
        buf.write("\24\3\2\2\2\24\26\3\2\2\2\25\23\3\2\2\2\26\27\7\6\2\2")
        buf.write("\27\3\3\2\2\2\30\31\7\7\2\2\31 \5\6\4\2\32\33\7\17\2\2")
        buf.write("\33 \7\23\2\2\34\35\7\23\2\2\35\36\7\b\2\2\36 \5\6\4\2")
        buf.write("\37\30\3\2\2\2\37\32\3\2\2\2\37\34\3\2\2\2 \5\3\2\2\2")
        buf.write("!\"\b\4\1\2\")\7\22\2\2#$\7\3\2\2$%\5\6\4\2%&\7\4\2\2")
        buf.write("&)\3\2\2\2\')\7\23\2\2(!\3\2\2\2(#\3\2\2\2(\'\3\2\2\2")
        buf.write(")\66\3\2\2\2*+\f\7\2\2+,\t\2\2\2,-\5\6\4\b-.\b\4\1\2.")
        buf.write("\65\3\2\2\2/\60\f\6\2\2\60\61\t\3\2\2\61\62\5\6\4\7\62")
        buf.write("\63\b\4\1\2\63\65\3\2\2\2\64*\3\2\2\2\64/\3\2\2\2\658")
        buf.write("\3\2\2\2\66\64\3\2\2\2\66\67\3\2\2\2\67\7\3\2\2\28\66")
        buf.write("\3\2\2\2\7\23\37(\64\66")
        return buf.getvalue()


class ExprParser ( Parser ):

    grammarFileName = "Expr.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'('", "')'", "'{'", "'}'", "'print'", 
                     "'='", "'*'", "'/'", "'+'", "'-'", "<INVALID>", "<INVALID>", 
                     "'let'", "'main'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "SPACES", "FUN", 
                      "LET", "MAIN", "NEWLINE", "INT", "IDENT" ]

    RULE_prog = 0
    RULE_stmt = 1
    RULE_expr = 2

    ruleNames =  [ "prog", "stmt", "expr" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    T__7=8
    T__8=9
    T__9=10
    SPACES=11
    FUN=12
    LET=13
    MAIN=14
    NEWLINE=15
    INT=16
    IDENT=17

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7.2")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class ProgContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def FUN(self):
            return self.getToken(ExprParser.FUN, 0)

        def MAIN(self):
            return self.getToken(ExprParser.MAIN, 0)

        def NEWLINE(self, i:int=None):
            if i is None:
                return self.getTokens(ExprParser.NEWLINE)
            else:
                return self.getToken(ExprParser.NEWLINE, i)

        def stmt(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.StmtContext)
            else:
                return self.getTypedRuleContext(ExprParser.StmtContext,i)


        def getRuleIndex(self):
            return ExprParser.RULE_prog

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProg" ):
                listener.enterProg(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProg" ):
                listener.exitProg(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitProg" ):
                return visitor.visitProg(self)
            else:
                return visitor.visitChildren(self)




    def prog(self):

        localctx = ExprParser.ProgContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_prog)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 6
            self.match(ExprParser.FUN)
            self.state = 7
            self.match(ExprParser.MAIN)
            self.state = 8
            self.match(ExprParser.T__0)
            self.state = 9
            self.match(ExprParser.T__1)
            self.state = 10
            self.match(ExprParser.T__2)
            self.state = 11
            self.match(ExprParser.NEWLINE)

            self.state = 17
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while (((_la) & ~0x3f) == 0 and ((1 << _la) & ((1 << ExprParser.T__4) | (1 << ExprParser.LET) | (1 << ExprParser.IDENT))) != 0):
                self.state = 12
                self.stmt()
                self.state = 13
                self.match(ExprParser.NEWLINE)
                self.state = 19
                self._errHandler.sync(self)
                _la = self._input.LA(1)

            self.state = 20
            self.match(ExprParser.T__3)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class StmtContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.printexp = None # ExprContext
            self.let = None # Token
            self.var = None # Token
            self.ident = None # Token
            self.assign = None # ExprContext

        def expr(self):
            return self.getTypedRuleContext(ExprParser.ExprContext,0)


        def LET(self):
            return self.getToken(ExprParser.LET, 0)

        def IDENT(self):
            return self.getToken(ExprParser.IDENT, 0)

        def getRuleIndex(self):
            return ExprParser.RULE_stmt

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterStmt" ):
                listener.enterStmt(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitStmt" ):
                listener.exitStmt(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitStmt" ):
                return visitor.visitStmt(self)
            else:
                return visitor.visitChildren(self)




    def stmt(self):

        localctx = ExprParser.StmtContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_stmt)
        try:
            self.state = 29
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [ExprParser.T__4]:
                self.enterOuterAlt(localctx, 1)
                self.state = 22
                self.match(ExprParser.T__4)
                self.state = 23
                localctx.printexp = self.expr(0)
                pass
            elif token in [ExprParser.LET]:
                self.enterOuterAlt(localctx, 2)
                self.state = 24
                localctx.let = self.match(ExprParser.LET)
                self.state = 25
                localctx.var = self.match(ExprParser.IDENT)
                pass
            elif token in [ExprParser.IDENT]:
                self.enterOuterAlt(localctx, 3)
                self.state = 26
                localctx.ident = self.match(ExprParser.IDENT)

                self.state = 27
                self.match(ExprParser.T__5)
                self.state = 28
                localctx.assign = self.expr(0)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class ExprContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.left = None # ExprContext
            self.value = None # Token
            self.exp = None # ExprContext
            self.ident = None # Token
            self.op = None # Token
            self.right = None # ExprContext

        def INT(self):
            return self.getToken(ExprParser.INT, 0)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExprParser.ExprContext,i)


        def IDENT(self):
            return self.getToken(ExprParser.IDENT, 0)

        def getRuleIndex(self):
            return ExprParser.RULE_expr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExpr" ):
                listener.enterExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExpr" ):
                listener.exitExpr(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitExpr" ):
                return visitor.visitExpr(self)
            else:
                return visitor.visitChildren(self)



    def expr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = ExprParser.ExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 4
        self.enterRecursionRule(localctx, 4, self.RULE_expr, _p)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 38
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [ExprParser.INT]:
                self.state = 32
                localctx.value = self.match(ExprParser.INT)
                pass
            elif token in [ExprParser.T__0]:
                self.state = 33
                self.match(ExprParser.T__0)
                self.state = 34
                localctx.exp = self.expr(0)
                self.state = 35
                self.match(ExprParser.T__1)
                pass
            elif token in [ExprParser.IDENT]:
                self.state = 37
                localctx.ident = self.match(ExprParser.IDENT)
                pass
            else:
                raise NoViableAltException(self)

            self._ctx.stop = self._input.LT(-1)
            self.state = 52
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,4,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 50
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,3,self._ctx)
                    if la_ == 1:
                        localctx = ExprParser.ExprContext(self, _parentctx, _parentState)
                        localctx.left = _prevctx
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 40
                        if not self.precpred(self._ctx, 5):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 5)")
                        self.state = 41
                        localctx.op = self._input.LT(1)
                        _la = self._input.LA(1)
                        if not(_la==ExprParser.T__6 or _la==ExprParser.T__7):
                            localctx.op = self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 42
                        localctx.right = self.expr(6)
                        print('MulExpr')
                        pass

                    elif la_ == 2:
                        localctx = ExprParser.ExprContext(self, _parentctx, _parentState)
                        localctx.left = _prevctx
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 45
                        if not self.precpred(self._ctx, 4):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 4)")
                        self.state = 46
                        localctx.op = self._input.LT(1)
                        _la = self._input.LA(1)
                        if not(_la==ExprParser.T__8 or _la==ExprParser.T__9):
                            localctx.op = self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 47
                        localctx.right = self.expr(5)
                        print('AddExpr')
                        pass

             
                self.state = 54
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,4,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[2] = self.expr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def expr_sempred(self, localctx:ExprContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 5)
         

            if predIndex == 1:
                return self.precpred(self._ctx, 4)
         




