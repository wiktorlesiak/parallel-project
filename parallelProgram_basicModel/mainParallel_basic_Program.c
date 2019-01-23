/*
**************************************
BASIC MODEL - PARALLEL
**************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "worldFunctions.h"
#include "worldVariables.h"
#include "timer.h"

int main(int argc, char *argv[]) {

 if(argc == 3) {

  // make rows and columns size as per command line entry
  ROWS = atoi(argv[1]);
  COLS = atoi(argv[1]);
  // make thread count number as per command line entry
  thread_count = atoi(argv[2]);

  // timer
  // clocks_t clock(void) - returns number of clocks ticks elapsed since program launched
  double start, finish, time_elapsed;

  // start the clock
  GET_TIME(start);

  // size of world for neighborhood counts
  size=ROWS;
  // start at zero for world iteration count
  iteration = 0;

  // initialising it to zero for world iteration 0
  totalDeadWorldCount=0;
  totalHumanWorldCount=0;
  totalZombieWorldCount=0;
  totalHumanToTurnZombieCount=0;

  // for thread rank, use long in case of 64 bit system
  long thread;
  // declare array of pthread structures
  pthread_t *thread_handles;
  // allocate memory for child threads
  thread_handles = malloc(thread_count *sizeof(pthread_t));
  // initialise mutex lock
  // we don't use the second argument so pass NULL to it
  pthread_mutex_init(&mutex1, NULL);
  
  int i;
  time_t t;

  srand((unsigned) time(&t)); // time generator

  // allocate memory for the world & tempWorld - 2D Arrays
  world = malloc(ROWS * sizeof (*world));
  tempWorld = malloc(ROWS * sizeof (*tempWorld));
  for (i=0; i<ROWS; i++)
    {
      world[i] = malloc(COLS * sizeof (*world[i]));
      tempWorld[i] = malloc(COLS * sizeof (*tempWorld[i]));
    }

  // create a random world of 0(Zombies) and 1(Humans)
  createWorld(world);
  //printWorld(world);
  printf("Human Count: %d\nZombie World Count: %d\n", totalHumanWorldCount, totalZombieWorldCount);
  print_to_file(world);

  // keep iterating until no humans left
  while (totalHumanWorldCount != 0) {
    
    // create the child threads and pass the child thread to function
    for(thread=0; thread < thread_count; thread++) {
      pthread_create(&thread_handles[thread], NULL, world_Calculation, (void*) thread);
    }

    // join function waits for mythread to complete
    for(thread=0; thread < thread_count; thread++)
      pthread_join(thread_handles[thread], NULL);
    printf("****************\n");
    printf("Threads finished world iteration\n");
    printf("****************\n");
    
  // make tempworld to newworld
  world = tempWorld;
  //printWorld(world);
  //do a head count of new world
  worldHeadCount(world);
  printf("Human Count: %d\nZombie World Count: %d\nDead World Count: %d\nHumanKilledByZombie: %d\n", totalHumanWorldCount, totalZombieWorldCount, totalDeadWorldCount, totalHumanToTurnZombieCount);
  // print world to file
  print_to_file(world);
   
  }
  // stop the clock
  GET_TIME(finish);
  // to get number of seconds divide by clocks_per_sec
  time_elapsed = finish-start;
  printf("Elapsed time = %f seconds\n", time_elapsed); 
 }

  else if(argc > 3 || argc < 3) {
    printf("input number for ROWS(COLS) and threads along with program name\n");
  }

  else {
    printf("incorrect commands used\n");
  }

  free(world);
  /* do not need to free up tempWorld as by making world=tempWorld the pointers point
     to same region in memory
     Trying to free up tempWorld separately gives double free or corruption error as
     attempting to free already freed memory
  */
    
 return 0;
}
