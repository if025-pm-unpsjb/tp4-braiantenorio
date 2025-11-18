/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

#define MAX_MSG_LEN 100

int main(void) {

   boardConfig();
   uartConfig(UART_USB, 115200);

   char c;
   char buffer[MAX_MSG_LEN];
   uint16_t index = 0;

   while(1) {

      if (uartReadByte(UART_USB, (uint8_t*)&c)) {

         if(index < MAX_MSG_LEN - 1) {
            buffer[index++] = c;
         }

         if(c == '\n') {
            buffer[index] = '\0';
            uartWriteString(UART_USB, buffer);
            index = 0;
         }
      }
   }

   return 0;
}
