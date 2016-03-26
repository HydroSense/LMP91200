# LMP91200
The official HydroSense library for the TI LMP91200 PH frontend.
Updated: March 26, 2016 7:37 PM
By: Ward Prescott

## Class
###Constructor
`LMP91200(int cs)` The only argument is the chipselect pin for the device.

### Methods
- `.begin(void)` is used start the SPI bus with the correct settings.  Note that the LMP91200 uses SPI mode 3, though most other TI devices use SPI mode 1.

- `.setPGA(int PGASet)` is used to set the programmable gain amplifier internal to the AFE.  Arguments are:

| Argument | Description |
|--------|--------|
|      PGA5 |  5 Volts/Volt (DEFAULT)      |
|PGA10 | 10 Volts/Volt|

- `.setVCM(int VCOMSet)` is used to set the reference voltage offset.  This setting can be changed if the PH range is within known values that are skewed to acidic or basic.  Arguments are:


| Argument | Description |
|--------|--------|
|     VCM_78  |  Common mode voltage at 7/8 Vcc   |
|     VCM_34  |  Common mode voltage at 3/4 Vcc   |
|     VCM_58  |  Common mode voltage at 5/8 Vcc   |
|     VCM_12  |  Common mode voltage at 1/2 Vcc (DEFAULT)   |
|     VCM_38  |  Common mode voltage at 3/8 Vcc   |
|     VCM_14  |  Common mode voltage at 1/4 Vcc   |
|     VCM_18  |  Common mode voltage at 1/8 Vcc   |


- `.setVOCM(int VOCMSet)` is used to select between differential or singled ened output.  Arguments are:

| Argument | Description |
|--------|--------|
|      VOCM_VOCM  |  Differential output (DEFAULT)      |
|VOCM_GND | Singled ended output |
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
