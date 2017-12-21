/*
  Piezo Test
  Claus Kuehnel 2017-12-19 info@ckuehnel.ch

  Tested w/ NodeMCU
*/
#include "pitches.h"

unsigned int freq;
unsigned long duration;
const int Piezo = D0;

void setup() 
{
  duration = 100;     // ms
  tone(Piezo, NOTE_C8, duration); 
  delay(1.3*duration);   //delay starts same time as tone before
  tone(Piezo, NOTE_C7, 5*duration);
  delay(6*duration);
  tone(Piezo, NOTE_C8, duration);
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
