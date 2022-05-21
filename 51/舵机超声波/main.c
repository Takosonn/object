#include <REGX52.H>
#include "sonar.h"
#include "control.h"

unsigned int m;
unsigned int n=0;

void main()
{
  Timer0_Init();	
	while(1)
		{
		  n = n+1;
			sonar();	
			m = sonar();
			if(m >= 33)
			{
			 if(n <= 300)
			 control1();
			 else
			 control3();
			}
			else
			{
				control2();
			if(n >= 100)
			n = 0;
			
}	}
		}