/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */
#include "../include/pda_reader.h"

#include <sstream>

PDA PDAReader::ReadFromFile(const char *filename, Symbol epsilon) {
  pda_file_ = std::ifstream(filename);
  if (!pda_file_.is_open()) {
    throw "File cannot be opened";
  }
  IgnoreComments();
  SetStates set_states = ParseSet();
  Alphabet input_alphabet = ParseSet();
  input_alphabet.Insert(epsilon);
  Alphabet stack_alphabet = ParseSet();
  stack_alphabet.Insert(epsilon);
  State initial_state = ParseInitial(set_states, TypeInitial::kState_);
  Symbol initial_stack_symbol =
      ParseInitial(stack_alphabet, TypeInitial::kSymbol_);
  std::vector<Transition> transitions =
      ParseTransitions(set_states, input_alphabet, stack_alphabet);
  return {input_alphabet, initial_state, initial_stack_symbol, transitions};
}

void PDAReader::IgnoreComments() {
  std::string file_line;
  while (pda_file_) {
    std::streampos oldpos = pda_file_.tellg();
    std::getline(pda_file_, file_line);
    if (file_line[0] != '#') {
      pda_file_.seekg(oldpos);
      break;
    }
  }
}

SetStrings PDAReader::ParseSet() {
  SetStrings set_t;
  std::string string;
  std::getline(pda_file_, string);
  std::stringstream ss(string);
  while (std::getline(ss, string, ' ')) {
    set_t.Insert(string);
  }
  return set_t;
}

std::string PDAReader::ParseInitial(SetStrings set, TypeInitial type) {
  std::string string;
  std::getline(pda_file_, string);
  if (set.Contains(string)) {
    return string;
  }
  std::string error_msg = "The initial ";
  if (type == TypeInitial::kState_) {
    error_msg += "state is not included in the Set of states";
  } else {
    error_msg += "symbol is not included in the Alphabet of the stack";
  }
  throw error_msg;
}

std::vector<Transition> PDAReader::ParseTransitions(SetStates set_states,
                                                    Alphabet input_alphabet,
                                                    Alphabet stack_alphabet) {
  std::string file_line;
  std::vector<Transition> transitions;
  while (pda_file_) {
    std::getline(pda_file_, file_line);
    if (file_line == "") {
      break;
    }
    transitions.push_back(
        ParseTransition(file_line, set_states, input_alphabet, stack_alphabet));
  }
  return transitions;
}

Transition PDAReader::ParseTransition(std::string file_line,
                                      SetStates set_states,
                                      Alphabet input_alphabet,
                                      Alphabet stack_alphabet) {
  std::stringstream ss(file_line);
  std::string from_state, from_input_symbol, from_stack_symbol, to_state,
      aux_string;
  std::vector<std::string> to_stack_symbols;

  std::getline(ss, from_state, ' ');
  if (!set_states.Contains(from_state)) {
    throw std::runtime_error("From state " + from_state +
                             " in transition not in the set of states ");
  }

  std::getline(ss, from_input_symbol, ' ');
  if (!input_alphabet.Contains(from_input_symbol)) {
    throw std::runtime_error("Input Symbol " + from_input_symbol +
                             " of the transition not in Alphabet");
  }

  std::getline(ss, from_stack_symbol, ' ');
  if (!stack_alphabet.Contains(from_stack_symbol)) {
    throw std::runtime_error("Input Symbol " + from_stack_symbol +
                             " of Stack in transition not in Alphabet");
  }

  std::getline(ss, to_state, ' ');
  if (!set_states.Contains(to_state)) {
    throw std::runtime_error("To state " + to_state +
                             " in transition not in the set of states");
  }

  while (std::getline(ss, aux_string, ' ')) {
    if (!stack_alphabet.Contains(aux_string)) {
      throw std::runtime_error("Symbol of Stack " + aux_string +
                               " in transition not in Alphabet");
    }
    to_stack_symbols.push_back(aux_string);
  }
  return {from_state, from_input_symbol, from_stack_symbol, to_state,
          to_stack_symbols};
}
