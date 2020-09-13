#include <RotaryEncoder.h>
#include "HID-Project.h"

RotaryEncoder encoder(5, 6);// Setup a RoraryEncoder for pins 5 and 6:
int buttonState = 0;
const int buttonPin = 7; //rotenc clicker
const int buttonPin2 = 16; //playpause
const int buttonPin3 = 14; //skip
const int buttonPin4 = 15; //back
void setup()
{

  encoder.setPosition(1);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

} 


void loop()
{

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
 if (digitalRead(buttonPin3)==HIGH) {
    Consumer.write(MEDIA_NEXT);
    delay(300);

  }
//   if (digitalRead(buttonPin4)==HIGH) {
//    Consumer.write(MEDIA_PREVIOUS);
//    delay(300);

//  } 

  
}
