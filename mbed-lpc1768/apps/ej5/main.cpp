#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Serial pc(USBTX, USBRX);

int lead = 0b0000;
int interval_ms = 2000;

int main()
{
    char buffer[10];
    int marca = 0;

    while(1)
    {
        if (pc.readable()) {
              char c = pc.getc();

              if (c == '\r' || c == '\n') {
                  buffer[marca] = '\0';
                  interval_ms = atoi(buffer);
                  marca = 0;
                  pc.putc('\n\r');
              }
              else if (marca < sizeof(buffer)-1) {
            	  pc.putc(c);
                  buffer[marca++] = c;
              }
          }

        led1 = lead & 0b0001;
        led2 = lead & 0b0010;
        led3 = lead & 0b0100;
        led4 = lead & 0b1000;

        wait_ms(interval_ms);

        lead += 1;

        if (lead == 15) {
            lead = 0;
        }
    }
}
