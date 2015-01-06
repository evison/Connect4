/********************************************************
*	Strategy.h : Interfaces for the strategy           *
*	Yongfeng Zhang                                     *
*	zhangyf07@gmail.com                                 *
*	2015.1                                              *
*********************************************************/

#ifndef STRATEGY_H_
#define	STRATEGY_H_

#include "Point.h"

extern "C" __declspec(dllexport) Point* getPoint(const int M, const int N, const int* top, const int* _board, 
	const int lastX, const int lastY, const int noX, const int noY);

extern "C" __declspec(dllexport) void clearPoint(Point* p);

void clearArray(int M, int N, int** board);

/*
	Add your own supporting functions
*/


#endif