#include <REGX52.H>
#include <intrins.h>
#include "run.h"
#include "Delay.h"

////////////////////////////////////////////////////////////////

sbit Trig1 = P2^0;   //emitter  front
sbit Trig2 = P2^2;   //emitter  right1
sbit Trig3 = P2^4;   //emitter  right2
sbit Echo1 = P2^1;   //receiver front
sbit Echo2 = P2^3;   //receiver right1
sbit Echo3 = P2^5;   //receiver right2

static unsigned int distance1,distance2,distance3;//distance? due to P2^?
static unsigned int j = 0,k = 0,l = 0;			//flags

////////////////////////////////////////////////////////////////

void Delay15us2()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 5;
	while (--i);
}

////////////////////////////////////////////////////////////////

void sonar2()
{
	TMOD  = 0x11;    //since timer1 has set as mode1 in run.c
	TL1   = 0;       //initial set
	TH1   = 0;       //initial set
	EA    = 1;		   //open all timers
	
////////////////////////////
	
	Trig1 = 1;       //front emiter
	Delay15us2();
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
	Delay15us2();
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
	Delay15us2();
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
 
if(distance1 < 77 && distance1 > 69 && distance3 < 20 && k == 0 )
 {
	 if(distance3 < 10)
	  {car_stop();Delay(150);car_leftgo();Delay(520);car_stop();Delay(60);car_go();Delay(100);k = 1;j = 1;}
 }

if(j == 1)
 { 
	 if(distance1 < 33)
	  {car_stop();Delay(80);j = 0;}
	 if(l <= 9)
		{car_go();Delay(200);car_stop();Delay(100);l = l+1;}
	 if(l > 9)
	  {car_stop();Delay(150);car_leftstop();Delay(320);l = 0;} 
	 
 }	
else
 {
	if(distance1 < 15)    
	{car_stop();Delay(80);car_leftstop();Delay(110);car_stop();Delay(80);}
  if(distance2 < 15)    
	{car_stop();Delay(80);car_leftstop();Delay(110);car_stop();Delay(80);}
	else
  {
   if(distance3 < 8.5)
	 {car_leftgo();Delay(60);car_go();Delay(120);car_stop();Delay(80);}
   if(distance3 > 8.5)
	 {
		if(distance3 > 20 && distance3 < 240)
		{car_rightgo();Delay(93);car_go();Delay(49);car_stop();Delay(80);}
	  else
	  {car_rightgo();Delay(60);car_go();Delay(120);car_stop();Delay(80);}
	 }
	}		
 }	

}