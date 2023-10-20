from __future__ import annotations
from typing import List

from nodes.expressions.Expression import Expression
from typing import TYPE_CHECKING


if TYPE_CHECKING:
    from visitors.Visitor import Visitor


class PrintStatement:
    def __init__(
            self,
            expression: Expression
        ) -> None:
        self.expression = expression
    
    def accept(self, visitor: Visitor):
        return visitor.visit_print_statement(self)
