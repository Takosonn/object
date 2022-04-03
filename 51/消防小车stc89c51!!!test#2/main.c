#include "run.h"
#include "Delay.h"
#include "sonar.h"

void main()
{
	Timer0_Init();
	
	while(1)
	{
	car_go();
	sonar();
	}
}	