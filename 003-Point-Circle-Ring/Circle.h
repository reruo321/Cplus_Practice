#ifndef __CIRCLE_H_
#define __CIRCLE_H_
#include "Point.h"

class Circle
{
private:
	Point mid_point;
	int radius;
public:
	Circle(int x, int y, int r) : mid_point(x, y), radius(r) {}
	void ShowCircleInfo() const;
};

#endif