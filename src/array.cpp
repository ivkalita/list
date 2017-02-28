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
    for (int i = First(); i <= Last(); i = Next(i)) {
      if (Retrieve(i) == x) {
        return i;
      }
    }
    return -1;
  };

  int ArrayList::Retrieve(int position) {
    if (position > Last() || position < First()) {
      throw new OutOfBounds(Last(), position);
    }
    return elements[position];
  };

  void ArrayList::Remove(int position) {
    if (position > Last() || position < First()) {
      throw new OutOfBounds(Last(), position);
    }
    for (int i = position; i <= Previous(Last()); i = Next(i)) {
      elements[i] = elements[i + 1];
    }
    last--;
  };

  int ArrayList::Next(int position) {
    if (position >= last || position < -1) {
      throw new OutOfBounds(maxlength, position);
    }
    return ++position;
  };

  int ArrayList::Previous(int position) {
    if (position > last || position < 0) {
      throw new OutOfBounds(maxlength, position);
    }
    return --position;
  };

  void ArrayList::Insert(int x, int position) {
    if (last >= maxlength - 1) {
      throw new OutOfBounds(maxlength, position);
    }
    if (position < 0 || position > last + 1) {
      throw new OutOfBounds(last + 1, position);
    }
    for (int i = last + 1; i > position; i--) {
      elements[i] = elements[i - 1];
    }
    elements[position] = x;
    last++;
  }

  void ArrayList::MakeNull() {
    last = -1;
  };

  int ArrayList::First() {
    return 0;
  }

  int ArrayList::Last() {
    return last;
  }

  void ArrayList::Print() {
    std::cout << "Array maxlength = " << maxlength << "\n";
    std::cout << "Last = " << Last() << "\n";
    std::cout << "First = " << First() << "\n";
    if (last < 0) {
      std::cout << "No items\n";
    } else {
      std::cout << "Items:\n";
      for (int i = 0; i <= last; i++) {
        std::cout << elements[i] << " ";
      }
      std::cout << "\n";
    }
  };
}
