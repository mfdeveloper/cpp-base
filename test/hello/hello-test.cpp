#include <gtest/gtest.h>
#include "../../src/hello/hello.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  
  string msg = hello();
  string expectedMsg = "Hello C++ World from VS Code and the C++ extension! ";

  // Expect two strings not to be equal.
  EXPECT_EQ(expectedMsg, msg);

  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
