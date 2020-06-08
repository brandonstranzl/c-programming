#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include <assert.h>
#define N_ITERS 2000000

void add_and_print(deck_t * d, char v, char s) {
  printf("Adding the %c%c",v,s);
  fflush(stdout);
  add_card_to(d,card_from_letters(v,s));
  printf(" results in: ");
  fflush(stdout);
  print_hand(d);
  printf("\n");
}
void check_contains(deck_t *d, char v, char s, int exp) {
  printf("Checking if the hand contains %c%c", v,s);
  fflush(stdout);
  int x = deck_contains(d,card_from_letters(v,s));
  printf(" got %d [%s]\n", x, (x==exp? "correct": "INCORRECT"));
  if (x != exp) {
    fprintf(stderr,"Incorrect value from deck_contains: stopping\n");
    exit(EXIT_FAILURE);
  }
}
int cnum_for_stest(card_t c){
  switch(c.suit){
  case CLUBS:
    assert(c.value == VALUE_KING || c.value == VALUE_QUEEN);
    return c.value == VALUE_KING?  0 : 5;
  case HEARTS:
    assert(c.value == VALUE_ACE || c.value == 4);
    if (c.value == VALUE_ACE) {
      return 1;
    }
    return 3;
  case SPADES:
    assert(c.value == VALUE_ACE || c.value == 2);
    if (c.value == VALUE_ACE) {
      return 4;
    }
    return 2;
  default:
    fprintf(stderr,"Invalid card in shuffle\n");
    abort();
  }
}
int numerize_hand(deck_t * temp){
  int cv[5];
  for(int i =0; i < 5; i++) {
    cv[i] = cnum_for_stest(*temp->cards[i]);
  }
  int total = 0;
  int mult[] = {120,24,6,2,1,0};
  for(int i =0; i < 5; i++) {
    int x = cv[i];
    for(int j = 0; j < i; j++) {
      if (cv[j] < cv[i]) {
	x--;
      }
    }
    assert(x>=0);
    total += x * mult[i];
    assert(total < 720);
  }
  return total;
}
int main(void) {
  printf("Creating a full deck:\n");
  printf("---------------------\n");
  deck_t empty;
  empty.n_cards = 0;
  empty.cards = NULL;
  check_contains(&empty, 'Q', 'c', 0);
  check_contains(&empty, '9', 'h', 0);
  check_contains(&empty, '3', 'd', 0);
  deck_t * d = make_deck_exclude(&empty);
  my_sort_deck(d);
  print_hand(d);
  printf("\n");
  assert_full_deck(d);
  check_contains(d, 'Q', 'c', 1);
  check_contains(d, '9', 'h', 1);
  check_contains(d, '5', 's', 1);
  print_hand(d);
  printf("\n");
  assert_full_deck(d);
  printf("\nMaking a smaller deck...\n");
  deck_t * temp = malloc(sizeof(*temp));
  temp->n_cards = 0;
  temp->cards =NULL;
  add_and_print(temp, 'K', 'c');
  add_and_print(temp, 'A', 'h');
  add_and_print(temp, '2', 's');
  add_and_print(temp, '4', 'h');
  check_contains(temp, '4', 'h', 1);
  check_contains(temp, 'A', 's', 0);
  add_and_print(temp, 'A', 's');
  check_contains(temp, 'Q', 'c', 0);
  add_and_print(temp, 'Q', 'c');
  check_contains(temp, 'Q', 'c', 1);
  check_contains(temp, 'K', 'h', 0);
  check_contains(temp, 'A', 'c', 0);
  check_contains(temp, 'A', 's', 1);
  check_contains(temp, '3', 'd', 0);
  check_contains(temp, '2', 's', 1);
  size_t counts[720] = {0};
  for(int i = 0; i < N_ITERS; i++) {
    shuffle(temp);
    int total = numerize_hand(temp);
    counts[total]++;
  }
  printf("\n");
  size_t max_ind = 0;
  size_t min_ind = 0;
  for(int i = 1; i < 720;i++) {
    if (counts[i] > counts[max_ind]) {
      max_ind = i;
    }
    if (counts[i] < counts[min_ind]) {
      min_ind = i;
    }
  }
  double max_pct = counts[max_ind]*100.0/(double)N_ITERS;
  double min_pct = counts[min_ind]*100.0/(double)N_ITERS;
  double diff = max_pct- min_pct;
  assert(diff >= 0);
  printf("%lf (%lf - %lf) \n", diff, max_pct, min_pct);
  return EXIT_SUCCESS;
}
