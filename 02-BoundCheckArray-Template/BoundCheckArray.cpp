#include <iostream>
#include "BoundCheckArray.h"

using namespace std;

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len) {
	arr = new T[len];
}
template <class T>
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "잘못된 배열 접근입니다." << endl;
		exit(1);
	}
	return arr[idx];
}
template <class T>
T& BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "잘못된 배열 접근입니다." << endl;
		exit(1);
	}
	return arr[idx];
}
template <class T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}
template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}