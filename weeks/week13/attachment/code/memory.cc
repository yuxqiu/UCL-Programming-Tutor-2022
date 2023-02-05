int main(void) {
  // initialize a int with value 0
  int *i = new int(0);
  delete i;

  // initialize an array of int with random value
  int *array = new int[10];
  delete[] array; // use [] to delete the array

  // the order of construction and destruction
  // lower index to higher index
  int *array2 = new int[100];
  delete[] array2;

  // so array2[0] is first constructed, then array2[1]...array2[99]
  // array2[99] is first destructed, then array[98]...array[0]
}