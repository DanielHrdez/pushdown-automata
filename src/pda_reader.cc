/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */
#include "../include/pda_reader.h"

#include <sstream>

#include "../include/fpda.h"

PDA PDAReader::ReadFromFile(const char *filename) {
  PDAData args = ReadFile(filename, false);
  return PDA(args);
}

FPDA PDAReader::ReadFromFileFPDA(const char *filename) {
  FPDAData args = ReadFile(filename, true);
  return FPDA(args);
}

FPDAData PDAReader::ReadFile(const char *filename, bool finite) {
  std::ifstream pda_file(filename);
  if (!pda_file.is_open()) {
    throw "File cannot be opened";
  }
  IgnoreComments(pda_file);
  IgnoreLines(pda_file, 3);
  std::string initial_state = ParseInitial(pda_file);
  std::string initial_stack_symbol = ParseInitial(pda_file);
  std::set<std::string> finite_states;
  if (finite) {
    finite_states = ParseSet(pda_file);
  }
  std::vector<Transition> transitions = ParseTransitions(pda_file);
  return {initial_state, initial_stack_symbol, transitions, finite_states};
}

void PDAReader::IgnoreComments(std::ifstream &file) {
  std::string file_line;
  while (file) {
    std::streampos oldpos = file.tellg();
    std::getline(file, file_line);
    if (file_line[0] != '#') {
      file.seekg(oldpos);
      break;
    }
  }
}

void PDAReader::IgnoreLines(std::ifstream &file, size_t n) {
  std::string aux;
  for (size_t i = 0; i < n; i++) {
    std::getline(file, aux);
  }
}

std::set<std::string> PDAReader::ParseSet(std::ifstream &file) {
  std::set<std::string> set_t;
  std::string string;
  std::getline(file, string);
  std::stringstream ss(string);
  while (std::getline(ss, string, ' ')) {
    set_t.insert(string);
  }
  return set_t;
}

std::string PDAReader::ParseInitial(std::ifstream &file) {
  std::string string;
  std::getline(file, string);
  return string;
}

std::vector<Transition> PDAReader::ParseTransitions(std::ifstream &file) {
  std::string file_line;
  std::vector<Transition> transitions;
  while (file) {
    std::getline(file, file_line);
    if (file_line == "") {
      break;
    }
    transitions.push_back(ParseTransition(file_line));
  }
  return transitions;
}

Transition PDAReader::ParseTransition(std::string file_line) {
  std::stringstream ss(file_line);
  std::string from_state, from_input_symbol, from_stack_symbol, to_state,
      aux_string;
  std::vector<std::string> to_stack_symbols;
  std::getline(ss, from_state, ' ');
  std::getline(ss, from_input_symbol, ' ');
  std::getline(ss, from_stack_symbol, ' ');
  std::getline(ss, to_state, ' ');
  while (std::getline(ss, aux_string, ' ')) {
    to_stack_symbols.push_back(aux_string);
  }
  return {from_state, from_input_symbol, from_stack_symbol, to_state,
          to_stack_symbols};
}
