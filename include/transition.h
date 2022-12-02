/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_TRANSITION_H_
#define INCLUDE_TRANSITION_H_

#include <string>
#include <vector>

#include "../include/aliases.h"

class Transition {
 public:
  Transition();

 private:
  State from_state;
  Symbol from_input_symbol;
  Symbol from_stack_symbol;
  State to_state;
  std::vector<Symbol> to_stack_symbols;
};

#endif  // INCLUDE_TRANSITION_H_
