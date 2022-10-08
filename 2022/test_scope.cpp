//
// Created by akhtyamovpavel on 3/11/21.
//

#include <scopes/BaseScope.h>
#include <symbols/StVariable.h>
#include <symbols/StFunction.h>

#include <cassert>

int main() {

  BaseScope global_scope;

  global_scope.elements["six"] = new StVariable("six");

  Function function("main", new ParamList(), new StatementList());
  global_scope.elements["main"] = new StFunction(
    &function
  );

  ParamList foo_param_list;
  foo_param_list.AddParam("a");
  foo_param_list.AddParam("b");
  foo_param_list.AddParam("c");

  Function foo("foo", &foo_param_list, new StatementList());

  global_scope.elements["foo"] = new StFunction(
      &foo
  );

  StFunction* foo_result = dynamic_cast<StFunction*>(global_scope.elements["foo"]);

  assert(foo_result->arguments[0].name == "a");
  assert(foo_result->arguments[1].name == "b");
  assert(foo_result->arguments[2].name == "c");

  BaseScope main_scope;
  main_scope.elements["three"] = new StVariable("three");
  main_scope.elements["four"] = new StVariable("four");


  BaseScope foo_scope;

  foo_scope.elements["a"] = new StArgument("a");
  foo_scope.elements["b"] = new StArgument("b");
  foo_scope.elements["c"] = new StArgument("c");

}