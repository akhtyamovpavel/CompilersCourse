cmake_minimum_required(VERSION 3.0)
project(Compilers)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compilers_SOURCE_DIR}/bin)

add_subdirectory(01-scanners)
add_subdirectory(02-parsers)
add_subdirectory(03-parsers-with-ast)
add_subdirectory(04-visitors)
