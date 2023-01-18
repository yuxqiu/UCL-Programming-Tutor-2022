#include <time.h>
#include <stdio.h>

// Do not use this in real-world development
int main(void) {
  double startTime = (double)clock() / CLOCKS_PER_SEC;

  // Do something

  double endTime = (double)clock() / CLOCKS_PER_SEC;
  double timeElapsed = endTime - startTime;

  printf("%f\n", timeElapsed);

  return 0;
}
