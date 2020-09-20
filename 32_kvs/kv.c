#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void stripNewline(char * str) {
  char * p = strchr(str, '\n');
  if (p != NULL) {
    *p = '\0';
  }
}

kvpair_t * splitPair(char * line){
  kvpair_t * answer = malloc(sizeof(*answer));
  stripNewline(line);
  char * token = NULL;
  token = strtok(line, "=");
  answer->key = token;
  //while (token != NULL) {
  token = strtok(NULL,"=");
  answer->value = token;
  //}
  return answer;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen (fname, "r");
  if (f == NULL) {
    return NULL; //Could not open file->indicate failure
  }
  kvarray_t * answer = malloc(sizeof(*answer));
  answer->length = 0;
  answer->kvpairs = malloc((answer->length + 1)*(sizeof(*answer->kvpairs)) );
  char * line = NULL;
  size_t n;
  while ( getline(&line,&n,f)  >= 0 ) {
    answer->kvpairs = realloc(answer->kvpairs, (answer->length + 1)*(sizeof(*answer->kvpairs)) );
    answer->kvpairs[answer->length] = splitPair(line);
    line = NULL;
    answer->length++;
  }
  free(line);
  fclose(f);
  return answer;

}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    free(pairs->kvpairs[i]->key);
    //free(pairs->kvpairs[i]->value);
    free(pairs->kvpairs[i]);
  }
  free(pairs->kvpairs);
  free(pairs);

}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvpairs[i]->key, pairs->kvpairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for (int i = 0; i < pairs->length; i++) {
    if ( strcmp(key,pairs->kvpairs[i]->key) == 0) {
      return pairs->kvpairs[i]->value;
    }
  }
  return NULL;
}


