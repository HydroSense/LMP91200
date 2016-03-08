# LMP91200
The official HydroSense library for the TI LMP91200 PH frontend.
Updated: Mar 8, 2016 11:24 AM
By: Ward Prescott

## Class
###Constructor

### Methods
.begin()
.setPGA()
.setVCM()
.setVOCM()
### Parameters
The class has no public parameters.
##Usage
```
#include <LMP91200.h>
LMP91200 myLMP(A4);

void setup(){
 myLMP.begin();
 delay(50);
 myLMP.setVCM(0b000);
 myLMP.setPGA(0b0);
 
}

void loop(){
//Read the LMP via an ADC
}

```
The device works via an SPI bus, so it is imperative that all chip select pins are set to high for other SPI peripherals.

##Notes
The LMP91200 is not reccomened for new designs and a suitable replacement is currently being researched.

##Further Work
The PGA does not appear to be working on the LMP91200 but further investigation is needed to confirm this.
