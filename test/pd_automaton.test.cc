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

  EXPECT_FALSE(pda.Check(""));
  EXPECT_FALSE(pda.Check("a"));
  EXPECT_FALSE(pda.Check("b"));
  EXPECT_FALSE(pda.Check("abb"));
  EXPECT_FALSE(pda.Check("aab"));
}

TEST(PDAutomaton, Check_APv_2) {
  PDAutomaton pda = PDAutomaton("examples/APv-2.txt");

  EXPECT_TRUE(pda.Check(""));
  EXPECT_TRUE(pda.Check("00"));
  EXPECT_TRUE(pda.Check("11"));
  EXPECT_TRUE(pda.Check("01"));
  EXPECT_TRUE(pda.Check("10"));
  EXPECT_TRUE(pda.Check("0110"));
  EXPECT_TRUE(pda.Check("1001"));
  EXPECT_TRUE(pda.Check("0000"));
  EXPECT_TRUE(pda.Check("1111"));
  EXPECT_TRUE(pda.Check("101101"));
  EXPECT_TRUE(pda.Check("110011"));
  EXPECT_TRUE(pda.Check("10100101"));
  EXPECT_TRUE(pda.Check("110010010011"));

  EXPECT_FALSE(pda.Check("0"));
  EXPECT_FALSE(pda.Check("1"));
  EXPECT_FALSE(pda.Check("010"));
  EXPECT_FALSE(pda.Check("101"));
  EXPECT_FALSE(pda.Check("1010"));
  EXPECT_FALSE(pda.Check("0101"));
}

TEST(PDAutomaton, Check_APv_3) {
  PDAutomaton pda = PDAutomaton("examples/APv-3.txt");

  EXPECT_TRUE(pda.Check("a"));
  EXPECT_TRUE(pda.Check("b"));
  EXPECT_TRUE(pda.Check(""));
  EXPECT_TRUE(pda.Check("aaba"));
  EXPECT_TRUE(pda.Check("baba"));
  EXPECT_TRUE(pda.Check("abba"));
  EXPECT_TRUE(pda.Check("bbba"));
  EXPECT_TRUE(pda.Check("abba"));

  EXPECT_FALSE(pda.Check("aa"));
  EXPECT_FALSE(pda.Check("ab"));
  EXPECT_FALSE(pda.Check("ba"));
  EXPECT_FALSE(pda.Check("bb"));
  EXPECT_FALSE(pda.Check("abaa"));
}
