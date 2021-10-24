#include "Ring.h"

Ring::Ring(int x1, int y1, int r1, int x2, int y2, int r2) : a(x1, y1, r1), b(x2, y2, r2) {
}
void Ring::ShowRingInfo() const {
	cout << "Inner Circle Info..." << endl;
	a.ShowCircleInfo();
	cout << "Outer Circle Info..." << endl;
	b.ShowCircleInfo();
}