/*
**************************************
LATENT/INFECTED MODEL - SERIAL
**************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "worldVariables.h"
#include "worldFunctions.h"

// print world values to a text file
void print_to_file(int **world){
  
    struct stat st = {0};
    // size of characters needed to form file path name
    char path[100];
    FILE *fp = NULL;
    int i,j;

    // checks if the directory exists, if not it creates the directory
    if (stat("world_iterations", &st) == -1){
      mkdir("world_iterations", 0777);
    }

    // allows to add iteration value to each path
    sprintf(path,"world_iterations/%d.text", iteration);

    // create and open file for writing
    fp = fopen(path, "w");

    // loop to print world into text file
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            fprintf(fp,"%d", world[i][j]);
        }
    }

    // close file
    fclose(fp);

    printf("Printed LatentModel_Iteration to File Number %d!\n", iteration);
    iteration++;
}
