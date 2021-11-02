#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x=0, int y=0): xpos(x), ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

/* TODO: operator>> */

istream& operator>>(istream& is, Point& pos) {
	
	is >> pos.xpos >> pos.ypos;
	return is;
}

int main() {
	cout << "-----예제-----" << endl;
	Point pos1(1, 3);
	cout << pos1;
	Point pos2(101, 303);
	cout << pos2;
	
	cout << "-----문제-----" << endl;
	Point pos3;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos3;
	cout << pos3;

	Point pos4;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos4;
	cout << pos4;

	return 0;
}