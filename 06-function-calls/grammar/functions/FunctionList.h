//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include <base_elements/BaseElement.h>
#include "Function.h"

#include <vector>
class FunctionList : public BaseElement {
 public:
  void Accept(Visitor *visitor) override;

  FunctionList();

  void AddFunction(Function* function);
  std::vector<Function*> functions_;


};



