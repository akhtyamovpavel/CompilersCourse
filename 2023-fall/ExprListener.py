# Generated from Expr.g4 by ANTLR 4.13.0
from antlr4 import *
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.MulExpression import MulExpression

from nodes.expressions.NumberExpression import NumberExpression
if "." in __name__:
    from .ExprParser import ExprParser
else:
    from ExprParser import ExprParser

# This class defines a complete listener for a parse tree produced by ExprParser.
class ExprListener(ParseTreeListener):

    # Enter a parse tree produced by ExprParser#prog.
    def enterProg(self, ctx:ExprParser.ProgContext):
        pass

    # Exit a parse tree produced by ExprParser#prog.
    def exitProg(self, ctx:ExprParser.ProgContext):
        pass


    # Enter a parse tree produced by ExprParser#expr.
    def enterExpr(self, ctx:ExprParser.ExprContext):
        pass

    # Exit a parse tree produced by ExprParser#expr.
    def exitExpr(self, ctx:ExprParser.ExprContext):
        if ctx.value is not None:
            return NumberExpression(ctx.value)
        if ctx.op == '/':
            return DivExpression(ctx.left, ctx.right)
        elif ctx.op == '*':
            return MulExpression(ctx.left, ctx.right)



del ExprParser