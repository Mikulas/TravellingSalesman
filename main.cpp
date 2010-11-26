// http://en.wikipedia.org/wiki/Traveling_salesman_problem


#include <iostream>
#include <string.h>
#include "Map.h"
#include "Solution.h"
#include "City.h"
#include "Generation.h"
#include "config.h"

using namespace std;



int main (int argc, char * const argv[])
{
	Log dump = Log();
	
	Map map = Map(MAP_WIDTH, MAP_HEIGHT);
	
	if (GENERATION_SIZE % 2 != 0) {
		cout << "NotImplementedException thrown @ main.cpp: rulette merging not available";
		exit(2);
	}
	if (RAND_MAX < GENERATION_SIZE) {
		cout << "NotImplementedException thrown @ main.cpp: rulette merging implemntation requires randomom number to be available for each entity in single generation";
		exit(3);
	}

	cout << " - - - Traveling salesman - - - " << endl << endl;

	for (int i; i < CITIES;) {
		if (map.addCity(rand() % MAP_WIDTH, rand() % MAP_HEIGHT)) {
			i++;
		}
	}
	
	map.print();

	// randomize first generation
	dump << "randomize first generation";
	Generation generation(map);
	
	// evolution
	for (int g = 0; g < GENERATION_COUNT; g++) {
		// this should merge with best fitness
		cout << "\rcomputing generation " << g + 1 << " out of " << GENERATION_COUNT << "...";
		generation = Generation(generation, true);
	}
	
	cout << "\n";
	
	Solution solution = generation.getBestSolution();
	
	// print best found solution
	cout << endl << " - - - SOLUTION - - - " << endl;
	cout << "fitness: " << solution.getFitness() << endl;
	solution.print();
	cout << endl << endl;
	
	return 0;
}
