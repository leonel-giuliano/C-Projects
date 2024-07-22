cmake_minimum_required(VERSION 3.0)

# Project name
project(libdetect-args)

# Set the version number
set(LIB_VERSION 1.0.1)
set(SO_VERSION 1)

# Specify the library source
set(SOURCE_FILE libdetect-args.c)

# Add the library target
add_library(detect-args SHARED ${SOURCE_FILE})

# Set the version properties
set_target_properties(detect-args PROPERTIES
    VERSION ${LIB_VERSION}
    SOVERSION ${SO_VERSION}
    OUTPUT_NAME "libdetect-args"
)

# Specify the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compile with Position Independent Code
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
