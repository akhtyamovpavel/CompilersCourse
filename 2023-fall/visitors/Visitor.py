from __future__ import annotations
from abc import ABC, abstractmethod
from nodes.Program import Program
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.MulExpression import MulExpression
from nodes.expressions.IdentExpression import IdentExpression

from nodes.expressions.NumberExpression import NumberExpression
from nodes.expressions.SubExpression import SubExpression
from nodes.statements.AssignStatement import AssignStatement
from nodes.statements.PrintStatement import PrintStatement


class Visitor(ABC):

    @abstractmethod
    def visit_number_expression(self, expression: NumberExpression):
        pass

    @abstractmethod
    def visit_add_expression(self, expression: AddExpression):
        pass

    @abstractmethod
    def visit_sub_expression(self, expression: SubExpression):
        pass

    @abstractmethod
    def visit_mul_expression(self, expression: MulExpression):
        pass

    @abstractmethod
    def visit_div_expression(self, expression: DivExpression):
        pass

    @abstractmethod
    def visit_brace_expression(self, expression: BraceExpression):
        pass

    @abstractmethod
    def visit_program(self, program: Program):
        pass

    @abstractmethod
    def visit_assign_statement(self, statement: AssignStatement):
        pass

    @abstractmethod
    def visit_print_statement(self, statement: PrintStatement):
        pass

    @abstractmethod
    def visit_ident_expression(self, expression: IdentExpression):
        pass
