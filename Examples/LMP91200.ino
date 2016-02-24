#include <SPI.h>

#define CS_LMP91200 A4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
 SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
  //SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
  pinMode(CS_LMP91200, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
    digitalWrite(A5, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  Serial.println("here");

}

void loop() {
  // put your main code here, to run repeatedly:
LMP91200_init(A4);
delay(500);
}

bool LMP91200_init(int cs){
uint16_t dataIn = 0xA080;
//Check for connection by sending default config and checking that it return corretly
digitalWrite(CS_LMP91200, LOW);
//digitalWrite(A4, LOW);
SPI.transfer16(dataIn);
uint16_t recievedVal = SPI.transfer16(dataIn);

//digitalWrite(A4, HIGH);
digitalWrite(CS_LMP91200, HIGH);

Serial.print("Out: ");
Serial.println(recievedVal, HEX);
Serial.println();
}

void LMP91200_setPGA(){
  
}

void LMP91200_setVCM(){
  
}

void LMP91200_setVOCM(){
  
}

void LMP91200_setDIAG(){
  
}


