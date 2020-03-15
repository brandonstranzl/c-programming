#include <stdio.h>
#include <stdlib.h>


/* 
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
  // if coord is in range, return 1
  if (coord >= offset && coord <= (offset + size)) {
    return 1;
  }
  // else, return 0
  else {
    return 0;
  }
}

/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  // if coord is equal to offest or offset + size
  if (coord == offset || coord == (offset + size)) {
    return 1;
  }
  else {
    return 0;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w;
  int h;

  if (size1 > (x_offset + size2)) {
    w = size1;
  }
  else {
    w = (x_offset + size2);
  }


  //compute the max of size1 and (y_offset + size2).  Call this h
  if (size1 > (y_offset + size2)) {
    h = size1;
  }
  else {
    h = (y_offset + size2);
  }

  //loop through and print
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if ((isInRange(x, x_offset, (size2-1)) && isAtBorder(y, y_offset, (size2-1))) ||
	  (isInRange(y, y_offset, (size2-1)) && isAtBorder(x, x_offset, (size2-1))))
	{
	  printf("*");
	}
      else if
	(((x < size1) && (y == 0 || y == (size1 - 1))) ||
	 ((y < size1) && (x == 0 || x == (size1 -1)))) {
	printf("#");
      }
      else {
	printf(" ");
      } 
    }
    printf("\n");
   }
}
