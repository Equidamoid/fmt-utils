project(fmt-utils)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

if (NOT TARGET fmt::fmt)
    message("Using bundled fmtlib")
    add_subdirectory(fmt)
endif()

add_executable(fmt-utils main.cpp)
target_include_directories(fmt-utils
PUBLIC
    include
)

set_property(TARGET fmt-utils PROPERTY CXX_STANDARD 17)
set_property(TARGET fmt-utils PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(fmt-utils fmt::fmt)
