/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/set_strings.h"

#include <gtest/gtest.h>

TEST(SetStrings, DefaultConstructor) { EXPECT_NO_THROW(SetStrings()); }

TEST(SetStrings, Constructor) {
  EXPECT_NO_THROW(SetStrings({"a"}));
  EXPECT_NO_THROW(SetStrings({"a", "b", "c"}));
  EXPECT_NO_THROW(SetStrings({"a", "b", "c", "a", "b", "c", "a", "b", "c"}));
}

TEST(SetStrings, Contains) {
  SetStrings s1 = SetStrings({"a", "b", "c"});
  SetStrings s2 = SetStrings({"a", "b", "c", "a", "b", "c", "a", "b", "c"});

  EXPECT_TRUE(s1.Contains("a"));
  EXPECT_TRUE(s1.Contains("b"));
  EXPECT_TRUE(s1.Contains("c"));

  EXPECT_TRUE(s2.Contains("a"));
  EXPECT_TRUE(s2.Contains("b"));
  EXPECT_TRUE(s2.Contains("c"));

  EXPECT_FALSE(s1.Contains("x"));
  EXPECT_FALSE(s1.Contains("y"));
  EXPECT_FALSE(s1.Contains("z"));

  EXPECT_FALSE(s2.Contains("x"));
  EXPECT_FALSE(s2.Contains("y"));
  EXPECT_FALSE(s2.Contains("z"));
}

TEST(SetStrings, Insert) {
  SetStrings s1 = SetStrings({"a", "b", "c"});
  SetStrings s2 = SetStrings({"a", "b", "c", "a", "b", "c", "a", "b", "c"});

  EXPECT_TRUE(s1.Insert("x"));
  EXPECT_TRUE(s1.Insert("y"));
  EXPECT_TRUE(s1.Insert("z"));

  EXPECT_FALSE(s1.Insert("a"));
  EXPECT_FALSE(s1.Insert("b"));
  EXPECT_FALSE(s1.Insert("c"));

  EXPECT_TRUE(s2.Insert("x"));
  EXPECT_TRUE(s2.Insert("y"));
  EXPECT_TRUE(s2.Insert("z"));

  EXPECT_FALSE(s2.Insert("a"));
  EXPECT_FALSE(s2.Insert("b"));
  EXPECT_FALSE(s2.Insert("c"));
}
