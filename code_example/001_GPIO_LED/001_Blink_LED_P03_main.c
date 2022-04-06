/**---------------------------------------------
*\date  11.11.2021
*\brief
*     ML51EB9AE
*   ------------
*  |            |
*  |            |
*  |            |
*  |        P0.3| --> LED G1
*  |            |
*  |            |
*
*\authors ScuratovaAnna 
*
*************************************************************************************************
*\brief
*  #define GPIO_MODE_QUASI      0
*  #define GPIO_MODE_PUSHPULL   1
*  #define GPIO_MODE_INPUT      2
*  #define GPIO_MODE_OPENDRAIN  3
*  
*  #define  Port0     0
*  #define  Port1     1
*  #define  Port2     2
*  #define  Port3     3
*  #define  Port4     4
*  #define  Port5     5
*  #define  Port6     6
*    
*  #define BIT0    0x01
*  #define BIT1    0x02
*  #define BIT2    0x04
*  #define BIT3    0x08
*  #define BIT4    0x10
*  #define BIT5    0x20
*  #define BIT6    0x40
*  #define BIT7    0x80
*
*  #define  PULLUP     0
*  #define  PULLDOWN   1
*  end of group GPIO_EXPORTED_CONSTANTS 
*
*  void GPIO_SetMode(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8Mode);
*  void GPIO_Pull_Enable(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8PullMode);
*  void GPIO_Pull_Disable(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8PullMode);
*************************************************************************************************
*                                               0                                               *
//**********************************************************************************************//
#include "ML51.H"
uint32_t period =80000;
void pause(uint32_t z);
//----------------------------------------------------------------------------------------------//
void main (void)
{
  SFRS=1;P0M1&=0xFE;P0M2|=0x01;//P00_PUSHPULL_MODE;
  while(1)
  {
  P00=1;//1	
  pause(period);
  P00=0 ;//0
  pause(period);		
  }	
}
//----------------------------------------------------------------------------------------------//
void pause(uint32_t z){
  volatile uint32_t i=0;
  for(i=0;i<z;++i)
  {
   nop;
  }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               1                                               *
************************************************************************************************//
#include "ML51.H"
#define Led P03
//----------------------------------------------------------------------------------------------//
void main (void)
{
	P03_PUSHPULL_MODE;
//----------------------------------------------------------------------------------------------//
  while(1)
  {
	Led = !Led;
	Timer3_Delay(24000000,4,200,1000);		
  }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               2                                               *
************************************************************************************************//

#include "ML51.H"
#define Led P03
//----------------------------------------------------------------------------------------------//
void main (void)
{
	P03_PUSHPULL_MODE;
//----------------------------------------------------------------------------------------------//
  while(1)
  {
	Led = ~Led;
	Timer2_Delay(24000000,4,200,1000);		
  }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               3                                               *
************************************************************************************************//

#include "ML51.H"
#define Led P03
//----------------------------------------------------------------------------------------------//
void main (void)
{
	P03_PUSHPULL_MODE;
//----------------------------------------------------------------------------------------------//
  while(1)
  {
	P0 =0x8;
	Timer2_Delay(24000000,4,200,1000);
	P0 =0x0;
	Timer3_Delay(24000000,4,200,1000);
  }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               4                                               *
************************************************************************************************//

#include "ML51.H"
#define Led P03
//----------------------------------------------------------------------------------------------//
void main (void)
{
	P03_PUSHPULL_MODE;
//----------------------------------------------------------------------------------------------//
  while(1)
  {
	P0 |= (1 << 3); //1
	Timer2_Delay(24000000,4,200,1000);
	P0 &= ~(1 << 3);//0
	Timer3_Delay(24000000,4,200,1000);
  }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               5                                               *
************************************************************************************************//
#include "ML51.H"
#define Led P03

 void pause(uint32_t z){
 volatile uint32_t i=0;
 for(i=0;i<z;++i)
  {
   _nop_();
  }
 }

void main (void)
{  
//GPIO_SetMode(Port0,BIT3,GPIO_MODE_PUSHPULL);
SFRS=1;P0M1&=0xF7;P0M2|=0x08;
//----------------------------------------------------------------------------------------------//
  while(1)
 {
  //также можно использовать FAIL 1; PASS 0; TRUE 1; FALSE 0;
  Led = Enable;//1	
  pause(80000);
  Led = Disable;//0
  pause(80000);
 }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                               6                                               *
************************************************************************************************//
/**---------------------------------------------
*\brief 
*https://alexgyver.ru/lessons/pointers/
-----------------------------------------------*/
#include "ML51.H"
uint8_t CW[2]= {0x0,0x1};
uint8_t i;
//----------------------------------------------------------------------------------------------//
void main (void)
{
  //GPIO_SetMode(Port0,BIT3,GPIO_MODE_PUSHPULL);
  P03_PUSHPULL_MODE;
//----------------------------------------------------------------------------------------------//
 while(1)
 {
	for (i=0;i<2;i++)
	{
		P03 = *(CW+i);
		Timer2_Delay(24000000,4,200,1000);
	}
 }
}
//---------------------------------------------END----------------------------------------------//

/************************************************************************************************
*                                       7_button example                                        *
************************************************************************************************//
/**---------------------------------------------
*\brief 
*     ML51EB9AE
*   ------------
*  |            |
*  |        P0.0| <-- Button
*  |            |
*  |        P0.3| --> LED G1
*  |            |
*  |            |
*
*  Touch button module TTP223B
-----------------------------------------------*/
#include "ML51.H"
#define Led P03
//----------------------------------------------------------------------------------------------//
void pause(uint32_t z){
  volatile uint32_t i=0;
  for(i=0;i<z;++i)
   {
	//  _nop_();
	nop;
   }
}

void main (void)
{
  /// P03_PUSHPULL_MODE;
  GPIO_SetMode(Port0,BIT3,GPIO_MODE_QUASI);///P03 Led output
  /// P00_INPUT_MODE;
  GPIO_SetMode(Port0,BIT0,GPIO_MODE_INPUT);///P00 button input
//----------------------------------------------------------------------------------------------//
while(1)
  {
  uint32_t period = 80000;
  if(P00 != FALSE) period = 8000;	
  Led = 1;//1	
  pause(period);
  Led = 0 ;//0
  pause(period);
  }
}
//---------------------------------------------END----------------------------------------------//