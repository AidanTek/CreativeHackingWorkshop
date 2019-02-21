#include <Adafruit_NeoPixel.h>

byte pin = 11; // The DATA pin connected on the Arduino
byte totalpixels = 50; byte totalpixels = 50; // How many lights are in your strip?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

int delayTime = 500; // Set the delay time to change the speed of the sketch

void setup() {
  pixels.begin();

}

void loop() {
  pixels.setPixelColor(0, 255, 0, 0); // Pick led 0, preset it to be red
  pixels.show(); // light up any changes!
  delay(delayTime); // wait for some time in milliseconds
  
  pixels.setPixelColor(0, 0, 0, 0); // Pick led 0, preset it to be off
  pixels.setPixelColor(1, 0, 255, 0); // Pick led 1, preset it to be green
  pixels.show();
  delay(delayTime);
  
  pixels.setPixelColor(1, 0, 0, 0); // Pick led 1, preset it to be off
  pixels.setPixelColor(2, 0, 0, 255); // Pick led 2, preset it to be blue
  pixels.show();
  delay(delayTime);
  
  pixels.setPixelColor(2, 0, 0, 0); // Pick led 2, preset it to be off
  pixels.setPixelColor(3, 255, 255, 255); // Pick led 3, preset it to be white
  pixels.show();
  delay(delayTime);
  
  pixels.setPixelColor(3, 0, 0, 0); // Pick led 3, preset it to be off
}
