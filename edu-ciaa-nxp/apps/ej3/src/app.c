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

    bool_t R = FALSE, G = FALSE, B = FALSE;

    while(TRUE) {

        if(!gpioRead(TEC2)) {
            R = !R;
            delay(200);
        }

        if(!gpioRead(TEC3)) {
            G = !G;
            delay(200);
        }

        if(!gpioRead(TEC4)) {
            B = !B;
            delay(200);
        }


        gpioWrite(LEDR, R ? ON : OFF);
        gpioWrite(LEDG, G ? ON : OFF);
        gpioWrite(LEDB, B ? ON : OFF);

    }

}
