#include <Adafruit_NeoPixel.h>

byte pin = 11;
byte totalpixels = 50;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

int delayTime = 500; // Set the delay time to change the speed of the sketch
int counter = 0; // A counter to sequence the lights

void setup() {
  pixels.begin();

}

void loop() {
  pixels.setPixelColor(counter, 255, 0, 0);
  pixels.show();
  delay(delayTime);

  counter++; // Add 1 to counter

  // Reset the counter when it gets to the end
  if(counter >= totalpixels) {
    counter = 0;
  }
}
