#include <stdio.h>
#include <stdlib.h>

#define Debug 1

int sorter(const void *first_arg, const void *second_arg) {
  int* first = (int*) first_arg;
  int* second = (int*) second_arg;

  return *first - *second;
}

int reverse_sorter(const void *first_arg, const void *second_arg) {
  int* first = (int*) first_arg;
  int* second = (int*) second_arg;

  return *second - *first;
}

int (*comparator)(const void *first_arg, const void *second_arg) = sorter; 

void sort_part(int *array, int lo, int hi) {
  if (lo == hi-1) { return ; }
  int me = (hi+lo) / 2;
  sort_part(array, lo, me);
  sort_part(array, me, hi);
  int tmp_array[hi-lo];
  int count_lo = lo;
  int count_hi = me;
  while (count_lo < me && count_hi < hi) {
    if (comparator(array+count_lo, array+count_hi) <= 0) {
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

void mergesort(int *array, int size, int (*compare)(const void *, const void *)) {
  comparator = compare;
  sort_part(array, 0, size);
  if (Debug) {
    int n;
    for (n=0; n<10; n++) { printf("%d, ", array[n]); }
    printf("\n");
  }
}

int main() {
  int array[10] = {3, 5, 1, 7, 2, 7, 6, 0, 8, 4};

  mergesort(array, 10, &sorter);
  mergesort(array, 10, &reverse_sorter);

 
}
  
  
