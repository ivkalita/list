#include <iostream>
#include "list/array.h"
#include "gtest/gtest.h"
#include "list/out_of_bounds.h"

using namespace kaduev13;

List* createList(int maxlength = 5) {
  return new ArrayList(maxlength);
}

List* createFilledList(int maxlength = 5) {
  List *list = createList(maxlength);
  for (int i = 0; i < maxlength; i++) {
    list->Insert(i, list->End());
  }
  return list;
}

TEST(insert, at_the_start) {
  List *list = createList();
  list->Insert(13, list->First());
  int item = list->Retrieve(list->First());
  ASSERT_EQ(13, item) << "First element mismatch";
}

TEST(insert, at_the_end) {
  List* list = createList();
  list->Insert(13, list->End());
  list->Insert(14, list->End());
  ASSERT_EQ(13, list->Retrieve(0)) << "First element mismatch.";
  ASSERT_EQ(14, list->Retrieve(1)) << "Second element mismatch.";
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

TEST(insert, mixed) {
  List *list = createList();
  list->Insert(0, list->First());
  list->Insert(2, list->End());
  list->Insert(1, list->Next(list->First()));
  ASSERT_EQ(0, list->Retrieve(0)) << "First element mismatch.";
  ASSERT_EQ(1, list->Retrieve(1)) << "Second element mismatch.";
  ASSERT_EQ(2, list->Retrieve(2)) << "Third element mismatch.";
}

TEST(make_null, fill) {
  List *list = createList();
  list->Insert(0, list->First());
  ASSERT_FALSE(list->First() == list->End()) << "Non-null list is null.";
  list->MakeNull();
  ASSERT_TRUE(list->First() == list->End()) << "List is not null.";
}

TEST(previous, empty_pre_first) {
  List *list = createList();
  int pre_first = list->Previous(list->First());
  EXPECT_THROW(list->Previous(pre_first), OutOfBounds*);
}

TEST(previous, empty_first) {
  List *list = createList();
  int pos = list->Previous(list->First());
  ASSERT_EQ(-1, pos) << "Pre-first position mismatch.";
}

TEST(previous, empty_end) {
  List *list = createList();
  int pos = list->Previous(list->End());
  ASSERT_EQ(-1, pos) << "Pre-end position mismatch.";
}

TEST(previous, filled_pre_first) {
  List *list = createFilledList();
  int pre_first = list->Previous(list->First());
  EXPECT_THROW(list->Previous(pre_first), OutOfBounds*);
}

TEST(previous, filled_first) {
  List *list = createFilledList();
  int pos = list->Previous(list->First());
  ASSERT_EQ(-1, pos) << "Pre-first position mismatch.";
}

TEST(previous, filled_end) {
  List *list = createFilledList(5);
  int pos = list->Previous(list->End());
  ASSERT_EQ(4, pos) << "Pre-end position mismatch.";
}

TEST(next, empty_pre_first) {
  List *list = createList();
  int pre_first = list->Previous(list->First());
  ASSERT_EQ(list->First(), list->Next(pre_first));
}

TEST(next, empty_first) {
  List *list = createList();
  ASSERT_EQ(1, list->Next(list->First()));
}

TEST(next, empty_end) {
  List *list = createList();
  ASSERT_EQ(1, list->Next(list->End()));
}

TEST(next, empty_pre_end) {
  List *list = createList();
  int pre_end = list->Previous(list->End());
  ASSERT_EQ(list->End(), list->Next(pre_end));
}

TEST(next, empty_post_end) {
  List *list = createList();
  int post_end = list->Next(list->End());
  EXPECT_THROW(list->Next(post_end), OutOfBounds*);
}

TEST(next, filled_pre_first) {
  List *list = createFilledList();
  int pre_first = list->Previous(list->First());
  ASSERT_EQ(list->First(), list->Next(pre_first));
}

TEST(next, filled_first) {
  List *list = createFilledList();
  ASSERT_EQ(1, list->Next(list->First()));
}

TEST(next, filled_end) {
  List *list = createFilledList(5);
  ASSERT_EQ(6, list->Next(list->End()));
}

TEST(next, filled_pre_end) {
  List *list = createFilledList();
  int pre_end = list->Previous(list->End());
  ASSERT_EQ(list->End(), list->Next(pre_end));
}

TEST(next, filled_post_end) {
  List *list = createFilledList();
  int post_end = list->Next(list->End());
  EXPECT_THROW(list->Next(post_end), OutOfBounds*);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}