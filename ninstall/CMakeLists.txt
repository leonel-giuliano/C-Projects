cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(ninstall VERSION 1.0)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Specify source files
set(SOURCES
    ninstall.c
    manage-op.c
    op.c
)

# Specify the library search path
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Create the executable from source files
add_executable(ninstall ${SOURCES})

# Link the external library
target_link_libraries(ninstall argop)
