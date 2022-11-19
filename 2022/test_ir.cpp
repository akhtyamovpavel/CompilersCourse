#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>

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

  builder_.SetInsertPoint(entry);

  

  std::error_code errorCode;

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

//   

  std::string hello_world = "Hello world\n";
  auto fmt = llvm::ConstantDataArray::getString(context_, hello_world);

  auto string_alloca = builder_.CreateAlloca(fmt->getType());

  auto string_value = builder_.CreateStore(fmt, string_alloca);

  auto formatted_string = builder_.CreateBitCast(string_alloca, builder_.getInt8PtrTy());
  
  auto result = builder_.CreateCall(printf_function, {formatted_string});


  
  /////// Create if

  auto true_entry = llvm::BasicBlock::Create(context_, "btrue", function_llvm);
  auto false_entry = llvm::BasicBlock::Create(context_, "bfalse", function_llvm);
  auto end_entry = llvm::BasicBlock::Create(context_, "bend", function_llvm);

  auto int_type = llvm::Type::getInt32Ty(context_);
  auto int_ptr_type = llvm::Type::getInt32PtrTy(context_);

  auto a_alloca = builder_.CreateAlloca(int_type);
  auto b_alloca = builder_.CreateAlloca(int_type);

  auto a_value = builder_.CreateStore(
    llvm::ConstantInt::get(context_, llvm::APInt(/*nbits*/32, 2, /*bool*/true)),
    a_alloca
  );

  auto b_value = builder_.CreateStore(
    llvm::ConstantInt::get(context_, llvm::APInt(/*nbits*/32, 5, /*bool*/true)),
    b_alloca
  );


  builder_.CreateCondBr(
    builder_.CreateICmpSGT(
        builder_.CreateLoad(int_type, a_alloca),
        builder_.CreateLoad(int_type, b_alloca)
    ),
    true_entry, false_entry
  );

  builder_.SetInsertPoint(true_entry);
  auto result2 = builder_.CreateCall(printf_function, {formatted_string});
  builder_.CreateBr(end_entry);

  builder_.SetInsertPoint(false_entry);

  builder_.CreateBr(end_entry);
  builder_.SetInsertPoint(end_entry);

  builder_.CreateRetVoid();

  llvm::raw_fd_ostream ll("test_ir.ll", errorCode);
  module_.print(ll, nullptr);
  module_.print(llvm::errs(), nullptr);

  /**
   * a = 2
   * b = 5
   * if (a > b) {
   *    printf("Hello world\n");
   * } else {
   * }
  */
}