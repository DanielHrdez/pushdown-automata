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
  std::set<std::string> finite_states;
};

class FPDA : public PDA {
 public:
  FPDA(std::string inital_state, std::string initial_stack_symbol,
       std::vector<Transition> transition_functions,
       std::set<std::string> finite_states);
  explicit FPDA(FPDAData data);

 private:
  std::set<std::string> finite_states_;
};

#endif  // INCLUDE_FPDA_H_
