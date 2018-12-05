#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Mitsubishi.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRMitsubishiAC ac(kIrLed);  // Set the GPIO used for sending messages.

const uint16_t HEAT_TEMP = 20;
const uint16_t COLD_TEMP = 26;

// Turn off the AC
BLYNK_WRITE(V0) {
  ac.off();
  ac.send();
}

// Turn on the AC on heat mode
BLYNK_WRITE(V1) {
  ac.on();
  ac.setMode(kMitsubishiAcHeat);
  ac.setTemp(HEAT_TEMP);
  ac.send();
}

// Turn on the AC on cold mode
BLYNK_WRITE(V2) {
  ac.on();
  ac.setMode(kMitsubishiAcCool);
  ac.setTemp(COLD_TEMP);
  ac.send();
}

void setup() {
  Blynk.begin(auth, ssid, pass);
  ac.begin();

  // Base settings that does not change
  ac.setFan(1);
  ac.setVane(kMitsubishiAcVaneAuto);
}

void loop() {
  Blynk.run();
}
