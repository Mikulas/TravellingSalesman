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
	Log dump = Log();
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
	
	dump << "\tnew random solution:\n";
	for (int c = 0; c < CITIES; c++) {
		dump << "\t\t" << this->path[c].x + 1 << "; " << this->path[c].y + 1 << "\n";
	}
}


Solution::Solution(Solution s1, Solution s2)
{
	Log dump = Log();
	int preference = CITIES / 2;
	
	vector<CITY> cities;
	for (int i = 0; i < CITIES; i++) {
		cities.push_back(s1.path[i]);
	}
	
	// take first half from the first solution
	for (int c = 0; c < preference; c++) {
		this->path[c] = s1.path[c];
		for (int i = 0; i < cities.size(); i++) {
			if (cities[i].x == s1.path[c].x && cities[i].y == s1.path[c].y) {
				cities.erase(cities.begin() + i);
			}
		}
	}
	
	int index = preference;
	// compute the second half as remaining cities in order of second solution	
	for (int i = 0; i < CITIES; i++) {
		for (int c = 0; c < cities.size(); c++) {
			if (s2.path[i].x == cities[c].x && s2.path[i].y == cities[c].y) {
				this->path[index] = s2.path[i];
				index++;
				break;
			}
		}
	}
	
	dump << "new solution by merge:\n";
	for (int i = 0; i < CITIES; i++) {
		dump << "\t" << this->path[i].x + 1 << "; " << this->path[i].y + 1 << "\n";
	}
}


double Solution::getDistance(CITY city1, CITY city2) const
{
	double dx = 0, dy = 0;
	dx = abs((long) (city1.x - city2.x));
	dy = abs((long) (city1.y - city2.y));
	return sqrt(dx * dx + dy * dy);
}


double Solution::getFitness() const
{
	// this needs caching
	double fitness = 0;
	for(int c = 0; c < CITIES - 1; c++) {
		fitness += getDistance(this->path[c], this->path[c + 1]);
	}	
	return fitness;
}


void Solution::print()
{
	int perline = 0;
	for(int c = 0; c < CITIES; c++) {
		printf("[\033[32m%.3ld\033[0m; \033[32m%.3ld\033[0m]", this->path[c].x + 1, this->path[c].y + 1);
		if (c != CITIES - 1) {
			cout << ", ";
		}
		
		perline++;
		if (perline > 7) {
			cout << endl;
			perline = 0;
		}
	}
}
