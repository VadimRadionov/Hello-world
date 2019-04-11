# include <stdio.h>
# include <stdlib.h>

void Double(int* a) {
  *a *= 2;
};

int reverse_sorter(const void *first_arg, const void *second_arg) {
  int* first = (int*) first_arg;
  int* second = (int*) second_arg;

  if (*first > *second) { return -1; }
  else if (*first < *second) { return 1; }
  return 0;
}

void mergesort(void)

int main() {
  int x = 42;
  Double(&x);
  printf("%d\n", x);

  int array[10] = {3, 5, 1, 7, 2, 7, 6, 0, 8, 4};
  qsort(array,10,sizeof(int),&reverse_sorter);

  int n;
  for (n=0; n<10; n++) { printf("%d, ", array[n]); }
}
  
  
