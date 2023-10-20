from nodes.expressions.Expression import Expression


class IdentExpression(Expression):
    def __init__(
            self,
            name: str,
        ) -> None:
        self.name = name
    
    def accept(self, visitor):
        return visitor.visit_ident_expression(self)
