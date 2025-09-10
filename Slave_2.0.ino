#include <LoRa.h>

byte central = 0x01;
byte localAdress = 0x02;

void setup() {
  Serial.begin(9600);  // Communication started with  9600 baud

    while (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    delay(1000);
  }
}
void loop() {
  int sensor = analogRead(A0);  // Incoming analog  signal read and appointed sensor
  Serial.println(sensor);       //Wrote serial port

  if (sensor > 150) {
    Serial.println("Innodation");

    LoRa.beginPacket();
    LoRa.write(central);
    LoRa.write(localAdress);
    LoRa.write(0xAA);
    
    delay(1000);
  }

  else {
    Serial.println("Normal");
    delay(1000);
  }
}