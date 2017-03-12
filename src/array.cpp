#include "list/array.h"
#include "list/out_of_bounds.h"
#include <iostream>

namespace kaduev13 {

  ArrayList::ArrayList(int _maxlength): maxlength(_maxlength), last(-1) {
    elements = new int[_maxlength];
  };

  ArrayList::~ArrayList() {
    delete elements;
  };

  int ArrayList::Locate(int x) {
    for (int i = First(); i != End(); i = Next(i)) {
      if (Retrieve(i) == x) {
        return i;
      }
    }
    return -1;
  };

  int ArrayList::Retrieve(int position) {
    if (position > Previous(End()) || position < First()) {
      throw new OutOfBounds(End(), position);
    }
    return elements[position];
  };

  void ArrayList::Remove(int position) {
    if (position > Previous(End()) || position < First()) {
      throw new OutOfBounds(End(), position);
    }
    for (int i = position; i != Previous(End()); i = Next(i)) {
      elements[i] = Retrieve(Next(i));
    }
    last--;
  };

  int ArrayList::Next(int position) {
    if (position > End() || position < Previous(First())) {
      throw new OutOfBounds(End(), position);
    }

    return ++position;
  };

  int ArrayList::Previous(int position) {
    if (position > End() || position < First()) {
      throw new OutOfBounds(End(), position);
    }

    return --position;
  };

  List* ArrayList::Insert(int x, int position) {
    if (last >= maxlength - 1) {
      throw new OutOfBounds(maxlength, position);
    }
    if (position < First() || position > End()) {
      throw new OutOfBounds(End(), position);
    }
    for (int i = End(); i > position; i = Previous(i)) {
      elements[i] = Retrieve(Previous(i));
    }
    elements[position] = x;
    last++;

    return this;
  }

  void ArrayList::MakeNull() {
    last = -1;
  };

  int ArrayList::First() {
    return 0;
  }

  int ArrayList::End() {
    return last + 1;
  }

  void ArrayList::Print() {
    std::cout << "Array maxlength = " << maxlength << "\n";
    std::cout << "End = " << End() << "\n";
    std::cout << "Last = " << last << "\n";
    std::cout << "First = " << First() << "\n";
    for (int i = First(); i != End(); i = Next(i)) {
      std::cout << Retrieve(i) << " ";
    }
    std::cout << "\n";
  };
}
