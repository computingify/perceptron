# Set the default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

cmake_minimum_required(VERSION 3.12)
project(PerceptronProject CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define directories
set(SRC_DIR src)
set(INC_DIR inc)
set(BUILD_DIR build)


# List all source files
file(GLOB SRCS ${SRC_DIR}/*.cpp)

# Add the third-party libraries
add_subdirectory(lib/matplotlib-cpp)
include_directories(lib/matplotlib-cpp)

# Create the executable
add_executable(perceptron ${SRCS})

# Specify include directories
target_include_directories(perceptron PRIVATE ${INC_DIR})

# Link the third-party library to your executable
target_link_libraries(perceptron PRIVATE matplotlib_cpp)