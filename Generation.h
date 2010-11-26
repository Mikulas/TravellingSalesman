#pragma once
/*
 *  Generation.h
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/26/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector.h>
#include "Map.h"
#include "Solution.h"


using namespace std;


class Generation
{
private:
	Solution solutions[GENERATION_SIZE];
	vector<Solution> ordered;
public:
	Generation();
	Generation(Map);
	Generation(Generation, bool);
	Solution getSolution();
	Solution getBestSolution();
	vector<Solution> getSolutionsByFitness();
};
