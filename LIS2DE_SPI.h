/*
  LIS2DE_SPI.h - Arduino library for the LIS2DE accelerometer / digital motion sensor from STMicroelectronics.
  Created by Leonardo Marquez, September 28, 2020.
  Bridge PCB Design: http://www.bridgepcbdesign.com
*/

#ifndef LIS2DE_H
#define LIS2DE_H

#include <Arduino.h>
#include <SPI.h>

// Register mapping:
#define STATUS_REG_AUX    0x07
#define OUT_TEMP_L        0x0C
#define OUT_TEMP_H        0x0D
#define WHO_AM_I          0x0F
#define CTRL_REG0         0x1E
#define TEMP_CFG_REG      0x1F
#define CTRL_REG1         0x20
#define CTRL_REG2         0x21
#define CTRL_REG3         0x22
#define CTRL_REG4         0x23
#define CTRL_REG5         0x24
#define CTRL_REG6         0x25
#define REFERENCE         0x26
#define STATUS_REG        0x27
#define FIFO_READ_START   0x28
#define OUT_X_H           0x29
#define OUT_Y_H           0x2B
#define OUT_Z_H           0x2D


// Temperature settings:
#define TEMP_ENABLED      0x11
#define TEMP_DISABLED     0x00

// ODR Settings;
#define POWER_DOWN        0x00
#define ODR_1HZ           0x01
#define ODR_10HZ          0x02
#define ODR_25HZ          0x03
#define ODR_50HZ          0x04
#define ODR_100HZ         0x05
#define ODR_200HZ         0x06
#define ODR_400HZ         0x07
#define ODR_1620HZ        0x08
#define ODR_5376HZ        0x09

class Lis2de
{
  public:    
    Lis2de(int SS_pin);   // Constructor
  
    // Structure to hold all the device's settings
    struct sensorSettings {
				uint8_t TEMP_ENABLE = 0x00;
				//CTRL1
				uint8_t ODR = 0x00;
				uint8_t LPEN= 0x01;
				uint8_t ZEN = 0x01;
				uint8_t YEN = 0x01;
				uint8_t XEN = 0x01;
				//CTRL2
				uint8_t HPM = 0x00;
				uint8_t HPCF = 0x00;
				uint8_t FDS = 0x00;
				uint8_t HPCLICK = 0x00;
				uint8_t HPIA2 = 0x00;
				uint8_t HPIA1 = 0x00;
				//CTRL3
				uint8_t INT1_CLICK = 0x00;
				uint8_t INT1_IA1 = 0x00;
				uint8_t INT1_IA2 = 0x00;
				uint8_t INT1_ZYXDA = 0x00;
				uint8_t INT1_WTM = 0x00;
				uint8_t INT1_OVERRUN = 0x00;
				//CTRL4
				uint8_t BDU = 0x00;
				uint8_t FS  = 0x00;
				uint8_t ST  = 0x00;
				uint8_t SIM = 0x00;
				//CTRL5
				uint8_t BOOT = 0x00;
				uint8_t FIFO_EN = 0x00;
				uint8_t LIR_INT1 = 0x00;
				uint8_t D4D_INT1 = 0x00;
				uint8_t LIR_INT2 = 0x00;
				uint8_t D4D_INT2 = 0x00;
				//CTRL6
				uint8_t INT2_CLICK = 0x00;
				uint8_t INT2_IA1 = 0x00;
				uint8_t INT2_IA2 = 0x00;
				uint8_t INT2_BOOT = 0x00;
				uint8_t INT2_ACT = 0x00;
				uint8_t INT_POLARITY = 0x00;
		} settings;
    
    void begin(void);
    void writeByte(uint8_t addr, uint8_t data);    
    uint8_t readByte(uint8_t addr);
    int8_t readOUT_X();
    int8_t readOUT_Y();
    int8_t readOUT_Z();
    
  private:
    uint8_t _SS_pin;
    
};


#endif