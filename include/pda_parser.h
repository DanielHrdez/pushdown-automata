/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_PARSER_H_
#define INCLUDE_PDA_PARSER_H_

#include <fstream>
#include <string>
#include <vector>

#include "../include/pd_automaton.h"
#include "../include/set_strings.h"
#include "../include/transition.h"

class PDAParser {
 public:
  explicit PDAParser(const char *filename);
  std::streampos FileReadPosition();
  void IgnoreComments();
  SetStrings ParseSet();
  enum TypeInitial { kState_, kSymbol_ };
  std::string ParseInitial(SetStrings set, TypeInitial type);
  ListTransitions ParseTransitions(SetStates set_states,
                                   Alphabet input_alphabet,
                                   Alphabet stack_alphabet);
  Transition ParseTransition(std::string file_line, SetStates set_states,
                             Alphabet input_alphabet, Alphabet stack_alphabet);

 private:
  std::ifstream pda_file_;
};

#endif  // INCLUDE_PDA_PARSER_H_
