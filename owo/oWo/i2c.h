#ifndef __I2C_H
#define __I2C_H

#include "main.h"
#define uchar unsigned char
void I2CStart(void);
void I2CStop(void);
unsigned char I2CWaitAck(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2CInit(void);
void ee_write(uchar addr,uchar dat);
uchar ee_read(uchar addr);
void RES_Write(uint8_t value);
uint8_t RES_Read();
#endif
