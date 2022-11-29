/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  std::cout << "RUNNING TESTS ..." << std::endl;
  int ret {RUN_ALL_TESTS()};
  if (!ret) {
    std::cout << "<<<SUCCESS>>>" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
  }
  return 0;
}
