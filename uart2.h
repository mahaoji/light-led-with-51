
#ifndef __UART2_H_
#define __UART2_H_

void Uart2Init(void);
void Uart2Send(char x);
void Uart2SendStr(char *x);
void Uart2SendMsg(char *x);
bit checkok(void);  //ok return 1     no  return 0


extern bit busy2;
extern char wptr2;
extern char buffer2[8];
extern char readflag2;   // =1 is reading    =0 havecheck =2  have read not check



#endif

   //  uart2 is used to connect esp8266  and send msg to the sever 