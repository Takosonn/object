#include "run.h"
#include "sonar.h"
#include "fire.h"
#include "fan.h"
#include "sonar2.h"
#include "Delay.h"
int flag = 0;
void main()
{
	fan_off();
	Timer_Init();
	while(1)
	{
	flag = fire();
	if(flag <= 1)
		{
		  sonar();
		  fire();
		}
  if(flag == 2)
		{
			sonar2();
			fire();
	if(flag == 3)
		{
			car_leftstop();
		  Delay(400);
			car_go();
			Delay(330);
			sonar();
		}
	 }
	}
}	