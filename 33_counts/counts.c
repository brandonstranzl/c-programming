#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  //The first, createCounts should allocate memory for a counts_t structure, and initialize
  //it to represent that nothing has been counted yet.
   counts_t * answer = malloc(sizeof(*answer));
   answer->array = NULL;
   answer->size = 0;
   return answer;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  char * p;  
  if (name == NULL) {
    p = malloc(8*(sizeof(*p)));
    strcpy(p, "unknown");
  }
  else {
    int len = strlen(name);
    p = malloc((len+1)*(sizeof(*p)));
    strcpy(p, name);
  }
 
  int found = 0;
  for (int i = 0; i<c->size; i++) {
    int result = strcmp(c->array[i]->string, p);
    if (result == 0) {
      c->array[i]->count++;
      found = 1;
    }
  }

  if (found == 0) {
    one_count_t * new = malloc(sizeof(*new));
    new->string=p;
    new->count=1;
    c->size++;  
    c->array = realloc(c->array, c->size*(sizeof(*c->array)));
    c->array[c->size-1] = new;
    }
  else {
  free(p);
  }
}

void printCounts(counts_t * c, FILE * outFile) {

  for (int i = 0; i < c->size; i++) {
    if (strcmp(c->array[i]->string, "unknown") != 0) {
    fprintf(outFile, "%s: %d\n", c->array[i]->string, c->array[i]->count);
    }  
  }
  for (int i = 0; i < c->size; i++) {
    if (strcmp(c->array[i]->string, "unknown") == 0) {
    fprintf(outFile, "<%s>: %d\n", c->array[i]->string, c->array[i]->count);
    }  
  }

}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->size; i++) {
    free(c->array[i]->string);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}


/*
struct _one_count_t {
  //DEFINE ME
  char * string;
  int count; 
};

typedef struct _one_count_t one_count_t;

struct _counts_t {
  //DEFINE ME
  one_count_t ** array;
  size_t size;
};

typedef struct _counts_t counts_t;

*/
