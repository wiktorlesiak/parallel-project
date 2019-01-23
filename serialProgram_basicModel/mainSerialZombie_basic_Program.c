/*
**************************************
BASIC MODEL - SERIAL
**************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "worldFunctions.h"
#include "worldVariables.h"

int main(int argc, char* argv[]) {

    if(argc==2) {
    int i;
    time_t t;

    // timer
    // clocks_t clock(void) - returns number of clocks ticks elapsed since program launched
    clock_t start, finish;
    double time_elapsed;
    
    // make rows and columns size as per command line entry
    ROWS = atoi(argv[1]);
    COLS = atoi(argv[1]);

    // start the clock
    start = clock();
    
    // size of world for neighborhood counts
    size=ROWS;
    // start at zero for world iteration count
    iteration = 0;

    // initialising it to zero for world iteration 0
    totalDeadWorldCount=0;
    totalHumanWorldCount=0;
    totalZombieWorldCount=0;
    totalHumanToTurnZombieCount=0;
    
    // time generator
    srand((unsigned) time(&t));

    // allocate memory for the two worlds
    world = malloc(ROWS * sizeof (*world));
    tempWorld = malloc(ROWS * sizeof (*tempWorld));
    for (i=0; i<ROWS; i++)
    {
        world[i] = malloc(COLS * sizeof (*world[i]));
        tempWorld[i] = malloc(COLS * sizeof (*tempWorld[i]));
    }

    
    // create a random world of 0(Zombies) and 1(Humans)
    createWorld(world);
    printf("Human Count: %d\nZombie World Count: %d\n", totalHumanWorldCount, totalZombieWorldCount);
    print_to_file(world);

    // keep iterating until no humans left
    while (totalHumanWorldCount != 0) {

    int cellState;
    int zombieNeighbors;
    int humanNeighbors;

    for(int x=0; x<COLS; x++) {
        for(int y=0; y<COLS; y++) {

	  // check individual state of each cell (whether it zombie/human/dead)
            cellState = stateCheck(world, x, y);
            // check zombies numbers in neighborhood
            zombieNeighbors = zombieNeighborCount(world, x, y);
            // check human numbers in neighborhood
            humanNeighbors = humanNeighborCount(world, x, y);
            // create new world
            newWorld(tempWorld, cellState, zombieNeighbors, humanNeighbors, x, y);
            }
        }

    // make tempworld to newworld
    world = tempWorld;
    //do a head count of new world
    worldHeadCount(world);
    printf("Human Count: %d\nZombie World Count: %d\nDead World Count: %d\nHumanKilledByZombie: %d\n", totalHumanWorldCount, totalZombieWorldCount, totalDeadWorldCount, totalHumanToTurnZombieCount);
    // print world to file
    print_to_file(world);

        }
    // stop the clock
    finish = clock();
    // to get number of seconds divide by clocks_per_sec
    time_elapsed = ((double) (finish-start)) / CLOCKS_PER_SEC;
    printf("Elapsed time = %f seconds\n", time_elapsed);
    }
    
    else {
    printf("not the correct arguments supplied at command line\nenter a number for rows/cols for world size\n");
    }
        
    free(world);
    /* do not need to free up tempWorld as by making world=tempWorld the pointers point
       to same region in memory
       Trying to free up tempWorld separately gives double free or corruption error as
       attempting to free already freed memory
    */
    
    return 0;
}
