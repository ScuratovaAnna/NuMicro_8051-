//10.11.2021
//************************************************************************************************
//  File Function: ML51 GPIO toggle RGB Led
/*************************************************************************************************
*     ML51EB9AE
*   ------------
*  |            |
*  |        P0.0| --> LED R
*  |        P0.1| --> LED G
*  |        P0.2| --> LED B
*  |            |
*  |            |
*  Autor: ScuratovaAnna 
*************************************************************************************************/
#include "ML51.H"
uint8_t CW[3]= {0x1,0x2,0x4};
uint8_t i;

//----------------------------------------------------------------------------------------------//
void main (void)
{
	GPIO_SetMode(Port0,BIT0|BIT1|BIT2,GPIO_MODE_PUSHPULL);
	P0 = 0x00;
//----------------------------------------------------------------------------------------------//
  while(1)
  {
		for (i=0;i<3;i++)
		{
		P0 = CW[i];
    Timer2_Delay(24000000,4,200,2000);
		}
  }
}
//--------------------------------------END-----------------------------------------------------//