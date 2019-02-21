#include <Adafruit_NeoPixel.h>

byte pin = 11;
byte totalpixels = 50;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(totalpixels, pin, NEO_RGB + NEO_KHZ800);

int delayTime = 10; // Set the delay time to change the speed of the sketch

void setup() {
  pixels.begin();

}

void loop() {
  // Pay attention to the curly brackets {}
  // This indicates where a loop starts and ends:
  
  for(byte f = 0; f < 255; f++) {
    for(byte x = 0; x < totalpixels; x++) {
      pixels.setPixelColor(x, 0, 0, f); // use "x" and "f" to preset a pixel
    }
    pixels.show(); // light it up!
    delay(delayTime); // wait for some time
  }
  
  for(byte x = 0; x < totalpixels; x++) {
    // Let's use a loop to switch the leds off
    pixels.setPixelColor(x, 0, 0, 0); // preset led "x" to be off
  }
  pixels.show(); // light it up!
  delay(100); // wait for some time 
}
