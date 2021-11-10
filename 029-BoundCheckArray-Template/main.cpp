#include <iostream>
#include "BoundCheckArray.h"
#include "Point.h"
#include "BoundCheckArray.cpp"

using namespace std;

int main() {

	cout << "-----Int Array-----" << endl;
	BoundCheckArray<int> intarr(3);
	intarr[0] = 0;
	intarr[1] = 1;
	intarr[2] = 2;

	for (int i = 0; i < intarr.GetArrLen(); i++)
		cout << intarr[i] << endl;

	cout << "-----Point Array-----" << endl;
	BoundCheckArray<Point> parr(3);
	parr[0] = Point(0, 1);
	parr[1] = Point(1, 2);
	parr[2] = Point(2, 3);

	for (int i = 0; i < parr.GetArrLen(); i++)
		cout << parr[i];

	cout << "-----Point Pointer Array-----" << endl;
	BoundCheckArray<Point *> ptrarr(3);
	ptrarr[0] = new Point(9, 8);
	ptrarr[1] = new Point(7, 6);
	ptrarr[2] = new Point(5, 4);

	for (int i = 0; i < ptrarr.GetArrLen(); i++)
		cout << *(ptrarr[i]);

	for (int i = 0; i < ptrarr.GetArrLen(); i++)
		delete ptrarr[i];

	return 0;
}