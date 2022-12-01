/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <iostream>
#include "../include/pda_reader.h"

int main() {
  FPDA fpda = PDAReader::ReadFromFileFPDA("examples/APf.txt");
  std::cout << "FPDA complete!!" << std::endl;
  return 0;
}
