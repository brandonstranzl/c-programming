#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

//.counts  + /0
char * computeOutputFileName(const char * inputName) {
  char * outFileName = malloc((strlen(inputName) + 8)  * sizeof(*outFileName));
  strcpy(outFileName, inputName);
  strcat(outFileName, ".counts");
  //free(outFileName);
  return outFileName;
  //WRITE ME
}
