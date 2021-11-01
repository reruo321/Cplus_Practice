#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x=0, int y=0): xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point& operator-() {
		xpos *= -1;
		ypos *= -1;
		return *this;
	}

	friend Point& operator--(Point& ref);
	friend Point& operator~(Point& ref);
};

Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point& operator~(Point& ref) {
	ref.xpos = ~ref.xpos;
	ref.ypos = ~ref.ypos;
	return ref;
}

int main() {
	Point pos(1, 2);

	cout << "-----예시-----" << endl;
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition();

	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	
	cout << "-----1번 문제-----" << endl;
	pos.ShowPosition();
	Point pos2 = -pos;
	pos2.ShowPosition();
	
	cout << "-----2번 문제-----" << endl;
	pos.ShowPosition();
	Point pos3 = ~pos;
	pos3.ShowPosition();

	return 0;
}
