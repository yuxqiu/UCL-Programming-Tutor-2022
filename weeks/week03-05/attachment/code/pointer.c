#include <stdio.h>
#include <stdlib.h>

// A function that cannot correctly swap two values
// void swap(int i, int j) {
//   int temp = i;
//   i = j;
//   j = temp;
// }

struct point {
  int x, y;
  double d1, d2, d3;
};

void swap(int *ip, int *jp) {
  int temp = *ip;
  *ip = *jp;
  *jp = temp;
}

void modify_array(int a[]) {
  a[0] = 1;
}

int main(void) {
  // int arr[] = {-1, 2, 3};
  // modify_array(arr);
  // printf("%d\n", arr[0]);

  int i = 0, j = 10;
  // int *p = &i; // pointer to int
  // swap(p, &j); // correctly swap two variables

  // function pointers
  void (*f)(int *, int *) = &swap;
  f(&i, &j); // call the functions

  // printf("%d %d\n", i, j);


  return 0;
}
