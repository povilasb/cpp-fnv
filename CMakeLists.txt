cmake_minimum_required(VERSION 2.6)

project(cpp-fnv CXX)
set(lib_cpp_fnv "${PROJECT_NAME}")
set(example1 "example1")
set(example2 "example2")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic")

set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(examples_dir "${CMAKE_CURRENT_SOURCE_DIR}/examples")
set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE src_files "${src_dir}/*.cpp")
list(REMOVE_ITEM src_files "${src_dir}/main.cpp")
add_library("${lib_cpp_fnv}" STATIC ${src_files})

include_directories(${include_dir})

add_executable("${example1}" "${examples_dir}/${example1}.cpp")
target_link_libraries(${example1} ${lib_cpp_fnv})

add_executable("${example2}" "${examples_dir}/${example2}.cpp")
target_link_libraries(${example2} ${lib_cpp_fnv})
