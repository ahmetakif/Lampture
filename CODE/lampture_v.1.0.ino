#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "AuthKey";

char ssid[] = "wifiismi";
char pass[] = "sifre";

#include <Servo.h>
Servo lampservo;
const int servopin = 14;

int kapaliaci = 120;
int acikaci = 80;
int varaci = 100;

void setup()
{
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if (pinValue == 0) {
    openlamp();
  }
  else if (pinValue == 2) {
    closelamp();
  }
}

void openlamp() {
  lampservo.attach(servopin);
  lampservo.write(acikaci);
  delay(500);
  lampservo.write(varaci);
  lampservo.detach();
}

void closelamp() {
  lampservo.attach(servopin);
  lampservo.write(kapaliaci);
  delay(500);
  lampservo.write(varaci);
  lampservo.detach();
}
