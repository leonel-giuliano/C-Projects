cmake_minimum_required(VERSION 3.10)
project(cat_project)

# Specify the C standard (optional)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add the library search path
link_directories(lib)

# Create an object file for cat.c
add_library(cat_obj OBJECT cat.c)

# Add an executable target
add_executable(cat $<TARGET_OBJECTS:cat_obj>)

# Link the detect-args library to the executable
target_link_libraries(cat detect-args)
