#include "mbed.h"
#include <cmath>

PwmOut led1(LED1);
PwmOut led2(LED1);
PwmOut led3(LED1);
PwmOut led4(LED1);

float lead = 0;

int main()
{
    while(1){
    	lead +=0.1;
        led1 = fmod(lead, 1.0);
        led2 = fmod(lead, 2.0);
        led3 = fmod(lead, 3.0);
        led4= fmod(lead, 4.0);
        wait(0.10);
        if (lead < 4.0){
        	lead = 0
        }
    }

}
