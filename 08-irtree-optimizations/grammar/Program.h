#pragma once

#include "statements/AssignmentList.h"
#include "expressions/Expression.h"
#include <functions/FunctionList.h>

class Program {
 public:
  explicit Program(FunctionList* function_list);
  FunctionList* function_list_;
};