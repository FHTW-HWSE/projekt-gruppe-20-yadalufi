cmake_minimum_required(VERSION 3.10.0)

# Name of the project and used language
project(yadalufi)

add_executable(yadalufi
        src/menu/add_student.cpp
        src/menu/create_plan.cpp
        src/menu/load_csv.cpp
        src/menu/quit.cpp
        src/contact_tracing.cpp
        src/csv_read.cpp
        src/csv_write.cpp
        src/file.cpp
        src/main.cpp
        src/menu.cpp
        src/student.cpp
)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(yadalufi_tests
        src/menu/create_plan.cpp
        src/menu/add_student.cpp
        src/menu/load_csv.cpp
        src/menu/quit.cpp
        tests/test.cpp
        src/menu.cpp
        src/file.cpp
        src/student.cpp
        src/contact_tracing.cpp
        src/csv_read.cpp
)

catch_discover_tests(yadalufi_tests)
# add_executable(yadalufi src/main.cpp)

