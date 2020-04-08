#include "atm.h"
#include <stdio.h>

unsigned int get_money(unsigned short int amount ) {
  unsigned  int curr_notes = 0x00000000;
  int notes[] = DENOMINATIONS;

  if( amount > MAX_VALUE ){
    return curr_notes;
  }
  for( int i = 0; i < 8; i++) {
    curr_notes <<= 4;
    curr_notes |= amount / notes[i];
    amount %= notes[i];
  }
  return curr_notes;
}

void print_notes(unsigned  int notes ){
  unsigned int note_weight, note_position = 0xf0000000;
  int notes_list[] = DENOMINATIONS;
  for(int i = 0; i < 8; i++){
    note_weight = (note_position & notes) >> ((7 - i) * 4);
    note_weight && printf("%d notes of rupees %d\n",note_weight, notes_list[i]);
    note_position >>= 4;
  }
}