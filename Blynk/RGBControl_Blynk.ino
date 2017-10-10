/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  Control color and brightness on Ledunia's RGB-LEDs using sliders

  For this example you need FastLED library:
    https://github.com/FastLED/FastLED
  
  App project setup:
    Slider widget (0...255) on V1
	Slider widget (0...255) on V2
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <FastLED.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "Your password";

// default for Ledunia
#define NUM_LEDS 4
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

int shift, dim;

BLYNK_WRITE(V1)
{
  shift = param.asInt();
}

BLYNK_WRITE(V2)
{
  dim = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  Serial.println("Ledunia RGB LED Control");

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  for (int i = 0; i < NUM_LEDS; i++) leds[i].setHue(shift);
  for (int i = 0; i < NUM_LEDS; i++) leds[i].nscale8(dim);
  FastLED.show();
  Serial.print("Hue:"); Serial.println(shift);
  Serial.print("Brightness: "); Serial.println(dim);
  delay(500);
}

