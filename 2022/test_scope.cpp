//
// Created by akhtyamovpavel on 3/11/21.
//

#include <scopes/BaseScope.h>
#include <symbols/VariableSymbol.h>

#include <cassert>
#include <iostream>


int main() {
  auto main_scope = BaseScope();
  
  auto* three_var = new VariableSymbol();
  three_var->name = "three";

  main_scope.elements["three"] = three_var;

  auto* four_var = new VariableSymbol();
  four_var->name = "four";

  main_scope.elements["four"] = four_var;

  auto* shadow_scope = new BaseScope(&main_scope);
  auto* three_var_shadow = new VariableSymbol();
  three_var_shadow->name = "three";
  
  shadow_scope->elements["three"] = three_var_shadow;

  main_scope.children_.push_back(shadow_scope);

  auto symbol = shadow_scope->GetVariable("four");
  std::cout << symbol->name;
}