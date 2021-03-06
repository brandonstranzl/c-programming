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
  char * p = strchr(line, '=');
  size_t keylen = p - line + 1;
  answer->key = malloc(keylen*sizeof(answer->key));
  strncpy(answer->key, line, keylen - 1);
  answer->key[keylen - 1] = '\0';
  int valueLength = strchr(line, '\0')-p;
  answer->value = malloc((valueLength + 1)*sizeof(answer->value));
  strncpy(answer->value, p + 1, valueLength);
  answer->value[valueLength + 1] = '\0';
  return answer;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen (fname, "r");
  if (f == NULL) {
    return NULL; //Could not open file->indicate failure
  }
  kvarray_t * answer = malloc(sizeof(*answer));
  if(answer==NULL){
    return NULL;
  }
  answer->length = 0;
  answer->kvpairs = NULL;
  char * line = NULL;
  size_t n = 0;
  size_t length = 0;
  while ( getline(&line,&n,f)  >= 0 ) {
    answer->kvpairs = realloc(answer->kvpairs, (length + 1)*(sizeof(*answer->kvpairs)) );
    answer->length = length + 1;
    answer->kvpairs[length] = splitPair(line);
    length++;
  }
  free(line);
  fclose(f);
  return answer;
}

void freeKVs(kvarray_t * answer) {
  //WRITE ME
  for (int i = 0; i < answer->length; i++) {
    free(answer->kvpairs[i]->key);
    free(answer->kvpairs[i]->value);
    free(answer->kvpairs[i]);
  }
  free(answer->kvpairs);
  free(answer);

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


