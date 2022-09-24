cmake_minimum_required(VERSION 3.0)
project(Lexer)

set(CMAKE_CXX_STANDARD 17)
FLEX_TARGET(MyScanner lexer.l ${Lexer_SOURCE_DIR}/lexer.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    01-LexerExample
    main.cpp
    ${FLEX_MyScanner_OUTPUTS}
)
