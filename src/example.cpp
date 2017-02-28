#include <iostream>
#include "list/array.h"

using namespace kaduev13;

int main() {
  List *list = new ArrayList(15);
  list->MakeNull();
  list->Print();
  for (int i = 0; i < 12; i++) {
    list->Insert(i, 0);
  }
  list->Print();
  list->Insert(333, 1);
  list->Print();
  list->Insert(222, 0);
  list->Print();
  list->Insert(999, list->Last() + 1);
  list->Print();
  list->Remove(0);
  list->Print();
  list->Remove(list->Last());
  list->Print();
  list->Remove(1);
  list->Print();
  std::cout << "Index of 0 is " << list->Locate(0) << "\n";
  std::cout << "Item at position 2 is " << list->Retrieve(2) << "\n";

  return 0;
}