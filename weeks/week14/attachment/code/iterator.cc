#include <iostream>

// std::copy
#include <algorithm>
#include <iterator>
#include <vector>

int main(void) {
  std::vector<int> v = {1, 2, 3, 4, 5};

  // Range-based for loop
  for (int i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // Use iterator
  // Notice const correctness
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // A fancier way to output by using iterator adaptor
  // We will talk more about this in algorithm
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
