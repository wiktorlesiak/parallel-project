/*
**************************************
LATENT/INFECTED MODEL - SERIAL
**************************************
*/

#include "worldFunctions.h"
#include "worldVariables.h"

// count number of Zombie neighbors in Moore neighborhood
int zombieNeighborCount(int **world, int x, int y) {

    int i = x;
    int j = y;

    
    int neighbor1, neighbor2, neighbor3, neighbor4, neighbor5, neighbor6, neighbor7, neighbor8;
    int zombieCounter=0;

    // NorthWest Neighbor
    neighbor1 = world[(((i-1)+size)%size)][(((j-1)+size)%size)];
    // North Neighbor
    neighbor2 = world[(((i-1)+size)%size)][j];
    // NorthEast Neighbor
    neighbor3 = world[(((i-1)+size)%size)][(j+1)%size];
    // West Neighbor
    neighbor4 = world[(i)][(((j-1)+size)%size)];
    // East Neighbor
    neighbor5 = world[(i)][(j+1)%size];
    // SouthWest Neighbor
    neighbor6 = world[((i+1)%size)][(((j-1)+size)%size)];
    // South Neighbor
    neighbor7 = world[((i+1)%size)][j];
    // SouthEast Neighbor
    neighbor8 = world[((i+1)%size)][(j+1)%size];

    // create a neighboorhood array to hold all the 8 neighbors
    int neighborhood[8] = {neighbor1, neighbor2, neighbor3, neighbor4, neighbor5, neighbor6, neighbor7, neighbor8};

    // create a loop to check through each of 8 neighbors to check if human or zombie and count them
    for(int n=0; n<8; n++) {
        // check if Human (0) state, print and increase Human counter
        if(neighborhood[n]==0) {
           zombieCounter++;
              }
           }

    return zombieCounter;
}
