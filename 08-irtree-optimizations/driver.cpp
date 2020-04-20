#include <visitors/FunctionCallVisitor.h>
#include <function-mechanisms/FunctionStorage.h>
#include <visitors/IrtreeBuildVisitor.h>
#include <irtree/visitors/PrintVisitor.h>
#include <irtree/visitors/DoubleCallEliminateVisitor.h>
#include "driver.hh"
#include "parser.hh"

#include "visitors/Interpreter.h"
#include "visitors/PrintVisitor.h"

#include "visitors/SymbolTreeVisitor.h"



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
    SymbolTreeVisitor visitor;
    visitor.Visit(program);

    std::cout << "Symbol tree built" << std::endl;

    ScopeLayerTree root = visitor.GetRoot();

    auto functions = visitor.GetFunctions();

    FunctionStorage& storage = FunctionStorage::GetInstance();
    for (auto it : functions) {
        storage.Set(it.first, it.second);
    }

    Function* main_function = storage.Get(Symbol("main"));

    std::shared_ptr<FunctionType> function_type = std::dynamic_pointer_cast<FunctionType>(
        root.Get(Symbol("main"))
    );

    FunctionCallVisitor function_visitor(
        root.GetFunctionScopeByName(Symbol("main")),
        function_type
      );

    function_visitor.SetTree(&root);

    function_visitor.Visit(main_function);

    root.PrintTree("symbol_tree.txt");

    IrtreeBuildVisitor irt_build_visitor(&root);

    irt_build_visitor.Visit(program);

    IrtMapping methods = irt_build_visitor.GetTrees();

    for (auto func_view = methods.begin(); func_view != methods.end(); ++func_view) {
      IRT::PrintVisitor print_visitor_irt(func_view->first + "_irt.txt");
      methods[func_view->first]->Accept(&print_visitor_irt);

      IRT::DoubleCallEliminateVisitor call_eliminate_visitor;
      methods[func_view->first]->Accept(&call_eliminate_visitor);

      auto stmt_result = call_eliminate_visitor.GetTree();

      IRT::PrintVisitor print_visitor_two(func_view->first + "_without_double_call.txt");
      stmt_result->Accept(&print_visitor_two);

    }
//    Interpreter interpreter(root);
//    int interpreter_result = interpreter.GetResult(program);

//    delete root;
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

