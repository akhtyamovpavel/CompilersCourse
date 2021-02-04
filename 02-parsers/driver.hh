#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"


class Driver {
 public:
    Driver();
    std::map<std::string, int> variables;
    int result;
    int parse(const std::string& f);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    bool location_debug;
 private:
    std::ifstream stream;

};
