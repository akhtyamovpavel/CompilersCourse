//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include "FrameEmulator.h"
FrameEmulator::FrameEmulator(std::shared_ptr<FunctionType> function) {
  params_.resize(function->arguments_.size());

  AllocScope();
}

void FrameEmulator::SetParams(const std::vector<int> &values) {
  if (params_.size() != values.size()) {
    throw std::runtime_error("Mismatched number of arguments");
  }
  params_ = values;
}

size_t FrameEmulator::AllocVariable() {
  size_t index = variables_.size();
  variables_.push_back(0);

  return index;
}

void FrameEmulator::DeallocScope() {
  size_t new_size = offsets_.top();
  offsets_.pop();

  // TODO(@akhtyamovpavel) - Call destructors
  variables_.resize(new_size);
}

void FrameEmulator::AllocScope() {
  offsets_.push(variables_.size());
}

int FrameEmulator::Get(int index) const {
  if (index >= 0) {
    return variables_.at(index);
  } else {
    return params_.at(-index - 1);
  }
}

void FrameEmulator::Set(int index, int value) {
  if (index >= 0) {
    variables_.at(index) = value;
  } else {
    params_.at(-index - 1) = value;
  }
}

void FrameEmulator::SetReturnValue(int value) {
    return_value_ = value;
}

void FrameEmulator::SetParentFrame(FrameEmulator *frame) {
    parent_frame = frame;

}

void FrameEmulator::SetParentReturnValue(int value) {
    parent_frame->return_value_ = value;

}

bool FrameEmulator::HasParent() {
    return parent_frame != nullptr;
}

int FrameEmulator::GetReturnValue() const {
    return return_value_;
}
