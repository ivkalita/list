#ifndef KADUEV13_ARRAY
#define KADUEV13_ARRAY

#include "list/list.h"

namespace kaduev13 {
  class ArrayList: public List {
  public:
    ArrayList(int maxlength);
    ~ArrayList();
    List* Insert(int x, int position);
    int Locate(int x);
    int Retrieve(int position);
    void Remove(int position);
    int Next(int position);
    int Previous(int position);
    void MakeNull();
    int First();
    int End();
    void Print();
  private:
    int maxlength;
    int *elements;
    int last;
  };
}

#endif