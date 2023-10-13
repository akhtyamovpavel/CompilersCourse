from nodes.expressions.Expression import Expression


class BraceExpression(Expression):

    def __init__(
            self,
            expression: Expression
        ) -> None:
        self.expression = expression
    
    def accept(self, visitor):
        return visitor.visit_brace_expression(self)
