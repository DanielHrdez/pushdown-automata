/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <iostream>
#include "../include/pda_reader.h"

int main() {
  PDAReader reader = PDAReader();
  PDA pda = reader.ReadFromFile("examples/APv-2.txt");
  std::cout << "PDA complete!!" << std::endl;
  return 0;
}
