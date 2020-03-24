//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#include "ParamList.h"

#include <algorithm>

#include <stdexcept>

ParamList::ParamList(const std::string &param) {
  params_ = {param};
}

ParamList::ParamList() {}

void ParamList::AddParam(const std::string &param) {
  if (std::find(params_.begin(), params_.end(), param) != params_.end()) {
    throw std::runtime_error("Param has been defined");

  }
  params_.push_back(param);
}

void ParamList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
