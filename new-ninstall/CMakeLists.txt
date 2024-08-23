cmake_minimum_required(VERSION 3.10)
project(ninstall)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Specify the include directory
include_directories(include)

# Specify the source files
set(SOURCES
    ninstall.c
    comm.c
)

# Specify the library search path
link_directories(lib)

# Specify the libraries to link against
set(LIBRARIES
    detect-args
)

# Compile the source files into an executable
add_executable(ninstall ${SOURCES})

# Link the executable against the specified libraries
target_link_libraries(ninstall ${LIBRARIES})
