#include "run.h"
//#include "Delay.h"
#include "sonar.h"
#include "fire.h"
#include "fan.h"

void main()
{
	fan_off();
	Timer_Init();
	car_go();
	while(1)
	{
	sonar();
	fire();
	}
}	