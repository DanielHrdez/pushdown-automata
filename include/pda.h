/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_H_
#define INCLUDE_PDA_H_

#include <string>
#include <vector>

#include "../include/transition.h"

struct PDAData {
  State inital_state;
  Symbol initial_stack_symbol;
  std::vector<Transition> transition_functions;
};

class PDA {
 public:
  PDA(State inital_state, Symbol initial_stack_symbol,
      std::vector<Transition> transition_functions);
  explicit PDA(PDAData data);

 protected:
  State inital_state_;
  Symbol initial_stack_symbol_;
  std::vector<Transition> transition_functions_;
};

#endif  // INCLUDE_PDA_H_
