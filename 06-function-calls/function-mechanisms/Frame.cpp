//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include "Frame.h"
Frame::Frame(std::shared_ptr<FunctionType> function) {
  params_.resize(function->arguments_.size());

  AllocScope();
}

void Frame::SetParams(const std::vector<int> &values) {
  if (params_.size() != values.size()) {
    throw std::runtime_error("Mismatched number of arguments");
  }
  params_ = values;
}

size_t Frame::AllocVariable() {
  size_t index = variables_.size();
  variables_.push_back(0);

  return index;
}

void Frame::DeallocScope() {
  size_t new_size = offsets_.top();
  offsets_.pop();

  // TODO(@akhtyamovpavel) - Call destructors
  variables_.resize(new_size);
}

void Frame::AllocScope() {
  offsets_.push(variables_.size());
}

int Frame::Get(int index) const {
  if (index >= 0) {
    return variables_.at(index);
  } else {
    return params_.at(-index - 1);
  }
}

void Frame::Set(int index, int value) {
  if (index >= 0) {
    variables_.at(index) = value;
  } else {
    params_.at(-index - 1) = value;
  }
}
