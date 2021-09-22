/*
 * File:   delay.c
 * Author: 20187263
 *
 * Created on 17 de Setembro de 2021, 13:13
 */


#include <xc.h>
#include "delay.h"

void delay( unsigned int t )
{
    while( t )
    {
        __delay_ms(1);
        --t;
    }
}
