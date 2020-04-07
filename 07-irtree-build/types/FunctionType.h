//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#pragma once

#include "Type.h"

#include <vector>
#include <string>
class FunctionType : public Type {
 public:
  FunctionType(const std::vector<std::string>& argument_names);
  std::vector<Type*> arguments_;
  std::vector<std::string> argument_names_;

};



