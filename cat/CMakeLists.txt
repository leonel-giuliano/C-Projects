cmake_minimum_required(VERSION 3.10)

# Project name
project(CatProject)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the include directories
include_directories(include)

# Add source files
set(SOURCES cat.c operation.c)

# Specify the library search path
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Create the executable from object files
add_executable(cat ${SOURCES})

# Link the external library (largop)
target_link_libraries(cat argop)
