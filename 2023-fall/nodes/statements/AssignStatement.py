from __future__ import annotations
from typing import List

from nodes.expressions.Expression import Expression
from typing import TYPE_CHECKING


if TYPE_CHECKING:
    from visitors.Visitor import Visitor


class AssignStatement:
    def __init__(
            self,
            variable: str,
            expression: Expression,
        ) -> None:
        self.variable = variable
        self.expression = expression
    
    def accept(self, visitor: Visitor):
        return visitor.visit_assign_statement(self)
