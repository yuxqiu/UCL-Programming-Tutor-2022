#include <stdio.h>

void fun_to_test(unsigned int num) {
  if (num < 0) {
    printf("num is less than 0\n");
  } else {
    printf("num is larger than or equal to 0\n");
  }
}

void test_fun_to_test(void) {
  fun_to_test(1);
  fun_to_test(2);
  fun_to_test(0);
}

int main(void) {
  test_fun_to_test();
  return 0;
}
