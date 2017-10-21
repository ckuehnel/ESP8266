/*
  Heartbeat on ESP8266 
  
  The Ticker object is used to call the function heartbeat
  with a defined period and on-time. The built-in LED will be blinking.
  
  You can have as many Tickers as you like, memory being the only limitation.
  Each Ticker calls one function. 
  
  A function may be attached to a ticker and detached from the ticker.
  There are two variants of the attach function: attach and attach_ms.
  The first one takes period in seconds, the second one in milliseconds.
*/

#include <Ticker.h>

Ticker ticker;

const int TICK = 50;      // On time for LED in msec
const int PERIOD = 1500;  // Period for blinking LED in msec

void heartbeat()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TICK);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  ticker.attach_ms(PERIOD, heartbeat);
}

void loop() 
{
  // application code
}
