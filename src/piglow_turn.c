#include <wiringPi.h>
#include <sn3218.h>

#include <stdio.h>
#include <stdlib.h>

#define	LED_BASE 533

int main (void) {
  int i;

  wiringPiSetupSys () ;

  sn3218Setup (LED_BASE) ;

  for (i = 0 ; i < 18 ; ++i) {
    printf ("Glowing %i\n",i);
    analogWrite (LED_BASE + i, 255) ;
    delay (1500);
    analogWrite (LED_BASE + i, 0) ;
  }

  return 0;
}
