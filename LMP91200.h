#ifndef LMP91200_h
#define LMP91200_h

#include "Arduino.h"

#define PGA_5 0 //Set the PGA at 5Volts/Volt
#define PGA_10 1  //Set the PGA at 10 Volts/Volt

#define VCM_78 0b011
#define VCM_34 0b010
#define VCM_58 0b001
#define VCM_12 0b000
#define VCM_38 0b101
#define VCM_14 0b110
#define VCM_18 0b111

#define VOCM_VOCM 0
#define VOCM_GND 1

#define DIAG_EN 1
#define DIAG_OFF 0

class LMP91200
{
public:
	LMP91200(int cs);
	void begin();
	boolean setPGA(uint16_t PGASet);
	boolean setVCM(uint16_t VCMSet);
	boolean setVOCM(uint16_t VCOMSet);
	boolean setDIAG(uint16_t DIAGSet);
private:
	int _cs;
	uint16_t _mask;
	boolean sendPacket(uint16_t bits);
};

#endif