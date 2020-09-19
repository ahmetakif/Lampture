#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "kRQIwOmnoQkGj-HQT85bb8JwoaDgz2A5";

char ssid[] = "SUPERONLINE_WiFi_7275";
char pass[] = "xv4uun7Q6xJg";

#include <Servo.h>
Servo lampservo;
const int servopin = 14;

int kapaliaci = 122;
int acikaci = 42;
int varaci = 82;

void setup()
{
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  delay(10);
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
  delay(500);
  lampservo.write(acikaci);
  delay(500);
  lampservo.write(varaci);
  delay(500);
  lampservo.detach();
  delay(500);
}

void closelamp() {
  lampservo.attach(servopin);
  delay(500);
  lampservo.write(kapaliaci);
  delay(500);
  lampservo.write(varaci);
  delay(500);
  lampservo.detach();
  delay(500);
}

//--------------------------------------------------------
//--------------------------------------------------------

BLYNK_WRITE(V1) // For varaci
{
  int pinValue = param.asInt();
  varaci = pinValue;
}
BLYNK_WRITE(V2) // For acikaci
{
  int pinValue = param.asInt();
  acikaci = pinValue;
}
BLYNK_WRITE(V3) // For kapaliaci
{
  int pinValue = param.asInt();
  kapaliaci = pinValue;
}
