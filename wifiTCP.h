/* 
 * File:   wifiTCP.h
 * Author: Domingos Neto
 *
 * Created on 29 de Julho de 2015, 15:38
 */

#ifndef WIFITCP_H
#define	WIFITCP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Serial.h"
#include "conversions.h"
    
    
    bit flagLink = 0, flagData;
    unsigned char WifiTCPData[15];
    unsigned WifiTCPDataLen = 15;
    //void initWifiTCP(const char login[], const char senha[]){
    
    void WifiTCPinit(){

       SerialWrite("AT+RST\r\n");
        delaySeg(2);
        
       
       SerialWrite("AT+CWMODE=1\r\n");
        delaySeg(2);
        
       //SerialWrite("AT+CWJAP=\"BatCaverna\",\"23dfd1b64b\"\r\n");
       SerialWrite("AT+CWJAP=\"talkinghand\",\"tk123456\"\r\n");
        delaySeg(8);
        
       SerialWrite("AT+CIPMUX=1\r\n");
        delaySeg(2);
       
       SerialWrite("AT+CIPSERVER=1,4000\r\n");
        delaySeg(2);
        return;
    }

    void WifiTCPSend(unsigned char *stringToSend, unsigned lenStr)
    {
        unsigned char newLine[] = "\r\n";
        unsigned sizeStringToSend = strlen(stringToSend);
        SerialWrite("AT+CIPSEND=0,");
        SerialPrint(lenStr+48);
        SerialWrite(newLine);

        if(ContainString("link is not") && flagLink)
            flagLink = 0;
        __delay_ms(10);
        SerialWrite(stringToSend);
        SerialWrite(newLine);
        waitUntil("OK");
        return;
    }

    
    void WifiTCPRead(void)
    {
        waitToken('_');
        SerialReadUntilToken('_');
        for(unsigned i = 0; i < SerialLen; ++i)
                WifiTCPData[i] = SerialReceivedString[i];
        WifiTCPData[SerialLen] = '\0';
        WifiTCPDataLen = SerialLen;
        return;
    }


#ifdef	__cplusplus
}
#endif

#endif	 WIFITCP_H
