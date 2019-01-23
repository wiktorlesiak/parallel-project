########################
# BASIC MODEL - SERIAL
########################

#makefile for serial BASIC_MODEL program

mainSerialZombieBasicProgram: mainSerialZombie_basic_Program.c createWorld.o humanNeighborCount.o zombieNeighborCount.o stateCheck.o newWorld.o printWorld.o print_to_file.o worldHeadCount.o worldFunctions.h worldVariables.h
	gcc mainSerialZombie_basic_Program.c createWorld.o humanNeighborCount.o zombieNeighborCount.o stateCheck.o newWorld.o printWorld.o print_to_file.o worldHeadCount.o -o mainSerialBasicProgram

createWorld.o: createWorld.c worldFunctions.h worldVariables.h
	gcc -c createWorld.c

humanNeighborCount.o: humanNeighborCount.c worldFunctions.h worldVariables.h
	gcc -c humanNeighborCount.c

zombieNeighborCount.o: zombieNeighborCount.c worldFunctions.h worldVariables.h
	gcc -c zombieNeighborCount.c

stateCheck.o: stateCheck.c worldFunctions.h worldVariables.h
	gcc -c stateCheck.c

newWorld.o: newWorld.c worldFunctions.h worldVariables.h
	gcc -c newWorld.c

printWorld.o: printWorld.c worldFunctions.h worldVariables.h
	gcc -c printWorld.c

print_to_file.o: print_to_file.c worldFunctions.h worldVariables.h
	gcc -c print_to_file.c

worldHeadCount.o: worldHeadCount.c worldFunctions.h worldVariables.h
	gcc -c worldHeadCount.c
