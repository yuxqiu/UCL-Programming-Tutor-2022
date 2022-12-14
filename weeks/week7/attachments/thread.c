// This example is taken from Clang 16.0.0git documentation

#include <pthread.h>

int Global;

void *Thread1(void *x) {
  Global = 42;
  return x;
}

int main(void) {
  pthread_t t;
  pthread_create(&t, NULL, Thread1, NULL);
  Global = 43;
  pthread_join(t, NULL);
  return Global;
}
