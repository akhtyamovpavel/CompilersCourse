//
// Created by akhtyamovpavel on 4/7/20.
//

#include "LtExpression.h"
void LtExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
LtExpression::LtExpression(Expression *first, Expression *second) : first(first), second(second) {

}
