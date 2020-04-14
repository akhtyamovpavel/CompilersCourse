cmake_minimum_required(VERSION 3.0)
project(Compilers)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compilers_SOURCE_DIR}/bin)

add_subdirectory(01-scanners)
add_subdirectory(02-parsers)
add_subdirectory(03-parsers-with-ast)
add_subdirectory(04-visitors)
add_subdirectory(05-variable-scopes)
add_subdirectory(06-function-calls)
add_subdirectory(07-irtree-build)
add_subdirectory(08-irtree-optimizations)
