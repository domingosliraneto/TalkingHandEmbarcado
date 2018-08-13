/* 
 * File:   PWM.h
 * Author: Domingos Neto
 *
 * Created on 16 de Março de 2016, 14:46
 */

#ifndef PWM_H
#define	PWM_H

void pwmExecute(unsigned char* duty){
    counter2++;
    if(counter2 == 10)
    {
        counter2 = 0;
        counter++;
    }
    if(counter == duty[0]){
        LATB &= 0b11111011; 
    }
    if(counter == duty[1]){
        LATB &= 0b11110111; 
    }
    if(counter == duty[2]){
        LATB &= 0b11101111; 
    }
    if(counter == duty[3]){
        LATB &= 0b11011111; 
    }else if(counter == 0){
        LATB |= 0b11111100;
    }else if(counter == 256){
        counter = 0;
    }
    return;
}

#endif	/* PWM_H */

