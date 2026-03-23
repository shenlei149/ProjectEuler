cmake_minimum_required(VERSION 3.14)



find_package(GTest REQUIRED)

add_executable(ProjectEulerTests UnitTest.cc)

target_link_libraries(ProjectEulerTests
    PRIVATE
    project_euler_lib
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ProjectEulerTests)
