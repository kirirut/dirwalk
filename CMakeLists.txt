cmake_minimum_required(VERSION 3.10)
project(dirwalk)

# Указываем стандарт C11 для целевого файла
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Указываем выходные директории для Release и Debug
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Если не Debug и не Release, используем текущую директорию (${CMAKE_BINARY_DIR})
if (NOT CMAKE_BUILD_TYPE MATCHES "Debug|Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Указываем исходные файлы (относительные пути от CMakeLists.txt)
add_executable(dirwalk
    src/main.c
    src/walk_directory.c
    src/process_entry.c
)

# Указываем заголовочные файлы (опционально, для IDE)
target_sources(dirwalk PRIVATE
    include/dirwalk.h
)

# Указываем директории с заголовочными файлами
target_include_directories(dirwalk PRIVATE include)

# Флаги компиляции для Debug
target_compile_options(dirwalk PRIVATE
    $<$<CONFIG:Debug>:-g -ggdb -pedantic -W -Wall -Wextra>
)

# Флаги компиляции для Release
target_compile_options(dirwalk PRIVATE
    $<$<CONFIG:Release>:-pedantic -W -Wall -Wextra -Werror>
)