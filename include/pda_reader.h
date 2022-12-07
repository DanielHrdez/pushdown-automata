/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_PDA_READER_H_
#define INCLUDE_PDA_READER_H_

#include <string>

#include "../include/pda_parser.h"

class PDAReader {
 public:
  static PDAutomaton ReadFromFile(std::string filename);
};

#endif  // INCLUDE_PDA_READER_H_
