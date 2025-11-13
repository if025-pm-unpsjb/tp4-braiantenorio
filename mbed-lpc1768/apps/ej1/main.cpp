#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int lead = 0b0000;

int main()
{
    while(1)
    {
    	led1 = lead & 0b0001;
    	led2 = lead & 0b0010;
    	led3 = lead & 0b0100;
    	led4 = lead & 0b1000;

    	wait(2);

    	lead += 1;

    	if (lead == 15){
    		lead = 0;
    	}
    }
}
