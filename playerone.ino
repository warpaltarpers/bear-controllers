#include <Bounce2.h>

#ifndef __MKL26Z64__ // Using Teensy LC
#error Make sure you have a Teensy LC board, then select the proper board type in tools: Tools > Board > Teensy LC
#endif

// Setting pin positions as variables
const int kLeft = 0;
const int kRight = 1;
const int kUp = 2;
const int kAttack = 14;

const double kButtonInterval = 10;

Bounce btn = Bounce();

void setup() {
  // Set the pin for the Bounce, and pull the signal up.
  // If the signal is PULLUP by default, 'falling' is pressed.
  btn.attach(kUp, INPUT_PULLUP);

  // Set the interval for the pin
  btn.interval(kButtonInterval);

  delay(500);

  pinMode(kLeft, INPUT_PULLUP);
  pinMode(kRight, INPUT_PULLUP);
}
