//
// Created by akhtyamovpavel on 3/11/21.
//


#pragma once

#include "BaseSymbol.h"

#include <string>
class StArgument : public BaseSymbol {
 public:
  StArgument(std::string argument);
  std::string type = "int";
};


