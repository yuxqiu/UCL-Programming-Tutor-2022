#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = malloc(sizeof(int));
  if (!p)
    return 1;
  printf("%d\n", *p);
  free(p);
  return 0;
}
