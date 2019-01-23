/*
*************************************
LATENT/INFECTED MODEL - SERIAL
*************************************
 */

#include "worldFunctions.h"
#include "worldVariables.h"

// check the current Human or Zombie state of each cell
// counts total number of humans and zombies in the World
int stateCheck(int **world, int x, int y) {

    int currentCellState;

    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++){
            // loop through and find if current cell is human, zombie or dead
            currentCellState = world[x][y];

           }
        }

    return currentCellState;
}
