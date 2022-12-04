/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_READER_H_
#define INCLUDE_PDA_READER_H_

#include <fstream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

#include "../include/pda.h"
#include "../include/set_strings.h"
#include "../include/transition.h"

class PDAReader {
 public:
  PDAReader() {}
  PDA ReadFromFile(const char *filename, Symbol epsilon = ".");

 private:
  enum TypeInitial { kState_, kSymbol_ };
  void IgnoreComments();
  SetStrings ParseSet();
  std::string ParseInitial(SetStrings set, TypeInitial type);
  std::vector<Transition> ParseTransitions(SetStates set_states,
                                           Alphabet input_alphabet,
                                           Alphabet stack_alphabet);
  Transition ParseTransition(std::string file_line, SetStates set_states,
                             Alphabet input_alphabet, Alphabet stack_alphabet);

  std::ifstream pda_file_;
};

#endif  // INCLUDE_PDA_READER_H_
