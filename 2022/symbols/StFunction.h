
#pragma once

#include "BaseSymbol.h"
#include "StArgument.h"

#include <vector>
#include <grammar/functions/Function.h>

class StFunction: public BaseSymbol {
 public:
  std::vector<StArgument> arguments;
  std::string return_type = "void";
  explicit StFunction(Function* function);
};


