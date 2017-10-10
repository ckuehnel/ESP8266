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

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  WARNING :
  For this example you'll need Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App project setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
    LED widget attached to V1
    Button widget attached to GP3
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "Your password";

#define DHTPIN 2          // What digital pin we're connected to
#define BUTTONPIN 3

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
WidgetLED led1(V1);

// We make these values volatile, as they are used in interrupt context
volatile bool pinChanged = false;
volatile int  pinValue   = 0;

boolean flag;

// Most boards won't send data to WiFi out of interrupt handler.
// We just store the value and process it in the main loop.
void checkPin()
{
  // Invert state, since button is "Active LOW"
  pinValue = !digitalRead(BUTTONPIN);

  // Mark pin value changed
  pinChanged = true;
}

// This function sends temperature and humidity every second to V6 and V5.
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  String str;
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  float f = dht.readTemperature(true); // for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // for debugging
  Serial.print(" T = ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.print(" H = ");
  Serial.print(h);
  Serial.println(" %");
  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.

  // Send it to the server
  if (flag) str = String(t, 1) + " ℃"; // Format: 1 decimal place, add ℃
  else      str = String(f, 1) + " °F"; // Format: 1 decimal place, add °F
  Blynk.virtualWrite(V6, str);

  str = String(h, 0) + " %";
  Blynk.virtualWrite(V5, str); 

  led1.on();
  delay(10);
  led1.off();
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  // Make pin BUTTONPIN HIGH by default
  pinMode(BUTTONPIN, INPUT_PULLUP);
  // Attach INT to our handler
  attachInterrupt(digitalPinToInterrupt(BUTTONPIN), checkPin, CHANGE);
}

void loop()
{
  Blynk.run();
  timer.run();
  if (pinChanged) 
  {
    // Process the value
    if (pinValue) flag = true;
    else flag = false;
    
    // Clear the mark, as we have processed the value
    pinChanged = false;
  }
}

