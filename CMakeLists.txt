cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
project(BruteForce)
set(CMAKE_BUILD_TYPE Debug)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(main main.cpp attacker.cpp)
target_include_directories(main PRIVATE include)

add_executable(tests tests.cpp attacker.cpp)
target_link_libraries(tests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
target_include_directories(tests PRIVATE include)
