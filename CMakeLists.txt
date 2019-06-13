project(fmt-utils)
cmake_minimum_required(VERSION 3.10)

add_definitions('--std=c++17')

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

#find_package(fmt REQUIRED)
add_subdirectory(fmt)

add_executable(fmt-utils-test main.cpp)
target_include_directories(fmt-utils-test
PUBLIC
include)

target_link_libraries(fmt-utils-test fmt::fmt)
