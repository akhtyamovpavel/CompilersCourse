//#include <visitors/FunctionCallVisitor.h>
//#include <function-mechanisms/FunctionStorage.h>
#include <visitors/MainInterpreter.h>
#include <visitors/PrintVisitor.h>
#include "driver.hh"
#include "parser.hh"

//#include "visitors/Interpreter.h"
//#include "visitors/PrintVisitor.h"
//
//#include "visitors/SymbolTreeVisitor.h"



Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    std::cout << "parser " << res << std::endl;
    scan_end();
    return res;
}

int Driver::Evaluate() {

  Function* main_function = nullptr;

  for (Function* function: program->function_list_->functions_) {
    if (function->name_ == "main") {
      main_function = function;
    }
  }

  MainInterpreter visitor(this);

  main_function->Accept(&visitor);
//  visitor.Visit(main_function);
  return 0;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty() || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
    stream.close();
}

void Driver::PrintTree(const std::string& filename) {
    PrintVisitor visitor(filename);
    visitor.Visit(program);
}

