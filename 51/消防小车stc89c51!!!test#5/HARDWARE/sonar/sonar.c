#include <REGX52.H>
#include <intrins.h>
#include "run.h"
#include "Delay.h"

////////////////////////////////////////////////////////////////

sbit Trig1 = P2^0;   //emitter  front
sbit Trig2 = P2^2;   //emitter  left
sbit Trig3 = P2^4;   //emitter  right
sbit Echo1 = P2^1;   //receiver front
sbit Echo2 = P2^3;   //receiver left
sbit Echo3 = P2^5;   //receiver right

unsigned int distance1,distance2,distance3;         //distance? due to P2^?
//unsigned int limit1=20,limit2=20,limit3=20;         //limit?    due to P2^?

////////////////////////////////////////////////////////////////

void Delay15us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 5;
	while (--i);
}

////////////////////////////////////////////////////////////////

void sonar()
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
		distance1 = ((TH1*256+TL1)*0.034)/2;
		TL1 = 0;       //initial reset
		TH1 = 0;       //initial reset	
	}
	
	
	Trig2 = 1;       //left emiter
	Delay15us();
	Trig2 = 0;			 //emit a TTL in 20us 
	while(!Echo2);
	TR1   = 1;			 //clock start
	while(Echo2);		 //until received
	{
		TR1 = 0; 		   //end clock
		distance2 = ((TH1*256+TL1)*0.034)/2;
		TL1 = 0;       //initial reset
		TH1 = 0;       //initial reset	
	}

	
	Trig3 = 1;       //right emiter
	Delay15us();
	Trig3 = 0;			 //emit a TTL in 20us 
	while(!Echo3);
	TR1   = 1;			 //clock start
	while(Echo3);		 //until received
	{
		TR1 = 0; 		   //end clock
		distance3 = ((TH1*256+TL1)*0.034)/2;
		TL1 = 0;       //initial reset
		TH1 = 0;       //initial reset	
	}

///////////////////////////
	
	if(distance1 < 15)    
	{car_stop();Delay(80);car_leftstop();Delay(150);car_stop();Delay(80);}
  if(distance2 < 15)    
	{car_stop();Delay(80);car_leftstop();Delay(150);car_stop();Delay(80);}
	else
  {

	if(distance3 < 8.5)
	{car_leftgo();Delay(50);car_go();Delay(130);car_stop();Delay(80);}
  if(distance3 > 8.5)
	{
		
		if(distance3 > 50 && distance3 < 200)
		{car_rightgo();Delay(100);car_go();Delay(30);car_stop();Delay(80);}
	  else
	  {car_rightgo();Delay(70);car_go();Delay(130);car_stop();Delay(80);}
	}
	}	
}