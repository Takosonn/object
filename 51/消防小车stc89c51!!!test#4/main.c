#include "run.h"
#include "Delay.h"
#include "sonar.h"

void main()
{
	Timer_Init();
	car_go();
  while(1)
	{
	
	sonar();
	}
}	