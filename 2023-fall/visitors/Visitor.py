from __future__ import annotations
from abc import ABC, abstractmethod
from nodes.Program import Program
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.MulExpression import MulExpression

from nodes.expressions.NumberExpression import NumberExpression
from nodes.expressions.SubExpression import SubExpression


class Visitor(ABC):

    @abstractmethod
    def visit_number_expression(expression: NumberExpression):
        pass

    @abstractmethod
    def visit_add_expression(expression: AddExpression):
        pass

    @abstractmethod
    def visit_sub_expression(expression: SubExpression):
        pass

    @abstractmethod
    def visit_mul_expression(expression: MulExpression):
        pass

    @abstractmethod
    def visit_div_expression(expression: DivExpression):
        pass

    @abstractmethod
    def visit_brace_expression(expression: BraceExpression):
        pass

    @abstractmethod
    def visit_program(program: Program):
        pass
