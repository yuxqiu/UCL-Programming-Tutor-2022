#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void handler(int i) {
  (void)i; // a trick to suppress compiler warning

  // Why `write`? We will talk about this if we have
  // a talk in concurrency
  const char *msg = "Hello World\n";
  write(1, msg, strlen(msg)); // Ignore the return value of write is incorrect
}

int main(void) {
  // This code is not compatible.
  signal(SIGINT, handler);

  getchar();

  // Why no return?
}
