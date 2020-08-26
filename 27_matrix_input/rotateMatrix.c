#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix[10][10]) {
  char rotated[10][10];
  if(matrix != NULL) {
    for (int i = 0; i < 10; i ++) {
      for (int j = 0; j < 10; j++) {
	rotated[i][j] = matrix[10-1-j][i];
      }
    }
    for (int i = 0; i < 10; i ++) {
      for (int j = 0; j < 10; j++) {
	matrix[i][j] = rotated[i][j];
      }
    }
  }
}

void readMatrix(FILE * f, char matrix[10][10]) {
  int c;
  int numLines = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      c = fgetc(f);
      //printf("%c", c);
      if(c == EOF) {
	fprintf(stderr,"Empty File\n");
	exit(EXIT_FAILURE);
      }
      if (c == '\n') {
	fprintf(stderr,"line %d too short, %c = \\n at %d\n",i,c,j);
	exit(EXIT_FAILURE);
      }
      else {
	//write the first 10 chars of a row to the matrix
	matrix[i][j] = c;
      }
    }
    //chomp off next char make sure it's a '\n'
    if ( (c = fgetc(f)) != '\n' ) {
      fprintf(stderr,"Invalid input: line %d too long\n",i);
      exit(EXIT_FAILURE);
    }
    //else {
    //  printf("\n");
    // }
    numLines = i;
  }
  //fail if too few rows read
  if (numLines != 9) {
    fprintf(stderr,"Not enough rows\n");
    exit(EXIT_FAILURE);
  }
  //count each row read, fail if too many rows read
  if ( (c=fgetc(f)) != EOF) {
    fprintf(stderr,"Input file is too long\n");
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char ** argv) {

  if (argc != 2) {
    fprintf(stderr,"Invalid number of params in argv!\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if (f == NULL) {
    fprintf(stderr,"Invalid input file\n");
    return EXIT_FAILURE;
  }

  char matrix[10][10];

  readMatrix(f, matrix);
  rotate(matrix);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    };
    printf("\n");
  }

  if(fclose(f)!=0){
    fprintf(stderr,"Unable to close file '%s'\n",argv[1]);
    return EXIT_FAILURE;
  }

  return 0;
}
