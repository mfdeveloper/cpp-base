# GoogleTest: requires at least C++11

set(BINARY ${CMAKE_PROJECT_NAME}-test)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.hpp *.h *.cpp *.cc)
set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}-lib gtest gmock)

include(GoogleTest)
include_directories(./mocks)
# gtest_discover_tests(${BINARY})
gtest_add_tests(
  TARGET ${BINARY}
  SOURCES ${TEST_SOURCES}
  TEST_LIST tlist
)
set_tests_properties(${tlist} PROPERTIES FIXTURES_REQUIRED ${BINARY})

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)