#include <stdlib.h>
#include <stdio.h>
#include "max-seq.h"

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
      printf("%d\n", count);
      }
    else {
    if (count > max) {
      max = count;
      printf("max  = %d\n",max);
      count = 1;
      printf("count = %d\n", count);
      }
    }
    if (count > max) {
      max = count;
    }  
  }
  printf("answer = %d \n",max);
  return max; 
}
  

/*int main(void) {
int array1[] = {11111,123456789};
int size = sizeof(array1)/sizeof((array1[0]));
maxSeq(array1,size);
printf("%d\n",maxSeq(array1,size));
}*/


