cmake_minimum_required(VERSION 3.13)
project(foo)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED CONFIG COMPONENTS unit_test_framework )

add_library(bar_lib INTERFACE)
target_include_directories(bar_lib INTERFACE bar_lib)

# test binary
add_executable(foo_test foo_test.cpp)
target_link_libraries(foo_test PUBLIC bar_lib Boost::unit_test_framework)

enable_testing()

add_test(NAME foo_test COMMAND $<TARGET_FILE:foo_test>)
