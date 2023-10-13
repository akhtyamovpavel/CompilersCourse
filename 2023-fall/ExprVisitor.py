# Generated from Expr.g4 by ANTLR 4.13.0
from antlr4 import *
from nodes.Program import Program
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.MulExpression import MulExpression

from nodes.expressions.NumberExpression import NumberExpression
if "." in __name__:
    from .ExprParser import ExprParser
else:
    from ExprParser import ExprParser

# This class defines a complete generic visitor for a parse tree produced by ExprParser.

class ExprVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by ExprParser#prog.
    def visitProg(self, ctx:ExprParser.ProgContext):
        expressions = []

        for expression in ctx.expr():
            expressions.append(self.visit(expression))
        return Program(expressions=expressions)


    # Visit a parse tree produced by ExprParser#expr.
    def visitExpr(self, ctx:ExprParser.ExprContext):
        if ctx.value is not None:
            return NumberExpression(ctx.value.text)
        
        if ctx.op.text == '/':
            return DivExpression(
                self.visit(
                    ctx.left,
                ),
                self.visit(
                    ctx.right,
                )
            )
        elif ctx.op.text == '*':
            return MulExpression(
                self.visit(
                    ctx.left,
                ),
                self.visit(
                    ctx.right
                ),
            )
        elif ctx.op.text == '+':
            return AddExpression(
                self.visit(
                    ctx.left,
                ),
                self.visit(
                    ctx.right,
                ),
            )



del ExprParser