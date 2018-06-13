#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "Android50";
char _lwifi_pass[] = "12345678";
MCSDevice mcs("DaMvLhnh", "tauidCWcirhDhoXX");

MCSControllerOnOff led("LED_control");

void setup()
{
  Serial.begin(9600);

  Serial.println("Connect to Wifi");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) {
    Serial.println("Wifi Reconnecting..");
    delay(1000);
  }

  Serial.println("Connect to MCS...");
  while (!mcs.connected()) {
    Serial.println("MCS Reconnecting..");
    mcs.connect();
  }
  Serial.println("MCS Connected!");
  mcs.addChannel(led);

  pinMode(7, OUTPUT);

}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) {
      Serial.println("MCS Reconnect");
    }
  }
  mcs.process(1000);

  if (led.value() == 1) {
    digitalWrite(7, HIGH);

  } else {
    digitalWrite(7, LOW);

  }

  delay(200);
}
