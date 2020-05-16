#include <stdlib.h>
#include <stdio.h>
#include "power.h"

unsigned power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (power(x,y) != expected_ans) {
    printf("FAILED AT %d, %d, %d\n", x,y,expected_ans);
    exit(EXIT_FAILURE);
  }
/*  else {
    printf("Worked for %d, %d, %d\n", x,y,expected_ans);
    //exit(EXIT_SUCCESS);
  }
*/
}

int main() {
  //int x = 5;
  //int y = 3;
  //int result = power(x,y);
  //printf("%d\n", result);

  run_check(5,3,125);
  run_check(5,3,124);
  run_check(-5,3,125);
  run_check(5,-3,125);
  run_check(5,0,-125);
  run_check(0,3,125);
  run_check(0,0,125);
  
}




/*In particular, you should create a file
called test-power.c, which has a main function that performs the tests.

If the power function passes all test cases, your program should exit
with EXIT_SUCCESS.  If the power function fails any test case, your program
should exit with EXIT_FAILURE.  Note that your program's exit status is the
return value from main, if main returns.  However, you can make your program
exit immediately (wherever it is) by calling exit, passing in either EXIT_SUCCESS
or EXIT_FAILURE, e.g.

int main(void) {
  uint32_t array1[] = { 1, 2, 3, 4, 5, 15, 109};
  uint32_t array2[] = { 123456789, 987654321 };
  int bits[7*32-1];
  doTest (array1, 7);
  doTest (array2, 2);
  numToBits(array1,7, bits , 7*32-1);
  return EXIT_SUCCESS;
}
 When I did this, I wrote the following helper function:
       void run_check(unsigned x, unsigned y, unsigned expected_ans)
      which calls power, checks that the result is expected_ans,
      and if not, prints a message and calls exit(EXIT_FAILURE).






*/
