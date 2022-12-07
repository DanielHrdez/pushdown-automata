/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/transition.h"

#include <gtest/gtest.h>

TEST(Transition, Constructor) {
  EXPECT_NO_THROW(Transition("q1", "a", "A", "q2", {"A", "S"}));
  EXPECT_NO_THROW(Transition("q1", "a", "A", "q2", {"A"}));
}

TEST(Transition, Transit) {
  Transition t1 = Transition("q1", "a", "A", "q2", {"A", "S"});
  Transition t2 = Transition("q1", "a", ".", "q2", {"A", "A"});
  Transition t3 = Transition("q1", "a", "A", "q2", {"."});
  Transition t4 = Transition("q1", "a", ".", "q2", {"."});

  TransitionOutput real_t1_output = t1.Transit("q1", "a", "A");
  TransitionOutput real_t2_output = t2.Transit("q1", "a", ".");
  TransitionOutput real_t3_output = t3.Transit("q1", "a", "A");
  TransitionOutput real_t4_output = t4.Transit("q1", "a", ".");

  TransitionOutput expect_t1_output = {"q2", {"A", "S"}, kReplace_};
  TransitionOutput expect_t2_output = {"q2", {"A", "A"}, kPush_};
  TransitionOutput expect_t3_output = {"q2", {}, kPop_};
  TransitionOutput expect_t4_output = {"q2", {}, kNoChange_};

  EXPECT_EQ(real_t1_output.state, expect_t1_output.state);
  EXPECT_EQ(real_t1_output.stack_symbols, expect_t1_output.stack_symbols);
  EXPECT_EQ(real_t1_output.type, expect_t1_output.type);

  EXPECT_EQ(real_t2_output.state, expect_t2_output.state);
  EXPECT_EQ(real_t2_output.stack_symbols, expect_t2_output.stack_symbols);
  EXPECT_EQ(real_t2_output.type, expect_t2_output.type);

  EXPECT_EQ(real_t3_output.state, expect_t3_output.state);
  EXPECT_EQ(real_t3_output.stack_symbols, expect_t3_output.stack_symbols);
  EXPECT_EQ(real_t3_output.type, expect_t3_output.type);

  EXPECT_EQ(real_t4_output.state, expect_t4_output.state);
  EXPECT_EQ(real_t4_output.stack_symbols, expect_t4_output.stack_symbols);
  EXPECT_EQ(real_t4_output.type, expect_t4_output.type);
}

TEST(Transition, TransitTHROW) {
  Transition t1 = Transition("q1", "a", "A", "q2", {"A", "S"});
  Transition t2 = Transition("q1", "a", ".", "q2", {"A", "A"});
  EXPECT_THROW(t1.Transit("q1", "a", "X"), std::invalid_argument);
  EXPECT_THROW(t2.Transit("q1", "b", "X"), std::invalid_argument);
}
