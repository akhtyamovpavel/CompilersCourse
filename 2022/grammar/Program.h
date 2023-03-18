#pragma once

#include "statements/StatementList.h"
#include "expressions/Expression.h"
#include <functions/FunctionList.h>

class Program : public BaseElement {
 public:
  Program(FunctionList* function_list, StatementList* statement_list);
  FunctionList* function_list_;
  StatementList* statement_list_;
  void Accept(Visitor *visitor) override;
};