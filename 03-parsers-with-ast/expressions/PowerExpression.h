#pragma once
#include "Expression.h"

class PowerExpression: public Expression {
 public:
  PowerExpression(Expression* expr1, Expression* expr2);
  int eval(const Driver& driver) const;
 private:
  Expression* first;
  Expression* second;
};