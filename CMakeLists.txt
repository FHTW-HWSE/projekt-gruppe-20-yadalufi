cmake_minimum_required(VERSION 3.10.0)

# Name of the project and used language
project(yadalufi)

add_executable(yadalufi
        src/menu.cpp
        src/menu/create_plan.cpp
        src/file.cpp
        src/student.cpp
        src/main.cpp
)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(yadalufi_tests
        src/menu/create_plan.cpp
        tests/test.cpp
        src/menu.cpp
        src/file.cpp
        src/student.cpp
)

catch_discover_tests(yadalufi_tests)
# add_executable(yadalufi src/main.cpp)

