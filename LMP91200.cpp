#include "LMP91200.h"
#include "SPI.h"


LMP91200::LMP91200(int cs){
	_mask = 0000000000000000;
	_cs = cs;
}

void LMP91200::begin(){
	SPI.begin();
	SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE3));
	pinMode(_cs, OUTPUT);
}

boolean LMP91200::setPGA(uint16_t PGASet){
	_mask |= (PGASet << 11); //Set the bit
	_mask &= ~(PGASet << 11); //Clear the bit
	Serial.println(_mask, BIN);
	return sendPacket(_mask);
}

boolean LMP91200::setVCM(uint16_t VCMSet){
	return true;

}

boolean LMP91200::setVCOM(uint16_t VCOMSet){
	return true;
}

boolean LMP91200::setDIAG(uint16_t DIAGSet){
	return true;
}

boolean LMP91200::sendPacket(uint16_t bits){
	digitalWrite(_cs, LOW);
	SPI.transfer16(bits);
	uint16_t returnedVal = SPI.transfer16(bits);
	digitalWrite(_cs, HIGH);

	if (returnedVal == bits){
		return true; //Transaction sucessful
	}
	else{
		return false; // Didn't match up
	}
}
