/*

AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)

*/


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(21, 22); // SoftwareSerial Object BTSerial(RX, TX)

void setup() 
{
  pinMode(23, OUTPUT);  //this pin will pull the HC-05 pin 34 (KEY Pin) HIGH to switch module to AT mode
  digitalWrite(23, HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command mode
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}


