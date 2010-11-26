/*
 *  Generation.cpp
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/26/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include "Generation.h"


Generation::Generation()
{
}


Generation::Generation(Map map)
{
	for (int s = 0; s < GENERATION_SIZE; s++) {
		this->solutions[s] = Solution(map);
	}
}


Generation::Generation(Generation ancestors, bool debug)
{
	for (int s = 0; s < GENERATION_SIZE; s++) {
		this->solutions[s] = Solution(ancestors.solutions[s], ancestors.getSolution());
	}
}


Solution Generation::getSolution()
{
	//return this->solutions[0];
	// solutions with better fitness are more likely to be returned

	int base = rand() % (GENERATION_SIZE - 1);
	int key = -1 * (double) (base * base) / (double) GENERATION_SIZE + (double) GENERATION_SIZE - 1;// + GENERATION_SIZE;	

	return this->getSolutionsByFitness()[key];
}


vector<Solution> Generation::getSolutionsByFitness()
{
	// get rulette solution
	// use exponential function
	
	// caching
	if (this->ordered.size() == 0) {
		for (int i = 0; i < GENERATION_SIZE; i++) {
			this->ordered.push_back(this->solutions[i]);
		}
		sort(this->ordered.begin(), this->ordered.end());
	}
	
	return this->ordered;
}

Solution Generation::getBestSolution()
{
	return this->getSolutionsByFitness()[0];
}
