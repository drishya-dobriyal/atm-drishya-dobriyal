#include "atm.h"

unsigned int get_money(unsigned short int amount ) {
  unsigned  int curr_notes = 0x00000000;
  int notes[] = DENOMINATIONS;

  if( amount > MAX_VALUE ){
    return curr_notes;
  }
  for( int i = 0; i < 8; i++) {
    curr_notes = curr_notes << 4;
    curr_notes = curr_notes | amount / notes[i];
    amount = amount % notes[i];
  }
  return curr_notes;
}
