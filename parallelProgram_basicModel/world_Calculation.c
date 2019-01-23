/*
**********************************
BASIC MODEL - PARALLEL
**********************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "worldFunctions.h"
#include "worldVariables.h"

void* world_Calculation(void * rank) {

  long my_rank = (long) rank;
  long long x, y;
  long long my_n = size/thread_count;
  long long my_first_x = my_n * my_rank;
  long long my_last_x = my_first_x + my_n;

  int cellState;
  int zombieNeighbors;
  int humanNeighbors;

  for(x = my_first_x; x < my_last_x; x++) {
    for(y = 0; y < COLS; y++) {

      //printf("Thread %ld looking after first row %ld to last row %ld\n", my_rank, my_first_x, my_last_x);

      cellState = stateCheck(world, x, y);
      zombieNeighbors = zombieNeighborCount(world, x, y);
      humanNeighbors = humanNeighborCount(world, x, y);
      
      pthread_mutex_lock(&mutex1);
      newWorld(tempWorld, cellState, zombieNeighbors, humanNeighbors, x, y);
      pthread_mutex_unlock(&mutex1);
      
    }
  }

  return NULL;
}
