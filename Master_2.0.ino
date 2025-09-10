#include <LoRa.h>

byte localAdress = 0x01;

void setup() {
  Serial.begin(9600);  // Communication started with  9600 baud

    while (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    delay(1000);
  }
}
void loop() {
  onReceive(LoRa.parsePacket());
}

void onReceive(int packetSize) {
  if (packetSize == 0) return;  // if there's no packet, return

  int recipient = LoRa.read();
  int sender = LoRa.read();
  byte code = LoRa.read();

  
  Serial.print("message to ");
  Serial.print(recipient);
  Serial.print(" from ");
  Serial.print(sender);

  if (recipient != localAddress) {
    Serial.println(": This message is not for me.");
    return;  // skip rest of function
  }

  Serial.print(" : '");
  Serial.print(incoming);
  Serial.print("' || RSSI: ");
  Serial.println(LoRa.packetRssi());
  Serial.println();

  reponse(code);
}

void reponse(byte code){

  if (code == 0xAA){

    //Code Alarme
  }

}

