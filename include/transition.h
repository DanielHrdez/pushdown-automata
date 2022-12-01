/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_TRANSITION_H_
#define INCLUDE_TRANSITION_H_

#include <string>
#include <vector>

class Transition {
 public:
  Transition(std::string from_state, std::string from_input_symbol,
             std::string from_stack_symbol, std::string to_state,
             std::vector<std::string> to_stack_symbols)
      : from_state_(from_state),
        from_input_symbol_(from_input_symbol),
        from_stack_symbol_(from_stack_symbol),
        to_state_(to_state),
        to_stack_symbols_(to_stack_symbols) {}

 private:
  std::string from_state_;
  std::string from_input_symbol_;
  std::string from_stack_symbol_;
  std::string to_state_;
  std::vector<std::string> to_stack_symbols_;
};

#endif  // INCLUDE_TRANSITION_H_
