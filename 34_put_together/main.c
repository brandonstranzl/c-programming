#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kv) {
  //WRITE ME
  counts_t * c = createCounts();
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL; //Could not open file->indicate failure
  }
  char * line = NULL;
  size_t n = 0;
  while ( getline(&line,&n,fp)  >= 0 ) {
    char *p =strchr(line,'\n');
    *p='\0';
    addCount(c, lookupValue(kv, line)); 
  }
  free(line);
  fclose(fp);
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc < 3) {
    fprintf(stderr,"%s : Invalid number of arguments!\n", argv[0]);
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
      //count the values that appear in the file named by argv[i], using kv as the key/value pair
      //   (call this result c)
      counts_t * c = countFile(argv[i],kv);
      //compute the output file name from argv[i] (call this outName)
      char * outName = malloc((strlen(argv[i]) + 8)* sizeof(*outName));
      strcpy(outName, argv[i]);
      strcat(outName, ".counts");

      //open the file named by outName (call that f)
      FILE *fp = fopen(outName, "w");
      //print the counts from c into the FILE f
      printCounts(c, fp);
      //close f
      fclose(fp);
      //free the memory for outName and c
      free(outName);
      freeCounts(c);
  }
  //free the memory for kv
  freeKVs(kv);

  return EXIT_SUCCESS;
}

/*struct _one_count_t {
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

/*
struct _kvpair_t {
  //DEFINE ME!
  char * key; //name of fruit
  char * value; // color of fruit

};
typedef struct _kvpair_t kvpair_t;

struct _kvarray_t {
  //DEFINE ME!
  kvpair_t ** kvpairs;
  int length;
};
typedef struct _kvarray_t kvarray_t;
*/
