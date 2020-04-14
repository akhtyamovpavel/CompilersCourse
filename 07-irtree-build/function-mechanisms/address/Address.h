#pragma once

#include <irtree/nodes/expressions/Expression.h>
namespace IRT {

class Address {
 public:
  virtual ~Address() = default;
  virtual Expression* ToExpression() = 0;
};

}
