#include "mbed.h"

Serial pc(USBTX, USBRX);

char serial_led = 0;

int main() {
	pc.printf("Hello World!\n");

    while(1) {
    	serial_led = pc.getc();

        pc.putc(pc.getc());
    }
}
