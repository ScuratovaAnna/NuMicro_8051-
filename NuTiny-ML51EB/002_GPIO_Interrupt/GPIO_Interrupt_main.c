//21.11.2021
/*************************************************************************************************
*     ML51EB9AE
*   ------------
*  |            |
*  |        P0.3| --> LED G1
*  |            |
*  |        P1.7| <-- USR_SW
*  |            |
*  |            |
*  Autor: ScuratovaAnna 
*************************************************************************************************/
#include "ML51.h"
#define LED P03
//----------------------------------------------------------------------------------------------//
void PinInterrupt_ISR (void) interrupt 7
{
_push_(SFRS);
SFRS = 0;
LED ^= 1;
PIF = 0;
_pop_(SFRS);
}
//----------------------------------------------------------------------------------------------//
void main (void)
{
MFP_P17_GPIO;//Button_pin
MFP_P03_GPIO;//Led_pin
//GPIO_SetMode(Port1,BIT7,GPIO_MODE_INPUT);
P17_INPUT_MODE;
//GPIO_Pull_Enable(Port1,BIT7,PULLDOWN);
ENABLE_P17_PULLDOWN;
GPIO_EnableInt(PIT0,RISING,EDGE,Port1,7);
P03_PUSHPULL_MODE;
ENABLE_GLOBAL_INTERRUPT;// global enable bit
while(1);
}
//---------------------------------------------END----------------------------------------------//