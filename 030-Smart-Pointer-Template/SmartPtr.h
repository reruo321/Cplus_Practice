#pragma once

template <class T>
class SmartPtr {
	T * posptr;
public:
	SmartPtr(T * ptr): posptr(ptr) {}
	T& operator*() const { return *posptr; }
	T* operator->() const { return posptr; }
	~SmartPtr() { delete posptr; }
};