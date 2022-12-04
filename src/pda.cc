/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pda.h"

PDA::PDA(Alphabet input_alphabet, std::string initial_state,
         std::string initial_stack_symbol,
         std::vector<Transition> transition_functions) {
  input_alphabet_ = input_alphabet;
  initial_state_ = initial_state;
  initial_stack_symbol_ = initial_stack_symbol;
  transition_functions_ = transition_functions;
}
