# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(bulletin)

# Add executable and source files
add_executable(bulletin main.c bulletin.c file.c)
