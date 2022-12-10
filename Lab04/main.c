/*
WARNING:
This code is LICENSED.
This code is public but it doesn't mean you can take it and send it as yours.
Please, provide your code and your ideas for this course, you may take
inspirations from this code. Any actions that will harm our group can and will
be legally persecuted. As this code is on github with a timestamp, even if you
copy this code and deliver before my team, you will take an action against my
license which is legally registered on github. # Author: Gaetano Salvatore Falco
*/

#include "bufferArray.h"
#include <stdio.h>
#include <stdlib.h>

S buffer;

int main() {
  buffer = BUFFERinit(2);

  BUFFERpush(buffer, 5);
  BUFFERpush(buffer, 13);
  printf("\nBuffer size: \t%d", BUFFERsize(buffer));
  printf("\nBuffer sum is: \t%d", BUFFERshowSum(buffer));
  BUFFERpush(buffer, 13);
  printf("\nBuffer size: \t%d", BUFFERsize(buffer));
  printf("\nBuffer sum is: \t%d", BUFFERshowSum(buffer));
  return 0;
}