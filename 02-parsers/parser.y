%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    /* Forward declaration of classes in order to disable cyclic dependencies */
    class Scanner;
    class Driver;
}


%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}
// token name in variable
%token
    END 0 "end of file"
    ASSIGN ":="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    SEMICOLON ";"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> exp

// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%
%left "+" "-";
%left "*" "/";

%start unit;
unit: assignments exp ";" { driver.result = $2; };

assignments:
    %empty {}
    | assignments assignment {};

assignment:
    "identifier" ":=" exp ";" {
        driver.variables[$1] = $3;
        if (driver.location_debug) {
            std::cerr << driver.location << std::endl;
        }
    }
    | error ";" {
    	// Hint for compilation error, resuming producing messages
    	std::cerr << "You should provide assignment in the form: variable := expression ; " << std::endl;
    };



exp:
    "number"
    | "identifier" {$$ = driver.variables[$1];}
    | exp "+" exp {$$ = $1 + $3; }
    | exp "-" exp {$$ = $1 - $3; }
    | exp "*" exp {$$ = $1 * $3; }
    | exp "/" exp {$$ = $1 / $3; }
    | "(" exp ")" {$$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
