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
  output_.stack_symbols = to_stack_symbols;
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
  return state == from_state_ && input_symbol == from_input_symbol_ &&
         stack_symbol == from_stack_symbol_;
}
