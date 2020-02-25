cmake_minimum_required(VERSION 3.0)
project(Lexer)

find_package(FLEX REQUIRED)

FLEX_TARGET(MyScanner lexer.l ${Lexer_SOURCE_DIR}/lexer.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    LexerExample
    main.cpp
    ${FLEX_MyScanner_OUTPUTS}
)
