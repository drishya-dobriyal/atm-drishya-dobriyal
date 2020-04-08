#include <stdio.h>
#include "atm.h"

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < 6; i++)
  {
    printf("For amount %d\n",amounts[i] );
    unsigned int notes = get_money(amounts[i]);
    print_notes(notes);
  }
  return 0;
}
