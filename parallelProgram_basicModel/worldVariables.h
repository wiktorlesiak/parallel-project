/*
*********************************
BASIC MODEL - PARALLEL
*********************************
 */
#define ZOMBIE 0    // zombie
#define HUMAN 1    // human being
#define DEADTYPE_1 2 // human died of natural causes and zombie killed
#define DEADTYPE_2 3 // human dies after zombie attack


// WORLD SIZE
int ROWS;
int COLS;
// iteration of worlds
int iteration;
// the main world
int **world;
// the temp world (used to store new state before transferring to main world)
int **tempWorld;
// count number of humans per world cycle
int totalHumanWorldCount;
// count number of zombies per world cycle
int totalZombieWorldCount;
// count number of dead(human natural causes or killed zombies) per world cycle
int totalDeadWorldCount;
// count number of dead Humans to turn into Zombies next cycle
int totalHumanToTurnZombieCount;
// size used for world size for zombie & human count
int size;
// thread-count
int thread_count;
// mutex lock
pthread_mutex_t mutex1;
