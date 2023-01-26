struct Point {
public:
  int m_x_;
  const int m_y_;

  Point(int x = 0, int y = 0) : m_x_(x), m_y_(y) {
    // write your function body
    m_x_ = x;
    // cannot do this as this is not the way to initialize stuff
    // m_y_ = y;
  }

  ~Point() {}

  //   Copy Constructor and Assignment
  Point(const Point &);
  Point &operator=(const Point &);
};

// All the fields in `class` are default to be private
// class PointPrivate {
//   int x;
//   int y;
// };

// C way to define a struct
typedef struct PointInC {

} PointInc;

// In C
struct PointInC p1;

// In C++
Point p2;
