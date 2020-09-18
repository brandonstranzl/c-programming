#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define KNOWN_MINE -3
#define HAS_MINE -2
#define UNKNOWN -1

#define IS_MINE(x) ((x) == HAS_MINE || (x) == KNOWN_MINE)

struct _board_t {
  int ** board;
  int width;
  int height;
  int totalMines;
};

typedef struct _board_t board_t;

void addRandomMine(board_t * b) {
  int x;
  int y;
  //we could have a board too small for the number
  //of mines that we request. try w*h*10 times before
  //we give up
  int limit = b->width * b->height * 10;
  do {
    x = random() % b->width;
    y = random() % b->height;
    assert(limit > 0);
    limit--;
  } while(b->board[y][x] == HAS_MINE);
  b->board[y][x] = HAS_MINE;
}

board_t * makeBoard(int w, int h, int numMines ) {
  

  board_t *b = malloc (sizeof(*b));
  b->width = w;
  b->height = h;
  b->totalMines = numMines;

  b->board = malloc(h * sizeof( *(b->board) ) );
  //b->board = malloc(sizeof(int[h][w]));

  for(int i = 0; i < h; i++) {
    b->board[i] = malloc(w * sizeof( *(b->board) ) );
    for(int j = 0; j< w; j++) {
      b->board[i][j]=UNKNOWN;
    }
  } 

  for (int i = 0; i < numMines; i++) {
    addRandomMine(b);
  }

  return b;

} 

//#define IS_MINE(x) ((x) == HAS_MINE || (x) == KNOWN_MINE)
int countMines(board_t * b, int x, int y) {
  //WRITE ME!
  int r = b->height;
  int c = b->width;
  int count = 0;

  for (int i = -1; i < 2; i++) {
    int ny = y + i;
    if (ny >= 0 && ny <= r) {
      for (int j = -1; j < 2; j++) {
        int nx = x + j;
        if (nx >= 0 && nx <= c) {
          if IS_MINE(b->board[ny][nx]) {
            count++;
          }
        }
      }
    }
  }
  if ( count > 0 && IS_MINE(b->board[y][x]) ) {
    count--;
  }
  return count;
}

int checkWin(board_t * b) {
  //WRITE ME!
  int r = b->height;
  int c = b->width;
  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (b->board[i][j] == UNKNOWN) {
        count++;
      }
    }
  }
  if (count == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

void freeBoard(board_t * b) {
  //WRITE ME!
  int h = b->height;
  int w = b->width;

  for(int i = 0; i < h; i++) {
    free(b->board[i]); 
  }
  free(b->board);
  free(b);
}


int main(int argc, char * argv[]) {
  int w = atoi(argv[1]);
  int h = atoi(argv[2]);
  int numMines = atoi(argv[3]);
  
  board_t * b = makeBoard (w, h, numMines);
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j <  w; j++) {
      printf("%d", b->board[i][j]);
    }
    printf("\n");
  }

  printf("count mines around 1,1: %d\n",countMines(b,1,1));
  
  if (checkWin(b) == 1) {
    printf("checkwin = %d, you win\n", checkWin(b) );
  }
  else {
    printf("checkwin = %d, you lose\n", checkWin(b) );
  }

  freeBoard(b);

  return 0;
  
}

/*
board_t * makeBoard(int w, int h, int numMines ) {
  

  //board_t *b = malloc (sizeof(*b));
  
  //not sure why you need this:
  if(w > 0 && h > 0 && numMines > 0) {
    board_t *b = malloc(sizeof(*b));
    if( b == NULL ) {
      return NULL;
    }
    b->width = w;
    b->height = h;
    b->totalMines = numMines;
    b->board = malloc(h * sizeof( *(b->board) ) );
    //b->board = malloc(sizeof(int[h][w]));
    if(b->board==NULL){
      free(b);
      return NULL;
    }

    for(int i = 0; i < h; i++) {
      b->board[i] = malloc(w * sizeof( **(b->board) ) );
      if( b->board[i] == NULL ) {
        for(int m = 0; m < i; m++ ) {
        free(b->board[m]);
        free(b);
        return NULL;
        }
      }
      for(int j = 0; j< w; j++) {
        b->board[i][j]=UNKNOWN;
      }
    }
    for (int i = 0; i < numMines; i++) {
    addRandomMine(b);
    }
    return b;
  }
  return NULL;
}
*/