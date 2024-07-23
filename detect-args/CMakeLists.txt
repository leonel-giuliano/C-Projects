cmake_minimum_required(VERSION 3.10)
project(DetectArgs C)

# Specify the version of the library
set(LIB_VERSION "1.0.0")
set(LIB_SOVERSION "1")

# Add the source file
set(SOURCES detect-args.c)

# Compile the source file into a shared library
add_library(detect-args SHARED ${SOURCES})

# Set the version properties
set_target_properties(detect-args PROPERTIES 
    VERSION ${LIB_VERSION}
    SOVERSION ${LIB_SOVERSION}
)

# Specify the output name of the shared library
set_target_properties(detect-args PROPERTIES 
    OUTPUT_NAME "detect-args"
)

# Position Independent Code
set_target_properties(detect-args PROPERTIES 
    POSITION_INDEPENDENT_CODE ON
)
