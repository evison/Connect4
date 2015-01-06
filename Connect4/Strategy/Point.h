/********************************************************
*	Point.h : Class for a point on chess board         *
*	Yongfeng Zhang                                     *
*	zhangyf07@gmail.com                                 *
*	2015.1                                              *
*********************************************************/

#ifndef POINT_H_
#define POINT_H_

class Point{
public:
	int x;
	int y;

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

#endif
