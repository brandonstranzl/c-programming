#include <stdlib.h>
#include <stdio.h>
//#include "max-seq.h"

int maxSeq(int * array, size_t n);

/*int maxSeq(int * array, size_t n) {
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

void doTest(int * array, int n) {
  printf("maxSeq of array(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
	      printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int * p = maxSeq (array, n);
  if (p == NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", *p);
  }
}*/

int main(void) {
  int array1[] = {1,2,3,4};
  int array2[] = {5};
  int array3[] = {2,4,3,6,10,15,-1,7,8,2 };
  int array4[] = { 1,2,3,2};
  int array5[] = { 2,-3,5,6,8};
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
    printf("Failed on 2,4,3,6,10,15,-1,7,8,\n");
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
    printf("Failed on NULL\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array7, 1) != 1) {
   printf("Failed on -2\n");
   exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;

}
