#include <wiringPi.h>
#include <sn3218.h>
#include "piglow_colors.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	LED_BASE 533

void rotateLight(int light1, int light2, int light3) {
  for(;;) {
    analogWrite (LED_BASE + light1, 255);
    delay(500);
    analogWrite (LED_BASE + light1, 0);
    analogWrite (LED_BASE + light2, 255);
    delay(500);
    analogWrite (LED_BASE + light2, 0);
    analogWrite (LED_BASE + light3, 255);
    delay(500);
    analogWrite (LED_BASE + light3, 0);
  }
}

int main (int argc, char *argv []) {
  wiringPiSetupSys () ;

  sn3218Setup (LED_BASE) ;

  if(argc != 2) {
    return 1;
  }

  if ((argc == 2) && (strcasecmp (argv [1], "red0") == 0)) {
    rotateLight(LEG0_COLOR_RED0, LEG1_COLOR_RED0, LEG2_COLOR_RED0);
  }

  if ((argc == 2) && (strcasecmp (argv [1], "red1") == 0)) {
    rotateLight(LEG0_COLOR_RED1, LEG1_COLOR_RED1, LEG2_COLOR_RED1);
  }

  if ((argc == 2) && (strcasecmp (argv [1], "orange") == 0)) {
    rotateLight(LEG0_COLOR_ORANGE, LEG1_COLOR_ORANGE, LEG2_COLOR_ORANGE);
  }

  if ((argc == 2) && (strcasecmp (argv [1], "green") == 0)) {
    rotateLight(LEG0_COLOR_GREEN, LEG1_COLOR_GREEN, LEG2_COLOR_GREEN);
  }

  if ((argc == 2) && (strcasecmp (argv [1], "blue") == 0)) {
    rotateLight(LEG0_COLOR_BLUE, LEG1_COLOR_BLUE, LEG2_COLOR_BLUE);
  }

  if ((argc == 2) && (strcasecmp (argv [1], "white") == 0)) {
    rotateLight(LEG0_COLOR_WHITE, LEG1_COLOR_WHITE, LEG2_COLOR_WHITE);
  }

  return 0;
}
