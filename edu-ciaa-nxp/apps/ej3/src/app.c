/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

int main(void)
{
    boardConfig();
    uartConfig(UART_USB, 115200);

    while(TRUE)
    {
        if(!gpioRead(TEC1)) {
            gpioWrite(LEDB, ON);               // LED Azul
            uartWriteString(UART_USB, "BOTON1\n");
        } else {
            gpioWrite(LEDB, OFF);
        }

        if(!gpioRead(TEC2)) {
            gpioWrite(LED1, ON);               // LED Rojo
            uartWriteString(UART_USB, "BOTON2\n");
        } else {
            gpioWrite(LED1, OFF);
        }

        if(!gpioRead(TEC3)) {
            gpioWrite(LED2, ON);               // LED Amarillo
            uartWriteString(UART_USB, "BOTON3\n");
        } else {
            gpioWrite(LED2, OFF);
        }

        if(!gpioRead(TEC4)) {
            gpioWrite(LED3, ON);               // LED Verde
            uartWriteString(UART_USB, "BOTON4\n");
        } else {
            gpioWrite(LED3, OFF);
        }

    }

}
