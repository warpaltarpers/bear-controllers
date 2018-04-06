#include <Bounce2.h>

#ifndef __MKL26Z64__ // Using Teensy LC
#error Make sure you have a Teensy LC board, then select the proper board type in tools: Tools > Board > Teensy LC
#endif

// Setting pin positions as variables
const int kLeft = 0;
const int kRight = 1;
const int kUp = 2;
const int kAttack = 14;
