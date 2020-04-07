unsigned int get_money(unsigned short int);

unsigned int get_money(unsigned short int amount ) {
  unsigned short int curr_notes = 0;
  int notes[] = { 2000, 500, 100, 50, 20, 10, 5, 1};
  int *note_ptr = notes;
  int num = 8;
  while( num != 0 ){
    curr_notes = curr_notes << 4;
    curr_notes = curr_notes | amount / *note_ptr;
    amount = amount % *note_ptr;
    note_ptr++;
    num--;
  }
  return curr_notes;
}