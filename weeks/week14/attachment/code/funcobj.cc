#include <iostream>

// std::bind
#include <functional>
// std::count
#include <algorithm>
#include <vector>

bool Even(int num) { return num == 1; }

int main(void) {
  std::vector<int> nums = {1, 23, 6, 21, 1, 8, 3, 0, 1};
  std::cout << std::count_if(nums.cbegin(), nums.cend(), &Even) << std::endl;

  // Suppose we have a more complicated condition
  // E.g. Number of items equal to 2 or equal to 3
  // DO we need to create a free function for every call?
  // We could use function object

  // Yes. You can create a struct inside a function in C/C++
  struct EqualToAOrB {
    int A, B;
    // This is a function object. As it overloads operator()
    // This makes it a callable. You can think like this:
    // every EqualToAOrB Object can be treated as a function
    bool operator()(int num) { return num == A || num == B; }
  };

  std::cout << std::count_if(nums.cbegin(), nums.cend(), EqualToAOrB{1, 0})
            << std::endl;
  std::cout << std::count_if(nums.cbegin(), nums.cend(), EqualToAOrB{23, 21})
            << std::endl;

  // But declaring a struct every time is still troublesome
  // Could we do better
  // Yes, by using lambda.

  std::cout << std::count_if(nums.cbegin(), nums.cend(),
                             [](int num) { return num == 1 || num == 6; });

  // A lambda looks like this
  // This is an empty function
  // This is essentially a syntactic sugar for local struct
  // We could only use auto as type because we don't know the name of the struct
  auto lambda = []() {};
  // You can call it. Nothing will happen.
  lambda();

  // Mutable lambda
  int i{0};
  auto lambda_2 = [i]() mutable {
    i = 1; // not possible without mutable keyword
  };
  lambda_2();

  return 0;
}
