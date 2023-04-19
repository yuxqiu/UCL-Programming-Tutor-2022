#include <iostream>

// algorithm
#include <algorithm>
// std::accumulate
#include <numeric>
#include <ostream>
#include <random>
#include <vector>

void PrintVector(const std::vector<int> &nums) {
  // Range-based for loop
  for (int i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main(void) {
  std::vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  // Sum the entire array
  std::cout << std::accumulate(nums.cbegin(), nums.cend(), 0) << std::endl;

  // count the number of items equal to some value of type T: std::count
  // as shown before in funcobj.cc

  // std::copy
  // as shown before in iterator.cc

  // std::shuffle
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(nums.begin(), nums.end(), g);

  // std::sort
  std::sort(nums.begin(), nums.end());
  PrintVector(nums);

  // std::binary_search
  // return bool
  std::cout << std::binary_search(nums.cbegin(), nums.cend(), 7) << std::endl;
  // lower_bound: find the first element that is >= the given value
  std::cout << (std::lower_bound(nums.cbegin(), nums.cend(), 7) != nums.end())
            << std::endl;
  // upper_bound: find  the first element that is > the given value
  std::cout << (std::upper_bound(nums.cbegin(), nums.cend(), 9) == nums.end())
            << std::endl;

  return 0;
}
