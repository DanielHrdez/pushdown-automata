/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */
#include "../include/pda_tracer.h"

PDATracer::PDATracer() {}

PDATracer::PDATracer(State initial_state, Symbol initial_stack_symbol) {
  trace_ = "Automaton Initialized:\n  State: " + initial_state +
           ", Stack symbol: " + initial_stack_symbol + "\n";
}

void PDATracer::Add(Symbol symbol) {
  trace_ += "Reading Symbol: " + symbol + "\n";
}

void PDATracer::Add(State state, Symbol stack_symbol) {
  trace_ += "  State: " + state + ", Stack symbol: " + stack_symbol + "\n";
}

void PDATracer::Add(bool result) {
  trace_ += "The input string is ";
  if (result) {
    trace_ += "Accepted\n";
  } else {
    trace_ += "Rejected\n";
  }
}

void PDATracer::Error(const char *error) {
  trace_ += "The input string is not recognized by the Pushdown Automaton:\n " +
            std::string(error);
}

void PDATracer::Fail() { trace_ += "Branch Fails, changing to other..."; }

std::string PDATracer::ShowTrace() { return trace_; }
