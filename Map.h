#pragma once
/*
 *  Map.h
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/10/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector.h>
#include "City.h"
#include "config.h"


class Map
{
private:
	int width;
	int height;
	bool content[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int, int);
	bool addCity(int, int);
	Map print();
	vector<CITY> getCities();
};
