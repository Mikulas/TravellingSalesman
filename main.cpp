// http://en.wikipedia.org/wiki/Traveling_salesman_problem


#include <iostream>
#include <string.h>
#include "Map.h"
#include "Solution.h"
#include "City.h"
#include "config.h"

using namespace std;



int main (int argc, char * const argv[])
{
	Map map = Map(MAP_WIDTH, MAP_HEIGHT);

	cout << " - - - Traveling salesman - - - " << endl << endl;

	for (int i; i < CITIES;) {
		if (map.addCity(rand() % MAP_WIDTH, rand() % MAP_HEIGHT)) {
			i++;
		}
	}
	
	map.print();
	
	Solution generation[GENERATION_SIZE];
	Solution nextGeneration[GENERATION_SIZE];
	
	// randomize first generation
	for (int s = 0; s < GENERATION_SIZE; s++) {
		generation[s] = Solution(map);
	}
	
	// evolution
	for (int g = 0; g < GENERATION_COUNT; g++) {
		for (int s; s < GENERATION_SIZE; s += 2) {
			nextGeneration[s] = Solution(generation[s], generation[s + 1]);
			nextGeneration[s + 1] = Solution(generation[s + 1], generation[s]);
		}
		
		// move new generation solutions into the old one
		for (int s; s < GENERATION_SIZE; s += 2) {
			generation[s] = nextGeneration[s];
		}
	}
	
	// get best solution from last generation
	Solution solution;
	unsigned long highestFitness = LONG_LONG_MAX;
	for (int s = 0; s < GENERATION_SIZE; s++) {
		if (highestFitness > generation[s].getFitness()) {
			solution = generation[s];
			highestFitness = generation[s].getFitness();
		}
	}
	
	// print best found solution
	cout << endl << " - - - SOLUTION - - - " << endl;
	cout << "fitness: " << solution.getFitness() << endl;
	solution.print();
	
	return 0;
}
