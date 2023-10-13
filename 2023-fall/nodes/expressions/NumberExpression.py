from __future__ import annotations
from typing import TYPE_CHECKING
from nodes.expressions.Expression import Expression

if TYPE_CHECKING:
    from visitors.Visitor import Visitor


class NumberExpression(Expression):

    def __init__(self, number: str) -> None:
        self.number = int(number)

    def accept(self, visitor: Visitor):
        return visitor.visit_number_expression(self)
