#include <Adafruit_NeoPixel.h>

byte pin = 11; 
byte totalpixels = 50;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

int delayTime = 500; // Set the delay time to change the speed of the sketch

void setup() {
  pixels.begin();

}

void loop() {
  for(byte x = 0; x < totalpixels; x++) {
    // The for loop will loop as many times as "totalpixels"
    // Each time it loops, the value x has 1 added to it
    pixels.setPixelColor(x, 0, 0, 255); // preset led "x" to be blue
    pixels.show(); // light it up!
    delay(100); // wait for 100 ms
  }
  for(byte x = 0; x < totalpixels; x++) {
    // Let's use a loop to switch the leds off
    pixels.setPixelColor(x, 0, 0, 0); // preset led "x" to be off
  }
  pixels.show(); // light it up!
  delay(100); // wait for 100 ms
}
