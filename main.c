#include <uart1.h>
#include <intrins.h>
#include <stc8.h>
#include <uart2.h>
#include <led_task.h>
#include <Ref_Sys.h>
#include <wifi.h>


sbit DO = P1^6;//Êý¾ÝÊä³ö
sbit key = P1^7;
sbit gnd = P0^0;
unsigned char msg[8];
unsigned char i,j;
void main()
{	  
		
		
		while(1){
			
			
		Display_jiantou();
	delays(100);
	


		}
		
		
		
		
}





