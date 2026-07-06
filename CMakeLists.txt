cmake_minimum_required(VERSION 3.20)

project(Chapter18_UnitTesting)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Utils
    src/Utils.cpp
)

target_include_directories(Utils
    PUBLIC
    include
)

add_executable(UnitTestingApp
    src/main.cpp
)

target_link_libraries(UnitTestingApp
    PRIVATE
    Utils
)

add_executable(UnitTests
    tests/tests.cpp
)

target_link_libraries(UnitTests
    PRIVATE
    Utils
)
