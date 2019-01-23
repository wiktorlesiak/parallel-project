/*
***********************************
LATENT/INFECTED MODEL - SERIAL
***********************************
 */

#include <stdio.h>
#include "worldVariables.h"
#include "worldFunctions.h"

// function to print any world
void printWorld(int **theworld) {

    int i, j;

    for(i=0;i<ROWS;i++) {
        for(j=0; j<COLS;j++)
            printf("%d", theworld[i][j]);

        printf("\n");
    }
}
