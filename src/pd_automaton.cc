/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pd_automaton.h"

#include <stdexcept>

#include "../include/pda_reader.h"

PDAutomaton::PDAutomaton(Alphabet input_alphabet, std::string initial_state,
                         std::string initial_stack_symbol,
                         ListTransitions transition_functions) {
  input_alphabet_ = input_alphabet;
  initial_state_ = initial_state;
  initial_stack_symbol_ = initial_stack_symbol;
  transition_functions_ = transition_functions;
}

PDAutomaton::PDAutomaton(const char *filename) {
  *this = PDAReader::ReadFromFile(filename);
}

bool PDAutomaton::Check(std::string input_tape) {
  input_alphabet_.CheckString(input_tape);
  current_state_ = initial_state_;
  stack_ = std::stack<Symbol>();
  stack_.push(initial_stack_symbol_);
  for (char char_symbol : input_tape) {
    Symbol symbol = Symbol(1, char_symbol);
    try {
      std::vector<TransitionOutput> branches =
          transition_functions_.Transit(current_state_, stack_, symbol);
      CheckBranches(branches, symbol);
    } catch (std::runtime_error &e) {
      throw std::runtime_error(
          "The input string is not recognized by the Pushdown Automaton:\n  " +
          std::string(e.what()));
    }
  }
  return stack_.size() == 0;
}

void PDAutomaton::CheckBranches(std::vector<TransitionOutput> branches,
                                Symbol symbol) {
  return;
}

bool PDAutomaton::ChangeStack(TransitionOutput output) {
  current_state_ = output.state;
  switch (output.type) {
    case kReplace_:
    case kPop_:
      stack_.pop();
      break;
    case kPush_:
    case kNoChange_:
      break;
    default:
      throw std::runtime_error("Unexpected Transition Type");
  }
  for (Symbol stack_symbol : output.stack_symbols) {
    stack_.push(stack_symbol);
  }
  return true;
}
