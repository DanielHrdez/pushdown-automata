/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#ifndef INCLUDE_SET_STRINGS_H_
#define INCLUDE_SET_STRINGS_H_

#include <set>
#include <string>

class SetStrings {
 public:
  SetStrings();
  explicit SetStrings(std::set<std::string> set_strings);
  bool Contains(std::string element);
  bool CheckString(std::string string);
  bool Insert(std::string element);

  friend bool operator==(const SetStrings &left, const SetStrings &right) {
    return left.set_strings_ == right.set_strings_;
  }

 private:
  std::set<std::string> set_strings_;
};

using Alphabet = SetStrings;
using SetStates = SetStrings;

#endif  // INCLUDE_SET_STRINGS_H_
