# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(ls_project C)

# Set the directory for header files
include_directories(include)

# Specify the source files
set(SOURCES
    ls.c
    manage_op.c
    op.c
)

# Specify the output binary
add_executable(ls ${SOURCES})

# Link to the largop library located in lib/ directory
target_link_libraries(ls PRIVATE argop)

# Add the path to the library directory
target_link_directories(ls PRIVATE ${CMAKE_SOURCE_DIR}/lib)
