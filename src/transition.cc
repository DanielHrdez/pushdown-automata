/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/transition.h"

#include <stdexcept>

Transition::Transition(State from_state, Symbol from_input_symbol,
                       Symbol from_stack_symbol, State to_state,
                       std::vector<Symbol> to_stack_symbols) {
  from_state_ = from_state;
  from_input_symbol_ = from_input_symbol;
  from_stack_symbol_ = from_stack_symbol;
  output_.state = to_state;
  std::string epsilon = ".";
  if (to_stack_symbols[0] != epsilon) {
    output_.stack_symbols = to_stack_symbols;
  }
  if (from_stack_symbol != epsilon && to_stack_symbols[0] != epsilon) {
    output_.type = kReplace_;
  } else if (from_stack_symbol == epsilon && to_stack_symbols[0] != epsilon) {
    output_.type = kPush_;
  } else if (from_stack_symbol != epsilon) {
    output_.type = kPop_;
  } else {
    output_.type = kNoChange_;
  }
}

TransitionOutput Transition::Transit(State state, Symbol input_symbol,
                                     Symbol stack_symbol) {
  if (!CheckInputs(state, input_symbol, stack_symbol)) {
    throw std::invalid_argument("Bad Inputs to Transition");
  }
  return output_;
}

bool Transition::CheckInputs(State state, Symbol input_symbol,
                             Symbol stack_symbol) {
  return state == from_state_ &&
         (input_symbol == from_input_symbol_ || from_input_symbol_ == ".") &&
         (stack_symbol == from_stack_symbol_ || from_stack_symbol_ == ".");
}

bool operator==(const TransitionOutput left, const TransitionOutput right) {
  return left.state == right.state && left.type == right.type &&
         left.stack_symbols == right.stack_symbols;
}
