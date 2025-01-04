//
// The digital pins are grounded when they are pressed.
// Pin 15 = Up
// Pin 10 = Down
// Pin 2  = Right
// Pin 3  = Left
// Pin 9  = Fire Button
// Pin 8  = B Button
// Pin 4  = Switch 1
// Pin 6  = Switch 2
// Pin 7  = Switch 3
// Pin 14 = Switch 4
// Pin 16 = Switch 5
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Buchzn
// 11.10.2024
//--------------------------------------------------------------------
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  10, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

#define UP 15
#define DOWN 10
#define RIGHT 2
#define LEFT 3
#define BUTTONO 9 
#define BUTTONR 8

#define SW1 4
#define SW2 6
#define SW3 7
#define SW4 14
#define SW5 16

void setup() {
  // Initialize Button Pins
  ///Serial.begin(9600);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(BUTTONO, INPUT_PULLUP);
  pinMode(BUTTONR, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastState[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Pin definition
int Pins[11] = {UP,DOWN,RIGHT,LEFT,BUTTONO,BUTTONR,SW1,SW2,SW3,SW4,SW5};

void loop() {

  // Read Button values
  for (int index = 0; index < 11; index++) {
    int currentState = !digitalRead(Pins[index]);
    if (currentState != lastState[index]) {
      switch (index) {
        case 0: // UP
          if (currentState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 1: // DOWN
          if (currentState == 1) {
            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 2: // RIGHT
          if (currentState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 3: // LEFT
          if (currentState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 4: // FIRE
          Joystick.setButton(0, currentState);
          break;
        case 5: // Back Button
          Joystick.setButton(1, currentState);
          break;
        case 6: // Switch 1
          Joystick.pressButton(2);
          delay(50);
          Joystick.releaseButton(2);
          break;
        case 7: // Switch 2
          if(currentState == true) {
            Joystick.pressButton(3);
            delay(50);
            Joystick.releaseButton(3);
          }
          else if (currentState == false) {
            Joystick.pressButton(4);
            delay(50);
            Joystick.releaseButton(4);
          }
          break;
        case 8: // Switch 3
          Joystick.pressButton(5);
          delay(50);
          Joystick.releaseButton(5);
          break;
        case 9: // Switch 4
          if(currentState == true) {
            Joystick.pressButton(6);
            delay(50);
            Joystick.releaseButton(6);
          }
          else if (currentState == false) {
            Joystick.pressButton(7);
            delay(50);
            Joystick.releaseButton(7);
          }
          break;
        case 10: //Switch 5
          if(currentState == true) {
            Joystick.pressButton(8);
            delay(50);
            Joystick.releaseButton(8);
          }
          else if (currentState == false) {
            Joystick.pressButton(9);
            delay(50);
            Joystick.releaseButton(9);
          }
          break;
      }
      lastState[index] = currentState;
    }
  }


  delay(10);
}