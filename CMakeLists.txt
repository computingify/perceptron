# Set the default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

cmake_minimum_required(VERSION 3.12)
project(PerceptronProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define directories
set(SRC_DIR src)
set(INC_DIR inc)
set(BUILD_DIR build)

# List all source files
file(GLOB SRCS ${SRC_DIR}/*.cpp)

# Create the executable
add_executable(perceptron ${SRCS})

# Specify include directories
target_include_directories(perceptron PRIVATE ${INC_DIR})
