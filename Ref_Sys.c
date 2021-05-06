#include <uart2.h>
#include <wifi.h>

extern unsigned char msg[8];

void calculate8()
{unsigned char i;
	msg[7]=0;
	for (i=0;i<7;i++)		msg[7] +=	msg[i];
}
void sendmop()
{
	unsigned char i;
	for (i=2;i<7;i++)  msg[i] = 0;
	calculate8();
	wifisend(msg);
}
void sendnum(unsigned char x)
{ unsigned char i;
	msg[2]=5;
	msg[3]=x;
	for (i=4;i<7;i++) msg[i]=0;
	calculate8();
	wifisend(msg);

}


bit checkRec()
{	
	unsigned char i;
	unsigned char ans;
	ans=0;
	
	for (i=0;i<7;i++) ans+=buffer2[i];
	if (ans == buffer2[7] && buffer2[0] == 0x7A )  return(1);
	return(0);
}