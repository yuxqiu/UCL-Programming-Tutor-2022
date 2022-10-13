#include <stdio.h>

int main(void) {
  FILE *file = fopen("text.txt", "rt");
  getchar();
  fclose(file);
  return 0;
}
