#include "atm.h"
#include <stdio.h>

unsigned int get_money(unsigned short int amount ) {
  unsigned  int curr_notes = 0x00000000;
  int notes[] = { 2000, 500, 100, 50, 20, 10, 5, 1};

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

void print_notes(unsigned  int notes ){
  unsigned int notes_weight, notes_value = 0xf0000000;
  int notes_list[] ={ 1, 5, 10, 20,  50, 100,500, 2000};
  for(int i = 7; i >= 0; i--){
    notes_weight = (notes_value & notes) >> (i * 4);
    notes_weight && printf("%d notes of rupees %d\n",notes_weight, notes_list[i]);
    notes_value = notes_value >> 4;
  }
}