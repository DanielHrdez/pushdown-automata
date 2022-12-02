/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_FPDA_H_
#define INCLUDE_FPDA_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../include/pda.h"

struct FPDAData : PDAData {
  std::set<State> finite_states;
};

class FPDA : public PDA {
 public:
  FPDA(State inital_state, Symbol initial_stack_symbol,
       std::vector<Transition> transition_functions,
       std::set<State> finite_states);
  explicit FPDA(FPDAData data);

 private:
  std::set<State> finite_states_;
};

#endif  // INCLUDE_FPDA_H_
