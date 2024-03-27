cmake_minimum_required(VERSION 3.10)

project(antlr4)

add_subdirectory(IR)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# set(ANTLR4_TAG e4c1a74)

# add_subdirectory(runtime)
# include_directories(runtime/src)

# add_executable(
#     Test
#     ArithmeticsBaseListener.cpp
#     ArithmeticsLexer.cpp
#     ArithmeticsListener.cpp
#     ArithmeticsParser.cpp
#     main.cpp
# )
# link(dist)
# target_link_libraries(Test antlr4-runtime Threads::Threads)

