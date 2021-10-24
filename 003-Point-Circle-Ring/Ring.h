#ifndef __RING_H_
#define __RING_H_
#include "Circle.h"

class Ring
{
private:
	Circle a;
	Circle b;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2);
	void ShowRingInfo() const;
};

#endif