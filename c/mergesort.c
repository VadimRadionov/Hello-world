#include <stdio.h>
#include <stdlib.h>

#define Debug 1

int reverse_sorter(const void *first_arg, const void *second_arg) {
  int* first = (int*) first_arg;
  int* second = (int*) second_arg;

  if (*first > *second) { return -1; }
  else if (*first < *second) { return 1; }
  return 0;
}

void sort_part(int *array, int lo, int hi) {
  if (lo == hi-1) { return ; }
  int me = (hi+lo) / 2;
  sort_part(array, lo, me);
  sort_part(array, me, hi);
  int tmp_array[hi-lo];
  int count_lo = lo;
  int count_hi = me;
  while (count_lo < me && count_hi < hi) {
    if (array[count_lo] < array[count_hi]) {
      tmp_array[count_lo-lo+count_hi-me] = array[count_lo];
      count_lo++;
    } else {
      tmp_array[count_lo-lo+count_hi-me] = array[count_hi];
      count_hi++;
    }
  }
  int tmp_size = count_hi-me + count_lo-lo;
  while (count_lo < me) {
    array[count_lo+hi-me] = array[count_lo];
    count_lo++;
  }
  int n;
  for (n=lo; n<lo+tmp_size; n++) {
    array[n] = tmp_array[n-lo];
  }
  return ;
}

void mergesort(int *array, int size) {
  sort_part(array, 0, size);
  if (Debug) {
    int n;
    for (n=0; n<10; n++) { printf("%d, ", array[n]); }
    printf("\n");
  }
}

int main() {
  int array[10] = {3, 5, 1, 7, 2, 7, 6, 0, 8, 4};
  mergesort(array, 10);

  int array1[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  mergesort(array1, 10);

  int array2[10] = {-10000000, 2, 3, 4, 5, 100000000, 4, 3, 2, 1 };
  mergesort(array2, 10);

  int array3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  mergesort(array3, 10);
  
	 
}
  
  
