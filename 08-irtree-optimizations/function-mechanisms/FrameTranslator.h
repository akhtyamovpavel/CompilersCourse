//
// Created by akhtyamovpavel on 4/14/20.
//


#pragma once

#include <string>
#include <unordered_map>
#include <function-mechanisms/address/Address.h>
#include <stack>
#include <vector>
namespace IRT {
class FrameTranslator {
 public:
  FrameTranslator(const std::string& function_name);
  void SetupScope();
  void TearDownScope();

  void AddVariable(const std::string& name);
  void AddLocalVariable(const std::string& name);
  void AddReturnAddress();

  void AddArgumentAddress(const std::string& name);

  Address* FramePointer();
  Address* GetAddress(const std::string& name);
  Address* GetReturnValueAddress();

 private:
  std::string return_address_ = "::return";
  std::string frame_pointer_address_ = "::fp";
  std::string return_value_address_ = "::return_value";

  std::unordered_map<std::string, std::stack<Address*> > addresses_;

  std::stack<std::string> symbols_;
  std::vector<std::string> variables_;
  int word_size_ = 4;
  std::string function_name_;

  std::stack<int> scope_offsets_;
  int GetOffset();
  int max_offset_ = 0;
};

}

