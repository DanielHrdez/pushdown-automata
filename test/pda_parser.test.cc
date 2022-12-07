/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pda_parser.h"

#include <gtest/gtest.h>

TEST(PDAParser, Constructor) {
  EXPECT_NO_THROW(PDAParser("examples/APv.txt"));
  EXPECT_NO_THROW(PDAParser("examples/APv-2.txt"));
  EXPECT_NO_THROW(PDAParser("examples/APv-3.txt"));
  EXPECT_NO_THROW(PDAParser("examples/APf.txt"));
  EXPECT_NO_THROW(PDAParser("examples/APf-2.txt"));
  EXPECT_NO_THROW(PDAParser("examples/APf-3.txt"));
}

TEST(PDAParser, IgnoreComments) {
  PDAParser parser = PDAParser("examples/APv.txt");
  parser.IgnoreComments();
  EXPECT_EQ(parser.FileReadPosition(), 123);

  PDAParser parser_2 = PDAParser("examples/APv-2.txt");
  parser_2.IgnoreComments();
  EXPECT_EQ(parser_2.FileReadPosition(), 199);

  PDAParser parser_3 = PDAParser("examples/APv-3.txt");
  parser_3.IgnoreComments();
  EXPECT_EQ(parser_3.FileReadPosition(), 69);
}

TEST(PDAParser, ParseSet) {
  PDAParser parser = PDAParser("examples/APv.txt");
  parser.IgnoreComments();
  EXPECT_EQ(parser.ParseSet(), SetStates({"q1", "q2"}));
  EXPECT_EQ(parser.ParseSet(), Alphabet({"a", "b"}));
  EXPECT_EQ(parser.ParseSet(), Alphabet({"S", "A"}));

  PDAParser parser_2 = PDAParser("examples/APv-2.txt");
  parser_2.IgnoreComments();
  EXPECT_EQ(parser_2.ParseSet(), SetStates({"p", "q"}));
  EXPECT_EQ(parser_2.ParseSet(), Alphabet({"0", "1"}));
  EXPECT_EQ(parser_2.ParseSet(), Alphabet({"0", "1", "S"}));

  PDAParser parser_3 = PDAParser("examples/APv-3.txt");
  parser_3.IgnoreComments();
  EXPECT_EQ(parser_3.ParseSet(), SetStates({"q0"}));
  EXPECT_EQ(parser_3.ParseSet(), Alphabet({"a", "b"}));
  EXPECT_EQ(parser_3.ParseSet(), Alphabet({"a", "b", "S", "B"}));
}

TEST(PDAParser, ParseInitial) {
  PDAParser parser = PDAParser("examples/APv.txt");
  parser.IgnoreComments();
  SetStates states = parser.ParseSet();
  parser.ParseSet();
  Alphabet stack_alphabet = parser.ParseSet();

  EXPECT_EQ(parser.ParseInitial(states, PDAParser::TypeInitial::kState_), "q1");
  EXPECT_EQ(
      parser.ParseInitial(stack_alphabet, PDAParser::TypeInitial::kSymbol_),
      "S");

  PDAParser parser_2 = PDAParser("examples/APv-2.txt");
  parser_2.IgnoreComments();
  SetStates states_2 = parser_2.ParseSet();
  parser_2.ParseSet();
  Alphabet stack_alphabet_2 = parser_2.ParseSet();

  EXPECT_EQ(parser_2.ParseInitial(states_2, PDAParser::TypeInitial::kState_),
            "p");
  EXPECT_EQ(
      parser_2.ParseInitial(stack_alphabet_2, PDAParser::TypeInitial::kSymbol_),
      "S");

  PDAParser parser_3 = PDAParser("examples/APv-3.txt");
  parser_3.IgnoreComments();
  SetStates states_3 = parser_3.ParseSet();
  parser_3.ParseSet();
  Alphabet stack_alphabet_3 = parser_3.ParseSet();

  EXPECT_EQ(parser_3.ParseInitial(states_3, PDAParser::TypeInitial::kState_),
            "q0");
  EXPECT_EQ(
      parser_3.ParseInitial(stack_alphabet_3, PDAParser::TypeInitial::kSymbol_),
      "S");
}

TEST(PDAParser, ParseTransition) {
  PDAParser parser = PDAParser("examples/APv.txt");
  PDAParser parser_2 = PDAParser("examples/APv-2.txt");
  PDAParser parser_3 = PDAParser("examples/APv-3.txt");

  parser.IgnoreComments();
  parser_2.IgnoreComments();
  parser_3.IgnoreComments();

  SetStates states = parser.ParseSet();
  SetStates states_2 = parser_2.ParseSet();
  SetStates states_3 = parser_3.ParseSet();

  Alphabet input_alphabet = parser.ParseSet();
  Alphabet input_alphabet_2 = parser_2.ParseSet();
  Alphabet input_alphabet_3 = parser_3.ParseSet();

  Alphabet stack_alphabet = parser.ParseSet();
  Alphabet stack_alphabet_2 = parser_2.ParseSet();
  Alphabet stack_alphabet_3 = parser_3.ParseSet();

  EXPECT_THROW(parser.ParseTransition("q1 a X q1 A", states, input_alphabet,
                                      stack_alphabet),
               std::runtime_error);
  EXPECT_THROW(parser_2.ParseTransition("q1 a X q1 A", states_2,
                                        input_alphabet_2, stack_alphabet_2),
               std::runtime_error);
  EXPECT_THROW(parser_3.ParseTransition("q1 a X q1 A", states_3,
                                        input_alphabet_3, stack_alphabet_3),
               std::runtime_error);
}

TEST(PDAParser, ParseTransitions) {
  PDAParser parser = PDAParser("examples/APv.txt");
  PDAParser parser_2 = PDAParser("examples/APv-2.txt");
  PDAParser parser_3 = PDAParser("examples/APv-3.txt");

  parser.IgnoreComments();
  parser_2.IgnoreComments();
  parser_3.IgnoreComments();

  SetStates states = parser.ParseSet();
  SetStates states_2 = parser_2.ParseSet();
  SetStates states_3 = parser_3.ParseSet();

  Alphabet input_alphabet = parser.ParseSet();
  Alphabet input_alphabet_2 = parser_2.ParseSet();
  Alphabet input_alphabet_3 = parser_3.ParseSet();

  Alphabet stack_alphabet = parser.ParseSet();
  Alphabet stack_alphabet_2 = parser_2.ParseSet();
  Alphabet stack_alphabet_3 = parser_3.ParseSet();

  parser.ParseInitial(states, PDAParser::TypeInitial::kState_);
  parser_2.ParseInitial(states_2, PDAParser::TypeInitial::kState_);
  parser_3.ParseInitial(states_3, PDAParser::TypeInitial::kState_);
  parser.ParseInitial(stack_alphabet, PDAParser::TypeInitial::kSymbol_);
  parser_2.ParseInitial(stack_alphabet_2, PDAParser::TypeInitial::kSymbol_);
  parser_3.ParseInitial(stack_alphabet_3, PDAParser::TypeInitial::kSymbol_);

  EXPECT_NO_THROW(
      parser.ParseTransitions(states, input_alphabet, stack_alphabet));
  EXPECT_NO_THROW(
      parser_2.ParseTransitions(states_2, input_alphabet_2, stack_alphabet_2));
  EXPECT_NO_THROW(
      parser_3.ParseTransitions(states_3, input_alphabet_3, stack_alphabet_3));
}
