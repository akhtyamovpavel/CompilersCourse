# Generated from Expr.g4 by ANTLR 4.13.0
from antlr4 import *
from nodes.Program import Program
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.BraceExpression import BraceExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.IdentExpression import IdentExpression
from nodes.expressions.MulExpression import MulExpression

from nodes.expressions.NumberExpression import NumberExpression
from nodes.expressions.SubExpression import SubExpression
from nodes.statements.AssignStatement import AssignStatement
from nodes.statements.PrintStatement import PrintStatement
from nodes.statements.VarDeclStatement import VarDeclStatement
if "." in __name__:
    from .ExprParser import ExprParser
else:
    from ExprParser import ExprParser

# This class defines a complete generic visitor for a parse tree produced by ExprParser.

class ExprVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by ExprParser#prog.
    def visitProg(self, ctx:ExprParser.ProgContext):
        statements = []

        for statement in ctx.stmt():
            statements.append(self.visit(statement))
        return Program(expressions=statements)

    def visitStmt(self, ctx:ExprParser.StmtContext):
        if ctx.assign is not None:
            return AssignStatement(
                variable=ctx.ident.text,
                expression=self.visit(ctx.assign)
            )
        elif ctx.let is not None:
            return VarDeclStatement(
                name=ctx.var.text,
            )
        else:
            return PrintStatement(self.visit(ctx.printexp))

    # Visit a parse tree produced by ExprParser#expr.
    def visitExpr(self, ctx:ExprParser.ExprContext):
        if ctx.value is not None:
            return NumberExpression(ctx.value.text)
        
        if ctx.exp is not None:
            return BraceExpression(
                self.visit(ctx.exp)
            )
        
        if ctx.ident is not None:
            return IdentExpression(
                ctx.ident.text
            )

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
        elif ctx.op.text == '-':
            return SubExpression(
                self.visit(
                    ctx.left,
                ),
                self.visit(
                    ctx.right
                ),
            )



del ExprParser