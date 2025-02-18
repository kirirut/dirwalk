cmake_minimum_required(VERSION 3.10)
project(dirwalk)

# Указываем стандарт C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Указываем выходные директории для Release и Debug
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Если не Debug и не Release, используем текущую директорию (${CMAKE_BINARY_DIR})
if (NOT CMAKE_BUILD_TYPE MATCHES "Debug|Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Флаги для Debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -ggdb -std=c11 -pedantic -W -Wall -Wextra")

# Флаги для Release
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c11 -pedantic -W -Wall -Wextra -Werror")

# Указываем исходные файлы (относительные пути от CMakeLists.txt)
add_executable(dirwalk
    src/main.c
    src/walk_directory.c
    src/process_entry.c
)

# Указываем директории с заголовочными файлами
target_include_directories(dirwalk PRIVATE include)