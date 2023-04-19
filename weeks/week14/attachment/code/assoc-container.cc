#include <cstddef>
#include <functional>
#include <iostream>

// std::set
#include <set>
// std::map
#include <map>
// std::pair
#include <tuple>
#include <utility>
// std::unordered_set
#include <unordered_set>
// std::unordered_map
#include <unordered_map>

/* std::set */
void InsertToSet(std::set<int> &nums) {
  nums.insert(0);
  nums.insert(1);
  nums.insert(2);
}

// What would happen if you erase an element that is not in the list?
void EraseFromSet(std::set<int> &nums) {
  nums.erase(0);
  nums.erase(1);
  nums.erase(2);
}

class CustomTypeForSetMap {
public:
  int i;
  friend bool operator<(const CustomTypeForSetMap &lhs,
                        const CustomTypeForSetMap &rhs);
};

// There are many ways to overload operator.
// You can declare it as a free function like this, or declare it inside the
// class.
bool operator<(const CustomTypeForSetMap &lhs, const CustomTypeForSetMap &rhs) {
  return lhs.i < rhs.i;
}

class IncompatibleTypeForSet {};

template <typename T> void PrintSet(const T &set_like_container) {
  for (const auto &val : set_like_container) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
/* std::set ends */

/* std::map */
// Return true if they key exists in the map
bool FindFromMap(std::map<int, bool> &map_nums, int key) {
  return map_nums.find(key) != map_nums.end();
}

void AccessMap(std::map<int, bool> &map_nums, int key) {
  // Access map by using operator[]
  // When they key doesn't exist in map, the value will be default constructed
  // For bool, it will be initialized to 0
  map_nums[key] = true;
}

void PairExample() {
  // Internally, std::map uses std::pair to store the key, value pair
  // std::pair is a class template that allows you to put two custom types
  // inside
  std::pair<int, float> pair;
  pair.first = 1;
  pair.second = 1.;

  // The space of pair is allocated on the stack
}

void TupleExample() {
  // Tuple is like an advanced version of the map
  // You can put as many members as you like
  std::tuple<int, float, bool, char> tuple;

  // Access it is a bit hard
  std::get<0>(tuple) = 1;
  std::get<1>(tuple) = 1.;
  std::get<2>(tuple) = true;
  std::get<3>(tuple) = 'a';
}

// Insert and Erase in std::map is quite similar to those in std::Set

class IncompatibleTypeForMap {
public:
  IncompatibleTypeForMap(int i) : i(i) {}

  int i;
};
/* std::map ends */

/* std::unordered_* */
// unordered_* is implemented via HashMap
// So, if we want to use custom type to be the key (in std::unordered_map) or be
// the value (std::unordered_set), we need to define a hash function
// Primitive types (bool, int, ...) have their hash function.
// We only need to define these for custom types.

// You can do something like this:
class CustomTypeForUnorderedSetMap {
public:
  int i;
};

namespace std {
// This is called function object
// They overload the operator(), which allows them to be called as a function
// We will talk more about this in function object section.
template <> struct hash<CustomTypeForUnorderedSetMap> {
  std::size_t operator()(const CustomTypeForUnorderedSetMap &obj) const {
    return hash<int>()(obj.i);
  }
};
} // namespace std

// Besides hash, we need to overload operator==
// Why do we need this? (Think about how you could implement a HashMap)
bool operator==(const CustomTypeForUnorderedSetMap &lhs,
                const CustomTypeForUnorderedSetMap &rhs) {
  return lhs.i == rhs.i;
}
/* std::unordered_* ends */

int main(void) {
  /* std::set */
  std::set<int> set_nums;
  InsertToSet(set_nums);
  PrintSet(set_nums);

  EraseFromSet(set_nums);
  PrintSet(set_nums);

  std::set<CustomTypeForSetMap> set_custom;
  set_custom.insert(CustomTypeForSetMap{1});
  std::set<IncompatibleTypeForSet> set_incompatible;
  // set_incompatible.insert(IncompatibleTypeForSet{}); // compile-time errors

  /* std::set ends */

  /* std::map */
  std::map<CustomTypeForSetMap, bool> map_custom;
  map_custom[CustomTypeForSetMap{1}] = true;

  std::map<bool, IncompatibleTypeForMap> map_incompatible;
  // compile-time error: because the custom type for value cannot be default
  // constructed.
  // map_incompatible[true] = IncompatibleTypeForMap{1};

  /* std::map ends */

  /* std::unordered_* */
  std::unordered_set<CustomTypeForUnorderedSetMap> unordered_set_custom;
  unordered_set_custom.insert(CustomTypeForUnorderedSetMap{1});

  std::unordered_map<CustomTypeForUnorderedSetMap, bool> unordered_map_custom;
  unordered_map_custom[CustomTypeForUnorderedSetMap{1}] = true;
  /* std::unordered_* ends */

  return 0;
}
