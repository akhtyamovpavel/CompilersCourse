#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <string>

int main() {
    llvm::LLVMContext context_;
  llvm::IRBuilder<> builder_(context_);
  llvm::Module module_("file", context_);

  // Function with no args that return void
  auto function_type = llvm::FunctionType::get(
    llvm::Type::getVoidTy(context_), false
  );

  // Create main function
  auto function_llvm = llvm::Function::Create(
    function_type,
    llvm::Function::ExternalLinkage,
    "main",
    module_
  );

  auto entry = llvm::BasicBlock::Create(context_, "entry", function_llvm);

  auto printf_function_type = llvm::FunctionType::get(
    llvm::Type::getInt32Ty(context_), 
    {builder_.getInt8PtrTy()},
    true
  );

  auto printf_function = llvm::Function::Create(
    printf_function_type,
    llvm::Function::ExternalLinkage,
    "printf",
    module_    
  );

  auto int_type = llvm::Type::getInt32Ty(context_);
  auto bool_type = llvm::Type::getInt1Ty(context_);
  auto bool_ptr_type = llvm::Type::getInt1PtrTy(context_);


  builder_.SetInsertPoint(entry);

  

  auto true_alloca = builder_.CreateAlloca(bool_type); // create true_ptr

  builder_.CreateStore(
    llvm::ConstantInt::getTrue(context_),
    true_alloca
  ); // true_ptr <- true

  auto true_load = builder_.CreateLoad(bool_type, true_alloca); // load true_ptr 

  auto a_alloca = builder_.CreateAlloca(int_type);

  auto true_int = builder_.CreateIntCast(
    true_load, int_type, false
  );

  builder_.CreateStore(
    true_int,
    a_alloca
  );

  auto a_load = builder_.CreateLoad(int_type, a_alloca);

  // Cast to int


  // printf("%d\n", a);

  std::string format = "%d\n";
  auto fmt = llvm::ConstantDataArray::getString(context_, format);

  auto string_alloca = builder_.CreateAlloca(fmt->getType());

  auto string_value = builder_.CreateStore(fmt, string_alloca);

  auto formatted_string = builder_.CreateBitCast(string_alloca, builder_.getInt8PtrTy());
  
  auto result = builder_.CreateCall(printf_function, {formatted_string, a_load});

  builder_.CreateRetVoid();


  std::error_code errorCode;

  llvm::raw_fd_ostream ll("test_types.ll", errorCode);
  module_.print(ll, nullptr);
  module_.print(llvm::errs(), nullptr);
}