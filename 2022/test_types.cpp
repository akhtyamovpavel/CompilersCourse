#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/ADT/IntrusiveRefCntPtr.h>



#include <string>

using namespace llvm;
using namespace llvm::sys;


void writeModuleToFile(llvm::Module *module)
{
    auto TargetTriple = getDefaultTargetTriple();
    LLVMInitializeX86TargetInfo();
    LLVMInitializeX86Target();
    LLVMInitializeX86TargetMC();
    LLVMInitializeX86AsmParser();
    LLVMInitializeX86AsmPrinter();

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);
    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    module->setDataLayout(TargetMachine->createDataLayout());
    module->setTargetTriple(TargetTriple);

    auto Filename = "output.o";
    std::error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType))
    {
        errs() << "TargetMachine can't emit a file of this type";
        return;
    }
    pass.run(*module);
    dest.flush();

    // IntrusiveRefCntPtr<clang::DiagnosticOptions> DiagOpts = new clang::DiagnosticOptions;
    // clang::TextDiagnosticPrinter *DiagClient = new clang::TextDiagnosticPrinter(errs(), &*DiagOpts);
    // IntrusiveRefCntPtr<clang::DiagnosticIDs> DiagID(new clang::DiagnosticIDs());
    // clang::DiagnosticsEngine Diags(DiagID, &*DiagOpts, DiagClient);
    // clang::driver::Driver TheDriver("/usr/bin/clang++-12", TargetTriple, Diags);

    // auto args = ArrayRef<const char *>{"-g", "output.o", "-o", "main"};

    // std::unique_ptr<clang::driver::Compilation> C(TheDriver.BuildCompilation(args));

    // if (C && !C->containsError())
    // {
    //     SmallVector<std::pair<int, const clang::driver::Command *>, 4> FailingCommands;
    //     TheDriver.ExecuteCompilation(*C, FailingCommands);
    // }

    // remove(Filename);
}

int main() {
  llvm::LLVMContext context_;
  llvm::IRBuilder<> builder_(context_);
  llvm::Module module_("file", context_);

  auto int_type = llvm::Type::getInt32Ty(context_);
  auto bool_type = llvm::Type::getInt1Ty(context_);
  auto bool_ptr_type = llvm::Type::getInt1PtrTy(context_);

  auto struct_type = llvm::StructType::create(context_, "Foo");

  auto myStructPtrType = llvm::PointerType::get(struct_type, 0);
  struct_type->setBody({ int_type, int_type }, false);

  // llvm::StructType::create(
  //   {int_type, bool_type},
  //   "Foo"
  // );

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

  auto function_bar_type = llvm::FunctionType::get(
    llvm::Type::getInt32Ty(context_), 
    {llvm::Type::getInt32Ty(context_)},
    false
  );

  auto bar_function = llvm::Function::Create(
    function_bar_type,
    llvm::Function::ExternalLinkage,
    "bar",
    module_
  );

  auto bar_entry = llvm::BasicBlock::Create(context_, "entry", bar_function);

  builder_.SetInsertPoint(bar_entry);

  builder_.CreateRet(bar_function->getArg(0));


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

  auto foo_alloca = builder_.CreateAlloca(struct_type);

  auto x = builder_.CreateStructGEP(struct_type, foo_alloca, 0);

  auto x_value = builder_.CreateStore(
    llvm::ConstantInt::get(context_, llvm::APInt(/*nbits*/32, 5, /*bool*/true)),
    x
  );

  auto x_loaded = builder_.CreateLoad(x);

  auto result_bar = builder_.CreateCall(bar_function, {x_loaded});

  auto result_x = builder_.CreateCall(printf_function, {formatted_string, result_bar});

  // Get a type

//   auto a_type = a_load->getType();
//   if (a_type == llvm::Type::Integer)
  builder_.CreateRetVoid();

  // writeModuleToFile(&module_);

  std::error_code errorCode;

  llvm::raw_fd_ostream ll("test_types.ll", errorCode);
  module_.print(ll, nullptr);
  module_.print(llvm::errs(), nullptr);

  
}