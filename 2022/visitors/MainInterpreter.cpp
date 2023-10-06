//
// Created by akhtyamovpavel on 3/11/21.
//

#include <iostream>
#include "MainInterpreter.h"
#include "elements.h"

void MainInterpreter::Visit(NumberExpression *expression) {
  SetValue(expression->value_);
}

void MainInterpreter::Visit(AddExpression *expression) {

}
void MainInterpreter::Visit(SubstractExpression *expression) {

}
void MainInterpreter::Visit(MulExpression *expression) {
  SetValue(
    Accept(expression->first) *
    Accept(expression->second)
  );
}
void MainInterpreter::Visit(DivExpression *expression) {

}
void MainInterpreter::Visit(IdentExpression *expression) {
  SetValue(driver_->variables[expression->ident_]);
}

void MainInterpreter::Visit(Assignment *assignment) {
  std::cerr << "Assignment visited" << std::endl;

  int value = Accept(assignment->expression_);
  std::cerr << value << std::endl;
  driver_->variables[assignment->variable_] = value;

}
void MainInterpreter::Visit(VarDecl *var_decl) {

}
void MainInterpreter::Visit(PrintStatement *statement) {
  std::cerr << "Print visited" << std::endl;
  std::cout << "PRINT VALUE" << std::endl;
  std::cout << Accept(statement->expression_) << std::endl;
}

void MainInterpreter::Visit(StatementList *assignment_list) {
  std::cerr << "Assignment list visited" << std::endl;
  for (auto* statement : assignment_list->statements_) {
      statement->Accept(this);
  }
}

void MainInterpreter::Visit(ScopeAssignmentList *list) {

}

void MainInterpreter::Visit(Program *program) {

}
void MainInterpreter::Visit(ParamList *param_list) {

}
void MainInterpreter::Visit(Function *function) {
  std::cerr << "Main function visited" << std::endl;

  function->statements_->Accept(this);
}


void MainInterpreter::Visit(FunctionCallExpression *statement) {

}
void MainInterpreter::Visit(FunctionList *function_list) {

}
void MainInterpreter::Visit(ParamValueList *value_list) {

}
void MainInterpreter::Visit(ReturnStatement *return_statement) {

}
MainInterpreter::MainInterpreter(Driver *driver): driver_(driver) {

}
