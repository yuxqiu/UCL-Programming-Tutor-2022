#include <stdio.h>

int main(void) {
  // r means read, w means write;
  // t means text; b means binary;
  // rt means read as text
  // wb means write as bytes
  FILE *file = fopen("../others/text.txt", "rt");
  getchar();
  fclose(file);
  return 0;
}

// File Descriptor Table
// 0 = stdin
// 1 = stdout
// 2 = stderr
// 3 = ../others/text.txt
// ......
