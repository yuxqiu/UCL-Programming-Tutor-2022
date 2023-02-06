void thread_local_storage() {
  thread_local int i;
  (void)i;
}

void static_storage() {
  static int i;
  (void)i;
}

void automatic_storage() {
  int i;
  (void)i;
}

void dynamic_storage() {
  int *ptr = new int();
  delete ptr;
}
