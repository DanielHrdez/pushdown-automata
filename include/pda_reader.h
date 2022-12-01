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

#include "../include/fpda.h"

class PDAReader {
 public:
  static PDA ReadFromFile(const char *filename);
  static FPDA ReadFromFileFPDA(const char *filename);

 private:
  using FPDATupleArgs =
      std::tuple<std::string, std::string, std::set<std::string>,
                 std::vector<Transition>>;

  static FPDATupleArgs ReadFile(const char *filename);
  static void IgnoreComments(std::ifstream &file);
  static void IgnoreLines(std::ifstream &file, size_t n);

  static std::set<std::string> ParseSet(std::ifstream &file);

  static std::string ParseInitial(std::ifstream &file);

  static std::vector<Transition> ParseTransitions(std::ifstream &file);

  static Transition ParseTransition(std::string file_line);
};

#endif  // INCLUDE_PDA_READER_H_
