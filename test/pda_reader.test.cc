/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pda_reader.h"

#include <gtest/gtest.h>

#include "../include/fpda.h"

TEST(PDAReader, ReadFromFile) {
  EXPECT_NO_THROW(PDAReader::ReadFromFile("examples/APv.txt"));
}

TEST(PDAReader, AlsoReadFPDA) {
  EXPECT_NO_THROW(PDAReader::ReadFromFileFPDA("examples/APf.txt"));
}
