# Creative Hardware Hacking 
## An Introduction to Arduino Programming with Addressable LEDs 
### Aidan Taylor - Finding Maindee 2019

---

This document is meant as a supporting guide to the Creative Hardware Hacking Workshop. You can find this document, and all of the examples for this workshop in this GitHub repository: 

To continue this workshop at home, I recommend the following items:

* An Arduino Uno and a USB cable
* A small breadboard
* A string or strip of Neopixel LEDs (WS2812 or WS2811 LEDs)
* A 5V power supply - one that can provide at least 1.5A is a good idea
* A set of breadboard jumper wires

---

#### Setting Up

You need the Arduino IDE installed, and the Neopixel Library provided by Adafruit

* The Arduino IDE is free, open-source software and can be installed from the Arduino website:
	* https://www.arduino.cc/en/Main/Software
* The Neopixel Library can be installed from inside the Arduino IDE
	* Open the Arduino IDE
	* Navigate to the **Sketch** menu and hover over **Include Library...** and choose the top option: **Manage Libraries...**
	* In the dialogue box that opens up, type in **"Neopixel"** as the search criteria
	* Select the box that says **Adafruit Neopixel** and choose **Install** - be careful not to pick the wrong library as a couple are named similarly
	
---	
	
#### Plugging In

For this workshop, we do not need to change the electronics setup once it is plugged in - this is probably the trickiest thing we will do today! Take your time with this step and I will help you get started. 

* First, examine the LED string and find the end that has the female connector - this end is the INPUT
* Take 3 jumper wires and connect them to the 3 sockets of the female LED connector, notice the wires that connect to the LEDs:
	* **Red** indicates +5 Volts
	* **White** indicates DATA
	* **Green** indicates Ground (or 0 Volts)
* Connect the +5 Volts to an outer row on the breadboard
* Connect Ground to an inner row
* Connect DATA to a digital pin on the Arduino Uno - I use pin 11
* Now, before you plug it in to a socket, connect the power supply to the breadboard. On the power supplies provided for the workshop, the wire with the dotted line is +5 Volts and the other wire is Ground, these will correspond to the wires on the LEDs, so connect them to the same rows on the breadboard.
* One more wire is needed, connect the Ground row on the breadboard to a Ground (GND) pin on the Arduino.

That's it, everything is connected! Once I have inspected your setup, you can plug in to a socket to power the LEDs

---

#### How to light up an LED

This example sketch can be found in the "basic_light" file in the repository - or you can type it as below:

```cpp
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
```


#### Make a pattern with a sequence

This example sketch can be found in the "basic_sequence" file in the repository - or you can type it as below:

```cpp
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
```

#### Using a Variable

This example sketch can be found in the "basic_variables" file in the repository - or you can type it as below:

```cpp
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
  pixels.setPixelColor(counter, 255, 0, 0); // set a pixel to red
  pixels.show(); // light it up!
  delay(delayTime);

  counter++; // Add 1 to counter

  // Reset the counter when it gets to the end
  if(counter >= totalpixels) {
    counter = 0;
  }
}
```


#### Using Random

This example sketch can be found in the "random" file in the repository - or you can type it as below:

```cpp
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
```

#### For Loop

This example sketch can be found in the "for_loop" file in the repository - or you can type it as below:

```cpp
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
```

#### Fade

This example sketch can be found in the "for_loop_fade" file in the repository - or you can type it as below:

```cpp
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
```

#### Modulo
	
This example sketch can be found in the "modulo" file in the repository - or you can type it as below:

```cpp
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
      if(x % 2) {
        pixels.setPixelColor(x, 0, 0, f); // use "x" and "f" to preset a pixel
      }
      else {
        pixels.setPixelColor(x, f, 0, 0); // use "x" and "f" to preset a pixel
      }
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
```

