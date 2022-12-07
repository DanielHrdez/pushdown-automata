/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/list_transitions.h"

#include <gtest/gtest.h>

TEST(ListTransitions, Constructor) { EXPECT_NO_THROW(ListTransitions()); }

TEST(ListTransitions, Transit) {
  std::vector<Transition> vector_transitions = {
      {"q0", "a", "A", "q1", {"A", "b"}},
      {"q0", "a", "A", "q1", {"B", "b"}},
      {"q0", "b", "A", "q0", {"A"}},
      {"q0", ".", ".", "q1", {"."}}};
  ListTransitions transitions = ListTransitions(vector_transitions);
  std::vector<TransitionOutput> output = {{"q1", {"A", "b"}, kReplace_},
                                          {"q1", {"B", "b"}, kReplace_},
                                          {"q1", {}, kNoChange_}};
  Branches real = transitions.Transit("q0", "a", "A");
  EXPECT_EQ(real.size(), output.size());
  EXPECT_EQ(real[0], output[0]);
  EXPECT_EQ(real[1], output[1]);
  EXPECT_EQ(real[2], output[2]);
  EXPECT_THROW(transitions.Transit("q3", "A", "X"), std::runtime_error);
}
