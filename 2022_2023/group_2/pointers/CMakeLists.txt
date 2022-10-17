cmake_minimum_required(VERSION 3.5)

project(pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pointers main.cpp)

add_executable(public_and_not public_and_not.cpp)
