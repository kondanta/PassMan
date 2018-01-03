#include "../inc/pass.hpp"
#include "../src/pass.cpp"
#include "gtest/gtest.h"

TEST(Testing, Testing) {
  PassGen obj;
  obj.setPassword("asd");
  EXPECT_EQ("asd", obj.getPassword());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
