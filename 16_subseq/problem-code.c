#include <stdlib.h>
#include <stdio.h>
#include "maxSeq.h"

int maxSeq(int * array, size_t n) {
  //printf("**inside maxseq**\n");
  for (int i=0; i<n; i++) {
    if (i != (n-1)) {
      printf("%d, ", array[i]);
    }
    if (i == (n-1)) {
      printf("%d end\n", array[i]);
    }
  }

  int count = 1;
  int max = 1;
  if (n == 0) {
    return 0;
  }
  for (int i=1;i<n;i++) {
    if (array[i] > array[i-1]) {
      count += 1;
      //printf("count = %d\n", count);
      if (count > max) {
      max = count;
      //printf("max  = %d\n",max);
      }
    } else {
    if (array[i] <= array[i-1]) {
      count = 1;
      //printf("here is count reset %d\n", count);
      } 
    }
  }  
  printf("answer = %d \n",max);
  return max; 
}

  /*int array1[] = {1,2,3,4};
  int array2[] = {5};
  int array3[] = {2,4,3,6,10,15,-1,7,8,2};
  int array4[] = { 1,2,3,2};
  int array5[] = {2,-3,5,6,8};
  int array6[] = { 2,2,2,6 };
  int array7[] = { -5 };

  i=1
  count = 1 + 1 = 2
  max = 2

  i=2
  count = 1

  i =3
  count = 2
  max = 2

  i = 4
  count = 3
  max = 3

  i = 5
  count = 4
  max = 4

  i = 6
  count =1

