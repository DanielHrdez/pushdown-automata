/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <gtest/gtest.h>
#include "../include/pda_reader.h"

TEST(PDAReader, ReadFromFile) {
  EXPECT_NO_THROW(PDAReader::ReadFromFile("examples/APv.txt"));
}

TEST(PDAReader, ReadGood) {
  PDA pda = PDAReader::ReadFromFile("examples/APv.txt");
  EXPECT_NO_THROW();
}
