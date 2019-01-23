/*
*******************************
BASIC MODEL - PARALLEL
*******************************
*/

#include <stdio.h>
#include <pthread.h>
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
    //printf("ZombieValue of NorthWest neighbor [1] is: %d\n", neighbor1);
    // North Neighbor
    neighbor2 = world[(((i-1)+size)%size)][j];
    //printf("ZombieValue of North neighbor (2) is: %d\n", neighbor2);
    // NorthEast Neighbor
    neighbor3 = world[(((i-1)+size)%size)][(j+1)%size];
    //printf("ZombieValue of NorthEast neighbor (3) is: %d\n", neighbor3);
    // West Neighbor
    neighbor4 = world[(i)][(((j-1)+size)%size)];
    //printf("ZombieValue of West neighbor (4) is: %d\n", neighbor4);
    // East Neighbor
    neighbor5 = world[(i)][(j+1)%size];
    //printf("ZombieValue of East neighbor (5) is: %d\n", neighbor5);
    // SouthWest Neighbor
    neighbor6 = world[((i+1)%size)][(((j-1)+size)%size)];
    //printf("ZombieValue of SouthWest neighbor (6) is: %d\n", neighbor6);
    // South Neighbor
    neighbor7 = world[((i+1)%size)][j];
    //printf("ZombieValue of South neighbor (7) is: %d\n", neighbor7);
    // SouthEast Neighbor
    neighbor8 = world[((i+1)%size)][(j+1)%size];
    //printf("ZombieValue of SouthEast neighbor (8) is: %d\n", neighbor8);

    //printf("Finding Neighborhood of Cell[%d][%d]:\n", i,j);
    //printf("%d\t %d\t %d\n", neighbor1, neighbor2, neighbor3);
    //printf("%d\t \t %d\n", neighbor4, neighbor5);
    //printf("%d\t %d\t %d\n", neighbor6, neighbor7, neighbor8);


    // create a neighboorhood array to hold all the 8 neighbors
    int neighborhood[8] = {neighbor1, neighbor2, neighbor3, neighbor4, neighbor5, neighbor6, neighbor7, neighbor8};

    // create a loop to check through each of 8 neighbors to check if human or zombie and count them
    for(int n=0; n<8; n++) {
        // check if Human (0) state, print and increase Human counter
        if(neighborhood[n]==0) {
           zombieCounter++;
              }
           }

        // print which cell and how many zombie neighbors they have
    // printf("Function: Zombie Neighbors of Cell[%d][%d] is: %d\n", i,j, zombieCounter);


    return zombieCounter;
}
