#include <stdlib.h>
#include <stdio.h>
#include "rotate.h"

int main() {

char matrix[10];
FILE* fp;
char* filename = "sample2.txt";
fp = fopen(filename, "r");

if (fp == NULL){
  printf("Could not open file %s",filename);
  return 1;
}

for (int i = 0; i < 10; i++) {
    //for (int j = 0; j < 10 ; j++) { 
    //   fscanf (fp, "%c", &matrix[i][j]);
    //}
       fscanf (fp, "%c", &matrix[i]);
}      

fclose(fp);

//rotate(matrix[10][10]);

for (int i = 0; i < 10; i++) {
  //  for (int j = 0; j < 10 ; j++) { 
//      printf("%c", matrix[i][j]);
 //   }
        printf("%c", matrix[i];
}

return 0;

}

//while (fgets(str, 10, fp) != NULL)
//  printf("%s", str);