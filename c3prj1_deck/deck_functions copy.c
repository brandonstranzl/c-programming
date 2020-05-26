#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//#define VALUE_ACE 14
//#define VALUE_KING 13
//#define VALUE_QUEEN 12
//#define VALUE_JACK 11

typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;
 
struct card_tag {
  unsigned value;
  suit_t suit;
};
typedef struct card_tag card_t;

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = (c / 4) + 2;
  temp.suit = c%4;
  return temp;
}

char value_letter(card_t c) {
  switch (c.value) {
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case 11: return 'A';
  case 12: return 'K';
  case 13: return 'Q';
  case 14: return 'J';
  default: return '?';
  }
}

char suit_letter(card_t c) {
  switch(c.suit) {
  case 0: return 's';
  case 1: return 'h';
  case 2: return 'd';
  case 3: return 'c';
  default: return '?';  
  }
}

struct deck_tag {
	  card_t ** cards;
	  size_t n_cards;
};
typedef struct deck_tag deck_t;

void print_card(card_t c) {
  char value = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c", value, suit);
}

void print_hand(deck_t * hand){
  for(size_t i=0; i<hand->n_cards; i++){
    card_t card = **(hand->cards+i);
    print_card(card);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(size_t i=0; i<d->n_cards; i++){
    card_t card = **((d->cards)+i);
    if (card.value == c.value && card.suit == c.suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t ** cards = d->cards;
  //card_t *temp;
  size_t n = d->n_cards;
  printf("\nhere is the n in shuffle %lu\n", n);
  int r;
  for(size_t i = n - 1; i > 0; i--){
    r = rand() % (i + 1);
    printf("%d  ", r);
    card_t temp = **(cards + i);
    **(cards + i) = **(cards + r);
    **(cards + r) = temp;
    // **((d->cards)+r) = **((d->cards)+i);
    // **((d->cards)+i) = **temp; 
  }
  printf("\n");
}

void assert_full_deck(deck_t * d) {
  // printf("here is the assert deck:\n");
  // print_hand(d);
  // printf("\n");
  // printf("size of d = %zu\n", d->n_cards);
  int count = 0;
  for(size_t i=0; i<d->n_cards; i++){
    card_t card1 = **(d->cards+i);
    //print_card(card1);
    //printf("\n");
    //printf(" YIKES %u%c\n", card1.value, suit_letter(card1));
    for(size_t j=0; j<d->n_cards; j++){
      card_t card2 = **(d->cards+j);
      //print_card(card2);  
      if(card2.value==card1.value && card2.suit == card1.suit) { 
         count = 1;
      }
      //printf(" ");
    }
    //printf("\ncount = %d\n", count);
  }
  assert(count == 1);
} 

int main(void) {
  //srand ( time(NULL) );

  card_t cards[52], *ptr[52];

  for (int i=0; i<52; i++) {
    cards[i] = card_from_num(i) ;
  };

  for (int i=0; i<52; i++) {
    ptr[i] = &cards[i];
  };//need to make this pointer randomly select some cards

  //for (int i=0; i<52; i++) {
  //  printf("%d%d \n", ptr[i]->suit, ptr[i]->value ); 
  //};

  // for (int i=0; i<52; i++) {
  //   char value = value_letter(*ptr[i]);
  //   char suit = suit_letter(*ptr[i]);
  //   printf("%c%c\n", value, suit); 
  // };

  printf("here is the array of cards[i]\n");
  printf("-----------------------------\n");
  for (int i=0; i<52; i++) {
    print_card(cards[i]);
    printf(" ");
  };
  printf("\n\n");
  
  printf("here is the array of card pointers ptr[i]\n");
  printf("-----------------------------------------\n");
  for (int i=0; i<52; i++) {
    print_card(*ptr[i]);
    printf(" ");
  };
  printf("\n\n");

  deck_t my_hand;
  my_hand.cards = ptr;
  my_hand.n_cards = 52;
  printf("here is the array of **ptr called my_hand[52]:\n");
  printf("----------------------------------------------\n");
  print_hand(&my_hand);
  printf("\n");

  //deck_t * d = &my_hand;
  card_t my_card;
  my_card.value = 20;
  my_card.suit = 3;
  if (deck_contains(&my_hand, my_card) == 1) {
    printf("YES!\n");
  }
  else {
    printf("NO!\n");
  };
  printf("\n");

  shuffle(&my_hand);
  printf("\nhere is the shuffled my_hand[52]:\n");
  printf("----------------------------------------------\n");
  print_hand(&my_hand);
  printf("\n\n");

  assert_full_deck(&my_hand); 


  return 0;

}
