# Generated from Expr.g4 by ANTLR 4.13.0
from antlr4 import *
if "." in __name__:
    from .ExprParser import ExprParser
else:
    from ExprParser import ExprParser

# This class defines a complete listener for a parse tree produced by ExprParser.
class ExprListener(ParseTreeListener):

    # Enter a parse tree produced by ExprParser#prog.
    def enterProg(self, ctx:ExprParser.ProgContext):
        print(ctx)

    # Exit a parse tree produced by ExprParser#prog.
    def exitProg(self, ctx:ExprParser.ProgContext):
        print(ctx)


    # Enter a parse tree produced by ExprParser#stmt.
    def enterStmt(self, ctx:ExprParser.StmtContext):
        print(ctx)

    # Exit a parse tree produced by ExprParser#stmt.
    def exitStmt(self, ctx:ExprParser.StmtContext):
        print(ctx.printexp)
        print(ctx.assign)


    # Enter a parse tree produced by ExprParser#expr.
    def enterExpr(self, ctx:ExprParser.ExprContext):
        print(ctx)

    # Exit a parse tree produced by ExprParser#expr.
    def exitExpr(self, ctx:ExprParser.ExprContext):
        print(ctx)



del ExprParser