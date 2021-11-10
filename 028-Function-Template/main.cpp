#include <iostream>

using namespace std;

template <class T>
void SwapData(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class X>
X SumArray(X arr[], int len) {
	X sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

class Point {
	int xpos, ypos;
public:
	Point(int x=0, int y=0): xpos(x), ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main() {
	cout << "-----Problem 1-----" << endl;
	Point p1(1, 2);
	Point p2(3, 4);
	p1.ShowPosition();
	p2.ShowPosition();

	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

	cout << "-----Problem 2-----" << endl;
	const int len = 5;
	char CharArray[len] = {'A', 1, 2, 3, 4};
	int IntArray[len] = { 1, 2, 3, 4, 5 };
	double DoubleArray[len] = { 1.1, 3.3, 5.6, 7.8, 9.0 };

	cout << "Sum of Char: " << SumArray(CharArray, len) << endl;
	cout << "Sum of Int: " << SumArray(IntArray, len) << endl;
	cout << "Sum of Double: " << SumArray(DoubleArray, len) << endl;

	return 0;
}
