%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
    
    #include "visitors/forward_decl.h"
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "visitors/elements.h"
    #include "Program.h"

    #include <iostream>

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN ":="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    PRINT "print"
    VAR "var"
    LEFTSCOPE "{"
    RIGHTSCOPE "}"
    SEMICOLON ";"
    COMMA ","
    FUNC "func"
    RETURN "return"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <FunctionList*> function_list

%nterm <Function*> function_def

%nterm <ParamList*> param_list
%nterm <ParamList*> empty_param_list
%nterm <ParamList*> complex_param_list
%nterm <ParamValueList*> param_value_list
%nterm <ParamValueList*> empty_param_value_list
%nterm <ParamValueList*> complex_param_value_list
%nterm <Expression*> exp
%nterm <Statement*> statement
%nterm <AssignmentList*> statements
%nterm <Program*> unit


%%
%start unit;

unit: function_list { $$ = new Program($1); driver.program = $$; };

function_list:
    %empty { $$ = new FunctionList(); }
    | function_list function_def {
        $1->AddFunction($2); $$ = $1;
    };

function_def:
    "func" "identifier" "(" param_list ")" "{" statements "}" { $$ = new Function($2, $4, $7); };

param_list:
    empty_param_list {$$ = $1;} /* func foo () {}*/
    | complex_param_list {$$ = $1;} /* func foo(a, b, c) {} */
    ;

empty_param_list:
    %empty { $$ = new ParamList();}
    ;

complex_param_list: /* a, b, c */
    | "identifier" {$$ = new ParamList($1);}
    | complex_param_list "," "identifier" { $1->AddParam($3); $$ = $1; }
    ;

statements:
    %empty { $$ = new AssignmentList(); /* A -> eps */}
    | statements statement {
        $1->AddStatement($2); $$ = $1;
    };

statement:
    "identifier" ":=" exp ";" { $$ = new Assignment($1, $3);}
    | "print" "(" exp ")" ";" { $$ = new PrintStatement($3); }
    | "var" "identifier" ";" { $$ = new VarDecl($2); }
    | "{" statements "}" { $$ = new ScopeAssignmentList($2); }
    | "return" exp ";" { $$ = new ReturnStatement($2); }
    ;

%left "+" "-";
%left "*" "/";

exp:
    "number" {$$ = new NumberExpression($1); }
    | "identifier" {$$ = new IdentExpression($1); }
    | exp "+" exp { $$ = new AddExpression($1, $3); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3); }
    | exp "*" exp { $$ = new MulExpression($1, $3); }
    | exp "/" exp { $$ = new DivExpression($1, $3); }
    | "identifier" "(" param_value_list ")"  {
        $$ = new FunctionCallExpression($1, $3);
    }
    | "(" exp ")" { $$ = $2; };


param_value_list:
    empty_param_value_list {$$ = $1;} /* foo () {}*/
    | complex_param_value_list {
        $$ = $1;
      } /* foo(a, b, c) {} */
    ;

empty_param_value_list:
    %empty { $$ = new ParamValueList();}
    ;

complex_param_value_list: /* a, b, c */
    | exp {$$ = new ParamValueList($1);}
    | complex_param_value_list "," exp { $1->AddParam($3); $$ = $1; }
    ;

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
