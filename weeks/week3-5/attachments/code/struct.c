#include <stdio.h>

struct point {
  double x, y;
};

void print_point(struct point p) {
  printf("%f %f\n", p.x, p.y);
}

int main(void) {
  return 0;
}
