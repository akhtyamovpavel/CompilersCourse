#pragma once

#include <map>
#include <string>
#include <fstream>
#include <unordered_map>
#include "grammar/scanner.h"
#include "parser.hh"

#include "grammar/Program.h"



class Driver {
 public:
    Driver();
    int result;
    int parse(const std::string& f);
    int Evaluate();
    void PrintTree(const std::string& filename);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    Program* program;

  std::unordered_map<std::string, int> variables;
 private:
    std::ifstream stream;


};
