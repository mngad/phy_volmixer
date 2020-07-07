#include <RotaryEncoder.h>
#include "HID-Project.h"

RotaryEncoder encoder(5, 6);// Setup a RoraryEncoder for pins 5 and 6:
int buttonState = 0;
const int buttonPin = 7; //rotenc clicker
const int buttonPin2 = 16; //playpause

void setup()
{

  encoder.setPosition(1);
  pinMode(buttonPin, INPUT_PULLUP);

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
 

  
}
