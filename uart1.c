#include <intrins.h>
#include <stc8.h>


bit busy1=0;
char wptr1=0;
char buffer1;
char readflag1=0;    //   =1 is reading    =0 havecheck =2  have read not check

void Uart1Init(void)
{
	SCON = 0x50;
	AUXR |= 0x15;
  T2L = 0xE8;
	T2H = 0xFF;
	wptr1 = 0x00;
	busy1 = 0;
}

void Uart1Isr() interrupt 4
{
	unsigned char s=SBUF;
		if (TI)
		{
				TI=0;
				busy1=0;
		}
		if (RI)
		{
				RI=0;
				
				if (readflag1 == 1  && s<=10)  {buffer1=s;  readflag1=2;}
				if (readflag1 == 0  && s=='@')   {readflag1=1;}
		}
}

void Uart1Send(char dat)
{
		while(busy1);
		busy1 = 1;
		SBUF = dat;
}

void Uart1SendStr(char *p)
{
		while(*p)
		{
				Uart1Send(*p++);
		}
}


