#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = "your-ssid";
const char *password = "your-password";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}
