/* Version 0.8 */

#include <iostream>
#include "AccountArray.h"

using namespace std;

	BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len) {
		arr = new ACCOUNT_PTR[len];
	}
	ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "잘못된 계좌순번 접근입니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "잘못된 계좌순번 접근입니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	int BoundCheckAccountPtrArray::GetArrLen() const {
		return arrlen;
	}

	BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
		delete[]arr;
	}