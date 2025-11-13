#include "mbed.h"

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("Hello World!\n");
    while(1) {
        pc.putc(pc.getc());
    }
}
