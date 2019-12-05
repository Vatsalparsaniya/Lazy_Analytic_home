#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "95rkZlkSMucQ0Oo53_ctuFwWI9I57Od8"; // the auth code that you got on your gmail
char ssid[] = "vatsal__1"; // username or ssid of your WI-FI  a Lannister always surfs the net
char pass[] = "qwertyuiop"; // password of your Wi-Fi  sakuranohana2110

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
