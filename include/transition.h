/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_TRANSITION_H_
#define INCLUDE_TRANSITION_H_

#include <string>
#include <vector>

using Symbol = std::string;
using State = std::string;

enum TransitionType {
  kReplace_,
  kPush_,
  kPop_,
  kNoChange_,
};

struct TransitionOutput {
  State state;
  std::vector<Symbol> stack_symbols;
  TransitionType type;
};

bool operator==(const TransitionOutput left, const TransitionOutput right);

class Transition {
 public:
  Transition(State from_state, Symbol from_input_symbol,
             Symbol from_stack_symbol, State to_state,
             std::vector<Symbol> to_stack_symbols);

  TransitionOutput Transit(State state, Symbol input_symbol,
                           Symbol stack_symbol);

 private:
  bool CheckInputs(State state, Symbol input_symbol, Symbol stack_symbol);

  State from_state_;
  Symbol from_input_symbol_;
  Symbol from_stack_symbol_;
  TransitionOutput output_;
};

#endif  // INCLUDE_TRANSITION_H_
