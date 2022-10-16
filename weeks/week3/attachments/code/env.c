#include <stdio.h>

// Not Portable
int main(int argc, char *argv[], char *envp[]) {
  (void)argc, (void)argv;
  while (*envp) {
    puts(*(envp++));
  }
}
