//
// Created by akhtyamovpavel on 4/14/20.
//

#include <function-mechanisms/address/AddressInRegister.h>
#include <function-mechanisms/address/AddressInFrame.h>
#include "FrameTranslator.h"

namespace IRT {
FrameTranslator::FrameTranslator(const std::string &function_name)
    : function_name_(function_name) {

  addresses_[frame_pointer_address_].push(new AddressInRegister(
      Temporary(frame_pointer_address_)
  ));

  addresses_[return_value_address_].push(new AddressInRegister(
      Temporary(return_value_address_)
      ));
}
void FrameTranslator::SetupScope() {
  symbols_.push("{");
}

void FrameTranslator::TearDownScope() {
  while (symbols_.top() != "{") {
    std::string symbol = symbols_.top();

//    std::cerr << "Popping " << symbol.GetName() << std::endl;

    addresses_[symbol].pop();
    if (addresses_[symbol].empty()) {
      addresses_.erase(symbol);
    }
    symbols_.pop();
  }
  symbols_.pop();
}

void FrameTranslator::AddLocalVariable(const std::string &name) {
  AddVariable(name);
}

Address *FrameTranslator::FramePointer() {
  return addresses_[frame_pointer_address_].top();
}

int FrameTranslator::GetOffset() {
  int tmp = max_offset_;
  max_offset_ += word_size_;
  return tmp;
}
void FrameTranslator::AddArgumentAddress(const std::string &name) {
  AddVariable(name);
}

void FrameTranslator::AddVariable(const std::string &name) {
  symbols_.push(name);

  if (addresses_.find(name) == addresses_.end()) {
    addresses_[name];
  }
  addresses_[name].push(
      new AddressInFrame(FramePointer(), GetOffset())
  );
}
Address *FrameTranslator::GetAddress(const std::string &name) {
  return addresses_[name].top();
}
void FrameTranslator::AddReturnAddress() {
  AddVariable(return_address_);
}

Address *FrameTranslator::GetReturnValueAddress() {
  return  GetAddress(return_value_address_);
}

}