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

int (*comparator)(const void *first_arg, const void *second_arg); 

void sort_part(void *array, int lo, int hi, int size) {
  if (lo == hi-1) { return ; }
  char * a = array ;
  int n;
  int me = (hi+lo) / 2;
  sort_part(array, lo, me, size);
  sort_part(array, me, hi, size);
  char tmp_array[(hi-lo)*size];
  int count_lo = lo;
  int count_hi = me;
  while (count_lo < me && count_hi < hi) {
    if (comparator(a+count_lo*size, a+count_hi*size) <= 0) {
      for (n=0; n<size; n++) {
	tmp_array[(count_lo-lo+count_hi-me)*size+n] = *(a+count_lo*size+n);
      }
      count_lo++;
    } else {
      for (n=0; n<size; n++) {
	tmp_array[(count_lo-lo+count_hi-me)*size+n] = *(a+count_hi*size+n);
      }
      count_hi++;
    }
  }
  int tmp_size = (count_hi-me + count_lo-lo)*size;
  while (count_lo < me) {
    for (n=0; n<size; n++) {
      *(a+(count_lo+hi-me)*size+n) = *(a+count_lo*size+n);
    }
    count_lo++;
  }
  for (n=lo*size; n<lo*size+tmp_size; n++) {
    *(a+n) = tmp_array[n-lo*size];
  }
  return ;
}


void mergesort(void *array, int number, int elem_size , int (*compare)(const void *, const void *)) {
  comparator = compare;
  int size = elem_size;
  sort_part(array, 0, number, size);
}


int main() {
  int array[10] = {3, 5, 1000000000, 7, 2, 7, 6, 0, 8, -10000000};

  int n;

  mergesort(array, 10, sizeof(int), &sorter);
  for (n=0; n<10; n++) { printf("%d, ", array[n]); }
  printf("\n");

  mergesort(array, 10, sizeof(int), &reverse_sorter);
  for (n=0; n<10; n++) { printf("%d, ", array[n]); }
  printf("\n");
 
}
  
  
