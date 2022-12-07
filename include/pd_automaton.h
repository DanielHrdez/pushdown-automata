/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PD_AUTOMATON_H_
#define INCLUDE_PD_AUTOMATON_H_

#include <stack>
#include <string>
#include <vector>

#include "../include/list_transitions.h"
#include "../include/pda_tracer.h"
#include "../include/set_strings.h"

using Head = size_t;
using Stack = std::stack<Symbol>;

class PDAutomaton {
 public:
  PDAutomaton(Alphabet input_alphabet, State initial_state,
              Symbol initial_stack_symbol,
              ListTransitions transition_functions);
  explicit PDAutomaton(std::string filename);
  bool Check(std::string input_tape);
  std::string ShowTrace();

 private:
  void UpdateStack(Stack *stack, TransitionOutput transition_output);
  void SaveBranches(Branches branches);
  Head PopBranch();
  bool TransitSaveBranches(Symbol symbol);
  void Initialize(std::string input_tape);

  Alphabet input_alphabet_;
  State initial_state_;
  Symbol initial_stack_symbol_;
  ListTransitions transition_functions_;

  State current_state_;
  Stack stack_;
  Head head_;

  std::stack<State> saved_states_;
  std::stack<Stack> saved_stacks_;
  std::stack<Head> saved_heads_;

  PDATracer tracer_;
};

#endif  // INCLUDE_PD_AUTOMATON_H_
