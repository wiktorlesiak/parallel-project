/*
*************************************
BASIC MODEL - SERIAL
*************************************
*/

// create new world
void createWorld(int **world);
// check if human or zombie of a specific cell (current cell)
int stateCheck(int **world, int x, int y);
// check zombie neighbors of a current cell
int zombieNeighborCount(int **world, int x, int y);
// check human neighbors of a current cell
int humanNeighborCount(int **world, int x, int y);
// create new world using temp world (not to overwrite current world), cellState, neighbors and position
void newWorld(int **tempWorld, int currentState, int zomNeighbors, int humNeighbors, int x, int y);
// head count of humans/zombies/dead in new/temp world
void worldHeadCount(int **world);
// print any world
void printWorld(int **theworld);
// print to a file
void print_to_file(int **theworld);
