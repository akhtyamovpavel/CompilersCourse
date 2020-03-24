project(FunctionCalls)
set(CURRENT_EXECUTABLE "${PROJECT_NAME}Executable")

set(
    SOURCES
    driver.cpp
    visitors/Interpreter.cpp
    visitors/TemplateVisitor.cpp
    visitors/PrintVisitor.cpp
    symbol_table/Symbol.cpp
    symbol_table/Table.cpp
    symbol_table/ScopeLayer.cpp
    symbol_table/ScopeLayerTree.cpp
    types/Integer.cpp
    types/Type.cpp
    types/UninitObject.cpp
    visitors/SymbolTreeVisitor.cpp
    types/PrimitiveType.cpp
    types/PrimitiveType.h
    types/FunctionType.cpp
    types/FunctionType.h
)

add_subdirectory(grammar)

add_executable(
    ${CURRENT_EXECUTABLE}
    main.cpp
    ${SOURCES}
)


target_include_directories(
    ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
    ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)


target_link_libraries(${CURRENT_EXECUTABLE} GrammarLib)



