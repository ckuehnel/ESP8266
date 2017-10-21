/*
    EEPROM (emulated by ESP8266 Flash) 
    (c) Claus Kuehnel 2017-10-12 info@ckuehnel.ch

    Comment not used functions in loop().
 */

#include <EEPROM.h>

#define SIZE 128

void cleanEEPROM()
{
  Serial.println(F("Erase EEPROM..."));
  // write a 0 to all 512 bytes of the EEPROM
  for (int i = 0; i < SIZE; i++)
    EEPROM.write(i, 0);
  EEPROM.commit();  // copy RAM content to flash
}

void readEEPROM()
{
  Serial.println(F("Read EEPROM..."));
  for (int address = 0; address < SIZE; address = address+16)
  {
    printf( "%4X:  ", address);
    //Serial.print("\t");

    for (int i=0; i < 16; i++)
    {
      int value = EEPROM.read(address+i);
      printf( "%2X  ", value );
      //Serial.print("\t");
    }
    Serial.println();
  }
}

void writeEEPROM()
{
  Serial.println(F("Write EEPROM..."));
  // write a number to all bytes of the EEPROM
  for (int i = 0; i < SIZE; i++)
    EEPROM.write(i, i);
  EEPROM.commit();  // copy RAM content to flash
}

void setup()
{
  Serial.begin(115200);
  delay(4000);     // to switch on internal monitor
  Serial.println(F("EEPROM actions:"));
  
  EEPROM.begin(SIZE);

//  cleanEEPROM();
  readEEPROM();
//  writeEEPROM();
//  readEEPROM();

  EEPROM.end();
}

void loop()
{

}
