/*
Pinm 16 Check
Pin 15  Check
Pin 14  Check
Pin 10  Check
Pin 9   Check
Pin 8   Check
Pin 7   Check
Pin 6   Check
Pin 5   Check
Pin 4   Check
Pin 3   Check
Pin 2   Check
*/


//
// The digital pins are grounded when they are pressed.
// Pin 7 = UP
// Pin 5 = DOWN
// Pin 14 = RIGHT
// Pin 16 = LEFT
// Pin 4 = BUTTON
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Buchzn
// 11.10.2024
//--------------------------------------------------------------------
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  1, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

#define UP 7
#define DOWN 5
#define RIGHT 14
#define LEFT 16
#define BUTTON 4

void setup() {
  // Initialize Button Pins
  Serial.begin(9600);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(BUTTON, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastButtonState[5] = {0,0,0,0,0};
int pins[5] = {7,5,14,16,4};

void loop() {



  // Read pin values
  for (int index = 0; index < 5; index++)
  {
    int currentButtonState = digitalRead(pins[index]);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
        case 0: // UP
          if (currentButtonState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 1: // DOWN
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 2: // RIGHT
          if (currentButtonState == 1) {
            Joystick.setYAxis(1);
          } else {
            //Joystick.setYAxis(0);
          }
          break;
        case 3: // LEFT
          if (currentButtonState == 1) {
            //Joystick.setXAxis(-1);
            Serial.println("LEFT");
          } else {
            //Joystick.setXAxis(0);
          }
          break;
        case 4: // FIRE
          //Joystick.setButton(0, currentButtonState);
          break;
      }
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(10);
}