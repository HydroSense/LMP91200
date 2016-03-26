#include <SPI.h>
#include <LMP91200.h>

LMP91200 myLMP(A4);

void setup() {
  myLMP.begin();
  delay(50);
  myLMP.setVCM(VCM_78);
  myLMP.setPGA(PGA_5);
  myLMP.setVOCM(VOCM_VOCM);


}

void loop() {
  // put your main code here, to run repeatedly:

delay(500);

}