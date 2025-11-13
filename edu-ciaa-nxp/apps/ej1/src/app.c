/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

int main(void) {

   boardConfig();
   uartConfig(UART_USB, 115200);

   char c;

   while(1) {
      if (uartReadByte(UART_USB, (uint8_t*)&c)) {
         uartWriteByte(UART_USB, c);
      }
   }

   return 0;
}
