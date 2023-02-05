#include <iostream>

int main() {
  // Indexing
  std::string s = "0123456789";
  std::cout << s[0] << std::endl;
  // std::cout << s.at(100) << std::endl;

  // Substring
  std::cout << s.substr(2, 2) << std::endl;

  // Search
  std::cout << s.find('9') << std::endl;    // by character
  std::cout << s.find("3456") << std::endl; // by string

  // Concatenation
  s += "abcd";
  s.append("efgh");
  std::cout << s << std::endl;

  // Iterate

  // NRW
  for (unsigned int i = 0; i < s.size(); ++i) {
    std::cout << s[i];
  }
  std::cout << std::endl;

  // For-range loop (since C++11)
  for (char c : s) {
    std::cout << c;
  }
  std::cout << std::endl;

  // Construction and Assignment
  const std::string a = s; // construction
  std::string b;
  b = a; // assignment

  return 0;
}
