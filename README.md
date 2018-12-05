# iot-ac-remote
IoT AC Remote using a Wemos D1 Mini and the Blynk app

## Hardware
- Wemos D1 Mini
- IR transmitter with transistor embedded
- Mini USB cable
- Wires

## Software
- Arduino IDE
- Blynk mobile app

## Instructions
1. Create a new app project in Blynk. Copy the auth token from the email they send you and paste it as the value of `auth` in the Arduino sketch.
2. Add 3 push buttons in your Blynk app:
  - Hot (V1 pin)
  - Cold (V2 pin)
  - Off (V0 pin)
3. Configure your WiFi SSID and password in the Arduino sketch
4. Choose the temperatures for Heat and Cold modes.
5. Compile and upload the sketch to the microcontroller
6. Wire your circuit as following:
  - Wemos GND to tranmitter GND
  - Wemos 5V to transmitter VCC
  - Wemos D2 to transmitter DATA
7. Power the circuit. It's ready!

## Limitations
This is a project for my personal use. I have a Mitsubishi Electric AC unit at home so this sketch only works for this maker. It would be easy to adapt it for other brands.

## Dependencies
- IR Remote library https://github.com/markszabo/IRremoteESP8266
- Blynk app and library https://www.blynk.cc/

