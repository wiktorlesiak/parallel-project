/*
**************************************
LATENT/INFECTED MODEL - SERIAL
**************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "worldVariables.h"
#include "worldFunctions.h"

// create original World
void createWorld(int **world) {

    int i,j,x,y;

    for(i=0; i<ROWS;i++) {
        for(j=0; j<COLS; j++) {
        // using bitwise operator to create 75% probability of human, 25% probability of zombie
        world[i][j] = rand() % 2 | rand() % 2;
        }
    }

    // count the number of Humans and Zombies at the creation of the world
    int currentCellState;

    for(x=0; x<ROWS;x++) {
        for(y=0; y<COLS; y++) {

        currentCellState = world[x][y];

	// count zombies
            if(currentCellState==0) {
                totalZombieWorldCount++;
            }

	    // count humans
            if(currentCellState==1) {
                totalHumanWorldCount++;
            }
        }
    }
}
