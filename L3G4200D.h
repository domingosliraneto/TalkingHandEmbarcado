/* 
 * File:   L3G4200D.h
 * Author: Domingos Neto
 *
 * Created on 3 de Maio de 2016, 14:54
 */

#include <plib/i2c.h>

unsigned readGIRO(unsigned Adress){
    
    StartI2C();
    WriteI2C(0xD0);
    IdleI2C();
    WriteI2C(Adress);
    IdleI2C();
    RestartI2C();
    WriteI2C(0xD1);
    IdleI2C();
    unsigned c = ReadI2C();
    NotAckI2C();
    StopI2C();
    return c;       
}