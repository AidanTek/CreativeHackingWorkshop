#include <Adafruit_NeoPixel.h>

byte pin = 11; // The DATA pin connected on the Arduino
byte totalpixels = 50; // How many lights are in your strip?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();

}

void loop() {
  pixels.setPixelColor(0, 255, 0, 0); // Pick led 0, preset it to red
  pixels.show(); // Light it up!
}
