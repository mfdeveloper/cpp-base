#
# References:
#   - https://code.visualstudio.com/docs/cpp/cmake-linux
#   - https://stackoverflow.com/questions/3201154/automatically-add-all-files-in-a-folder-to-a-target-using-cmake
#   - https://stackoverflow.com/questions/30250494/ctest-not-detecting-tests
#   - Cmake + CTest setup: https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html

cmake_minimum_required(VERSION 3.14)
project(cpp-base VERSION 0.1.0)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/*.hpp src/*.h src/*.cpp src/*.cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CPP_FLAGS} -std=c++17")
set(BINARY ${CMAKE_PROJECT_NAME})
set(CTEST_OUTPUT_ON_FAILURE 1)

add_executable(${BINARY} ${SOURCES})
add_library(${BINARY}-lib STATIC ${SOURCES})

include(CPack)
include_directories(src/core)

enable_testing()

add_subdirectory(test)
