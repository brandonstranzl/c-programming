#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix[10][10]) {
  char rotated[10][10];
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

int main(int argc, char ** argv) {

  FILE * f = fopen(argv[1], "r");  

    if (argc != 2) {
    fprintf(stderr,"Invalid number of params in argv!\n");
    exit(EXIT_FAILURE);
    }

    if (f == NULL) {    
    fprintf(stderr,"Invalid input file '%s' - input file == NULL\n",argv[1]);
    exit(EXIT_FAILURE);
  }

  char matrix[10][10];

  for (int i = 0; i < 10; i++) {
    char temp[12];
    if ( fgets(temp, 12, f) == NULL ) {
      exit(EXIT_FAILURE);
    }
    if (temp[10] == '\n') {
    for (int j = 0; j < 10; j++) {
      if (temp[j] != '\n') {
	    matrix[i][j] = temp[j];
      }
      else {
        fprintf(stderr,"Invalid input file '%s' - newline in wrong place\n",argv[1]);
	      exit(EXIT_FAILURE);
        }
	    }
    }
    else {
      fprintf(stderr,"Invalid input\n",argv[1]);
	    exit(EXIT_FAILURE);
    }
  }
  int c=fgetc(f);
  if(c != EOF){
    fprintf(stderr,"Input file '%s' is too long\n",argv[1]);
    exit(EXIT_FAILURE);
  }
  
  rotate(matrix);
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);    
    };
    printf("\n");
  }
  
  return 0;
}