//
// Created by akhtyamovpavel on 4/9/20.
//


#pragma once

#include "../../types/BinaryOperatorType.h"
#include "Expression.h"
namespace IRT {
class BinopExpression : public Expression {
 public:
  BinopExpression(BinaryOperatorType type,
                  Expression *first,
                  Expression *second);
  void Accept(Visitor *visitor) override;
  BinaryOperatorType operator_type_;
  Expression* first_;
  Expression* second_;
};

}


