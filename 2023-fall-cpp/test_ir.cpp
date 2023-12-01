#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

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

  auto entry = llvm::BasicBlock::Create(
    context_, "entry", function_llvm
    );

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

  // a + b function
  // int add(int a, int b) {}
  auto add_function_type = llvm::FunctionType::get(
    llvm::Type::getInt32Ty(context_),
    {builder_.getInt32Ty(), builder_.getInt32Ty()},
    false
  );

  auto add_function = llvm::Function::Create(
    add_function_type,
    llvm::Function::ExternalLinkage,
    "add",
    module_
  );

  std::string hello_world = "Hello world\n";
  auto fmt = llvm::ConstantDataArray::getString(context_, hello_world);
  auto string_alloca = builder_.CreateAlloca(fmt->getType());
  auto string_value = builder_.CreateStore(fmt, string_alloca);

  auto formatted_string = builder_.CreateBitCast(
    string_alloca, builder_.getInt8PtrTy()
  );

  std::string int_string = "%d\n";
  auto fmt_int = llvm::ConstantDataArray::getString(context_, int_string);
  auto string_int_alloca = builder_.CreateAlloca(fmt_int->getType());
  auto string_int_value = builder_.CreateStore(fmt_int, string_int_alloca);

  auto formatted_int_string = builder_.CreateBitCast(
    string_int_alloca, builder_.getInt8PtrTy()
  );
  
  // auto result = builder_.CreateCall(
  //   printf_function, {formatted_string}
  // );


  
  /////// Create if

  auto true_entry = llvm::BasicBlock::Create(context_, "btrue", function_llvm);
  auto false_entry = llvm::BasicBlock::Create(context_, "bfalse", function_llvm);
  auto end_entry = llvm::BasicBlock::Create(context_, "bend", function_llvm);

  auto int_type = llvm::Type::getInt32Ty(context_);
  auto int_ptr_type = llvm::Type::getInt32PtrTy(context_);

  auto a_alloca = builder_.CreateAlloca(int_type);
  auto b_alloca = builder_.CreateAlloca(int_type);

  auto a_value = builder_.CreateStore(
    llvm::ConstantInt::get(
      context_, llvm::APInt(/*nbits*/32, 2, /*bool*/true)),
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
  // true branch
  builder_.SetInsertPoint(true_entry);
  auto result2 = builder_.CreateCall(printf_function, {formatted_string});
  builder_.CreateBr(end_entry);

  // false branch
  builder_.SetInsertPoint(false_entry);

  builder_.CreateBr(end_entry);
  builder_.SetInsertPoint(end_entry);

  // Call Plus function


  auto result = builder_.CreateCall(
    add_function, {
      builder_.CreateLoad(int_type, a_alloca),
      builder_.CreateLoad(int_type, b_alloca)
    }
  );

  auto result3 = builder_.CreateCall(
    printf_function, {formatted_int_string, result});

  builder_.CreateRetVoid();

  // Add function start
  auto entry_add = llvm::BasicBlock::Create(
    context_, "entry", add_function
    );


  builder_.SetInsertPoint(entry_add);

  auto first_arg = add_function->getArg(0);
  auto second_arg = add_function->getArg(1);

  auto sum = builder_.CreateAdd(
    first_arg, second_arg, "added", false, true
  );


  builder_.CreateRet(sum);

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