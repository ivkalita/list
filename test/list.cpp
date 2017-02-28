#include <iostream>
#include "list/array.h"
#include "gtest/gtest.h"

using namespace kaduev13;

TEST(test_case_name, test_name)
{
  ASSERT_EQ(1, 0) << "1 is not equal 0";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}