#include "LMP91200.h"
#include "SPI.h"


LMP91200::LMP91200(int cs){
	_mask = 0x0000;  //Default settings
	_cs = cs;
}

void LMP91200::begin(){
	//Checked and works. -WP
	SPI.begin();
	SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE3));
	pinMode(_cs, OUTPUT);
	digitalWrite(_cs, HIGH);
}

boolean LMP91200::setPGA(uint16_t PGASet){
	//Checked and works. -WP
	
	//Serial.print("In:  ");
	//Serial.println(_mask, BIN);
	uint16_t shiftedMask = (PGASet << 11);
	_mask &= ~(0b1 << 11); //Clear the bit
	_mask = shiftedMask | _mask;  //Or the cleared initial mask with new
	//Serial.print("Out: ");
	//Serial.println(_mask, BIN);
	//Serial.println();
	return sendPacket(_mask);
}

boolean LMP91200::setVCM(uint16_t VCMSet){
	//Checked and works. -WP

	uint16_t shiftedMask = (VCMSet << 8);
	_mask &= ~(0b111 << 8);  //Clear the bits of interest
	_mask = shiftedMask | _mask;  //Or the cleared initial mask with new
	return sendPacket(_mask);
}

boolean LMP91200::setVOCM(uint16_t VCOMSet){
	//Checked and works. -Wp
	
	// Serial.print("In:  ");
	// Serial.println(_mask, BIN);
	uint16_t shiftedMask = (VCOMSet << 7);
	_mask &= ~(0b1 << 7); //Clear the bit
	_mask = shiftedMask | _mask;  //Or the cleared initial mask with new
	// Serial.print("Out: ");
	// Serial.println(_mask, BIN);
	// Serial.println();
	return sendPacket(_mask);
}

boolean LMP91200::setDIAG(uint16_t DIAGSet){
	//Checked and works. -Wp
	
	// Serial.print("In:  ");
	// Serial.println(_mask, BIN);
	uint16_t shiftedMask = (DIAGSet << 6);
	_mask &= ~(0b1 << 6); //Clear the bit
	_mask = shiftedMask | _mask;  //Or the cleared initial mask with new
	// Serial.print("Out: ");
	// Serial.println(_mask, BIN);
	// Serial.println();
	return sendPacket(_mask);
}

boolean LMP91200::sendPacket(uint16_t bits){
	//Checked and works. -WP
	
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
