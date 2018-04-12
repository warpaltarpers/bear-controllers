#include <Bounce2.h>

#ifndef __MKL26Z64__ // Using Teensy LC
#error Make sure you have a Teensy LC board, then select the proper board type in tools: Tools > Board > Teensy LC
#endif

// Setting pin positions as variables
const int kLeft = 0;
const int kRight = 1;
const int kUp = 2;
const int kAttack = 15;

int flexPos;
int isTouchL;
int isTouchR;

const double kButtonInterval = 10;

Bounce btn = Bounce();
Bounce btnAtt = Bounce();

void setup() {
  // Set the pin for the Bounce, and pull the signal up.
  // If the signal is PULLUP by default, 'falling' is pressed.
  btn.attach(kUp, INPUT_PULLUP);
  btnAtt.attach(kAttack, INPUT_PULLUP);

  // Set the interval for the pin
  btn.interval(kButtonInterval);
  btnAtt.interval(kButtonInterval);

  delay(500);

  pinMode(kLeft, INPUT_PULLUP);
  pinMode(kRight, INPUT_PULLUP);
}

void loop() {
  // This let's the Bounce update it's status.
   btn.update();
   // This will activate once each time the button is pressed.
   // In other words, when the signal 'falls'.
   if ( btn.fell() ) {
    Keyboard.press(KEY_I);
   }

   // This will activate once each time the button is released.
   // In other words, when the signal 'rises'.
   if ( btn.rose() ) {
    Keyboard.release(KEY_I);
  }

   // This let's the Bounce update it's status.
   btnAtt.update();
   // This will activate once each time the button is pressed.
   // In other words, when the signal 'falls'.
   if ( btnAtt.fell() ) {
    Keyboard.press(KEY_P);
   }

   // This will activate once each time the button is released.
   // In other words, when the signal 'rises'.
   if ( btnAtt.rose() ) {
    Keyboard.release(KEY_P);
  }

  // Mapping left movement
  isTouchL = touchRead(kLeft);
  if(isTouchL > 4500){
    Keyboard.press(KEY_J);
  } else {
    Keyboard.release(KEY_J);
  }

  // Mapping right movement
  isTouchR = touchRead(kRight);
  if(isTouchR > 4500){
    Keyboard.press(KEY_L);
  } else {
    Keyboard.release(KEY_L);
  }
}
