#ifndef _LED_H
#define _LED_H

#include <STC8.H>
#define Fosc 11059200

typedef enum{
	COLOR_OFF,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_YELLOW,
} ColorState_e;

#define COLOR_NUM 100


extern void WS2812WR(unsigned char Re,unsigned char Gr,unsigned char Bl); 
extern void delays(unsigned int m);
extern void Display_all(unsigned char);
extern void Display_char(unsigned char);
extern void Display_edge();
extern void Display_jiantou();
extern ColorState_e color;
extern unsigned char color_buf[3];

#endif