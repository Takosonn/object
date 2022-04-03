#include <REGX52.H>

sbit fan1 = P1^0;    //IN1
sbit fan2 = P1^1;    //IN3

////////////////////////////////////////////////////////////////

void fan_on()
{
		 fan1 = 1;
		 fan2 = 1;
}	

void fan_off()
{
		 fan1 = 0;
		 fan2 = 0;
}	