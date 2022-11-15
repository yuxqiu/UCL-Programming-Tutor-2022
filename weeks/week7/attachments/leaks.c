#include <stdlib.h>

int main(void){
  // Memory leak here
  // Leak 16 bytes why?
  (void)malloc(4);

  return 0;
}
