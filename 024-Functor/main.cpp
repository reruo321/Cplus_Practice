#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;

public:
	Point(int x=0, int y=0): xpos(x), ypos(y){}
	Point operator+(const Point &ref) const {
		return Point(xpos + ref.xpos, ypos + ref.ypos);
	}
	friend ostream& operator<<(ostream &os, const Point& ref);
};

ostream& operator<<(ostream& os, const Point& ref) {
	cout << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
	return os;
}

class Adder {
public:
	int operator()(const int &x, const int &y) {
		return x + y;
	}
	double operator()(const double& x, const double& y) {
		return x + y;
	}
	Point operator()(const Point& x, const Point& y) {
		return x + y;
	}
};

int main() {
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(1, 2), Point(3, 4)) << endl;

	return 0;
}