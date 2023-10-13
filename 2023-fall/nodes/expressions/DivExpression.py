from nodes.expressions.Expression import Expression


class DivExpression(Expression):
    def __init__(
            self,
            left: Expression,
            right: Expression
        ) -> None:
        self.left = left
        self.right = right

    def accept(self, visitor):
        return visitor.visit_add_expression(self)
