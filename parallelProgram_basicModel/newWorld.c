/*
*******************************
BASIC MODEL - PARALLEL
*******************************
*/

#include <stdio.h>
#include <pthread.h>
#include "worldVariables.h"
#include "worldFunctions.h"

// create a new World
void newWorld(int **tempWorld, int currentState, int zomNeighbors, int humNeighbors, int x, int y) {

    int newCellstate=0;

    // if Human and less than 1 human neighbor
    if((currentState==1) && (humNeighbors <1)) {
      // human dies of natural causes
        newCellstate = 2;
    }

    // if Human
    if(currentState==1) {
       // 17.5% chance of turning into a zombie per zombie neighbor
       float zChance = 17.5;
       // 10% chance of staying human per human neighbor
       float hChance = 10.0;

       // calculations
       float zombieChance = zomNeighbors * zChance;
       float humanChance = humNeighbors * hChance;

       
       if (zombieChance > humanChance) {
	 // turn into Zombie
            newCellstate = 0;
       }

       if (humanChance > zombieChance) {
	 // stay human
            newCellstate = 1;
       }
       
       if (zombieChance > 120) {
	 // human killed by zombies
	 newCellstate = 3;
       }	 
    }

    // if Zombie
    if(currentState==0) {
      // 20% chance of staying a zombie per zombie neighbor
      float zChance = 20.0;
      // 10% chance of being killed by a human per human neighbor
       float hChance = 10.0;

       // calculations
       float zombieChance = zomNeighbors * zChance;
       float humanChance = humNeighbors * hChance;

       if (zombieChance > humanChance) {
	 // stay zombie
            newCellstate = 0;
       }

       if (humanChance > zombieChance) {
	 // killed by humans
            newCellstate = 2;
       }
    }

    // if Human that died from natural causes and/or Zombie killed by human
    if(currentState==2) {
      // stay the same state (dead)
      newCellstate=2;
    }

    // if previously Human but was killed by Zombie attack
    if(currentState==3) {
      // dead Human resurrected into Zombie
        newCellstate=0;
    }

    //printf("New Cell State for [%d][%d] is: %d\n", x, y, newCellstate);
    tempWorld[x][y] = newCellstate;
}
