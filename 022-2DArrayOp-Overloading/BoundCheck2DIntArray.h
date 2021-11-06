#pragma once
#include <iostream>

using namespace std;

class RowArray {
	int* ptr;
	int col, row;

public:
	RowArray(int x = 0, int y = 0): col(x), row(y) {
		ptr = new int[y];
	}
	int& operator[] (int y) {
		if (y < 0 || y >= GetRow()) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return ptr[y];
	}
	int GetCol() const {
		return col;
	}
	int GetRow() const {
		return row;
	}
};

class BoundCheck2DIntArray: public RowArray {
	RowArray * arr;

	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int x = 0, int y = 0): RowArray(x, y) {
		arr = new RowArray[x];
		for (int i = 0; i < x; i++)
			arr[i] = RowArray(x, y);
	}
	RowArray &operator[] (int x) {
			if (x < 0 || x >= GetCol()) {
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[x];
	}

};
