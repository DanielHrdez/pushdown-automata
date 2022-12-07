/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_TRACER_H_
#define INCLUDE_PDA_TRACER_H_

#include <string>

using Symbol = std::string;
using State = std::string;

class PDATracer {
 public:
  PDATracer();
  PDATracer(State initial_state, Symbol initial_stack_symbol);
  void Add(Symbol symbol);
  void Add(State state, Symbol stack_symbol);
  void Add(bool result);
  void Fail();
  void Error(const char *error);
  std::string ShowTrace();

 private:
  std::string trace_;
};

#endif  // INCLUDE_PDA_TRACER_H_
