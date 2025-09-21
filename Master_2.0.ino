#include <LoRa.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

byte localAdress = 0x01;

#define PIN  8
#define NUMPIXELS 22
int alerte = 0;
int raspberry = 0;
int bout1 = ;
int bout2 = ;
bool valbout1 = true;
bool valbout2 = true;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);  // Communication started with  9600 baud
    pinMode(bout1, INPUT);
    pinMode(bout2, INPUT);
    while (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    delay(1000);
    
  }
  pixels.begin();
}
void loop() {
  onReceive(LoRa.parsePacket());
  if(digitalRead(bout1)){
    valbout1 =  !valbout1 ;
  }
  if(digitalRead(bout2)){
    valbout2 =  !valbout2 ;
  }
  if(alerte == 2){
    valbout1 = true ;
  }
  if(alerte == 3){
    valbout1 = true ;
    valbout2 = true ;
  }
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

  }
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

    alerte = 3;
    
  }else{
    if(raspberry = 0){
      alerte = 0;
    }else if(raspberry = 1){
      alerte = 1;
    }else if(raspberry = 2){
      alerte = 2;
    }
    
  }
  if (alerte = 0){
    
    if(valbout1){
      pixels.setPixelColor(pixels.Color(0, 150, 0));
      pixels.show(); 
    }else{
      pixels.clear();
    }
    
  } else if(alerte = 1){
    
    if(valbout1){
      pixels.setPixelColor(pixels.Color(130, 64, 0));
      pixels.show(); 
    }else{
      pixels.clear();
    }
      
  }else if(alerte = 2){
      
  }else if(alerte = 3){
      
  }

