//
// Created by akhtyamovpavel on 4/7/20.
//

#include "AndExpression.h"
void AndExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
AndExpression::AndExpression(Expression *e1, Expression *e2): first(e1), second(e2) {

}
