#ifndef KADUEV13_OUT_OF_BOUNDS
#define KADUEV13_OUT_OF_BOUNDS
#include <stdexcept>

namespace kaduev13 {
  class OutOfBounds : public std::logic_error {
  public:
    OutOfBounds(int _array_length, int _index);
  private:
    int array_length;
    int index;
  };
}

#endif