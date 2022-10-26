#include <unistd.h>

int main(void) {
  // a function from the exec family
  // usually we use this function with fork()
  execl("/bin/echo", "/bin/echo", "hello", "world", NULL);
  return 0;
}
