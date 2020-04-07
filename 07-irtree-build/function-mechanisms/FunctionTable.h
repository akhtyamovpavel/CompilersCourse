//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include <symbol_table/Symbol.h>

#include <stack>

class FunctionTable {
 public:
  void Put(Symbol symbol, int value);

  void CreateVariable(Symbol symbol);


  int Get(Symbol key);

  void BeginScope();
  void EndScope();

 private:
  std::unordered_map<Symbol, std::stack<int>> values_;
  std::stack<Symbol> symbols_;
};



