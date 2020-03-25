//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include <types/FunctionType.h>
#include <stack>
#include <grammar/functions/Function.h>
class Frame {
 public:
  explicit Frame(std::shared_ptr<FunctionType> function);
  void SetParams(const std::vector<int>& values);

  size_t AllocVariable();

  void DeallocScope();
  void AllocScope();

  int Get(int index) const;

  void Set(int index, int value);

 private:
  std::stack<int> offsets_;
  std::vector<int> params_;
  std::vector<int> variables_;

};



