/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_H_
#define INCLUDE_PDA_H_

#include <string>
#include <vector>

#include "../include/transition.h"

class PDA {
 public:
  PDA(std::string inital_state, std::string initial_stack_symbol,
      std::vector<Transition> transition_functions)
      : inital_state_(inital_state),
        initial_stack_symbol_(initial_stack_symbol),
        transition_functions_(transition_functions) {}

 protected:
  std::string inital_state_;
  std::string initial_stack_symbol_;
  std::vector<Transition> transition_functions_;
};

#endif  // INCLUDE_PDA_H_
