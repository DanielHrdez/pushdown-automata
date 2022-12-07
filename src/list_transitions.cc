/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/list_transitions.h"

#include <stdexcept>

ListTransitions::ListTransitions() {
  transition_functions_ = std::vector<Transition>();
}

ListTransitions::ListTransitions(std::vector<Transition> transitions) {
  transition_functions_ = transitions;
}

Branches ListTransitions::Transit(State state, Symbol input_symbol,
                                  Symbol stack_symbol) {
  Branches branches;
  for (Transition transition : transition_functions_) {
    try {
      TransitionOutput output =
          transition.Transit(state, input_symbol, stack_symbol);
      branches.push_back(output);
    } catch (...) {
      continue;
    }
  }
  if (branches.empty()) {
    throw std::runtime_error(
        "No exist Transition Function for symbol \x1B[31m" + input_symbol +
        "\033[0m with current state \x1B[31m" + state +
        "\033[0m and top stack \x1B[31m" + stack_symbol + "\033[0m");
  }
  return branches;
}
