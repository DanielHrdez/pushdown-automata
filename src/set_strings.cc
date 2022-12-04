/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/set_strings.h"

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
