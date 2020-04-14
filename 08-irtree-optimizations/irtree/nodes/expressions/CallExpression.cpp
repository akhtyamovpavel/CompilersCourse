//
// Created by akhtyamovpavel on 4/14/20.
//

#include "CallExpression.h"
void IRT::CallExpression::Accept(IRT::Visitor *visitor) {
  visitor->Visit(this);

}
IRT::CallExpression::CallExpression(
    IRT::Expression *expression,
    IRT::ExpressionList *args
  ): function_name_(expression), args_(args) {

}
