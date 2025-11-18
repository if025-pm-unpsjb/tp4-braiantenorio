#include "mbed.h"

Serial pc(USBTX, USBRX);

char serial_led = 0;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main() {

    while (1) {
		char c = pc.getc();

		led1 = led2 = led3 = led4 = 0;

		switch(c) {
			case '1': while(1){ led1 = !led1; wait_ms(250); if(pc.readable()) break; } break;
			case '2': while(1){ led2 = !led2; wait_ms(250); if(pc.readable()) break; } break;
			case '3': while(1){ led3 = !led3; wait_ms(250); if(pc.readable()) break; } break;
			case '4': while(1){ led4 = !led4; wait_ms(250); if(pc.readable()) break; } break;
			default:break;
		}

    }
}
