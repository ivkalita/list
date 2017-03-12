#ifndef KADUEV13_LIST
#define KADUEV13_LIST

namespace kaduev13 {
  class List {
  public:
    virtual ~List() = 0;
    virtual List* Insert(int x, int position) = 0;
    virtual int Locate(int x) = 0;
    virtual int Retrieve(int position) = 0;
    virtual void Remove(int position) = 0;
    virtual int Next(int position) = 0;
    virtual int Previous(int position) = 0;
    virtual void MakeNull() = 0;
    virtual int First() = 0;
    virtual int End() = 0;
    virtual void Print() = 0;
  };

  inline List::~List() {}
}

#endif