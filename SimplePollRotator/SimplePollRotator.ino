// -----
// SimplePollRotator.ino - Example for the RotaryEncoder library.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// 18.01.2014 created by Matthias Hertel
// -----

// This example checks the state of the rotary encoder in the loop() function.
// The current position is printed on output when changed.

// Hardware setup:
// Attach a rotary encoder with output pins to A2 and A3.
// The common contact should be attached to ground.

#include <RotaryEncoder.h>

// Setup a RoraryEncoder for pins A2 and A3:
RotaryEncoder encoder(A2, A3);
int buttonState = 0;
const int buttonPin = 5;
void setup()
{
  Serial.begin(57600);
  encoder.setPosition(1);
pinMode(buttonPin, INPUT);
  //Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  //delay(10);
  static int pos = 1;
  ;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (newPos > 100) {
    newPos = 100;
    encoder.setPosition(100);
  }
   

  if (newPos < 0) {
    newPos = 0;
    encoder.setPosition(0);
  }


  
  if (pos != newPos) {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
    
  } 
if (buttonState == HIGH) {
    Serial.print("MUTE");
    Serial.println();
  }
 

  
} // loop ()

// The End
