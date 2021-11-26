# GoogleTest: requires at least C++11

set(This cpp-base-test)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

file(GLOB_RECURSE cpp-base_TEST CONFIGURE_DEPENDS FOLLOW_SYMLINKS "*.h" "*.hpp" "*.cpp")
add_executable(cpp-base-test ${cpp-base_TEST})

target_link_libraries(
    cpp-base-test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(cpp-base-test)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)