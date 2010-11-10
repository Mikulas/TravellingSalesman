/*
 *  Solution.cpp
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/10/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include "Solution.h"

Solution::Solution()
{
}


Solution::Solution(Map map)
{
	vector<CITY> cities = map.getCities();
	vector<CITY> remaining = map.getCities();
	vector<CITY> temp;
	
	for (int c = 0; c < cities.size(); c++) {
		int key = rand() % remaining.size();
		// add city to path
		this->path[c] = remaining[key];

		// push all cities but this to temp 
		for (int i = 0; i < remaining.size(); i++) {
			if (i != key) {
				temp.push_back(remaining[i]);
			}
		}

		// push temp to remaining
		remaining.clear();
		for (int i = 0; i < temp.size(); i++) {
			remaining.push_back(temp[i]);
		}
		temp.clear();
	}
}


Solution::Solution(Solution s1, Solution s2)
{
	for (int c = 0; c < CITIES; c++) {
		if (c < CITIES / 2) {
			this->path[c] = s1.path[c];
		} else {
			this->path[c] = s2.path[c];
		}
	}
}


unsigned long Solution::getDistance(CITY city1, CITY city2)
{
	int dx = 0, dy = 0;
	dx = city1.x - city2.x;
	dy = city1.y - city2.y;
	return sqrt(dx^2 + dy^2);
}


unsigned long Solution::getFitness()
{
	int fitness = 0;
	for(int c = 0; c < CITIES - 1; c++) {
		fitness += getDistance(this->path[c], this->path[c + 1]);
	}
	return fitness;
}


void Solution::print()
{
	int perline = 0;
	for(int c = 0; c < CITIES - 1; c++) {
		printf("[%.3ld-%.3ld]", this->path[c].x , this->path[c].y);
		perline++;
		if (perline > 7) {
			cout << endl;
			perline = 0;
		}
	}
}
