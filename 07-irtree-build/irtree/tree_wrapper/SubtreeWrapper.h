#pragma once

#include "../generators/Label.h"
#include "../nodes/expressions/Expression.h"
#include "../nodes/statements/Statement.h"

namespace IRT {
class SubtreeWrapper {
 public:
  virtual ~SubtreeWrapper() = default;
  virtual Expression* ToExpression() = 0;
  virtual Statement* ToStatement() = 0;
  virtual Statement* ToConditional(Label true_label, Label false_label) = 0;
};

}