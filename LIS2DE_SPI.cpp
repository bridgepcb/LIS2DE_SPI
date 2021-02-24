/*
  LIS2DE_SPI.cpp - Arduino library for the LIS2DE accelerometer / digital motion sensor from STMicroelectronics.
  Created by Leonardo Marquez, September 28, 2020.
  Bridge PCB Design: http://www.bridgepcbdesign.com
*/

#include "LIS2DE_SPI.h"

/*
 * Constructor method
 * Params: 
 *    SS_pin - SPI Chip Select (SS) pin number
 */ 
Lis2de::Lis2de(int SS_pin)
{
  _SS_pin = SS_pin;
}


/*
 * Initializes LIS2DE in SPI mode
 * Params: 
 *    None
 * Returns: 
 *    None
 */ 
void Lis2de::begin(void)
{
  uint8_t s;                  // Variable used to form each setting byte
  pinMode(_SS_pin, OUTPUT);
  SPI.begin();
  
  // TEMP_CFG_REG
  s = settings.TEMP_ENABLE<<6;
  writeByte(TEMP_CFG_REG, s);
  
  // CTRL_REG1
  s = settings.ODR<<4 | settings.LPEN<<3 | settings.ZEN<<2 | settings.YEN<<1 | settings.XEN;
  writeByte(CTRL_REG1, s);
  
  // CTRL_REG2
  s = settings.HPM<<6 | settings.HPCF<<4 | settings.FDS<<3 | settings.HPCLICK<<2 | settings.HPIA2<<1 | settings.HPIA1;
  writeByte(CTRL_REG2, s);
  
  // CTRL_REG3
  s = settings.INT1_CLICK<<7 | settings.INT1_IA1<<6 | settings.INT1_IA2<<5 | settings.INT1_ZYXDA<<4 | settings.INT1_WTM<<2 | settings.INT1_OVERRUN<<1;
  writeByte(CTRL_REG3, s);
  
  // CTRL_REG4
  s = settings.BDU<<7 | settings.FS<<4 | settings.ST<<1 | settings.SIM;
  writeByte(CTRL_REG4, s);
  
  // CTRL_REG5
  s = settings.BOOT<<7 | settings.FIFO_EN<<6 | settings.LIR_INT1<<3 | settings.D4D_INT1<<2 | settings.LIR_INT2<<1 | settings.D4D_INT2;
  writeByte(CTRL_REG5, s);
  
  // CTRL_REG6
  s = settings.INT2_CLICK<<7 | settings.INT2_IA1<<6 | settings.INT2_IA2<<5 | settings.INT2_BOOT<<4 | settings.INT2_ACT<<3 | settings.INT_POLARITY<<1;
  writeByte(CTRL_REG6, s);
}


/*
 * Writes a byte over SPI
 * Params: 
 *    addr - Register address to write
 *    data - data to write on the provided address
 * Returns: 
 *    None
 */ 
void Lis2de::writeByte(uint8_t addr, uint8_t data)
{
  digitalWrite(_SS_pin, LOW);
  SPI.transfer(addr);
  SPI.transfer(data);
  digitalWrite(_SS_pin, HIGH);
}


/*
 * Reads a byte over SPI
 * Params: 
 *    addr - Register address to read
 * Returns: 
 *    Data from register
 */ 
uint8_t Lis2de::readByte(uint8_t addr)
{
  uint8_t resp;                 // Response from LIS2DE    
  uint8_t req;                  // Request byte: MSB=0b10 (read mode, no increment address) followed by address
  req = 0b10<<6 | addr;
  digitalWrite(_SS_pin, LOW);
  SPI.transfer(req);
  resp = SPI.transfer(0);
  digitalWrite(_SS_pin, HIGH);
  return resp;
}


/*
 * Reads value on X-axis
 * Params: 
 *    None
 * Returns: 
 *    Acceleration data from X-axis
 */ 
int8_t Lis2de::readOUT_X(){
    int8_t OUT_X = (int8_t)readByte(OUT_X_H);
    return OUT_X;
}


/*
 * Reads value on Y-axis 
 * Params: 
 *    None
 * Returns: 
 *    Acceleration data from Y-axis
 */ 
int8_t Lis2de::readOUT_Y(){
    int8_t OUT_Y = (int8_t)readByte(OUT_Y_H);
    return OUT_Y;
}


/*
 * Reads value on Z-axis 
 * Params: 
 *    None
 * Returns: 
 *    Acceleration data from Z-axis
 */ 
int8_t Lis2de::readOUT_Z(){
    int8_t OUT_Z = (int8_t)readByte(OUT_Z_H);
    return OUT_Z;
}
