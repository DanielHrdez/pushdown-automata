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
  tracer_ = PDATracer(initial_state_, initial_stack_symbol_);
}

PDAutomaton::PDAutomaton(std::string filename) {
  *this = PDAReader::ReadFromFile(filename);
}

std::string PDAutomaton::ShowTrace() { return tracer_.ShowTrace(); }

bool PDAutomaton::Check(std::string input_tape) {
  Initialize(input_tape);
  Head initial_head = 0;
  size_t input_length = input_tape.length();

  if (input_length == 0) {
    while (!stack_.empty()) {
      if (TransitSaveBranches(".")) {
        break;
      }
    }
  }

  while (!stack_.empty() || initial_head != input_length) {
    for (head_ = initial_head; head_ < input_length; head_++) {
      Symbol symbol = Symbol(1, input_tape[head_]);
      if (TransitSaveBranches(symbol) && saved_heads_.empty()) {
        return false;
      }
    }
    if (saved_heads_.empty() || stack_.empty()) {
      break;
    }
    initial_head = PopBranch();
  }

  bool result = stack_.empty();
  tracer_.Add(result);
  return result;
}

void PDAutomaton::Initialize(std::string input_tape) {
  input_alphabet_.CheckString(input_tape);
  current_state_ = initial_state_;
  stack_ = std::stack<Symbol>();
  stack_.push(initial_stack_symbol_);
  tracer_ = PDATracer(current_state_, initial_stack_symbol_);
}

bool PDAutomaton::TransitSaveBranches(Symbol symbol) {
  tracer_.Add(symbol);
  try {
    Symbol stack_symbol;
    if (stack_.empty()) {
      stack_symbol = ".";
    } else {
      stack_symbol = stack_.top();
    }
    Branches branches =
        transition_functions_.Transit(current_state_, symbol, stack_symbol);
    SaveBranches(branches);
  } catch (std::runtime_error &e) {
    tracer_.Error(e.what());
    stack_.push(".");
    return true;
  }
  return false;
}

Head PDAutomaton::PopBranch() {
  tracer_.Fail();
  Head head = saved_heads_.top();
  current_state_ = saved_states_.top();
  stack_ = saved_stacks_.top();
  saved_heads_.pop();
  saved_states_.pop();
  saved_stacks_.pop();
  return head;
}

void PDAutomaton::SaveBranches(Branches branches) {
  for (size_t i = 1; i < branches.size(); i++) {
    saved_heads_.push(head_ + 1);
    saved_states_.push(branches[i].state);
    Stack new_stack = stack_;
    UpdateStack(&new_stack, branches[i]);
    saved_stacks_.push(new_stack);
  }
  UpdateStack(&stack_, branches[0]);
  Symbol stack_symbol;
  if (stack_.empty()) {
    stack_symbol = ".";
  } else {
    stack_symbol = stack_.top();
  }
  tracer_.Add(current_state_, stack_symbol);
}

void PDAutomaton::UpdateStack(Stack *stack, TransitionOutput output) {
  current_state_ = output.state;
  switch (output.type) {
    case kReplace_:
    case kPop_:
      (*stack).pop();
      break;
    case kPush_:
    case kNoChange_:
      break;
    default:
      throw std::runtime_error("Unexpected Transition Type");
  }
  for (Symbol stack_symbol : output.stack_symbols) {
    (*stack).push(stack_symbol);
  }
}
