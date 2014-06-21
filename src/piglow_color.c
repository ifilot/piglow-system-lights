#include <wiringPi.h>
#include <sn3218.h>
#include "piglow_colors.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	LED_BASE 533

static int getPercent (char *typed) {
  int percent ;

  percent = atoi (typed) ;
  if ((percent < 0) || (percent > 100)) {
    fprintf (stderr, "piglow: percent value out of range\n") ;
    exit (EXIT_FAILURE) ;
  }
  return (percent * 255) / 100 ;
}

int main (int argc, char *argv []) {
  int i;

  wiringPiSetupSys () ;

  sn3218Setup (LED_BASE) ;

  if(argc != 3) {
    return 1;
  } else {
    i = getPercent(argv[2]);
  }

  if ((argc == 3) && (strcasecmp (argv [1], "red0") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_RED0, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_RED0, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_RED0, i) ;
  }

  if ((argc == 3) && (strcasecmp (argv [1], "red1") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_RED1, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_RED1, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_RED1, i) ;
  }

  if ((argc == 3) && (strcasecmp (argv [1], "orange") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_ORANGE, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_ORANGE, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_ORANGE, i) ;
  }

  if ((argc == 3) && (strcasecmp (argv [1], "green") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_GREEN, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_GREEN, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_GREEN, i) ;
  }

  if ((argc == 3) && (strcasecmp (argv [1], "blue") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_BLUE, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_BLUE, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_BLUE, i) ;
  }

  if ((argc == 3) && (strcasecmp (argv [1], "white") == 0)) {
    analogWrite (LED_BASE + LEG0_COLOR_WHITE, i) ;
    analogWrite (LED_BASE + LEG1_COLOR_WHITE, i) ;
    analogWrite (LED_BASE + LEG2_COLOR_WHITE, i) ;
  }

  return 0;
}
