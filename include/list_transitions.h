/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_LIST_TRANSITIONS_H_
#define INCLUDE_LIST_TRANSITIONS_H_

#include <stack>
#include <vector>

#include "../include/transition.h"

using Stack = std::stack<Symbol>;

class ListTransitions {
 public:
  ListTransitions();
  explicit ListTransitions(std::vector<Transition> transitions);
  std::vector<TransitionOutput> Transit(State state, Stack stack,
                                        Symbol symbol);

 private:
  std::vector<Transition> transition_functions_;
};

#endif  // INCLUDE_LIST_TRANSITIONS_H_
