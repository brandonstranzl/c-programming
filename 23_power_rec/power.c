#include <stdlib.h>
#include <stdio.h>
#include "power.h"

unsigned power(unsigned x, unsigned y) {
  if (y == 0) {
    return 1;
  }
  else 
  return power(x, (y-1)) * x;
}
