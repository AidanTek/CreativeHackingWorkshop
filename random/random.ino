#include <Adafruit_NeoPixel.h>

byte pin = 11;
byte totalpixels = 50;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

int delayTime = 100; // Set the delay time to change the speed of the sketch

void setup() {
  pixels.begin();

}

void loop() {
  // Pick some random numbers:
  byte randR = random(127);
  byte randG = random(127);
  byte randB = random(127);
  byte randLED = random(totalpixels);
  
  pixels.setPixelColor(randLED, randR, randG, randB);
  pixels.show();
  delay(delayTime);
}
