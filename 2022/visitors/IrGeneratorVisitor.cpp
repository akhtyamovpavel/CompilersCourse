#include "IrGeneratorVisitor.h"
#include "elements.h"
#include <iostream>


IrGeneratorVisitor::IrGeneratorVisitor():
  builder_(context_),
  module_("file", context_) {

  }

void IrGeneratorVisitor::Visit(NumberExpression *expression) {
    auto alloca = builder_.CreateAlloca(builder_.getInt32Ty());

    llvm::Value* value = builder_.getInt32(expression->value_);
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(AddExpression *expression) {}
void IrGeneratorVisitor::Visit(SubstractExpression *expression) {}
void IrGeneratorVisitor::Visit(MulExpression *expression) {}
void IrGeneratorVisitor::Visit(DivExpression *expression) {}

void IrGeneratorVisitor::Visit(IdentExpression *expression) {
    SetValue(named_values_[expression->ident_]);
}

void IrGeneratorVisitor::Visit(Assignment *assignment) {
    auto pointer = Accept(assignment->expression_);

    auto value = builder_.CreateLoad(builder_.getInt32Ty(), pointer);

    auto variable = named_values_[assignment->variable_];

    builder_.CreateStore(value, variable);
}

void IrGeneratorVisitor::Visit(VarDecl *var_decl) {
    auto function = builder_.GetInsertBlock()->getParent();
    llvm::BasicBlock &block = function->getEntryBlock();
    
    // Insert var decl to the beginning
    llvm::IRBuilder<> tmp(&block, block.begin());

    auto variable = tmp.CreateAlloca(builder_.getInt32Ty(), nullptr, var_decl->variable_);

    named_values_[var_decl->variable_] = variable;
}

void IrGeneratorVisitor::Visit(PrintStatement *statement) {
    std::string string = "%d\n";
    auto fmt = llvm::ConstantDataArray::getString(context_, string);

    auto alloca = builder_.CreateAlloca(fmt->getType());
    builder_.CreateStore(fmt, alloca);

    // cast string to char*
    auto formatted_string = builder_.CreateBitCast(alloca, builder_.getInt8PtrTy());

    auto pointer = Accept(statement->expression_);

    auto value = builder_.CreateLoad(builder_.getInt32Ty(), pointer);

    auto pointer_type = builder_.getInt8PtrTy();

    auto printfType = llvm::FunctionType::get(
        builder_.getInt32Ty(),
        {pointer_type},
        true
    );

    auto printfFunction = llvm::Function::Create(
        printfType, llvm::Function::ExternalLinkage,
        "printf",
        module_
    );

    SetValue(
        builder_.CreateCall(printfFunction, {formatted_string, value}, "printCall")
    );
    
}

void IrGeneratorVisitor::Visit(StatementList *assignment_list) {
    for (auto* statement: assignment_list->statements_) {
        Accept(statement);
    }
}
void IrGeneratorVisitor::Visit(ScopeAssignmentList *list) {}

void IrGeneratorVisitor::Visit(Program *program) {
    Accept(program->function_list_);
}

void IrGeneratorVisitor::Visit(ParamList *param_list) {}

void IrGeneratorVisitor::Visit(Function *function) {
    std::cerr << "Function visited" << std::endl;
    auto function_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context_), false
    );

    auto function_llvm = llvm::Function::Create(
        function_type,
        llvm::Function::ExternalLinkage,
        function->name_,
        module_
    );

    auto entry = llvm::BasicBlock::Create(context_, "entry", function_llvm);

    builder_.SetInsertPoint(entry);

    // TODO (@akhtyamovpavel) Add arguments to function
    Accept(function->statements_);

    builder_.CreateRetVoid();
}

void IrGeneratorVisitor::Visit(FunctionCallExpression *statement) {}
void IrGeneratorVisitor::Visit(FunctionList *function_list) {
    for (auto* function: function_list->functions_) {
        Accept(function);
    }
}
void IrGeneratorVisitor::Visit(ParamValueList *value_list) {}
void IrGeneratorVisitor::Visit(ReturnStatement *return_statement) {}


llvm::Module* IrGeneratorVisitor::GetModule() {
    return &module_;
}
