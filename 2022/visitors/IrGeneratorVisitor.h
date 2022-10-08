#pragma once

#include "TemplateVisitor.h"
#include <include/driver.hh>


#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <unordered_map>



class IrGeneratorVisitor : public TemplateVisitor<llvm::Value *> {
 public:
  IrGeneratorVisitor();
  void Visit(NumberExpression *expression) override;
  void Visit(AddExpression *expression) override;
  void Visit(SubstractExpression *expression) override;
  void Visit(MulExpression *expression) override;
  void Visit(DivExpression *expression) override;
  void Visit(IdentExpression *expression) override;
  void Visit(Assignment *assignment) override;
  void Visit(VarDecl *var_decl) override;
  void Visit(PrintStatement *statement) override;
  void Visit(StatementList *assignment_list) override;
  void Visit(ScopeAssignmentList *list) override;
  void Visit(Program *program) override;
  void Visit(ParamList *param_list) override;
  void Visit(Function *function) override;
  void Visit(FunctionCallExpression *statement) override;
  void Visit(FunctionList *function_list) override;
  void Visit(ParamValueList *value_list) override;
  void Visit(ReturnStatement *return_statement) override;

  llvm::Module* GetModule();

 private:
  llvm::LLVMContext context_;
  llvm::IRBuilder<> builder_;
  llvm::Module module_;
  std::unordered_map<std::string, llvm::AllocaInst*> named_values_;
};