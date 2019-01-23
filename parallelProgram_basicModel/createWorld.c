/*
**********************************
BASIC MODEL - PARALLEL
**********************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "worldVariables.h"
#include "worldFunctions.h"

// create Original World
void createWorld(int **world) {
  int i, j, x, y;

    for(i=0; i<ROWS;i++) {
        for(j=0; j<COLS; j++) {
        // firstly populate the world with all humans
	  world[i][j] = 1;
        }
    }

    // next we add the zombies randomly in the world
    // 1/10 of population starts out as zombies
    
    // used for randomising cells
    time_t t;
    // time generator
    srand((unsigned) time(&t));

    // create and initialise
    int randomXCell=0;
    int randomYCell=0;
    int totalRandomCellCount = (ROWS*COLS)/10;

    for(i=0; i<totalRandomCellCount;i++)
      {
	randomXCell = ((float)rand()/(float)(RAND_MAX))*ROWS;
	randomYCell = ((float)rand()/(float)(RAND_MAX))*ROWS;
	//printf("random cell: [%d][%d]\n", randomXCell,randomYCell);
    world[randomXCell][randomYCell] = 0;
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
