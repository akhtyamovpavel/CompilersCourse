from __future__ import annotations
from nodes.expressions.Expression import Expression


class SubExpression(Expression):

    def __init__(
            self,
            left: Expression,
            right: Expression
        ) -> None:
        self.left = left
        self.right = right
    
    def accept(self, visitor):
        return visitor.visit_sub_expression(self)
