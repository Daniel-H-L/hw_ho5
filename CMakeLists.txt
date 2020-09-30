cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Project name
project(hw_ho5)

# Where to find included source files
include_directories("${PROJECT_SOURCE_DIR}")

# List sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")

# Create a (static by default) library using all of IMC sources / headers
add_library(imc ${IMC_HEADERS} ${IMC_SOURCES})

#Create executable
add_executable(hw_ho5 hw_ho5.cpp)