#pragma once

#include "statements/AssignmentList.h"
#include "expressions/Expression.h"
#include <functions/Function.h>

class Program {
 public:
  explicit Program(Function* function);
  Function* function_;
};