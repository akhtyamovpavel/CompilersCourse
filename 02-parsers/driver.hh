#pragma once

#include <map>
#include <string>
#include "parser.hh"


#define YY_DECL yy::parser::symbol_type yylex(Driver& drv)

YY_DECL;


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

};
