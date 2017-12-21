/*
  ESP8266 Test
  (c) Claus Kuehnel 2017-10-12 info@ckuehnel.ch
*/

// Uncomment your board
#define ESP12E_LED 2     // for ESP-12E Module
#define ESP8266_LED 5     // for Ledunia
#define NodeMCU_LED D0    // for NodeMCU

#define LED ESP12E_LED   // adapt it

ADC_MODE(ADC_VCC);

byte count = 0;

void setup() 
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(1000); // waiting to start the monitor
  Serial.print("Hi there, here is "); 
  Serial.println("ESP-12E Module");     // for ESP-12E Module
//  Serial.println("Ledunia");            // for Ledunia
//  Serial.println("NodeMCU");            // for NodeMCU
  Serial.print("ESP8266 Reset Reason ");
  Serial.println(ESP.getResetReason());
  Serial.print("ESP8266 Core Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("ESP8266 Chip ID: ");
  Serial.println(ESP.getChipId());
  Serial.print("Flash Chip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("Flash available [KB]: ");
  Serial.println(ESP.getFlashChipSize()/1024);
  Serial.print("Flash Chip Size [KB]: ");
  Serial.println(ESP.getFlashChipRealSize()/1024);
  Serial.print("Flash frequency [MHz]: ");
  Serial.println(ESP.getFlashChipSpeed()/1000000);
  Serial.print("Free Heap [KB]: ");
  Serial.println(ESP.getFreeHeap()/1024);
  Serial.print("VCC [mV]: ");
  Serial.println(ESP.getVcc());
}

void loop() 
{

  Serial.print(".");
  count++;
  if (count == 25)
  {
    Serial.println();
    count=0;
  }
  digitalWrite(LED, HIGH);
  delay(980);
  digitalWrite(LED, LOW);
  delay(20);
}
