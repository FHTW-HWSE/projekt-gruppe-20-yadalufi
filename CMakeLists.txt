cmake_minimum_required(VERSION 3.10.0)

# Name of the project and used language
project(yadalufi)

add_executable(yadalufi
        src/menu.cpp
        src/file.cpp
        src/main.cpp
)
# add_executable(yadalufi src/file.c src/menu.c src/main.c tests/test.cpp)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(yadalufi_tests
        tests/test_example.cpp
)

# add_executable(yadalufi src/main.cpp)

