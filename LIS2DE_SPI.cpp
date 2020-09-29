/*
  LIS2DE_SPI.c - Arduino library for the LIS2DE accelerometer / digital motion sensor from STMicroelectronics.
  Created by Leonardo Marquez, September 28, 2020.
  Bridge PCB Design: http://www.bridgepcbdesign.com
*/

#include "LIS2DE_SPI.h"
#include "SPI.h"

/*
 * Constructor method
 * Params: 
 * SS_pin - SPI Chip Select (SS) pin number
 */ 
Lis2de::Lis2de(int SS_pin)
{
  _SS_pin = SS_pin;
}


/*
 * Initialized LIS2DE in SPI mode
 * Params: 
 *    None
 * Returns: 
 *    None
 */ 
void Lis2de::begin(void)
{
  
}  

/*
 * Writes a byte over SPI
 * Params: 
 *    addr - Register address to write
 *    data - data to write on the provided address
 * Returns: 
 *    None
 */ 
void Lis2de::write_byte(uint8_t addr, uint8_t data)
{
  digitalWrite(_SS_pin, LOW);
  SPI.transfer(addr);
  SPI.transfer(data);
  digitalWrite(_SS_pin, HIGH);
}