/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */
#include "../include/pda_reader.h"

#include "../include/pda_parser.h"

PDAutomaton PDAReader::ReadFromFile(std::string filename) {
  PDAParser parser = PDAParser(filename);
  parser.IgnoreComments();
  SetStates set_states = parser.ParseSet();
  Alphabet input_alphabet = parser.ParseSet();
  Alphabet stack_alphabet = parser.ParseSet();
  State initial_state =
      parser.ParseInitial(set_states, PDAParser::TypeInitial::kState_);
  Symbol initial_stack_symbol =
      parser.ParseInitial(stack_alphabet, PDAParser::TypeInitial::kSymbol_);
  ListTransitions transitions =
      parser.ParseTransitions(set_states, input_alphabet, stack_alphabet);
  return {input_alphabet, initial_state, initial_stack_symbol, transitions};
}
