/*
  TimeBase on ESP8266 
  (c) Claus Kuehnel 2017-10-12 info@ckuehnel.ch
    
  The Ticker object is used to call the function sec
  with one second period. The built-in LED will be blinking.

  Tested w/ Ledunia.
*/

#include <Ticker.h>

Ticker ticker;

const int TICK = 50;      // On time for LED in msec
const int PERIOD = 1000;  // Ticker period in msec

unsigned long time1;
unsigned long time2;
 
void sec()
{
  unsigned int second;
  float dev;
  
  time2 = micros();
  second = time2 - time1;
  time1 = time2;
  Serial.print(second);
  Serial.print("\t");
  dev = (second/1000.0 - PERIOD)/PERIOD;
  dev = dev *1000000;
  if (dev >= 0) Serial.print("+");
  Serial.print(dev);
  Serial.println(" ppm");
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TICK);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  ticker.attach_ms(PERIOD, sec);
  Serial.begin(115200);
}

void loop() 
{
  // application code
}
