cmake_minimum_required(VERSION 3.0)
project(DetectArgs)

# Set the version number
set(LIBRARY_VERSION 2.0.0)
set(LIBRARY_SONAME 2)

# Specify the source file
set(SOURCE_FILE detect-args.c)

# Set the library output name and version
set(LIBRARY_NAME detect-args)
set(LIBRARY_OUTPUT_NAME ${LIBRARY_NAME})
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Create the shared library
add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILE})

# Set the library version and soname
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${LIBRARY_VERSION}
    SOVERSION ${LIBRARY_SONAME}
    OUTPUT_NAME ${LIBRARY_OUTPUT_NAME}
)

# Specify the output directory for the library
set_target_properties(${LIBRARY_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY}
)

# Position-independent code
set_target_properties(${LIBRARY_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
