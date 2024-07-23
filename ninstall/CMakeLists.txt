cmake_minimum_required(VERSION 3.10)

# Define the project
project(ninstall)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Include the directory where additional header files are located
include_directories(include)

# Link the directory where additional libraries are located
link_directories(lib)

# Specify the source file
add_executable(ninstall ninstall.c)

# Link the library (detect-args)
target_link_libraries(ninstall detect-args)
