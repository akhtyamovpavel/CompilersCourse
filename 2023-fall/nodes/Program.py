from __future__ import annotations
from typing import List

from nodes.expressions.Expression import Expression
from typing import TYPE_CHECKING


if TYPE_CHECKING:
    from visitors.Visitor import Visitor


class Program:
    def __init__(
            self,
            expressions: List[Expression]
        ) -> None:
        self.expressions = expressions
    
    def accept(self, visitor: Visitor):
        return visitor.visit_program(self)
