#include <stdlib.h>

int AddN(int num, int n) {
  for (int i = 0; i < n; ++i) {
    ++num;
  }
  return num;
}

int Logic(int num, int m) {
  for (int i = 0; i < m; ++i) {
    num = AddN(num, 10000);
  }
  return num;
}

// Task: add a number by 10^8
int main(void) {
  Logic(0, 10000);
  return 0;
}
