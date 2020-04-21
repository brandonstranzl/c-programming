#include <stdlib.h>
#include <stdio.h>
#include "max-seq.h"

int maxSeq(int * array, size_t n) {
  int count = 1;
  int max = 1;
  if (n == 0) {
    return 0;
  }
  for (int i=0;i<(n-1);i++) {
    if (array[i] < array[i+1]) {
      count += 1;
    }
    else {
    if (count > max) {
      max = count;
      count = 1;
      }
    } 
  }
  return max;
}

int main(void) {
int array1[] = {11111,123456789};
int size = sizeof(array1)/sizeof((array1[0]));
maxSeq(array1,size);
printf("%d\n",maxSeq(array1,size));
}
