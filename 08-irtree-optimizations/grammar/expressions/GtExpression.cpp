//
// Created by akhtyamovpavel on 4/7/20.
//

#include "GtExpression.h"
void GtExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

GtExpression::GtExpression(Expression *first, Expression *second) : first(first), second(second) {

}
