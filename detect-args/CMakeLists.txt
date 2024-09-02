cmake_minimum_required(VERSION 3.10)

# Project name
project(DetectArgs C)

# Set the version numbers
set(LIB_VERSION_MAJOR 3)
set(LIB_VERSION_MINOR 0)
set(LIB_VERSION_PATCH 1)

# Create the version string
set(LIB_VERSION ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR}.${LIB_VERSION_PATCH})

# Set the source file
set(SRC_FILE detect-args.c)

# Specify the output library name
set(LIB_NAME detect-args)

# Compile the source file into an object file with -fPIC
add_library(${LIB_NAME} SHARED ${SRC_FILE})
set_target_properties(${LIB_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    SOVERSION ${LIB_VERSION_MAJOR}
    VERSION ${LIB_VERSION}
    OUTPUT_NAME ${LIB_NAME}
)

# Set the library output directory
set_target_properties(${LIB_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

if(NOT WIN32)
    # Create a symbolic link for the soname
    add_custom_command(TARGET ${LIB_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${LIB_NAME}.${LIB_VERSION} ${LIB_NAME}.${LIB_VERSION_MAJOR}
    )
endif()