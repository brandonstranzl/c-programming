#include <stdlib.h>
#include <stdio.h>
#include "maxSeq.h"

//int maxSeq(int * array, size_t n);

int main(void) {
  int array1[] = {1,2,3,4};
  int array2[] = {5};
  int array3[] = {2,4,3,6,10,15,-1,7,8,2};
  int array4[] = { 1,2,3,2};
  int array5[] = {2,-3,5,6,8};
  int array6[] = { 2,2,2,6 };
  int array7[] = { -5 };
  
  if (maxSeq(NULL, 0)) {
    printf("Failed on NULL\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array1, 0)) {
    printf("Failed on 1,2,3,4 for NULL\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array1, 4) != 4) {    
    printf("Failed on 1,2,3,4\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array2, 1) != 1) {
    printf("Failed on 5\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array3, 10) != 4) {
    printf("Failed on 2,4,3,6,10,15,-1,7,8,2 \n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array4, 4) != 3) {
    printf("Failed on 1,2,3,2\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array5, 5) != 4) {
    printf("Failed on  2,-3,5,6,8\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6, 4) != 2) {
    printf("Failed on 2, 2, 2, 4\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array7, 1) != 1) {
   printf("Failed on -5\n");
   exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;

}
