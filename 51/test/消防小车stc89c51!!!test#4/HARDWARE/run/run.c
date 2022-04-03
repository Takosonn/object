#include <REGX52.H>
#include "wheel.h"

////////////////////////////////////////////////////////////////

sbit EN1A = P0^7;  //LF
sbit EN1B = P0^2;  //RF
sbit EN2A = P3^7;  //LR
sbit EN2B = P3^2;  //RR

///////////////////////////////////////////////////////////////

unsigned char counter1,speed;  //max speed=100

void Timer_Init()	//@11.0592MHz 100ms
{
	TMOD = 0x11;    //set timer1&&0 as mode1 (16-bit)
	TL0  = 0xA4;		//initial set
	TH0  = 0xFF;		//initial set
	TF0  = 0;		    //clear TF0
	TR0  = 1;		    //timer start
	ET0  = 1;       //allow to interrupt
	EA   = 1;       //open all timers
	PT0  = 1;       //interrupt priority
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;		  //initial set
	TH0 = 0xFF;		  //initial set
	
	counter1++;
	if(counter1 >= 100)
	{
		counter1 = 0;
	}
	
	if(counter1 < speed)
	{
		EN1A = 1;
		EN1B = 1;
		EN2A = 1;
		EN2B = 1;
	}
	
	else
	{
		EN1A = 0;
		EN1B = 0;
		EN2A = 0;
		EN2B = 0;
	}
}

////////////////////////////////////////////////////////////////

void car_go()
{
	speed = 14;
	LF_motor_go();
	RF_motor_go();
	LR_motor_go();
	RR_motor_go();
}
void car_back()
{
	speed = 30;
	LF_motor_back();
	RF_motor_back();
	LR_motor_back();
	RR_motor_back();
}
void car_stop()
{
	speed = 30;
	LF_motor_stop();
	RF_motor_stop();
	LR_motor_stop();
	RR_motor_stop();
}
void car_leftgo()
{
	speed = 30;
	LF_motor_go();
	RF_motor_stop();
	LR_motor_go();
	RR_motor_stop();
}
void car_rightgo()
{
	speed = 30;
	LF_motor_stop();
	RF_motor_go();
	LR_motor_stop();
	RR_motor_go();
}
void car_rightback()
{
	speed = 25;
	LF_motor_back();
	RF_motor_stop();
	LR_motor_back();
	RR_motor_stop();
}
void car_leftback()
{
	speed = 25;
	LF_motor_stop();
	RF_motor_back();
	LR_motor_stop();
	RR_motor_back();
}
void car_leftstop()
{
	speed = 25;
	LF_motor_go();
	RF_motor_back();
	LR_motor_go();
	RR_motor_back();
}
void car_rightstop()
{
	speed = 25;
	LF_motor_back();
	RF_motor_go();
	LR_motor_back();
	RR_motor_go();
}