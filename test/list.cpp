#include <iostream>
#include "list/array.h"
#include "gtest/gtest.h"
#include "list/out_of_bounds.h"

using namespace kaduev13;

List* createList(int maxlength = 5) {
  return new ArrayList(5);
}

TEST(insert, at_the_start) {
  List *list = createList();
  list->Insert(13, list->First());
  int item = list->Retrieve(list->First());
  ASSERT_EQ(13, item);
}

TEST(insert, at_the_end) {
  List* list = createList();
  list->Insert(13, list->End());
  list->Insert(14, list->End());
  ASSERT_EQ(13, list->Retrieve(list->First()));
  ASSERT_EQ(14, list->Retrieve(list->Next(list->First())));
}

TEST(insert, length_overflow) {
  List *list = createList();
  list->Insert(0, list->End())
    ->Insert(1, list->End())
    ->Insert(2, list->End())
    ->Insert(3, list->End())
    ->Insert(4, list->End());
  EXPECT_THROW(list->Insert(5, list->End()), OutOfBounds*);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}