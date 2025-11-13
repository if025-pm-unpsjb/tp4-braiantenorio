#include "mbed.h"
#include <cmath>

PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

float lead = 0;

int main()
{
    while(1){
    	lead +=0.05;

        led1 = (lead < 1) ? lead : 0;

        led2 = (lead < 2) ? lead-1 : 0;

        led3 = (lead < 3) ? lead-2 : 0;

        led4 = (lead < 4) ? lead-3 : 0;

        wait(0.25);

        if (lead > 4.0){
        	lead = 0;
        }
    }
}
