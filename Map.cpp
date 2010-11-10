/*
 *  Map.cpp
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/10/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include "Map.h"


Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;
	
	for (int w = 0; w < width; w++) {
		for (int h = 0; h < height; h++) {
			this->content[w][h] = false;
		}
	}
}


bool Map::addCity(int x, int y)
{
	if (this->content[x][y]) {
		return false;
	} else {
		return this->content[x][y] = true;
	}
}


Map Map::print()
{
	// x axis labels
	cout << "      ";
	char buffer[3];
	for (int w = 0; w < MAP_WIDTH; w++) {
		sprintf(buffer, "%d", w);
		cout << buffer[0] << " ";
	}
	cout << endl;
	cout << "      ";
	for (int w = 0; w < MAP_WIDTH; w++) {
		if (sprintf(buffer, "%d", w) != 2) {
			buffer[1] = ' ';
		}
		cout << buffer[1] << " ";
	}
	cout << endl;

	// content
	for (int h = 0; h < MAP_HEIGHT; h++) {
		printf("%.4d:", h);
		
		for (int w = 0; w < MAP_WIDTH; w++) {
			cout << " " << (this->content[h][w] ? "⌂" : ".");
		}
		cout << endl;
	}
	return *this;
}


vector<CITY> Map::getCities()
{
	vector<CITY> cities;
	for (int h = 0; h < MAP_HEIGHT; h++) {
		for (int w = 0; w < MAP_WIDTH; w++) {
			if (this->content[h][w]) {
				CITY city;
				city.x = w;
				city.y = h;
				cities.push_back(city);
			}
		}
	}
	return cities;	
}
