#include <REGX52.H>
#include <intrins.h>

sbit Trig1 = P2^0;   //emitter
sbit Echo1 = P2^1;   //receiver

unsigned int distance;

////////////////////////////////////////////////////////////////

void Delay15us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 4;
	while (--i);
}

////////////////////////////////////////////////////////////////

int sonar()
{
	TMOD  = 0x11;    //since timer1 has set as mode1 in run.c
	TL1   = 0;       //initial set
	TH1   = 0;       //initial set
	EA    = 1;		   //open all timers
	
////////////////////////////
	
	Trig1 = 1;       //front emiter
	Delay15us();
	Trig1 = 0;			 //emit a TTL in 20us 
	while(!Echo1);
	TR1   = 1;			 //clock start
	while(Echo1);		 //until received
	{
		TR1 = 0; 		   //end clock
		distance = ((TH1*256+TL1)*0.034)/2;
		TL1 = 0;       //initial reset
		TH1 = 0;       //initial reset	
	}
	return distance;
  }