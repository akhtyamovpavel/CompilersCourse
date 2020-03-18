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

    ScopeLayer* root = visitor.GetRoot();
    Interpreter interpreter(root);
    return interpreter.GetResult(program);
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
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

