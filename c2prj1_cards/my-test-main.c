#include "cards.h"

int main(void) {

  void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);    
  };

}
