/*
 * File:   main.c
 * Author: 20185070
 *
 * Created on 21 de Setembro de 2021, 13:43
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "dispLCD4vias.h"
#include "eprom2.h"
#include "fifo.h"
#include "teclado.h"
#include "timer.h"



char vetor[10];
char estado = 1;

void main(void)

      
{
    teclado_init();
    initLCD();
    
    char tecla = 0;
    
    switch (estado)
    {
            case 1:
                
                
                lcd(0,0,"Inicializado");
                __delay_ms(3000);
                lcd(0,1,"Boladao");
                setT1(1000);       
                
                estado = 2;
                break;
                
            case 2:
                dispLCD_clr();
                lcd(0,0,"1: salvar uma seq?");
                lcd(1,0,"2: seq salvas");
                switch(tecla)
                {
                                case '1':
                                             estado = 4;
                                                        break;   
                                case '2':
                                             estado = 3;     
                                                        break;
                }
                        
            
        case 3:
            
            estado = 15;
            break;
        case 4:
                              dispLCD_clr();                         //LIMPA O DISPLAY
                              lcd(0,0,"   A- B- C- D-  ");       //INSERE A MESNSAGEM NA 1ª LINHA DO DISPLAY
                              
                            tecla = teclado_borda();               //A VARIAVEL TECLA RECEBE A TECLA PRESSIONADA PELO USUÁRIO
                            switch(tecla)
                            {
                                case 'A':   alt_atuador(tecla); LCD_lincol(0, 4); dispLCD_instReg(ler_atuador('A') ? 'A' : 'a');     break;        //CASO "A" FOR PRESSIONADO AVANÇA ATUADOR A, POSICIONA O CURSOR NA LINHA 0 COLUNA 4, LE O ATUADOR, SE FOR VERDADEIRO +, SE FOR FALSO -  
                                case 'B':   alt_atuador(tecla); LCD_lincol(0, 7); dispLCD_instReg(ler_atuador('B') ? 'B' : 'b');     break;        //CASO "B" FOR PRESSIONADO AVANÇA ATUADOR B, POSICIONA O CURSOR NA LINHA 0 COLUNA 7, LE O ATUADOR, SE FOR VERDADEIRO +, SE FOR FALSO -
                                case 'C':   alt_atuador(tecla); LCD_lincol(0,10); dispLCD_instReg(ler_atuador('C') ? 'C' : 'c');     break;        //CASO "C" FOR PRESSIONADO AVANÇA ATUADOR C, POSICIONA O CURSOR NA LINHA 0 COLUNA 7, LE O ATUADOR, SE FOR VERDADEIRO +, SE FOR FALSO -
                                case 'D':   alt_atuador(tecla); LCD_lincol(0,13); dispLCD_instReg(ler_atuador('D') ? 'D' : 'd');     break;
                                case '#':   estado = 6;                            break;                        
                            };
            estado = 5;
            break;
        case 5:
            
            estado = 6;
            break;
            
    }
    return;
}

