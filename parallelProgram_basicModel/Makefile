###########################
# BASIC MODEL - PARALLEL
###########################

#makefile for parallel BASIC_MODEL program

mainParallel_basic_Program: mainParallel_basic_Program.c createWorld.o humanNeighborCount.o zombieNeighborCount.o stateCheck.o newWorld.o printWorld.o print_to_file.o worldHeadCount.o world_Calculation.o worldFunctions.h worldVariables.h timer.h
	gcc mainParallel_basic_Program.c createWorld.o humanNeighborCount.o zombieNeighborCount.o stateCheck.o newWorld.o world_Calculation.o printWorld.o print_to_file.o worldHeadCount.o -lpthread -o mainParallel_basic_Program

createWorld.o: createWorld.c worldFunctions.h worldVariables.h
	gcc -c createWorld.c -lpthread

humanNeighborCount.o: humanNeighborCount.c worldFunctions.h worldVariables.h
	gcc -c humanNeighborCount.c -lpthread

zombieNeighborCount.o: zombieNeighborCount.c worldFunctions.h worldVariables.h
	gcc -c zombieNeighborCount.c -lpthread

stateCheck.o: stateCheck.c worldFunctions.h worldVariables.h
	gcc -c stateCheck.c -lpthread

newWorld.o: newWorld.c worldFunctions.h worldVariables.h
	gcc -c newWorld.c -lpthread

world_Calculation: world_Calculation.c header.h
	gcc -c world_Calculation.c -lpthread

printWorld.o: printWorld.c worldFunctions.h worldVariables.h
	gcc -c printWorld.c -lpthread

print_to_file.o: print_to_file.c worldFunctions.h worldVariables.h
	gcc -c print_to_file.c -lpthread

worldHeadCount.o: worldHeadCount.c worldFunctions.h worldVariables.h
	gcc -c worldHeadCount.c -lpthread
