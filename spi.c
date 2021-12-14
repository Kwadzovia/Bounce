/*
 * spi.c
 *
 *  Created on: Dec. 13, 2021
 *      Author: seli
 */

#include "spi.h"

void spi_init(void){

    //The recommended eUSCI initialization or reconfiguration process is:
    //1. Set UCSWRST.
        UCA0CTLW0 = UCSWRST;
    //2. Initialize all eUSCI registers while UCSWRST = 1 (including UCxCTL1).
        UCA0CTLW0 |= UCSSEL__SMCLK + UCSYNC;
    //3. Configure ports.

    //4. Clear UCSWRST in software.
        UCA0CTLW0 &= ~(UCSWRST);

    //BIC.B #UCSWRST,&UCxCTL1
    //5. Enable interrupts (optional) by setting UCRXIE or UCTXIE.
        UCA0IE = UCTXIE + UCRXIE;
}
