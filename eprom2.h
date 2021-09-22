#ifndef EPROM2_H
#define EPROM2_H

char EEPROM_read( unsigned char addr );
void EEPROM_write( unsigned char addr, unsigned char data );
void write (char adrs, unsigned char *data);
void read ( char adrs , char qtd , char * eep );
void Deletar (char inicio, char fim);


#endif

