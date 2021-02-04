project(ParserExample)
set(
    HEADERS
    ${ParserExample_SOURCE_DIR}/driver.hh
    ${ParserExample_SOURCE_DIR}/parser.hh
    )

BISON_TARGET(
    MyParser
    parser.y
    ${ParserExample_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScanner
    scanner.l
    ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    02-ParserExample
    main.cpp
    driver.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
target_include_directories(02-ParserExample PRIVATE ${ParserExample_SOURCE_DIR})



