//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#include "FunctionType.h"
#include "Integer.h"

FunctionType::FunctionType(const std::vector<std::string> &argument_names) : argument_names_(argument_names){
  for (const std::string& name : argument_names) {
    arguments_.push_back(new Integer(0));
  }

}
