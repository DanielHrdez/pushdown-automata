/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/set_strings.h"

#include <stdexcept>

SetStrings::SetStrings() { set_strings_ = {}; }

SetStrings::SetStrings(std::set<std::string> set_strings) {
  set_strings_ = set_strings;
}

bool SetStrings::Contains(std::string element) {
  return set_strings_.find(element) != set_strings_.end();
}

bool SetStrings::Insert(std::string element) {
  return set_strings_.insert(element).second;
}

bool SetStrings::CheckString(std::string string) {
  for (char symbol : string) {
    std::string s_symbol = std::string(1, symbol);
    if (!Contains(s_symbol)) {
      throw std::runtime_error("Symbol " + s_symbol +
                               " not included in the Alphabet");
    }
  }
  return true;
}
