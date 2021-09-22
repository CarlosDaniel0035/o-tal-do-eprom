#ifndef DISPLCD4VIAS_H
#define DISPLCD4VIAS_H

#define LCD_ROWS        2
#define LCD_COLS        16

void initLCD( void );
void intTOstr( int ui16, char * str );
void lcd( unsigned char x, unsigned char y, const char * ptr );
void lcdxy( unsigned char x, unsigned char y );
void dispLCD_clr (void);
void LCD_lincol( unsigned char lin, unsigned char col);
void dispLCD_instReg( unsigned char i );
void dispLCD_dataReg( unsigned char d );
/*
 * **************** Funções de acesso aos botões da placa do display LCD
 */
char lcdb0( void );
char lcdb1( void );


#endif	/* LCD_H */
