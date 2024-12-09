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
  7, 0,                  // Button Count, Hat Switch Count
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
int lastState[11] = {0,0,0,0,0,0,0,0,0,0,0};

//Pin definition
int Pins[11] = {DOWN,UP,RIGHT,LEFT,BUTTONO,BUTTONR,SW1,SW2,SW3,SW4,SW5};

void loop() {

  // Read Button values
  for (int index = 0; index < 11; index++) {
    int currentState = digitalRead(Pins[index]);
    if (currentState != lastState[index]) {
      switch (index) {
        case 0: // UP
          if (currentState == 1) {
            Joystick.setYAxis(-1);
            //Serial.println("UP");
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 1: // DOWN
          if (currentState == 1) {
            Joystick.setXAxis(1);
            //Serial.println("DOWN");
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 2: // RIGHT
          if (currentState == 1) {
            Joystick.setYAxis(1);
            //Serial.println("RIGHT");
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 3: // LEFT
          if (currentState == 1) {
            Joystick.setXAxis(-1);
            //Serial.println("LEFT");
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 4: // FIRE
          Joystick.setButton(BUTTONO, currentState);
          //Serial.println("Fire Button");
          break;
        case 5: // Back Button
          Joystick.setButton(BUTTONR, currentState);
          //Serial.println("Back Button");
          break;
        case 6: // Switch 1
          Joystick.setButton(SW1, 1);
          delay(1);
          Joystick.setButton(SW1, 0);
          //Serial.println("Switch 1");
          break;
        case 7: // Switch 2
          Joystick.setButton(SW2, 1);
          delay(1);
          Joystick.setButton(SW2, 0);
          //Serial.println("Switch 2");
          break;
        case 8: // Switch 3
          Joystick.setButton(SW3, 1);
          delay(1);
          Joystick.setButton(SW3, 0);
          //Serial.println("Switch 3");
          break;
        case 9: // Switch 4
          Joystick.setButton(SW4, 1);
          delay(1);
          Joystick.setButton(SW4, 0);
          //Serial.println("Switch 4");
          break;
        case 10: //Switch 5
          Joystick.setButton(SW5, 1);
          delay(1);
          Joystick.setButton(SW5, 0);
          //Serial.println("Switch 5");
          break;
  
      }
      lastState[index] = currentState;
    }
  }


  delay(10);
}