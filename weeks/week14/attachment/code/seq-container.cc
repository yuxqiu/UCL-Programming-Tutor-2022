#include <cstddef>
#include <iostream>

// std::vector
#include <vector>
// std::deque
#include <deque>
// std::list
#include <list>
// std::forward_list
#include <forward_list>

/* std::vector */
void SelectionSort(std::vector<int> &nums) {
  // It's better to use std::vector<int>::size_type instead of size_t

  // size()
  for (std::size_t i = 0; i < nums.size(); ++i) {
    std::size_t target = i;
    for (std::size_t j = i + 1; j < nums.size(); ++j) {
      // operator[]
      if (nums[j] < nums[target]) {
        target = j;
      }
    }
    // a function that swaps the first/second arg
    // it's easy to implement by using reference
    std::swap(nums[i], nums[target]);
  }
}

// Remember const correctness
void PrintVector(const std::vector<int> &nums) {
  // Range-based for loop
  for (int i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void PushToEndOfVector(std::vector<int> &nums) {
  // Add 8 and 9 to the end of the vector
  nums.push_back(8);
  nums.push_back(9);
}

void ClearVector(std::vector<int> &nums) {
  // Remove all the elements in the vector
  nums.clear();
}

void InsertToBeginningOfVector(std::vector<int> &nums) {
  // Insert 0 to the beginning of the vector
  // Don't worry about what's nums.begin now
  nums.insert(nums.begin(), 0);
}

void EraseFromBeginningOfVector(std::vector<int> &nums) {
  nums.erase(nums.begin(), nums.begin() + 1);
}
/* std::vector ends */

/* std::deque */
void PushToTheEndOfDeque(std::deque<int> &nums) {
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
}

void PushToTheFrontOfDeque(std::deque<int> &nums) {
  nums.push_front(-1);
  nums.push_front(-2);
  nums.push_front(-3);
}

void PopFromFrontOfDeque(std::deque<int> &nums) {
  nums.pop_front();
  nums.pop_front();
  nums.pop_front();
}

void PopFromEndOfDeque(std::deque<int> &nums) {
  nums.pop_back();
  nums.pop_back();
  nums.pop_back();
}

// We start to copy-paste vector code now
// Could we do better?
void PrintDeque(const std::deque<int> &nums) {
  // Range-based for loop
  for (int i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
/* std::deque ends */

/* std::list */
template <typename T> void PrintSeqContainer(const T &seq) {
  // auto: Type Deduction Here
  // it's worth noting that we also have auto in C
  // but they have completely different meanings
  for (const auto &elem : seq) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void PushToTheEndOfList(std::list<int> &nums) {
  nums.push_back(-1);
  nums.push_back(-2);
  nums.push_back(-3);
}

void PopFromEndOfList(std::list<int> &nums) {
  nums.pop_back();
  nums.pop_back();
  nums.pop_back();
}

void InsertToBeginningOfList(std::list<int> &nums) {
  // it's doubly linked list
  // so we don't need to worry about the insertion at the beginning
  nums.insert(nums.begin(), 0);
}

void EraseFromBeginningOfList(std::list<int> &nums) {
  // it's doubly linked list
  // so we don't need to worry about the erase at the beginning
  nums.erase(nums.begin());
}
/* std::list ends */

/* std::forward_list */
void InsertToBeginningOfForwardList(std::forward_list<int> &nums) {
  // it's singly linked list
  // so, we can only insert_after
  // or the insert we done before is like insert_before
  nums.insert_after(nums.before_begin(), 0);
}

void EraseFromBeginningOfForwardList(std::forward_list<int> &nums) {
  nums.erase_after(nums.before_begin());
}
/* std::forward_list ends */

int main(void) {
  /* std::vector */
  {
    // Initialize a vector with 10 element. Elements are initialized to 0.
    std::vector<int> nums_1(10);
    // Same as above, but elements are initialized to 1.
    std::vector<int> nums_2(10, 1);
  }
  // Initialize a vector using std::initializer_list.
  // The final vector contains 7 items from 7 to 1.
  std::vector<int> vector_nums = {7, 6, 5, 4, 3, 2, 1};

  SelectionSort(vector_nums);
  PrintVector(vector_nums);

  PushToEndOfVector(vector_nums);
  PrintVector(vector_nums);

  InsertToBeginningOfVector(vector_nums);
  PrintVector(vector_nums);

  EraseFromBeginningOfVector(vector_nums);
  PrintVector(vector_nums);
  /* std::vector ends */

  /* std::deque */
  std::deque<int> deque_nums;
  PushToTheEndOfDeque(deque_nums);
  PushToTheFrontOfDeque(deque_nums);
  PrintDeque(deque_nums);

  PopFromEndOfDeque(deque_nums);
  PopFromFrontOfDeque(deque_nums);
  PrintDeque(deque_nums);
  /* std::deque ends */

  /* std::list */
  std::list<int> list_nums;
  PushToTheEndOfList(list_nums);
  PrintSeqContainer(list_nums);

  InsertToBeginningOfList(list_nums);
  EraseFromBeginningOfList(list_nums);
  PrintSeqContainer(list_nums);

  PopFromEndOfList(list_nums);
  /* std::list ends */

  /* std::forward_list */
  std::forward_list<int> forward_list_nums;
  InsertToBeginningOfForwardList(forward_list_nums);
  PrintSeqContainer(forward_list_nums);

  EraseFromBeginningOfForwardList(forward_list_nums);
  /* std::forward_list ends */
}
