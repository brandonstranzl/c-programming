#include <stdio.h>
#include <stdlib.h>

int f(int ** r, int ** s) {
  int temp = ** r;
  int temp2 = **s;
  int * z = *r;
  *r = *s;
  *s = z;
  printf("**r = %d\n",**r);
  printf("**s = %d\n",**s);
  *z += 3;
  **s -= 8;
  **r -= 19;
  return temp + temp2;
}

/*Note that r is a double pointer. This means that (*r) dereferences the pointer once to match the type of z, int *. Thus z is a pointer to the same value that the second pointer in r** points to. Imagine r consists of three parts - the first pointer, the second pointer and the value. *r retrieves the value of the second pointer. I've drawn some arrows below to help visualize.

int ** r has a type that implies it consists of: ptr1 -> ptr2 -> value

*r dereferences once so we get: ptr2 -> value

int * z = *r thus implies z = ptr2->value*/


int main(void) {
  int a = 80;
  int b = 12;
  int * p = &a;
  int * q = &b;
  int x = f(&p, &q);
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("*q = %d\n", *q);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return EXIT_SUCCESS;
}
