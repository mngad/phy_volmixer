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
#include "HID-Project.h"
// Setup a RoraryEncoder for pins A2 and A3:
RotaryEncoder encoder(5, 6);
int buttonState = 0;
const int buttonPin = 7;
const int buttonPin2 = 16;
void setup()
{

  encoder.setPosition(1);
  pinMode(buttonPin, INPUT_PULLUP);
  //Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  //delay(10);
  static int pos = 1;
  
  encoder.tick();

  int newPos = encoder.getPosition();

  
  if (pos != newPos) {

    if(pos > newPos){
      Consumer.write(MEDIA_VOLUME_UP);
    }
     if(pos < newPos){
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
    pos = newPos;
    
  } 
  if (!digitalRead(buttonPin)) {
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(300);

  }
    if (digitalRead(buttonPin2)==HIGH) {
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(300);

  }
 

  
} // loop ()

// The End
