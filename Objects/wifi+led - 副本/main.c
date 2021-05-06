#include <uart1.h>
#include <intrins.h>
#include <stc8.h>
#include <uart2.h>
#include <led_task.h>
#include <Ref_Sys.h>
#include <wifi.h>


sbit DO = P1^6;//数据输出
sbit key = P1^7;
sbit gnd = P0^0;
unsigned char msg[8];

void main()
{	  
		unsigned char i;
		unsigned char j;
		Uart1Init();
		Uart2Init();
		IE2=0x01;      // open uart2 interrupt
		ES=1;          // open uart1 interrupt
		EA=1;          // open interrupt


		msg[0] = 0x7a;    //  帧首位
		msg[1] = 0x01;    //  裁判系统01号

	color=COLOR_RED;
	
		EA=0;
		for (i=0;i<=3;i++) WS2812WR(120,0,120);
		EA=1;
		wifistart();
		wificonnect("RM_Server","12345678");
		wificipstart("192.168.1.101\",7777");
		
		delays(500);
		
		Display_char(10);	
		Display_edge();
		
		sendmop();
		
		
		while(1){
		if (readflag2 == 2 && checkRec() ) 
			{
			readflag2=0;
			for ( j=0;j<8;j++) Uart1Send(buffer2[j]);	
			}
		if (readflag1 == 2)
		{
			readflag1=0;
			Display_char(buffer1);
			sendnum(buffer1);
		
		}
			
		
		delays(10);
		}
		
		
		
}





