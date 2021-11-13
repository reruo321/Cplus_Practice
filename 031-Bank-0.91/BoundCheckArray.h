/* Version 0.91 */

#pragma once

#include "Account.h"
#include "BankingCommonDecl.h"

template <class T>
class BoundCheckArray
{
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray) {}
public:
	BoundCheckArray(int len = BANK_SIZE) : arrlen(len) {
		arr = new T[len];
	}
	T& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "잘못된 계좌순번 접근입니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	T& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "잘못된 계좌순번 접근입니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}

	~BoundCheckArray() {
		delete[]arr;
	}
};
