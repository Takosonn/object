#include "run.h"
#include "Delay.h"
#include "sonar.h"

void main()
{
	Timer_Init();
	
	while(1)
	{
	car_go();
	Delay(1);
	sonar();
	}
}	