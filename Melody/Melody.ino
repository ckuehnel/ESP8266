/*
  Melody

  Plays a melody 

  circuit:
  - Piezo speaker at pin D0

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone

  adapted to Piezo at NodeMCU (ESP8266)
  Claus Kuehnel 2017-12-19 info@ckuehnel.ch 
*/

#include "pitches.h"

const int Piezo = D0;

// notes in the melody:
int melody[] = 
{
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, REST, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = 
{
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Play melody...");
    
  // iterate over the notes of the melody:
  
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    digitalWrite(LED_BUILTIN, LOW);
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Piezo, melody[thisNote], noteDuration);
    digitalWrite(LED_BUILTIN, HIGH);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Piezo);
  } 
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() 
{
  // no need to repeat the melody.
}
