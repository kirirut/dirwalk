cmake_minimum_required(VERSION 3.10)
project(dirwalk)

set(CMAKE_C_STANDARD 99)

# Указываем относительные пути к исходным файлам
add_executable(dirwalk
    src/main.c
    src/walk_directory.c
    src/process_entry.c
)


target_include_directories(dirwalk PRIVATE include)
