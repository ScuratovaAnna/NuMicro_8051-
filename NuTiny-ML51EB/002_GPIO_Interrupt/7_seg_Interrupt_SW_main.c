//07.12.2021
//-----------------------------------------------------------------------//
/*
*      1        1->P2.0->17
*     ---       2->P2.1->16
*  6 | 7 |2     3->P2.2->15
*     ---       4->P2.3->14
*  5 | 4 |3     5->P2.4->13
*     ---       6->P2.5->12
*               7->P0.0->23
*      ++       USR_SW P1.6
*      --       USR_SW P1.7
*  Autor: ScuratovaAnna + PivnevNikolay
*/
#include "ML51.h"
#define Led P03
bit condition = TRUE;
uint8_t Count = 0;
//-----------------------------------------------------------------------//
void PinInterrupt_ISR (void) interrupt 7
{
    _push_(SFRS);
  
    SFRS = 0;
    switch(PIF)
    {
    case 0x01:
		condition = FALSE;
		Count++;
		if(Count>=9)Count=9;
		break;
    case 0x02:
		condition = FALSE;
		if(Count==0)Count=1;
		Count--;
		break;
    default: break;
    }
    PIF = 0; 
  
    _pop_(SFRS);
}
//-----------------------------------------------------------------------//
void main (void) {
	MFP_P16_GPIO;
	MFP_P17_GPIO;
	GPIO_SetMode(Port1,BIT6,GPIO_MODE_INPUT);
	GPIO_SetMode(Port1,BIT7,GPIO_MODE_INPUT);
	GPIO_EnableInt(PIT0,RISING,EDGE,Port1,6);
	GPIO_EnableInt(PIT1,RISING,EDGE,Port1,7);
	GPIO_SetMode(Port2,BIT0|BIT1|BIT2|BIT3|BIT4|BIT5,GPIO_MODE_PUSHPULL);
	GPIO_SetMode(Port0,BIT0|BIT3,GPIO_MODE_PUSHPULL);
	ENABLE_GLOBAL_INTERRUPT; 
//-----------------------------------------------------------------------//
while(1){
	switch(Count){      
    case 0:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 <<5);//0
	condition = TRUE;
    break;
    case 1:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 <<1)|(1 << 2);//1
	condition = TRUE;
    break;
    case 2:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 3)|(1 << 4);//2
	P0 |= (1 <<0);//2
	condition = TRUE;
    break;
    case 3:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 2)|(1 << 3);//3
	P0 |= (1 <<0);//3
	condition = TRUE;
    break;
    case 4:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 1)|(1 <<2)|(1 << 5);//4
	P0 |= (1 <<0);//4;
	condition = TRUE;
    break;
    case 5:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<2)|(1 << 3)|(1 << 5);//5
	P0 |= (1 <<0);//5
	condition = TRUE;
    break;
    case 6:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<2)|(1 << 3)|(1 << 4)|(1 << 5);//6
	P0 |= (1 <<0);//6
	condition = TRUE;
    break;
    case 7:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 2);//7
	condition = TRUE;
    break;
    case 8:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5);//8
	P0 |= (1 <<0);//8
	condition = TRUE;
    break;
    case 9:
	P0 &= ~(1 << 0);
	P2 &= ~((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)|(1 << 4)|(1 << 5));
	P2 |= (1 << 0)|(1 <<1)|(1 << 2)|(1 << 3)|(1 << 5);//9
	P0 |= (1 <<0);//9
	condition = TRUE;
    break;
    }
	while(condition){
	Led = ~Led;
	Timer2_Delay(24000000,4,200,1000);
	}
	}
}
//--------------------------------END------------------------------------//