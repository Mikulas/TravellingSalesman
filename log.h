#pragma once
/*
 *  log.h
 *  TravellingSalesman
 *
 *  Created by Mikulas Dite on 11/25/10.
 *  Copyright 2010 GChD. All rights reserved.
 *
 */

#include <string>

#define DEBUG 0


using namespace std;


/** @todo fix passing std::endl */
class Log {
public:
	template<class T>
	friend Log& operator<<(Log &log, const T& t)
	{
		if (DEBUG == 1) {
			cout << t;
		}
		return log;
	}
};


//Log dump = Log();
