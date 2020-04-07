project(GrammarFunctionCalls)

set(PARSER_TARGET "Parser${PROJECT_NAME}")
set(SCANNER_TARGET "Scanner${PROJECT_NAME}")
set(TREE_TARGET "Tree${PROJECT_NAME}")

set(PARSER_OUTPUT "BISON_${PARSER_TARGET}_OUTPUTS")
set(SCANNER_OUTPUT "FLEX_${SCANNER_TARGET}_OUTPUTS")


set(
        HEADERS
        driver.hh
        parser.hh
)

BISON_TARGET(
        ${PARSER_TARGET}
        parser.y
        ${PROJECT_SOURCE_DIR}/parser.cpp
        COMPILE_FLAGS --graph
        DEFINES_FILE ${PROJECT_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        ${SCANNER_TARGET}
        scanner.l
        ${PROJECT_SOURCE_DIR}/scanner.cpp
)



ADD_FLEX_BISON_DEPENDENCY(${SCANNER_TARGET} ${PARSER_TARGET})

set(
        SOURCES
        ${${PARSER_OUTPUT}}
        ${${SCANNER_OUTPUT}}
        Program.cpp
        expressions/NumberExpression.cpp
        expressions/MulExpression.cpp
        expressions/AddExpression.cpp
        expressions/SubstractExpression.cpp
        expressions/DivExpression.cpp
        expressions/IdentExpression.cpp
        statements/Statement.cpp
        statements/Assignment.cpp
        statements/AssignmentList.cpp
        statements/PrintStatement.cpp
        statements/VarDecl.cpp
        statements/ScopeAssignmentList.cpp
        functions/ParamList.cpp
        functions/ParamList.h
        functions/Function.cpp
        functions/Function.h
        functions/FunctionList.cpp functions/FunctionList.h expressions/FunctionCallExpression.cpp expressions/FunctionCallExpression.h functions/ParamValueList.cpp functions/ParamValueList.h statements/ReturnStatement.cpp statements/ReturnStatement.h expressions/AndExpression.cpp expressions/AndExpression.h expressions/OrExpression.cpp expressions/OrExpression.h expressions/NotExpression.cpp expressions/NotExpression.h statements/IfStatement.cpp statements/IfStatement.h expressions/LtExpression.cpp expressions/LtExpression.h expressions/GtExpression.cpp expressions/GtExpression.h)

add_library(
        ${GRAMMAR_LIB}
        SHARED
        ${SOURCES}
)

target_include_directories(
        ${GRAMMAR_LIB} PRIVATE ${PROJECT_SOURCE_DIR}
)

target_include_directories(
        ${GRAMMAR_LIB} PRIVATE ${PROJECT_SOURCE_DIR}/..
)

target_include_directories(
        ${GRAMMAR_LIB} PRIVATE ${PROJECT_SOURCE_DIR}/../include
)