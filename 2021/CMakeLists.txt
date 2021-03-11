project(Compilers2021)
set(CURRENT_EXECUTABLE "${PROJECT_NAME}Executable")
set(GRAMMAR_LIB "${PROJECT_NAME}GrammarLib")
set(GRAMMAR_PROJECT "${PROJECT_NAME}GrammarProject")

set(
        SOURCES
        driver.cpp
#        visitors/Interpreter.cpp
        visitors/TemplateVisitor.cpp
        visitors/PrintVisitor.cpp
        visitors/MainInterpreter.cpp
        visitors/MainInterpreter.h
        symbols/BaseSymbol.cpp symbols/BaseSymbol.h
        symbols/StFunction.h symbols/StFunction.cpp
        symbols/StVariable.cpp symbols/StVariable.h
        symbols/StArgument.cpp symbols/StArgument.h scopes/BaseScope.cpp scopes/BaseScope.h visitors/SymbolTableVisitor.cpp visitors/SymbolTableVisitor.h)

add_subdirectory(grammar)

add_executable(
        ${CURRENT_EXECUTABLE}
        main.cpp
        ${SOURCES}
)

add_executable(
        ${CURRENT_EXECUTABLE}_tests
        test_scope.cpp
        ${SOURCES}
)


target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)


target_link_libraries(${CURRENT_EXECUTABLE} ${GRAMMAR_LIB})

target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)


target_link_libraries(${CURRENT_EXECUTABLE}_tests ${GRAMMAR_LIB})