/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pda.h"

PDA::PDA(std::string inital_state, std::string initial_stack_symbol,
         std::vector<Transition> transition_functions) {
  inital_state_ = inital_state;
  initial_stack_symbol_ = initial_stack_symbol;
  transition_functions_ = transition_functions;
}

PDA::PDA(PDAData data) {
  inital_state_ = data.inital_state;
  initial_stack_symbol_ = data.initial_stack_symbol;
  transition_functions_ = data.transition_functions;
}
