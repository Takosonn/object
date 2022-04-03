#include <REGX52.H>
#include <intrins.h>
#include "run.h"
#include "Delay.h"

////////////////////////////////////////////////////////////////

sbit Trig = P2^1;   //emitter
sbit Echo = P2^2;   //receiver

unsigned int distance;
unsigned int limit=30;

////////////////////////////////////////////////////////////////

void Delay20us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}

////////////////////////////////////////////////////////////////

void sonar()
{
	TMOD = 0x11;     //mode set
	TL1  = 0;        //initial set
	TH1  = 0;        //initial set
	
	Trig = 1;
	Delay20us();
	Trig = 0;
	
	while(!Echo);
	TR1  = 1;				 //transmit
	while(Echo);
	TR1  = 0;				 //stop transmit
	
	distance = ((TH1*256+TL1)*0.034)/2;
	
	if(distance<limit)
	{
		car_leftstop();
		Delay(600);
	}
}
