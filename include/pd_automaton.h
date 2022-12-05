/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PD_AUTOMATON_H_
#define INCLUDE_PD_AUTOMATON_H_

#include <string>
#include <vector>

#include "../include/list_transitions.h"
#include "../include/set_strings.h"

class PDAutomaton {
 public:
  PDAutomaton(Alphabet input_alphabet, State initial_state,
              Symbol initial_stack_symbol,
              ListTransitions transition_functions);
  explicit PDAutomaton(const char *filename);
  bool Check(std::string input_tape);

 private:
  bool ChangeStack(TransitionOutput transition_output);
  void CheckBranches(std::vector<TransitionOutput> branches, Symbol symbol);

  Alphabet input_alphabet_;
  State initial_state_;
  Symbol initial_stack_symbol_;
  ListTransitions transition_functions_;

  State current_state_;
  Stack stack_;
};

#endif  // INCLUDE_PD_AUTOMATON_H_
