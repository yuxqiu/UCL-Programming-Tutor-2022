#include <string>

template <typename T> struct Point {
public:
  T m_x_;
  T m_y_;

  //   NRW
  Point(T x = 0, T y = 0) : m_x_(x), m_y_(y) {
    // write your function body
    m_x_ = x;
    // m_y_ = y;
  }
};

// a null op
// NRW
template <typename T> void f(T) {}

int main() {
  Point<int> p = {1, 2};
  Point<double> pd = {1.5, 2.5};

  f(p);
  f(pd);

  // why we template string: w string
  std::wstring ws;
}
