/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_LIST_TRANSITIONS_H_
#define INCLUDE_LIST_TRANSITIONS_H_

#include <stack>
#include <vector>

#include "../include/transition.h"

using Branches = std::vector<TransitionOutput>;

class ListTransitions {
 public:
  ListTransitions();
  explicit ListTransitions(std::vector<Transition> transitions);
  Branches Transit(State state, Symbol input_symbol, Symbol stack_symbol);

 private:
  std::vector<Transition> transition_functions_;
};

#endif  // INCLUDE_LIST_TRANSITIONS_H_
