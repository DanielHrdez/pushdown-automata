/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_H_
#define INCLUDE_PDA_H_

#include <string>
#include <vector>

#include "../include/transition.h"
#include "../include/set_strings.h"

class PDA {
 public:
  PDA(Alphabet input_alphabet, State initial_state, Symbol initial_stack_symbol,
      std::vector<Transition> transition_functions);

 protected:
  Alphabet input_alphabet_;
  State initial_state_;
  Symbol initial_stack_symbol_;
  std::vector<Transition> transition_functions_;
};

#endif  // INCLUDE_PDA_H_
