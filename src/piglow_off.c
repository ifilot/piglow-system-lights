#include <wiringPi.h>
#include <sn3218.h>

#define	LED_BASE 533

int main (void) {
  int i;

  wiringPiSetupSys () ;

  sn3218Setup (LED_BASE) ;

  for (i = 0 ; i < 18 ; ++i) {
    analogWrite (LED_BASE + i, 0) ;
  }

  return 0;
}
