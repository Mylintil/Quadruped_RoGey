#ifndef DEF_ROGPIO

#include "RoGPIO.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#endif // DEF_ROGPIO


int main(void)
{
    	while(1)
	{
		GPIO servo_1;
		servo_1.ecrire_PWM(12, 1);
		usleep(1000000);
		servo_1.ecrire_PWM(12,180);
	}
	return 0;
}
