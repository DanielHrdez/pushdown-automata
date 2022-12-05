/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <iostream>

#include "../include/pd_automaton.h"
#include "../include/pda_parser.h"

int main() {
  PDAParser parser = PDAParser("examples/APv.txt");
  parser.IgnoreComments();
  std::cout << parser.FileReadPosition() << std::endl;
  // PDAutomaton pda = PDAutomaton("examples/APv.txt");
  // std::string str;
  // str = "ab";
  // std::cout << str << pda.Check(str) << std::endl;
  // str = "aab";
  // std::cout << str << pda.Check(str) << std::endl;
  // str = "abba";
  // std::cout << str << pda.Check(str) << std::endl;
  // str = "abaaba";
  // std::cout << str << pda.Check(str) << std::endl;
  return 0;
}
