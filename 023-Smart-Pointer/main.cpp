#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0): xpos(x), ypos(y){
		cout << "Æ÷ÀÎÆ® °´Ã¼ »ý¼º" << endl;
	}
	~Point() {
		cout << "Æ÷ÀÎÆ® °´Ã¼ ¼Ò¸ê" << endl;
	}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	friend ostream &operator<<(ostream &os, const Point& ref);
	
};

ostream &operator<<(ostream &os, const Point& ref) {
	os << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
	return os;
}

class SmartPtr {
	Point* pptr;
public:
	SmartPtr(Point * ptr): pptr(ptr){}
	Point &operator*() {
		return *pptr;
	}
	Point * operator->() {
		return pptr;
	}
	~SmartPtr() {
		delete pptr;
	}
};

int main() {
	SmartPtr sp1(new Point(1, 2));
	SmartPtr sp2(new Point(3, 4));
	SmartPtr sp3(new Point(5, 6));

	cout << *sp1;
	cout << *sp2;
	cout << *sp3;

	sp1->SetPos(11, 12);
	sp2->SetPos(13, 14);
	sp3->SetPos(15, 16);

	cout << *sp1;
	cout << *sp2;
	cout << *sp3;

	return 0;
}