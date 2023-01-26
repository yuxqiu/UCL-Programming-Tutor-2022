#include <iostream>
#include <ostream>

class Point {
private:
  int m_x_;
  int m_y_;

public:
  Point(int x = 0, int y = 0) : m_x_(x), m_y_(y) {}

  //   Return & to support chaining
  Point &operator+=(const Point &other) {
    m_x_ += other.m_x_;
    m_y_ += other.m_y_;
    return *this;
  }

  //   remember the const correctness
  bool operator==(const Point &other) const {
    return m_x_ == other.m_x_ && m_y_ == other.m_y_;
  }

  friend std::ostream &operator<<(std::ostream &out, const Point &p);
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << "Point{" << p.m_x_ << ", " << p.m_y_ << "}";
  return out;
}

int main() {
  std::string s = "0123";

  // Concatenation
  // Equivalent to the s.operator+=...
  // due to the operator overloading
  s += "abcd";
  s.operator+=("abcd");

  int i = 0;
  (i += 10) += 10;

  Point p = {1, 2}, p2 = {0, -1};
  p += p2;
  std::cout << p << std::endl;

  const Point pa = {1, 2}, pb = {1, 2};
  std::cout << (pa == pb);

  return 0;
}