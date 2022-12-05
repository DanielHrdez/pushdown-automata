/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pd_automaton.h"

#include <gtest/gtest.h>

TEST(PDAutomaton, Constructor) {
  EXPECT_NO_THROW(PDAutomaton("examples/APv-3.txt"));
}

TEST(PDAutomaton, Check_APv) {
  PDAutomaton pda = PDAutomaton("examples/APv.txt");

  EXPECT_TRUE(pda.Check("ab"));
  EXPECT_TRUE(pda.Check("aabb"));
  EXPECT_TRUE(pda.Check("aaabbb"));
  EXPECT_TRUE(pda.Check("aaaabbbb"));
  EXPECT_TRUE(pda.Check("aaaaaaabbbbbbb"));

  EXPECT_THROW(pda.Check(""), std::runtime_error);
  EXPECT_THROW(pda.Check("a"), std::runtime_error);
  EXPECT_THROW(pda.Check("b"), std::runtime_error);
  EXPECT_THROW(pda.Check("abb"), std::runtime_error);
  EXPECT_THROW(pda.Check("aab"), std::runtime_error);
}

TEST(PDAutomaton, Check_APv_2) {
  PDAutomaton pda = PDAutomaton("examples/APv-2.txt");

  EXPECT_TRUE(pda.Check(""));
  EXPECT_TRUE(pda.Check("00"));
  EXPECT_TRUE(pda.Check("11"));
  EXPECT_TRUE(pda.Check("0110"));
  EXPECT_TRUE(pda.Check("1001"));
  EXPECT_TRUE(pda.Check("0000"));
  EXPECT_TRUE(pda.Check("1111"));
  EXPECT_TRUE(pda.Check("110010010011"));

  EXPECT_THROW(pda.Check("0"), std::runtime_error);
  EXPECT_THROW(pda.Check("1"), std::runtime_error);
  EXPECT_THROW(pda.Check("b"), std::runtime_error);
  EXPECT_THROW(pda.Check("abb"), std::runtime_error);
  EXPECT_THROW(pda.Check("aab"), std::runtime_error);
}

TEST(PDAutomaton, Check_APv_3) {
  PDAutomaton pda = PDAutomaton("examples/APv-3.txt");

  EXPECT_TRUE(pda.Check("ab"));
  EXPECT_TRUE(pda.Check("aabb"));
  EXPECT_TRUE(pda.Check("aaabbb"));
  EXPECT_TRUE(pda.Check("aaaabbbb"));

  EXPECT_THROW(pda.Check(""), std::runtime_error);
  EXPECT_THROW(pda.Check("a"), std::runtime_error);
  EXPECT_THROW(pda.Check("b"), std::runtime_error);
  EXPECT_THROW(pda.Check("abb"), std::runtime_error);
  EXPECT_THROW(pda.Check("aab"), std::runtime_error);
}
