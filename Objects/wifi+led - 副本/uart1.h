// uart1 is used to connect the car    


#ifndef __UART1_H_
#define __UART1_H_

void Uart1Init(void);
void Uart1Send(char x);
void Uart1SendStr(char *x);
bit Uart1checkok(char *x);              // 


extern bit busy1;
extern char wptr1;
extern char buffer1;
extern char readflag1;



#endif