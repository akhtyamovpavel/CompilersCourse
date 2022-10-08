//
// Created by akhtyamovpavel on 3/11/21.
//

#include "StFunction.h"

StFunction::StFunction(Function *function) {
  name = function->name_;
  for (auto argument: function->param_list_->params_) {
    arguments.emplace_back(argument);
  }

}
