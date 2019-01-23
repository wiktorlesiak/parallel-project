/*
***********************************
LATENT/INFECTED MODEL - SERIAL
***********************************
*/

#include "worldFunctions.h"
#include "worldVariables.h"

// count number of Zombies, Humans and Dead per each world cycle
void worldHeadCount(int **world) {
    // count the number of Humans and Zombies at the creation of the world
    int currentCellState, x, y;

    // restart each world with zero count
    totalDeadWorldCount=0;
    totalHumanToTurnZombieCount=0;
    totalHumanWorldCount=0;
    totalZombieWorldCount=0;
    totalInfectedHumansCount=0;
    
    for(x=0; x<ROWS;x++) {
        for(y=0; y<COLS; y++) {

        currentCellState = world[x][y];

	// zombie count
            if(currentCellState==0) {
                totalZombieWorldCount++;
            }
	    // human count
            if(currentCellState==1) {
                totalHumanWorldCount++;
            }
	    // dead count
            if(currentCellState==2) {
                totalDeadWorldCount++;
            }
	    // humans to be resurrected to zombies count
            if(currentCellState==3) {
                totalHumanToTurnZombieCount++;
            }

	    // Infected humans (latent period)
	    if(currentCellState==4) {
	      totalInfectedHumansCount++;
	    }
        }
    }
}
