cmake_minimum_required(VERSION 3.19)
project(chapter01)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(main main.cpp)
add_executable(mainOverload mainOverload.cpp)
