#include <stdio.h>
#include <limits.h>

int main(void){
  int a = INT_MIN;
  int b = -1;

  // Any differences between these two?

  // First case
  printf("%d\n", a / b);

  // Second case
  printf("%d\n", a / -1);

  return 0;
}
