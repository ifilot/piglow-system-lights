#include <wiringPi.h>
#include <sn3218.h>
#include "piglow_colors.h"

#include <stdio.h>
#include <stdlib.h>

#define	LED_BASE 533

int main (void) {
  int i;

  wiringPiSetupSys () ;

  sn3218Setup (LED_BASE) ;

  // color outer red
  printf ("Glowing outer red\n");
  analogWrite (LED_BASE + LEG0_COLOR_RED0, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_RED0, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_RED0, 255) ;
  delay (1500);
  printf ("Glowing outer red\n");
  analogWrite (LED_BASE + LEG0_COLOR_RED1, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_RED1, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_RED1, 255) ;
  delay (1500);
  printf ("Glowing outer orange\n");
  analogWrite (LED_BASE + LEG0_COLOR_ORANGE, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_ORANGE, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_ORANGE, 255) ;
  delay (1500);
  printf ("Glowing outer green\n");
  analogWrite (LED_BASE + LEG0_COLOR_GREEN, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_GREEN, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_GREEN, 255) ;
  delay (1500);
  printf ("Glowing outer blue\n");
  analogWrite (LED_BASE + LEG0_COLOR_BLUE, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_BLUE, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_BLUE, 255) ;
  delay (1500);
  printf ("Glowing outer white\n");
  analogWrite (LED_BASE + LEG0_COLOR_WHITE, 255) ;
  analogWrite (LED_BASE + LEG1_COLOR_WHITE, 255) ;
  analogWrite (LED_BASE + LEG2_COLOR_WHITE, 255) ;
  delay (1500);

  for(i = 0; i < 18; ++i) {
    analogWrite(LED_BASE + i, 0);
  }

  return 0;
}
