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
//	car_go();
//		Delay(200);
//		car_stop();
//		Delay(80);
	flag = fire();
	if(flag <= 1)
		{
		  sonar();
		  fire();
		}
  if(flag > 1)
		{
			sonar2();
			fire();
		}
	}
}	