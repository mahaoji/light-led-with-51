#include <led_task.h>
#include <uart2.h>
#include <intrins.h>

void delays(unsigned int m);


void wifistart(void)
{unsigned char i; 
	while (!checkok()){
		Uart2SendStr("AT\r\n");
		delays(50);
		}
		EA=0;
		for (i=0;i<=5;i++) WS2812WR(120,0,120);
		EA=1;
		
			
		while (!checkok()){
		Uart2SendStr("AT+CWMODE=1\r\n");
		delays(50);
		}
		EA=0;
		for (i=0;i<=7;i++) WS2812WR(120,0,120);
		EA=1;
}

void wificonnect(char * name,char * password)
{unsigned char i; 
	while (!checkok()){
		Uart2SendStr("AT+CWJAP=\"");
		Uart2SendStr(name);
		Uart2SendStr("\",\"");
		Uart2SendStr(password);
		Uart2SendStr("\"\r\n");
		delays(1000);
		}
		EA=0;
		for (i=0;i<=9;i++) WS2812WR(120,0,120);
		EA=1;
}

void wificipstart(char *ip)
{unsigned char i; 
		while (!checkok()){
		Uart2SendStr("\"AT+CIPSTART=\"TCP\",\"");
		Uart2SendStr(ip);
		Uart2SendStr("\r\n");
		delays(500);
		}
		EA=0;
		for (i=0;i<=11;i++) WS2812WR(120,0,120);
		EA=1;
}

void wifisend(char *msg)
{
	while (!checkok()){
	Uart2SendStr("AT+CIPSEND=8\r\n");
	delays(50);
	}
	while (!checkok()){
	Uart2SendMsg(msg);
	delays(50);
	}
}



void delays(unsigned int m)
{
	do{
		unsigned char i, j;

		_nop_();
		_nop_();
		i = 15;
		j = 90;
		do
		{
			while (--j);
		} while (--i);
	} while (--m);
}