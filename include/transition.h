/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_TRANSITION_H_
#define INCLUDE_TRANSITION_H_

#include <string>
#include <vector>

struct Transition {
  std::string from_state;
  std::string from_input_symbol;
  std::string from_stack_symbol;
  std::string to_state;
  std::vector<std::string> to_stack_symbols;
};

#endif  // INCLUDE_TRANSITION_H_
