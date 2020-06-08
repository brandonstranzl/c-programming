#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

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
  size_t n = d->n_cards;
  //printf("\nhere is the n in shuffle %lu\n", n);
  int r;
  for(size_t i = n - 1; i > 0; i--){
    r = rand() % (i + 1);
    //printf("%d  ", r);
    card_t temp = **(cards + i);
    **(cards + i) = **(cards + r);
    **(cards + r) = temp;
    // **((d->cards)+r) = **((d->cards)+i);
    // **((d->cards)+i) = **temp; 
  }
  //printf("\n");
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
