#include "list/out_of_bounds.h"

namespace kaduev13 {
  OutOfBounds::OutOfBounds(int _array_length, int _index)
    : std::logic_error("Array index out of bounds"),
      array_length(_array_length),
      index(_index) { };

  int OutOfBounds::GetArrayLength() {
    return array_length;
  }

  int OutOfBounds::GetRequestedPosition() {
    return index;
  }
}