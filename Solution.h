#pragma once
/*
 *  Solution.h
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/10/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector.h>
#include "Map.h"
#include "City.h"
#include "config.h"


using namespace std;


class Solution
{
private:
	CITY path[CITIES];
	unsigned long getDistance(CITY, CITY);
public:
	Solution();
	Solution(Map);
	Solution(Solution, Solution);
	Solution(CITY[CITIES]);
	unsigned long getFitness();
	void print();
};
