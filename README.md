  # Parallel Computing project 

This project introduces a simulation for the zombie infection outbreak based on the cellular automaton model. The simulation takes place in a 2-dimensional array made of cells. For human in order to become zombie, they must get infected by zombies that located in their neighborhood.  
Cellular automata divides the world into cells, each cell will start as either Human or Zombie which are affected by the neighbours according to set rules. Rules are applied in every generation and all cells in each generation are affected simultaneously.   The Rules will impact on the state of the cell and could change cell to Human, Zombie or Dead (and in the case of Latent Model infected).
There are many zombie outbreak models our main focus was on Basic and Latent Infection models.

<img src="https://i.imgur.com/yZel5sB.png">

<img src="https://i.imgur.com/vDxGTB3.png">


| Thread Count   | Time Taken (seconds)  |
| :------------ |:---------------:|
| 1     | 2592  |
| 2     | 1364        |
| 4     | 700        |
| 8     | 647        |
