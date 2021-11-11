#pragma once
#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0): xpos(x), ypos(y){}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const { cout << '[' << xpos << ", " << ypos << ']' << endl; }
};