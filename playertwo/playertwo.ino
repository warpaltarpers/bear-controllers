#include <Bounce2.h>

#ifndef __MKL26Z64__ // Using Teensy LC
#error Make sure you have a Teensy LC board, then select the proper board type in tools: Tools > Board > Teensy LC
#endif

// Setting pin positions as variables
const int kLeft = 0;
const int kRight = 1;
const int kUp = 2;
const int kAttack = A0;

int flexPos;
int isTouchL;
int isTouchR;

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
  pinMode(kAttack, INPUT_PULLUP);
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

  // Mapping the flex sensor to attack
  /* Don't un-comment until flex sensor is plugged in
  flexPos = analogRead(kAttack);
  flexPos = map(flexPos, 0, 1023, 0, 1);
  if(flexPos == 0){
    Keyboard.release(KEY_P);
  } else if(flexPos == 1){
    Keyboard.press(KEY_P);
  }
  */

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
