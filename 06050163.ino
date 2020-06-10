#include <Ultrasonic.h>
#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"
#define _SSID "AA202_2G"
#define _KEY  "iteaa202"
MCSDevice mcs("DPBGPBBQ", "c6hcfkumNvEPQfGY");
MCSDisplayInteger cm("cm");
Ultrasonic ultrasonic(12, 13);
int distance;
void setup() 
{
  Serial.begin(9600);
  mcs.addChannel(cm);
  while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
 
}
 Serial.println("WiFi connected !!");
  
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");


 
}

void loop() 
{
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  cm.set(distance);
  delay (500);
  
}
