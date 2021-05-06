#ifndef _LED_c
#define _LED_c

#endif

#include <STC8.H>
#include <intrins.h>
#include "UART1.h"
#include "led_task.h"
#include "Char.h"

#define Fosc 11059200

sbit DO = P1^6;//数据输出口口

	ColorState_e  color=COLOR_RED;

unsigned char state = 0;
unsigned char color_buf[3];
unsigned char jiantou[6] = 
{0x99,0x3C,0x7E,0xFF,0xE7,0xC3};


void delay1us()
{
    unsigned char a;
    for(a=3;a>0;a--);
}

/**目前测试STC15系列9～30MHz整得成**/
/**适当调整_NOP_(),最低8MHz也整得成***/
/*调整Re、Gr、Bl的比例可搭配出各种颜色*/
/********0～255,共256级亮度 *********/
/*****调整数字大小可调整色调及亮度*****/
//括号内分别代表（红、绿、蓝）数据
void WS2812WR(unsigned char Re,unsigned char Gr,unsigned char Bl)
{
	unsigned char Color=3,dat,i=8;
	DO=0;
	//依次输出24bit GRB数据
	while(Color--)
	{
		if(Color==2)dat=Gr;
		if(Color==1)dat=Re;
		if(Color==0)dat=Bl;
		while(i--)
		{
			if(dat & 0X80)//写1
			{
				DO=1;delay1us();
				DO=0;_nop_();
			}
			else          //写0
			{
				DO=1;_nop_();
				DO=0;delay1us();
			}
			dat <<= 1;
		}
		
        i=8;
	}
}

void Display_all(unsigned char color){
	unsigned char i;
	
	switch(color){
		case COLOR_OFF:
			for(i = 0; i < COLOR_NUM; i++){
				WS2812WR(0, 0, 0);
			}
			break;
			
		case COLOR_RED:
			for(i = 0; i < COLOR_NUM; i++){
				WS2812WR(200, 0, 0);
			}
			break;
			
		case COLOR_BLUE:
			for(i = 0; i < COLOR_NUM; i++){
				WS2812WR(0, 0, 200);
			}
			break;
			
		case COLOR_GREEN:
			for(i = 0; i < COLOR_NUM; i++){
				WS2812WR(0, 200, 0);
			}
			break;
			
		case COLOR_YELLOW:
			for(i = 0; i < COLOR_NUM; i++){
				WS2812WR(100, 100, 0);
			}
			break;
			
		default:
			break;
	}
}

void Display_one_led(unsigned char color){
	
	switch(color){
		case COLOR_OFF:
				WS2812WR(0, 0, 0);
			break;
			
		case COLOR_RED:
				WS2812WR(200, 0, 0);
			break;
			
		case COLOR_BLUE:
				WS2812WR(0, 0, 200);
			break;
			
		case COLOR_GREEN:
				WS2812WR(0, 200, 0);
			break;
			
		case COLOR_YELLOW:
				WS2812WR(100, 100, 0);
			break;
			
		default:
			break;
	}
}

void Display_char(unsigned char character){
	unsigned char i;
	for(i = 0; i < 8; i++){
		unsigned char display_buf = character_table[character][i];
		unsigned char j;
		for(j = 0; j < 8; j++){
			if((display_buf >> j) & 0x01) Display_one_led(color);
			else Display_one_led(COLOR_OFF);
		}
	}
}

void Display_jiantou(){
	static char add=0;
	unsigned char i;
	add++;
	add=add%6;
	for(i = 0; i < 48; i++){
		unsigned char display_buf = jiantou[(i+add)%6];
		unsigned char j;
		for(j = 0; j < 8; j++){
			if((display_buf >> j) & 0x01) Display_one_led(color);
			else Display_one_led(COLOR_OFF);
		}
	}
}


void Display_edge(){
	unsigned char i;
	for(i = 0; i < 24; i++){
		Display_one_led(color);
	}
}
