#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t child;

  if ((child = fork()) == -1) {
    // No checks on the return value
    puts("Failed to create a child");
    return EXIT_FAILURE;
  } else if (child == 0) { // child part
    puts("I am a child");
    sleep(10); // sleep 5 seconds
    puts("Child exit");
  } else {
    puts("I am waiting for child");
    waitpid(child, NULL, 0); // system call
    sleep(10); // library call
    puts("Finish waiting");
  }

  return EXIT_SUCCESS;
}
