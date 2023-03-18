//
// Created by akhtyamovpavel on 3/11/21.
//

#include <scopes/BaseScope.h>
#include <symbols/VariableSymbol.h>
#include <symbols/Function.h>

#include <cassert>
#include <iostream>


int main() {
  auto global_scope = symbols::BaseScope();

  auto main_function = symbols::Function();

  main_function.return_type = "int";
  main_function.name = "main";
  global_scope.elements["main"] = &main_function;

  auto main_scope = symbols::BaseScope(&global_scope);

  global_scope.named_children_["main"] = &main_scope;
  
  auto* three_var = new symbols::VariableSymbol();
  three_var->name = "three";

  main_scope.elements["three"] = three_var;

  auto* four_var = new symbols::VariableSymbol();
  four_var->name = "four";

  main_scope.elements["four"] = four_var;

  auto* shadow_scope = new symbols::BaseScope(&main_scope);
  auto* three_var_shadow = new symbols::VariableSymbol();
  three_var_shadow->name = "three";
  
  shadow_scope->elements["three"] = three_var_shadow;

  main_scope.children_.push_back(shadow_scope);

  auto symbol = shadow_scope->GetVariable("four");
  std::cout << symbol->name << std::endl;

  auto bar_fn = symbols::Function();

  global_scope.elements["Bar"] = &bar_fn;

  auto x_var = symbols::VariableSymbol();
  x_var.name = "x";

  bar_fn.arguments.push_back(x_var);
  bar_fn.return_type = "int";
  bar_fn.name = "Bar";

  auto bar_fn_scope = symbols::BaseScope(&global_scope);
  
  global_scope.named_children_["Bar"] = &bar_fn_scope;

  auto bar_symbol = shadow_scope->GetVariable("Bar");

  std::cout << bar_symbol->base_type << std::endl;

  symbols::Function* bar_function = dynamic_cast<symbols::Function*>(bar_symbol);

  std::cout << bar_function->return_type << std::endl;
}