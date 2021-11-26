#
# References:
#   - https://code.visualstudio.com/docs/cpp/cmake-linux
#   - https://stackoverflow.com/questions/3201154/automatically-add-all-files-in-a-folder-to-a-target-using-cmake
#   - https://stackoverflow.com/questions/30250494/ctest-not-detecting-tests

cmake_minimum_required(VERSION 3.14)
project(cpp-base VERSION 0.1.0)

file(GLOB_RECURSE cpp-base_SRC CONFIGURE_DEPENDS FOLLOW_SYMLINKS "src/*.h" "src/*.hpp" "src/*.cpp")
add_executable(cpp-base ${cpp-base_SRC})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

enable_testing()

add_subdirectory(test)
