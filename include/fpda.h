/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_FPDA_H_
#define INCLUDE_FPDA_H_

#include <set>
#include <string>
#include <vector>

#include "../include/pda.h"

class FPDA : public PDA {
 public:
  FPDA(std::string inital_state, std::string initial_stack_symbol,
       std::set<std::string> finite_states,
       std::vector<Transition> transition_functions)
      : PDA(inital_state, initial_stack_symbol, transition_functions),
        finite_states_(finite_states) {}

 private:
  std::set<std::string> finite_states_;
};

#endif  // INCLUDE_FPDA_H_
