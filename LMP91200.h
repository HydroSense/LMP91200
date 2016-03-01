#ifndef LMP91200_h
#define LMP91200_h

#include "Arduino.h"

#define PGA_5 0; //Set the PGA at 5Volts/Volt
#define PGA_10 1;  //Set the PGA at 10 Volts/Volt

//VCM Masking

#define VOCM_VOCM 
#define VOCM_GND

#define DIAG_EN 
#define DIAG_OFF

class LMP91200
{
public:
	LMP91200(int cs);
	void begin();
	boolean setPGA(uint16_t PGASet);
	boolean setVCM(uint16_t VCMSet);
	boolean setVCOM(uint16_t VCOMSet);
	boolean setDIAG(uint16_t DIAGSet);
private:
	int _cs;
	uint16_t _mask;
	boolean sendPacket(uint16_t bits);
};

#endif