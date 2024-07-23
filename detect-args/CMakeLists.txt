cmake_minimum_required(VERSION 3.10)

# Project name
project(DetectArgs VERSION 1.0.2)

# Set the library version
set(LIB_VERSION 1.0.2)
set(LIB_SOVERSION 1)

# Specify the source file
set(SOURCE_FILE detect-args.c)

# Create the shared library
add_library(detect-args SHARED ${SOURCE_FILE})

# Set the version properties
set_target_properties(detect-args PROPERTIES
    VERSION ${LIB_VERSION}
    SOVERSION ${LIB_SOVERSION}
    OUTPUT_NAME "detect-args"
)

# Specify position-independent code
set_target_properties(detect-args PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Specify the output directory for the shared library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Optionally, you can specify the name of the output library file
set_target_properties(detect-args PROPERTIES
    OUTPUT_NAME "detect-args"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
