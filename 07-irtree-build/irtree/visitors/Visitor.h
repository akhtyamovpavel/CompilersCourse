#pragma once

namespace IRT {

class ExpStatement;
class ConstExpression;

class Visitor {
 public:
  virtual ~Visitor() = default;

  virtual void Visit(ExpStatement* stmt) = 0;
  virtual void Visit(ConstExpression* const_expression) = 0;
};
};
