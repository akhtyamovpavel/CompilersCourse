from __future__ import annotations
from abc import ABC, abstractmethod
from nodes.Program import Program
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.BraceExpression import BraceExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.MulExpression import MulExpression

from nodes.expressions.NumberExpression import NumberExpression
from nodes.expressions.SubExpression import SubExpression
from visitors.Visitor import Visitor


class InterpreterVisitor(Visitor):

    def visit_number_expression(self, expression: NumberExpression):
        return expression.number

    def visit_add_expression(self, expression: AddExpression):
        return expression.left.accept(self) + expression.right.accept(self)

    def visit_sub_expression(self, expression: SubExpression):
        return expression.left.accept(self) - expression.right.accept(self)

    def visit_mul_expression(self, expression: MulExpression):
        return expression.left.accept(self) * expression.right.accept(self)

    def visit_div_expression(self, expression: DivExpression):
        return expression.left.accept(self) // expression.right.accept(self)

    def visit_brace_expression(self, expression: BraceExpression):
        return expression.expression.accept(self)

    def visit_program(self, program: Program):
        for expression in program.expressions:
            print(expression.accept(self))
