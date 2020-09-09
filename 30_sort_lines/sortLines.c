#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}


char ** read_lines(FILE * input, char ** array, size_t * lines_read) {
  char * buffer = NULL;
  size_t n;
  while ( getline(&buffer,&n,input) >= 0 ) {
    array = realloc ( array, (*lines_read + 1)*(sizeof(*array)) );
    array[*lines_read] = buffer;
    buffer = NULL;
    (*lines_read)++;
    /*
      array[*lines_read] = malloc( (strlen(buffer)+1) * sizeof(array[*lines_read]));
      strcpy(array[*lines_read -1], buffer);
    */
  }
  free(buffer);
  return array;
}

void print_and_free(char ** array, int lines_read) {
  int i = 0;
  while (i < lines_read) {
    printf("%s",*(array + i));
    free(*(array +i));
    i++;
  }
  free(array);
}

//ssize_t getline (char **lineptr, size_t *n, FILE *stream)
int main(int argc, char ** argv) {
  char ** array = NULL;
  size_t lines_read = 0;

  if (argc == 1) {
    array = read_lines(stdin, array, &lines_read);
    sortData(array, lines_read);
    print_and_free(array, lines_read);
    array = NULL;
  }

  else {
    for (int i = 1; i < argc; i++) {
      FILE * f = fopen(argv[i], "r");
      if (f == NULL) {
	perror("Could not open file");
	return EXIT_FAILURE;
      }
      else {
	lines_read = 0;
	array = read_lines(f, array, &lines_read);
	sortData(array, lines_read);
	print_and_free(array, lines_read);
      }
      fclose(f);
      array = NULL;
    }
  }

  return EXIT_SUCCESS;

}

