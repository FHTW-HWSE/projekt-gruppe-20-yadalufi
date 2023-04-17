cmake_minimum_required(VERSION 3.18)
project(yadalufi C)

set(CMAKE_C_STANDARD 11)

add_executable(yadalufi
        src/file.c src/menu.c src/main.c)
