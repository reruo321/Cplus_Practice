#pragma once

template <class T>
class BoundCheckArray
{
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray &arr) {}
	BoundCheckArray& operator=(const BoundCheckArray &arr){}

public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T& operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();

};