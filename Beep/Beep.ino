/*
  Beep

  Creating beep tones for signalization purposes 

  circuit:
  - Piezo speaker at pin D0

  Claus Kuehnel 2017-12-19 info@ckuehnel.ch 
*/

#include "pitches.h"

const int Piezo = D0;
const unsigned int LoMax = 3000;
const unsigned int LocMin = 3500;
const unsigned int HiMax = 4200;

// Generation of beep tone
void beep(unsigned int pitch, unsigned long duration)
{
    digitalWrite(LED_BUILTIN, LOW);
    tone(Piezo, pitch, duration);
    delay(1.3 * duration);
    digitalWrite(LED_BUILTIN, HIGH);
}

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Play different beep tones...");
}

void loop() 
{
  Serial.println("Pitch a'");
  beep(NOTE_A4, 1000);
  Serial.println("Short Melody");
  beep(NOTE_C5, 1000);
  beep(NOTE_E5, 1000);
  beep(NOTE_G5, 1000);
  beep(NOTE_C6, 1000);
  Serial.println("Piezo frequency response");
  Serial.println("       /\ ");
  Serial.println("  /\  /  \ ");
  Serial.println(" /  --    \ ");
  Serial.println("/          \ ");
  Serial.println("Low Max = ");
  beep(LoMax, 1000);
  Serial.println("Local Min = ");
  beep(LocMin, 1000);
  Serial.println("High Max = ");
  beep(HiMax, 1000);  
  delay(2000);
}
