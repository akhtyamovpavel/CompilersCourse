project(Scopes)
set(
    HEADERS
    driver.hh
    parser.hh
    )

BISON_TARGET(
    ParserScopes
    parser.y
    ${Scopes_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${Scopes_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    ScannerScopes
    scanner.l
    ${Scopes_SOURCE_DIR}/scanner.cpp
)



ADD_FLEX_BISON_DEPENDENCY(ScannerScopes ParserScopes)

set(
    SOURCES
    driver.cpp
    ${BISON_ParserScopes_OUTPUTS}
    ${FLEX_ScannerScopes_OUTPUTS}
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
    visitors/Interpreter.cpp
    visitors/TemplateVisitor.cpp
    visitors/PrintVisitor.cpp
    symbol_table/Symbol.cpp
    symbol_table/Table.cpp
    symbol_table/ScopeLayer.cpp
    symbol_table/ScopeLayerTree.cpp
    objects/Integer.cpp
    objects/Object.cpp
    objects/UninitObject.cpp
    Program.cpp
    visitors/SymbolTreeVisitor.cpp
)

add_executable(
    ScopesExecutable
    main.cpp
    ${SOURCES}
)

add_executable(
    TestScopes
    tests/test_scope_layer.cpp
    ${SOURCES}
)

target_include_directories(
    TestScopes PRIVATE ${Scopes_SOURCE_DIR}
)

target_include_directories(
    ScopesExecutable PRIVATE ${Scopes_SOURCE_DIR}
)

add_custom_target(
    ScopesTree
    COMMAND dot -Tpng ${Scopes_SOURCE_DIR}/parser.gv -o ${Scopes_SOURCE_DIR}/parser.png
    
    DEPENDS ${Scopes_SOURCE_DIR}/parser.cpp
)

add_dependencies(ScopesExecutable ScopesTree)



