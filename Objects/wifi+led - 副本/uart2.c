#include <intrins.h>
#include <stc8.h>


bit busy2=0;
char wptr2=0;
char buffer2[8];

char readflag2=0;    //    =1 is reading    =0 havecheck =2  have read not check

static bit finishK=0;


bit checkok(void)
{
		bit s=finishK;
		finishK = 0;
		return(s);
}

void Uart2Init(void)
{
	S2CON = 0x50;
	AUXR |= 0x14;
  T2L = 0xE8;
	T2H = 0xFF;
	wptr2 = 0x00;
	busy2 = 0;
}

void Uart2Isr() interrupt 8
{
		if (S2CON & 0x02)       //Ti2
		{
				S2CON &= ~0x02;
				busy2=0;
		}
		if (S2CON & 0x01)      // Ri2
		{
				unsigned char s=S2BUF;
				S2CON &=~0x01;
				if (readflag2 == 1)
						buffer2[wptr2++] = s;
				else {
						if (s == 'K') finishK = 1;
						if (s == 0x7A) {readflag2 = 1; buffer2[wptr2++] = s;}
				}
				if (wptr2 == 8)
				{
					readflag2 = 2;
					wptr2 = 0;
				}
					
				
			
		}
}

void Uart2Send(char dat)
{
		while(busy2);
		busy2 = 1;
		S2BUF = dat;
}

void Uart2SendStr(char *p)
{
		while(*p)
		{
				Uart2Send(*p++);
		}
}

void Uart2SendMsg(char *p)
{
		unsigned char i;
		for (i=0;i<8;i++) Uart2Send(*p++);
}