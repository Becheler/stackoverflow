cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project("foo" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)
# add alias so the project can be used with add_subdirectory
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Include Boost as an imported target
find_package(Boost 1.72 REQUIRED COMPONENTS unit_test_framework)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
