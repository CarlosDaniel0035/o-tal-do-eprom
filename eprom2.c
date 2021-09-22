/*
 * File:   eeprom.c
 * Author: curtaeletronica
 *
 * Created on 10 de Janeiro de 2020, 16:34
 */

#include <xc.h>

char EEPROM_read( unsigned char addr )
{
    EEADRH = 0;           // habilita EEDAT
    EEADR = addr;         // endereço 
    EECON1bits.EEPGD = 0;      // acessa memoria de dado
    EECON1bits.RD = 1;         // inicia leitura de memoria
    return( EEDAT );           // retorna 
}

void EEPROM_write( unsigned char addr, unsigned char data )
{
    INTCONbits.GIE = 0;
    EEADR = addr;               // endereço 
    EEDAT = data;               // dados
    EECON1bits.EEPGD = 0;       // acessa memoria de dado
    EECON1bits.WREN = 1;        // habilita gravação
    EECON2 = 0x55;              // 
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    
    while( EECON1bits.WR );  // enquanto ciclo de gravação 
    
    EECON1bits.WREN = 0; // desabilita gravação
    INTCONbits.GIE = 1; // desabilita todas as interrupções 
}

void write (char adrs, unsigned char *data)
{ 
    char i = adrs;
    
    while(*data)
    {
        EEPROM_write(i,*data);
        ++data;
        ++i;
    }   
}

void read ( char adrs , char qtd , char * eep )
{
   
     int i = adrs;
     while(  i <= (qtd + adrs) )
     {
        *(eep + i) = EEPROM_read(i);
        ++i;
     }
}

void Deletar (char inicio, char fim)
{
    while(inicio < fim)
    {
        EEPROM_write(inicio,' ');
        ++ inicio;
    }
}

void clear_eeprom (void)
{
    char i = 255;
    
    if( i > 0)
    {
        EEPROM_write(i,' ');
        i++;
    }
}
