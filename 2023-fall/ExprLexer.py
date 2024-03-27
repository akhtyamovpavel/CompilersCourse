# Generated from Expr.g4 by ANTLR 4.7.2
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys


def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\23")
        buf.write("b\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7")
        buf.write("\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4\f\t\f\4\r\t\r\4\16")
        buf.write("\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22\3\2\3\2")
        buf.write("\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3")
        buf.write("\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\f\3")
        buf.write("\r\3\r\3\r\3\r\3\r\3\r\3\r\5\rI\n\r\3\16\3\16\3\16\3\16")
        buf.write("\3\17\3\17\3\17\3\17\3\17\3\20\6\20U\n\20\r\20\16\20V")
        buf.write("\3\21\6\21Z\n\21\r\21\16\21[\3\22\6\22_\n\22\r\22\16\22")
        buf.write("`\2\2\23\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f")
        buf.write("\27\r\31\16\33\17\35\20\37\21!\22#\23\3\2\6\4\2\13\13")
        buf.write("\"\"\4\2\f\f\17\17\3\2\62;\4\2C\\c|\2e\2\3\3\2\2\2\2\5")
        buf.write("\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2")
        buf.write("\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2")
        buf.write("\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2")
        buf.write("\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\3%\3\2\2\2\5\'\3\2")
        buf.write("\2\2\7)\3\2\2\2\t+\3\2\2\2\13-\3\2\2\2\r\63\3\2\2\2\17")
        buf.write("\65\3\2\2\2\21\67\3\2\2\2\239\3\2\2\2\25;\3\2\2\2\27=")
        buf.write("\3\2\2\2\31H\3\2\2\2\33J\3\2\2\2\35N\3\2\2\2\37T\3\2\2")
        buf.write("\2!Y\3\2\2\2#^\3\2\2\2%&\7*\2\2&\4\3\2\2\2\'(\7+\2\2(")
        buf.write("\6\3\2\2\2)*\7}\2\2*\b\3\2\2\2+,\7\177\2\2,\n\3\2\2\2")
        buf.write("-.\7r\2\2./\7t\2\2/\60\7k\2\2\60\61\7p\2\2\61\62\7v\2")
        buf.write("\2\62\f\3\2\2\2\63\64\7?\2\2\64\16\3\2\2\2\65\66\7,\2")
        buf.write("\2\66\20\3\2\2\2\678\7\61\2\28\22\3\2\2\29:\7-\2\2:\24")
        buf.write("\3\2\2\2;<\7/\2\2<\26\3\2\2\2=>\t\2\2\2>?\3\2\2\2?@\b")
        buf.write("\f\2\2@\30\3\2\2\2AB\7h\2\2BC\7w\2\2CI\7p\2\2DE\7h\2\2")
        buf.write("EF\7w\2\2FG\7p\2\2GI\7\64\2\2HA\3\2\2\2HD\3\2\2\2I\32")
        buf.write("\3\2\2\2JK\7n\2\2KL\7g\2\2LM\7v\2\2M\34\3\2\2\2NO\7o\2")
        buf.write("\2OP\7c\2\2PQ\7k\2\2QR\7p\2\2R\36\3\2\2\2SU\t\3\2\2TS")
        buf.write("\3\2\2\2UV\3\2\2\2VT\3\2\2\2VW\3\2\2\2W \3\2\2\2XZ\t\4")
        buf.write("\2\2YX\3\2\2\2Z[\3\2\2\2[Y\3\2\2\2[\\\3\2\2\2\\\"\3\2")
        buf.write("\2\2]_\t\5\2\2^]\3\2\2\2_`\3\2\2\2`^\3\2\2\2`a\3\2\2\2")
        buf.write("a$\3\2\2\2\7\2HV[`\3\b\2\2")
        return buf.getvalue()


class ExprLexer(Lexer):

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    T__0 = 1
    T__1 = 2
    T__2 = 3
    T__3 = 4
    T__4 = 5
    T__5 = 6
    T__6 = 7
    T__7 = 8
    T__8 = 9
    T__9 = 10
    SPACES = 11
    FUN = 12
    LET = 13
    MAIN = 14
    NEWLINE = 15
    INT = 16
    IDENT = 17

    channelNames = [ u"DEFAULT_TOKEN_CHANNEL", u"HIDDEN" ]

    modeNames = [ "DEFAULT_MODE" ]

    literalNames = [ "<INVALID>",
            "'('", "')'", "'{'", "'}'", "'print'", "'='", "'*'", "'/'", 
            "'+'", "'-'", "'let'", "'main'" ]

    symbolicNames = [ "<INVALID>",
            "SPACES", "FUN", "LET", "MAIN", "NEWLINE", "INT", "IDENT" ]

    ruleNames = [ "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", 
                  "T__7", "T__8", "T__9", "SPACES", "FUN", "LET", "MAIN", 
                  "NEWLINE", "INT", "IDENT" ]

    grammarFileName = "Expr.g4"

    def __init__(self, input=None, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7.2")
        self._interp = LexerATNSimulator(self, self.atn, self.decisionsToDFA, PredictionContextCache())
        self._actions = None
        self._predicates = None


