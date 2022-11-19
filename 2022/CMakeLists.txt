project(Compilers2022)
set(CURRENT_EXECUTABLE "${PROJECT_NAME}Executable")
set(GRAMMAR_LIB "${PROJECT_NAME}GrammarLib")
set(GRAMMAR_PROJECT "${PROJECT_NAME}GrammarProject")

if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=lld")
endif()

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
message(INFO ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


set(
        SOURCES
        driver.cpp
#        visitors/Interpreter.cpp
        visitors/TemplateVisitor.cpp
        visitors/PrintVisitor.cpp
        visitors/MainInterpreter.cpp
        visitors/MainInterpreter.h
        visitors/IrGeneratorVisitor.h
        visitors/IrGeneratorVisitor.cpp
        visitors/SymbolTableVisitor.h
        visitors/SymbolTableVisitor.cpp
        symbols/BaseSymbol.cpp symbols/BaseSymbol.h
        symbols/VariableSymbol.cpp
        symbols/Function.cpp
        scopes/BaseScope.cpp scopes/BaseScope.h)

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

add_executable(
    ${CURRENT_EXECUTABLE}_ir
    test_ir.cpp
    ${SOURCES}
)


target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

llvm_map_components_to_libnames(llvm_libs support core irreader)


target_link_libraries(${CURRENT_EXECUTABLE} ${GRAMMAR_LIB} ${llvm_libs})

target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_ir PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_ir PRIVATE ${PROJECT_SOURCE_DIR}
)


target_link_libraries(${CURRENT_EXECUTABLE}_tests ${GRAMMAR_LIB} ${llvm_libs})

target_link_libraries(${CURRENT_EXECUTABLE}_ir ${GRAMMAR_LIB} ${llvm_libs})
