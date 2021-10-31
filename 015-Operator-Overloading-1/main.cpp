#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);

	/* TODO: Overload operator+= and operator-= as member functions */

	Point& operator+=(const Point& ref) {
		Point pos(xpos += ref.xpos, ypos += ref.ypos);
		return pos;
	}

	Point& operator-=(const Point& ref) {
		Point pos(xpos -= ref.xpos, ypos -= ref.ypos);
		return pos;
	}

};

Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

/* TODO: Overload operator- as global function */

Point operator- (const Point & pos1, const Point & pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

/* TODO: Overload operator== and operator!= as global functions */

bool operator==(const Point& pos1, const Point& pos2) {
	if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos))
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2) {
	if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos))
		return false;
	else
		return true;
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;
	Point pos4 = pos1 - pos2;

	cout << "-----예시-----" << endl;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	cout << "-----1번 문제-----" << endl;

	pos4.ShowPosition();

	cout << "-----2번 문제-----" << endl;

	pos1.ShowPosition();
	pos1.operator+=(pos2);
	pos1.ShowPosition();
	pos1.operator-=(pos2);
	pos1.ShowPosition();

	cout << "-----3번 문제-----" << endl;

	Point pos5(3, 4);
	bool bool1 = pos1 == pos5;
	bool bool2 = pos1 == pos2;
	cout << bool1 << endl;
	cout << bool2 << endl;

}