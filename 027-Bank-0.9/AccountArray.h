/* Version 0.8 */

#pragma once
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
	ACCOUNT_PTR* arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray &arr){}
	BoundCheckAccountPtrArray & operator=(const BoundCheckAccountPtrArray){}
public:
	BoundCheckAccountPtrArray(int len=100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR& operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};