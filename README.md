# Custom Vector Class in C++

A lightweight implementation of a dynamic array (vector) class in C++ that mimics the behavior of the STL `std::vector` container.

---

## Features

- Dynamic resizing of the array
- Supports basic operations:
  - `push_back()`
  - `pop_back()`
  - `insert()`
  - `erase()`
  - `clear()`
  - `size()`
  - `capacity()`
  - Element access (`operator[]`, `at()`, `front()`, `back()`)
- Supports iterators and reverse iterators
- Exception safety for out-of-bound access
- Custom memory management

---

## Usage

Include the header file and create a vector object like this:

```cpp
#include "Vector.h"

int main() {
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 10 20 30

    return 0;
}
