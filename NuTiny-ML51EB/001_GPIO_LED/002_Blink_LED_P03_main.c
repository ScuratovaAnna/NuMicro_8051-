/************************************************************************************************
*     ML51EB9AE
*   ------------
*  |            |
*  |            |
*  |            |
*  |        P0.3| --> LED G1
*  |            |
*  |            |
*  Autor: ScuratovaAnna + PivnevNikolay
*************************************************************************************************/
//**********************************************1***********************************************//
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

//**********************************************2***********************************************//
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

//**********************************************3***********************************************//
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

//**********************************************4***********************************************//
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