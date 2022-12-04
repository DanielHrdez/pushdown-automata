/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include "../include/pda_reader.h"

#include <gtest/gtest.h>

TEST(PDAReader, Constructor) { EXPECT_NO_THROW(PDAReader()); }

TEST(PDAReader, ReadFromFile) {
  PDAReader reader = PDAReader();
  EXPECT_NO_THROW(reader.ReadFromFile("examples/APv.txt"));
  EXPECT_NO_THROW(reader.ReadFromFile("examples/APv-2.txt"));
  EXPECT_NO_THROW(reader.ReadFromFile("examples/APv-3.txt"));
}

TEST(PDAReader, NotReadFromFile) {
  PDAReader reader = PDAReader();
  EXPECT_THROW(reader.ReadFromFile("examples/APf.txt"), std::runtime_error);
  EXPECT_THROW(reader.ReadFromFile("examples/APf-2.txt"), std::runtime_error);
  EXPECT_THROW(reader.ReadFromFile("examples/APf-3.txt"), std::runtime_error);
}
