//
// Created by akhtyamovpavel on 4/7/20.
//

#include "OrExpression.h"

void OrExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
OrExpression::OrExpression(Expression *e1, Expression *e2) : first(e1), second(e2) {

}
