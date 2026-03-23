cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE SOURCES "*.cc")

# Exclude main.cpp if it exists (for library) but we don't have one yet.
list(FILTER SOURCES EXCLUDE REGEX "main.cc")

add_library(project_euler_lib ${SOURCES})

# Include directories
target_include_directories(project_euler_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Use C++20
target_compile_features(project_euler_lib PUBLIC cxx_std_20)

add_executable(ProjectEuler main.cc)
target_link_libraries(ProjectEuler PRIVATE project_euler_lib)
target_compile_features(ProjectEuler PUBLIC cxx_std_20)
