/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/fpda.h"

FPDA::FPDA(std::string inital_state, std::string initial_stack_symbol,
           std::vector<Transition> transition_functions,
           std::set<std::string> finite_states)
    : PDA(inital_state_, initial_stack_symbol_, transition_functions_) {
  finite_states_ = finite_states;
}

FPDA::FPDA(FPDAData data) : PDA(data) { finite_states_ = data.finite_states; }
