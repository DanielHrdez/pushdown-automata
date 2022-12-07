/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */
#include "../include/pda_parser.h"

#include <sstream>

PDAParser::PDAParser(std::string filename) {
  pda_file_ = std::ifstream(filename);
}

std::streampos PDAParser::FileReadPosition() { return pda_file_.tellg(); }

void PDAParser::IgnoreComments() {
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

SetStrings PDAParser::ParseSet() {
  SetStrings set_t;
  std::string string;
  std::getline(pda_file_, string);
  std::stringstream ss(string);
  while (std::getline(ss, string, ' ')) {
    set_t.Insert(string);
  }
  return set_t;
}

std::string PDAParser::ParseInitial(SetStrings set, TypeInitial type) {
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

ListTransitions PDAParser::ParseTransitions(SetStates set_states,
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
  pda_file_.close();
  return ListTransitions(transitions);
}

Transition PDAParser::ParseTransition(std::string file_line,
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
  if (!input_alphabet.Contains(from_input_symbol) && from_input_symbol != ".") {
    throw std::runtime_error("Input Symbol " + from_input_symbol +
                             " of the transition not in Alphabet");
  }

  std::getline(ss, from_stack_symbol, ' ');
  if (!stack_alphabet.Contains(from_stack_symbol) && from_stack_symbol != ".") {
    throw std::runtime_error("Input Symbol " + from_stack_symbol +
                             " of Stack in transition not in Alphabet");
  }

  std::getline(ss, to_state, ' ');
  if (!set_states.Contains(to_state)) {
    throw std::runtime_error("To state " + to_state +
                             " in transition not in the set of states");
  }

  while (std::getline(ss, aux_string, ' ')) {
    if (!stack_alphabet.Contains(aux_string) && aux_string != ".") {
      throw std::runtime_error("Symbol of Stack " + aux_string +
                               " in transition not in Alphabet");
    }
    to_stack_symbols.push_back(aux_string);
  }
  return {from_state, from_input_symbol, from_stack_symbol, to_state,
          to_stack_symbols};
}
