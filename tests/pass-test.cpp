#include "../src/Randomizer/pass.hpp"
#include "gtest/gtest.h"

TEST(SetandGet, SetAndGet) {
  PassGen obj;
  obj.setPassword("asd");
  EXPECT_EQ("asd", obj.getPassword());
}

TEST(GeneratePass, PassGen) {
  PassGen obj;
  std::string a;
  obj.GeneratePassword(1, 1, 5);
  a = obj.getPassword();
  EXPECT_EQ(5, a.length());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
